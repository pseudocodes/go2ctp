//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

import (
	"os/exec"
	"path/filepath"
	"reflect"
	"runtime"
	"testing"

	"github.com/pseudocodes/go2ctp/thost"
)

func TestNativeThreadAndVirtualSlots(t *testing.T) {
	lib := buildFixture(t, "md")

	var apis []thost.MdApi
	for i := 0; i < 2; i++ {
		api := CreateMdApi(MdDynamicLibPath(lib), MdUsingUDP(true), MdMultiCast(true), MdProductionMode(false))
		t.Cleanup(api.Release)
		apis = append(apis, api)
		spi := &recordingSpi{t: t, id: -123 - i, events: make(chan string, 13)}
		api.RegisterSpi(spi)
		if day := api.GetTradingDay(); day != "20261127" {
			t.Fatal(day)
		}
		api.RegisterFront("front")
		api.RegisterNameServer("ns")
		api.RegisterFensUserInfo(&thost.CThostFtdcFensUserInfoField{LoginMode: 'A'})
		login := thost.CThostFtdcReqUserLoginField{}
		login.BrokerID[0] = 'B'
		got := []int{
			api.SubscribeMarketData("IF01", "IF02"), api.UnSubscribeMarketData("IF01", "IF02"),
			api.SubscribeForQuoteRsp("IF01", "IF02"), api.UnSubscribeForQuoteRsp(),
			api.ReqUserLogin(&login, spi.id), api.ReqUserLogout(&thost.CThostFtdcUserLogoutField{}, -13),
			api.ReqQryMulticastInstrument(&thost.CThostFtdcQryMulticastInstrumentField{}, 14),
		}
		if !reflect.DeepEqual(got, []int{8, 9, 10, 11, -12, -13, -14}) {
			t.Fatal(got)
		}
		t.Cleanup(func() {
			want := []string{"connect", "disconnect", "heartbeat", "login", "logout", "query", "error", "subscribe", "unsubscribe", "quoteSub", "quoteUnsub", "tick", "quote"}
			var got []string
			for len(spi.events) > 0 {
				got = append(got, <-spi.events)
			}
			if !reflect.DeepEqual(got, want) {
				t.Errorf("SPI events: %v", got)
			}
		})
	}
	for _, a := range apis {
		a.Init()
	}
	for _, a := range apis {
		if a.Join() != -17 {
			t.Fatal("Join status")
		}
		a.Release()
		a.Release()
	}
}

// A native compiler is optional for this test and is never used by the Go package.
func buildFixture(t *testing.T, kind string) string {
	t.Helper()
	dir := t.TempDir()
	header, err := filepath.Abs("../ctp/lib/v6.7.13_20260225_api_traderapi_se_linux64")
	if err != nil {
		t.Fatal(err)
	}
	src, err := filepath.Abs("testdata/" + kind + "_fixture.cpp")
	if err != nil {
		t.Fatal(err)
	}
	var cmd *exec.Cmd
	if kind == "trader" {
		writeTraderDefaults(t, header, dir)
	}
	lib := filepath.Join(dir, kind+"-fixture.so")
	if runtime.GOOS == "windows" {
		cl, err := exec.LookPath("cl.exe")
		if err != nil {
			t.Skip("MSVC developer prompt needed only to build the Windows test fixture")
		}
		lib = filepath.Join(dir, kind+"-fixture.dll")
		cmd = exec.Command(cl, "/nologo", "/LD", "/EHsc", "/std:c++14", "/DWIN32", "/DISLIB", "/DLIB_MD_API_EXPORT", "/DLIB_TRADER_API_EXPORT", "/I"+dir, "/I"+header, src, "/link", "/OUT:"+lib)
	} else {
		cxx, err := exec.LookPath("c++")
		if err != nil {
			t.Skip("c++ needed only to build the test fixture")
		}
		cmd = exec.Command(cxx, "-std=c++11", "-shared", "-fPIC", "-pthread", "-I"+header, "-I"+dir, src, "-o", lib)
	}
	cmd.Dir = dir
	if out, err := cmd.CombinedOutput(); err != nil {
		t.Fatalf("compile test fixture: %v\n%s", err, out)
	}
	return lib
}

type recordingSpi struct {
	t      *testing.T
	id     int
	events chan string
}

func (s *recordingSpi) record(name string, valid bool) {
	s.t.Helper()
	if !valid {
		s.t.Errorf("bad %s callback arguments for %d", name, s.id)
	}
	s.events <- name
}
func (s *recordingSpi) OnFrontConnected()              { s.record("connect", true) }
func (s *recordingSpi) OnFrontDisconnected(reason int) { s.record("disconnect", reason == -1) }
func (s *recordingSpi) OnHeartBeatWarning(n int)       { s.record("heartbeat", n == 23) }
func (s *recordingSpi) OnRspUserLogin(r *thost.CThostFtdcRspUserLoginField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("login", r == nil && e != nil && e.ErrorID == -9 && n == s.id && last)
}
func (s *recordingSpi) OnRspUserLogout(r *thost.CThostFtdcUserLogoutField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("logout", r == nil && e == nil && n == -2 && !last)
}
func (s *recordingSpi) OnRspQryMulticastInstrument(r *thost.CThostFtdcMulticastInstrumentField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("query", r == nil && e == nil && n == 3 && last)
}
func (s *recordingSpi) OnRspError(e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("error", e != nil && e.ErrorID == -9 && n == 4 && !last)
}
func (s *recordingSpi) OnRspSubMarketData(r *thost.CThostFtdcSpecificInstrumentField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("subscribe", r == nil && e == nil && n == 5 && last)
}
func (s *recordingSpi) OnRspUnSubMarketData(r *thost.CThostFtdcSpecificInstrumentField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("unsubscribe", r == nil && e == nil && n == 6 && !last)
}
func (s *recordingSpi) OnRspSubForQuoteRsp(r *thost.CThostFtdcSpecificInstrumentField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("quoteSub", r == nil && e == nil && n == 7 && last)
}
func (s *recordingSpi) OnRspUnSubForQuoteRsp(r *thost.CThostFtdcSpecificInstrumentField, e *thost.CThostFtdcRspInfoField, n int, last bool) {
	s.record("quoteUnsub", r == nil && e == nil && n == 8 && !last)
}
func (s *recordingSpi) OnRtnDepthMarketData(d *thost.CThostFtdcDepthMarketDataField) {
	s.record("tick", d != nil && d.LastPrice == 42.25 && d.InstrumentID.String() == "IF01")
}
func (s *recordingSpi) OnRtnForQuoteRsp(d *thost.CThostFtdcForQuoteRspField) {
	s.record("quote", d == nil)
}
