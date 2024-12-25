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

extern uintptr_t _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi();
extern uintptr_t _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi2(uintptr_t, char *);

// extern CThostFtdcTraderApi * _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi(uintptr_t, const char *);

extern const char * _wrap_CThostFtdcTraderApi_GetApiVersion(uintptr_t);

extern void _wrap_CThostFtdcTraderApi_Release(uintptr_t);

extern void _wrap_CThostFtdcTraderApi_Init(uintptr_t);

extern int _wrap_CThostFtdcTraderApi_Join(uintptr_t);

extern const char * _wrap_CThostFtdcTraderApi_GetTradingDay(uintptr_t);

extern void _wrap_CThostFtdcTraderApi_GetFrontInfo(uintptr_t, struct CThostFtdcFrontInfoField *);

extern void _wrap_CThostFtdcTraderApi_RegisterFront(uintptr_t, char *);

extern void _wrap_CThostFtdcTraderApi_RegisterNameServer(uintptr_t, char *);

extern void _wrap_CThostFtdcTraderApi_RegisterFensUserInfo(uintptr_t, struct CThostFtdcFensUserInfoField *);

extern void _wrap_CThostFtdcTraderApi_RegisterSpi(uintptr_t, uintptr_t);

extern void _wrap_CThostFtdcTraderApi_SubscribePrivateTopic(uintptr_t, enum THOST_TE_RESUME_TYPE);

extern void _wrap_CThostFtdcTraderApi_SubscribePublicTopic(uintptr_t, enum THOST_TE_RESUME_TYPE);

extern int _wrap_CThostFtdcTraderApi_ReqAuthenticate(uintptr_t, struct CThostFtdcReqAuthenticateField *, int);

extern int _wrap_CThostFtdcTraderApi_RegisterUserSystemInfo(uintptr_t, struct CThostFtdcUserSystemInfoField *);

extern int _wrap_CThostFtdcTraderApi_SubmitUserSystemInfo(uintptr_t, struct CThostFtdcUserSystemInfoField *);

