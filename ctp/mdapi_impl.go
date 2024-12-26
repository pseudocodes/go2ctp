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

package ctp

/*
#include <stdint.h>
#include <stdlib.h>

#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"

// typedef long long intgo;

typedef struct { char *p; int64_t n; } _gostring_;
typedef struct { void* array; int64_t len; int64_t cap; } _goslice_;

extern uintptr_t _wrap_CThostFtdcMdApi_CreateFtdcMdApi();
extern uintptr_t _wrap_CThostFtdcMdApi_CreateFtdcMdApi2(uintptr_t goUserApi, char*, _Bool, _Bool);


extern const char * _wrap_CThostFtdcMdApi_GetApiVersion(uintptr_t);

extern void _wrap_CThostFtdcMdApi_Release(uintptr_t);

extern void _wrap_CThostFtdcMdApi_Init(uintptr_t);

extern int64_t _wrap_CThostFtdcMdApi_Join(uintptr_t);

extern const char * _wrap_CThostFtdcMdApi_GetTradingDay(uintptr_t);

extern void _wrap_CThostFtdcMdApi_RegisterFront(uintptr_t, char *);

extern void _wrap_CThostFtdcMdApi_RegisterNameServer(uintptr_t, char *);

extern void _wrap_CThostFtdcMdApi_RegisterFensUserInfo(uintptr_t, struct CThostFtdcFensUserInfoField *);

extern void _wrap_CThostFtdcMdApi_RegisterSpi(uintptr_t, uintptr_t);

extern int64_t _wrap_CThostFtdcMdApi_SubscribeMarketData(uintptr_t, char **, int);

extern int64_t _wrap_CThostFtdcMdApi_UnSubscribeMarketData(uintptr_t, char **, int);

extern int64_t _wrap_CThostFtdcMdApi_SubscribeForQuoteRsp(uintptr_t, char **, int);

extern int64_t _wrap_CThostFtdcMdApi_UnSubscribeForQuoteRsp(uintptr_t, char **, int);

extern int64_t _wrap_CThostFtdcMdApi_ReqUserLogin(uintptr_t, struct CThostFtdcReqUserLoginField *, int);

extern int64_t _wrap_CThostFtdcMdApi_ReqUserLogout(uintptr_t, struct CThostFtdcUserLogoutField *, int);

extern int64_t _wrap_CThostFtdcMdApi_ReqQryMulticastInstrument(uintptr_t, struct CThostFtdcQryMulticastInstrumentField *, int);

*/
import "C"
import (
	"os"
	"path/filepath"
	"runtime/cgo"
	"strings"
	"unsafe"

	"github.com/pseudocodes/go2ctp/thost"
)

const (
	defaultFlowPath    = ""
	defaultIsUsingUdp  = false
	defaultIsMulticast = false
)

type MdOption func(api *MdApi)

type MdApi struct {
	apiPtr uintptr
	spi    thost.MdSpi

	flowPath  string
	usingUDP  bool
	multicast bool
}

func CreateMdApi(options ...MdOption) thost.MdApi {
	api := &MdApi{
		flowPath:  defaultFlowPath,
		usingUDP:  defaultIsUsingUdp,
		multicast: defaultIsMulticast,
	}
	handle := cgo.NewHandle(api)
	for _, opt := range options {
		opt(api)
	}
	if api.flowPath != "" {
		var err error
		if strings.HasSuffix(api.flowPath, "/") {
			err = os.MkdirAll(api.flowPath, os.ModePerm)
		} else {
			parentDir := filepath.Dir(api.flowPath)
			err = os.MkdirAll(parentDir, os.ModePerm)
		}
		if err != nil && !os.IsExist(err) {
			panic(err)
		}
	}
	cflowPath := C.CString(api.flowPath)
	defer C.free(unsafe.Pointer(cflowPath))

	api.apiPtr = uintptr(C._wrap_CThostFtdcMdApi_CreateFtdcMdApi2(C.uintptr_t(handle), cflowPath, C._Bool(api.usingUDP), C._Bool(api.multicast)))

	return api
}

// /获取API的版本信息
// /@retrun 获取到的版本号
func (c *MdApi) GetApiVersion() string {
	cString := C._wrap_CThostFtdcMdApi_GetApiVersion(C.uintptr_t(c.apiPtr))
	return C.GoString(cString)
}

// 删除接口对象本身
// /@remark 不再使用本接口对象时,调用该函数删除接口对象
func (c *MdApi) Release() {
	C._wrap_CThostFtdcMdApi_RegisterSpi(C.uintptr_t(c.apiPtr), C.uintptr_t(0))
	C._wrap_CThostFtdcMdApi_Release(C.uintptr_t(c.apiPtr))
}

// 初始化
// /@remark 初始化运行环境,只有调用后,接口才开始工作
func (c *MdApi) Init() {
	C._wrap_CThostFtdcMdApi_Init(C.uintptr_t(c.apiPtr))
}

