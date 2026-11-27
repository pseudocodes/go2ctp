//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"os"
	"os/signal"
	"runtime"
	"syscall"

	"github.com/pseudocodes/go2ctp/ctp_purego"
	"github.com/pseudocodes/go2ctp/thost"
)

type event struct {
	requestLogin bool
	loginErr     error
}

type marketSPI struct {
	ctp_purego.BaseMdSpi
	ctx    context.Context
	events chan event
}

func (s *marketSPI) notify(e event) {
	select {
	case s.events <- e:
	case <-s.ctx.Done():
	}
}

func (s *marketSPI) OnFrontConnected() {
	log.Print("行情前置已连接，准备登录")
	s.notify(event{requestLogin: true})
}

func (s *marketSPI) OnFrontDisconnected(reason int) {
	log.Printf("行情前置已断开，原因 %#x，等待 SDK 重连", reason)
}

func responseError(info *thost.CThostFtdcRspInfoField) error {
	if info == nil || info.ErrorID == 0 {
		return nil
	}
	return fmt.Errorf("CTP %d: %s", info.ErrorID, info.ErrorMsg.GBString())
}

func (s *marketSPI) OnRspUserLogin(_ *thost.CThostFtdcRspUserLoginField, info *thost.CThostFtdcRspInfoField, _ int, last bool) {
	err := responseError(info)
	if err != nil || last {
		s.notify(event{loginErr: err})
	}
}

func (s *marketSPI) OnRspSubMarketData(instrument *thost.CThostFtdcSpecificInstrumentField, info *thost.CThostFtdcRspInfoField, _ int, _ bool) {
	var id string
	if instrument != nil {
		id = instrument.InstrumentID.String()
	}
	if err := responseError(info); err != nil {
		log.Printf("订阅 %s 失败：%v", id, err)
		return
	}
	log.Printf("订阅确认 %s", id)
}

func (s *marketSPI) OnRspError(info *thost.CThostFtdcRspInfoField, requestID int, _ bool) {
	if err := responseError(info); err != nil {
		log.Printf("请求 %d 出错：%v", requestID, err)
	}
}

func (s *marketSPI) OnRtnDepthMarketData(tick *thost.CThostFtdcDepthMarketDataField) {
	if tick != nil {
		log.Printf("%s %s.%03d 最新价 %g 成交量 %d", tick.InstrumentID.String(), tick.UpdateTime.String(), tick.UpdateMillisec, tick.LastPrice, tick.Volume)
	}
}

func defaultLibrary() string {
	if path := os.Getenv("CTP_MD_LIBRARY"); path != "" {
		return path
	}
	switch runtime.GOOS {
	case "darwin":
		return "../../ctp/lib/v6.7.13_MacOS_20260529/thostmduserapi_se.framework/Versions/A/thostmduserapi_se"
	case "linux":
		return "../../ctp/lib/v6.7.13_20260225_api_traderapi_se_linux64/thostmduserapi_se.so"
	default:
		return "thostmduserapi_se.dll"
	}
}

func run() error {
	lib := flag.String("lib", defaultLibrary(), "CTP 6.7.13 行情库文件路径")
	front := flag.String("front", os.Getenv("CTP_MD_FRONT"), "行情前置地址，如 tcp://host:port")
	flag.Usage = func() {
		fmt.Fprintf(flag.CommandLine.Output(), "用法：%s -front tcp://host:port [选项] 合约 [合约...]\n", os.Args[0])
		flag.PrintDefaults()
	}
	flag.Parse()
	instruments := flag.Args()
	if *front == "" || len(instruments) == 0 {
		flag.Usage()
		return fmt.Errorf("请指定行情前置和至少一个合约")
	}

	var login thost.CThostFtdcReqUserLoginField
	for name, dst := range map[string][]byte{
		"CTP_BROKER_ID": login.BrokerID[:], "SIMNOW_USER_0": login.UserID[:], "SIMNOW_PASS_0": login.Password[:],
	} {
		value := os.Getenv(name)
		if len(value) >= len(dst) {
			return fmt.Errorf("%s 超过字段长度（最多 %d 字节）", name, len(dst)-1)
		}
		copy(dst, value)
	}
	copy(login.BrokerID[:], "9999")

	flow, err := os.MkdirTemp("", "go2ctp-md-")
	if err != nil {
		return err
	}
	defer os.RemoveAll(flow)
	api := ctp_purego.CreateMdApi(
		ctp_purego.MdDynamicLibPath(*lib),
		ctp_purego.MdFlowPath(flow+string(os.PathSeparator)),
	)
	defer api.Release()
	ctx, stop := signal.NotifyContext(context.Background(), os.Interrupt, syscall.SIGTERM)
	defer stop()
	spi := &marketSPI{ctx: ctx, events: make(chan event, 8)}
	api.RegisterSpi(spi)
	api.RegisterFront(*front)
	log.Printf("CTP %s，前置 %s", api.GetApiVersion(), *front)
	api.Init()

	// Keep all API calls on the owner goroutine, including release on shutdown.
	requestID := 0
	for {
		select {
		case <-ctx.Done():
			return nil
		case e := <-spi.events:
			if e.requestLogin {
				requestID++
				if rc := api.ReqUserLogin(&login, requestID); rc != 0 {
					return fmt.Errorf("提交登录请求失败：%d", rc)
				}
				continue
			}
			if e.loginErr != nil {
				return fmt.Errorf("登录失败：%w", e.loginErr)
			}
			log.Printf("登录成功，交易日 %s", api.GetTradingDay())
			if rc := api.SubscribeMarketData(instruments...); rc != 0 {
				return fmt.Errorf("提交订阅请求失败：%d", rc)
			}
		}
	}
}

func main() {
	if err := run(); err != nil {
		log.Fatal(err)
	}
}
