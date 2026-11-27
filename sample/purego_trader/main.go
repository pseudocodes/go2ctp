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
	"time"

	"github.com/pseudocodes/go2ctp/ctp_purego"
	"github.com/pseudocodes/go2ctp/thost"
)

const simNowFront = "tcp://182.254.243.31:40001"

type eventKind int

const (
	connected eventKind = iota
	disconnected
	authenticated
	loggedIn
	queryDone
	requestError
)

type event struct {
	kind eventKind
	id   int
	err  error
}

type traderSPI struct {
	ctp_purego.BaseTraderSpi
	ctx    context.Context
	events chan event
}

func (s *traderSPI) notify(e event) {
	select {
	case s.events <- e:
	case <-s.ctx.Done():
	}
}

func (s *traderSPI) reply(kind eventKind, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	if info != nil && info.ErrorID != 0 {
		s.notify(event{kind: requestError, id: id, err: fmt.Errorf("CTP %d: %s", info.ErrorID, info.ErrorMsg.GBString())})
	} else if last && kind != requestError {
		s.notify(event{kind: kind, id: id})
	}
}

func (s *traderSPI) OnFrontConnected() { s.notify(event{kind: connected}) }
func (s *traderSPI) OnFrontDisconnected(reason int) {
	log.Printf("交易前置已断开，原因 %#x，等待 SDK 重连", reason)
	s.notify(event{kind: disconnected})
}
func (s *traderSPI) OnRspAuthenticate(_ *thost.CThostFtdcRspAuthenticateField, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	s.reply(authenticated, info, id, last)
}
func (s *traderSPI) OnRspUserLogin(_ *thost.CThostFtdcRspUserLoginField, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	s.reply(loggedIn, info, id, last)
}
func (s *traderSPI) OnRspQryTradingAccount(row *thost.CThostFtdcTradingAccountField, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	if row != nil && (info == nil || info.ErrorID == 0) {
		log.Printf("资金账户 %s 权益 %.2f 可用 %.2f", row.CurrencyID.String(), row.Balance, row.Available)
	}
	s.reply(queryDone, info, id, last)
}
func (s *traderSPI) OnRspQryInstrument(row *thost.CThostFtdcInstrumentField, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	if row != nil && (info == nil || info.ErrorID == 0) {
		log.Printf("合约 %s 交易所 %s 合约乘数 %d 最小变动价位 %g", row.InstrumentID.String(), row.ExchangeID.String(), row.VolumeMultiple, row.PriceTick)
	}
	s.reply(queryDone, info, id, last)
}
func (s *traderSPI) OnRspError(info *thost.CThostFtdcRspInfoField, id int, last bool) {
	s.reply(requestError, info, id, last)
}

func defaultLibrary() string {
	if path := os.Getenv("CTP_TRADER_LIBRARY"); path != "" {
		return path
	}
	switch runtime.GOOS {
	case "darwin":
		return "../../ctp/lib/v6.7.13_MacOS_20260529/thosttraderapi_se.framework/Versions/A/thosttraderapi_se"
	case "linux":
		return "../../ctp/lib/v6.7.13_20260225_api_traderapi_se_linux64/thosttraderapi_se.so"
	default:
		return "thosttraderapi_se.dll"
	}
}