extern int _wrap_CThostFtdcTraderApi_ReqUserLogin(uintptr_t, struct CThostFtdcReqUserLoginField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqUserLoginMac(uintptr_t, struct CThostFtdcReqUserLoginField *, int, int, char*);

extern int _wrap_CThostFtdcTraderApi_ReqUserLogout(uintptr_t, struct CThostFtdcUserLogoutField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqUserPasswordUpdate(uintptr_t, struct CThostFtdcUserPasswordUpdateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(uintptr_t, struct CThostFtdcTradingAccountPasswordUpdateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqUserAuthMethod(uintptr_t, struct CThostFtdcReqUserAuthMethodField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqGenUserCaptcha(uintptr_t, struct CThostFtdcReqGenUserCaptchaField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqGenUserText(uintptr_t, struct CThostFtdcReqGenUserTextField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqUserLoginWithCaptcha(uintptr_t, struct CThostFtdcReqUserLoginWithCaptchaField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqUserLoginWithText(uintptr_t, struct CThostFtdcReqUserLoginWithTextField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqUserLoginWithOTP(uintptr_t, struct CThostFtdcReqUserLoginWithOTPField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqOrderInsert(uintptr_t, struct CThostFtdcInputOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqParkedOrderInsert(uintptr_t, struct CThostFtdcParkedOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqParkedOrderAction(uintptr_t, struct CThostFtdcParkedOrderActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqOrderAction(uintptr_t, struct CThostFtdcInputOrderActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryMaxOrderVolume(uintptr_t, struct CThostFtdcQryMaxOrderVolumeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqSettlementInfoConfirm(uintptr_t, struct CThostFtdcSettlementInfoConfirmField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqRemoveParkedOrder(uintptr_t, struct CThostFtdcRemoveParkedOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqRemoveParkedOrderAction(uintptr_t, struct CThostFtdcRemoveParkedOrderActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqExecOrderInsert(uintptr_t, struct CThostFtdcInputExecOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqExecOrderAction(uintptr_t, struct CThostFtdcInputExecOrderActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqForQuoteInsert(uintptr_t, struct CThostFtdcInputForQuoteField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQuoteInsert(uintptr_t, struct CThostFtdcInputQuoteField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQuoteAction(uintptr_t, struct CThostFtdcInputQuoteActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqBatchOrderAction(uintptr_t, struct CThostFtdcInputBatchOrderActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqOptionSelfCloseInsert(uintptr_t, struct CThostFtdcInputOptionSelfCloseField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqOptionSelfCloseAction(uintptr_t, struct CThostFtdcInputOptionSelfCloseActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqCombActionInsert(uintptr_t, struct CThostFtdcInputCombActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryOrder(uintptr_t, struct CThostFtdcQryOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTrade(uintptr_t, struct CThostFtdcQryTradeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorPosition(uintptr_t, struct CThostFtdcQryInvestorPositionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTradingAccount(uintptr_t, struct CThostFtdcQryTradingAccountField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestor(uintptr_t, struct CThostFtdcQryInvestorField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTradingCode(uintptr_t, struct CThostFtdcQryTradingCodeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInstrumentMarginRate(uintptr_t, struct CThostFtdcQryInstrumentMarginRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(uintptr_t, struct CThostFtdcQryInstrumentCommissionRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryExchange(uintptr_t, struct CThostFtdcQryExchangeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryProduct(uintptr_t, struct CThostFtdcQryProductField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInstrument(uintptr_t, struct CThostFtdcQryInstrumentField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryDepthMarketData(uintptr_t, struct CThostFtdcQryDepthMarketDataField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTraderOffer(uintptr_t, struct CThostFtdcQryTraderOfferField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySettlementInfo(uintptr_t, struct CThostFtdcQrySettlementInfoField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTransferBank(uintptr_t, struct CThostFtdcQryTransferBankField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorPositionDetail(uintptr_t, struct CThostFtdcQryInvestorPositionDetailField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryNotice(uintptr_t, struct CThostFtdcQryNoticeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(uintptr_t, struct CThostFtdcQrySettlementInfoConfirmField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(uintptr_t, struct CThostFtdcQryInvestorPositionCombineDetailField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(uintptr_t, struct CThostFtdcQryCFMMCTradingAccountKeyField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryEWarrantOffset(uintptr_t, struct CThostFtdcQryEWarrantOffsetField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(uintptr_t, struct CThostFtdcQryInvestorProductGroupMarginField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRate(uintptr_t, struct CThostFtdcQryExchangeMarginRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(uintptr_t, struct CThostFtdcQryExchangeMarginRateAdjustField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryExchangeRate(uintptr_t, struct CThostFtdcQryExchangeRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySecAgentACIDMap(uintptr_t, struct CThostFtdcQrySecAgentACIDMapField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryProductExchRate(uintptr_t, struct CThostFtdcQryProductExchRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryProductGroup(uintptr_t, struct CThostFtdcQryProductGroupField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(uintptr_t, struct CThostFtdcQryMMInstrumentCommissionRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(uintptr_t, struct CThostFtdcQryMMOptionInstrCommRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(uintptr_t, struct CThostFtdcQryInstrumentOrderCommRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(uintptr_t, struct CThostFtdcQryTradingAccountField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySecAgentCheckMode(uintptr_t, struct CThostFtdcQrySecAgentCheckModeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(uintptr_t, struct CThostFtdcQrySecAgentTradeInfoField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(uintptr_t, struct CThostFtdcQryOptionInstrTradeCostField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryOptionInstrCommRate(uintptr_t, struct CThostFtdcQryOptionInstrCommRateField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryExecOrder(uintptr_t, struct CThostFtdcQryExecOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryForQuote(uintptr_t, struct CThostFtdcQryForQuoteField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryQuote(uintptr_t, struct CThostFtdcQryQuoteField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryOptionSelfClose(uintptr_t, struct CThostFtdcQryOptionSelfCloseField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestUnit(uintptr_t, struct CThostFtdcQryInvestUnitField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryCombInstrumentGuard(uintptr_t, struct CThostFtdcQryCombInstrumentGuardField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryCombAction(uintptr_t, struct CThostFtdcQryCombActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTransferSerial(uintptr_t, struct CThostFtdcQryTransferSerialField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryAccountregister(uintptr_t, struct CThostFtdcQryAccountregisterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryContractBank(uintptr_t, struct CThostFtdcQryContractBankField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryParkedOrder(uintptr_t, struct CThostFtdcQryParkedOrderField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryParkedOrderAction(uintptr_t, struct CThostFtdcQryParkedOrderActionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryTradingNotice(uintptr_t, struct CThostFtdcQryTradingNoticeField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryBrokerTradingParams(uintptr_t, struct CThostFtdcQryBrokerTradingParamsField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(uintptr_t, struct CThostFtdcQryBrokerTradingAlgosField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(uintptr_t, struct CThostFtdcQueryCFMMCTradingAccountTokenField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqFromBankToFutureByFuture(uintptr_t, struct CThostFtdcReqTransferField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqFromFutureToBankByFuture(uintptr_t, struct CThostFtdcReqTransferField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(uintptr_t, struct CThostFtdcReqQueryAccountField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryClassifiedInstrument(uintptr_t, struct CThostFtdcQryClassifiedInstrumentField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryCombPromotionParam(uintptr_t, struct CThostFtdcQryCombPromotionParamField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(uintptr_t, struct CThostFtdcQryRiskSettleInvstPositionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(uintptr_t, struct CThostFtdcQryRiskSettleProductStatusField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMFutureParameter(uintptr_t, struct CThostFtdcQrySPBMFutureParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMOptionParameter(uintptr_t, struct CThostFtdcQrySPBMOptionParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMIntraParameter(uintptr_t, struct CThostFtdcQrySPBMIntraParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMInterParameter(uintptr_t, struct CThostFtdcQrySPBMInterParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMPortfDefinition(uintptr_t, struct CThostFtdcQrySPBMPortfDefinitionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMInvestorPortfDef(uintptr_t, struct CThostFtdcQrySPBMInvestorPortfDefField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorPortfMarginRatio(uintptr_t, struct CThostFtdcQryInvestorPortfMarginRatioField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdSPBMDetail(uintptr_t, struct CThostFtdcQryInvestorProdSPBMDetailField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorCommoditySPMMMargin(uintptr_t, struct CThostFtdcQryInvestorCommoditySPMMMarginField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorCommodityGroupSPMMMargin(uintptr_t, struct CThostFtdcQryInvestorCommodityGroupSPMMMarginField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPMMInstParam(uintptr_t, struct CThostFtdcQrySPMMInstParamField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPMMProductParam(uintptr_t, struct CThostFtdcQrySPMMProductParamField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQrySPBMAddOnInterParameter(uintptr_t, struct CThostFtdcQrySPBMAddOnInterParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRCAMSCombProductInfo(uintptr_t, struct CThostFtdcQryRCAMSCombProductInfoField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInstrParameter(uintptr_t, struct CThostFtdcQryRCAMSInstrParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRCAMSIntraParameter(uintptr_t, struct CThostFtdcQryRCAMSIntraParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInterParameter(uintptr_t, struct CThostFtdcQryRCAMSInterParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRCAMSShortOptAdjustParam(uintptr_t, struct CThostFtdcQryRCAMSShortOptAdjustParamField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInvestorCombPosition(uintptr_t, struct CThostFtdcQryRCAMSInvestorCombPositionField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdRCAMSMargin(uintptr_t, struct CThostFtdcQryInvestorProdRCAMSMarginField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRULEInstrParameter(uintptr_t, struct CThostFtdcQryRULEInstrParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRULEIntraParameter(uintptr_t, struct CThostFtdcQryRULEIntraParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryRULEInterParameter(uintptr_t, struct CThostFtdcQryRULEInterParameterField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdRULEMargin(uintptr_t, struct CThostFtdcQryInvestorProdRULEMarginField *, int);

extern int _wrap_CThostFtdcTraderApi_ReqQryInvestorPortfSetting(uintptr_t, struct CThostFtdcQryInvestorPortfSettingField *, int);

*/
import "C"
import (
	"os"
	"path/filepath"
	"runtime"
	"runtime/cgo"
	"strings"
	"unsafe"

	"github.com/pseudocodes/go2ctp/thost"
)

type TraderOption func(api *TraderApi)

func TraderFlowPath(path string) TraderOption {
	return func(api *TraderApi) {
		api.flowPath = path
	}
}

func TraderSystemInfo(systemInfo []byte, length int) TraderOption {
	return func(api *TraderApi) {
		api.length = length
		copy(api.systemInfo[:], systemInfo)
	}
}

type TraderApi struct {
	apiPtr uintptr
	spi    thost.TraderSpi

	length     int
	systemInfo [273]byte

	flowPath string
}

func CreateTraderApi(options ...TraderOption) thost.TraderApi {
	api := &TraderApi{
		flowPath: defaultFlowPath,
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

	api.apiPtr = uintptr(C._wrap_CThostFtdcTraderApi_CreateFtdcTraderApi2(C.uintptr_t(handle), cflowPath))
	return api
}

// / 获取API的版本信息
// /@retrun 获取到的版本号
func (s *TraderApi) GetApiVersion() string {
	cstr := C._wrap_CThostFtdcTraderApi_GetApiVersion(C.uintptr_t(s.apiPtr))
	return C.GoString(cstr)
}

// / 删除接口对象本身
// /@remark 不再使用本接口对象时,调用该函数删除接口对象
func (s *TraderApi) Release() {
	C._wrap_CThostFtdcTraderApi_RegisterSpi(C.uintptr_t(s.apiPtr), C.uintptr_t(0))
	C._wrap_CThostFtdcTraderApi_Release(C.uintptr_t(s.apiPtr))

}

// / 初始化
// /@remark 初始化运行环境,只有调用后,接口才开始工作
func (s *TraderApi) Init() {
	C._wrap_CThostFtdcTraderApi_Init(C.uintptr_t(s.apiPtr))
}

// / 等待接口线程结束运行
// /@return 线程退出代码
func (s *TraderApi) Join() int {
	return (int)(C._wrap_CThostFtdcTraderApi_Join(C.uintptr_t(s.apiPtr)))
}

// / 获取当前交易日
// /@retrun 获取到的交易日
// /@remark 只有登录成功后,才能得到正确的交易日
func (s *TraderApi) GetTradingDay() string {
	cstr := C._wrap_CThostFtdcTraderApi_GetTradingDay(C.uintptr_t(s.apiPtr))
	return C.GoString(cstr)
}

// / 获取已连接的前置的信息
// /  @param pFrontInfo：输入输出参数，用于存储获取到的前置信息，不能为空
// /  @remark 连接成功后，可获取正确的前置地址信息
// /  @remark 登录成功后，可获取正确的前置流控信息
func (s *TraderApi) GetFrontInfo(pFrontInfo *thost.CThostFtdcFrontInfoField) {
	C._wrap_CThostFtdcTraderApi_GetFrontInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcFrontInfoField)(unsafe.Pointer(pFrontInfo)))
}

// / 注册前置机网络地址
// /@param pszFrontAddress：前置机网络地址。
// /@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
// /@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
func (s *TraderApi) RegisterFront(pszFrontAddress string) {
	addr := C.CString(pszFrontAddress)
	defer C.free(unsafe.Pointer(addr))
	C._wrap_CThostFtdcTraderApi_RegisterFront(C.uintptr_t(s.apiPtr), addr)
}

// / 注册名字服务器网络地址
// /@param pszNsAddress：名字服务器网络地址。
// /@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
// /@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
// /@remark RegisterNameServer优先于RegisterFront
func (s *TraderApi) RegisterNameServer(pszNsAddress string) {
	addr := C.CString(pszNsAddress)
	defer C.free(unsafe.Pointer(addr))
	C._wrap_CThostFtdcTraderApi_RegisterNameServer(C.uintptr_t(s.apiPtr), addr)
}

// / 注册名字服务器用户信息
// /@param pFensUserInfo：用户信息。
func (s *TraderApi) RegisterFensUserInfo(pFensUserInfo *thost.CThostFtdcFensUserInfoField) {
	C._wrap_CThostFtdcTraderApi_RegisterFensUserInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcFensUserInfoField)(unsafe.Pointer(pFensUserInfo)))
}

// / 注册回调接口
// /@param pSpi 派生自回调接口类的实例
func (s *TraderApi) RegisterSpi(pSpi thost.TraderSpi) {
	s.spi = pSpi
}

// / 订阅私有流。
// /@param nResumeType 私有流重传方式
// /         THOST_TERT_RESTART:从本交易日开始重传
// /         THOST_TERT_RESUME:从上次收到的续传
// /         THOST_TERT_QUICK:只传送登录后私有流的内容
// /@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
func (s *TraderApi) SubscribePrivateTopic(nResumeType thost.THOST_TE_RESUME_TYPE) {
	C._wrap_CThostFtdcTraderApi_SubscribePrivateTopic(C.uintptr_t(s.apiPtr), C.enum_THOST_TE_RESUME_TYPE(nResumeType))
}

// / 订阅公共流。
// /@param nResumeType 公共流重传方式
// /         THOST_TERT_RESTART:从本交易日开始重传
// /         THOST_TERT_RESUME:从上次收到的续传
// /         THOST_TERT_QUICK:只传送登录后公共流的内容
// /         THOST_TERT_NONE:取消订阅公共流
// /@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
func (s *TraderApi) SubscribePublicTopic(nResumeType thost.THOST_TE_RESUME_TYPE) {
	C._wrap_CThostFtdcTraderApi_SubscribePublicTopic(C.uintptr_t(s.apiPtr), C.enum_THOST_TE_RESUME_TYPE(nResumeType))
}

// / 客户端认证请求
func (s *TraderApi) ReqAuthenticate(pReqAuthenticateField *thost.CThostFtdcReqAuthenticateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqAuthenticate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqAuthenticateField)(unsafe.Pointer(pReqAuthenticateField)), C.int(nRequestID)))
}

// / 注册用户终端信息，用于中继服务器多连接模式
// / 需要在终端认证成功后，用户登录前调用该接口
func (s *TraderApi) RegisterUserSystemInfo(pUserSystemInfo *thost.CThostFtdcUserSystemInfoField) int {
	return (int)(C._wrap_CThostFtdcTraderApi_RegisterUserSystemInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcUserSystemInfoField)(unsafe.Pointer(pUserSystemInfo))))
}

// / 上报用户终端信息，用于中继服务器操作员登录模式
// / 操作员登录后，可以多次调用该接口上报客户信息
func (s *TraderApi) SubmitUserSystemInfo(pUserSystemInfo *thost.CThostFtdcUserSystemInfoField) int {
	return (int)(C._wrap_CThostFtdcTraderApi_SubmitUserSystemInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcUserSystemInfoField)(unsafe.Pointer(pUserSystemInfo))))
}

// 用户登录请求
func (s *TraderApi) ReqUserLogin(pReqUserLoginField *thost.CThostFtdcReqUserLoginField, nRequestID int) int {
	if runtime.GOOS != "darwin" {
		return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLogin(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserLoginField)(unsafe.Pointer(pReqUserLoginField)), C.int(nRequestID)))
	}
	if s.length == 0 {
		return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLoginMac(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserLoginField)(unsafe.Pointer(pReqUserLoginField)), C.int(nRequestID), C.int(0), (*C.char)(nil)))
	}
	out := (*C.char)(unsafe.Pointer(&s.systemInfo[0]))
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLoginMac(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserLoginField)(unsafe.Pointer(pReqUserLoginField)), C.int(nRequestID), C.int(s.length), out))
}

// / 登出请求
func (s *TraderApi) ReqUserLogout(pUserLogout *thost.CThostFtdcUserLogoutField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLogout(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcUserLogoutField)(unsafe.Pointer(pUserLogout)), C.int(nRequestID)))
}

// / 用户口令更新请求
func (s *TraderApi) ReqUserPasswordUpdate(pUserPasswordUpdate *thost.CThostFtdcUserPasswordUpdateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserPasswordUpdate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcUserPasswordUpdateField)(unsafe.Pointer(pUserPasswordUpdate)), C.int(nRequestID)))
}

// / 资金账户口令更新请求
func (s *TraderApi) ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate *thost.CThostFtdcTradingAccountPasswordUpdateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcTradingAccountPasswordUpdateField)(unsafe.Pointer(pTradingAccountPasswordUpdate)), C.int(nRequestID)))
}

// / 查询用户当前支持的认证模式
func (s *TraderApi) ReqUserAuthMethod(pReqUserAuthMethod *thost.CThostFtdcReqUserAuthMethodField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserAuthMethod(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserAuthMethodField)(unsafe.Pointer(pReqUserAuthMethod)), C.int(nRequestID)))
}

// / 用户发出获取图形验证码请求
func (s *TraderApi) ReqGenUserCaptcha(pReqGenUserCaptcha *thost.CThostFtdcReqGenUserCaptchaField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqGenUserCaptcha(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqGenUserCaptchaField)(unsafe.Pointer(pReqGenUserCaptcha)), C.int(nRequestID)))
}

// / 用户发出获取短信验证码请求
func (s *TraderApi) ReqGenUserText(pReqGenUserText *thost.CThostFtdcReqGenUserTextField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqGenUserText(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqGenUserTextField)(unsafe.Pointer(pReqGenUserText)), C.int(nRequestID)))
}

// / 用户发出带有图片验证码的登陆请求
func (s *TraderApi) ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha *thost.CThostFtdcReqUserLoginWithCaptchaField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLoginWithCaptcha(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserLoginWithCaptchaField)(unsafe.Pointer(pReqUserLoginWithCaptcha)), C.int(nRequestID)))
}

// / 用户发出带有短信验证码的登陆请求
func (s *TraderApi) ReqUserLoginWithText(pReqUserLoginWithText *thost.CThostFtdcReqUserLoginWithTextField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLoginWithText(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserLoginWithTextField)(unsafe.Pointer(pReqUserLoginWithText)), C.int(nRequestID)))
}

// / 用户发出带有动态口令的登陆请求
func (s *TraderApi) ReqUserLoginWithOTP(pReqUserLoginWithOTP *thost.CThostFtdcReqUserLoginWithOTPField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqUserLoginWithOTP(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqUserLoginWithOTPField)(unsafe.Pointer(pReqUserLoginWithOTP)), C.int(nRequestID)))
}

// / 报单录入请求
func (s *TraderApi) ReqOrderInsert(pInputOrder *thost.CThostFtdcInputOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqOrderInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputOrderField)(unsafe.Pointer(pInputOrder)), C.int(nRequestID)))
}

// / 预埋单录入请求
func (s *TraderApi) ReqParkedOrderInsert(pParkedOrder *thost.CThostFtdcParkedOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqParkedOrderInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcParkedOrderField)(unsafe.Pointer(pParkedOrder)), C.int(nRequestID)))
}

// / 预埋撤单录入请求
func (s *TraderApi) ReqParkedOrderAction(pParkedOrderAction *thost.CThostFtdcParkedOrderActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqParkedOrderAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcParkedOrderActionField)(unsafe.Pointer(pParkedOrderAction)), C.int(nRequestID)))
}

// / 报单操作请求
func (s *TraderApi) ReqOrderAction(pInputOrderAction *thost.CThostFtdcInputOrderActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqOrderAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputOrderActionField)(unsafe.Pointer(pInputOrderAction)), C.int(nRequestID)))
}

// / 查询最大报单数量请求
func (s *TraderApi) ReqQryMaxOrderVolume(pQryMaxOrderVolume *thost.CThostFtdcQryMaxOrderVolumeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryMaxOrderVolume(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryMaxOrderVolumeField)(unsafe.Pointer(pQryMaxOrderVolume)), C.int(nRequestID)))
}

// / 投资者结算结果确认
func (s *TraderApi) ReqSettlementInfoConfirm(pSettlementInfoConfirm *thost.CThostFtdcSettlementInfoConfirmField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqSettlementInfoConfirm(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcSettlementInfoConfirmField)(unsafe.Pointer(pSettlementInfoConfirm)), C.int(nRequestID)))
}

// / 请求删除预埋单
func (s *TraderApi) ReqRemoveParkedOrder(pRemoveParkedOrder *thost.CThostFtdcRemoveParkedOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqRemoveParkedOrder(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcRemoveParkedOrderField)(unsafe.Pointer(pRemoveParkedOrder)), C.int(nRequestID)))
}

// / 请求删除预埋撤单
func (s *TraderApi) ReqRemoveParkedOrderAction(pRemoveParkedOrderAction *thost.CThostFtdcRemoveParkedOrderActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqRemoveParkedOrderAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcRemoveParkedOrderActionField)(unsafe.Pointer(pRemoveParkedOrderAction)), C.int(nRequestID)))
}

// / 执行宣告录入请求
func (s *TraderApi) ReqExecOrderInsert(pInputExecOrder *thost.CThostFtdcInputExecOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqExecOrderInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputExecOrderField)(unsafe.Pointer(pInputExecOrder)), C.int(nRequestID)))
}

// / 执行宣告操作请求
func (s *TraderApi) ReqExecOrderAction(pInputExecOrderAction *thost.CThostFtdcInputExecOrderActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqExecOrderAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputExecOrderActionField)(unsafe.Pointer(pInputExecOrderAction)), C.int(nRequestID)))
}

// / 询价录入请求
func (s *TraderApi) ReqForQuoteInsert(pInputForQuote *thost.CThostFtdcInputForQuoteField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqForQuoteInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputForQuoteField)(unsafe.Pointer(pInputForQuote)), C.int(nRequestID)))
}

// / 报价录入请求
func (s *TraderApi) ReqQuoteInsert(pInputQuote *thost.CThostFtdcInputQuoteField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQuoteInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputQuoteField)(unsafe.Pointer(pInputQuote)), C.int(nRequestID)))
}

// / 报价操作请求
func (s *TraderApi) ReqQuoteAction(pInputQuoteAction *thost.CThostFtdcInputQuoteActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQuoteAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputQuoteActionField)(unsafe.Pointer(pInputQuoteAction)), C.int(nRequestID)))
}

// / 批量报单操作请求
func (s *TraderApi) ReqBatchOrderAction(pInputBatchOrderAction *thost.CThostFtdcInputBatchOrderActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqBatchOrderAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputBatchOrderActionField)(unsafe.Pointer(pInputBatchOrderAction)), C.int(nRequestID)))
}

// / 期权自对冲录入请求
func (s *TraderApi) ReqOptionSelfCloseInsert(pInputOptionSelfClose *thost.CThostFtdcInputOptionSelfCloseField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqOptionSelfCloseInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputOptionSelfCloseField)(unsafe.Pointer(pInputOptionSelfClose)), C.int(nRequestID)))
}

// / 期权自对冲操作请求
func (s *TraderApi) ReqOptionSelfCloseAction(pInputOptionSelfCloseAction *thost.CThostFtdcInputOptionSelfCloseActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqOptionSelfCloseAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputOptionSelfCloseActionField)(unsafe.Pointer(pInputOptionSelfCloseAction)), C.int(nRequestID)))
}

// / 申请组合录入请求
func (s *TraderApi) ReqCombActionInsert(pInputCombAction *thost.CThostFtdcInputCombActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqCombActionInsert(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcInputCombActionField)(unsafe.Pointer(pInputCombAction)), C.int(nRequestID)))
}

// / 请求查询报单
func (s *TraderApi) ReqQryOrder(pQryOrder *thost.CThostFtdcQryOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryOrder(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryOrderField)(unsafe.Pointer(pQryOrder)), C.int(nRequestID)))
}

// / 请求查询成交
func (s *TraderApi) ReqQryTrade(pQryTrade *thost.CThostFtdcQryTradeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTrade(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTradeField)(unsafe.Pointer(pQryTrade)), C.int(nRequestID)))
}

// / 请求查询投资者持仓
func (s *TraderApi) ReqQryInvestorPosition(pQryInvestorPosition *thost.CThostFtdcQryInvestorPositionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorPosition(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorPositionField)(unsafe.Pointer(pQryInvestorPosition)), C.int(nRequestID)))
}

// / 请求查询资金账户
func (s *TraderApi) ReqQryTradingAccount(pQryTradingAccount *thost.CThostFtdcQryTradingAccountField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTradingAccount(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTradingAccountField)(unsafe.Pointer(pQryTradingAccount)), C.int(nRequestID)))
}

// / 请求查询投资者
func (s *TraderApi) ReqQryInvestor(pQryInvestor *thost.CThostFtdcQryInvestorField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestor(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorField)(unsafe.Pointer(pQryInvestor)), C.int(nRequestID)))
}

// / 请求查询交易编码
func (s *TraderApi) ReqQryTradingCode(pQryTradingCode *thost.CThostFtdcQryTradingCodeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTradingCode(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTradingCodeField)(unsafe.Pointer(pQryTradingCode)), C.int(nRequestID)))
}

// / 请求查询合约保证金率
func (s *TraderApi) ReqQryInstrumentMarginRate(pQryInstrumentMarginRate *thost.CThostFtdcQryInstrumentMarginRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInstrumentMarginRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInstrumentMarginRateField)(unsafe.Pointer(pQryInstrumentMarginRate)), C.int(nRequestID)))
}

// / 请求查询合约手续费率
func (s *TraderApi) ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate *thost.CThostFtdcQryInstrumentCommissionRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInstrumentCommissionRateField)(unsafe.Pointer(pQryInstrumentCommissionRate)), C.int(nRequestID)))
}

// / 请求查询交易所
func (s *TraderApi) ReqQryExchange(pQryExchange *thost.CThostFtdcQryExchangeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryExchange(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryExchangeField)(unsafe.Pointer(pQryExchange)), C.int(nRequestID)))
}

// / 请求查询产品
func (s *TraderApi) ReqQryProduct(pQryProduct *thost.CThostFtdcQryProductField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryProduct(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryProductField)(unsafe.Pointer(pQryProduct)), C.int(nRequestID)))
}

// / 请求查询合约
func (s *TraderApi) ReqQryInstrument(pQryInstrument *thost.CThostFtdcQryInstrumentField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInstrument(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInstrumentField)(unsafe.Pointer(pQryInstrument)), C.int(nRequestID)))
}

