// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package main

import (
	"log"
	"runtime"
	"time"

	"github.com/pseudocodes/go2ctp/ctp"
	"github.com/pseudocodes/go2ctp/ctp_dyn"
	"github.com/pseudocodes/go2ctp/thost"
)

/*
Simnow是上期技术提供的CTP程序测试、模拟、学习的模拟平台。
2025.06.19 收盘后环境
7x24环境：
交易前置: tcp://182.254.243.31:40001
行情前置: tcp://182.254.243.31:40011

仿真环境1：交易时段同实盘
交易前置: tcp://182.254.243.31:30001
行情前置: tcp://182.254.243.31:30011

仿真环境2：交易时段同实盘
交易前置: tcp://182.254.243.31:30002
行情前置: tcp://182.254.243.31:30012

仿真环境3：交易时段同实盘
交易前置: tcp://182.254.243.31:30003
行情前置: tcp://182.254.243.31:30013
*/
var SimnowEnv map[string]map[string]string = map[string]map[string]string{
	"td": {
		"7x24":      "tcp://182.254.243.31:40001",
		"telesim1":  "tcp://182.254.243.31:30001",
		"telesim2":  "tcp://182.254.243.31:30002",
		"moblesim3": "tcp://182.254.243.31:30003",
	},
	"md": {
		"7x24":      "tcp://182.254.243.31:40011",
		"telesim1":  "tcp://182.254.243.31:30011",
		"telesim2":  "tcp://182.254.243.31:30012",
		"moblesim3": "tcp://182.254.243.31:30013",
	},
}

func init() {
	log.SetFlags(log.LstdFlags | log.Lshortfile)
}

type baseSpi struct {
	ctp_dyn.BaseMdSpi
	// ctp.BaseMdSpi
	mdapi thost.MdApi
}

func CreateBaseSpi() *baseSpi {
	s := &baseSpi{}
	return s
}

func (s *baseSpi) OnFrontConnected() {
	log.Printf("OnFrontConnected\n")

	loginR := &thost.CThostFtdcReqUserLoginField{}
	copy(loginR.BrokerID[:], "9999")
	copy(loginR.UserID[:], "046056")

	ret := s.mdapi.ReqUserLogin(loginR, 1)

	log.Printf("user log: %v\n", ret)
}

func (s *baseSpi) OnHeartBeatWarning(timelapse int) {
	log.Printf("OnHeartBeatWarning: %v\n", timelapse)
}

func (s *baseSpi) OnFrontDisconnected(nReason int) {
	log.Printf("OnFrontDisconnected: %v\n", nReason)
}

func (s *baseSpi) OnRspUserLogin(pRspUserLogin *thost.CThostFtdcRspUserLoginField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("RspUserLogin: %+v\nRspInfo: %+v\n", pRspUserLogin, nil)
	s.mdapi.SubscribeMarketData("ag2508")
}

func (s *baseSpi) OnRspSubMarketData(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {

	log.Printf("instrumentID: %+v\n  RspInfo: %+v\n", pSpecificInstrument, nil)
}

func (s *baseSpi) OnRtnDepthMarketData(pDepthMarketData *thost.CThostFtdcDepthMarketDataField) {
	log.Printf("OnRtnDeptMarketData: %s\n", string(pDepthMarketData.InstrumentID[:7]))
}

func (s *baseSpi) OnRspError(pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("RspInfo: %+v\n", pRspInfo.ErrorID)
}

type baseSpi2 struct {
	ctp.BaseMdSpi
	mdapi thost.MdApi
}

func CreateBaseSpi2() *baseSpi2 {
	s := &baseSpi2{}

	s.OnFrontConnectedCallback = func() {
		log.Printf("OnFrontConnected\n")

		loginR := &thost.CThostFtdcReqUserLoginField{}
		copy(loginR.BrokerID[:], "9999")
		copy(loginR.UserID[:], "046056")

		ret := s.mdapi.ReqUserLogin(loginR, 1)

		log.Printf("user log: %v\n", ret)
	}
	s.OnFrontDisconnectedCallback = func(nReason int) {
		log.Printf("OnFrontDisconnected: %v\n", nReason)
	}
	s.OnRspUserLoginCallback = func(pRspUserLogin *thost.CThostFtdcRspUserLoginField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
		log.Printf("RspUserLogin: %+v\nRspInfo: %+v\n", pRspUserLogin, nil)
		s.mdapi.SubscribeMarketData("ag2508")
	}
	s.OnRtnDepthMarketDataCallback = func(pDepthMarketData *thost.CThostFtdcDepthMarketDataField) {
		// log.Printf("tick {%+v}\n", quote)
		log.Printf("OnRtnDeptMarketData 222\n")
	}
	return s

}

var (
	CTPLibPathLinux = "../../ctp/lib/v6.7.2_20230913_api_traderapi_se_linux64/thostmduserapi_se.so"

	TTSFront    = "tcp://121.37.80.177:20004"
	SimnowFront = SimnowEnv["md"]["telesim1"]
)

func sample1() {
	var (
		mdapi     thost.MdApi
		frontAddr string
	)
	if runtime.GOOS == "darwin" {
		fwlib := "../../ctp/lib/v6.7.2_MacOS_20231016/thostmduserapi_se.framework/Versions/A/thostmduserapi_se"
		// mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(TTSLibPathDarwin), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(fwlib), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))

		frontAddr = SimnowEnv["md"]["7x24"]
		frontAddr = SimnowEnv["md"]["telesim1"]

	} else if runtime.GOOS == "linux" {
		// mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(TTSLibPathLinux), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(CTPLibPathLinux), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		frontAddr = SimnowFront
	}

	baseSpi := CreateBaseSpi()
	baseSpi.mdapi = mdapi
	mdapi.RegisterSpi(baseSpi)

	mdapi.RegisterFront(frontAddr)
	// mdapi.RegisterFront(SimnowEnv["md"]["telesim1"])

	mdapi.Init()

	println(mdapi.GetApiVersion())
	println(mdapi.GetTradingDay())

	// mdapi.Join()
	for {
		time.Sleep(10 * time.Second)
	}

}

func sample2() {
	mdapi := ctp.CreateMdApi(ctp.MdFlowPath("./data/"), ctp.MdUsingUDP(false), ctp.MdMultiCast(false))
	baseSpi2 := CreateBaseSpi2()
	baseSpi2.mdapi = mdapi
	mdapi.RegisterSpi(baseSpi2)

	// mdapi.RegisterFront("tcp://140.206.244.33:11616")
	// mdapi.RegisterFront("tcp://182.254.243.31:10131")
	// mdapi.RegisterFront(SimnowEnv["md"]["telesim1"])

	mdapi.Init()

	println(mdapi.GetApiVersion())
	println(mdapi.GetTradingDay())

	mdapi.Join()
	// for {
	// 	time.Sleep(10 * time.Second)
	// }

}

func main() {
	sample1()
	// sample2()
}