// 等待接口线程结束运行
// /@return 线程退出代码
func (c *MdApi) Join() int {
	return (int)(C._wrap_CThostFtdcMdApi_Join(C.uintptr_t(c.apiPtr)))
}

// /获取当前交易日
// /@retrun 获取到的交易日
// /@remark 只有登录成功后,才能得到正确的交易日
func (c *MdApi) GetTradingDay() string {
	cString := C._wrap_CThostFtdcMdApi_GetTradingDay(C.uintptr_t(c.apiPtr))
	return C.GoString(cString)
}

func (c *MdApi) RegisterFront(frontAddress string) {
	addr := C.CString(frontAddress)
	defer C.free(unsafe.Pointer(addr))
	C._wrap_CThostFtdcMdApi_RegisterFront(C.uintptr_t(c.apiPtr), addr)
}

// 注册名字服务器用户信息
func (c *MdApi) RegisterNameServer(nsAddress string) {
	addr := C.CString(nsAddress)
	defer C.free(unsafe.Pointer(addr))
	C._wrap_CThostFtdcMdApi_RegisterNameServer(C.uintptr_t(c.apiPtr), addr)
}

// /@param pFensUserInfo：用户信息。
func (c *MdApi) RegisterFensUserInfo(pFensUserInfo *thost.CThostFtdcFensUserInfoField) {
	C._wrap_CThostFtdcMdApi_RegisterFensUserInfo(C.uintptr_t(c.apiPtr), (*C.struct_CThostFtdcFensUserInfoField)(unsafe.Pointer(pFensUserInfo)))
}

// 注册回调接口
// /@param pSpi 派生自回调接口类的实例
func (c *MdApi) RegisterSpi(pSpi thost.MdSpi) {
	c.spi = pSpi
}

// /订阅行情。
// /@param ppInstrumentID 合约ID
// /@param nCount 要订阅/退订行情的合约个数
// /@remark
func (c *MdApi) SubscribeMarketData(instrumentIDs ...string) int {
	cinlist := []*C.char{}
	for _, ins := range instrumentIDs {
		cinlist = append(cinlist, C.CString(ins))
	}
	defer func() {
		for i := range cinlist {
			C.free(unsafe.Pointer(cinlist[i]))
		}
	}()

	return (int)(C._wrap_CThostFtdcMdApi_SubscribeMarketData(C.uintptr_t(c.apiPtr), (**C.char)(unsafe.Pointer(&cinlist[0])), C.int(len(cinlist))))
}

// /退订行情。
// /@param ppInstrumentID 合约ID
// /@param nCount 要订阅/退订行情的合约个数
// /@remark
func (c *MdApi) UnSubscribeMarketData(instrumentIDs ...string) int {
	cinlist := []*C.char{}
	for _, ins := range instrumentIDs {
		cinlist = append(cinlist, C.CString(ins))
	}
	defer func() {
		for i := range cinlist {
			C.free(unsafe.Pointer(cinlist[i]))
		}
	}()

	return (int)(C._wrap_CThostFtdcMdApi_UnSubscribeMarketData(C.uintptr_t(c.apiPtr), (**C.char)(unsafe.Pointer(&cinlist[0])), C.int(len(cinlist))))
}

// /订阅询价。
// /@param ppInstrumentID 合约ID
// /@param nCount 要订阅/退订行情的合约个数
// /@remark
func (c *MdApi) SubscribeForQuoteRsp(instrumentIDs ...string) int {
	cinlist := []*C.char{}
	for _, ins := range instrumentIDs {
		cinlist = append(cinlist, C.CString(ins))
	}
	defer func() {
		for i := range cinlist {
			C.free(unsafe.Pointer(cinlist[i]))
		}
	}()

	return (int)(C._wrap_CThostFtdcMdApi_SubscribeForQuoteRsp(C.uintptr_t(c.apiPtr), (**C.char)(unsafe.Pointer(&cinlist[0])), C.int(len(cinlist))))
}

// /退订询价。
// /@param ppInstrumentID 合约ID
// /@param nCount 要订阅/退订行情的合约个数
// /@remark
func (c *MdApi) UnSubscribeForQuoteRsp(instrumentIDs ...string) int {
	cinlist := []*C.char{}
	for _, ins := range instrumentIDs {
		cinlist = append(cinlist, C.CString(ins))
	}
	defer func() {
		for i := range cinlist {
			C.free(unsafe.Pointer(cinlist[i]))
		}
	}()

	return (int)(C._wrap_CThostFtdcMdApi_UnSubscribeForQuoteRsp(C.uintptr_t(c.apiPtr), (**C.char)(unsafe.Pointer(&cinlist[0])), C.int(len(cinlist))))
}