// / 请求查询行情
func (s *TraderApi) ReqQryDepthMarketData(pQryDepthMarketData *thost.CThostFtdcQryDepthMarketDataField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryDepthMarketData(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryDepthMarketDataField)(unsafe.Pointer(pQryDepthMarketData)), C.int(nRequestID)))
}

// / 请求查询交易员报盘机
func (s *TraderApi) ReqQryTraderOffer(pQryTraderOffer *thost.CThostFtdcQryTraderOfferField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTraderOffer(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTraderOfferField)(unsafe.Pointer(pQryTraderOffer)), C.int(nRequestID)))
}

// / 请求查询投资者结算结果
func (s *TraderApi) ReqQrySettlementInfo(pQrySettlementInfo *thost.CThostFtdcQrySettlementInfoField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySettlementInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySettlementInfoField)(unsafe.Pointer(pQrySettlementInfo)), C.int(nRequestID)))
}

// / 请求查询转帐银行
func (s *TraderApi) ReqQryTransferBank(pQryTransferBank *thost.CThostFtdcQryTransferBankField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTransferBank(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTransferBankField)(unsafe.Pointer(pQryTransferBank)), C.int(nRequestID)))
}

// / 请求查询投资者持仓明细
func (s *TraderApi) ReqQryInvestorPositionDetail(pQryInvestorPositionDetail *thost.CThostFtdcQryInvestorPositionDetailField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorPositionDetail(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorPositionDetailField)(unsafe.Pointer(pQryInvestorPositionDetail)), C.int(nRequestID)))
}

// / 请求查询客户通知
func (s *TraderApi) ReqQryNotice(pQryNotice *thost.CThostFtdcQryNoticeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryNotice(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryNoticeField)(unsafe.Pointer(pQryNotice)), C.int(nRequestID)))
}

// / 请求查询结算信息确认
func (s *TraderApi) ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm *thost.CThostFtdcQrySettlementInfoConfirmField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySettlementInfoConfirmField)(unsafe.Pointer(pQrySettlementInfoConfirm)), C.int(nRequestID)))
}

// / 请求查询投资者持仓明细
func (s *TraderApi) ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail *thost.CThostFtdcQryInvestorPositionCombineDetailField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorPositionCombineDetailField)(unsafe.Pointer(pQryInvestorPositionCombineDetail)), C.int(nRequestID)))
}

// / 请求查询保证金监管系统经纪公司资金账户密钥
func (s *TraderApi) ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey *thost.CThostFtdcQryCFMMCTradingAccountKeyField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryCFMMCTradingAccountKeyField)(unsafe.Pointer(pQryCFMMCTradingAccountKey)), C.int(nRequestID)))
}

// / 请求查询仓单折抵信息
func (s *TraderApi) ReqQryEWarrantOffset(pQryEWarrantOffset *thost.CThostFtdcQryEWarrantOffsetField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryEWarrantOffset(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryEWarrantOffsetField)(unsafe.Pointer(pQryEWarrantOffset)), C.int(nRequestID)))
}

// / 请求查询投资者品种/跨品种保证金
func (s *TraderApi) ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin *thost.CThostFtdcQryInvestorProductGroupMarginField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorProductGroupMarginField)(unsafe.Pointer(pQryInvestorProductGroupMargin)), C.int(nRequestID)))
}

// / 请求查询交易所保证金率
func (s *TraderApi) ReqQryExchangeMarginRate(pQryExchangeMarginRate *thost.CThostFtdcQryExchangeMarginRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryExchangeMarginRateField)(unsafe.Pointer(pQryExchangeMarginRate)), C.int(nRequestID)))
}

// / 请求查询交易所调整保证金率
func (s *TraderApi) ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust *thost.CThostFtdcQryExchangeMarginRateAdjustField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryExchangeMarginRateAdjustField)(unsafe.Pointer(pQryExchangeMarginRateAdjust)), C.int(nRequestID)))
}

// / 请求查询汇率
func (s *TraderApi) ReqQryExchangeRate(pQryExchangeRate *thost.CThostFtdcQryExchangeRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryExchangeRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryExchangeRateField)(unsafe.Pointer(pQryExchangeRate)), C.int(nRequestID)))
}

// / 请求查询二级代理操作员银期权限
func (s *TraderApi) ReqQrySecAgentACIDMap(pQrySecAgentACIDMap *thost.CThostFtdcQrySecAgentACIDMapField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySecAgentACIDMap(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySecAgentACIDMapField)(unsafe.Pointer(pQrySecAgentACIDMap)), C.int(nRequestID)))
}

// / 请求查询产品报价汇率
func (s *TraderApi) ReqQryProductExchRate(pQryProductExchRate *thost.CThostFtdcQryProductExchRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryProductExchRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryProductExchRateField)(unsafe.Pointer(pQryProductExchRate)), C.int(nRequestID)))
}

// / 请求查询产品组
func (s *TraderApi) ReqQryProductGroup(pQryProductGroup *thost.CThostFtdcQryProductGroupField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryProductGroup(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryProductGroupField)(unsafe.Pointer(pQryProductGroup)), C.int(nRequestID)))
}

// / 请求查询做市商合约手续费率
func (s *TraderApi) ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate *thost.CThostFtdcQryMMInstrumentCommissionRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryMMInstrumentCommissionRateField)(unsafe.Pointer(pQryMMInstrumentCommissionRate)), C.int(nRequestID)))
}

// / 请求查询做市商期权合约手续费
func (s *TraderApi) ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate *thost.CThostFtdcQryMMOptionInstrCommRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryMMOptionInstrCommRateField)(unsafe.Pointer(pQryMMOptionInstrCommRate)), C.int(nRequestID)))
}

// / 请求查询报单手续费
func (s *TraderApi) ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate *thost.CThostFtdcQryInstrumentOrderCommRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInstrumentOrderCommRateField)(unsafe.Pointer(pQryInstrumentOrderCommRate)), C.int(nRequestID)))
}

// / 请求查询资金账户
func (s *TraderApi) ReqQrySecAgentTradingAccount(pQryTradingAccount *thost.CThostFtdcQryTradingAccountField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTradingAccountField)(unsafe.Pointer(pQryTradingAccount)), C.int(nRequestID)))
}

// / 请求查询二级代理商资金校验模式
func (s *TraderApi) ReqQrySecAgentCheckMode(pQrySecAgentCheckMode *thost.CThostFtdcQrySecAgentCheckModeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySecAgentCheckMode(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySecAgentCheckModeField)(unsafe.Pointer(pQrySecAgentCheckMode)), C.int(nRequestID)))
}

// / 请求查询二级代理商信息
func (s *TraderApi) ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo *thost.CThostFtdcQrySecAgentTradeInfoField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySecAgentTradeInfoField)(unsafe.Pointer(pQrySecAgentTradeInfo)), C.int(nRequestID)))
}

// / 请求查询期权交易成本
func (s *TraderApi) ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost *thost.CThostFtdcQryOptionInstrTradeCostField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryOptionInstrTradeCostField)(unsafe.Pointer(pQryOptionInstrTradeCost)), C.int(nRequestID)))
}

// / 请求查询期权合约手续费
func (s *TraderApi) ReqQryOptionInstrCommRate(pQryOptionInstrCommRate *thost.CThostFtdcQryOptionInstrCommRateField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryOptionInstrCommRate(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryOptionInstrCommRateField)(unsafe.Pointer(pQryOptionInstrCommRate)), C.int(nRequestID)))
}

// / 请求查询执行宣告
func (s *TraderApi) ReqQryExecOrder(pQryExecOrder *thost.CThostFtdcQryExecOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryExecOrder(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryExecOrderField)(unsafe.Pointer(pQryExecOrder)), C.int(nRequestID)))
}

// / 请求查询询价
func (s *TraderApi) ReqQryForQuote(pQryForQuote *thost.CThostFtdcQryForQuoteField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryForQuote(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryForQuoteField)(unsafe.Pointer(pQryForQuote)), C.int(nRequestID)))
}

