//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

import (
	"fmt"
	"hash/crc32"
	"os"
	"path/filepath"
	"reflect"
	"regexp"
	"strings"
	"testing"

	"github.com/pseudocodes/go2ctp/thost"
)

// Distinct negative return values identify which native method was actually called.
func fixtureStatus(name string) int {
	return -int(crc32.ChecksumIEEE([]byte(name)) & 0x3fffffff)
}

func writeTraderDefaults(t *testing.T, header, dir string) {
	t.Helper()
	source, err := os.ReadFile(filepath.Join(header, "ThostFtdcTraderApi.h"))
	if err != nil {
		t.Fatal(err)
	}
	virtual := regexp.MustCompile(`(?m)^\s*virtual\s+(void|int|const char\s*\*)\s*(\w+)(\([^\n]*\))\s*=\s*0;`)
	var out strings.Builder
	for _, m := range virtual.FindAllStringSubmatch(string(source), -1) {
		body := ""
		switch m[1] {
		case "void":
		case "int":
			body = fmt.Sprintf("return %d;", fixtureStatus(m[2]))
		default:
			body = `return "20261127";`
		}
		fmt.Fprintf(&out, "%s %s%s override { %s }\n", m[1], m[2], m[3], body)
	}
	if err := os.WriteFile(filepath.Join(dir, "trader_defaults.inc"), []byte(out.String()), 0600); err != nil {
		t.Fatal(err)
	}
}

type traderProbe struct {
	BaseTraderSpi
	events []string // read after native Join; one native writer per instance
}

func (s *traderProbe) OnRtnPrivateSeqNo(n int) { s.events = append(s.events, fmt.Sprint("seq=", n)) }
func (s *traderProbe) OnRspAuthenticate(_ *thost.CThostFtdcRspAuthenticateField, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	s.events = append(s.events, fmt.Sprintf("auth=%d,%d,%t", info.ErrorID, id, last))
}
func (s *traderProbe) OnRtnOrder(o *thost.CThostFtdcOrderField) {
	s.events = append(s.events, fmt.Sprint("order=", o.VolumeTotalOriginal))
}
func (s *traderProbe) OnErrRtnOrderInsert(_ *thost.CThostFtdcInputOrderField, info *thost.CThostFtdcRspInfoField) {
	s.events = append(s.events, fmt.Sprint("insert=", info.ErrorID))
}
func (s *traderProbe) OnRspError(info *thost.CThostFtdcRspInfoField, id int, last bool) {
	s.events = append(s.events, fmt.Sprintf("error=%d,%d,%t", info.ErrorID, id, last))
}
func (s *traderProbe) OnRspQryHedgeCfm(data *thost.CThostFtdcHedgeCfmField, info *thost.CThostFtdcRspInfoField, id int, last bool) {
	s.events = append(s.events, fmt.Sprintf("query=%t,%d,%t", data == nil && info == nil, id, last))
}
func (s *traderProbe) OnErrRtnHedgeCfmAction(_ *thost.CThostFtdcHedgeCfmActionField, info *thost.CThostFtdcRspInfoField) {
	s.events = append(s.events, fmt.Sprint("last=", info.ErrorID))
}

func TestTraderBindings(t *testing.T) {
	lib := buildFixture(t, "trader")
	dir := t.TempDir()
	stock := CreateTraderApi(TraderDynamicLibPath(lib), TraderFlowPath(filepath.Join(dir, "prod")+string(os.PathSeparator)))
	defer stock.Release()
	eval := CreateTraderApi(TraderDynamicLibPath(lib), TraderFlowPath(filepath.Join(dir, "evaluation", "prefix")), TraderProductionMode(false), TraderSystemInfo([]byte("legacy"), 6))
	defer eval.Release()
	if _, err := os.Stat(filepath.Join(dir, "evaluation")); err != nil {
		t.Fatal(err)
	}
	var spis []*traderProbe
	for i, api := range []thost.TraderApi{stock, eval} {
		spi := new(traderProbe)
		spis = append(spis, spi)
		api.RegisterSpi(spi)
		if api.GetApiVersion() != "6.7.13_trader_fixture" || api.GetTradingDay() != "20261127" {
			t.Fatal("wrong library or method")
		}
		api.SubscribePrivateTopic(thost.THOST_TERT_RESTART)
		if i == 1 {
			api.SubscribePrivateTopic(thost.THOST_TERT_RESUME_FROM_SEQ_NO, 37)
		}
		var info thost.CThostFtdcFrontInfoField
		api.GetFrontInfo(&info)
		if info.QryFreq != []thost.TThostFtdcQueryFreqType{1, 37}[i] {
			t.Fatal(info)
		}
		var login thost.CThostFtdcReqUserLoginField
		login.BrokerID[0] = 'B'
		if api.ReqUserLogin(&login, -9, "legacy") != -9 {
			t.Fatal("login arguments")
		}
		checkRequestSlots(t, api)
		api.Init()
	}
	for i, api := range []thost.TraderApi{stock, eval} {
		if api.Join() != -27 {
			t.Fatal("Join status")
		}
		want := []string{fmt.Sprint("seq=", []int{1, 37}[i]), "auth=-12,-77,true", "order=17", "insert=-12", "error=-12,42,false", "query=true,-8,false", "last=-12"}
		if !reflect.DeepEqual(spis[i].events, want) {
			t.Errorf("instance %d: %v", i, spis[i].events)
		}
		api.Release()
	}
}

// Invoke every fixed-signature request against the fixture only. The return
// value is derived from its C++ method name, so even a one-slot shift fails.
func checkRequestSlots(t *testing.T, api thost.TraderApi) {
	t.Helper()
	iface := reflect.TypeOf((*thost.TraderApi)(nil)).Elem()
	for i := 0; i < iface.NumMethod(); i++ {
		method := iface.Method(i)
		if method.Type.NumOut() != 1 || method.Type.Out(0).Kind() != reflect.Int || method.Name == "Join" || method.Name == "ReqUserLogin" {
			continue
		}
		args := make([]reflect.Value, method.Type.NumIn())
		for j := range args {
			args[j] = reflect.Zero(method.Type.In(j))
		}
		got := reflect.ValueOf(api).MethodByName(method.Name).Call(args)[0].Int()
		if got != int64(fixtureStatus(method.Name)) {
			t.Errorf("%s = %d", method.Name, got)
		}
	}
}