func run() error {
	defaultFront := os.Getenv("CTP_TRADER_FRONT")
	if defaultFront == "" {
		defaultFront = simNowFront
	}
	front := flag.String("front", defaultFront, "SimNow 交易前置地址")
	lib := flag.String("lib", defaultLibrary(), "CTP 6.7.13 交易库文件路径")
	flag.Usage = func() {
		fmt.Fprintf(flag.CommandLine.Output(), "用法：%s [选项] [合约...]\n", os.Args[0])
		flag.PrintDefaults()
	}
	flag.Parse()
	instruments := flag.Args()
	var instrument thost.CThostFtdcQryInstrumentField
	for _, id := range instruments {
		if id == "" || len(id) >= len(instrument.InstrumentID) {
			return fmt.Errorf("无效合约代码 %q", id)
		}
	}

	var login thost.CThostFtdcReqUserLoginField
	user, password := os.Getenv("SIMNOW_USER_0"), os.Getenv("SIMNOW_PASS_0")
	if user == "" || password == "" {
		return fmt.Errorf("请设置 SIMNOW_USER_0 和 SIMNOW_PASS_0")
	}
	if len(user) >= len(login.UserID) || len(password) >= len(login.Password) {
		return fmt.Errorf("用户名或密码超过 CTP 字段长度")
	}
	copy(login.BrokerID[:], "9999")
	copy(login.UserID[:], user)
	copy(login.Password[:], password)
	auth := thost.CThostFtdcReqAuthenticateField{BrokerID: login.BrokerID, UserID: login.UserID}
	copy(auth.AppID[:], "simnow_client_test")
	copy(auth.AuthCode[:], "0000000000000000")
	account := thost.CThostFtdcQryTradingAccountField{BrokerID: login.BrokerID}
	copy(account.InvestorID[:], user)

	flow, err := os.MkdirTemp("", "go2ctp-trader-")
	if err != nil {
		return err
	}
	defer os.RemoveAll(flow)
	api := ctp_purego.CreateTraderApi(ctp_purego.TraderDynamicLibPath(*lib), ctp_purego.TraderFlowPath(flow+string(os.PathSeparator)))
	defer api.Release()
	ctx, stop := signal.NotifyContext(context.Background(), os.Interrupt, syscall.SIGTERM)
	defer stop()
	spi := &traderSPI{ctx: ctx, events: make(chan event, 8)}
	api.RegisterSpi(spi)
	api.SubscribePrivateTopic(thost.THOST_TERT_QUICK)
	api.SubscribePublicTopic(thost.THOST_TERT_QUICK)
	api.RegisterFront(*front)
	log.Printf("CTP %s，前置 %s", api.GetApiVersion(), *front)
	api.Init()

	// Only the owner goroutine sends requests. Ignore replies from a previous connection.
	var requestID, pending, nextInstrument int
	var nextQuery <-chan time.Time
	for {
		var operation string
		var rc int
		select {
		case <-ctx.Done():
			return nil
		case e := <-spi.events:
			if e.kind != connected && e.kind != disconnected && (pending == 0 || e.id != pending) {
				continue
			}
			switch e.kind {
			case connected:
				nextQuery = nil
				nextInstrument = 0
				requestID++
				operation = "客户端认证"
				rc = api.ReqAuthenticate(&auth, requestID)
			case disconnected:
				pending = 0
				nextQuery = nil
				continue
			case authenticated:
				requestID++
				operation = "用户登录"
				rc = api.ReqUserLogin(&login, requestID)
			case loggedIn:
				log.Printf("登录成功，交易日 %s", api.GetTradingDay())
				requestID++
				operation = "查询资金账户"
				rc = api.ReqQryTradingAccount(&account, requestID)
			case queryDone:
				pending = 0
				if nextInstrument < len(instruments) {
					nextQuery = time.After(time.Second)
				}
				continue
			case requestError:
				return fmt.Errorf("请求 %d 失败：%w", e.id, e.err)
			}
		case <-nextQuery:
			nextQuery = nil
			req := thost.CThostFtdcQryInstrumentField{}
			copy(req.InstrumentID[:], instruments[nextInstrument])
			operation = "查询合约 " + instruments[nextInstrument]
			nextInstrument++
			requestID++
			rc = api.ReqQryInstrument(&req, requestID)
		}
		if rc != 0 {
			return fmt.Errorf("提交%s失败：%d", operation, rc)
		}
		pending = requestID
	}
}
func main() {
	if err := run(); err != nil {
		log.Fatal(err)
	}
}