// / 请求查询报价
func (s *TraderApi) ReqQryQuote(pQryQuote *thost.CThostFtdcQryQuoteField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryQuote(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryQuoteField)(unsafe.Pointer(pQryQuote)), C.int(nRequestID)))
}

// / 请求查询期权自对冲
func (s *TraderApi) ReqQryOptionSelfClose(pQryOptionSelfClose *thost.CThostFtdcQryOptionSelfCloseField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryOptionSelfClose(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryOptionSelfCloseField)(unsafe.Pointer(pQryOptionSelfClose)), C.int(nRequestID)))
}

// / 请求查询投资单元
func (s *TraderApi) ReqQryInvestUnit(pQryInvestUnit *thost.CThostFtdcQryInvestUnitField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestUnit(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestUnitField)(unsafe.Pointer(pQryInvestUnit)), C.int(nRequestID)))
}

// / 请求查询组合合约安全系数
func (s *TraderApi) ReqQryCombInstrumentGuard(pQryCombInstrumentGuard *thost.CThostFtdcQryCombInstrumentGuardField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryCombInstrumentGuard(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryCombInstrumentGuardField)(unsafe.Pointer(pQryCombInstrumentGuard)), C.int(nRequestID)))
}

// / 请求查询申请组合
func (s *TraderApi) ReqQryCombAction(pQryCombAction *thost.CThostFtdcQryCombActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryCombAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryCombActionField)(unsafe.Pointer(pQryCombAction)), C.int(nRequestID)))
}

// / 请求查询转帐流水
func (s *TraderApi) ReqQryTransferSerial(pQryTransferSerial *thost.CThostFtdcQryTransferSerialField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTransferSerial(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTransferSerialField)(unsafe.Pointer(pQryTransferSerial)), C.int(nRequestID)))
}

// / 请求查询银期签约关系
func (s *TraderApi) ReqQryAccountregister(pQryAccountregister *thost.CThostFtdcQryAccountregisterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryAccountregister(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryAccountregisterField)(unsafe.Pointer(pQryAccountregister)), C.int(nRequestID)))
}

// / 请求查询签约银行
func (s *TraderApi) ReqQryContractBank(pQryContractBank *thost.CThostFtdcQryContractBankField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryContractBank(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryContractBankField)(unsafe.Pointer(pQryContractBank)), C.int(nRequestID)))
}

// / 请求查询预埋单
func (s *TraderApi) ReqQryParkedOrder(pQryParkedOrder *thost.CThostFtdcQryParkedOrderField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryParkedOrder(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryParkedOrderField)(unsafe.Pointer(pQryParkedOrder)), C.int(nRequestID)))
}

// / 请求查询预埋撤单
func (s *TraderApi) ReqQryParkedOrderAction(pQryParkedOrderAction *thost.CThostFtdcQryParkedOrderActionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryParkedOrderAction(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryParkedOrderActionField)(unsafe.Pointer(pQryParkedOrderAction)), C.int(nRequestID)))
}

// / 请求查询交易通知
func (s *TraderApi) ReqQryTradingNotice(pQryTradingNotice *thost.CThostFtdcQryTradingNoticeField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryTradingNotice(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryTradingNoticeField)(unsafe.Pointer(pQryTradingNotice)), C.int(nRequestID)))
}

// / 请求查询经纪公司交易参数
func (s *TraderApi) ReqQryBrokerTradingParams(pQryBrokerTradingParams *thost.CThostFtdcQryBrokerTradingParamsField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryBrokerTradingParams(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryBrokerTradingParamsField)(unsafe.Pointer(pQryBrokerTradingParams)), C.int(nRequestID)))
}

// / 请求查询经纪公司交易算法
func (s *TraderApi) ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos *thost.CThostFtdcQryBrokerTradingAlgosField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryBrokerTradingAlgosField)(unsafe.Pointer(pQryBrokerTradingAlgos)), C.int(nRequestID)))
}

// / 请求查询监控中心用户令牌
func (s *TraderApi) ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken *thost.CThostFtdcQueryCFMMCTradingAccountTokenField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQueryCFMMCTradingAccountTokenField)(unsafe.Pointer(pQueryCFMMCTradingAccountToken)), C.int(nRequestID)))
}

// / 期货发起银行资金转期货请求
func (s *TraderApi) ReqFromBankToFutureByFuture(pReqTransfer *thost.CThostFtdcReqTransferField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqFromBankToFutureByFuture(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqTransferField)(unsafe.Pointer(pReqTransfer)), C.int(nRequestID)))
}

// / 期货发起期货资金转银行请求
func (s *TraderApi) ReqFromFutureToBankByFuture(pReqTransfer *thost.CThostFtdcReqTransferField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqFromFutureToBankByFuture(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqTransferField)(unsafe.Pointer(pReqTransfer)), C.int(nRequestID)))
}

// / 期货发起查询银行余额请求
func (s *TraderApi) ReqQueryBankAccountMoneyByFuture(pReqQueryAccount *thost.CThostFtdcReqQueryAccountField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcReqQueryAccountField)(unsafe.Pointer(pReqQueryAccount)), C.int(nRequestID)))
}

// / 请求查询分类合约
func (s *TraderApi) ReqQryClassifiedInstrument(pQryClassifiedInstrument *thost.CThostFtdcQryClassifiedInstrumentField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryClassifiedInstrument(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryClassifiedInstrumentField)(unsafe.Pointer(pQryClassifiedInstrument)), C.int(nRequestID)))
}

// / 请求组合优惠比例
func (s *TraderApi) ReqQryCombPromotionParam(pQryCombPromotionParam *thost.CThostFtdcQryCombPromotionParamField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryCombPromotionParam(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryCombPromotionParamField)(unsafe.Pointer(pQryCombPromotionParam)), C.int(nRequestID)))
}

// / 投资者风险结算持仓查询
func (s *TraderApi) ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition *thost.CThostFtdcQryRiskSettleInvstPositionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRiskSettleInvstPositionField)(unsafe.Pointer(pQryRiskSettleInvstPosition)), C.int(nRequestID)))
}

// / 风险结算产品查询
func (s *TraderApi) ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus *thost.CThostFtdcQryRiskSettleProductStatusField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRiskSettleProductStatusField)(unsafe.Pointer(pQryRiskSettleProductStatus)), C.int(nRequestID)))
}

// / SPBM期货合约参数查询
func (s *TraderApi) ReqQrySPBMFutureParameter(pQrySPBMFutureParameter *thost.CThostFtdcQrySPBMFutureParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMFutureParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMFutureParameterField)(unsafe.Pointer(pQrySPBMFutureParameter)), C.int(nRequestID)))
}

// / SPBM期权合约参数查询
func (s *TraderApi) ReqQrySPBMOptionParameter(pQrySPBMOptionParameter *thost.CThostFtdcQrySPBMOptionParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMOptionParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMOptionParameterField)(unsafe.Pointer(pQrySPBMOptionParameter)), C.int(nRequestID)))
}

// / SPBM品种内对锁仓折扣参数查询
func (s *TraderApi) ReqQrySPBMIntraParameter(pQrySPBMIntraParameter *thost.CThostFtdcQrySPBMIntraParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMIntraParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMIntraParameterField)(unsafe.Pointer(pQrySPBMIntraParameter)), C.int(nRequestID)))
}

// / SPBM跨品种抵扣参数查询
func (s *TraderApi) ReqQrySPBMInterParameter(pQrySPBMInterParameter *thost.CThostFtdcQrySPBMInterParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMInterParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMInterParameterField)(unsafe.Pointer(pQrySPBMInterParameter)), C.int(nRequestID)))
}

// / SPBM组合保证金套餐查询
func (s *TraderApi) ReqQrySPBMPortfDefinition(pQrySPBMPortfDefinition *thost.CThostFtdcQrySPBMPortfDefinitionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMPortfDefinition(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMPortfDefinitionField)(unsafe.Pointer(pQrySPBMPortfDefinition)), C.int(nRequestID)))
}

// / 投资者SPBM套餐选择查询
func (s *TraderApi) ReqQrySPBMInvestorPortfDef(pQrySPBMInvestorPortfDef *thost.CThostFtdcQrySPBMInvestorPortfDefField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMInvestorPortfDef(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMInvestorPortfDefField)(unsafe.Pointer(pQrySPBMInvestorPortfDef)), C.int(nRequestID)))
}

// / 投资者新型组合保证金系数查询
func (s *TraderApi) ReqQryInvestorPortfMarginRatio(pQryInvestorPortfMarginRatio *thost.CThostFtdcQryInvestorPortfMarginRatioField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorPortfMarginRatio(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorPortfMarginRatioField)(unsafe.Pointer(pQryInvestorPortfMarginRatio)), C.int(nRequestID)))
}

// / 投资者产品SPBM明细查询
func (s *TraderApi) ReqQryInvestorProdSPBMDetail(pQryInvestorProdSPBMDetail *thost.CThostFtdcQryInvestorProdSPBMDetailField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorProdSPBMDetail(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorProdSPBMDetailField)(unsafe.Pointer(pQryInvestorProdSPBMDetail)), C.int(nRequestID)))
}

// / 投资者商品组SPMM记录查询
func (s *TraderApi) ReqQryInvestorCommoditySPMMMargin(pQryInvestorCommoditySPMMMargin *thost.CThostFtdcQryInvestorCommoditySPMMMarginField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorCommoditySPMMMargin(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorCommoditySPMMMarginField)(unsafe.Pointer(pQryInvestorCommoditySPMMMargin)), C.int(nRequestID)))
}

// / 投资者商品群SPMM记录查询
func (s *TraderApi) ReqQryInvestorCommodityGroupSPMMMargin(pQryInvestorCommodityGroupSPMMMargin *thost.CThostFtdcQryInvestorCommodityGroupSPMMMarginField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorCommodityGroupSPMMMargin(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorCommodityGroupSPMMMarginField)(unsafe.Pointer(pQryInvestorCommodityGroupSPMMMargin)), C.int(nRequestID)))
}

// / SPMM合约参数查询
func (s *TraderApi) ReqQrySPMMInstParam(pQrySPMMInstParam *thost.CThostFtdcQrySPMMInstParamField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPMMInstParam(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPMMInstParamField)(unsafe.Pointer(pQrySPMMInstParam)), C.int(nRequestID)))
}

// / SPMM产品参数查询
func (s *TraderApi) ReqQrySPMMProductParam(pQrySPMMProductParam *thost.CThostFtdcQrySPMMProductParamField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPMMProductParam(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPMMProductParamField)(unsafe.Pointer(pQrySPMMProductParam)), C.int(nRequestID)))
}

// / SPBM附加跨品种抵扣参数查询
func (s *TraderApi) ReqQrySPBMAddOnInterParameter(pQrySPBMAddOnInterParameter *thost.CThostFtdcQrySPBMAddOnInterParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQrySPBMAddOnInterParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQrySPBMAddOnInterParameterField)(unsafe.Pointer(pQrySPBMAddOnInterParameter)), C.int(nRequestID)))
}

// / RCAMS产品组合信息查询
func (s *TraderApi) ReqQryRCAMSCombProductInfo(pQryRCAMSCombProductInfo *thost.CThostFtdcQryRCAMSCombProductInfoField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRCAMSCombProductInfo(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRCAMSCombProductInfoField)(unsafe.Pointer(pQryRCAMSCombProductInfo)), C.int(nRequestID)))
}

// / RCAMS同合约风险对冲参数查询
func (s *TraderApi) ReqQryRCAMSInstrParameter(pQryRCAMSInstrParameter *thost.CThostFtdcQryRCAMSInstrParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRCAMSInstrParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRCAMSInstrParameterField)(unsafe.Pointer(pQryRCAMSInstrParameter)), C.int(nRequestID)))
}

// / RCAMS品种内风险对冲参数查询
func (s *TraderApi) ReqQryRCAMSIntraParameter(pQryRCAMSIntraParameter *thost.CThostFtdcQryRCAMSIntraParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRCAMSIntraParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRCAMSIntraParameterField)(unsafe.Pointer(pQryRCAMSIntraParameter)), C.int(nRequestID)))
}

// / RCAMS跨品种风险折抵参数查询
func (s *TraderApi) ReqQryRCAMSInterParameter(pQryRCAMSInterParameter *thost.CThostFtdcQryRCAMSInterParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRCAMSInterParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRCAMSInterParameterField)(unsafe.Pointer(pQryRCAMSInterParameter)), C.int(nRequestID)))
}

// / RCAMS空头期权风险调整参数查询
func (s *TraderApi) ReqQryRCAMSShortOptAdjustParam(pQryRCAMSShortOptAdjustParam *thost.CThostFtdcQryRCAMSShortOptAdjustParamField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRCAMSShortOptAdjustParam(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRCAMSShortOptAdjustParamField)(unsafe.Pointer(pQryRCAMSShortOptAdjustParam)), C.int(nRequestID)))
}

