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

#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <iostream>
#include <string>

#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"

#include "traderapi_wrap.h"

typedef long long intgo;

const char* TraderApiCreateSymbol = "_ZN19CThostFtdcTraderApi19CreateFtdcTraderApiEPKc";
const char* TraderApiVersionSymbol = "_ZN19CThostFtdcTraderApi13GetApiVersionEv";

#ifdef __cplusplus
extern "C" {
#endif

TTSCTPTraderSpi* _wrap_tts_CThostFtdcTraderApi_CreateFtdcTraderApi()
{
    // CThostFtdcTraderApi* pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./data/");
    // TTSCTPTraderSpi* pUserSpi = new TTSCTPTraderSpi(pUserApi);
    // pUserSpi->RegisterSpi(pUserSpi);
    // return pUserSpi;
    return nullptr;
}

TTSCTPTraderSpi* _wrap_tts_CThostFtdcTraderApi_CreateFtdcTraderApi2(uintptr_t gUserApi, const char* pszFlowPath)
{
    // printf("go_user_api %lu\n", gUserApi);
    // CThostFtdcTraderApi* pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
    // TTSCTPTraderSpi* pUserSpi = new TTSCTPTraderSpi(pUserApi, gUserApi);
    // TTSCTPTraderSpi* pUserSpi = new TTSCTPTraderSpi(gUserApi, pszFlowPath);
    // pUserSpi->RegisterSpi(pUserSpi);
    // return pUserSpi;
    return nullptr;
}

TTSCTPTraderSpi* _wrap_tts_CThostFtdcTraderApi_CreateFtdcTraderApi3(uintptr_t gUserApi, const char* dllpath, const char* pszFlowPath)
{
    // printf("go_user_api %lu\n", gUserApi);
    TTSCTPTraderSpi* pUserSpi = new TTSCTPTraderSpi(gUserApi, dllpath, pszFlowPath);
    pUserSpi->RegisterSpi(pUserSpi);
    return pUserSpi;
}

uintptr_t _wrap_tts_CThostFtdcTraderApi_DestroyUserTraderApi(TTSCTPTraderSpi* pTraderApi)
{
    delete (pTraderApi);
    return 0;
}

// 创建TraderApi
///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
///@return 创建出的UserApi
// CThostFtdcTraderApi * _wrap_tts_CThostFtdcTraderApi_CreateFtdcTraderApi(TTSCTPTraderSpi* pTraderApi, const char * pszFlowPath)
// {
//     return pTraderApi->CreateFtdcTraderApi(pszFlowPath);
// }

// 获取API的版本信息
///@retrun 获取到的版本号
const char* _wrap_tts_CThostFtdcTraderApi_GetApiVersion(TTSCTPTraderSpi* pTraderApi)
{
    return pTraderApi->GetApiVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void _wrap_tts_CThostFtdcTraderApi_Release(TTSCTPTraderSpi* pTraderApi)
{
    pTraderApi->RegisterSpi(NULL);
    return pTraderApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void _wrap_tts_CThostFtdcTraderApi_Init(TTSCTPTraderSpi* pTraderApi)
{
    return pTraderApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int _wrap_tts_CThostFtdcTraderApi_Join(TTSCTPTraderSpi* pTraderApi)
{
    return pTraderApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* _wrap_tts_CThostFtdcTraderApi_GetTradingDay(TTSCTPTraderSpi* pTraderApi)
{
    return pTraderApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void _wrap_tts_CThostFtdcTraderApi_RegisterFront(TTSCTPTraderSpi* pTraderApi, char* pszFrontAddress)
{
    return pTraderApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void _wrap_tts_CThostFtdcTraderApi_RegisterNameServer(TTSCTPTraderSpi* pTraderApi, char* pszNsAddress)
{
    return pTraderApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void _wrap_tts_CThostFtdcTraderApi_RegisterFensUserInfo(TTSCTPTraderSpi* pTraderApi, CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return pTraderApi->RegisterFensUserInfo(pFensUserInfo);
}

// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void _wrap_tts_CThostFtdcTraderApi_RegisterSpi(TTSCTPTraderSpi* pTraderApi, CThostFtdcTraderSpi* pSpi)
{
    // return pTraderApi->RegisterSpi(pSpi);
}

// 订阅私有流。
///@param nResumeType 私有流重传方式
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
void _wrap_tts_CThostFtdcTraderApi_SubscribePrivateTopic(TTSCTPTraderSpi* pTraderApi, enum THOST_TE_RESUME_TYPE nResumeType)
{
    return pTraderApi->SubscribePrivateTopic(nResumeType);
}

// 订阅公共流。
///@param nResumeType 公共流重传方式
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后公共流的内容
///        THOST_TERT_NONE:取消订阅公共流
///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
void _wrap_tts_CThostFtdcTraderApi_SubscribePublicTopic(TTSCTPTraderSpi* pTraderApi, enum THOST_TE_RESUME_TYPE nResumeType)
{
    return pTraderApi->SubscribePublicTopic(nResumeType);
}

// 客户端认证请求
int _wrap_tts_CThostFtdcTraderApi_ReqAuthenticate(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
    return pTraderApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

// 注册用户终端信息，用于中继服务器多连接模式
/// 需要在终端认证成功后，用户登录前调用该接口
int _wrap_tts_CThostFtdcTraderApi_RegisterUserSystemInfo(TTSCTPTraderSpi* pTraderApi, CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return pTraderApi->RegisterUserSystemInfo(pUserSystemInfo);
}

// 上报用户终端信息，用于中继服务器操作员登录模式
/// 操作员登录后，可以多次调用该接口上报客户信息
int _wrap_tts_CThostFtdcTraderApi_SubmitUserSystemInfo(TTSCTPTraderSpi* pTraderApi, CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return pTraderApi->SubmitUserSystemInfo(pUserSystemInfo);
}

// 用户登录请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserLogin(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return pTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

// Mac 用户登录请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserLoginMac(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length,
    TThostFtdcClientSystemInfoType systemInfo)
{
    return pTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID, length, systemInfo);
}

// 登出请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserLogout(TTSCTPTraderSpi* pTraderApi, CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return pTraderApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 用户口令更新请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserPasswordUpdate(TTSCTPTraderSpi* pTraderApi, CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID)
{
    return pTraderApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

// 资金账户口令更新请求
int _wrap_tts_CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(TTSCTPTraderSpi* pTraderApi, CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID)
{
    return pTraderApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

// 查询用户当前支持的认证模式
int _wrap_tts_CThostFtdcTraderApi_ReqUserAuthMethod(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
    return pTraderApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

// 用户发出获取图形验证码请求
int _wrap_tts_CThostFtdcTraderApi_ReqGenUserCaptcha(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID)
{
    return pTraderApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

// 用户发出获取短信验证码请求
int _wrap_tts_CThostFtdcTraderApi_ReqGenUserText(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID)
{
    return pTraderApi->ReqGenUserText(pReqGenUserText, nRequestID);
}

// 用户发出带有图片验证码的登陆请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserLoginWithCaptcha(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID)
{
    return pTraderApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

// 用户发出带有短信验证码的登陆请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserLoginWithText(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID)
{
    return pTraderApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

// 用户发出带有动态口令的登陆请求
int _wrap_tts_CThostFtdcTraderApi_ReqUserLoginWithOTP(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID)
{
    return pTraderApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

// 报单录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqOrderInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputOrderField* pInputOrder, int nRequestID)
{
    return pTraderApi->ReqOrderInsert(pInputOrder, nRequestID);
}

// 预埋单录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqParkedOrderInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcParkedOrderField* pParkedOrder, int nRequestID)
{
    return pTraderApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

// 预埋撤单录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqParkedOrderAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID)
{
    return pTraderApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

// 报单操作请求
int _wrap_tts_CThostFtdcTraderApi_ReqOrderAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID)
{
    return pTraderApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

// 查询最大报单数量请求
int _wrap_tts_CThostFtdcTraderApi_ReqQryMaxOrderVolume(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
    return pTraderApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

// 投资者结算结果确认
int _wrap_tts_CThostFtdcTraderApi_ReqSettlementInfoConfirm(TTSCTPTraderSpi* pTraderApi, CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID)
{
    return pTraderApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

// 请求删除预埋单
int _wrap_tts_CThostFtdcTraderApi_ReqRemoveParkedOrder(TTSCTPTraderSpi* pTraderApi, CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID)
{
    return pTraderApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

// 请求删除预埋撤单
int _wrap_tts_CThostFtdcTraderApi_ReqRemoveParkedOrderAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID)
{
    return pTraderApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

// 执行宣告录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqExecOrderInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
    return pTraderApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

// 执行宣告操作请求
int _wrap_tts_CThostFtdcTraderApi_ReqExecOrderAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
    return pTraderApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

// 询价录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqForQuoteInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID)
{
    return pTraderApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

// 报价录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqQuoteInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputQuoteField* pInputQuote, int nRequestID)
{
    return pTraderApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

// 报价操作请求
int _wrap_tts_CThostFtdcTraderApi_ReqQuoteAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID)
{
    return pTraderApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

// 批量报单操作请求
int _wrap_tts_CThostFtdcTraderApi_ReqBatchOrderAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID)
{
    return pTraderApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

// 期权自对冲录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqOptionSelfCloseInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
    return pTraderApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

// 期权自对冲操作请求
int _wrap_tts_CThostFtdcTraderApi_ReqOptionSelfCloseAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
    return pTraderApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

// 申请组合录入请求
int _wrap_tts_CThostFtdcTraderApi_ReqCombActionInsert(TTSCTPTraderSpi* pTraderApi, CThostFtdcInputCombActionField* pInputCombAction, int nRequestID)
{
    return pTraderApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

// 请求查询报单
int _wrap_tts_CThostFtdcTraderApi_ReqQryOrder(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryOrderField* pQryOrder, int nRequestID)
{
    return pTraderApi->ReqQryOrder(pQryOrder, nRequestID);
}

// 请求查询成交
int _wrap_tts_CThostFtdcTraderApi_ReqQryTrade(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTradeField* pQryTrade, int nRequestID)
{
    return pTraderApi->ReqQryTrade(pQryTrade, nRequestID);
}

// 请求查询投资者持仓
int _wrap_tts_CThostFtdcTraderApi_ReqQryInvestorPosition(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

// 请求查询资金账户
int _wrap_tts_CThostFtdcTraderApi_ReqQryTradingAccount(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return pTraderApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询投资者
int _wrap_tts_CThostFtdcTraderApi_ReqQryInvestor(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorField* pQryInvestor, int nRequestID)
{
    return pTraderApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

// 请求查询交易编码
int _wrap_tts_CThostFtdcTraderApi_ReqQryTradingCode(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
    return pTraderApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

// 请求查询合约保证金率
int _wrap_tts_CThostFtdcTraderApi_ReqQryInstrumentMarginRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID)
{
    return pTraderApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

// 请求查询合约手续费率
int _wrap_tts_CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID)
{
    return pTraderApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

// 请求查询交易所
int _wrap_tts_CThostFtdcTraderApi_ReqQryExchange(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeField* pQryExchange, int nRequestID)
{
    return pTraderApi->ReqQryExchange(pQryExchange, nRequestID);
}

// 请求查询产品
int _wrap_tts_CThostFtdcTraderApi_ReqQryProduct(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryProductField* pQryProduct, int nRequestID)
{
    return pTraderApi->ReqQryProduct(pQryProduct, nRequestID);
}

// 请求查询合约
int _wrap_tts_CThostFtdcTraderApi_ReqQryInstrument(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID)
{
    return pTraderApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

// 请求查询行情
int _wrap_tts_CThostFtdcTraderApi_ReqQryDepthMarketData(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID)
{
    return pTraderApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

// 请求查询投资者结算结果
int _wrap_tts_CThostFtdcTraderApi_ReqQrySettlementInfo(TTSCTPTraderSpi* pTraderApi, CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID)
{
    return pTraderApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

// 请求查询转帐银行
int _wrap_tts_CThostFtdcTraderApi_ReqQryTransferBank(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID)
{
    return pTraderApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

// 请求查询投资者持仓明细
int _wrap_tts_CThostFtdcTraderApi_ReqQryInvestorPositionDetail(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

// 请求查询客户通知
int _wrap_tts_CThostFtdcTraderApi_ReqQryNotice(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryNoticeField* pQryNotice, int nRequestID)
{
    return pTraderApi->ReqQryNotice(pQryNotice, nRequestID);
}

// 请求查询结算信息确认
int _wrap_tts_CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(TTSCTPTraderSpi* pTraderApi, CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID)
{
    return pTraderApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

// 请求查询投资者持仓明细
int _wrap_tts_CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

// 请求查询保证金监管系统经纪公司资金账户密钥
int _wrap_tts_CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
    return pTraderApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

// 请求查询仓单折抵信息
int _wrap_tts_CThostFtdcTraderApi_ReqQryEWarrantOffset(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID)
{
    return pTraderApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

// 请求查询投资者品种/跨品种保证金
int _wrap_tts_CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID)
{
    return pTraderApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

// 请求查询交易所保证金率
int _wrap_tts_CThostFtdcTraderApi_ReqQryExchangeMarginRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
    return pTraderApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

// 请求查询交易所调整保证金率
int _wrap_tts_CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID)
{
    return pTraderApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

// 请求查询汇率
int _wrap_tts_CThostFtdcTraderApi_ReqQryExchangeRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID)
{
    return pTraderApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

// 请求查询二级代理操作员银期权限
int _wrap_tts_CThostFtdcTraderApi_ReqQrySecAgentACIDMap(TTSCTPTraderSpi* pTraderApi, CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

// 请求查询产品报价汇率
int _wrap_tts_CThostFtdcTraderApi_ReqQryProductExchRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID)
{
    return pTraderApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

// 请求查询产品组
int _wrap_tts_CThostFtdcTraderApi_ReqQryProductGroup(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID)
{
    return pTraderApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

// 请求查询做市商合约手续费率
int _wrap_tts_CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID)
{
    return pTraderApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

// 请求查询做市商期权合约手续费
int _wrap_tts_CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID)
{
    return pTraderApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

// 请求查询报单手续费
int _wrap_tts_CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
    return pTraderApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

// 请求查询资金账户
int _wrap_tts_CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询二级代理商资金校验模式
int _wrap_tts_CThostFtdcTraderApi_ReqQrySecAgentCheckMode(TTSCTPTraderSpi* pTraderApi, CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

// 请求查询二级代理商信息
int _wrap_tts_CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(TTSCTPTraderSpi* pTraderApi, CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

// 请求查询期权交易成本
int _wrap_tts_CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
    return pTraderApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

// 请求查询期权合约手续费
int _wrap_tts_CThostFtdcTraderApi_ReqQryOptionInstrCommRate(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
    return pTraderApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

// 请求查询执行宣告
int _wrap_tts_CThostFtdcTraderApi_ReqQryExecOrder(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
    return pTraderApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

// 请求查询询价
int _wrap_tts_CThostFtdcTraderApi_ReqQryForQuote(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID)
{
    return pTraderApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

// 请求查询报价
int _wrap_tts_CThostFtdcTraderApi_ReqQryQuote(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
    return pTraderApi->ReqQryQuote(pQryQuote, nRequestID);
}

// 请求查询期权自对冲
int _wrap_tts_CThostFtdcTraderApi_ReqQryOptionSelfClose(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
    return pTraderApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

// 请求查询投资单元
int _wrap_tts_CThostFtdcTraderApi_ReqQryInvestUnit(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
    return pTraderApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

// 请求查询组合合约安全系数
int _wrap_tts_CThostFtdcTraderApi_ReqQryCombInstrumentGuard(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
    return pTraderApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

// 请求查询申请组合
int _wrap_tts_CThostFtdcTraderApi_ReqQryCombAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
    return pTraderApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

// 请求查询转帐流水
int _wrap_tts_CThostFtdcTraderApi_ReqQryTransferSerial(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID)
{
    return pTraderApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

// 请求查询银期签约关系
int _wrap_tts_CThostFtdcTraderApi_ReqQryAccountregister(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID)
{
    return pTraderApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

// 请求查询签约银行
int _wrap_tts_CThostFtdcTraderApi_ReqQryContractBank(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryContractBankField* pQryContractBank, int nRequestID)
{
    return pTraderApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

// 请求查询预埋单
int _wrap_tts_CThostFtdcTraderApi_ReqQryParkedOrder(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
    return pTraderApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

// 请求查询预埋撤单
int _wrap_tts_CThostFtdcTraderApi_ReqQryParkedOrderAction(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
    return pTraderApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

// 请求查询交易通知
int _wrap_tts_CThostFtdcTraderApi_ReqQryTradingNotice(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID)
{
    return pTraderApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

// 请求查询经纪公司交易参数
int _wrap_tts_CThostFtdcTraderApi_ReqQryBrokerTradingParams(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID)
{
    return pTraderApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

// 请求查询经纪公司交易算法
int _wrap_tts_CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
    return pTraderApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

// 请求查询监控中心用户令牌
int _wrap_tts_CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(TTSCTPTraderSpi* pTraderApi, CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
    return pTraderApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

// 期货发起银行资金转期货请求
int _wrap_tts_CThostFtdcTraderApi_ReqFromBankToFutureByFuture(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return pTraderApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

// 期货发起期货资金转银行请求
int _wrap_tts_CThostFtdcTraderApi_ReqFromFutureToBankByFuture(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return pTraderApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

// 期货发起查询银行余额请求
int _wrap_tts_CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(TTSCTPTraderSpi* pTraderApi, CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
    return pTraderApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

// 请求查询分类合约
int _wrap_tts_CThostFtdcTraderApi_ReqQryClassifiedInstrument(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
    return pTraderApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

// 请求组合优惠比例
int _wrap_tts_CThostFtdcTraderApi_ReqQryCombPromotionParam(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
    return pTraderApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

// 投资者风险结算持仓查询
int _wrap_tts_CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
    return pTraderApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

// 风险结算产品查询
int _wrap_tts_CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(TTSCTPTraderSpi* pTraderApi, CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
    return pTraderApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}

#ifdef __cplusplus
}
#endif

// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
extern "C" void wrap_tts_TraderOnFrontConnected(uintptr_t);
void TTSCTPTraderSpi::OnFrontConnected()
{
    wrap_tts_TraderOnFrontConnected(gUserApi);
}

// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
extern "C" void wrap_tts_TraderOnFrontDisconnected(uintptr_t, int);
void TTSCTPTraderSpi::OnFrontDisconnected(int nReason)
{
    wrap_tts_TraderOnFrontDisconnected(gUserApi, nReason);
}

// 心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
extern "C" void wrap_tts_TraderOnHeartBeatWarning(uintptr_t, int);
void TTSCTPTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
    wrap_tts_TraderOnHeartBeatWarning(gUserApi, nTimeLapse);
}

// 客户端认证响应
extern "C" void wrap_tts_TraderOnRspAuthenticate(uintptr_t, CThostFtdcRspAuthenticateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspAuthenticate(gUserApi, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
}

// 登录请求响应
extern "C" void wrap_tts_TraderOnRspUserLogin(uintptr_t, CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspUserLogin(gUserApi, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

// 登出请求响应
extern "C" void wrap_tts_TraderOnRspUserLogout(uintptr_t, CThostFtdcUserLogoutField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspUserLogout(gUserApi, pUserLogout, pRspInfo, nRequestID, bIsLast);
}

// 用户口令更新请求响应
extern "C" void wrap_tts_TraderOnRspUserPasswordUpdate(uintptr_t, CThostFtdcUserPasswordUpdateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspUserPasswordUpdate(gUserApi, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

// 资金账户口令更新请求响应
extern "C" void wrap_tts_TraderOnRspTradingAccountPasswordUpdate(uintptr_t, CThostFtdcTradingAccountPasswordUpdateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspTradingAccountPasswordUpdate(gUserApi, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

// 查询用户当前支持的认证模式的回复
extern "C" void wrap_tts_TraderOnRspUserAuthMethod(uintptr_t, CThostFtdcRspUserAuthMethodField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspUserAuthMethod(gUserApi, pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast);
}

// 获取图形验证码请求的回复
extern "C" void wrap_tts_TraderOnRspGenUserCaptcha(uintptr_t, CThostFtdcRspGenUserCaptchaField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspGenUserCaptcha(gUserApi, pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast);
}

// 获取短信验证码请求的回复
extern "C" void wrap_tts_TraderOnRspGenUserText(uintptr_t, CThostFtdcRspGenUserTextField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspGenUserText(gUserApi, pRspGenUserText, pRspInfo, nRequestID, bIsLast);
}

// 报单录入请求响应
extern "C" void wrap_tts_TraderOnRspOrderInsert(uintptr_t, CThostFtdcInputOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspOrderInsert(gUserApi, pInputOrder, pRspInfo, nRequestID, bIsLast);
}

// 预埋单录入请求响应
extern "C" void wrap_tts_TraderOnRspParkedOrderInsert(uintptr_t, CThostFtdcParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspParkedOrderInsert(gUserApi, pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

// 预埋撤单录入请求响应
extern "C" void wrap_tts_TraderOnRspParkedOrderAction(uintptr_t, CThostFtdcParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspParkedOrderAction(gUserApi, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 报单操作请求响应
extern "C" void wrap_tts_TraderOnRspOrderAction(uintptr_t, CThostFtdcInputOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspOrderAction(gUserApi, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 查询最大报单数量响应
extern "C" void wrap_tts_TraderOnRspQryMaxOrderVolume(uintptr_t, CThostFtdcQryMaxOrderVolumeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryMaxOrderVolume(gUserApi, pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
}

// 投资者结算结果确认响应
extern "C" void wrap_tts_TraderOnRspSettlementInfoConfirm(uintptr_t, CThostFtdcSettlementInfoConfirmField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspSettlementInfoConfirm(gUserApi, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

// 删除预埋单响应
extern "C" void wrap_tts_TraderOnRspRemoveParkedOrder(uintptr_t, CThostFtdcRemoveParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspRemoveParkedOrder(gUserApi, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
}

// 删除预埋撤单响应
extern "C" void wrap_tts_TraderOnRspRemoveParkedOrderAction(uintptr_t, CThostFtdcRemoveParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspRemoveParkedOrderAction(gUserApi, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 执行宣告录入请求响应
extern "C" void wrap_tts_TraderOnRspExecOrderInsert(uintptr_t, CThostFtdcInputExecOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspExecOrderInsert(gUserApi, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
}

// 执行宣告操作请求响应
extern "C" void wrap_tts_TraderOnRspExecOrderAction(uintptr_t, CThostFtdcInputExecOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspExecOrderAction(gUserApi, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 询价录入请求响应
extern "C" void wrap_tts_TraderOnRspForQuoteInsert(uintptr_t, CThostFtdcInputForQuoteField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspForQuoteInsert(gUserApi, pInputForQuote, pRspInfo, nRequestID, bIsLast);
}

// 报价录入请求响应
extern "C" void wrap_tts_TraderOnRspQuoteInsert(uintptr_t, CThostFtdcInputQuoteField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQuoteInsert(gUserApi, pInputQuote, pRspInfo, nRequestID, bIsLast);
}

// 报价操作请求响应
extern "C" void wrap_tts_TraderOnRspQuoteAction(uintptr_t, CThostFtdcInputQuoteActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQuoteAction(gUserApi, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
}

// 批量报单操作请求响应
extern "C" void wrap_tts_TraderOnRspBatchOrderAction(uintptr_t, CThostFtdcInputBatchOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspBatchOrderAction(gUserApi, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 期权自对冲录入请求响应
extern "C" void wrap_tts_TraderOnRspOptionSelfCloseInsert(uintptr_t, CThostFtdcInputOptionSelfCloseField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspOptionSelfCloseInsert(gUserApi, pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
}

// 期权自对冲操作请求响应
extern "C" void wrap_tts_TraderOnRspOptionSelfCloseAction(uintptr_t, CThostFtdcInputOptionSelfCloseActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspOptionSelfCloseAction(gUserApi, pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
}

// 申请组合录入请求响应
extern "C" void wrap_tts_TraderOnRspCombActionInsert(uintptr_t, CThostFtdcInputCombActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspCombActionInsert(gUserApi, pInputCombAction, pRspInfo, nRequestID, bIsLast);
}

// 请求查询报单响应
extern "C" void wrap_tts_TraderOnRspQryOrder(uintptr_t, CThostFtdcOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryOrder(gUserApi, pOrder, pRspInfo, nRequestID, bIsLast);
}

// 请求查询成交响应
extern "C" void wrap_tts_TraderOnRspQryTrade(uintptr_t, CThostFtdcTradeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryTrade(gUserApi, pTrade, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者持仓响应
extern "C" void wrap_tts_TraderOnRspQryInvestorPosition(uintptr_t, CThostFtdcInvestorPositionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInvestorPosition(gUserApi, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
}

// 请求查询资金账户响应
extern "C" void wrap_tts_TraderOnRspQryTradingAccount(uintptr_t, CThostFtdcTradingAccountField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryTradingAccount(gUserApi, pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者响应
extern "C" void wrap_tts_TraderOnRspQryInvestor(uintptr_t, CThostFtdcInvestorField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInvestor(gUserApi, pInvestor, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易编码响应
extern "C" void wrap_tts_TraderOnRspQryTradingCode(uintptr_t, CThostFtdcTradingCodeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryTradingCode(gUserApi, pTradingCode, pRspInfo, nRequestID, bIsLast);
}

// 请求查询合约保证金率响应
extern "C" void wrap_tts_TraderOnRspQryInstrumentMarginRate(uintptr_t, CThostFtdcInstrumentMarginRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInstrumentMarginRate(gUserApi, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询合约手续费率响应
extern "C" void wrap_tts_TraderOnRspQryInstrumentCommissionRate(uintptr_t, CThostFtdcInstrumentCommissionRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInstrumentCommissionRate(gUserApi, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易所响应
extern "C" void wrap_tts_TraderOnRspQryExchange(uintptr_t, CThostFtdcExchangeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryExchange(gUserApi, pExchange, pRspInfo, nRequestID, bIsLast);
}

// 请求查询产品响应
extern "C" void wrap_tts_TraderOnRspQryProduct(uintptr_t, CThostFtdcProductField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryProduct(gUserApi, pProduct, pRspInfo, nRequestID, bIsLast);
}

// 请求查询合约响应
extern "C" void wrap_tts_TraderOnRspQryInstrument(uintptr_t, CThostFtdcInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInstrument(gUserApi, pInstrument, pRspInfo, nRequestID, bIsLast);
}

// 请求查询行情响应
extern "C" void wrap_tts_TraderOnRspQryDepthMarketData(uintptr_t, CThostFtdcDepthMarketDataField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryDepthMarketData(gUserApi, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者结算结果响应
extern "C" void wrap_tts_TraderOnRspQrySettlementInfo(uintptr_t, CThostFtdcSettlementInfoField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQrySettlementInfo(gUserApi, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
}

// 请求查询转帐银行响应
extern "C" void wrap_tts_TraderOnRspQryTransferBank(uintptr_t, CThostFtdcTransferBankField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryTransferBank(gUserApi, pTransferBank, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者持仓明细响应
extern "C" void wrap_tts_TraderOnRspQryInvestorPositionDetail(uintptr_t, CThostFtdcInvestorPositionDetailField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInvestorPositionDetail(gUserApi, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
}

// 请求查询客户通知响应
extern "C" void wrap_tts_TraderOnRspQryNotice(uintptr_t, CThostFtdcNoticeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryNotice(gUserApi, pNotice, pRspInfo, nRequestID, bIsLast);
}

// 请求查询结算信息确认响应
extern "C" void wrap_tts_TraderOnRspQrySettlementInfoConfirm(uintptr_t, CThostFtdcSettlementInfoConfirmField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQrySettlementInfoConfirm(gUserApi, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者持仓明细响应
extern "C" void wrap_tts_TraderOnRspQryInvestorPositionCombineDetail(uintptr_t, CThostFtdcInvestorPositionCombineDetailField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInvestorPositionCombineDetail(gUserApi, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
}

// 查询保证金监管系统经纪公司资金账户密钥响应
extern "C" void wrap_tts_TraderOnRspQryCFMMCTradingAccountKey(uintptr_t, CThostFtdcCFMMCTradingAccountKeyField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryCFMMCTradingAccountKey(gUserApi, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
}

// 请求查询仓单折抵信息响应
extern "C" void wrap_tts_TraderOnRspQryEWarrantOffset(uintptr_t, CThostFtdcEWarrantOffsetField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryEWarrantOffset(gUserApi, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者品种/跨品种保证金响应
extern "C" void wrap_tts_TraderOnRspQryInvestorProductGroupMargin(uintptr_t, CThostFtdcInvestorProductGroupMarginField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInvestorProductGroupMargin(gUserApi, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易所保证金率响应
extern "C" void wrap_tts_TraderOnRspQryExchangeMarginRate(uintptr_t, CThostFtdcExchangeMarginRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryExchangeMarginRate(gUserApi, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易所调整保证金率响应
extern "C" void wrap_tts_TraderOnRspQryExchangeMarginRateAdjust(uintptr_t, CThostFtdcExchangeMarginRateAdjustField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryExchangeMarginRateAdjust(gUserApi, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
}

// 请求查询汇率响应
extern "C" void wrap_tts_TraderOnRspQryExchangeRate(uintptr_t, CThostFtdcExchangeRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryExchangeRate(gUserApi, pExchangeRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询二级代理操作员银期权限响应
extern "C" void wrap_tts_TraderOnRspQrySecAgentACIDMap(uintptr_t, CThostFtdcSecAgentACIDMapField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQrySecAgentACIDMap(gUserApi, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
}

// 请求查询产品报价汇率
extern "C" void wrap_tts_TraderOnRspQryProductExchRate(uintptr_t, CThostFtdcProductExchRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryProductExchRate(gUserApi, pProductExchRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询产品组
extern "C" void wrap_tts_TraderOnRspQryProductGroup(uintptr_t, CThostFtdcProductGroupField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryProductGroup(gUserApi, pProductGroup, pRspInfo, nRequestID, bIsLast);
}

// 请求查询做市商合约手续费率响应
extern "C" void wrap_tts_TraderOnRspQryMMInstrumentCommissionRate(uintptr_t, CThostFtdcMMInstrumentCommissionRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryMMInstrumentCommissionRate(gUserApi, pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询做市商期权合约手续费响应
extern "C" void wrap_tts_TraderOnRspQryMMOptionInstrCommRate(uintptr_t, CThostFtdcMMOptionInstrCommRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryMMOptionInstrCommRate(gUserApi, pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询报单手续费响应
extern "C" void wrap_tts_TraderOnRspQryInstrumentOrderCommRate(uintptr_t, CThostFtdcInstrumentOrderCommRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInstrumentOrderCommRate(gUserApi, pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询资金账户响应
extern "C" void wrap_tts_TraderOnRspQrySecAgentTradingAccount(uintptr_t, CThostFtdcTradingAccountField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQrySecAgentTradingAccount(gUserApi, pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

// 请求查询二级代理商资金校验模式响应
extern "C" void wrap_tts_TraderOnRspQrySecAgentCheckMode(uintptr_t, CThostFtdcSecAgentCheckModeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQrySecAgentCheckMode(gUserApi, pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast);
}

// 请求查询二级代理商信息响应
extern "C" void wrap_tts_TraderOnRspQrySecAgentTradeInfo(uintptr_t, CThostFtdcSecAgentTradeInfoField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQrySecAgentTradeInfo(gUserApi, pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast);
}

// 请求查询期权交易成本响应
extern "C" void wrap_tts_TraderOnRspQryOptionInstrTradeCost(uintptr_t, CThostFtdcOptionInstrTradeCostField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryOptionInstrTradeCost(gUserApi, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
}

// 请求查询期权合约手续费响应
extern "C" void wrap_tts_TraderOnRspQryOptionInstrCommRate(uintptr_t, CThostFtdcOptionInstrCommRateField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryOptionInstrCommRate(gUserApi, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询执行宣告响应
extern "C" void wrap_tts_TraderOnRspQryExecOrder(uintptr_t, CThostFtdcExecOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryExecOrder(gUserApi, pExecOrder, pRspInfo, nRequestID, bIsLast);
}

// 请求查询询价响应
extern "C" void wrap_tts_TraderOnRspQryForQuote(uintptr_t, CThostFtdcForQuoteField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryForQuote(gUserApi, pForQuote, pRspInfo, nRequestID, bIsLast);
}

// 请求查询报价响应
extern "C" void wrap_tts_TraderOnRspQryQuote(uintptr_t, CThostFtdcQuoteField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryQuote(gUserApi, pQuote, pRspInfo, nRequestID, bIsLast);
}

// 请求查询期权自对冲响应
extern "C" void wrap_tts_TraderOnRspQryOptionSelfClose(uintptr_t, CThostFtdcOptionSelfCloseField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryOptionSelfClose(gUserApi, pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资单元响应
extern "C" void wrap_tts_TraderOnRspQryInvestUnit(uintptr_t, CThostFtdcInvestUnitField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryInvestUnit(gUserApi, pInvestUnit, pRspInfo, nRequestID, bIsLast);
}

// 请求查询组合合约安全系数响应
extern "C" void wrap_tts_TraderOnRspQryCombInstrumentGuard(uintptr_t, CThostFtdcCombInstrumentGuardField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryCombInstrumentGuard(gUserApi, pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
}

// 请求查询申请组合响应
extern "C" void wrap_tts_TraderOnRspQryCombAction(uintptr_t, CThostFtdcCombActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryCombAction(gUserApi, pCombAction, pRspInfo, nRequestID, bIsLast);
}

// 请求查询转帐流水响应
extern "C" void wrap_tts_TraderOnRspQryTransferSerial(uintptr_t, CThostFtdcTransferSerialField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryTransferSerial(gUserApi, pTransferSerial, pRspInfo, nRequestID, bIsLast);
}

// 请求查询银期签约关系响应
extern "C" void wrap_tts_TraderOnRspQryAccountregister(uintptr_t, CThostFtdcAccountregisterField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryAccountregister(gUserApi, pAccountregister, pRspInfo, nRequestID, bIsLast);
}

// 错误应答
extern "C" void wrap_tts_TraderOnRspError(uintptr_t, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspError(gUserApi, pRspInfo, nRequestID, bIsLast);
}

// 报单通知
extern "C" void wrap_tts_TraderOnRtnOrder(uintptr_t, CThostFtdcOrderField*);
void TTSCTPTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
    wrap_tts_TraderOnRtnOrder(gUserApi, pOrder);
}

// 成交通知
extern "C" void wrap_tts_TraderOnRtnTrade(uintptr_t, CThostFtdcTradeField*);
void TTSCTPTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
    wrap_tts_TraderOnRtnTrade(gUserApi, pTrade);
}

// 报单录入错误回报
extern "C" void wrap_tts_TraderOnErrRtnOrderInsert(uintptr_t, CThostFtdcInputOrderField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnOrderInsert(gUserApi, pInputOrder, pRspInfo);
}

// 报单操作错误回报
extern "C" void wrap_tts_TraderOnErrRtnOrderAction(uintptr_t, CThostFtdcOrderActionField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnOrderAction(gUserApi, pOrderAction, pRspInfo);
}

// 合约交易状态通知
extern "C" void wrap_tts_TraderOnRtnInstrumentStatus(uintptr_t, CThostFtdcInstrumentStatusField*);
void TTSCTPTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
    wrap_tts_TraderOnRtnInstrumentStatus(gUserApi, pInstrumentStatus);
}

// 交易所公告通知
extern "C" void wrap_tts_TraderOnRtnBulletin(uintptr_t, CThostFtdcBulletinField*);
void TTSCTPTraderSpi::OnRtnBulletin(CThostFtdcBulletinField* pBulletin)
{
    wrap_tts_TraderOnRtnBulletin(gUserApi, pBulletin);
}

// 交易通知
extern "C" void wrap_tts_TraderOnRtnTradingNotice(uintptr_t, CThostFtdcTradingNoticeInfoField*);
void TTSCTPTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
{
    wrap_tts_TraderOnRtnTradingNotice(gUserApi, pTradingNoticeInfo);
}

// 提示条件单校验错误
extern "C" void wrap_tts_TraderOnRtnErrorConditionalOrder(uintptr_t, CThostFtdcErrorConditionalOrderField*);
void TTSCTPTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
{
    wrap_tts_TraderOnRtnErrorConditionalOrder(gUserApi, pErrorConditionalOrder);
}

// 执行宣告通知
extern "C" void wrap_tts_TraderOnRtnExecOrder(uintptr_t, CThostFtdcExecOrderField*);
void TTSCTPTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
{
    wrap_tts_TraderOnRtnExecOrder(gUserApi, pExecOrder);
}

// 执行宣告录入错误回报
extern "C" void wrap_tts_TraderOnErrRtnExecOrderInsert(uintptr_t, CThostFtdcInputExecOrderField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnExecOrderInsert(gUserApi, pInputExecOrder, pRspInfo);
}

// 执行宣告操作错误回报
extern "C" void wrap_tts_TraderOnErrRtnExecOrderAction(uintptr_t, CThostFtdcExecOrderActionField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnExecOrderAction(gUserApi, pExecOrderAction, pRspInfo);
}

// 询价录入错误回报
extern "C" void wrap_tts_TraderOnErrRtnForQuoteInsert(uintptr_t, CThostFtdcInputForQuoteField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnForQuoteInsert(gUserApi, pInputForQuote, pRspInfo);
}

// 报价通知
extern "C" void wrap_tts_TraderOnRtnQuote(uintptr_t, CThostFtdcQuoteField*);
void TTSCTPTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
{
    wrap_tts_TraderOnRtnQuote(gUserApi, pQuote);
}

// 报价录入错误回报
extern "C" void wrap_tts_TraderOnErrRtnQuoteInsert(uintptr_t, CThostFtdcInputQuoteField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnQuoteInsert(gUserApi, pInputQuote, pRspInfo);
}

// 报价操作错误回报
extern "C" void wrap_tts_TraderOnErrRtnQuoteAction(uintptr_t, CThostFtdcQuoteActionField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnQuoteAction(gUserApi, pQuoteAction, pRspInfo);
}

// 询价通知
extern "C" void wrap_tts_TraderOnRtnForQuoteRsp(uintptr_t, CThostFtdcForQuoteRspField*);
void TTSCTPTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    wrap_tts_TraderOnRtnForQuoteRsp(gUserApi, pForQuoteRsp);
}

// 保证金监控中心用户令牌
extern "C" void wrap_tts_TraderOnRtnCFMMCTradingAccountToken(uintptr_t, CThostFtdcCFMMCTradingAccountTokenField*);
void TTSCTPTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
{
    wrap_tts_TraderOnRtnCFMMCTradingAccountToken(gUserApi, pCFMMCTradingAccountToken);
}

// 批量报单操作错误回报
extern "C" void wrap_tts_TraderOnErrRtnBatchOrderAction(uintptr_t, CThostFtdcBatchOrderActionField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnBatchOrderAction(gUserApi, pBatchOrderAction, pRspInfo);
}

// 期权自对冲通知
extern "C" void wrap_tts_TraderOnRtnOptionSelfClose(uintptr_t, CThostFtdcOptionSelfCloseField*);
void TTSCTPTraderSpi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose)
{
    wrap_tts_TraderOnRtnOptionSelfClose(gUserApi, pOptionSelfClose);
}

// 期权自对冲录入错误回报
extern "C" void wrap_tts_TraderOnErrRtnOptionSelfCloseInsert(uintptr_t, CThostFtdcInputOptionSelfCloseField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnOptionSelfCloseInsert(gUserApi, pInputOptionSelfClose, pRspInfo);
}

// 期权自对冲操作错误回报
extern "C" void wrap_tts_TraderOnErrRtnOptionSelfCloseAction(uintptr_t, CThostFtdcOptionSelfCloseActionField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnOptionSelfCloseAction(gUserApi, pOptionSelfCloseAction, pRspInfo);
}

// 申请组合通知
extern "C" void wrap_tts_TraderOnRtnCombAction(uintptr_t, CThostFtdcCombActionField*);
void TTSCTPTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
{
    wrap_tts_TraderOnRtnCombAction(gUserApi, pCombAction);
}

// 申请组合录入错误回报
extern "C" void wrap_tts_TraderOnErrRtnCombActionInsert(uintptr_t, CThostFtdcInputCombActionField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnCombActionInsert(gUserApi, pInputCombAction, pRspInfo);
}

// 请求查询签约银行响应
extern "C" void wrap_tts_TraderOnRspQryContractBank(uintptr_t, CThostFtdcContractBankField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryContractBank(gUserApi, pContractBank, pRspInfo, nRequestID, bIsLast);
}

// 请求查询预埋单响应
extern "C" void wrap_tts_TraderOnRspQryParkedOrder(uintptr_t, CThostFtdcParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryParkedOrder(gUserApi, pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

// 请求查询预埋撤单响应
extern "C" void wrap_tts_TraderOnRspQryParkedOrderAction(uintptr_t, CThostFtdcParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryParkedOrderAction(gUserApi, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易通知响应
extern "C" void wrap_tts_TraderOnRspQryTradingNotice(uintptr_t, CThostFtdcTradingNoticeField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryTradingNotice(gUserApi, pTradingNotice, pRspInfo, nRequestID, bIsLast);
}

// 请求查询经纪公司交易参数响应
extern "C" void wrap_tts_TraderOnRspQryBrokerTradingParams(uintptr_t, CThostFtdcBrokerTradingParamsField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryBrokerTradingParams(gUserApi, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
}

// 请求查询经纪公司交易算法响应
extern "C" void wrap_tts_TraderOnRspQryBrokerTradingAlgos(uintptr_t, CThostFtdcBrokerTradingAlgosField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryBrokerTradingAlgos(gUserApi, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
}

// 请求查询监控中心用户令牌
extern "C" void wrap_tts_TraderOnRspQueryCFMMCTradingAccountToken(uintptr_t, CThostFtdcQueryCFMMCTradingAccountTokenField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQueryCFMMCTradingAccountToken(gUserApi, pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
}

// 银行发起银行资金转期货通知
extern "C" void wrap_tts_TraderOnRtnFromBankToFutureByBank(uintptr_t, CThostFtdcRspTransferField*);
void TTSCTPTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    wrap_tts_TraderOnRtnFromBankToFutureByBank(gUserApi, pRspTransfer);
}

// 银行发起期货资金转银行通知
extern "C" void wrap_tts_TraderOnRtnFromFutureToBankByBank(uintptr_t, CThostFtdcRspTransferField*);
void TTSCTPTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    wrap_tts_TraderOnRtnFromFutureToBankByBank(gUserApi, pRspTransfer);
}

// 银行发起冲正银行转期货通知
extern "C" void wrap_tts_TraderOnRtnRepealFromBankToFutureByBank(uintptr_t, CThostFtdcRspRepealField*);
void TTSCTPTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    wrap_tts_TraderOnRtnRepealFromBankToFutureByBank(gUserApi, pRspRepeal);
}

// 银行发起冲正期货转银行通知
extern "C" void wrap_tts_TraderOnRtnRepealFromFutureToBankByBank(uintptr_t, CThostFtdcRspRepealField*);
void TTSCTPTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    wrap_tts_TraderOnRtnRepealFromFutureToBankByBank(gUserApi, pRspRepeal);
}

// 期货发起银行资金转期货通知
extern "C" void wrap_tts_TraderOnRtnFromBankToFutureByFuture(uintptr_t, CThostFtdcRspTransferField*);
void TTSCTPTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    wrap_tts_TraderOnRtnFromBankToFutureByFuture(gUserApi, pRspTransfer);
}

// 期货发起期货资金转银行通知
extern "C" void wrap_tts_TraderOnRtnFromFutureToBankByFuture(uintptr_t, CThostFtdcRspTransferField*);
void TTSCTPTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    wrap_tts_TraderOnRtnFromFutureToBankByFuture(gUserApi, pRspTransfer);
}

// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
extern "C" void wrap_tts_TraderOnRtnRepealFromBankToFutureByFutureManual(uintptr_t, CThostFtdcRspRepealField*);
void TTSCTPTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    wrap_tts_TraderOnRtnRepealFromBankToFutureByFutureManual(gUserApi, pRspRepeal);
}

// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
extern "C" void wrap_tts_TraderOnRtnRepealFromFutureToBankByFutureManual(uintptr_t, CThostFtdcRspRepealField*);
void TTSCTPTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    wrap_tts_TraderOnRtnRepealFromFutureToBankByFutureManual(gUserApi, pRspRepeal);
}

// 期货发起查询银行余额通知
extern "C" void wrap_tts_TraderOnRtnQueryBankBalanceByFuture(uintptr_t, CThostFtdcNotifyQueryAccountField*);
void TTSCTPTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
{
    wrap_tts_TraderOnRtnQueryBankBalanceByFuture(gUserApi, pNotifyQueryAccount);
}

// 期货发起银行资金转期货错误回报
extern "C" void wrap_tts_TraderOnErrRtnBankToFutureByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnBankToFutureByFuture(gUserApi, pReqTransfer, pRspInfo);
}

// 期货发起期货资金转银行错误回报
extern "C" void wrap_tts_TraderOnErrRtnFutureToBankByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnFutureToBankByFuture(gUserApi, pReqTransfer, pRspInfo);
}

// 系统运行时期货端手工发起冲正银行转期货错误回报
extern "C" void wrap_tts_TraderOnErrRtnRepealBankToFutureByFutureManual(uintptr_t, CThostFtdcReqRepealField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnRepealBankToFutureByFutureManual(gUserApi, pReqRepeal, pRspInfo);
}

// 系统运行时期货端手工发起冲正期货转银行错误回报
extern "C" void wrap_tts_TraderOnErrRtnRepealFutureToBankByFutureManual(uintptr_t, CThostFtdcReqRepealField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnRepealFutureToBankByFutureManual(gUserApi, pReqRepeal, pRspInfo);
}

// 期货发起查询银行余额错误回报
extern "C" void wrap_tts_TraderOnErrRtnQueryBankBalanceByFuture(uintptr_t, CThostFtdcReqQueryAccountField*, CThostFtdcRspInfoField*);
void TTSCTPTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
{
    wrap_tts_TraderOnErrRtnQueryBankBalanceByFuture(gUserApi, pReqQueryAccount, pRspInfo);
}

// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
extern "C" void wrap_tts_TraderOnRtnRepealFromBankToFutureByFuture(uintptr_t, CThostFtdcRspRepealField*);
void TTSCTPTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    wrap_tts_TraderOnRtnRepealFromBankToFutureByFuture(gUserApi, pRspRepeal);
}

// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
extern "C" void wrap_tts_TraderOnRtnRepealFromFutureToBankByFuture(uintptr_t, CThostFtdcRspRepealField*);
void TTSCTPTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    wrap_tts_TraderOnRtnRepealFromFutureToBankByFuture(gUserApi, pRspRepeal);
}

// 期货发起银行资金转期货应答
extern "C" void wrap_tts_TraderOnRspFromBankToFutureByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspFromBankToFutureByFuture(gUserApi, pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

// 期货发起期货资金转银行应答
extern "C" void wrap_tts_TraderOnRspFromFutureToBankByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspFromFutureToBankByFuture(gUserApi, pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

// 期货发起查询银行余额应答
extern "C" void wrap_tts_TraderOnRspQueryBankAccountMoneyByFuture(uintptr_t, CThostFtdcReqQueryAccountField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQueryBankAccountMoneyByFuture(gUserApi, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
}

// 银行发起银期开户通知
extern "C" void wrap_tts_TraderOnRtnOpenAccountByBank(uintptr_t, CThostFtdcOpenAccountField*);
void TTSCTPTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
{
    wrap_tts_TraderOnRtnOpenAccountByBank(gUserApi, pOpenAccount);
}

// 银行发起银期销户通知
extern "C" void wrap_tts_TraderOnRtnCancelAccountByBank(uintptr_t, CThostFtdcCancelAccountField*);
void TTSCTPTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
{
    wrap_tts_TraderOnRtnCancelAccountByBank(gUserApi, pCancelAccount);
}

// 银行发起变更银行账号通知
extern "C" void wrap_tts_TraderOnRtnChangeAccountByBank(uintptr_t, CThostFtdcChangeAccountField*);
void TTSCTPTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
{
    wrap_tts_TraderOnRtnChangeAccountByBank(gUserApi, pChangeAccount);
}

// 请求查询分类合约响应
extern "C" void wrap_tts_TraderOnRspQryClassifiedInstrument(uintptr_t, CThostFtdcInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryClassifiedInstrument(gUserApi, pInstrument, pRspInfo, nRequestID, bIsLast);
}

// 请求组合优惠比例响应
extern "C" void wrap_tts_TraderOnRspQryCombPromotionParam(uintptr_t, CThostFtdcCombPromotionParamField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryCombPromotionParam(gUserApi, pCombPromotionParam, pRspInfo, nRequestID, bIsLast);
}

// 投资者风险结算持仓查询响应
extern "C" void wrap_tts_TraderOnRspQryRiskSettleInvstPosition(uintptr_t, CThostFtdcRiskSettleInvstPositionField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryRiskSettleInvstPosition(gUserApi, pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast);
}

// 风险结算产品查询响应
extern "C" void wrap_tts_TraderOnRspQryRiskSettleProductStatus(uintptr_t, CThostFtdcRiskSettleProductStatusField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPTraderSpi::OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_TraderOnRspQryRiskSettleProductStatus(gUserApi, pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast);
}

TTSCTPTraderSpi::TTSCTPTraderSpi(CThostFtdcTraderApi* pUserApi)
{
    this->pUserApi = pUserApi;
}

TTSCTPTraderSpi::TTSCTPTraderSpi(CThostFtdcTraderApi* pUserApi, uintptr_t gUserApi)
{
    this->pUserApi = pUserApi;
    this->gUserApi = gUserApi;
}

TTSCTPTraderSpi::TTSCTPTraderSpi(uintptr_t gUserApi, const char* pszDLLPath, const char* pszFlowPath)
{
    typedef CThostFtdcTraderApi* (*TdApiCreator)(const char*);

    dllHandle = dlopen(pszDLLPath, RTLD_NOW);
    if (dllHandle == nullptr) {
        fprintf(stderr, "[%s] dlopen error: %s\n", pszDLLPath, dlerror());
        exit(-1);
    }
    TdApiCreator tdcreator = (TdApiCreator)dlsym(dllHandle, TraderApiCreateSymbol);
    if (tdcreator == nullptr) {
        fprintf(stderr, "[%s] dlsym error: %s\n", pszDLLPath, dlerror());
        exit(-1);
    }
    this->pUserApi = tdcreator(pszFlowPath);
    // this->pUserApi = pUserApi;

    this->gUserApi = gUserApi;
}

TTSCTPTraderSpi::~TTSCTPTraderSpi()
{
    if (this->pUserApi != nullptr) {
        this->pUserApi->RegisterSpi(nullptr);
        this->pUserApi->Release();
        this->pUserApi = nullptr;
        dlclose(dllHandle);
    }
}

// 获取API的版本信息
///@retrun 获取到的版本号
const char*
TTSCTPTraderSpi::GetApiVersion()
{
    typedef const char* (*GetApiVersion)();
    GetApiVersion getVersion = (GetApiVersion)dlsym(this->dllHandle, TraderApiVersionSymbol);
    // return this->pUserApi->GetApiVersion();
    return getVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void TTSCTPTraderSpi::Release()
{
    this->pUserApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void TTSCTPTraderSpi::Init()
{
    this->pUserApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int TTSCTPTraderSpi::Join()
{
    return this->pUserApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* TTSCTPTraderSpi::GetTradingDay()
{
    return this->pUserApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void TTSCTPTraderSpi::RegisterFront(char* pszFrontAddress)
{
    this->pUserApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void TTSCTPTraderSpi::RegisterNameServer(char* pszNsAddress)
{
    this->pUserApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void TTSCTPTraderSpi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
    this->pUserApi->RegisterFensUserInfo(pFensUserInfo);
}

// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void TTSCTPTraderSpi::RegisterSpi(CThostFtdcTraderSpi* pSpi)
{
    this->pUserApi->RegisterSpi(pSpi);
}

// 订阅私有流。
///@param nResumeType 私有流重传方式
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
void TTSCTPTraderSpi::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
{
    this->pUserApi->SubscribePrivateTopic(nResumeType);
}

// 订阅公共流。
///@param nResumeType 公共流重传方式
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后公共流的内容
///        THOST_TERT_NONE:取消订阅公共流
///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
void TTSCTPTraderSpi::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
    this->pUserApi->SubscribePublicTopic(nResumeType);
}

// 客户端认证请求
int TTSCTPTraderSpi::ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
    return this->pUserApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

// 注册用户终端信息，用于中继服务器多连接模式
/// 需要在终端认证成功后，用户登录前调用该接口
int TTSCTPTraderSpi::RegisterUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->RegisterUserSystemInfo(pUserSystemInfo);
}

// 上报用户终端信息，用于中继服务器操作员登录模式
/// 操作员登录后，可以多次调用该接口上报客户信息
int TTSCTPTraderSpi::SubmitUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->SubmitUserSystemInfo(pUserSystemInfo);
}

// 用户登录请求
int TTSCTPTraderSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
#ifdef __APPLE__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
#elif __linux__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
#endif
}

// 用户登录请求
int TTSCTPTraderSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length,
    TThostFtdcClientSystemInfoType systemInfo)
{
#ifdef __APPLE__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
#elif __linux__
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
#endif
}

// 登出请求
int TTSCTPTraderSpi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return this->pUserApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 用户口令更新请求
int TTSCTPTraderSpi::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID)
{
    return this->pUserApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

// 资金账户口令更新请求
int TTSCTPTraderSpi::ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID)
{
    return this->pUserApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

// 查询用户当前支持的认证模式
int TTSCTPTraderSpi::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
    return this->pUserApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

// 用户发出获取图形验证码请求
int TTSCTPTraderSpi::ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID)
{
    return this->pUserApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

// 用户发出获取短信验证码请求
int TTSCTPTraderSpi::ReqGenUserText(CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID)
{
    return this->pUserApi->ReqGenUserText(pReqGenUserText, nRequestID);
}

// 用户发出带有图片验证码的登陆请求
int TTSCTPTraderSpi::ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

// 用户发出带有短信验证码的登陆请求
int TTSCTPTraderSpi::ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

// 用户发出带有动态口令的登陆请求
int TTSCTPTraderSpi::ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

// 报单录入请求
int TTSCTPTraderSpi::ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder, int nRequestID)
{
    return this->pUserApi->ReqOrderInsert(pInputOrder, nRequestID);
}

// 预埋单录入请求
int TTSCTPTraderSpi::ReqParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

// 预埋撤单录入请求
int TTSCTPTraderSpi::ReqParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

// 报单操作请求
int TTSCTPTraderSpi::ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID)
{
    return this->pUserApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

// 查询最大报单数量请求
int TTSCTPTraderSpi::ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
    return this->pUserApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

// 投资者结算结果确认
int TTSCTPTraderSpi::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID)
{
    return this->pUserApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

// 请求删除预埋单
int TTSCTPTraderSpi::ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

// 请求删除预埋撤单
int TTSCTPTraderSpi::ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

// 执行宣告录入请求
int TTSCTPTraderSpi::ReqExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
    return this->pUserApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

// 执行宣告操作请求
int TTSCTPTraderSpi::ReqExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
    return this->pUserApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

// 询价录入请求
int TTSCTPTraderSpi::ReqForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID)
{
    return this->pUserApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

// 报价录入请求
int TTSCTPTraderSpi::ReqQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, int nRequestID)
{
    return this->pUserApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

// 报价操作请求
int TTSCTPTraderSpi::ReqQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID)
{
    return this->pUserApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

// 批量报单操作请求
int TTSCTPTraderSpi::ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID)
{
    return this->pUserApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

// 期权自对冲录入请求
int TTSCTPTraderSpi::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
    return this->pUserApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

// 期权自对冲操作请求
int TTSCTPTraderSpi::ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
    return this->pUserApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

// 申请组合录入请求
int TTSCTPTraderSpi::ReqCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, int nRequestID)
{
    return this->pUserApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

// 请求查询报单
int TTSCTPTraderSpi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder, int nRequestID)
{
    return this->pUserApi->ReqQryOrder(pQryOrder, nRequestID);
}

// 请求查询成交
int TTSCTPTraderSpi::ReqQryTrade(CThostFtdcQryTradeField* pQryTrade, int nRequestID)
{
    return this->pUserApi->ReqQryTrade(pQryTrade, nRequestID);
}

// 请求查询投资者持仓
int TTSCTPTraderSpi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

// 请求查询资金账户
int TTSCTPTraderSpi::ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return this->pUserApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询投资者
int TTSCTPTraderSpi::ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor, int nRequestID)
{
    return this->pUserApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

// 请求查询交易编码
int TTSCTPTraderSpi::ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
    return this->pUserApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

// 请求查询合约保证金率
int TTSCTPTraderSpi::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

// 请求查询合约手续费率
int TTSCTPTraderSpi::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

// 请求查询交易所
int TTSCTPTraderSpi::ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange, int nRequestID)
{
    return this->pUserApi->ReqQryExchange(pQryExchange, nRequestID);
}

// 请求查询产品
int TTSCTPTraderSpi::ReqQryProduct(CThostFtdcQryProductField* pQryProduct, int nRequestID)
{
    return this->pUserApi->ReqQryProduct(pQryProduct, nRequestID);
}

// 请求查询合约
int TTSCTPTraderSpi::ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

// 请求查询行情
int TTSCTPTraderSpi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID)
{
    return this->pUserApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

// 请求查询投资者结算结果
int TTSCTPTraderSpi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID)
{
    return this->pUserApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

// 请求查询转帐银行
int TTSCTPTraderSpi::ReqQryTransferBank(CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID)
{
    return this->pUserApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

// 请求查询投资者持仓明细
int TTSCTPTraderSpi::ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

// 请求查询客户通知
int TTSCTPTraderSpi::ReqQryNotice(CThostFtdcQryNoticeField* pQryNotice, int nRequestID)
{
    return this->pUserApi->ReqQryNotice(pQryNotice, nRequestID);
}

// 请求查询结算信息确认
int TTSCTPTraderSpi::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID)
{
    return this->pUserApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

// 请求查询投资者持仓明细
int TTSCTPTraderSpi::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

// 请求查询保证金监管系统经纪公司资金账户密钥
int TTSCTPTraderSpi::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
    return this->pUserApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

// 请求查询仓单折抵信息
int TTSCTPTraderSpi::ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID)
{
    return this->pUserApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

// 请求查询投资者品种/跨品种保证金
int TTSCTPTraderSpi::ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

// 请求查询交易所保证金率
int TTSCTPTraderSpi::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

// 请求查询交易所调整保证金率
int TTSCTPTraderSpi::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

// 请求查询汇率
int TTSCTPTraderSpi::ReqQryExchangeRate(CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

// 请求查询二级代理操作员银期权限
int TTSCTPTraderSpi::ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

// 请求查询产品报价汇率
int TTSCTPTraderSpi::ReqQryProductExchRate(CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID)
{
    return this->pUserApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

// 请求查询产品组
int TTSCTPTraderSpi::ReqQryProductGroup(CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID)
{
    return this->pUserApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

// 请求查询做市商合约手续费率
int TTSCTPTraderSpi::ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID)
{
    return this->pUserApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

// 请求查询做市商期权合约手续费
int TTSCTPTraderSpi::ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

// 请求查询报单手续费
int TTSCTPTraderSpi::ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

// 请求查询资金账户
int TTSCTPTraderSpi::ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询二级代理商资金校验模式
int TTSCTPTraderSpi::ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

// 请求查询二级代理商信息
int TTSCTPTraderSpi::ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

// 请求查询期权交易成本
int TTSCTPTraderSpi::ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
    return this->pUserApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

// 请求查询期权合约手续费
int TTSCTPTraderSpi::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

// 请求查询执行宣告
int TTSCTPTraderSpi::ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
    return this->pUserApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

// 请求查询询价
int TTSCTPTraderSpi::ReqQryForQuote(CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID)
{
    return this->pUserApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

// 请求查询报价
int TTSCTPTraderSpi::ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
    return this->pUserApi->ReqQryQuote(pQryQuote, nRequestID);
}

// 请求查询期权自对冲
int TTSCTPTraderSpi::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
    return this->pUserApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

// 请求查询投资单元
int TTSCTPTraderSpi::ReqQryInvestUnit(CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
    return this->pUserApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

// 请求查询组合合约安全系数
int TTSCTPTraderSpi::ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
    return this->pUserApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

// 请求查询申请组合
int TTSCTPTraderSpi::ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
    return this->pUserApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

// 请求查询转帐流水
int TTSCTPTraderSpi::ReqQryTransferSerial(CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID)
{
    return this->pUserApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

// 请求查询银期签约关系
int TTSCTPTraderSpi::ReqQryAccountregister(CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID)
{
    return this->pUserApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

// 请求查询签约银行
int TTSCTPTraderSpi::ReqQryContractBank(CThostFtdcQryContractBankField* pQryContractBank, int nRequestID)
{
    return this->pUserApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

// 请求查询预埋单
int TTSCTPTraderSpi::ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

// 请求查询预埋撤单
int TTSCTPTraderSpi::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

// 请求查询交易通知
int TTSCTPTraderSpi::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID)
{
    return this->pUserApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

// 请求查询经纪公司交易参数
int TTSCTPTraderSpi::ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID)
{
    return this->pUserApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

// 请求查询经纪公司交易算法
int TTSCTPTraderSpi::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
    return this->pUserApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

// 请求查询监控中心用户令牌
int TTSCTPTraderSpi::ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
    return this->pUserApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

// 期货发起银行资金转期货请求
int TTSCTPTraderSpi::ReqFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return this->pUserApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

// 期货发起期货资金转银行请求
int TTSCTPTraderSpi::ReqFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return this->pUserApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

// 期货发起查询银行余额请求
int TTSCTPTraderSpi::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
    return this->pUserApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

// 请求查询分类合约
int TTSCTPTraderSpi::ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

// 请求组合优惠比例
int TTSCTPTraderSpi::ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
    return this->pUserApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

// 投资者风险结算持仓查询
int TTSCTPTraderSpi::ReqQryRiskSettleInvstPosition(CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
    return this->pUserApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

// 风险结算产品查询
int TTSCTPTraderSpi::ReqQryRiskSettleProductStatus(CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
    return this->pUserApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}
