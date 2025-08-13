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

#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/types.h>

#include "traderapi_wrap.h"

typedef long long intgo;

#ifdef __cplusplus
extern "C" {
#endif

QCTPTraderSpi* _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi()
{
    CThostFtdcTraderApi* pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./data/");
    QCTPTraderSpi* pUserSpi = new QCTPTraderSpi(pUserApi);
    pUserSpi->RegisterSpi(pUserSpi);
    return pUserSpi;
}

QCTPTraderSpi* _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi2(uintptr_t gUserApi, const char* pszFlowPath, bool bIsProductionMode)
{
    // printf("go_user_api %lu\n", gUserApi);
    CThostFtdcTraderApi* pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath, bIsProductionMode);
    QCTPTraderSpi* pUserSpi = new QCTPTraderSpi(pUserApi, gUserApi);
    pUserSpi->RegisterSpi(pUserSpi);
    return pUserSpi;
}

uintptr_t _wrap_CThostFtdcTraderApi_DestroyUserTraderApi(QCTPTraderSpi* pTraderApi)
{
    delete (pTraderApi);
    return 0;
}

// 创建TraderApi
///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
///@return 创建出的UserApi
// CThostFtdcTraderApi * _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi(QCTPTraderSpi* pTraderApi, const char * pszFlowPath)
// {
//     return pTraderApi->CreateFtdcTraderApi(pszFlowPath);
// }

const char* _wrap_CThostFtdcTraderApi_GetApiVersion(QCTPTraderSpi* ptr)
{
    return ptr->GetApiVersion();
}

void _wrap_CThostFtdcTraderApi_Release(QCTPTraderSpi* ptr)
{
    return ptr->Release();
}

void _wrap_CThostFtdcTraderApi_Init(QCTPTraderSpi* ptr)
{
    return ptr->Init();
}

int _wrap_CThostFtdcTraderApi_Join(QCTPTraderSpi* ptr)
{
    return ptr->Join();
}

const char* _wrap_CThostFtdcTraderApi_GetTradingDay(QCTPTraderSpi* ptr)
{
    return ptr->GetTradingDay();
}

void _wrap_CThostFtdcTraderApi_GetFrontInfo(QCTPTraderSpi* ptr, CThostFtdcFrontInfoField* pFrontInfo)
{
    return ptr->GetFrontInfo(pFrontInfo);
}

void _wrap_CThostFtdcTraderApi_RegisterFront(QCTPTraderSpi* ptr, char* pszFrontAddress)
{
    return ptr->RegisterFront(pszFrontAddress);
}

void _wrap_CThostFtdcTraderApi_RegisterNameServer(QCTPTraderSpi* ptr, char* pszNsAddress)
{
    return ptr->RegisterNameServer(pszNsAddress);
}

void _wrap_CThostFtdcTraderApi_RegisterFensUserInfo(QCTPTraderSpi* ptr, CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return ptr->RegisterFensUserInfo(pFensUserInfo);
}

void _wrap_CThostFtdcTraderApi_RegisterSpi(QCTPTraderSpi* ptr, CThostFtdcTraderSpi* pSpi)
{
    return ptr->RegisterSpi(pSpi);
}

void _wrap_CThostFtdcTraderApi_SubscribePrivateTopic(QCTPTraderSpi* ptr, THOST_TE_RESUME_TYPE nResumeType)
{
    return ptr->SubscribePrivateTopic(nResumeType);
}

void _wrap_CThostFtdcTraderApi_SubscribePublicTopic(QCTPTraderSpi* ptr, THOST_TE_RESUME_TYPE nResumeType)
{
    return ptr->SubscribePublicTopic(nResumeType);
}

int _wrap_CThostFtdcTraderApi_ReqAuthenticate(QCTPTraderSpi* ptr, CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
    return ptr->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

int _wrap_CThostFtdcTraderApi_RegisterUserSystemInfo(QCTPTraderSpi* ptr, CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return ptr->RegisterUserSystemInfo(pUserSystemInfo);
}

int _wrap_CThostFtdcTraderApi_SubmitUserSystemInfo(QCTPTraderSpi* ptr, CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return ptr->SubmitUserSystemInfo(pUserSystemInfo);
}

int _wrap_CThostFtdcTraderApi_RegisterWechatUserSystemInfo(QCTPTraderSpi* ptr, CThostFtdcWechatUserSystemInfoField* pUserSystemInfo)
{
    return ptr->RegisterWechatUserSystemInfo(pUserSystemInfo);
}

int _wrap_CThostFtdcTraderApi_SubmitWechatUserSystemInfo(QCTPTraderSpi* ptr, CThostFtdcWechatUserSystemInfoField* pUserSystemInfo)
{
    return ptr->SubmitWechatUserSystemInfo(pUserSystemInfo);
}

int _wrap_CThostFtdcTraderApi_ReqUserLogin(QCTPTraderSpi* ptr, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return ptr->ReqUserLogin(pReqUserLoginField, nRequestID);
}
// Mac 用户登录请求
int _wrap_CThostFtdcTraderApi_ReqUserLoginMac(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length,
    TThostFtdcClientSystemInfoType systemInfo)
{
    return pTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID, length, systemInfo);
}

