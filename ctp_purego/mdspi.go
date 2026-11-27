//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

import (
	"sync"

	"github.com/ebitengine/purego"
	"github.com/pseudocodes/go2ctp/thost"
)

// Both the SPI object and its virtual table live in native, non-moving memory.
// The vptr points at the first method. The preceding words reserve the ABI's
// metadata slots; this adapter supports virtual dispatch, not C++ RTTI casts.
type nativeSPI struct {
	vptr     *uintptr
	metadata [2]uintptr
	methods  [13]uintptr
}

var (
	callbacksOnce sync.Once
	callbacks     [13]uintptr
	receivers     sync.Map // Native SPI pointer -> its Go receiver, accessed from SDK threads.
)

func receiver(this *nativeSPI) thost.MdSpi {
	s, _ := receivers.Load(this)
	if s == nil {
		return nil
	}
	return s.(thost.MdSpi)
}

func (s *nativeSPI) initialize() {
	callbacksOnce.Do(func() {
		// Address-point order of CThostFtdcMdSpi in the CTP 6.7.13 SDK.
		callbacks = [13]uintptr{
			purego.NewCallback(func(this *nativeSPI) uintptr {
				if s := receiver(this); s != nil {
					s.OnFrontConnected()
				}
				return 0
			}),
			integerCallback(thost.MdSpi.OnFrontDisconnected),
			integerCallback(thost.MdSpi.OnHeartBeatWarning),
			responseCallback(thost.MdSpi.OnRspUserLogin),
			responseCallback(thost.MdSpi.OnRspUserLogout),
			responseCallback(thost.MdSpi.OnRspQryMulticastInstrument),
			purego.NewCallback(func(this *nativeSPI, info *thost.CThostFtdcRspInfoField, id int32, last uint8) uintptr {
				if s := receiver(this); s != nil {
					s.OnRspError(info, int(id), last != 0)
				}
				return 0
			}),
			responseCallback(thost.MdSpi.OnRspSubMarketData),
			responseCallback(thost.MdSpi.OnRspUnSubMarketData),
			responseCallback(thost.MdSpi.OnRspSubForQuoteRsp),
			responseCallback(thost.MdSpi.OnRspUnSubForQuoteRsp),
			notificationCallback(thost.MdSpi.OnRtnDepthMarketData),
			notificationCallback(thost.MdSpi.OnRtnForQuoteRsp),
		}
	})
	s.methods = callbacks
	s.vptr = &s.methods[0]
}

func integerCallback(method func(thost.MdSpi, int)) uintptr {
	return purego.NewCallback(func(this *nativeSPI, value int32) uintptr {
		if s := receiver(this); s != nil {
			method(s, int(value))
		}
		return 0
	})
}

func responseCallback[T any](method func(thost.MdSpi, *T, *thost.CThostFtdcRspInfoField, int, bool)) uintptr {
	return purego.NewCallback(func(this *nativeSPI, data *T, info *thost.CThostFtdcRspInfoField, id int32, last uint8) uintptr {
		if s := receiver(this); s != nil {
			method(s, data, info, int(id), last != 0)
		}
		return 0
	})
}

func notificationCallback[T any](method func(thost.MdSpi, *T)) uintptr {
	return purego.NewCallback(func(this *nativeSPI, data *T) uintptr {
		if s := receiver(this); s != nil {
			method(s, data)
		}
		return 0
	})
}

// BaseMdSpi supplies empty callbacks. Embed it to implement only the events you use.
type BaseMdSpi struct{}

func (BaseMdSpi) OnFrontConnected() {}

func (BaseMdSpi) OnFrontDisconnected(nReason int) {}

func (BaseMdSpi) OnHeartBeatWarning(nTimeLapse int) {}

func (BaseMdSpi) OnRspUserLogin(pRspUserLogin *thost.CThostFtdcRspUserLoginField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRspUserLogout(pUserLogout *thost.CThostFtdcUserLogoutField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRspQryMulticastInstrument(pMulticastInstrument *thost.CThostFtdcMulticastInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRspError(pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {}

func (BaseMdSpi) OnRspSubMarketData(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRspUnSubMarketData(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRspSubForQuoteRsp(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRspUnSubForQuoteRsp(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
}

func (BaseMdSpi) OnRtnDepthMarketData(pDepthMarketData *thost.CThostFtdcDepthMarketDataField) {}

func (BaseMdSpi) OnRtnForQuoteRsp(pForQuoteRsp *thost.CThostFtdcForQuoteRspField) {}
