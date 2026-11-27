//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

//go:generate python3 gen_trader.py

import (
	"sync"

	"github.com/ebitengine/purego"
	"github.com/pseudocodes/go2ctp/thost"
)

type traderObject struct{ vtable *[traderMethodCount]uintptr }
type traderSPI struct {
	vptr     *uintptr
	metadata [2]uintptr
	methods  [traderCallbackCount]uintptr
}

type TraderApi struct {
	sdkSession[traderObject, traderSPI]
	sdkOptions
	methods traderMethods
}

type TraderOption func(*TraderApi)

func TraderDynamicLibPath(path string) TraderOption { return func(a *TraderApi) { a.dllPath = path } }
func TraderFlowPath(path string) TraderOption       { return func(a *TraderApi) { a.flowPath = path } }
func TraderProductionMode(production bool) TraderOption {
	return func(a *TraderApi) { a.production = production }
}

// TraderSystemInfo preserves the legacy constructor option. CTP 6.7.13 accepts
// system information through RegisterUserSystemInfo / SubmitUserSystemInfo.
func TraderSystemInfo(systemInfo []byte, length int) TraderOption { return func(*TraderApi) {} }

func CreateTraderApi(options ...TraderOption) thost.TraderApi {
	a := &TraderApi{sdkOptions: sdkOptions{production: true}}
	for _, option := range options {
		option(a)
	}
	a.open(a.sdkOptions, traderFactoryName, traderVersionName, (*traderSPI).initialize, func(factory uintptr) *traderObject {
		var create func(string, bool) *traderObject
		purego.RegisterFunc(&create, factory)
		return create(a.flowPath, a.production)
	})
	a.methods.bind(a.obj.vtable)
	a.methods.RegisterSpi(a.obj, a.spi)
	return a
}

func (a *TraderApi) RegisterSpi(spi thost.TraderSpi) {
	if spi == nil {
		receivers.Delete(a.spi)
	} else {
		receivers.Store(a.spi, spi)
	}
}
func (a *TraderApi) Release() { a.close(a.methods.RegisterSpi, a.methods.Release) }

func (a *TraderApi) SubscribePrivateTopic(mode thost.THOST_TE_RESUME_TYPE, seq ...int) {
	first := 1
	if len(seq) > 0 {
		first = seq[0]
	}
	a.methods.SubscribePrivateTopic(a.obj, mode, int32(first))
}

var (
	traderCallbacksOnce sync.Once
	traderCallbacks     [traderCallbackCount]uintptr
)

func (s *traderSPI) initialize() {
	traderCallbacksOnce.Do(func() { traderCallbacks = makeTraderCallbacks() })
	s.methods = traderCallbacks
	s.vptr = &s.methods[0]
}

func traderReceiver(this *traderSPI) thost.TraderSpi {
	s, ok := receivers.Load(this)
	if !ok {
		return nil
	}
	return s.(thost.TraderSpi)
}

func traderResponse[T any](method func(thost.TraderSpi, *T, *thost.CThostFtdcRspInfoField, int, bool)) uintptr {
	return purego.NewCallback(func(this *traderSPI, data *T, info *thost.CThostFtdcRspInfoField, id int32, last uint8) uintptr {
		if s := traderReceiver(this); s != nil {
			method(s, data, info, int(id), last != 0)
		}
		return 0
	})
}
func traderNotification[T any](method func(thost.TraderSpi, *T)) uintptr {
	return purego.NewCallback(func(this *traderSPI, data *T) uintptr {
		if s := traderReceiver(this); s != nil {
			method(s, data)
		}
		return 0
	})
}
func traderErrorReturn[T any](method func(thost.TraderSpi, *T, *thost.CThostFtdcRspInfoField)) uintptr {
	return purego.NewCallback(func(this *traderSPI, data *T, info *thost.CThostFtdcRspInfoField) uintptr {
		if s := traderReceiver(this); s != nil {
			method(s, data, info)
		}
		return 0
	})
}
func traderIntCallback(method func(thost.TraderSpi, int)) uintptr {
	return purego.NewCallback(func(this *traderSPI, n int32) uintptr {
		if s := traderReceiver(this); s != nil {
			method(s, int(n))
		}
		return 0
	})
}