// 用户登录请求
func (c *MdApi) ReqUserLogin(pReqUserLoginField *thost.CThostFtdcReqUserLoginField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcMdApi_ReqUserLogin(C.uintptr_t(c.apiPtr), (*C.struct_CThostFtdcReqUserLoginField)(unsafe.Pointer(pReqUserLoginField)), C.int(nRequestID)))
}

// 登出请求
func (c *MdApi) ReqUserLogout(pUserLogout *thost.CThostFtdcUserLogoutField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcMdApi_ReqUserLogout(C.uintptr_t(c.apiPtr), (*C.struct_CThostFtdcUserLogoutField)(unsafe.Pointer(pUserLogout)), C.int(nRequestID)))
}

// 请求查询组播合约
func (c *MdApi) ReqQryMulticastInstrument(pQryMulticastInstrument *thost.CThostFtdcQryMulticastInstrumentField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcMdApi_ReqQryMulticastInstrument(C.uintptr_t(c.apiPtr), (*C.struct_CThostFtdcQryMulticastInstrumentField)(unsafe.Pointer(pQryMulticastInstrument)), C.int(nRequestID)))
}

//export wrapMdOnFrontConnected
func wrapMdOnFrontConnected(v uintptr) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnFrontConnected()
}

//export wrapMdOnFrontDisconnected
func wrapMdOnFrontDisconnected(v uintptr, nReason C.int) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnFrontDisconnected(int(nReason))
}

//export wrapMdOnHeartBeatWarning
func wrapMdOnHeartBeatWarning(v uintptr, nTimeLapse C.int) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnHeartBeatWarning(int(nTimeLapse))
}

//export wrapMdOnRspUserLogin
func wrapMdOnRspUserLogin(v uintptr, pRspUserLogin *C.struct_CThostFtdcRspUserLoginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspUserLogin((*thost.CThostFtdcRspUserLoginField)(unsafe.Pointer(pRspUserLogin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspUserLogout
func wrapMdOnRspUserLogout(v uintptr, pUserLogout *C.struct_CThostFtdcUserLogoutField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspUserLogout((*thost.CThostFtdcUserLogoutField)(unsafe.Pointer(pUserLogout)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspQryMulticastInstrument
func wrapMdOnRspQryMulticastInstrument(v uintptr, pMulticastInstrument *C.struct_CThostFtdcMulticastInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspQryMulticastInstrument((*thost.CThostFtdcMulticastInstrumentField)(unsafe.Pointer(pMulticastInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspError
func wrapMdOnRspError(v uintptr, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspError((*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspSubMarketData
func wrapMdOnRspSubMarketData(v uintptr, pSpecificInstrument *C.struct_CThostFtdcSpecificInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspSubMarketData((*thost.CThostFtdcSpecificInstrumentField)(unsafe.Pointer(pSpecificInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspUnSubMarketData
func wrapMdOnRspUnSubMarketData(v uintptr, pSpecificInstrument *C.struct_CThostFtdcSpecificInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspUnSubMarketData((*thost.CThostFtdcSpecificInstrumentField)(unsafe.Pointer(pSpecificInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspSubForQuoteRsp
func wrapMdOnRspSubForQuoteRsp(v uintptr, pSpecificInstrument *C.struct_CThostFtdcSpecificInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspSubForQuoteRsp((*thost.CThostFtdcSpecificInstrumentField)(unsafe.Pointer(pSpecificInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRspUnSubForQuoteRsp
func wrapMdOnRspUnSubForQuoteRsp(v uintptr, pSpecificInstrument *C.struct_CThostFtdcSpecificInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRspUnSubForQuoteRsp((*thost.CThostFtdcSpecificInstrumentField)(unsafe.Pointer(pSpecificInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapMdOnRtnDepthMarketData
func wrapMdOnRtnDepthMarketData(v uintptr, pDepthMarketData *C.struct_CThostFtdcDepthMarketDataField) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRtnDepthMarketData((*thost.CThostFtdcDepthMarketDataField)(unsafe.Pointer(pDepthMarketData)))
}

//export wrapMdOnRtnForQuoteRsp
func wrapMdOnRtnForQuoteRsp(v uintptr, pForQuoteRsp *C.struct_CThostFtdcForQuoteRspField) {
	api := cgo.Handle(v).Value().(*MdApi)
	api.spi.OnRtnForQuoteRsp((*thost.CThostFtdcForQuoteRspField)(unsafe.Pointer(pForQuoteRsp)))
}

// -----------------------------------------------------
func MdFlowPath(path string) MdOption {
	return func(api *MdApi) {
		api.flowPath = path
	}
}

func MdUsingUDP(usingudp bool) MdOption {
	return func(api *MdApi) {
		api.usingUDP = usingudp
	}
}

func MdMultiCast(multicast bool) MdOption {
	return func(api *MdApi) {
		api.multicast = multicast
	}
}
