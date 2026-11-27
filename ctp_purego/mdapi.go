//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

// Package ctp_purego binds the CTP 6.7.13 market data and trader SDKs without cgo.
package ctp_purego

import (
	"math"
	"runtime"
	"strings"

	"github.com/ebitengine/purego"
	"github.com/pseudocodes/go2ctp/thost"
)

// apiObject points into the vendor library's C++ object.
type apiObject struct{ vtable *[15]uintptr }

type mdMethods struct {
	release, init                    func(*apiObject)
	join                             func(*apiObject) int32
	tradingDay                       func(*apiObject) string
	front, nameServer                func(*apiObject, string)
	fens                             func(*apiObject, *thost.CThostFtdcFensUserInfoField)
	registerSPI                      func(*apiObject, *nativeSPI)
	subscribe, unsubscribe           instrumentMethod
	subscribeQuote, unsubscribeQuote instrumentMethod
	login                            func(*apiObject, *thost.CThostFtdcReqUserLoginField, int32) int32
	logout                           func(*apiObject, *thost.CThostFtdcUserLogoutField, int32) int32
	query                            func(*apiObject, *thost.CThostFtdcQryMulticastInstrumentField, int32) int32
}

// Bind in the virtual declaration order in the SDK's ThostFtdcMdApi.h.
func (m *mdMethods) bind(vtable *[15]uintptr) {
	slots := [...]any{
		&m.release, &m.init, &m.join, &m.tradingDay,
		&m.front, &m.nameServer, &m.fens, &m.registerSPI,
		&m.subscribe, &m.unsubscribe, &m.subscribeQuote, &m.unsubscribeQuote,
		&m.login, &m.logout, &m.query,
	}
	for i, fn := range slots {
		purego.RegisterFunc(fn, vtable[i])
	}
}

type MdApi struct {
	sdkSession[apiObject, nativeSPI]
	sdkOptions
	methods             mdMethods
	usingUDP, multicast bool
}

type MdOption func(*MdApi)

func MdDynamicLibPath(path string) MdOption  { return func(a *MdApi) { a.dllPath = path } }
func MdFlowPath(path string) MdOption        { return func(a *MdApi) { a.flowPath = path } }
func MdUsingUDP(enabled bool) MdOption       { return func(a *MdApi) { a.usingUDP = enabled } }
func MdMultiCast(enabled bool) MdOption      { return func(a *MdApi) { a.multicast = enabled } }
func MdProductionMode(enabled bool) MdOption { return func(a *MdApi) { a.production = enabled } }

func CreateMdApi(options ...MdOption) thost.MdApi {
	a := &MdApi{sdkOptions: sdkOptions{production: true}}
	for _, option := range options {
		option(a)
	}
	a.open(a.sdkOptions, mdFactoryName, mdVersionName, (*nativeSPI).initialize, func(factory uintptr) *apiObject {
		var create func(string, bool, bool, bool) *apiObject
		purego.RegisterFunc(&create, factory)
		return create(a.flowPath, a.usingUDP, a.multicast, a.production)
	})
	a.methods.bind(a.obj.vtable)
	a.methods.registerSPI(a.obj, a.spi)
	return a
}

func (a *MdApi) Init() { a.methods.init(a.obj) }

func (a *MdApi) Join() int { return int(a.methods.join(a.obj)) }

func (a *MdApi) GetTradingDay() string { return a.methods.tradingDay(a.obj) }

func (a *MdApi) RegisterFront(addr string) { a.methods.front(a.obj, addr) }

func (a *MdApi) RegisterNameServer(addr string) { a.methods.nameServer(a.obj, addr) }

func (a *MdApi) RegisterFensUserInfo(f *thost.CThostFtdcFensUserInfoField) { a.methods.fens(a.obj, f) }

func (a *MdApi) RegisterSpi(s thost.MdSpi) {
	if s == nil {
		receivers.Delete(a.spi)
	} else {
		receivers.Store(a.spi, s)
	}
}

// Release from the owner goroutine after other API calls finish. Calling Release
// on an SDK callback thread can deadlock while the SDK joins its own thread.
func (a *MdApi) Release() {
	a.close(a.methods.registerSPI, a.methods.release)
}

type instrumentMethod func(*apiObject, **byte, int32) int32

func (a *MdApi) instruments(call instrumentMethod, ids []string) int {
	if len(ids) == 0 {
		return int(call(a.obj, nil, 0))
	}
	if len(ids) > math.MaxInt32 {
		panic("too many CTP instruments")
	}
	ptrs := make([]*byte, len(ids))
	for i, id := range ids {
		if strings.IndexByte(id, 0) >= 0 {
			panic("NUL in CTP instrument ID")
		}
		buf := make([]byte, len(id)+1)
		copy(buf, id)
		ptrs[i] = &buf[0]
	}
	result := call(a.obj, &ptrs[0], int32(len(ids)))
	runtime.KeepAlive(ptrs)
	return int(result)
}

func (a *MdApi) SubscribeMarketData(ids ...string) int {
	return a.instruments(a.methods.subscribe, ids)
}

func (a *MdApi) UnSubscribeMarketData(ids ...string) int {
	return a.instruments(a.methods.unsubscribe, ids)
}

func (a *MdApi) SubscribeForQuoteRsp(ids ...string) int {
	return a.instruments(a.methods.subscribeQuote, ids)
}

func (a *MdApi) UnSubscribeForQuoteRsp(ids ...string) int {
	return a.instruments(a.methods.unsubscribeQuote, ids)
}

func (a *MdApi) ReqUserLogin(f *thost.CThostFtdcReqUserLoginField, id int) int {
	return int(a.methods.login(a.obj, f, int32(id)))
}

func (a *MdApi) ReqUserLogout(f *thost.CThostFtdcUserLogoutField, id int) int {
	return int(a.methods.logout(a.obj, f, int32(id)))
}

func (a *MdApi) ReqQryMulticastInstrument(f *thost.CThostFtdcQryMulticastInstrumentField, id int) int {
	return int(a.methods.query(a.obj, f, int32(id)))
}