// / RCAMS策略组合持仓查询
func (s *TraderApi) ReqQryRCAMSInvestorCombPosition(pQryRCAMSInvestorCombPosition *thost.CThostFtdcQryRCAMSInvestorCombPositionField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRCAMSInvestorCombPosition(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRCAMSInvestorCombPositionField)(unsafe.Pointer(pQryRCAMSInvestorCombPosition)), C.int(nRequestID)))
}

// / 投资者品种RCAMS保证金查询
func (s *TraderApi) ReqQryInvestorProdRCAMSMargin(pQryInvestorProdRCAMSMargin *thost.CThostFtdcQryInvestorProdRCAMSMarginField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorProdRCAMSMargin(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorProdRCAMSMarginField)(unsafe.Pointer(pQryInvestorProdRCAMSMargin)), C.int(nRequestID)))
}

// / RULE合约保证金参数查询
func (s *TraderApi) ReqQryRULEInstrParameter(pQryRULEInstrParameter *thost.CThostFtdcQryRULEInstrParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRULEInstrParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRULEInstrParameterField)(unsafe.Pointer(pQryRULEInstrParameter)), C.int(nRequestID)))
}

// / RULE品种内对锁仓折扣参数查询
func (s *TraderApi) ReqQryRULEIntraParameter(pQryRULEIntraParameter *thost.CThostFtdcQryRULEIntraParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRULEIntraParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRULEIntraParameterField)(unsafe.Pointer(pQryRULEIntraParameter)), C.int(nRequestID)))
}

// / RULE跨品种抵扣参数查询
func (s *TraderApi) ReqQryRULEInterParameter(pQryRULEInterParameter *thost.CThostFtdcQryRULEInterParameterField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryRULEInterParameter(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryRULEInterParameterField)(unsafe.Pointer(pQryRULEInterParameter)), C.int(nRequestID)))
}

// / 投资者产品RULE保证金查询
func (s *TraderApi) ReqQryInvestorProdRULEMargin(pQryInvestorProdRULEMargin *thost.CThostFtdcQryInvestorProdRULEMarginField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorProdRULEMargin(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorProdRULEMarginField)(unsafe.Pointer(pQryInvestorProdRULEMargin)), C.int(nRequestID)))
}

// / 投资者投资者新组保设置查询
func (s *TraderApi) ReqQryInvestorPortfSetting(pQryInvestorPortfSetting *thost.CThostFtdcQryInvestorPortfSettingField, nRequestID int) int {
	return (int)(C._wrap_CThostFtdcTraderApi_ReqQryInvestorPortfSetting(C.uintptr_t(s.apiPtr), (*C.struct_CThostFtdcQryInvestorPortfSettingField)(unsafe.Pointer(pQryInvestorPortfSetting)), C.int(nRequestID)))
}

//------------------------------------------------------------------------------------

//export wrapTraderOnFrontConnected
func wrapTraderOnFrontConnected(v uintptr) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnFrontConnected()
}

//export wrapTraderOnFrontDisconnected
func wrapTraderOnFrontDisconnected(v uintptr, nReason C.int) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnFrontDisconnected(int(nReason))
}

//export wrapTraderOnHeartBeatWarning
func wrapTraderOnHeartBeatWarning(v uintptr, nTimeLapse C.int) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnHeartBeatWarning(int(nTimeLapse))
}