int _wrap_CThostFtdcTraderApi_ReqUserLogout(QCTPTraderSpi* ptr, CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return ptr->ReqUserLogout(pUserLogout, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqUserPasswordUpdate(QCTPTraderSpi* ptr, CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID)
{
    return ptr->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(QCTPTraderSpi* ptr, CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID)
{
    return ptr->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqUserAuthMethod(QCTPTraderSpi* ptr, CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
    return ptr->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqGenUserCaptcha(QCTPTraderSpi* ptr, CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID)
{
    return ptr->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqGenUserText(QCTPTraderSpi* ptr, CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID)
{
    return ptr->ReqGenUserText(pReqGenUserText, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqUserLoginWithCaptcha(QCTPTraderSpi* ptr, CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID)
{
    return ptr->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqUserLoginWithText(QCTPTraderSpi* ptr, CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID)
{
    return ptr->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqUserLoginWithOTP(QCTPTraderSpi* ptr, CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID)
{
    return ptr->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqOrderInsert(QCTPTraderSpi* ptr, CThostFtdcInputOrderField* pInputOrder, int nRequestID)
{
    return ptr->ReqOrderInsert(pInputOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqParkedOrderInsert(QCTPTraderSpi* ptr, CThostFtdcParkedOrderField* pParkedOrder, int nRequestID)
{
    return ptr->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqParkedOrderAction(QCTPTraderSpi* ptr, CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID)
{
    return ptr->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqOrderAction(QCTPTraderSpi* ptr, CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID)
{
    return ptr->ReqOrderAction(pInputOrderAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryMaxOrderVolume(QCTPTraderSpi* ptr, CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
    return ptr->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqSettlementInfoConfirm(QCTPTraderSpi* ptr, CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID)
{
    return ptr->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqRemoveParkedOrder(QCTPTraderSpi* ptr, CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID)
{
    return ptr->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqRemoveParkedOrderAction(QCTPTraderSpi* ptr, CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID)
{
    return ptr->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqExecOrderInsert(QCTPTraderSpi* ptr, CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
    return ptr->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqExecOrderAction(QCTPTraderSpi* ptr, CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
    return ptr->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqForQuoteInsert(QCTPTraderSpi* ptr, CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID)
{
    return ptr->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQuoteInsert(QCTPTraderSpi* ptr, CThostFtdcInputQuoteField* pInputQuote, int nRequestID)
{
    return ptr->ReqQuoteInsert(pInputQuote, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQuoteAction(QCTPTraderSpi* ptr, CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID)
{
    return ptr->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqBatchOrderAction(QCTPTraderSpi* ptr, CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID)
{
    return ptr->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqOptionSelfCloseInsert(QCTPTraderSpi* ptr, CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
    return ptr->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqOptionSelfCloseAction(QCTPTraderSpi* ptr, CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
    return ptr->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqCombActionInsert(QCTPTraderSpi* ptr, CThostFtdcInputCombActionField* pInputCombAction, int nRequestID)
{
    return ptr->ReqCombActionInsert(pInputCombAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryOrder(QCTPTraderSpi* ptr, CThostFtdcQryOrderField* pQryOrder, int nRequestID)
{
    return ptr->ReqQryOrder(pQryOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTrade(QCTPTraderSpi* ptr, CThostFtdcQryTradeField* pQryTrade, int nRequestID)
{
    return ptr->ReqQryTrade(pQryTrade, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorPosition(QCTPTraderSpi* ptr, CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID)
{
    return ptr->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTradingAccount(QCTPTraderSpi* ptr, CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return ptr->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestor(QCTPTraderSpi* ptr, CThostFtdcQryInvestorField* pQryInvestor, int nRequestID)
{
    return ptr->ReqQryInvestor(pQryInvestor, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTradingCode(QCTPTraderSpi* ptr, CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
    return ptr->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInstrumentMarginRate(QCTPTraderSpi* ptr, CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID)
{
    return ptr->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(QCTPTraderSpi* ptr, CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID)
{
    return ptr->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryUserSession(QCTPTraderSpi* ptr, CThostFtdcQryUserSessionField* pQryUserSession, int nRequestID)
{
    return ptr->ReqQryUserSession(pQryUserSession, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryExchange(QCTPTraderSpi* ptr, CThostFtdcQryExchangeField* pQryExchange, int nRequestID)
{
    return ptr->ReqQryExchange(pQryExchange, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryProduct(QCTPTraderSpi* ptr, CThostFtdcQryProductField* pQryProduct, int nRequestID)
{
    return ptr->ReqQryProduct(pQryProduct, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInstrument(QCTPTraderSpi* ptr, CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID)
{
    return ptr->ReqQryInstrument(pQryInstrument, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryDepthMarketData(QCTPTraderSpi* ptr, CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID)
{
    return ptr->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTraderOffer(QCTPTraderSpi* ptr, CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID)
{
    return ptr->ReqQryTraderOffer(pQryTraderOffer, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySettlementInfo(QCTPTraderSpi* ptr, CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID)
{
    return ptr->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTransferBank(QCTPTraderSpi* ptr, CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID)
{
    return ptr->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorPositionDetail(QCTPTraderSpi* ptr, CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID)
{
    return ptr->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryNotice(QCTPTraderSpi* ptr, CThostFtdcQryNoticeField* pQryNotice, int nRequestID)
{
    return ptr->ReqQryNotice(pQryNotice, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(QCTPTraderSpi* ptr, CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID)
{
    return ptr->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(QCTPTraderSpi* ptr, CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID)
{
    return ptr->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(QCTPTraderSpi* ptr, CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
    return ptr->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryEWarrantOffset(QCTPTraderSpi* ptr, CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID)
{
    return ptr->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(QCTPTraderSpi* ptr, CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID)
{
    return ptr->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRate(QCTPTraderSpi* ptr, CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
    return ptr->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(QCTPTraderSpi* ptr, CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID)
{
    return ptr->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryExchangeRate(QCTPTraderSpi* ptr, CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID)
{
    return ptr->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySecAgentACIDMap(QCTPTraderSpi* ptr, CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID)
{
    return ptr->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryProductExchRate(QCTPTraderSpi* ptr, CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID)
{
    return ptr->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryProductGroup(QCTPTraderSpi* ptr, CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID)
{
    return ptr->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(QCTPTraderSpi* ptr, CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID)
{
    return ptr->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(QCTPTraderSpi* ptr, CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID)
{
    return ptr->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(QCTPTraderSpi* ptr, CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
    return ptr->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(QCTPTraderSpi* ptr, CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return ptr->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySecAgentCheckMode(QCTPTraderSpi* ptr, CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID)
{
    return ptr->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(QCTPTraderSpi* ptr, CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
    return ptr->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(QCTPTraderSpi* ptr, CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
    return ptr->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryOptionInstrCommRate(QCTPTraderSpi* ptr, CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
    return ptr->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryExecOrder(QCTPTraderSpi* ptr, CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
    return ptr->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryForQuote(QCTPTraderSpi* ptr, CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID)
{
    return ptr->ReqQryForQuote(pQryForQuote, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryQuote(QCTPTraderSpi* ptr, CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
    return ptr->ReqQryQuote(pQryQuote, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryOptionSelfClose(QCTPTraderSpi* ptr, CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
    return ptr->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestUnit(QCTPTraderSpi* ptr, CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
    return ptr->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryCombInstrumentGuard(QCTPTraderSpi* ptr, CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
    return ptr->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryCombAction(QCTPTraderSpi* ptr, CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
    return ptr->ReqQryCombAction(pQryCombAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTransferSerial(QCTPTraderSpi* ptr, CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID)
{
    return ptr->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryAccountregister(QCTPTraderSpi* ptr, CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID)
{
    return ptr->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryContractBank(QCTPTraderSpi* ptr, CThostFtdcQryContractBankField* pQryContractBank, int nRequestID)
{
    return ptr->ReqQryContractBank(pQryContractBank, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryParkedOrder(QCTPTraderSpi* ptr, CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
    return ptr->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryParkedOrderAction(QCTPTraderSpi* ptr, CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
    return ptr->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryTradingNotice(QCTPTraderSpi* ptr, CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID)
{
    return ptr->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryBrokerTradingParams(QCTPTraderSpi* ptr, CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID)
{
    return ptr->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(QCTPTraderSpi* ptr, CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
    return ptr->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(QCTPTraderSpi* ptr, CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
    return ptr->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqFromBankToFutureByFuture(QCTPTraderSpi* ptr, CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return ptr->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqFromFutureToBankByFuture(QCTPTraderSpi* ptr, CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return ptr->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(QCTPTraderSpi* ptr, CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
    return ptr->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryClassifiedInstrument(QCTPTraderSpi* ptr, CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
    return ptr->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryCombPromotionParam(QCTPTraderSpi* ptr, CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
    return ptr->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(QCTPTraderSpi* ptr, CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
    return ptr->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(QCTPTraderSpi* ptr, CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
    return ptr->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMFutureParameter(QCTPTraderSpi* ptr, CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID)
{
    return ptr->ReqQrySPBMFutureParameter(pQrySPBMFutureParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMOptionParameter(QCTPTraderSpi* ptr, CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID)
{
    return ptr->ReqQrySPBMOptionParameter(pQrySPBMOptionParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMIntraParameter(QCTPTraderSpi* ptr, CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID)
{
    return ptr->ReqQrySPBMIntraParameter(pQrySPBMIntraParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMInterParameter(QCTPTraderSpi* ptr, CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID)
{
    return ptr->ReqQrySPBMInterParameter(pQrySPBMInterParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMPortfDefinition(QCTPTraderSpi* ptr, CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID)
{
    return ptr->ReqQrySPBMPortfDefinition(pQrySPBMPortfDefinition, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMInvestorPortfDef(QCTPTraderSpi* ptr, CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID)
{
    return ptr->ReqQrySPBMInvestorPortfDef(pQrySPBMInvestorPortfDef, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorPortfMarginRatio(QCTPTraderSpi* ptr, CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID)
{
    return ptr->ReqQryInvestorPortfMarginRatio(pQryInvestorPortfMarginRatio, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdSPBMDetail(QCTPTraderSpi* ptr, CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID)
{
    return ptr->ReqQryInvestorProdSPBMDetail(pQryInvestorProdSPBMDetail, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorCommoditySPMMMargin(QCTPTraderSpi* ptr, CThostFtdcQryInvestorCommoditySPMMMarginField* pQryInvestorCommoditySPMMMargin, int nRequestID)
{
    return ptr->ReqQryInvestorCommoditySPMMMargin(pQryInvestorCommoditySPMMMargin, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorCommodityGroupSPMMMargin(QCTPTraderSpi* ptr, CThostFtdcQryInvestorCommodityGroupSPMMMarginField* pQryInvestorCommodityGroupSPMMMargin, int nRequestID)
{
    return ptr->ReqQryInvestorCommodityGroupSPMMMargin(pQryInvestorCommodityGroupSPMMMargin, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPMMInstParam(QCTPTraderSpi* ptr, CThostFtdcQrySPMMInstParamField* pQrySPMMInstParam, int nRequestID)
{
    return ptr->ReqQrySPMMInstParam(pQrySPMMInstParam, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPMMProductParam(QCTPTraderSpi* ptr, CThostFtdcQrySPMMProductParamField* pQrySPMMProductParam, int nRequestID)
{
    return ptr->ReqQrySPMMProductParam(pQrySPMMProductParam, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQrySPBMAddOnInterParameter(QCTPTraderSpi* ptr, CThostFtdcQrySPBMAddOnInterParameterField* pQrySPBMAddOnInterParameter, int nRequestID)
{
    return ptr->ReqQrySPBMAddOnInterParameter(pQrySPBMAddOnInterParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRCAMSCombProductInfo(QCTPTraderSpi* ptr, CThostFtdcQryRCAMSCombProductInfoField* pQryRCAMSCombProductInfo, int nRequestID)
{
    return ptr->ReqQryRCAMSCombProductInfo(pQryRCAMSCombProductInfo, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInstrParameter(QCTPTraderSpi* ptr, CThostFtdcQryRCAMSInstrParameterField* pQryRCAMSInstrParameter, int nRequestID)
{
    return ptr->ReqQryRCAMSInstrParameter(pQryRCAMSInstrParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRCAMSIntraParameter(QCTPTraderSpi* ptr, CThostFtdcQryRCAMSIntraParameterField* pQryRCAMSIntraParameter, int nRequestID)
{
    return ptr->ReqQryRCAMSIntraParameter(pQryRCAMSIntraParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInterParameter(QCTPTraderSpi* ptr, CThostFtdcQryRCAMSInterParameterField* pQryRCAMSInterParameter, int nRequestID)
{
    return ptr->ReqQryRCAMSInterParameter(pQryRCAMSInterParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRCAMSShortOptAdjustParam(QCTPTraderSpi* ptr, CThostFtdcQryRCAMSShortOptAdjustParamField* pQryRCAMSShortOptAdjustParam, int nRequestID)
{
    return ptr->ReqQryRCAMSShortOptAdjustParam(pQryRCAMSShortOptAdjustParam, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInvestorCombPosition(QCTPTraderSpi* ptr, CThostFtdcQryRCAMSInvestorCombPositionField* pQryRCAMSInvestorCombPosition, int nRequestID)
{
    return ptr->ReqQryRCAMSInvestorCombPosition(pQryRCAMSInvestorCombPosition, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdRCAMSMargin(QCTPTraderSpi* ptr, CThostFtdcQryInvestorProdRCAMSMarginField* pQryInvestorProdRCAMSMargin, int nRequestID)
{
    return ptr->ReqQryInvestorProdRCAMSMargin(pQryInvestorProdRCAMSMargin, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRULEInstrParameter(QCTPTraderSpi* ptr, CThostFtdcQryRULEInstrParameterField* pQryRULEInstrParameter, int nRequestID)
{
    return ptr->ReqQryRULEInstrParameter(pQryRULEInstrParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRULEIntraParameter(QCTPTraderSpi* ptr, CThostFtdcQryRULEIntraParameterField* pQryRULEIntraParameter, int nRequestID)
{
    return ptr->ReqQryRULEIntraParameter(pQryRULEIntraParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryRULEInterParameter(QCTPTraderSpi* ptr, CThostFtdcQryRULEInterParameterField* pQryRULEInterParameter, int nRequestID)
{
    return ptr->ReqQryRULEInterParameter(pQryRULEInterParameter, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdRULEMargin(QCTPTraderSpi* ptr, CThostFtdcQryInvestorProdRULEMarginField* pQryInvestorProdRULEMargin, int nRequestID)
{
    return ptr->ReqQryInvestorProdRULEMargin(pQryInvestorProdRULEMargin, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorPortfSetting(QCTPTraderSpi* ptr, CThostFtdcQryInvestorPortfSettingField* pQryInvestorPortfSetting, int nRequestID)
{
    return ptr->ReqQryInvestorPortfSetting(pQryInvestorPortfSetting, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryInvestorInfoCommRec(QCTPTraderSpi* ptr, CThostFtdcQryInvestorInfoCommRecField* pQryInvestorInfoCommRec, int nRequestID)
{
    return ptr->ReqQryInvestorInfoCommRec(pQryInvestorInfoCommRec, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryCombLeg(QCTPTraderSpi* ptr, CThostFtdcQryCombLegField* pQryCombLeg, int nRequestID)
{
    return ptr->ReqQryCombLeg(pQryCombLeg, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqOffsetSetting(QCTPTraderSpi* ptr, CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID)
{
    return ptr->ReqOffsetSetting(pInputOffsetSetting, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqCancelOffsetSetting(QCTPTraderSpi* ptr, CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID)
{
    return ptr->ReqCancelOffsetSetting(pInputOffsetSetting, nRequestID);
}

int _wrap_CThostFtdcTraderApi_ReqQryOffsetSetting(QCTPTraderSpi* ptr, CThostFtdcQryOffsetSettingField* pQryOffsetSetting, int nRequestID)
{
    return ptr->ReqQryOffsetSetting(pQryOffsetSetting, nRequestID);
}

#ifdef __cplusplus
}
#endif

extern "C" void wrapTraderOnFrontConnected(uintptr_t);
void QCTPTraderSpi::OnFrontConnected()
{
    wrapTraderOnFrontConnected(gUserApi);
}

extern "C" void wrapTraderOnFrontDisconnected(uintptr_t, int);
void QCTPTraderSpi::OnFrontDisconnected(int nReason)
{
    wrapTraderOnFrontDisconnected(gUserApi, nReason);
}

extern "C" void wrapTraderOnHeartBeatWarning(uintptr_t, int);
void QCTPTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
    wrapTraderOnHeartBeatWarning(gUserApi, nTimeLapse);
}

extern "C" void wrapTraderOnRspAuthenticate(uintptr_t, CThostFtdcRspAuthenticateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspAuthenticate(gUserApi, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspUserLogin(uintptr_t, CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserLogin(gUserApi, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspUserLogout(uintptr_t, CThostFtdcUserLogoutField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserLogout(gUserApi, pUserLogout, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspUserPasswordUpdate(uintptr_t, CThostFtdcUserPasswordUpdateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserPasswordUpdate(gUserApi, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspTradingAccountPasswordUpdate(uintptr_t, CThostFtdcTradingAccountPasswordUpdateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspTradingAccountPasswordUpdate(gUserApi, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspUserAuthMethod(uintptr_t, CThostFtdcRspUserAuthMethodField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserAuthMethod(gUserApi, pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspGenUserCaptcha(uintptr_t, CThostFtdcRspGenUserCaptchaField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspGenUserCaptcha(gUserApi, pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspGenUserText(uintptr_t, CThostFtdcRspGenUserTextField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspGenUserText(gUserApi, pRspGenUserText, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspOrderInsert(uintptr_t, CThostFtdcInputOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOrderInsert(gUserApi, pInputOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspParkedOrderInsert(uintptr_t, CThostFtdcParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspParkedOrderInsert(gUserApi, pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspParkedOrderAction(uintptr_t, CThostFtdcParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspParkedOrderAction(gUserApi, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspOrderAction(uintptr_t, CThostFtdcInputOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOrderAction(gUserApi, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryMaxOrderVolume(uintptr_t, CThostFtdcQryMaxOrderVolumeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryMaxOrderVolume(gUserApi, pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspSettlementInfoConfirm(uintptr_t, CThostFtdcSettlementInfoConfirmField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspSettlementInfoConfirm(gUserApi, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspRemoveParkedOrder(uintptr_t, CThostFtdcRemoveParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspRemoveParkedOrder(gUserApi, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspRemoveParkedOrderAction(uintptr_t, CThostFtdcRemoveParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspRemoveParkedOrderAction(gUserApi, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspExecOrderInsert(uintptr_t, CThostFtdcInputExecOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspExecOrderInsert(gUserApi, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspExecOrderAction(uintptr_t, CThostFtdcInputExecOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspExecOrderAction(gUserApi, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspForQuoteInsert(uintptr_t, CThostFtdcInputForQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspForQuoteInsert(gUserApi, pInputForQuote, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQuoteInsert(uintptr_t, CThostFtdcInputQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQuoteInsert(gUserApi, pInputQuote, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQuoteAction(uintptr_t, CThostFtdcInputQuoteActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQuoteAction(gUserApi, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspBatchOrderAction(uintptr_t, CThostFtdcInputBatchOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspBatchOrderAction(gUserApi, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspOptionSelfCloseInsert(uintptr_t, CThostFtdcInputOptionSelfCloseField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOptionSelfCloseInsert(gUserApi, pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspOptionSelfCloseAction(uintptr_t, CThostFtdcInputOptionSelfCloseActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOptionSelfCloseAction(gUserApi, pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspCombActionInsert(uintptr_t, CThostFtdcInputCombActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspCombActionInsert(gUserApi, pInputCombAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryOrder(uintptr_t, CThostFtdcOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOrder(gUserApi, pOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTrade(uintptr_t, CThostFtdcTradeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTrade(gUserApi, pTrade, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorPosition(uintptr_t, CThostFtdcInvestorPositionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPosition(gUserApi, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTradingAccount(uintptr_t, CThostFtdcTradingAccountField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTradingAccount(gUserApi, pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestor(uintptr_t, CThostFtdcInvestorField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestor(gUserApi, pInvestor, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTradingCode(uintptr_t, CThostFtdcTradingCodeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTradingCode(gUserApi, pTradingCode, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInstrumentMarginRate(uintptr_t, CThostFtdcInstrumentMarginRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrumentMarginRate(gUserApi, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInstrumentCommissionRate(uintptr_t, CThostFtdcInstrumentCommissionRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrumentCommissionRate(gUserApi, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryUserSession(uintptr_t, CThostFtdcUserSessionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryUserSession(CThostFtdcUserSessionField* pUserSession, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryUserSession(gUserApi, pUserSession, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryExchange(uintptr_t, CThostFtdcExchangeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchange(gUserApi, pExchange, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryProduct(uintptr_t, CThostFtdcProductField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryProduct(gUserApi, pProduct, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInstrument(uintptr_t, CThostFtdcInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrument(gUserApi, pInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryDepthMarketData(uintptr_t, CThostFtdcDepthMarketDataField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryDepthMarketData(gUserApi, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTraderOffer(uintptr_t, CThostFtdcTraderOfferField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTraderOffer(CThostFtdcTraderOfferField* pTraderOffer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTraderOffer(gUserApi, pTraderOffer, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySettlementInfo(uintptr_t, CThostFtdcSettlementInfoField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySettlementInfo(gUserApi, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTransferBank(uintptr_t, CThostFtdcTransferBankField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTransferBank(gUserApi, pTransferBank, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorPositionDetail(uintptr_t, CThostFtdcInvestorPositionDetailField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPositionDetail(gUserApi, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryNotice(uintptr_t, CThostFtdcNoticeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryNotice(gUserApi, pNotice, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySettlementInfoConfirm(uintptr_t, CThostFtdcSettlementInfoConfirmField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySettlementInfoConfirm(gUserApi, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorPositionCombineDetail(uintptr_t, CThostFtdcInvestorPositionCombineDetailField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPositionCombineDetail(gUserApi, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryCFMMCTradingAccountKey(uintptr_t, CThostFtdcCFMMCTradingAccountKeyField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCFMMCTradingAccountKey(gUserApi, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryEWarrantOffset(uintptr_t, CThostFtdcEWarrantOffsetField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryEWarrantOffset(gUserApi, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorProductGroupMargin(uintptr_t, CThostFtdcInvestorProductGroupMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProductGroupMargin(gUserApi, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryExchangeMarginRate(uintptr_t, CThostFtdcExchangeMarginRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchangeMarginRate(gUserApi, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryExchangeMarginRateAdjust(uintptr_t, CThostFtdcExchangeMarginRateAdjustField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchangeMarginRateAdjust(gUserApi, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryExchangeRate(uintptr_t, CThostFtdcExchangeRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchangeRate(gUserApi, pExchangeRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySecAgentACIDMap(uintptr_t, CThostFtdcSecAgentACIDMapField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentACIDMap(gUserApi, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryProductExchRate(uintptr_t, CThostFtdcProductExchRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryProductExchRate(gUserApi, pProductExchRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryProductGroup(uintptr_t, CThostFtdcProductGroupField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryProductGroup(gUserApi, pProductGroup, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryMMInstrumentCommissionRate(uintptr_t, CThostFtdcMMInstrumentCommissionRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryMMInstrumentCommissionRate(gUserApi, pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryMMOptionInstrCommRate(uintptr_t, CThostFtdcMMOptionInstrCommRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryMMOptionInstrCommRate(gUserApi, pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInstrumentOrderCommRate(uintptr_t, CThostFtdcInstrumentOrderCommRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrumentOrderCommRate(gUserApi, pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySecAgentTradingAccount(uintptr_t, CThostFtdcTradingAccountField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentTradingAccount(gUserApi, pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySecAgentCheckMode(uintptr_t, CThostFtdcSecAgentCheckModeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentCheckMode(gUserApi, pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySecAgentTradeInfo(uintptr_t, CThostFtdcSecAgentTradeInfoField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentTradeInfo(gUserApi, pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryOptionInstrTradeCost(uintptr_t, CThostFtdcOptionInstrTradeCostField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOptionInstrTradeCost(gUserApi, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryOptionInstrCommRate(uintptr_t, CThostFtdcOptionInstrCommRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOptionInstrCommRate(gUserApi, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryExecOrder(uintptr_t, CThostFtdcExecOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExecOrder(gUserApi, pExecOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryForQuote(uintptr_t, CThostFtdcForQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryForQuote(gUserApi, pForQuote, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryQuote(uintptr_t, CThostFtdcQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryQuote(gUserApi, pQuote, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryOptionSelfClose(uintptr_t, CThostFtdcOptionSelfCloseField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOptionSelfClose(gUserApi, pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestUnit(uintptr_t, CThostFtdcInvestUnitField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestUnit(gUserApi, pInvestUnit, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryCombInstrumentGuard(uintptr_t, CThostFtdcCombInstrumentGuardField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombInstrumentGuard(gUserApi, pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryCombAction(uintptr_t, CThostFtdcCombActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombAction(gUserApi, pCombAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTransferSerial(uintptr_t, CThostFtdcTransferSerialField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTransferSerial(gUserApi, pTransferSerial, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryAccountregister(uintptr_t, CThostFtdcAccountregisterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryAccountregister(gUserApi, pAccountregister, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspError(uintptr_t, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspError(gUserApi, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRtnOrder(uintptr_t, CThostFtdcOrderField*);
void QCTPTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
    wrapTraderOnRtnOrder(gUserApi, pOrder);
}

extern "C" void wrapTraderOnRtnTrade(uintptr_t, CThostFtdcTradeField*);
void QCTPTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
    wrapTraderOnRtnTrade(gUserApi, pTrade);
}

extern "C" void wrapTraderOnErrRtnOrderInsert(uintptr_t, CThostFtdcInputOrderField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOrderInsert(gUserApi, pInputOrder, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnOrderAction(uintptr_t, CThostFtdcOrderActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOrderAction(gUserApi, pOrderAction, pRspInfo);
}

extern "C" void wrapTraderOnRtnInstrumentStatus(uintptr_t, CThostFtdcInstrumentStatusField*);
void QCTPTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
    wrapTraderOnRtnInstrumentStatus(gUserApi, pInstrumentStatus);
}

extern "C" void wrapTraderOnRtnBulletin(uintptr_t, CThostFtdcBulletinField*);
void QCTPTraderSpi::OnRtnBulletin(CThostFtdcBulletinField* pBulletin)
{
    wrapTraderOnRtnBulletin(gUserApi, pBulletin);
}

extern "C" void wrapTraderOnRtnTradingNotice(uintptr_t, CThostFtdcTradingNoticeInfoField*);
void QCTPTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
{
    wrapTraderOnRtnTradingNotice(gUserApi, pTradingNoticeInfo);
}

extern "C" void wrapTraderOnRtnErrorConditionalOrder(uintptr_t, CThostFtdcErrorConditionalOrderField*);
void QCTPTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
{
    wrapTraderOnRtnErrorConditionalOrder(gUserApi, pErrorConditionalOrder);
}

extern "C" void wrapTraderOnRtnExecOrder(uintptr_t, CThostFtdcExecOrderField*);
void QCTPTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
{
    wrapTraderOnRtnExecOrder(gUserApi, pExecOrder);
}

extern "C" void wrapTraderOnErrRtnExecOrderInsert(uintptr_t, CThostFtdcInputExecOrderField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnExecOrderInsert(gUserApi, pInputExecOrder, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnExecOrderAction(uintptr_t, CThostFtdcExecOrderActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnExecOrderAction(gUserApi, pExecOrderAction, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnForQuoteInsert(uintptr_t, CThostFtdcInputForQuoteField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnForQuoteInsert(gUserApi, pInputForQuote, pRspInfo);
}

extern "C" void wrapTraderOnRtnQuote(uintptr_t, CThostFtdcQuoteField*);
void QCTPTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
{
    wrapTraderOnRtnQuote(gUserApi, pQuote);
}

extern "C" void wrapTraderOnErrRtnQuoteInsert(uintptr_t, CThostFtdcInputQuoteField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnQuoteInsert(gUserApi, pInputQuote, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnQuoteAction(uintptr_t, CThostFtdcQuoteActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnQuoteAction(gUserApi, pQuoteAction, pRspInfo);
}

extern "C" void wrapTraderOnRtnForQuoteRsp(uintptr_t, CThostFtdcForQuoteRspField*);
void QCTPTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    wrapTraderOnRtnForQuoteRsp(gUserApi, pForQuoteRsp);
}

extern "C" void wrapTraderOnRtnCFMMCTradingAccountToken(uintptr_t, CThostFtdcCFMMCTradingAccountTokenField*);
void QCTPTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
{
    wrapTraderOnRtnCFMMCTradingAccountToken(gUserApi, pCFMMCTradingAccountToken);
}

extern "C" void wrapTraderOnErrRtnBatchOrderAction(uintptr_t, CThostFtdcBatchOrderActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnBatchOrderAction(gUserApi, pBatchOrderAction, pRspInfo);
}

extern "C" void wrapTraderOnRtnOptionSelfClose(uintptr_t, CThostFtdcOptionSelfCloseField*);
void QCTPTraderSpi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose)
{
    wrapTraderOnRtnOptionSelfClose(gUserApi, pOptionSelfClose);
}

extern "C" void wrapTraderOnErrRtnOptionSelfCloseInsert(uintptr_t, CThostFtdcInputOptionSelfCloseField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOptionSelfCloseInsert(gUserApi, pInputOptionSelfClose, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnOptionSelfCloseAction(uintptr_t, CThostFtdcOptionSelfCloseActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOptionSelfCloseAction(gUserApi, pOptionSelfCloseAction, pRspInfo);
}

extern "C" void wrapTraderOnRtnCombAction(uintptr_t, CThostFtdcCombActionField*);
void QCTPTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
{
    wrapTraderOnRtnCombAction(gUserApi, pCombAction);
}

extern "C" void wrapTraderOnErrRtnCombActionInsert(uintptr_t, CThostFtdcInputCombActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnCombActionInsert(gUserApi, pInputCombAction, pRspInfo);
}

extern "C" void wrapTraderOnRspQryContractBank(uintptr_t, CThostFtdcContractBankField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryContractBank(gUserApi, pContractBank, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryParkedOrder(uintptr_t, CThostFtdcParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryParkedOrder(gUserApi, pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryParkedOrderAction(uintptr_t, CThostFtdcParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryParkedOrderAction(gUserApi, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryTradingNotice(uintptr_t, CThostFtdcTradingNoticeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTradingNotice(gUserApi, pTradingNotice, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryBrokerTradingParams(uintptr_t, CThostFtdcBrokerTradingParamsField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryBrokerTradingParams(gUserApi, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryBrokerTradingAlgos(uintptr_t, CThostFtdcBrokerTradingAlgosField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryBrokerTradingAlgos(gUserApi, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQueryCFMMCTradingAccountToken(uintptr_t, CThostFtdcQueryCFMMCTradingAccountTokenField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQueryCFMMCTradingAccountToken(gUserApi, pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRtnFromBankToFutureByBank(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromBankToFutureByBank(gUserApi, pRspTransfer);
}

extern "C" void wrapTraderOnRtnFromFutureToBankByBank(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromFutureToBankByBank(gUserApi, pRspTransfer);
}

extern "C" void wrapTraderOnRtnRepealFromBankToFutureByBank(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromBankToFutureByBank(gUserApi, pRspRepeal);
}

extern "C" void wrapTraderOnRtnRepealFromFutureToBankByBank(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromFutureToBankByBank(gUserApi, pRspRepeal);
}

extern "C" void wrapTraderOnRtnFromBankToFutureByFuture(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromBankToFutureByFuture(gUserApi, pRspTransfer);
}

extern "C" void wrapTraderOnRtnFromFutureToBankByFuture(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromFutureToBankByFuture(gUserApi, pRspTransfer);
}

extern "C" void wrapTraderOnRtnRepealFromBankToFutureByFutureManual(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromBankToFutureByFutureManual(gUserApi, pRspRepeal);
}

extern "C" void wrapTraderOnRtnRepealFromFutureToBankByFutureManual(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromFutureToBankByFutureManual(gUserApi, pRspRepeal);
}

extern "C" void wrapTraderOnRtnQueryBankBalanceByFuture(uintptr_t, CThostFtdcNotifyQueryAccountField*);
void QCTPTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
{
    wrapTraderOnRtnQueryBankBalanceByFuture(gUserApi, pNotifyQueryAccount);
}

extern "C" void wrapTraderOnErrRtnBankToFutureByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnBankToFutureByFuture(gUserApi, pReqTransfer, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnFutureToBankByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnFutureToBankByFuture(gUserApi, pReqTransfer, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnRepealBankToFutureByFutureManual(uintptr_t, CThostFtdcReqRepealField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnRepealBankToFutureByFutureManual(gUserApi, pReqRepeal, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnRepealFutureToBankByFutureManual(uintptr_t, CThostFtdcReqRepealField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnRepealFutureToBankByFutureManual(gUserApi, pReqRepeal, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnQueryBankBalanceByFuture(uintptr_t, CThostFtdcReqQueryAccountField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnQueryBankBalanceByFuture(gUserApi, pReqQueryAccount, pRspInfo);
}

extern "C" void wrapTraderOnRtnRepealFromBankToFutureByFuture(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromBankToFutureByFuture(gUserApi, pRspRepeal);
}

extern "C" void wrapTraderOnRtnRepealFromFutureToBankByFuture(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromFutureToBankByFuture(gUserApi, pRspRepeal);
}

extern "C" void wrapTraderOnRspFromBankToFutureByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspFromBankToFutureByFuture(gUserApi, pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspFromFutureToBankByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspFromFutureToBankByFuture(gUserApi, pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQueryBankAccountMoneyByFuture(uintptr_t, CThostFtdcReqQueryAccountField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQueryBankAccountMoneyByFuture(gUserApi, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRtnOpenAccountByBank(uintptr_t, CThostFtdcOpenAccountField*);
void QCTPTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
{
    wrapTraderOnRtnOpenAccountByBank(gUserApi, pOpenAccount);
}

extern "C" void wrapTraderOnRtnCancelAccountByBank(uintptr_t, CThostFtdcCancelAccountField*);
void QCTPTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
{
    wrapTraderOnRtnCancelAccountByBank(gUserApi, pCancelAccount);
}

extern "C" void wrapTraderOnRtnChangeAccountByBank(uintptr_t, CThostFtdcChangeAccountField*);
void QCTPTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
{
    wrapTraderOnRtnChangeAccountByBank(gUserApi, pChangeAccount);
}

extern "C" void wrapTraderOnRspQryClassifiedInstrument(uintptr_t, CThostFtdcInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryClassifiedInstrument(gUserApi, pInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryCombPromotionParam(uintptr_t, CThostFtdcCombPromotionParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombPromotionParam(gUserApi, pCombPromotionParam, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRiskSettleInvstPosition(uintptr_t, CThostFtdcRiskSettleInvstPositionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRiskSettleInvstPosition(gUserApi, pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRiskSettleProductStatus(uintptr_t, CThostFtdcRiskSettleProductStatusField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRiskSettleProductStatus(gUserApi, pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMFutureParameter(uintptr_t, CThostFtdcSPBMFutureParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField* pSPBMFutureParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMFutureParameter(gUserApi, pSPBMFutureParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMOptionParameter(uintptr_t, CThostFtdcSPBMOptionParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField* pSPBMOptionParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMOptionParameter(gUserApi, pSPBMOptionParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMIntraParameter(uintptr_t, CThostFtdcSPBMIntraParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField* pSPBMIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMIntraParameter(gUserApi, pSPBMIntraParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMInterParameter(uintptr_t, CThostFtdcSPBMInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField* pSPBMInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMInterParameter(gUserApi, pSPBMInterParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMPortfDefinition(uintptr_t, CThostFtdcSPBMPortfDefinitionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField* pSPBMPortfDefinition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMPortfDefinition(gUserApi, pSPBMPortfDefinition, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMInvestorPortfDef(uintptr_t, CThostFtdcSPBMInvestorPortfDefField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField* pSPBMInvestorPortfDef, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMInvestorPortfDef(gUserApi, pSPBMInvestorPortfDef, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorPortfMarginRatio(uintptr_t, CThostFtdcInvestorPortfMarginRatioField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField* pInvestorPortfMarginRatio, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPortfMarginRatio(gUserApi, pInvestorPortfMarginRatio, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorProdSPBMDetail(uintptr_t, CThostFtdcInvestorProdSPBMDetailField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField* pInvestorProdSPBMDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProdSPBMDetail(gUserApi, pInvestorProdSPBMDetail, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorCommoditySPMMMargin(uintptr_t, CThostFtdcInvestorCommoditySPMMMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorCommoditySPMMMargin(CThostFtdcInvestorCommoditySPMMMarginField* pInvestorCommoditySPMMMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorCommoditySPMMMargin(gUserApi, pInvestorCommoditySPMMMargin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorCommodityGroupSPMMMargin(uintptr_t, CThostFtdcInvestorCommodityGroupSPMMMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorCommodityGroupSPMMMargin(CThostFtdcInvestorCommodityGroupSPMMMarginField* pInvestorCommodityGroupSPMMMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorCommodityGroupSPMMMargin(gUserApi, pInvestorCommodityGroupSPMMMargin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPMMInstParam(uintptr_t, CThostFtdcSPMMInstParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPMMInstParam(CThostFtdcSPMMInstParamField* pSPMMInstParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPMMInstParam(gUserApi, pSPMMInstParam, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPMMProductParam(uintptr_t, CThostFtdcSPMMProductParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPMMProductParam(CThostFtdcSPMMProductParamField* pSPMMProductParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPMMProductParam(gUserApi, pSPMMProductParam, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQrySPBMAddOnInterParameter(uintptr_t, CThostFtdcSPBMAddOnInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMAddOnInterParameter(CThostFtdcSPBMAddOnInterParameterField* pSPBMAddOnInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMAddOnInterParameter(gUserApi, pSPBMAddOnInterParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRCAMSCombProductInfo(uintptr_t, CThostFtdcRCAMSCombProductInfoField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSCombProductInfo(CThostFtdcRCAMSCombProductInfoField* pRCAMSCombProductInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSCombProductInfo(gUserApi, pRCAMSCombProductInfo, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRCAMSInstrParameter(uintptr_t, CThostFtdcRCAMSInstrParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSInstrParameter(CThostFtdcRCAMSInstrParameterField* pRCAMSInstrParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSInstrParameter(gUserApi, pRCAMSInstrParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRCAMSIntraParameter(uintptr_t, CThostFtdcRCAMSIntraParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSIntraParameter(CThostFtdcRCAMSIntraParameterField* pRCAMSIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSIntraParameter(gUserApi, pRCAMSIntraParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRCAMSInterParameter(uintptr_t, CThostFtdcRCAMSInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSInterParameter(CThostFtdcRCAMSInterParameterField* pRCAMSInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSInterParameter(gUserApi, pRCAMSInterParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRCAMSShortOptAdjustParam(uintptr_t, CThostFtdcRCAMSShortOptAdjustParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSShortOptAdjustParam(CThostFtdcRCAMSShortOptAdjustParamField* pRCAMSShortOptAdjustParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSShortOptAdjustParam(gUserApi, pRCAMSShortOptAdjustParam, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRCAMSInvestorCombPosition(uintptr_t, CThostFtdcRCAMSInvestorCombPositionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField* pRCAMSInvestorCombPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSInvestorCombPosition(gUserApi, pRCAMSInvestorCombPosition, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorProdRCAMSMargin(uintptr_t, CThostFtdcInvestorProdRCAMSMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProdRCAMSMargin(CThostFtdcInvestorProdRCAMSMarginField* pInvestorProdRCAMSMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProdRCAMSMargin(gUserApi, pInvestorProdRCAMSMargin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRULEInstrParameter(uintptr_t, CThostFtdcRULEInstrParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRULEInstrParameter(CThostFtdcRULEInstrParameterField* pRULEInstrParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRULEInstrParameter(gUserApi, pRULEInstrParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRULEIntraParameter(uintptr_t, CThostFtdcRULEIntraParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRULEIntraParameter(CThostFtdcRULEIntraParameterField* pRULEIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRULEIntraParameter(gUserApi, pRULEIntraParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryRULEInterParameter(uintptr_t, CThostFtdcRULEInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRULEInterParameter(CThostFtdcRULEInterParameterField* pRULEInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRULEInterParameter(gUserApi, pRULEInterParameter, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorProdRULEMargin(uintptr_t, CThostFtdcInvestorProdRULEMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProdRULEMargin(CThostFtdcInvestorProdRULEMarginField* pInvestorProdRULEMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProdRULEMargin(gUserApi, pInvestorProdRULEMargin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorPortfSetting(uintptr_t, CThostFtdcInvestorPortfSettingField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPortfSetting(CThostFtdcInvestorPortfSettingField* pInvestorPortfSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPortfSetting(gUserApi, pInvestorPortfSetting, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryInvestorInfoCommRec(uintptr_t, CThostFtdcInvestorInfoCommRecField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorInfoCommRec(CThostFtdcInvestorInfoCommRecField* pInvestorInfoCommRec, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorInfoCommRec(gUserApi, pInvestorInfoCommRec, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspQryCombLeg(uintptr_t, CThostFtdcCombLegField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombLeg(CThostFtdcCombLegField* pCombLeg, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombLeg(gUserApi, pCombLeg, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspOffsetSetting(uintptr_t, CThostFtdcInputOffsetSettingField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOffsetSetting(gUserApi, pInputOffsetSetting, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRspCancelOffsetSetting(uintptr_t, CThostFtdcInputOffsetSettingField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspCancelOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspCancelOffsetSetting(gUserApi, pInputOffsetSetting, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapTraderOnRtnOffsetSetting(uintptr_t, CThostFtdcOffsetSettingField*);
void QCTPTraderSpi::OnRtnOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting)
{
    wrapTraderOnRtnOffsetSetting(gUserApi, pOffsetSetting);
}

extern "C" void wrapTraderOnErrRtnOffsetSetting(uintptr_t, CThostFtdcInputOffsetSettingField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOffsetSetting(gUserApi, pInputOffsetSetting, pRspInfo);
}

extern "C" void wrapTraderOnErrRtnCancelOffsetSetting(uintptr_t, CThostFtdcCancelOffsetSettingField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnCancelOffsetSetting(CThostFtdcCancelOffsetSettingField* pCancelOffsetSetting, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnCancelOffsetSetting(gUserApi, pCancelOffsetSetting, pRspInfo);
}

extern "C" void wrapTraderOnRspQryOffsetSetting(uintptr_t, CThostFtdcOffsetSettingField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOffsetSetting(gUserApi, pOffsetSetting, pRspInfo, nRequestID, bIsLast);
}

QCTPTraderSpi::QCTPTraderSpi(CThostFtdcTraderApi* pUserApi)
{
    this->pUserApi = pUserApi;
}

QCTPTraderSpi::QCTPTraderSpi(CThostFtdcTraderApi* pUserApi, uintptr_t gUserApi)
{
    this->pUserApi = pUserApi;
    this->gUserApi = gUserApi;
}

const char* QCTPTraderSpi::GetApiVersion()
{
    return this->pUserApi->GetApiVersion();
}

void QCTPTraderSpi::Release()
{
    return this->pUserApi->Release();
}

void QCTPTraderSpi::Init()
{
    return this->pUserApi->Init();
}

int QCTPTraderSpi::Join()
{
    return this->pUserApi->Join();
}

const char* QCTPTraderSpi::GetTradingDay()
{
    return this->pUserApi->GetTradingDay();
}

void QCTPTraderSpi::GetFrontInfo(CThostFtdcFrontInfoField* pFrontInfo)
{
    return this->pUserApi->GetFrontInfo(pFrontInfo);
}

void QCTPTraderSpi::RegisterFront(char* pszFrontAddress)
{
    return this->pUserApi->RegisterFront(pszFrontAddress);
}

void QCTPTraderSpi::RegisterNameServer(char* pszNsAddress)
{
    return this->pUserApi->RegisterNameServer(pszNsAddress);
}

void QCTPTraderSpi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return this->pUserApi->RegisterFensUserInfo(pFensUserInfo);
}

void QCTPTraderSpi::RegisterSpi(CThostFtdcTraderSpi* pSpi)
{
    return this->pUserApi->RegisterSpi(pSpi);
}

void QCTPTraderSpi::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
{
    return this->pUserApi->SubscribePrivateTopic(nResumeType);
}

void QCTPTraderSpi::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
    return this->pUserApi->SubscribePublicTopic(nResumeType);
}

int QCTPTraderSpi::ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
    return this->pUserApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

int QCTPTraderSpi::RegisterUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->RegisterUserSystemInfo(pUserSystemInfo);
}

int QCTPTraderSpi::SubmitUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->SubmitUserSystemInfo(pUserSystemInfo);
}

int QCTPTraderSpi::RegisterWechatUserSystemInfo(CThostFtdcWechatUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->RegisterWechatUserSystemInfo(pUserSystemInfo);
}

int QCTPTraderSpi::SubmitWechatUserSystemInfo(CThostFtdcWechatUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->SubmitWechatUserSystemInfo(pUserSystemInfo);
}

// 用户登录请求
int QCTPTraderSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
#ifdef __APPLE__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID, 0, NULL);
#elif __linux__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
#endif
}

// 用户登录请求
int QCTPTraderSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length,
    TThostFtdcClientSystemInfoType systemInfo)
{
#ifdef __APPLE__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID, length, systemInfo);
#elif __linux__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
#endif
}

int QCTPTraderSpi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return this->pUserApi->ReqUserLogout(pUserLogout, nRequestID);
}

int QCTPTraderSpi::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID)
{
    return this->pUserApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

int QCTPTraderSpi::ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID)
{
    return this->pUserApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

int QCTPTraderSpi::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
    return this->pUserApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

int QCTPTraderSpi::ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID)
{
    return this->pUserApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

int QCTPTraderSpi::ReqGenUserText(CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID)
{
    return this->pUserApi->ReqGenUserText(pReqGenUserText, nRequestID);
}

int QCTPTraderSpi::ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

int QCTPTraderSpi::ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

int QCTPTraderSpi::ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

int QCTPTraderSpi::ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder, int nRequestID)
{
    return this->pUserApi->ReqOrderInsert(pInputOrder, nRequestID);
}

int QCTPTraderSpi::ReqParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

int QCTPTraderSpi::ReqParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

int QCTPTraderSpi::ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID)
{
    return this->pUserApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

int QCTPTraderSpi::ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
    return this->pUserApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

int QCTPTraderSpi::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID)
{
    return this->pUserApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

int QCTPTraderSpi::ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

int QCTPTraderSpi::ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

int QCTPTraderSpi::ReqExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
    return this->pUserApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

int QCTPTraderSpi::ReqExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
    return this->pUserApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

int QCTPTraderSpi::ReqForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID)
{
    return this->pUserApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

int QCTPTraderSpi::ReqQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, int nRequestID)
{
    return this->pUserApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

int QCTPTraderSpi::ReqQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID)
{
    return this->pUserApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

int QCTPTraderSpi::ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID)
{
    return this->pUserApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

int QCTPTraderSpi::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
    return this->pUserApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

int QCTPTraderSpi::ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
    return this->pUserApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

int QCTPTraderSpi::ReqCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, int nRequestID)
{
    return this->pUserApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

int QCTPTraderSpi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder, int nRequestID)
{
    return this->pUserApi->ReqQryOrder(pQryOrder, nRequestID);
}

int QCTPTraderSpi::ReqQryTrade(CThostFtdcQryTradeField* pQryTrade, int nRequestID)
{
    return this->pUserApi->ReqQryTrade(pQryTrade, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

int QCTPTraderSpi::ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return this->pUserApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor, int nRequestID)
{
    return this->pUserApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

int QCTPTraderSpi::ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
    return this->pUserApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

int QCTPTraderSpi::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

int QCTPTraderSpi::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

int QCTPTraderSpi::ReqQryUserSession(CThostFtdcQryUserSessionField* pQryUserSession, int nRequestID)
{
    return this->pUserApi->ReqQryUserSession(pQryUserSession, nRequestID);
}

int QCTPTraderSpi::ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange, int nRequestID)
{
    return this->pUserApi->ReqQryExchange(pQryExchange, nRequestID);
}

int QCTPTraderSpi::ReqQryProduct(CThostFtdcQryProductField* pQryProduct, int nRequestID)
{
    return this->pUserApi->ReqQryProduct(pQryProduct, nRequestID);
}

int QCTPTraderSpi::ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

int QCTPTraderSpi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID)
{
    return this->pUserApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

int QCTPTraderSpi::ReqQryTraderOffer(CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID)
{
    return this->pUserApi->ReqQryTraderOffer(pQryTraderOffer, nRequestID);
}

int QCTPTraderSpi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID)
{
    return this->pUserApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

int QCTPTraderSpi::ReqQryTransferBank(CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID)
{
    return this->pUserApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

int QCTPTraderSpi::ReqQryNotice(CThostFtdcQryNoticeField* pQryNotice, int nRequestID)
{
    return this->pUserApi->ReqQryNotice(pQryNotice, nRequestID);
}

int QCTPTraderSpi::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID)
{
    return this->pUserApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

int QCTPTraderSpi::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
    return this->pUserApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

int QCTPTraderSpi::ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID)
{
    return this->pUserApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

int QCTPTraderSpi::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

int QCTPTraderSpi::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

int QCTPTraderSpi::ReqQryExchangeRate(CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

int QCTPTraderSpi::ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

int QCTPTraderSpi::ReqQryProductExchRate(CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID)
{
    return this->pUserApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

int QCTPTraderSpi::ReqQryProductGroup(CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID)
{
    return this->pUserApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

int QCTPTraderSpi::ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID)
{
    return this->pUserApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

int QCTPTraderSpi::ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

int QCTPTraderSpi::ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

int QCTPTraderSpi::ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

int QCTPTraderSpi::ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

int QCTPTraderSpi::ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

int QCTPTraderSpi::ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
    return this->pUserApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

int QCTPTraderSpi::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

int QCTPTraderSpi::ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
    return this->pUserApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

int QCTPTraderSpi::ReqQryForQuote(CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID)
{
    return this->pUserApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

int QCTPTraderSpi::ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
    return this->pUserApi->ReqQryQuote(pQryQuote, nRequestID);
}

int QCTPTraderSpi::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
    return this->pUserApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestUnit(CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
    return this->pUserApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

int QCTPTraderSpi::ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
    return this->pUserApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

int QCTPTraderSpi::ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
    return this->pUserApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

int QCTPTraderSpi::ReqQryTransferSerial(CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID)
{
    return this->pUserApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

int QCTPTraderSpi::ReqQryAccountregister(CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID)
{
    return this->pUserApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

int QCTPTraderSpi::ReqQryContractBank(CThostFtdcQryContractBankField* pQryContractBank, int nRequestID)
{
    return this->pUserApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

int QCTPTraderSpi::ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

int QCTPTraderSpi::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

int QCTPTraderSpi::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID)
{
    return this->pUserApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

int QCTPTraderSpi::ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID)
{
    return this->pUserApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

int QCTPTraderSpi::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
    return this->pUserApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

int QCTPTraderSpi::ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
    return this->pUserApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

int QCTPTraderSpi::ReqFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return this->pUserApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

int QCTPTraderSpi::ReqFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return this->pUserApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

int QCTPTraderSpi::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
    return this->pUserApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

int QCTPTraderSpi::ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

int QCTPTraderSpi::ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
    return this->pUserApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

int QCTPTraderSpi::ReqQryRiskSettleInvstPosition(CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
    return this->pUserApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

int QCTPTraderSpi::ReqQryRiskSettleProductStatus(CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
    return this->pUserApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMFutureParameter(CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMFutureParameter(pQrySPBMFutureParameter, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMOptionParameter(CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMOptionParameter(pQrySPBMOptionParameter, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMIntraParameter(CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMIntraParameter(pQrySPBMIntraParameter, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMInterParameter(CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMInterParameter(pQrySPBMInterParameter, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMPortfDefinition(CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMPortfDefinition(pQrySPBMPortfDefinition, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMInvestorPortfDef(CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMInvestorPortfDef(pQrySPBMInvestorPortfDef, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorPortfMarginRatio(CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPortfMarginRatio(pQryInvestorPortfMarginRatio, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorProdSPBMDetail(CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProdSPBMDetail(pQryInvestorProdSPBMDetail, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorCommoditySPMMMargin(CThostFtdcQryInvestorCommoditySPMMMarginField* pQryInvestorCommoditySPMMMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorCommoditySPMMMargin(pQryInvestorCommoditySPMMMargin, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorCommodityGroupSPMMMargin(CThostFtdcQryInvestorCommodityGroupSPMMMarginField* pQryInvestorCommodityGroupSPMMMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorCommodityGroupSPMMMargin(pQryInvestorCommodityGroupSPMMMargin, nRequestID);
}

int QCTPTraderSpi::ReqQrySPMMInstParam(CThostFtdcQrySPMMInstParamField* pQrySPMMInstParam, int nRequestID)
{
    return this->pUserApi->ReqQrySPMMInstParam(pQrySPMMInstParam, nRequestID);
}

int QCTPTraderSpi::ReqQrySPMMProductParam(CThostFtdcQrySPMMProductParamField* pQrySPMMProductParam, int nRequestID)
{
    return this->pUserApi->ReqQrySPMMProductParam(pQrySPMMProductParam, nRequestID);
}

int QCTPTraderSpi::ReqQrySPBMAddOnInterParameter(CThostFtdcQrySPBMAddOnInterParameterField* pQrySPBMAddOnInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMAddOnInterParameter(pQrySPBMAddOnInterParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryRCAMSCombProductInfo(CThostFtdcQryRCAMSCombProductInfoField* pQryRCAMSCombProductInfo, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSCombProductInfo(pQryRCAMSCombProductInfo, nRequestID);
}

int QCTPTraderSpi::ReqQryRCAMSInstrParameter(CThostFtdcQryRCAMSInstrParameterField* pQryRCAMSInstrParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSInstrParameter(pQryRCAMSInstrParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryRCAMSIntraParameter(CThostFtdcQryRCAMSIntraParameterField* pQryRCAMSIntraParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSIntraParameter(pQryRCAMSIntraParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryRCAMSInterParameter(CThostFtdcQryRCAMSInterParameterField* pQryRCAMSInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSInterParameter(pQryRCAMSInterParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryRCAMSShortOptAdjustParam(CThostFtdcQryRCAMSShortOptAdjustParamField* pQryRCAMSShortOptAdjustParam, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSShortOptAdjustParam(pQryRCAMSShortOptAdjustParam, nRequestID);
}

int QCTPTraderSpi::ReqQryRCAMSInvestorCombPosition(CThostFtdcQryRCAMSInvestorCombPositionField* pQryRCAMSInvestorCombPosition, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSInvestorCombPosition(pQryRCAMSInvestorCombPosition, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorProdRCAMSMargin(CThostFtdcQryInvestorProdRCAMSMarginField* pQryInvestorProdRCAMSMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProdRCAMSMargin(pQryInvestorProdRCAMSMargin, nRequestID);
}

int QCTPTraderSpi::ReqQryRULEInstrParameter(CThostFtdcQryRULEInstrParameterField* pQryRULEInstrParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRULEInstrParameter(pQryRULEInstrParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryRULEIntraParameter(CThostFtdcQryRULEIntraParameterField* pQryRULEIntraParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRULEIntraParameter(pQryRULEIntraParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryRULEInterParameter(CThostFtdcQryRULEInterParameterField* pQryRULEInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRULEInterParameter(pQryRULEInterParameter, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorProdRULEMargin(CThostFtdcQryInvestorProdRULEMarginField* pQryInvestorProdRULEMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProdRULEMargin(pQryInvestorProdRULEMargin, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorPortfSetting(CThostFtdcQryInvestorPortfSettingField* pQryInvestorPortfSetting, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPortfSetting(pQryInvestorPortfSetting, nRequestID);
}

int QCTPTraderSpi::ReqQryInvestorInfoCommRec(CThostFtdcQryInvestorInfoCommRecField* pQryInvestorInfoCommRec, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorInfoCommRec(pQryInvestorInfoCommRec, nRequestID);
}

int QCTPTraderSpi::ReqQryCombLeg(CThostFtdcQryCombLegField* pQryCombLeg, int nRequestID)
{
    return this->pUserApi->ReqQryCombLeg(pQryCombLeg, nRequestID);
}

int QCTPTraderSpi::ReqOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID)
{
    return this->pUserApi->ReqOffsetSetting(pInputOffsetSetting, nRequestID);
}

int QCTPTraderSpi::ReqCancelOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID)
{
    return this->pUserApi->ReqCancelOffsetSetting(pInputOffsetSetting, nRequestID);
}

int QCTPTraderSpi::ReqQryOffsetSetting(CThostFtdcQryOffsetSettingField* pQryOffsetSetting, int nRequestID)
{
    return this->pUserApi->ReqQryOffsetSetting(pQryOffsetSetting, nRequestID);
}