//export wrapTraderOnRspAuthenticate
func wrapTraderOnRspAuthenticate(v uintptr, pRspAuthenticateField *C.struct_CThostFtdcRspAuthenticateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspAuthenticate((*thost.CThostFtdcRspAuthenticateField)(unsafe.Pointer(pRspAuthenticateField)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspUserLogin
func wrapTraderOnRspUserLogin(v uintptr, pRspUserLogin *C.struct_CThostFtdcRspUserLoginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspUserLogin((*thost.CThostFtdcRspUserLoginField)(unsafe.Pointer(pRspUserLogin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspUserLogout
func wrapTraderOnRspUserLogout(v uintptr, pUserLogout *C.struct_CThostFtdcUserLogoutField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspUserLogout((*thost.CThostFtdcUserLogoutField)(unsafe.Pointer(pUserLogout)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspUserPasswordUpdate
func wrapTraderOnRspUserPasswordUpdate(v uintptr, pUserPasswordUpdate *C.struct_CThostFtdcUserPasswordUpdateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspUserPasswordUpdate((*thost.CThostFtdcUserPasswordUpdateField)(unsafe.Pointer(pUserPasswordUpdate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspTradingAccountPasswordUpdate
func wrapTraderOnRspTradingAccountPasswordUpdate(v uintptr, pTradingAccountPasswordUpdate *C.struct_CThostFtdcTradingAccountPasswordUpdateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspTradingAccountPasswordUpdate((*thost.CThostFtdcTradingAccountPasswordUpdateField)(unsafe.Pointer(pTradingAccountPasswordUpdate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspUserAuthMethod
func wrapTraderOnRspUserAuthMethod(v uintptr, pRspUserAuthMethod *C.struct_CThostFtdcRspUserAuthMethodField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspUserAuthMethod((*thost.CThostFtdcRspUserAuthMethodField)(unsafe.Pointer(pRspUserAuthMethod)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspGenUserCaptcha
func wrapTraderOnRspGenUserCaptcha(v uintptr, pRspGenUserCaptcha *C.struct_CThostFtdcRspGenUserCaptchaField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspGenUserCaptcha((*thost.CThostFtdcRspGenUserCaptchaField)(unsafe.Pointer(pRspGenUserCaptcha)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspGenUserText
func wrapTraderOnRspGenUserText(v uintptr, pRspGenUserText *C.struct_CThostFtdcRspGenUserTextField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspGenUserText((*thost.CThostFtdcRspGenUserTextField)(unsafe.Pointer(pRspGenUserText)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspOrderInsert
func wrapTraderOnRspOrderInsert(v uintptr, pInputOrder *C.struct_CThostFtdcInputOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspOrderInsert((*thost.CThostFtdcInputOrderField)(unsafe.Pointer(pInputOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspParkedOrderInsert
func wrapTraderOnRspParkedOrderInsert(v uintptr, pParkedOrder *C.struct_CThostFtdcParkedOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspParkedOrderInsert((*thost.CThostFtdcParkedOrderField)(unsafe.Pointer(pParkedOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspParkedOrderAction
func wrapTraderOnRspParkedOrderAction(v uintptr, pParkedOrderAction *C.struct_CThostFtdcParkedOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspParkedOrderAction((*thost.CThostFtdcParkedOrderActionField)(unsafe.Pointer(pParkedOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspOrderAction
func wrapTraderOnRspOrderAction(v uintptr, pInputOrderAction *C.struct_CThostFtdcInputOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspOrderAction((*thost.CThostFtdcInputOrderActionField)(unsafe.Pointer(pInputOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryMaxOrderVolume
func wrapTraderOnRspQryMaxOrderVolume(v uintptr, pQryMaxOrderVolume *C.struct_CThostFtdcQryMaxOrderVolumeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryMaxOrderVolume((*thost.CThostFtdcQryMaxOrderVolumeField)(unsafe.Pointer(pQryMaxOrderVolume)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspSettlementInfoConfirm
func wrapTraderOnRspSettlementInfoConfirm(v uintptr, pSettlementInfoConfirm *C.struct_CThostFtdcSettlementInfoConfirmField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspSettlementInfoConfirm((*thost.CThostFtdcSettlementInfoConfirmField)(unsafe.Pointer(pSettlementInfoConfirm)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspRemoveParkedOrder
func wrapTraderOnRspRemoveParkedOrder(v uintptr, pRemoveParkedOrder *C.struct_CThostFtdcRemoveParkedOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspRemoveParkedOrder((*thost.CThostFtdcRemoveParkedOrderField)(unsafe.Pointer(pRemoveParkedOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspRemoveParkedOrderAction
func wrapTraderOnRspRemoveParkedOrderAction(v uintptr, pRemoveParkedOrderAction *C.struct_CThostFtdcRemoveParkedOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspRemoveParkedOrderAction((*thost.CThostFtdcRemoveParkedOrderActionField)(unsafe.Pointer(pRemoveParkedOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspExecOrderInsert
func wrapTraderOnRspExecOrderInsert(v uintptr, pInputExecOrder *C.struct_CThostFtdcInputExecOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspExecOrderInsert((*thost.CThostFtdcInputExecOrderField)(unsafe.Pointer(pInputExecOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspExecOrderAction
func wrapTraderOnRspExecOrderAction(v uintptr, pInputExecOrderAction *C.struct_CThostFtdcInputExecOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspExecOrderAction((*thost.CThostFtdcInputExecOrderActionField)(unsafe.Pointer(pInputExecOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspForQuoteInsert
func wrapTraderOnRspForQuoteInsert(v uintptr, pInputForQuote *C.struct_CThostFtdcInputForQuoteField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspForQuoteInsert((*thost.CThostFtdcInputForQuoteField)(unsafe.Pointer(pInputForQuote)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQuoteInsert
func wrapTraderOnRspQuoteInsert(v uintptr, pInputQuote *C.struct_CThostFtdcInputQuoteField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQuoteInsert((*thost.CThostFtdcInputQuoteField)(unsafe.Pointer(pInputQuote)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQuoteAction
func wrapTraderOnRspQuoteAction(v uintptr, pInputQuoteAction *C.struct_CThostFtdcInputQuoteActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQuoteAction((*thost.CThostFtdcInputQuoteActionField)(unsafe.Pointer(pInputQuoteAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspBatchOrderAction
func wrapTraderOnRspBatchOrderAction(v uintptr, pInputBatchOrderAction *C.struct_CThostFtdcInputBatchOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspBatchOrderAction((*thost.CThostFtdcInputBatchOrderActionField)(unsafe.Pointer(pInputBatchOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspOptionSelfCloseInsert
func wrapTraderOnRspOptionSelfCloseInsert(v uintptr, pInputOptionSelfClose *C.struct_CThostFtdcInputOptionSelfCloseField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspOptionSelfCloseInsert((*thost.CThostFtdcInputOptionSelfCloseField)(unsafe.Pointer(pInputOptionSelfClose)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspOptionSelfCloseAction
func wrapTraderOnRspOptionSelfCloseAction(v uintptr, pInputOptionSelfCloseAction *C.struct_CThostFtdcInputOptionSelfCloseActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspOptionSelfCloseAction((*thost.CThostFtdcInputOptionSelfCloseActionField)(unsafe.Pointer(pInputOptionSelfCloseAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspCombActionInsert
func wrapTraderOnRspCombActionInsert(v uintptr, pInputCombAction *C.struct_CThostFtdcInputCombActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspCombActionInsert((*thost.CThostFtdcInputCombActionField)(unsafe.Pointer(pInputCombAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryOrder
func wrapTraderOnRspQryOrder(v uintptr, pOrder *C.struct_CThostFtdcOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryOrder((*thost.CThostFtdcOrderField)(unsafe.Pointer(pOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTrade
func wrapTraderOnRspQryTrade(v uintptr, pTrade *C.struct_CThostFtdcTradeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTrade((*thost.CThostFtdcTradeField)(unsafe.Pointer(pTrade)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorPosition
func wrapTraderOnRspQryInvestorPosition(v uintptr, pInvestorPosition *C.struct_CThostFtdcInvestorPositionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorPosition((*thost.CThostFtdcInvestorPositionField)(unsafe.Pointer(pInvestorPosition)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTradingAccount
func wrapTraderOnRspQryTradingAccount(v uintptr, pTradingAccount *C.struct_CThostFtdcTradingAccountField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTradingAccount((*thost.CThostFtdcTradingAccountField)(unsafe.Pointer(pTradingAccount)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestor
func wrapTraderOnRspQryInvestor(v uintptr, pInvestor *C.struct_CThostFtdcInvestorField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestor((*thost.CThostFtdcInvestorField)(unsafe.Pointer(pInvestor)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTradingCode
func wrapTraderOnRspQryTradingCode(v uintptr, pTradingCode *C.struct_CThostFtdcTradingCodeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTradingCode((*thost.CThostFtdcTradingCodeField)(unsafe.Pointer(pTradingCode)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInstrumentMarginRate
func wrapTraderOnRspQryInstrumentMarginRate(v uintptr, pInstrumentMarginRate *C.struct_CThostFtdcInstrumentMarginRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInstrumentMarginRate((*thost.CThostFtdcInstrumentMarginRateField)(unsafe.Pointer(pInstrumentMarginRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInstrumentCommissionRate
func wrapTraderOnRspQryInstrumentCommissionRate(v uintptr, pInstrumentCommissionRate *C.struct_CThostFtdcInstrumentCommissionRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInstrumentCommissionRate((*thost.CThostFtdcInstrumentCommissionRateField)(unsafe.Pointer(pInstrumentCommissionRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryExchange
func wrapTraderOnRspQryExchange(v uintptr, pExchange *C.struct_CThostFtdcExchangeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryExchange((*thost.CThostFtdcExchangeField)(unsafe.Pointer(pExchange)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryProduct
func wrapTraderOnRspQryProduct(v uintptr, pProduct *C.struct_CThostFtdcProductField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryProduct((*thost.CThostFtdcProductField)(unsafe.Pointer(pProduct)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInstrument
func wrapTraderOnRspQryInstrument(v uintptr, pInstrument *C.struct_CThostFtdcInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInstrument((*thost.CThostFtdcInstrumentField)(unsafe.Pointer(pInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryDepthMarketData
func wrapTraderOnRspQryDepthMarketData(v uintptr, pDepthMarketData *C.struct_CThostFtdcDepthMarketDataField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryDepthMarketData((*thost.CThostFtdcDepthMarketDataField)(unsafe.Pointer(pDepthMarketData)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTraderOffer
func wrapTraderOnRspQryTraderOffer(v uintptr, pTraderOffer *C.struct_CThostFtdcTraderOfferField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTraderOffer((*thost.CThostFtdcTraderOfferField)(unsafe.Pointer(pTraderOffer)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySettlementInfo
func wrapTraderOnRspQrySettlementInfo(v uintptr, pSettlementInfo *C.struct_CThostFtdcSettlementInfoField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySettlementInfo((*thost.CThostFtdcSettlementInfoField)(unsafe.Pointer(pSettlementInfo)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTransferBank
func wrapTraderOnRspQryTransferBank(v uintptr, pTransferBank *C.struct_CThostFtdcTransferBankField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTransferBank((*thost.CThostFtdcTransferBankField)(unsafe.Pointer(pTransferBank)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorPositionDetail
func wrapTraderOnRspQryInvestorPositionDetail(v uintptr, pInvestorPositionDetail *C.struct_CThostFtdcInvestorPositionDetailField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorPositionDetail((*thost.CThostFtdcInvestorPositionDetailField)(unsafe.Pointer(pInvestorPositionDetail)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryNotice
func wrapTraderOnRspQryNotice(v uintptr, pNotice *C.struct_CThostFtdcNoticeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryNotice((*thost.CThostFtdcNoticeField)(unsafe.Pointer(pNotice)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySettlementInfoConfirm
func wrapTraderOnRspQrySettlementInfoConfirm(v uintptr, pSettlementInfoConfirm *C.struct_CThostFtdcSettlementInfoConfirmField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySettlementInfoConfirm((*thost.CThostFtdcSettlementInfoConfirmField)(unsafe.Pointer(pSettlementInfoConfirm)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorPositionCombineDetail
func wrapTraderOnRspQryInvestorPositionCombineDetail(v uintptr, pInvestorPositionCombineDetail *C.struct_CThostFtdcInvestorPositionCombineDetailField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorPositionCombineDetail((*thost.CThostFtdcInvestorPositionCombineDetailField)(unsafe.Pointer(pInvestorPositionCombineDetail)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryCFMMCTradingAccountKey
func wrapTraderOnRspQryCFMMCTradingAccountKey(v uintptr, pCFMMCTradingAccountKey *C.struct_CThostFtdcCFMMCTradingAccountKeyField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryCFMMCTradingAccountKey((*thost.CThostFtdcCFMMCTradingAccountKeyField)(unsafe.Pointer(pCFMMCTradingAccountKey)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryEWarrantOffset
func wrapTraderOnRspQryEWarrantOffset(v uintptr, pEWarrantOffset *C.struct_CThostFtdcEWarrantOffsetField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryEWarrantOffset((*thost.CThostFtdcEWarrantOffsetField)(unsafe.Pointer(pEWarrantOffset)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorProductGroupMargin
func wrapTraderOnRspQryInvestorProductGroupMargin(v uintptr, pInvestorProductGroupMargin *C.struct_CThostFtdcInvestorProductGroupMarginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorProductGroupMargin((*thost.CThostFtdcInvestorProductGroupMarginField)(unsafe.Pointer(pInvestorProductGroupMargin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryExchangeMarginRate
func wrapTraderOnRspQryExchangeMarginRate(v uintptr, pExchangeMarginRate *C.struct_CThostFtdcExchangeMarginRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryExchangeMarginRate((*thost.CThostFtdcExchangeMarginRateField)(unsafe.Pointer(pExchangeMarginRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryExchangeMarginRateAdjust
func wrapTraderOnRspQryExchangeMarginRateAdjust(v uintptr, pExchangeMarginRateAdjust *C.struct_CThostFtdcExchangeMarginRateAdjustField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryExchangeMarginRateAdjust((*thost.CThostFtdcExchangeMarginRateAdjustField)(unsafe.Pointer(pExchangeMarginRateAdjust)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryExchangeRate
func wrapTraderOnRspQryExchangeRate(v uintptr, pExchangeRate *C.struct_CThostFtdcExchangeRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryExchangeRate((*thost.CThostFtdcExchangeRateField)(unsafe.Pointer(pExchangeRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySecAgentACIDMap
func wrapTraderOnRspQrySecAgentACIDMap(v uintptr, pSecAgentACIDMap *C.struct_CThostFtdcSecAgentACIDMapField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySecAgentACIDMap((*thost.CThostFtdcSecAgentACIDMapField)(unsafe.Pointer(pSecAgentACIDMap)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryProductExchRate
func wrapTraderOnRspQryProductExchRate(v uintptr, pProductExchRate *C.struct_CThostFtdcProductExchRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryProductExchRate((*thost.CThostFtdcProductExchRateField)(unsafe.Pointer(pProductExchRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryProductGroup
func wrapTraderOnRspQryProductGroup(v uintptr, pProductGroup *C.struct_CThostFtdcProductGroupField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryProductGroup((*thost.CThostFtdcProductGroupField)(unsafe.Pointer(pProductGroup)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryMMInstrumentCommissionRate
func wrapTraderOnRspQryMMInstrumentCommissionRate(v uintptr, pMMInstrumentCommissionRate *C.struct_CThostFtdcMMInstrumentCommissionRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryMMInstrumentCommissionRate((*thost.CThostFtdcMMInstrumentCommissionRateField)(unsafe.Pointer(pMMInstrumentCommissionRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryMMOptionInstrCommRate
func wrapTraderOnRspQryMMOptionInstrCommRate(v uintptr, pMMOptionInstrCommRate *C.struct_CThostFtdcMMOptionInstrCommRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryMMOptionInstrCommRate((*thost.CThostFtdcMMOptionInstrCommRateField)(unsafe.Pointer(pMMOptionInstrCommRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInstrumentOrderCommRate
func wrapTraderOnRspQryInstrumentOrderCommRate(v uintptr, pInstrumentOrderCommRate *C.struct_CThostFtdcInstrumentOrderCommRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInstrumentOrderCommRate((*thost.CThostFtdcInstrumentOrderCommRateField)(unsafe.Pointer(pInstrumentOrderCommRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySecAgentTradingAccount
func wrapTraderOnRspQrySecAgentTradingAccount(v uintptr, pTradingAccount *C.struct_CThostFtdcTradingAccountField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySecAgentTradingAccount((*thost.CThostFtdcTradingAccountField)(unsafe.Pointer(pTradingAccount)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySecAgentCheckMode
func wrapTraderOnRspQrySecAgentCheckMode(v uintptr, pSecAgentCheckMode *C.struct_CThostFtdcSecAgentCheckModeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySecAgentCheckMode((*thost.CThostFtdcSecAgentCheckModeField)(unsafe.Pointer(pSecAgentCheckMode)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySecAgentTradeInfo
func wrapTraderOnRspQrySecAgentTradeInfo(v uintptr, pSecAgentTradeInfo *C.struct_CThostFtdcSecAgentTradeInfoField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySecAgentTradeInfo((*thost.CThostFtdcSecAgentTradeInfoField)(unsafe.Pointer(pSecAgentTradeInfo)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryOptionInstrTradeCost
func wrapTraderOnRspQryOptionInstrTradeCost(v uintptr, pOptionInstrTradeCost *C.struct_CThostFtdcOptionInstrTradeCostField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryOptionInstrTradeCost((*thost.CThostFtdcOptionInstrTradeCostField)(unsafe.Pointer(pOptionInstrTradeCost)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryOptionInstrCommRate
func wrapTraderOnRspQryOptionInstrCommRate(v uintptr, pOptionInstrCommRate *C.struct_CThostFtdcOptionInstrCommRateField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryOptionInstrCommRate((*thost.CThostFtdcOptionInstrCommRateField)(unsafe.Pointer(pOptionInstrCommRate)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryExecOrder
func wrapTraderOnRspQryExecOrder(v uintptr, pExecOrder *C.struct_CThostFtdcExecOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryExecOrder((*thost.CThostFtdcExecOrderField)(unsafe.Pointer(pExecOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryForQuote
func wrapTraderOnRspQryForQuote(v uintptr, pForQuote *C.struct_CThostFtdcForQuoteField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryForQuote((*thost.CThostFtdcForQuoteField)(unsafe.Pointer(pForQuote)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryQuote
func wrapTraderOnRspQryQuote(v uintptr, pQuote *C.struct_CThostFtdcQuoteField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryQuote((*thost.CThostFtdcQuoteField)(unsafe.Pointer(pQuote)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryOptionSelfClose
func wrapTraderOnRspQryOptionSelfClose(v uintptr, pOptionSelfClose *C.struct_CThostFtdcOptionSelfCloseField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryOptionSelfClose((*thost.CThostFtdcOptionSelfCloseField)(unsafe.Pointer(pOptionSelfClose)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestUnit
func wrapTraderOnRspQryInvestUnit(v uintptr, pInvestUnit *C.struct_CThostFtdcInvestUnitField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestUnit((*thost.CThostFtdcInvestUnitField)(unsafe.Pointer(pInvestUnit)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryCombInstrumentGuard
func wrapTraderOnRspQryCombInstrumentGuard(v uintptr, pCombInstrumentGuard *C.struct_CThostFtdcCombInstrumentGuardField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryCombInstrumentGuard((*thost.CThostFtdcCombInstrumentGuardField)(unsafe.Pointer(pCombInstrumentGuard)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryCombAction
func wrapTraderOnRspQryCombAction(v uintptr, pCombAction *C.struct_CThostFtdcCombActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryCombAction((*thost.CThostFtdcCombActionField)(unsafe.Pointer(pCombAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTransferSerial
func wrapTraderOnRspQryTransferSerial(v uintptr, pTransferSerial *C.struct_CThostFtdcTransferSerialField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTransferSerial((*thost.CThostFtdcTransferSerialField)(unsafe.Pointer(pTransferSerial)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryAccountregister
func wrapTraderOnRspQryAccountregister(v uintptr, pAccountregister *C.struct_CThostFtdcAccountregisterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryAccountregister((*thost.CThostFtdcAccountregisterField)(unsafe.Pointer(pAccountregister)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspError
func wrapTraderOnRspError(v uintptr, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspError((*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRtnOrder
func wrapTraderOnRtnOrder(v uintptr, pOrder *C.struct_CThostFtdcOrderField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnOrder((*thost.CThostFtdcOrderField)(unsafe.Pointer(pOrder)))
}

//export wrapTraderOnRtnTrade
func wrapTraderOnRtnTrade(v uintptr, pTrade *C.struct_CThostFtdcTradeField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnTrade((*thost.CThostFtdcTradeField)(unsafe.Pointer(pTrade)))
}

//export wrapTraderOnErrRtnOrderInsert
func wrapTraderOnErrRtnOrderInsert(v uintptr, pInputOrder *C.struct_CThostFtdcInputOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnOrderInsert((*thost.CThostFtdcInputOrderField)(unsafe.Pointer(pInputOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnOrderAction
func wrapTraderOnErrRtnOrderAction(v uintptr, pOrderAction *C.struct_CThostFtdcOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnOrderAction((*thost.CThostFtdcOrderActionField)(unsafe.Pointer(pOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRtnInstrumentStatus
func wrapTraderOnRtnInstrumentStatus(v uintptr, pInstrumentStatus *C.struct_CThostFtdcInstrumentStatusField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnInstrumentStatus((*thost.CThostFtdcInstrumentStatusField)(unsafe.Pointer(pInstrumentStatus)))
}

//export wrapTraderOnRtnBulletin
func wrapTraderOnRtnBulletin(v uintptr, pBulletin *C.struct_CThostFtdcBulletinField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnBulletin((*thost.CThostFtdcBulletinField)(unsafe.Pointer(pBulletin)))
}

//export wrapTraderOnRtnTradingNotice
func wrapTraderOnRtnTradingNotice(v uintptr, pTradingNoticeInfo *C.struct_CThostFtdcTradingNoticeInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnTradingNotice((*thost.CThostFtdcTradingNoticeInfoField)(unsafe.Pointer(pTradingNoticeInfo)))
}

//export wrapTraderOnRtnErrorConditionalOrder
func wrapTraderOnRtnErrorConditionalOrder(v uintptr, pErrorConditionalOrder *C.struct_CThostFtdcErrorConditionalOrderField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnErrorConditionalOrder((*thost.CThostFtdcErrorConditionalOrderField)(unsafe.Pointer(pErrorConditionalOrder)))
}

//export wrapTraderOnRtnExecOrder
func wrapTraderOnRtnExecOrder(v uintptr, pExecOrder *C.struct_CThostFtdcExecOrderField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnExecOrder((*thost.CThostFtdcExecOrderField)(unsafe.Pointer(pExecOrder)))
}

//export wrapTraderOnErrRtnExecOrderInsert
func wrapTraderOnErrRtnExecOrderInsert(v uintptr, pInputExecOrder *C.struct_CThostFtdcInputExecOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnExecOrderInsert((*thost.CThostFtdcInputExecOrderField)(unsafe.Pointer(pInputExecOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnExecOrderAction
func wrapTraderOnErrRtnExecOrderAction(v uintptr, pExecOrderAction *C.struct_CThostFtdcExecOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnExecOrderAction((*thost.CThostFtdcExecOrderActionField)(unsafe.Pointer(pExecOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnForQuoteInsert
func wrapTraderOnErrRtnForQuoteInsert(v uintptr, pInputForQuote *C.struct_CThostFtdcInputForQuoteField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnForQuoteInsert((*thost.CThostFtdcInputForQuoteField)(unsafe.Pointer(pInputForQuote)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRtnQuote
func wrapTraderOnRtnQuote(v uintptr, pQuote *C.struct_CThostFtdcQuoteField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnQuote((*thost.CThostFtdcQuoteField)(unsafe.Pointer(pQuote)))
}

//export wrapTraderOnErrRtnQuoteInsert
func wrapTraderOnErrRtnQuoteInsert(v uintptr, pInputQuote *C.struct_CThostFtdcInputQuoteField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnQuoteInsert((*thost.CThostFtdcInputQuoteField)(unsafe.Pointer(pInputQuote)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnQuoteAction
func wrapTraderOnErrRtnQuoteAction(v uintptr, pQuoteAction *C.struct_CThostFtdcQuoteActionField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnQuoteAction((*thost.CThostFtdcQuoteActionField)(unsafe.Pointer(pQuoteAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRtnForQuoteRsp
func wrapTraderOnRtnForQuoteRsp(v uintptr, pForQuoteRsp *C.struct_CThostFtdcForQuoteRspField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnForQuoteRsp((*thost.CThostFtdcForQuoteRspField)(unsafe.Pointer(pForQuoteRsp)))
}

//export wrapTraderOnRtnCFMMCTradingAccountToken
func wrapTraderOnRtnCFMMCTradingAccountToken(v uintptr, pCFMMCTradingAccountToken *C.struct_CThostFtdcCFMMCTradingAccountTokenField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnCFMMCTradingAccountToken((*thost.CThostFtdcCFMMCTradingAccountTokenField)(unsafe.Pointer(pCFMMCTradingAccountToken)))
}

//export wrapTraderOnErrRtnBatchOrderAction
func wrapTraderOnErrRtnBatchOrderAction(v uintptr, pBatchOrderAction *C.struct_CThostFtdcBatchOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnBatchOrderAction((*thost.CThostFtdcBatchOrderActionField)(unsafe.Pointer(pBatchOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRtnOptionSelfClose
func wrapTraderOnRtnOptionSelfClose(v uintptr, pOptionSelfClose *C.struct_CThostFtdcOptionSelfCloseField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnOptionSelfClose((*thost.CThostFtdcOptionSelfCloseField)(unsafe.Pointer(pOptionSelfClose)))
}

//export wrapTraderOnErrRtnOptionSelfCloseInsert
func wrapTraderOnErrRtnOptionSelfCloseInsert(v uintptr, pInputOptionSelfClose *C.struct_CThostFtdcInputOptionSelfCloseField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnOptionSelfCloseInsert((*thost.CThostFtdcInputOptionSelfCloseField)(unsafe.Pointer(pInputOptionSelfClose)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnOptionSelfCloseAction
func wrapTraderOnErrRtnOptionSelfCloseAction(v uintptr, pOptionSelfCloseAction *C.struct_CThostFtdcOptionSelfCloseActionField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnOptionSelfCloseAction((*thost.CThostFtdcOptionSelfCloseActionField)(unsafe.Pointer(pOptionSelfCloseAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRtnCombAction
func wrapTraderOnRtnCombAction(v uintptr, pCombAction *C.struct_CThostFtdcCombActionField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnCombAction((*thost.CThostFtdcCombActionField)(unsafe.Pointer(pCombAction)))
}

//export wrapTraderOnErrRtnCombActionInsert
func wrapTraderOnErrRtnCombActionInsert(v uintptr, pInputCombAction *C.struct_CThostFtdcInputCombActionField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnCombActionInsert((*thost.CThostFtdcInputCombActionField)(unsafe.Pointer(pInputCombAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRspQryContractBank
func wrapTraderOnRspQryContractBank(v uintptr, pContractBank *C.struct_CThostFtdcContractBankField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryContractBank((*thost.CThostFtdcContractBankField)(unsafe.Pointer(pContractBank)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryParkedOrder
func wrapTraderOnRspQryParkedOrder(v uintptr, pParkedOrder *C.struct_CThostFtdcParkedOrderField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryParkedOrder((*thost.CThostFtdcParkedOrderField)(unsafe.Pointer(pParkedOrder)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryParkedOrderAction
func wrapTraderOnRspQryParkedOrderAction(v uintptr, pParkedOrderAction *C.struct_CThostFtdcParkedOrderActionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryParkedOrderAction((*thost.CThostFtdcParkedOrderActionField)(unsafe.Pointer(pParkedOrderAction)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryTradingNotice
func wrapTraderOnRspQryTradingNotice(v uintptr, pTradingNotice *C.struct_CThostFtdcTradingNoticeField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryTradingNotice((*thost.CThostFtdcTradingNoticeField)(unsafe.Pointer(pTradingNotice)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryBrokerTradingParams
func wrapTraderOnRspQryBrokerTradingParams(v uintptr, pBrokerTradingParams *C.struct_CThostFtdcBrokerTradingParamsField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryBrokerTradingParams((*thost.CThostFtdcBrokerTradingParamsField)(unsafe.Pointer(pBrokerTradingParams)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryBrokerTradingAlgos
func wrapTraderOnRspQryBrokerTradingAlgos(v uintptr, pBrokerTradingAlgos *C.struct_CThostFtdcBrokerTradingAlgosField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryBrokerTradingAlgos((*thost.CThostFtdcBrokerTradingAlgosField)(unsafe.Pointer(pBrokerTradingAlgos)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQueryCFMMCTradingAccountToken
func wrapTraderOnRspQueryCFMMCTradingAccountToken(v uintptr, pQueryCFMMCTradingAccountToken *C.struct_CThostFtdcQueryCFMMCTradingAccountTokenField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQueryCFMMCTradingAccountToken((*thost.CThostFtdcQueryCFMMCTradingAccountTokenField)(unsafe.Pointer(pQueryCFMMCTradingAccountToken)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRtnFromBankToFutureByBank
func wrapTraderOnRtnFromBankToFutureByBank(v uintptr, pRspTransfer *C.struct_CThostFtdcRspTransferField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnFromBankToFutureByBank((*thost.CThostFtdcRspTransferField)(unsafe.Pointer(pRspTransfer)))
}

//export wrapTraderOnRtnFromFutureToBankByBank
func wrapTraderOnRtnFromFutureToBankByBank(v uintptr, pRspTransfer *C.struct_CThostFtdcRspTransferField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnFromFutureToBankByBank((*thost.CThostFtdcRspTransferField)(unsafe.Pointer(pRspTransfer)))
}

//export wrapTraderOnRtnRepealFromBankToFutureByBank
func wrapTraderOnRtnRepealFromBankToFutureByBank(v uintptr, pRspRepeal *C.struct_CThostFtdcRspRepealField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnRepealFromBankToFutureByBank((*thost.CThostFtdcRspRepealField)(unsafe.Pointer(pRspRepeal)))
}

//export wrapTraderOnRtnRepealFromFutureToBankByBank
func wrapTraderOnRtnRepealFromFutureToBankByBank(v uintptr, pRspRepeal *C.struct_CThostFtdcRspRepealField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnRepealFromFutureToBankByBank((*thost.CThostFtdcRspRepealField)(unsafe.Pointer(pRspRepeal)))
}

//export wrapTraderOnRtnFromBankToFutureByFuture
func wrapTraderOnRtnFromBankToFutureByFuture(v uintptr, pRspTransfer *C.struct_CThostFtdcRspTransferField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnFromBankToFutureByFuture((*thost.CThostFtdcRspTransferField)(unsafe.Pointer(pRspTransfer)))
}

//export wrapTraderOnRtnFromFutureToBankByFuture
func wrapTraderOnRtnFromFutureToBankByFuture(v uintptr, pRspTransfer *C.struct_CThostFtdcRspTransferField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnFromFutureToBankByFuture((*thost.CThostFtdcRspTransferField)(unsafe.Pointer(pRspTransfer)))
}

//export wrapTraderOnRtnRepealFromBankToFutureByFutureManual
func wrapTraderOnRtnRepealFromBankToFutureByFutureManual(v uintptr, pRspRepeal *C.struct_CThostFtdcRspRepealField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnRepealFromBankToFutureByFutureManual((*thost.CThostFtdcRspRepealField)(unsafe.Pointer(pRspRepeal)))
}

//export wrapTraderOnRtnRepealFromFutureToBankByFutureManual
func wrapTraderOnRtnRepealFromFutureToBankByFutureManual(v uintptr, pRspRepeal *C.struct_CThostFtdcRspRepealField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnRepealFromFutureToBankByFutureManual((*thost.CThostFtdcRspRepealField)(unsafe.Pointer(pRspRepeal)))
}

//export wrapTraderOnRtnQueryBankBalanceByFuture
func wrapTraderOnRtnQueryBankBalanceByFuture(v uintptr, pNotifyQueryAccount *C.struct_CThostFtdcNotifyQueryAccountField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnQueryBankBalanceByFuture((*thost.CThostFtdcNotifyQueryAccountField)(unsafe.Pointer(pNotifyQueryAccount)))
}

//export wrapTraderOnErrRtnBankToFutureByFuture
func wrapTraderOnErrRtnBankToFutureByFuture(v uintptr, pReqTransfer *C.struct_CThostFtdcReqTransferField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnBankToFutureByFuture((*thost.CThostFtdcReqTransferField)(unsafe.Pointer(pReqTransfer)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnFutureToBankByFuture
func wrapTraderOnErrRtnFutureToBankByFuture(v uintptr, pReqTransfer *C.struct_CThostFtdcReqTransferField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnFutureToBankByFuture((*thost.CThostFtdcReqTransferField)(unsafe.Pointer(pReqTransfer)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnRepealBankToFutureByFutureManual
func wrapTraderOnErrRtnRepealBankToFutureByFutureManual(v uintptr, pReqRepeal *C.struct_CThostFtdcReqRepealField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnRepealBankToFutureByFutureManual((*thost.CThostFtdcReqRepealField)(unsafe.Pointer(pReqRepeal)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnRepealFutureToBankByFutureManual
func wrapTraderOnErrRtnRepealFutureToBankByFutureManual(v uintptr, pReqRepeal *C.struct_CThostFtdcReqRepealField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnRepealFutureToBankByFutureManual((*thost.CThostFtdcReqRepealField)(unsafe.Pointer(pReqRepeal)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnErrRtnQueryBankBalanceByFuture
func wrapTraderOnErrRtnQueryBankBalanceByFuture(v uintptr, pReqQueryAccount *C.struct_CThostFtdcReqQueryAccountField, pRspInfo *C.struct_CThostFtdcRspInfoField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnErrRtnQueryBankBalanceByFuture((*thost.CThostFtdcReqQueryAccountField)(unsafe.Pointer(pReqQueryAccount)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)))
}

//export wrapTraderOnRtnRepealFromBankToFutureByFuture
func wrapTraderOnRtnRepealFromBankToFutureByFuture(v uintptr, pRspRepeal *C.struct_CThostFtdcRspRepealField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnRepealFromBankToFutureByFuture((*thost.CThostFtdcRspRepealField)(unsafe.Pointer(pRspRepeal)))
}

//export wrapTraderOnRtnRepealFromFutureToBankByFuture
func wrapTraderOnRtnRepealFromFutureToBankByFuture(v uintptr, pRspRepeal *C.struct_CThostFtdcRspRepealField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnRepealFromFutureToBankByFuture((*thost.CThostFtdcRspRepealField)(unsafe.Pointer(pRspRepeal)))
}

//export wrapTraderOnRspFromBankToFutureByFuture
func wrapTraderOnRspFromBankToFutureByFuture(v uintptr, pReqTransfer *C.struct_CThostFtdcReqTransferField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspFromBankToFutureByFuture((*thost.CThostFtdcReqTransferField)(unsafe.Pointer(pReqTransfer)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspFromFutureToBankByFuture
func wrapTraderOnRspFromFutureToBankByFuture(v uintptr, pReqTransfer *C.struct_CThostFtdcReqTransferField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspFromFutureToBankByFuture((*thost.CThostFtdcReqTransferField)(unsafe.Pointer(pReqTransfer)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQueryBankAccountMoneyByFuture
func wrapTraderOnRspQueryBankAccountMoneyByFuture(v uintptr, pReqQueryAccount *C.struct_CThostFtdcReqQueryAccountField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQueryBankAccountMoneyByFuture((*thost.CThostFtdcReqQueryAccountField)(unsafe.Pointer(pReqQueryAccount)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRtnOpenAccountByBank
func wrapTraderOnRtnOpenAccountByBank(v uintptr, pOpenAccount *C.struct_CThostFtdcOpenAccountField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnOpenAccountByBank((*thost.CThostFtdcOpenAccountField)(unsafe.Pointer(pOpenAccount)))
}

//export wrapTraderOnRtnCancelAccountByBank
func wrapTraderOnRtnCancelAccountByBank(v uintptr, pCancelAccount *C.struct_CThostFtdcCancelAccountField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnCancelAccountByBank((*thost.CThostFtdcCancelAccountField)(unsafe.Pointer(pCancelAccount)))
}

//export wrapTraderOnRtnChangeAccountByBank
func wrapTraderOnRtnChangeAccountByBank(v uintptr, pChangeAccount *C.struct_CThostFtdcChangeAccountField) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRtnChangeAccountByBank((*thost.CThostFtdcChangeAccountField)(unsafe.Pointer(pChangeAccount)))
}

//export wrapTraderOnRspQryClassifiedInstrument
func wrapTraderOnRspQryClassifiedInstrument(v uintptr, pInstrument *C.struct_CThostFtdcInstrumentField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryClassifiedInstrument((*thost.CThostFtdcInstrumentField)(unsafe.Pointer(pInstrument)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryCombPromotionParam
func wrapTraderOnRspQryCombPromotionParam(v uintptr, pCombPromotionParam *C.struct_CThostFtdcCombPromotionParamField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryCombPromotionParam((*thost.CThostFtdcCombPromotionParamField)(unsafe.Pointer(pCombPromotionParam)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRiskSettleInvstPosition
func wrapTraderOnRspQryRiskSettleInvstPosition(v uintptr, pRiskSettleInvstPosition *C.struct_CThostFtdcRiskSettleInvstPositionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRiskSettleInvstPosition((*thost.CThostFtdcRiskSettleInvstPositionField)(unsafe.Pointer(pRiskSettleInvstPosition)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRiskSettleProductStatus
func wrapTraderOnRspQryRiskSettleProductStatus(v uintptr, pRiskSettleProductStatus *C.struct_CThostFtdcRiskSettleProductStatusField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRiskSettleProductStatus((*thost.CThostFtdcRiskSettleProductStatusField)(unsafe.Pointer(pRiskSettleProductStatus)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMFutureParameter
func wrapTraderOnRspQrySPBMFutureParameter(v uintptr, pSPBMFutureParameter *C.struct_CThostFtdcSPBMFutureParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMFutureParameter((*thost.CThostFtdcSPBMFutureParameterField)(unsafe.Pointer(pSPBMFutureParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMOptionParameter
func wrapTraderOnRspQrySPBMOptionParameter(v uintptr, pSPBMOptionParameter *C.struct_CThostFtdcSPBMOptionParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMOptionParameter((*thost.CThostFtdcSPBMOptionParameterField)(unsafe.Pointer(pSPBMOptionParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMIntraParameter
func wrapTraderOnRspQrySPBMIntraParameter(v uintptr, pSPBMIntraParameter *C.struct_CThostFtdcSPBMIntraParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMIntraParameter((*thost.CThostFtdcSPBMIntraParameterField)(unsafe.Pointer(pSPBMIntraParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMInterParameter
func wrapTraderOnRspQrySPBMInterParameter(v uintptr, pSPBMInterParameter *C.struct_CThostFtdcSPBMInterParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMInterParameter((*thost.CThostFtdcSPBMInterParameterField)(unsafe.Pointer(pSPBMInterParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMPortfDefinition
func wrapTraderOnRspQrySPBMPortfDefinition(v uintptr, pSPBMPortfDefinition *C.struct_CThostFtdcSPBMPortfDefinitionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMPortfDefinition((*thost.CThostFtdcSPBMPortfDefinitionField)(unsafe.Pointer(pSPBMPortfDefinition)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMInvestorPortfDef
func wrapTraderOnRspQrySPBMInvestorPortfDef(v uintptr, pSPBMInvestorPortfDef *C.struct_CThostFtdcSPBMInvestorPortfDefField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMInvestorPortfDef((*thost.CThostFtdcSPBMInvestorPortfDefField)(unsafe.Pointer(pSPBMInvestorPortfDef)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorPortfMarginRatio
func wrapTraderOnRspQryInvestorPortfMarginRatio(v uintptr, pInvestorPortfMarginRatio *C.struct_CThostFtdcInvestorPortfMarginRatioField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorPortfMarginRatio((*thost.CThostFtdcInvestorPortfMarginRatioField)(unsafe.Pointer(pInvestorPortfMarginRatio)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorProdSPBMDetail
func wrapTraderOnRspQryInvestorProdSPBMDetail(v uintptr, pInvestorProdSPBMDetail *C.struct_CThostFtdcInvestorProdSPBMDetailField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorProdSPBMDetail((*thost.CThostFtdcInvestorProdSPBMDetailField)(unsafe.Pointer(pInvestorProdSPBMDetail)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorCommoditySPMMMargin
func wrapTraderOnRspQryInvestorCommoditySPMMMargin(v uintptr, pInvestorCommoditySPMMMargin *C.struct_CThostFtdcInvestorCommoditySPMMMarginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorCommoditySPMMMargin((*thost.CThostFtdcInvestorCommoditySPMMMarginField)(unsafe.Pointer(pInvestorCommoditySPMMMargin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorCommodityGroupSPMMMargin
func wrapTraderOnRspQryInvestorCommodityGroupSPMMMargin(v uintptr, pInvestorCommodityGroupSPMMMargin *C.struct_CThostFtdcInvestorCommodityGroupSPMMMarginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorCommodityGroupSPMMMargin((*thost.CThostFtdcInvestorCommodityGroupSPMMMarginField)(unsafe.Pointer(pInvestorCommodityGroupSPMMMargin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPMMInstParam
func wrapTraderOnRspQrySPMMInstParam(v uintptr, pSPMMInstParam *C.struct_CThostFtdcSPMMInstParamField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPMMInstParam((*thost.CThostFtdcSPMMInstParamField)(unsafe.Pointer(pSPMMInstParam)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPMMProductParam
func wrapTraderOnRspQrySPMMProductParam(v uintptr, pSPMMProductParam *C.struct_CThostFtdcSPMMProductParamField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPMMProductParam((*thost.CThostFtdcSPMMProductParamField)(unsafe.Pointer(pSPMMProductParam)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQrySPBMAddOnInterParameter
func wrapTraderOnRspQrySPBMAddOnInterParameter(v uintptr, pSPBMAddOnInterParameter *C.struct_CThostFtdcSPBMAddOnInterParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQrySPBMAddOnInterParameter((*thost.CThostFtdcSPBMAddOnInterParameterField)(unsafe.Pointer(pSPBMAddOnInterParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRCAMSCombProductInfo
func wrapTraderOnRspQryRCAMSCombProductInfo(v uintptr, pRCAMSCombProductInfo *C.struct_CThostFtdcRCAMSCombProductInfoField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRCAMSCombProductInfo((*thost.CThostFtdcRCAMSCombProductInfoField)(unsafe.Pointer(pRCAMSCombProductInfo)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRCAMSInstrParameter
func wrapTraderOnRspQryRCAMSInstrParameter(v uintptr, pRCAMSInstrParameter *C.struct_CThostFtdcRCAMSInstrParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRCAMSInstrParameter((*thost.CThostFtdcRCAMSInstrParameterField)(unsafe.Pointer(pRCAMSInstrParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRCAMSIntraParameter
func wrapTraderOnRspQryRCAMSIntraParameter(v uintptr, pRCAMSIntraParameter *C.struct_CThostFtdcRCAMSIntraParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRCAMSIntraParameter((*thost.CThostFtdcRCAMSIntraParameterField)(unsafe.Pointer(pRCAMSIntraParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRCAMSInterParameter
func wrapTraderOnRspQryRCAMSInterParameter(v uintptr, pRCAMSInterParameter *C.struct_CThostFtdcRCAMSInterParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRCAMSInterParameter((*thost.CThostFtdcRCAMSInterParameterField)(unsafe.Pointer(pRCAMSInterParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRCAMSShortOptAdjustParam
func wrapTraderOnRspQryRCAMSShortOptAdjustParam(v uintptr, pRCAMSShortOptAdjustParam *C.struct_CThostFtdcRCAMSShortOptAdjustParamField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRCAMSShortOptAdjustParam((*thost.CThostFtdcRCAMSShortOptAdjustParamField)(unsafe.Pointer(pRCAMSShortOptAdjustParam)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRCAMSInvestorCombPosition
func wrapTraderOnRspQryRCAMSInvestorCombPosition(v uintptr, pRCAMSInvestorCombPosition *C.struct_CThostFtdcRCAMSInvestorCombPositionField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRCAMSInvestorCombPosition((*thost.CThostFtdcRCAMSInvestorCombPositionField)(unsafe.Pointer(pRCAMSInvestorCombPosition)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorProdRCAMSMargin
func wrapTraderOnRspQryInvestorProdRCAMSMargin(v uintptr, pInvestorProdRCAMSMargin *C.struct_CThostFtdcInvestorProdRCAMSMarginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorProdRCAMSMargin((*thost.CThostFtdcInvestorProdRCAMSMarginField)(unsafe.Pointer(pInvestorProdRCAMSMargin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRULEInstrParameter
func wrapTraderOnRspQryRULEInstrParameter(v uintptr, pRULEInstrParameter *C.struct_CThostFtdcRULEInstrParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRULEInstrParameter((*thost.CThostFtdcRULEInstrParameterField)(unsafe.Pointer(pRULEInstrParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRULEIntraParameter
func wrapTraderOnRspQryRULEIntraParameter(v uintptr, pRULEIntraParameter *C.struct_CThostFtdcRULEIntraParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRULEIntraParameter((*thost.CThostFtdcRULEIntraParameterField)(unsafe.Pointer(pRULEIntraParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryRULEInterParameter
func wrapTraderOnRspQryRULEInterParameter(v uintptr, pRULEInterParameter *C.struct_CThostFtdcRULEInterParameterField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryRULEInterParameter((*thost.CThostFtdcRULEInterParameterField)(unsafe.Pointer(pRULEInterParameter)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorProdRULEMargin
func wrapTraderOnRspQryInvestorProdRULEMargin(v uintptr, pInvestorProdRULEMargin *C.struct_CThostFtdcInvestorProdRULEMarginField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorProdRULEMargin((*thost.CThostFtdcInvestorProdRULEMarginField)(unsafe.Pointer(pInvestorProdRULEMargin)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}

//export wrapTraderOnRspQryInvestorPortfSetting
func wrapTraderOnRspQryInvestorPortfSetting(v uintptr, pInvestorPortfSetting *C.struct_CThostFtdcInvestorPortfSettingField, pRspInfo *C.struct_CThostFtdcRspInfoField, nRequestID C.int, bIsLast C._Bool) {
	api := cgo.Handle(v).Value().(*TraderApi)
	api.spi.OnRspQryInvestorPortfSetting((*thost.CThostFtdcInvestorPortfSettingField)(unsafe.Pointer(pInvestorPortfSetting)), (*thost.CThostFtdcRspInfoField)(unsafe.Pointer(pRspInfo)), int(nRequestID), bool(bIsLast))
}
