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

#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"

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

QCTPTraderSpi* _wrap_CThostFtdcTraderApi_CreateFtdcTraderApi2(uintptr_t gUserApi, const char* pszFlowPath)
{
    // printf("go_user_api %lu\n", gUserApi);
    CThostFtdcTraderApi* pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
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

// 获取API的版本信息
///@retrun 获取到的版本号
const char* _wrap_CThostFtdcTraderApi_GetApiVersion(QCTPTraderSpi* pTraderApi)
{
    return pTraderApi->GetApiVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void _wrap_CThostFtdcTraderApi_Release(QCTPTraderSpi* pTraderApi)
{
    pTraderApi->RegisterSpi(NULL);
    return pTraderApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void _wrap_CThostFtdcTraderApi_Init(QCTPTraderSpi* pTraderApi)
{
    return pTraderApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int _wrap_CThostFtdcTraderApi_Join(QCTPTraderSpi* pTraderApi)
{
    return pTraderApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* _wrap_CThostFtdcTraderApi_GetTradingDay(QCTPTraderSpi* pTraderApi)
{
    return pTraderApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void _wrap_CThostFtdcTraderApi_RegisterFront(QCTPTraderSpi* pTraderApi, char* pszFrontAddress)
{
    return pTraderApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void _wrap_CThostFtdcTraderApi_RegisterNameServer(QCTPTraderSpi* pTraderApi, char* pszNsAddress)
{
    return pTraderApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void _wrap_CThostFtdcTraderApi_RegisterFensUserInfo(QCTPTraderSpi* pTraderApi, CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return pTraderApi->RegisterFensUserInfo(pFensUserInfo);
}

// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void _wrap_CThostFtdcTraderApi_RegisterSpi(QCTPTraderSpi* pTraderApi, CThostFtdcTraderSpi* pSpi)
{
    // return pTraderApi->RegisterSpi(pSpi);
}

// 订阅私有流。
///@param nResumeType 私有流重传方式
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
void _wrap_CThostFtdcTraderApi_SubscribePrivateTopic(QCTPTraderSpi* pTraderApi, enum THOST_TE_RESUME_TYPE nResumeType)
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
void _wrap_CThostFtdcTraderApi_SubscribePublicTopic(QCTPTraderSpi* pTraderApi, enum THOST_TE_RESUME_TYPE nResumeType)
{
    return pTraderApi->SubscribePublicTopic(nResumeType);
}

// 客户端认证请求
int _wrap_CThostFtdcTraderApi_ReqAuthenticate(QCTPTraderSpi* pTraderApi, CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
    return pTraderApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

// 注册用户终端信息，用于中继服务器多连接模式
/// 需要在终端认证成功后，用户登录前调用该接口
int _wrap_CThostFtdcTraderApi_RegisterUserSystemInfo(QCTPTraderSpi* pTraderApi, CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return pTraderApi->RegisterUserSystemInfo(pUserSystemInfo);
}

// 上报用户终端信息，用于中继服务器操作员登录模式
/// 操作员登录后，可以多次调用该接口上报客户信息
int _wrap_CThostFtdcTraderApi_SubmitUserSystemInfo(QCTPTraderSpi* pTraderApi, CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return pTraderApi->SubmitUserSystemInfo(pUserSystemInfo);
}

// 用户登录请求
int _wrap_CThostFtdcTraderApi_ReqUserLogin(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return pTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

// Mac 用户登录请求
int _wrap_CThostFtdcTraderApi_ReqUserLoginMac(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length,
    TThostFtdcClientSystemInfoType systemInfo)
{
    return pTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID, length, systemInfo);
}

// 登出请求
int _wrap_CThostFtdcTraderApi_ReqUserLogout(QCTPTraderSpi* pTraderApi, CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return pTraderApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 用户口令更新请求
int _wrap_CThostFtdcTraderApi_ReqUserPasswordUpdate(QCTPTraderSpi* pTraderApi, CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID)
{
    return pTraderApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

// 资金账户口令更新请求
int _wrap_CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(QCTPTraderSpi* pTraderApi, CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID)
{
    return pTraderApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

// 查询用户当前支持的认证模式
int _wrap_CThostFtdcTraderApi_ReqUserAuthMethod(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
    return pTraderApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

// 用户发出获取图形验证码请求
int _wrap_CThostFtdcTraderApi_ReqGenUserCaptcha(QCTPTraderSpi* pTraderApi, CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID)
{
    return pTraderApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

// 用户发出获取短信验证码请求
int _wrap_CThostFtdcTraderApi_ReqGenUserText(QCTPTraderSpi* pTraderApi, CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID)
{
    return pTraderApi->ReqGenUserText(pReqGenUserText, nRequestID);
}

// 用户发出带有图片验证码的登陆请求
int _wrap_CThostFtdcTraderApi_ReqUserLoginWithCaptcha(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID)
{
    return pTraderApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

// 用户发出带有短信验证码的登陆请求
int _wrap_CThostFtdcTraderApi_ReqUserLoginWithText(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID)
{
    return pTraderApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

// 用户发出带有动态口令的登陆请求
int _wrap_CThostFtdcTraderApi_ReqUserLoginWithOTP(QCTPTraderSpi* pTraderApi, CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID)
{
    return pTraderApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

// 报单录入请求
int _wrap_CThostFtdcTraderApi_ReqOrderInsert(QCTPTraderSpi* pTraderApi, CThostFtdcInputOrderField* pInputOrder, int nRequestID)
{
    return pTraderApi->ReqOrderInsert(pInputOrder, nRequestID);
}

// 预埋单录入请求
int _wrap_CThostFtdcTraderApi_ReqParkedOrderInsert(QCTPTraderSpi* pTraderApi, CThostFtdcParkedOrderField* pParkedOrder, int nRequestID)
{
    return pTraderApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

// 预埋撤单录入请求
int _wrap_CThostFtdcTraderApi_ReqParkedOrderAction(QCTPTraderSpi* pTraderApi, CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID)
{
    return pTraderApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

// 报单操作请求
int _wrap_CThostFtdcTraderApi_ReqOrderAction(QCTPTraderSpi* pTraderApi, CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID)
{
    return pTraderApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

// 查询最大报单数量请求
int _wrap_CThostFtdcTraderApi_ReqQryMaxOrderVolume(QCTPTraderSpi* pTraderApi, CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
    return pTraderApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

// 投资者结算结果确认
int _wrap_CThostFtdcTraderApi_ReqSettlementInfoConfirm(QCTPTraderSpi* pTraderApi, CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID)
{
    return pTraderApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

// 请求删除预埋单
int _wrap_CThostFtdcTraderApi_ReqRemoveParkedOrder(QCTPTraderSpi* pTraderApi, CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID)
{
    return pTraderApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

// 请求删除预埋撤单
int _wrap_CThostFtdcTraderApi_ReqRemoveParkedOrderAction(QCTPTraderSpi* pTraderApi, CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID)
{
    return pTraderApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

// 执行宣告录入请求
int _wrap_CThostFtdcTraderApi_ReqExecOrderInsert(QCTPTraderSpi* pTraderApi, CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
    return pTraderApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

// 执行宣告操作请求
int _wrap_CThostFtdcTraderApi_ReqExecOrderAction(QCTPTraderSpi* pTraderApi, CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
    return pTraderApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

// 询价录入请求
int _wrap_CThostFtdcTraderApi_ReqForQuoteInsert(QCTPTraderSpi* pTraderApi, CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID)
{
    return pTraderApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

// 报价录入请求
int _wrap_CThostFtdcTraderApi_ReqQuoteInsert(QCTPTraderSpi* pTraderApi, CThostFtdcInputQuoteField* pInputQuote, int nRequestID)
{
    return pTraderApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

// 报价操作请求
int _wrap_CThostFtdcTraderApi_ReqQuoteAction(QCTPTraderSpi* pTraderApi, CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID)
{
    return pTraderApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

// 批量报单操作请求
int _wrap_CThostFtdcTraderApi_ReqBatchOrderAction(QCTPTraderSpi* pTraderApi, CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID)
{
    return pTraderApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

// 期权自对冲录入请求
int _wrap_CThostFtdcTraderApi_ReqOptionSelfCloseInsert(QCTPTraderSpi* pTraderApi, CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
    return pTraderApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

// 期权自对冲操作请求
int _wrap_CThostFtdcTraderApi_ReqOptionSelfCloseAction(QCTPTraderSpi* pTraderApi, CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
    return pTraderApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

// 申请组合录入请求
int _wrap_CThostFtdcTraderApi_ReqCombActionInsert(QCTPTraderSpi* pTraderApi, CThostFtdcInputCombActionField* pInputCombAction, int nRequestID)
{
    return pTraderApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

// 请求查询报单
int _wrap_CThostFtdcTraderApi_ReqQryOrder(QCTPTraderSpi* pTraderApi, CThostFtdcQryOrderField* pQryOrder, int nRequestID)
{
    return pTraderApi->ReqQryOrder(pQryOrder, nRequestID);
}

// 请求查询成交
int _wrap_CThostFtdcTraderApi_ReqQryTrade(QCTPTraderSpi* pTraderApi, CThostFtdcQryTradeField* pQryTrade, int nRequestID)
{
    return pTraderApi->ReqQryTrade(pQryTrade, nRequestID);
}

// 请求查询投资者持仓
int _wrap_CThostFtdcTraderApi_ReqQryInvestorPosition(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

// 请求查询资金账户
int _wrap_CThostFtdcTraderApi_ReqQryTradingAccount(QCTPTraderSpi* pTraderApi, CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return pTraderApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询投资者
int _wrap_CThostFtdcTraderApi_ReqQryInvestor(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorField* pQryInvestor, int nRequestID)
{
    return pTraderApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

// 请求查询交易编码
int _wrap_CThostFtdcTraderApi_ReqQryTradingCode(QCTPTraderSpi* pTraderApi, CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
    return pTraderApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

// 请求查询合约保证金率
int _wrap_CThostFtdcTraderApi_ReqQryInstrumentMarginRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID)
{
    return pTraderApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

// 请求查询合约手续费率
int _wrap_CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID)
{
    return pTraderApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

// 请求查询交易所
int _wrap_CThostFtdcTraderApi_ReqQryExchange(QCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeField* pQryExchange, int nRequestID)
{
    return pTraderApi->ReqQryExchange(pQryExchange, nRequestID);
}

// 请求查询产品
int _wrap_CThostFtdcTraderApi_ReqQryProduct(QCTPTraderSpi* pTraderApi, CThostFtdcQryProductField* pQryProduct, int nRequestID)
{
    return pTraderApi->ReqQryProduct(pQryProduct, nRequestID);
}

// 请求查询合约
int _wrap_CThostFtdcTraderApi_ReqQryInstrument(QCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID)
{
    return pTraderApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

// 请求查询行情
int _wrap_CThostFtdcTraderApi_ReqQryDepthMarketData(QCTPTraderSpi* pTraderApi, CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID)
{
    return pTraderApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

// 请求查询投资者结算结果
int _wrap_CThostFtdcTraderApi_ReqQrySettlementInfo(QCTPTraderSpi* pTraderApi, CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID)
{
    return pTraderApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

// 请求查询转帐银行
int _wrap_CThostFtdcTraderApi_ReqQryTransferBank(QCTPTraderSpi* pTraderApi, CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID)
{
    return pTraderApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

// 请求查询投资者持仓明细
int _wrap_CThostFtdcTraderApi_ReqQryInvestorPositionDetail(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

// 请求查询客户通知
int _wrap_CThostFtdcTraderApi_ReqQryNotice(QCTPTraderSpi* pTraderApi, CThostFtdcQryNoticeField* pQryNotice, int nRequestID)
{
    return pTraderApi->ReqQryNotice(pQryNotice, nRequestID);
}

// 请求查询结算信息确认
int _wrap_CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(QCTPTraderSpi* pTraderApi, CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID)
{
    return pTraderApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

// 请求查询投资者持仓明细
int _wrap_CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

// 请求查询保证金监管系统经纪公司资金账户密钥
int _wrap_CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(QCTPTraderSpi* pTraderApi, CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
    return pTraderApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

// 请求查询仓单折抵信息
int _wrap_CThostFtdcTraderApi_ReqQryEWarrantOffset(QCTPTraderSpi* pTraderApi, CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID)
{
    return pTraderApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

// 请求查询投资者品种/跨品种保证金
int _wrap_CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID)
{
    return pTraderApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

// 请求查询交易所保证金率
int _wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
    return pTraderApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

// 请求查询交易所调整保证金率
int _wrap_CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(QCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID)
{
    return pTraderApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

// 请求查询汇率
int _wrap_CThostFtdcTraderApi_ReqQryExchangeRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID)
{
    return pTraderApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

// 请求查询二级代理操作员银期权限
int _wrap_CThostFtdcTraderApi_ReqQrySecAgentACIDMap(QCTPTraderSpi* pTraderApi, CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

// 请求查询产品报价汇率
int _wrap_CThostFtdcTraderApi_ReqQryProductExchRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID)
{
    return pTraderApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

// 请求查询产品组
int _wrap_CThostFtdcTraderApi_ReqQryProductGroup(QCTPTraderSpi* pTraderApi, CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID)
{
    return pTraderApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

// 请求查询做市商合约手续费率
int _wrap_CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID)
{
    return pTraderApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

// 请求查询做市商期权合约手续费
int _wrap_CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID)
{
    return pTraderApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

// 请求查询报单手续费
int _wrap_CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
    return pTraderApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

// 请求查询资金账户
int _wrap_CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(QCTPTraderSpi* pTraderApi, CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询二级代理商资金校验模式
int _wrap_CThostFtdcTraderApi_ReqQrySecAgentCheckMode(QCTPTraderSpi* pTraderApi, CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

// 请求查询二级代理商信息
int _wrap_CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(QCTPTraderSpi* pTraderApi, CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
    return pTraderApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

// 请求查询期权交易成本
int _wrap_CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(QCTPTraderSpi* pTraderApi, CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
    return pTraderApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

// 请求查询期权合约手续费
int _wrap_CThostFtdcTraderApi_ReqQryOptionInstrCommRate(QCTPTraderSpi* pTraderApi, CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
    return pTraderApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

// 请求查询执行宣告
int _wrap_CThostFtdcTraderApi_ReqQryExecOrder(QCTPTraderSpi* pTraderApi, CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
    return pTraderApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

// 请求查询询价
int _wrap_CThostFtdcTraderApi_ReqQryForQuote(QCTPTraderSpi* pTraderApi, CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID)
{
    return pTraderApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

// 请求查询报价
int _wrap_CThostFtdcTraderApi_ReqQryQuote(QCTPTraderSpi* pTraderApi, CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
    return pTraderApi->ReqQryQuote(pQryQuote, nRequestID);
}

// 请求查询期权自对冲
int _wrap_CThostFtdcTraderApi_ReqQryOptionSelfClose(QCTPTraderSpi* pTraderApi, CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
    return pTraderApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

// 请求查询投资单元
int _wrap_CThostFtdcTraderApi_ReqQryInvestUnit(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
    return pTraderApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

// 请求查询组合合约安全系数
int _wrap_CThostFtdcTraderApi_ReqQryCombInstrumentGuard(QCTPTraderSpi* pTraderApi, CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
    return pTraderApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

// 请求查询申请组合
int _wrap_CThostFtdcTraderApi_ReqQryCombAction(QCTPTraderSpi* pTraderApi, CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
    return pTraderApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

// 请求查询转帐流水
int _wrap_CThostFtdcTraderApi_ReqQryTransferSerial(QCTPTraderSpi* pTraderApi, CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID)
{
    return pTraderApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

// 请求查询银期签约关系
int _wrap_CThostFtdcTraderApi_ReqQryAccountregister(QCTPTraderSpi* pTraderApi, CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID)
{
    return pTraderApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

// 请求查询签约银行
int _wrap_CThostFtdcTraderApi_ReqQryContractBank(QCTPTraderSpi* pTraderApi, CThostFtdcQryContractBankField* pQryContractBank, int nRequestID)
{
    return pTraderApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

// 请求查询预埋单
int _wrap_CThostFtdcTraderApi_ReqQryParkedOrder(QCTPTraderSpi* pTraderApi, CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
    return pTraderApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

// 请求查询预埋撤单
int _wrap_CThostFtdcTraderApi_ReqQryParkedOrderAction(QCTPTraderSpi* pTraderApi, CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
    return pTraderApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

// 请求查询交易通知
int _wrap_CThostFtdcTraderApi_ReqQryTradingNotice(QCTPTraderSpi* pTraderApi, CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID)
{
    return pTraderApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

// 请求查询经纪公司交易参数
int _wrap_CThostFtdcTraderApi_ReqQryBrokerTradingParams(QCTPTraderSpi* pTraderApi, CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID)
{
    return pTraderApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

// 请求查询经纪公司交易算法
int _wrap_CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(QCTPTraderSpi* pTraderApi, CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
    return pTraderApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

// 请求查询监控中心用户令牌
int _wrap_CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(QCTPTraderSpi* pTraderApi, CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
    return pTraderApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

// 期货发起银行资金转期货请求
int _wrap_CThostFtdcTraderApi_ReqFromBankToFutureByFuture(QCTPTraderSpi* pTraderApi, CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return pTraderApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

// 期货发起期货资金转银行请求
int _wrap_CThostFtdcTraderApi_ReqFromFutureToBankByFuture(QCTPTraderSpi* pTraderApi, CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return pTraderApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

// 期货发起查询银行余额请求
int _wrap_CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(QCTPTraderSpi* pTraderApi, CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
    return pTraderApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

// 请求查询分类合约
int _wrap_CThostFtdcTraderApi_ReqQryClassifiedInstrument(QCTPTraderSpi* pTraderApi, CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
    return pTraderApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

// 请求组合优惠比例
int _wrap_CThostFtdcTraderApi_ReqQryCombPromotionParam(QCTPTraderSpi* pTraderApi, CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
    return pTraderApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

// 投资者风险结算持仓查询
int _wrap_CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(QCTPTraderSpi* pTraderApi, CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
    return pTraderApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

// 风险结算产品查询
int _wrap_CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(QCTPTraderSpi* pTraderApi, CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
    return pTraderApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}

// SPBM期货合约参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMFutureParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID)
{
    return pTraderApi->ReqQrySPBMFutureParameter(pQrySPBMFutureParameter, nRequestID);
}

// SPBM期权合约参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMOptionParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID)
{
    return pTraderApi->ReqQrySPBMOptionParameter(pQrySPBMOptionParameter, nRequestID);
}

// SPBM品种内对锁仓折扣参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMIntraParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID)
{
    return pTraderApi->ReqQrySPBMIntraParameter(pQrySPBMIntraParameter, nRequestID);
}

// SPBM跨品种抵扣参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMInterParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID)
{
    return pTraderApi->ReqQrySPBMInterParameter(pQrySPBMInterParameter, nRequestID);
}

// SPBM组合保证金套餐查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMPortfDefinition(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID)
{
    return pTraderApi->ReqQrySPBMPortfDefinition(pQrySPBMPortfDefinition, nRequestID);
}

// 投资者SPBM套餐选择查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMInvestorPortfDef(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID)
{
    return pTraderApi->ReqQrySPBMInvestorPortfDef(pQrySPBMInvestorPortfDef, nRequestID);
}

// 投资者新型组合保证金系数查询
int _wrap_CThostFtdcTraderApi_ReqQryInvestorPortfMarginRatio(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID)
{
    return pTraderApi->ReqQryInvestorPortfMarginRatio(pQryInvestorPortfMarginRatio, nRequestID);
}

// 投资者产品SPBM明细查询
int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdSPBMDetail(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID)
{
    return pTraderApi->ReqQryInvestorProdSPBMDetail(pQryInvestorProdSPBMDetail, nRequestID);
}

// 投资者商品组SPMM记录查询
int _wrap_CThostFtdcTraderApi_ReqQryInvestorCommoditySPMMMargin(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorCommoditySPMMMarginField* pQryInvestorCommoditySPMMMargin, int nRequestID)
{
    return pTraderApi->ReqQryInvestorCommoditySPMMMargin(pQryInvestorCommoditySPMMMargin, nRequestID);
}

// 投资者商品群SPMM记录查询
int _wrap_CThostFtdcTraderApi_ReqQryInvestorCommodityGroupSPMMMargin(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorCommodityGroupSPMMMarginField* pQryInvestorCommodityGroupSPMMMargin, int nRequestID)
{
    return pTraderApi->ReqQryInvestorCommodityGroupSPMMMargin(pQryInvestorCommodityGroupSPMMMargin, nRequestID);
}

// SPMM合约参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPMMInstParam(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPMMInstParamField* pQrySPMMInstParam, int nRequestID)
{
    return pTraderApi->ReqQrySPMMInstParam(pQrySPMMInstParam, nRequestID);
}

// SPMM产品参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPMMProductParam(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPMMProductParamField* pQrySPMMProductParam, int nRequestID)
{
    return pTraderApi->ReqQrySPMMProductParam(pQrySPMMProductParam, nRequestID);
}

// SPBM附加跨品种抵扣参数查询
int _wrap_CThostFtdcTraderApi_ReqQrySPBMAddOnInterParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQrySPBMAddOnInterParameterField* pQrySPBMAddOnInterParameter, int nRequestID)
{
    return pTraderApi->ReqQrySPBMAddOnInterParameter(pQrySPBMAddOnInterParameter, nRequestID);
}

// RCAMS产品组合信息查询
int _wrap_CThostFtdcTraderApi_ReqQryRCAMSCombProductInfo(QCTPTraderSpi* pTraderApi, CThostFtdcQryRCAMSCombProductInfoField* pQryRCAMSCombProductInfo, int nRequestID)
{
    return pTraderApi->ReqQryRCAMSCombProductInfo(pQryRCAMSCombProductInfo, nRequestID);
}

// RCAMS同合约风险对冲参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInstrParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQryRCAMSInstrParameterField* pQryRCAMSInstrParameter, int nRequestID)
{
    return pTraderApi->ReqQryRCAMSInstrParameter(pQryRCAMSInstrParameter, nRequestID);
}

// RCAMS品种内风险对冲参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRCAMSIntraParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQryRCAMSIntraParameterField* pQryRCAMSIntraParameter, int nRequestID)
{
    return pTraderApi->ReqQryRCAMSIntraParameter(pQryRCAMSIntraParameter, nRequestID);
}

// RCAMS跨品种风险折抵参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInterParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQryRCAMSInterParameterField* pQryRCAMSInterParameter, int nRequestID)
{
    return pTraderApi->ReqQryRCAMSInterParameter(pQryRCAMSInterParameter, nRequestID);
}

// RCAMS空头期权风险调整参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRCAMSShortOptAdjustParam(QCTPTraderSpi* pTraderApi, CThostFtdcQryRCAMSShortOptAdjustParamField* pQryRCAMSShortOptAdjustParam, int nRequestID)
{
    return pTraderApi->ReqQryRCAMSShortOptAdjustParam(pQryRCAMSShortOptAdjustParam, nRequestID);
}

// RCAMS策略组合持仓查询
int _wrap_CThostFtdcTraderApi_ReqQryRCAMSInvestorCombPosition(QCTPTraderSpi* pTraderApi, CThostFtdcQryRCAMSInvestorCombPositionField* pQryRCAMSInvestorCombPosition, int nRequestID)
{
    return pTraderApi->ReqQryRCAMSInvestorCombPosition(pQryRCAMSInvestorCombPosition, nRequestID);
}

// 投资者品种RCAMS保证金查询
int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdRCAMSMargin(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorProdRCAMSMarginField* pQryInvestorProdRCAMSMargin, int nRequestID)
{
    return pTraderApi->ReqQryInvestorProdRCAMSMargin(pQryInvestorProdRCAMSMargin, nRequestID);
}

// RULE合约保证金参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRULEInstrParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQryRULEInstrParameterField* pQryRULEInstrParameter, int nRequestID)
{
    return pTraderApi->ReqQryRULEInstrParameter(pQryRULEInstrParameter, nRequestID);
}

// RULE品种内对锁仓折扣参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRULEIntraParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQryRULEIntraParameterField* pQryRULEIntraParameter, int nRequestID)
{
    return pTraderApi->ReqQryRULEIntraParameter(pQryRULEIntraParameter, nRequestID);
}

// RULE跨品种抵扣参数查询
int _wrap_CThostFtdcTraderApi_ReqQryRULEInterParameter(QCTPTraderSpi* pTraderApi, CThostFtdcQryRULEInterParameterField* pQryRULEInterParameter, int nRequestID)
{
    return pTraderApi->ReqQryRULEInterParameter(pQryRULEInterParameter, nRequestID);
}

// 投资者产品RULE保证金查询
int _wrap_CThostFtdcTraderApi_ReqQryInvestorProdRULEMargin(QCTPTraderSpi* pTraderApi, CThostFtdcQryInvestorProdRULEMarginField* pQryInvestorProdRULEMargin, int nRequestID)
{
    return pTraderApi->ReqQryInvestorProdRULEMargin(pQryInvestorProdRULEMargin, nRequestID);
}

#ifdef __cplusplus
}
#endif

// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
extern "C" void wrapTraderOnFrontConnected(uintptr_t);
void QCTPTraderSpi::OnFrontConnected()
{
    wrapTraderOnFrontConnected(gUserApi);
}

// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
extern "C" void wrapTraderOnFrontDisconnected(uintptr_t, int);
void QCTPTraderSpi::OnFrontDisconnected(int nReason)
{
    wrapTraderOnFrontDisconnected(gUserApi, nReason);
}

// 心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
extern "C" void wrapTraderOnHeartBeatWarning(uintptr_t, int);
void QCTPTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
    wrapTraderOnHeartBeatWarning(gUserApi, nTimeLapse);
}

// 客户端认证响应
extern "C" void wrapTraderOnRspAuthenticate(uintptr_t, CThostFtdcRspAuthenticateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspAuthenticate(gUserApi, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
}

// 登录请求响应
extern "C" void wrapTraderOnRspUserLogin(uintptr_t, CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserLogin(gUserApi, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

// 登出请求响应
extern "C" void wrapTraderOnRspUserLogout(uintptr_t, CThostFtdcUserLogoutField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserLogout(gUserApi, pUserLogout, pRspInfo, nRequestID, bIsLast);
}

// 用户口令更新请求响应
extern "C" void wrapTraderOnRspUserPasswordUpdate(uintptr_t, CThostFtdcUserPasswordUpdateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserPasswordUpdate(gUserApi, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

// 资金账户口令更新请求响应
extern "C" void wrapTraderOnRspTradingAccountPasswordUpdate(uintptr_t, CThostFtdcTradingAccountPasswordUpdateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspTradingAccountPasswordUpdate(gUserApi, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

// 查询用户当前支持的认证模式的回复
extern "C" void wrapTraderOnRspUserAuthMethod(uintptr_t, CThostFtdcRspUserAuthMethodField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspUserAuthMethod(gUserApi, pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast);
}

// 获取图形验证码请求的回复
extern "C" void wrapTraderOnRspGenUserCaptcha(uintptr_t, CThostFtdcRspGenUserCaptchaField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspGenUserCaptcha(gUserApi, pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast);
}

// 获取短信验证码请求的回复
extern "C" void wrapTraderOnRspGenUserText(uintptr_t, CThostFtdcRspGenUserTextField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspGenUserText(gUserApi, pRspGenUserText, pRspInfo, nRequestID, bIsLast);
}

// 报单录入请求响应
extern "C" void wrapTraderOnRspOrderInsert(uintptr_t, CThostFtdcInputOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOrderInsert(gUserApi, pInputOrder, pRspInfo, nRequestID, bIsLast);
}

// 预埋单录入请求响应
extern "C" void wrapTraderOnRspParkedOrderInsert(uintptr_t, CThostFtdcParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspParkedOrderInsert(gUserApi, pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

// 预埋撤单录入请求响应
extern "C" void wrapTraderOnRspParkedOrderAction(uintptr_t, CThostFtdcParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspParkedOrderAction(gUserApi, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 报单操作请求响应
extern "C" void wrapTraderOnRspOrderAction(uintptr_t, CThostFtdcInputOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOrderAction(gUserApi, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 查询最大报单数量响应
extern "C" void wrapTraderOnRspQryMaxOrderVolume(uintptr_t, CThostFtdcQryMaxOrderVolumeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryMaxOrderVolume(gUserApi, pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
}

// 投资者结算结果确认响应
extern "C" void wrapTraderOnRspSettlementInfoConfirm(uintptr_t, CThostFtdcSettlementInfoConfirmField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspSettlementInfoConfirm(gUserApi, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

// 删除预埋单响应
extern "C" void wrapTraderOnRspRemoveParkedOrder(uintptr_t, CThostFtdcRemoveParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspRemoveParkedOrder(gUserApi, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
}

// 删除预埋撤单响应
extern "C" void wrapTraderOnRspRemoveParkedOrderAction(uintptr_t, CThostFtdcRemoveParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspRemoveParkedOrderAction(gUserApi, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 执行宣告录入请求响应
extern "C" void wrapTraderOnRspExecOrderInsert(uintptr_t, CThostFtdcInputExecOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspExecOrderInsert(gUserApi, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
}

// 执行宣告操作请求响应
extern "C" void wrapTraderOnRspExecOrderAction(uintptr_t, CThostFtdcInputExecOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspExecOrderAction(gUserApi, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 询价录入请求响应
extern "C" void wrapTraderOnRspForQuoteInsert(uintptr_t, CThostFtdcInputForQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspForQuoteInsert(gUserApi, pInputForQuote, pRspInfo, nRequestID, bIsLast);
}

// 报价录入请求响应
extern "C" void wrapTraderOnRspQuoteInsert(uintptr_t, CThostFtdcInputQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQuoteInsert(gUserApi, pInputQuote, pRspInfo, nRequestID, bIsLast);
}

// 报价操作请求响应
extern "C" void wrapTraderOnRspQuoteAction(uintptr_t, CThostFtdcInputQuoteActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQuoteAction(gUserApi, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
}

// 批量报单操作请求响应
extern "C" void wrapTraderOnRspBatchOrderAction(uintptr_t, CThostFtdcInputBatchOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspBatchOrderAction(gUserApi, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 期权自对冲录入请求响应
extern "C" void wrapTraderOnRspOptionSelfCloseInsert(uintptr_t, CThostFtdcInputOptionSelfCloseField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOptionSelfCloseInsert(gUserApi, pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
}

// 期权自对冲操作请求响应
extern "C" void wrapTraderOnRspOptionSelfCloseAction(uintptr_t, CThostFtdcInputOptionSelfCloseActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspOptionSelfCloseAction(gUserApi, pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
}

// 申请组合录入请求响应
extern "C" void wrapTraderOnRspCombActionInsert(uintptr_t, CThostFtdcInputCombActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspCombActionInsert(gUserApi, pInputCombAction, pRspInfo, nRequestID, bIsLast);
}

// 请求查询报单响应
extern "C" void wrapTraderOnRspQryOrder(uintptr_t, CThostFtdcOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOrder(gUserApi, pOrder, pRspInfo, nRequestID, bIsLast);
}

// 请求查询成交响应
extern "C" void wrapTraderOnRspQryTrade(uintptr_t, CThostFtdcTradeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTrade(gUserApi, pTrade, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者持仓响应
extern "C" void wrapTraderOnRspQryInvestorPosition(uintptr_t, CThostFtdcInvestorPositionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPosition(gUserApi, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
}

// 请求查询资金账户响应
extern "C" void wrapTraderOnRspQryTradingAccount(uintptr_t, CThostFtdcTradingAccountField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTradingAccount(gUserApi, pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者响应
extern "C" void wrapTraderOnRspQryInvestor(uintptr_t, CThostFtdcInvestorField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestor(gUserApi, pInvestor, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易编码响应
extern "C" void wrapTraderOnRspQryTradingCode(uintptr_t, CThostFtdcTradingCodeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTradingCode(gUserApi, pTradingCode, pRspInfo, nRequestID, bIsLast);
}

// 请求查询合约保证金率响应
extern "C" void wrapTraderOnRspQryInstrumentMarginRate(uintptr_t, CThostFtdcInstrumentMarginRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrumentMarginRate(gUserApi, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询合约手续费率响应
extern "C" void wrapTraderOnRspQryInstrumentCommissionRate(uintptr_t, CThostFtdcInstrumentCommissionRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrumentCommissionRate(gUserApi, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易所响应
extern "C" void wrapTraderOnRspQryExchange(uintptr_t, CThostFtdcExchangeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchange(gUserApi, pExchange, pRspInfo, nRequestID, bIsLast);
}

// 请求查询产品响应
extern "C" void wrapTraderOnRspQryProduct(uintptr_t, CThostFtdcProductField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryProduct(gUserApi, pProduct, pRspInfo, nRequestID, bIsLast);
}

// 请求查询合约响应
extern "C" void wrapTraderOnRspQryInstrument(uintptr_t, CThostFtdcInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrument(gUserApi, pInstrument, pRspInfo, nRequestID, bIsLast);
}

// 请求查询行情响应
extern "C" void wrapTraderOnRspQryDepthMarketData(uintptr_t, CThostFtdcDepthMarketDataField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryDepthMarketData(gUserApi, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者结算结果响应
extern "C" void wrapTraderOnRspQrySettlementInfo(uintptr_t, CThostFtdcSettlementInfoField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySettlementInfo(gUserApi, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
}

// 请求查询转帐银行响应
extern "C" void wrapTraderOnRspQryTransferBank(uintptr_t, CThostFtdcTransferBankField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTransferBank(gUserApi, pTransferBank, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者持仓明细响应
extern "C" void wrapTraderOnRspQryInvestorPositionDetail(uintptr_t, CThostFtdcInvestorPositionDetailField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPositionDetail(gUserApi, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
}

// 请求查询客户通知响应
extern "C" void wrapTraderOnRspQryNotice(uintptr_t, CThostFtdcNoticeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryNotice(gUserApi, pNotice, pRspInfo, nRequestID, bIsLast);
}

// 请求查询结算信息确认响应
extern "C" void wrapTraderOnRspQrySettlementInfoConfirm(uintptr_t, CThostFtdcSettlementInfoConfirmField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySettlementInfoConfirm(gUserApi, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者持仓明细响应
extern "C" void wrapTraderOnRspQryInvestorPositionCombineDetail(uintptr_t, CThostFtdcInvestorPositionCombineDetailField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPositionCombineDetail(gUserApi, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
}

// 查询保证金监管系统经纪公司资金账户密钥响应
extern "C" void wrapTraderOnRspQryCFMMCTradingAccountKey(uintptr_t, CThostFtdcCFMMCTradingAccountKeyField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCFMMCTradingAccountKey(gUserApi, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
}

// 请求查询仓单折抵信息响应
extern "C" void wrapTraderOnRspQryEWarrantOffset(uintptr_t, CThostFtdcEWarrantOffsetField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryEWarrantOffset(gUserApi, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资者品种/跨品种保证金响应
extern "C" void wrapTraderOnRspQryInvestorProductGroupMargin(uintptr_t, CThostFtdcInvestorProductGroupMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProductGroupMargin(gUserApi, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易所保证金率响应
extern "C" void wrapTraderOnRspQryExchangeMarginRate(uintptr_t, CThostFtdcExchangeMarginRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchangeMarginRate(gUserApi, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易所调整保证金率响应
extern "C" void wrapTraderOnRspQryExchangeMarginRateAdjust(uintptr_t, CThostFtdcExchangeMarginRateAdjustField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchangeMarginRateAdjust(gUserApi, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
}

// 请求查询汇率响应
extern "C" void wrapTraderOnRspQryExchangeRate(uintptr_t, CThostFtdcExchangeRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExchangeRate(gUserApi, pExchangeRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询二级代理操作员银期权限响应
extern "C" void wrapTraderOnRspQrySecAgentACIDMap(uintptr_t, CThostFtdcSecAgentACIDMapField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentACIDMap(gUserApi, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
}

// 请求查询产品报价汇率
extern "C" void wrapTraderOnRspQryProductExchRate(uintptr_t, CThostFtdcProductExchRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryProductExchRate(gUserApi, pProductExchRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询产品组
extern "C" void wrapTraderOnRspQryProductGroup(uintptr_t, CThostFtdcProductGroupField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryProductGroup(gUserApi, pProductGroup, pRspInfo, nRequestID, bIsLast);
}

// 请求查询做市商合约手续费率响应
extern "C" void wrapTraderOnRspQryMMInstrumentCommissionRate(uintptr_t, CThostFtdcMMInstrumentCommissionRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryMMInstrumentCommissionRate(gUserApi, pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询做市商期权合约手续费响应
extern "C" void wrapTraderOnRspQryMMOptionInstrCommRate(uintptr_t, CThostFtdcMMOptionInstrCommRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryMMOptionInstrCommRate(gUserApi, pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询报单手续费响应
extern "C" void wrapTraderOnRspQryInstrumentOrderCommRate(uintptr_t, CThostFtdcInstrumentOrderCommRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInstrumentOrderCommRate(gUserApi, pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询资金账户响应
extern "C" void wrapTraderOnRspQrySecAgentTradingAccount(uintptr_t, CThostFtdcTradingAccountField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentTradingAccount(gUserApi, pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

// 请求查询二级代理商资金校验模式响应
extern "C" void wrapTraderOnRspQrySecAgentCheckMode(uintptr_t, CThostFtdcSecAgentCheckModeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentCheckMode(gUserApi, pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast);
}

// 请求查询二级代理商信息响应
extern "C" void wrapTraderOnRspQrySecAgentTradeInfo(uintptr_t, CThostFtdcSecAgentTradeInfoField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySecAgentTradeInfo(gUserApi, pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast);
}

// 请求查询期权交易成本响应
extern "C" void wrapTraderOnRspQryOptionInstrTradeCost(uintptr_t, CThostFtdcOptionInstrTradeCostField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOptionInstrTradeCost(gUserApi, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
}

// 请求查询期权合约手续费响应
extern "C" void wrapTraderOnRspQryOptionInstrCommRate(uintptr_t, CThostFtdcOptionInstrCommRateField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOptionInstrCommRate(gUserApi, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

// 请求查询执行宣告响应
extern "C" void wrapTraderOnRspQryExecOrder(uintptr_t, CThostFtdcExecOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryExecOrder(gUserApi, pExecOrder, pRspInfo, nRequestID, bIsLast);
}

// 请求查询询价响应
extern "C" void wrapTraderOnRspQryForQuote(uintptr_t, CThostFtdcForQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryForQuote(gUserApi, pForQuote, pRspInfo, nRequestID, bIsLast);
}

// 请求查询报价响应
extern "C" void wrapTraderOnRspQryQuote(uintptr_t, CThostFtdcQuoteField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryQuote(gUserApi, pQuote, pRspInfo, nRequestID, bIsLast);
}

// 请求查询期权自对冲响应
extern "C" void wrapTraderOnRspQryOptionSelfClose(uintptr_t, CThostFtdcOptionSelfCloseField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryOptionSelfClose(gUserApi, pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
}

// 请求查询投资单元响应
extern "C" void wrapTraderOnRspQryInvestUnit(uintptr_t, CThostFtdcInvestUnitField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestUnit(gUserApi, pInvestUnit, pRspInfo, nRequestID, bIsLast);
}

// 请求查询组合合约安全系数响应
extern "C" void wrapTraderOnRspQryCombInstrumentGuard(uintptr_t, CThostFtdcCombInstrumentGuardField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombInstrumentGuard(gUserApi, pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
}

// 请求查询申请组合响应
extern "C" void wrapTraderOnRspQryCombAction(uintptr_t, CThostFtdcCombActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombAction(gUserApi, pCombAction, pRspInfo, nRequestID, bIsLast);
}

// 请求查询转帐流水响应
extern "C" void wrapTraderOnRspQryTransferSerial(uintptr_t, CThostFtdcTransferSerialField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTransferSerial(gUserApi, pTransferSerial, pRspInfo, nRequestID, bIsLast);
}

// 请求查询银期签约关系响应
extern "C" void wrapTraderOnRspQryAccountregister(uintptr_t, CThostFtdcAccountregisterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryAccountregister(gUserApi, pAccountregister, pRspInfo, nRequestID, bIsLast);
}

// 错误应答
extern "C" void wrapTraderOnRspError(uintptr_t, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspError(gUserApi, pRspInfo, nRequestID, bIsLast);
}

// 报单通知
extern "C" void wrapTraderOnRtnOrder(uintptr_t, CThostFtdcOrderField*);
void QCTPTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
    wrapTraderOnRtnOrder(gUserApi, pOrder);
}

// 成交通知
extern "C" void wrapTraderOnRtnTrade(uintptr_t, CThostFtdcTradeField*);
void QCTPTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
    wrapTraderOnRtnTrade(gUserApi, pTrade);
}

// 报单录入错误回报
extern "C" void wrapTraderOnErrRtnOrderInsert(uintptr_t, CThostFtdcInputOrderField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOrderInsert(gUserApi, pInputOrder, pRspInfo);
}

// 报单操作错误回报
extern "C" void wrapTraderOnErrRtnOrderAction(uintptr_t, CThostFtdcOrderActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOrderAction(gUserApi, pOrderAction, pRspInfo);
}

// 合约交易状态通知
extern "C" void wrapTraderOnRtnInstrumentStatus(uintptr_t, CThostFtdcInstrumentStatusField*);
void QCTPTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
    wrapTraderOnRtnInstrumentStatus(gUserApi, pInstrumentStatus);
}

// 交易所公告通知
extern "C" void wrapTraderOnRtnBulletin(uintptr_t, CThostFtdcBulletinField*);
void QCTPTraderSpi::OnRtnBulletin(CThostFtdcBulletinField* pBulletin)
{
    wrapTraderOnRtnBulletin(gUserApi, pBulletin);
}

// 交易通知
extern "C" void wrapTraderOnRtnTradingNotice(uintptr_t, CThostFtdcTradingNoticeInfoField*);
void QCTPTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
{
    wrapTraderOnRtnTradingNotice(gUserApi, pTradingNoticeInfo);
}

// 提示条件单校验错误
extern "C" void wrapTraderOnRtnErrorConditionalOrder(uintptr_t, CThostFtdcErrorConditionalOrderField*);
void QCTPTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
{
    wrapTraderOnRtnErrorConditionalOrder(gUserApi, pErrorConditionalOrder);
}

// 执行宣告通知
extern "C" void wrapTraderOnRtnExecOrder(uintptr_t, CThostFtdcExecOrderField*);
void QCTPTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
{
    wrapTraderOnRtnExecOrder(gUserApi, pExecOrder);
}

// 执行宣告录入错误回报
extern "C" void wrapTraderOnErrRtnExecOrderInsert(uintptr_t, CThostFtdcInputExecOrderField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnExecOrderInsert(gUserApi, pInputExecOrder, pRspInfo);
}

// 执行宣告操作错误回报
extern "C" void wrapTraderOnErrRtnExecOrderAction(uintptr_t, CThostFtdcExecOrderActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnExecOrderAction(gUserApi, pExecOrderAction, pRspInfo);
}

// 询价录入错误回报
extern "C" void wrapTraderOnErrRtnForQuoteInsert(uintptr_t, CThostFtdcInputForQuoteField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnForQuoteInsert(gUserApi, pInputForQuote, pRspInfo);
}

// 报价通知
extern "C" void wrapTraderOnRtnQuote(uintptr_t, CThostFtdcQuoteField*);
void QCTPTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
{
    wrapTraderOnRtnQuote(gUserApi, pQuote);
}

// 报价录入错误回报
extern "C" void wrapTraderOnErrRtnQuoteInsert(uintptr_t, CThostFtdcInputQuoteField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnQuoteInsert(gUserApi, pInputQuote, pRspInfo);
}

// 报价操作错误回报
extern "C" void wrapTraderOnErrRtnQuoteAction(uintptr_t, CThostFtdcQuoteActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnQuoteAction(gUserApi, pQuoteAction, pRspInfo);
}

// 询价通知
extern "C" void wrapTraderOnRtnForQuoteRsp(uintptr_t, CThostFtdcForQuoteRspField*);
void QCTPTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    wrapTraderOnRtnForQuoteRsp(gUserApi, pForQuoteRsp);
}

// 保证金监控中心用户令牌
extern "C" void wrapTraderOnRtnCFMMCTradingAccountToken(uintptr_t, CThostFtdcCFMMCTradingAccountTokenField*);
void QCTPTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
{
    wrapTraderOnRtnCFMMCTradingAccountToken(gUserApi, pCFMMCTradingAccountToken);
}

// 批量报单操作错误回报
extern "C" void wrapTraderOnErrRtnBatchOrderAction(uintptr_t, CThostFtdcBatchOrderActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnBatchOrderAction(gUserApi, pBatchOrderAction, pRspInfo);
}

// 期权自对冲通知
extern "C" void wrapTraderOnRtnOptionSelfClose(uintptr_t, CThostFtdcOptionSelfCloseField*);
void QCTPTraderSpi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose)
{
    wrapTraderOnRtnOptionSelfClose(gUserApi, pOptionSelfClose);
}

// 期权自对冲录入错误回报
extern "C" void wrapTraderOnErrRtnOptionSelfCloseInsert(uintptr_t, CThostFtdcInputOptionSelfCloseField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOptionSelfCloseInsert(gUserApi, pInputOptionSelfClose, pRspInfo);
}

// 期权自对冲操作错误回报
extern "C" void wrapTraderOnErrRtnOptionSelfCloseAction(uintptr_t, CThostFtdcOptionSelfCloseActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnOptionSelfCloseAction(gUserApi, pOptionSelfCloseAction, pRspInfo);
}

// 申请组合通知
extern "C" void wrapTraderOnRtnCombAction(uintptr_t, CThostFtdcCombActionField*);
void QCTPTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
{
    wrapTraderOnRtnCombAction(gUserApi, pCombAction);
}

// 申请组合录入错误回报
extern "C" void wrapTraderOnErrRtnCombActionInsert(uintptr_t, CThostFtdcInputCombActionField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnCombActionInsert(gUserApi, pInputCombAction, pRspInfo);
}

// 请求查询签约银行响应
extern "C" void wrapTraderOnRspQryContractBank(uintptr_t, CThostFtdcContractBankField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryContractBank(gUserApi, pContractBank, pRspInfo, nRequestID, bIsLast);
}

// 请求查询预埋单响应
extern "C" void wrapTraderOnRspQryParkedOrder(uintptr_t, CThostFtdcParkedOrderField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryParkedOrder(gUserApi, pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

// 请求查询预埋撤单响应
extern "C" void wrapTraderOnRspQryParkedOrderAction(uintptr_t, CThostFtdcParkedOrderActionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryParkedOrderAction(gUserApi, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

// 请求查询交易通知响应
extern "C" void wrapTraderOnRspQryTradingNotice(uintptr_t, CThostFtdcTradingNoticeField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryTradingNotice(gUserApi, pTradingNotice, pRspInfo, nRequestID, bIsLast);
}

// 请求查询经纪公司交易参数响应
extern "C" void wrapTraderOnRspQryBrokerTradingParams(uintptr_t, CThostFtdcBrokerTradingParamsField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryBrokerTradingParams(gUserApi, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
}

// 请求查询经纪公司交易算法响应
extern "C" void wrapTraderOnRspQryBrokerTradingAlgos(uintptr_t, CThostFtdcBrokerTradingAlgosField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryBrokerTradingAlgos(gUserApi, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
}

// 请求查询监控中心用户令牌
extern "C" void wrapTraderOnRspQueryCFMMCTradingAccountToken(uintptr_t, CThostFtdcQueryCFMMCTradingAccountTokenField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQueryCFMMCTradingAccountToken(gUserApi, pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
}

// 银行发起银行资金转期货通知
extern "C" void wrapTraderOnRtnFromBankToFutureByBank(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromBankToFutureByBank(gUserApi, pRspTransfer);
}

// 银行发起期货资金转银行通知
extern "C" void wrapTraderOnRtnFromFutureToBankByBank(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromFutureToBankByBank(gUserApi, pRspTransfer);
}

// 银行发起冲正银行转期货通知
extern "C" void wrapTraderOnRtnRepealFromBankToFutureByBank(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromBankToFutureByBank(gUserApi, pRspRepeal);
}

// 银行发起冲正期货转银行通知
extern "C" void wrapTraderOnRtnRepealFromFutureToBankByBank(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromFutureToBankByBank(gUserApi, pRspRepeal);
}

// 期货发起银行资金转期货通知
extern "C" void wrapTraderOnRtnFromBankToFutureByFuture(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromBankToFutureByFuture(gUserApi, pRspTransfer);
}

// 期货发起期货资金转银行通知
extern "C" void wrapTraderOnRtnFromFutureToBankByFuture(uintptr_t, CThostFtdcRspTransferField*);
void QCTPTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    wrapTraderOnRtnFromFutureToBankByFuture(gUserApi, pRspTransfer);
}

// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
extern "C" void wrapTraderOnRtnRepealFromBankToFutureByFutureManual(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromBankToFutureByFutureManual(gUserApi, pRspRepeal);
}

// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
extern "C" void wrapTraderOnRtnRepealFromFutureToBankByFutureManual(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromFutureToBankByFutureManual(gUserApi, pRspRepeal);
}

// 期货发起查询银行余额通知
extern "C" void wrapTraderOnRtnQueryBankBalanceByFuture(uintptr_t, CThostFtdcNotifyQueryAccountField*);
void QCTPTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
{
    wrapTraderOnRtnQueryBankBalanceByFuture(gUserApi, pNotifyQueryAccount);
}

// 期货发起银行资金转期货错误回报
extern "C" void wrapTraderOnErrRtnBankToFutureByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnBankToFutureByFuture(gUserApi, pReqTransfer, pRspInfo);
}

// 期货发起期货资金转银行错误回报
extern "C" void wrapTraderOnErrRtnFutureToBankByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnFutureToBankByFuture(gUserApi, pReqTransfer, pRspInfo);
}

// 系统运行时期货端手工发起冲正银行转期货错误回报
extern "C" void wrapTraderOnErrRtnRepealBankToFutureByFutureManual(uintptr_t, CThostFtdcReqRepealField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnRepealBankToFutureByFutureManual(gUserApi, pReqRepeal, pRspInfo);
}

// 系统运行时期货端手工发起冲正期货转银行错误回报
extern "C" void wrapTraderOnErrRtnRepealFutureToBankByFutureManual(uintptr_t, CThostFtdcReqRepealField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnRepealFutureToBankByFutureManual(gUserApi, pReqRepeal, pRspInfo);
}

// 期货发起查询银行余额错误回报
extern "C" void wrapTraderOnErrRtnQueryBankBalanceByFuture(uintptr_t, CThostFtdcReqQueryAccountField*, CThostFtdcRspInfoField*);
void QCTPTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
{
    wrapTraderOnErrRtnQueryBankBalanceByFuture(gUserApi, pReqQueryAccount, pRspInfo);
}

// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
extern "C" void wrapTraderOnRtnRepealFromBankToFutureByFuture(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromBankToFutureByFuture(gUserApi, pRspRepeal);
}

// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
extern "C" void wrapTraderOnRtnRepealFromFutureToBankByFuture(uintptr_t, CThostFtdcRspRepealField*);
void QCTPTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    wrapTraderOnRtnRepealFromFutureToBankByFuture(gUserApi, pRspRepeal);
}

// 期货发起银行资金转期货应答
extern "C" void wrapTraderOnRspFromBankToFutureByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspFromBankToFutureByFuture(gUserApi, pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

// 期货发起期货资金转银行应答
extern "C" void wrapTraderOnRspFromFutureToBankByFuture(uintptr_t, CThostFtdcReqTransferField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspFromFutureToBankByFuture(gUserApi, pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

// 期货发起查询银行余额应答
extern "C" void wrapTraderOnRspQueryBankAccountMoneyByFuture(uintptr_t, CThostFtdcReqQueryAccountField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQueryBankAccountMoneyByFuture(gUserApi, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
}

// 银行发起银期开户通知
extern "C" void wrapTraderOnRtnOpenAccountByBank(uintptr_t, CThostFtdcOpenAccountField*);
void QCTPTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
{
    wrapTraderOnRtnOpenAccountByBank(gUserApi, pOpenAccount);
}

// 银行发起银期销户通知
extern "C" void wrapTraderOnRtnCancelAccountByBank(uintptr_t, CThostFtdcCancelAccountField*);
void QCTPTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
{
    wrapTraderOnRtnCancelAccountByBank(gUserApi, pCancelAccount);
}

// 银行发起变更银行账号通知
extern "C" void wrapTraderOnRtnChangeAccountByBank(uintptr_t, CThostFtdcChangeAccountField*);
void QCTPTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
{
    wrapTraderOnRtnChangeAccountByBank(gUserApi, pChangeAccount);
}

// 请求查询分类合约响应
extern "C" void wrapTraderOnRspQryClassifiedInstrument(uintptr_t, CThostFtdcInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryClassifiedInstrument(gUserApi, pInstrument, pRspInfo, nRequestID, bIsLast);
}

// 请求组合优惠比例响应
extern "C" void wrapTraderOnRspQryCombPromotionParam(uintptr_t, CThostFtdcCombPromotionParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryCombPromotionParam(gUserApi, pCombPromotionParam, pRspInfo, nRequestID, bIsLast);
}

// 投资者风险结算持仓查询响应
extern "C" void wrapTraderOnRspQryRiskSettleInvstPosition(uintptr_t, CThostFtdcRiskSettleInvstPositionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRiskSettleInvstPosition(gUserApi, pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast);
}

// 风险结算产品查询响应
extern "C" void wrapTraderOnRspQryRiskSettleProductStatus(uintptr_t, CThostFtdcRiskSettleProductStatusField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRiskSettleProductStatus(gUserApi, pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast);
}

// SPBM期货合约参数查询响应
extern "C" void wrapTraderOnRspQrySPBMFutureParameter(uintptr_t, CThostFtdcSPBMFutureParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField* pSPBMFutureParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMFutureParameter(gUserApi, pSPBMFutureParameter, pRspInfo, nRequestID, bIsLast);
}

// SPBM期权合约参数查询响应
extern "C" void wrapTraderOnRspQrySPBMOptionParameter(uintptr_t, CThostFtdcSPBMOptionParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField* pSPBMOptionParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMOptionParameter(gUserApi, pSPBMOptionParameter, pRspInfo, nRequestID, bIsLast);
}

// SPBM品种内对锁仓折扣参数查询响应
extern "C" void wrapTraderOnRspQrySPBMIntraParameter(uintptr_t, CThostFtdcSPBMIntraParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField* pSPBMIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMIntraParameter(gUserApi, pSPBMIntraParameter, pRspInfo, nRequestID, bIsLast);
}

// SPBM跨品种抵扣参数查询响应
extern "C" void wrapTraderOnRspQrySPBMInterParameter(uintptr_t, CThostFtdcSPBMInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField* pSPBMInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMInterParameter(gUserApi, pSPBMInterParameter, pRspInfo, nRequestID, bIsLast);
}

// SPBM组合保证金套餐查询响应
extern "C" void wrapTraderOnRspQrySPBMPortfDefinition(uintptr_t, CThostFtdcSPBMPortfDefinitionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField* pSPBMPortfDefinition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMPortfDefinition(gUserApi, pSPBMPortfDefinition, pRspInfo, nRequestID, bIsLast);
}

// 投资者SPBM套餐选择查询响应
extern "C" void wrapTraderOnRspQrySPBMInvestorPortfDef(uintptr_t, CThostFtdcSPBMInvestorPortfDefField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField* pSPBMInvestorPortfDef, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMInvestorPortfDef(gUserApi, pSPBMInvestorPortfDef, pRspInfo, nRequestID, bIsLast);
}

// 投资者新型组合保证金系数查询响应
extern "C" void wrapTraderOnRspQryInvestorPortfMarginRatio(uintptr_t, CThostFtdcInvestorPortfMarginRatioField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField* pInvestorPortfMarginRatio, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorPortfMarginRatio(gUserApi, pInvestorPortfMarginRatio, pRspInfo, nRequestID, bIsLast);
}

// 投资者产品SPBM明细查询响应
extern "C" void wrapTraderOnRspQryInvestorProdSPBMDetail(uintptr_t, CThostFtdcInvestorProdSPBMDetailField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField* pInvestorProdSPBMDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProdSPBMDetail(gUserApi, pInvestorProdSPBMDetail, pRspInfo, nRequestID, bIsLast);
}

// 投资者商品组SPMM记录查询响应
extern "C" void wrapTraderOnRspQryInvestorCommoditySPMMMargin(uintptr_t, CThostFtdcInvestorCommoditySPMMMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorCommoditySPMMMargin(CThostFtdcInvestorCommoditySPMMMarginField* pInvestorCommoditySPMMMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorCommoditySPMMMargin(gUserApi, pInvestorCommoditySPMMMargin, pRspInfo, nRequestID, bIsLast);
}

// 投资者商品群SPMM记录查询响应
extern "C" void wrapTraderOnRspQryInvestorCommodityGroupSPMMMargin(uintptr_t, CThostFtdcInvestorCommodityGroupSPMMMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorCommodityGroupSPMMMargin(CThostFtdcInvestorCommodityGroupSPMMMarginField* pInvestorCommodityGroupSPMMMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorCommodityGroupSPMMMargin(gUserApi, pInvestorCommodityGroupSPMMMargin, pRspInfo, nRequestID, bIsLast);
}

// SPMM合约参数查询响应
extern "C" void wrapTraderOnRspQrySPMMInstParam(uintptr_t, CThostFtdcSPMMInstParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPMMInstParam(CThostFtdcSPMMInstParamField* pSPMMInstParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPMMInstParam(gUserApi, pSPMMInstParam, pRspInfo, nRequestID, bIsLast);
}

// SPMM产品参数查询响应
extern "C" void wrapTraderOnRspQrySPMMProductParam(uintptr_t, CThostFtdcSPMMProductParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPMMProductParam(CThostFtdcSPMMProductParamField* pSPMMProductParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPMMProductParam(gUserApi, pSPMMProductParam, pRspInfo, nRequestID, bIsLast);
}

// SPBM附加跨品种抵扣参数查询响应
extern "C" void wrapTraderOnRspQrySPBMAddOnInterParameter(uintptr_t, CThostFtdcSPBMAddOnInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQrySPBMAddOnInterParameter(CThostFtdcSPBMAddOnInterParameterField* pSPBMAddOnInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQrySPBMAddOnInterParameter(gUserApi, pSPBMAddOnInterParameter, pRspInfo, nRequestID, bIsLast);
}

// RCAMS产品组合信息查询响应
extern "C" void wrapTraderOnRspQryRCAMSCombProductInfo(uintptr_t, CThostFtdcRCAMSCombProductInfoField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSCombProductInfo(CThostFtdcRCAMSCombProductInfoField* pRCAMSCombProductInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSCombProductInfo(gUserApi, pRCAMSCombProductInfo, pRspInfo, nRequestID, bIsLast);
}

// RCAMS同合约风险对冲参数查询响应
extern "C" void wrapTraderOnRspQryRCAMSInstrParameter(uintptr_t, CThostFtdcRCAMSInstrParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSInstrParameter(CThostFtdcRCAMSInstrParameterField* pRCAMSInstrParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSInstrParameter(gUserApi, pRCAMSInstrParameter, pRspInfo, nRequestID, bIsLast);
}

// RCAMS品种内风险对冲参数查询响应
extern "C" void wrapTraderOnRspQryRCAMSIntraParameter(uintptr_t, CThostFtdcRCAMSIntraParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSIntraParameter(CThostFtdcRCAMSIntraParameterField* pRCAMSIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSIntraParameter(gUserApi, pRCAMSIntraParameter, pRspInfo, nRequestID, bIsLast);
}

// RCAMS跨品种风险折抵参数查询响应
extern "C" void wrapTraderOnRspQryRCAMSInterParameter(uintptr_t, CThostFtdcRCAMSInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSInterParameter(CThostFtdcRCAMSInterParameterField* pRCAMSInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSInterParameter(gUserApi, pRCAMSInterParameter, pRspInfo, nRequestID, bIsLast);
}

// RCAMS空头期权风险调整参数查询响应
extern "C" void wrapTraderOnRspQryRCAMSShortOptAdjustParam(uintptr_t, CThostFtdcRCAMSShortOptAdjustParamField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSShortOptAdjustParam(CThostFtdcRCAMSShortOptAdjustParamField* pRCAMSShortOptAdjustParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSShortOptAdjustParam(gUserApi, pRCAMSShortOptAdjustParam, pRspInfo, nRequestID, bIsLast);
}

// RCAMS策略组合持仓查询响应
extern "C" void wrapTraderOnRspQryRCAMSInvestorCombPosition(uintptr_t, CThostFtdcRCAMSInvestorCombPositionField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField* pRCAMSInvestorCombPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRCAMSInvestorCombPosition(gUserApi, pRCAMSInvestorCombPosition, pRspInfo, nRequestID, bIsLast);
}

// 投资者品种RCAMS保证金查询响应
extern "C" void wrapTraderOnRspQryInvestorProdRCAMSMargin(uintptr_t, CThostFtdcInvestorProdRCAMSMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProdRCAMSMargin(CThostFtdcInvestorProdRCAMSMarginField* pInvestorProdRCAMSMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProdRCAMSMargin(gUserApi, pInvestorProdRCAMSMargin, pRspInfo, nRequestID, bIsLast);
}

// RULE合约保证金参数查询响应
extern "C" void wrapTraderOnRspQryRULEInstrParameter(uintptr_t, CThostFtdcRULEInstrParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRULEInstrParameter(CThostFtdcRULEInstrParameterField* pRULEInstrParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRULEInstrParameter(gUserApi, pRULEInstrParameter, pRspInfo, nRequestID, bIsLast);
}

// RULE品种内对锁仓折扣参数查询响应
extern "C" void wrapTraderOnRspQryRULEIntraParameter(uintptr_t, CThostFtdcRULEIntraParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRULEIntraParameter(CThostFtdcRULEIntraParameterField* pRULEIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRULEIntraParameter(gUserApi, pRULEIntraParameter, pRspInfo, nRequestID, bIsLast);
}

// RULE跨品种抵扣参数查询响应
extern "C" void wrapTraderOnRspQryRULEInterParameter(uintptr_t, CThostFtdcRULEInterParameterField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryRULEInterParameter(CThostFtdcRULEInterParameterField* pRULEInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryRULEInterParameter(gUserApi, pRULEInterParameter, pRspInfo, nRequestID, bIsLast);
}

// 投资者产品RULE保证金查询响应
extern "C" void wrapTraderOnRspQryInvestorProdRULEMargin(uintptr_t, CThostFtdcInvestorProdRULEMarginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPTraderSpi::OnRspQryInvestorProdRULEMargin(CThostFtdcInvestorProdRULEMarginField* pInvestorProdRULEMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapTraderOnRspQryInvestorProdRULEMargin(gUserApi, pInvestorProdRULEMargin, pRspInfo, nRequestID, bIsLast);
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

// 获取API的版本信息
///@retrun 获取到的版本号
const char* QCTPTraderSpi::GetApiVersion()
{
    return this->pUserApi->GetApiVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void QCTPTraderSpi::Release()
{
    this->pUserApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void QCTPTraderSpi::Init()
{
    this->pUserApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int QCTPTraderSpi::Join()
{
    return this->pUserApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* QCTPTraderSpi::GetTradingDay()
{
    return this->pUserApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void QCTPTraderSpi::RegisterFront(char* pszFrontAddress)
{
    this->pUserApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void QCTPTraderSpi::RegisterNameServer(char* pszNsAddress)
{
    this->pUserApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void QCTPTraderSpi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
    this->pUserApi->RegisterFensUserInfo(pFensUserInfo);
}

// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void QCTPTraderSpi::RegisterSpi(CThostFtdcTraderSpi* pSpi)
{
    this->pUserApi->RegisterSpi(pSpi);
}

// 订阅私有流。
///@param nResumeType 私有流重传方式
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
void QCTPTraderSpi::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
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
void QCTPTraderSpi::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
    this->pUserApi->SubscribePublicTopic(nResumeType);
}

// 客户端认证请求
int QCTPTraderSpi::ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
    return this->pUserApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

// 注册用户终端信息，用于中继服务器多连接模式
/// 需要在终端认证成功后，用户登录前调用该接口
int QCTPTraderSpi::RegisterUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->RegisterUserSystemInfo(pUserSystemInfo);
}

// 上报用户终端信息，用于中继服务器操作员登录模式
/// 操作员登录后，可以多次调用该接口上报客户信息
int QCTPTraderSpi::SubmitUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
    return this->pUserApi->SubmitUserSystemInfo(pUserSystemInfo);
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

// 登出请求
int QCTPTraderSpi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return this->pUserApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 用户口令更新请求
int QCTPTraderSpi::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID)
{
    return this->pUserApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

// 资金账户口令更新请求
int QCTPTraderSpi::ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID)
{
    return this->pUserApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

// 查询用户当前支持的认证模式
int QCTPTraderSpi::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
    return this->pUserApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

// 用户发出获取图形验证码请求
int QCTPTraderSpi::ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID)
{
    return this->pUserApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

// 用户发出获取短信验证码请求
int QCTPTraderSpi::ReqGenUserText(CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID)
{
    return this->pUserApi->ReqGenUserText(pReqGenUserText, nRequestID);
}

// 用户发出带有图片验证码的登陆请求
int QCTPTraderSpi::ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

// 用户发出带有短信验证码的登陆请求
int QCTPTraderSpi::ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

// 用户发出带有动态口令的登陆请求
int QCTPTraderSpi::ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID)
{
    return this->pUserApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

// 报单录入请求
int QCTPTraderSpi::ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder, int nRequestID)
{
    return this->pUserApi->ReqOrderInsert(pInputOrder, nRequestID);
}

// 预埋单录入请求
int QCTPTraderSpi::ReqParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

// 预埋撤单录入请求
int QCTPTraderSpi::ReqParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

// 报单操作请求
int QCTPTraderSpi::ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID)
{
    return this->pUserApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

// 查询最大报单数量请求
int QCTPTraderSpi::ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
    return this->pUserApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

// 投资者结算结果确认
int QCTPTraderSpi::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID)
{
    return this->pUserApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

// 请求删除预埋单
int QCTPTraderSpi::ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

// 请求删除预埋撤单
int QCTPTraderSpi::ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

// 执行宣告录入请求
int QCTPTraderSpi::ReqExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
    return this->pUserApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

// 执行宣告操作请求
int QCTPTraderSpi::ReqExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
    return this->pUserApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

// 询价录入请求
int QCTPTraderSpi::ReqForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID)
{
    return this->pUserApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

// 报价录入请求
int QCTPTraderSpi::ReqQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, int nRequestID)
{
    return this->pUserApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

// 报价操作请求
int QCTPTraderSpi::ReqQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID)
{
    return this->pUserApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

// 批量报单操作请求
int QCTPTraderSpi::ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID)
{
    return this->pUserApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

// 期权自对冲录入请求
int QCTPTraderSpi::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
    return this->pUserApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

// 期权自对冲操作请求
int QCTPTraderSpi::ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
    return this->pUserApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

// 申请组合录入请求
int QCTPTraderSpi::ReqCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, int nRequestID)
{
    return this->pUserApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

// 请求查询报单
int QCTPTraderSpi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder, int nRequestID)
{
    return this->pUserApi->ReqQryOrder(pQryOrder, nRequestID);
}

// 请求查询成交
int QCTPTraderSpi::ReqQryTrade(CThostFtdcQryTradeField* pQryTrade, int nRequestID)
{
    return this->pUserApi->ReqQryTrade(pQryTrade, nRequestID);
}

// 请求查询投资者持仓
int QCTPTraderSpi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

// 请求查询资金账户
int QCTPTraderSpi::ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return this->pUserApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询投资者
int QCTPTraderSpi::ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor, int nRequestID)
{
    return this->pUserApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

// 请求查询交易编码
int QCTPTraderSpi::ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
    return this->pUserApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

// 请求查询合约保证金率
int QCTPTraderSpi::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

// 请求查询合约手续费率
int QCTPTraderSpi::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

// 请求查询交易所
int QCTPTraderSpi::ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange, int nRequestID)
{
    return this->pUserApi->ReqQryExchange(pQryExchange, nRequestID);
}

// 请求查询产品
int QCTPTraderSpi::ReqQryProduct(CThostFtdcQryProductField* pQryProduct, int nRequestID)
{
    return this->pUserApi->ReqQryProduct(pQryProduct, nRequestID);
}

// 请求查询合约
int QCTPTraderSpi::ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

// 请求查询行情
int QCTPTraderSpi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID)
{
    return this->pUserApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

// 请求查询投资者结算结果
int QCTPTraderSpi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID)
{
    return this->pUserApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

// 请求查询转帐银行
int QCTPTraderSpi::ReqQryTransferBank(CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID)
{
    return this->pUserApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

// 请求查询投资者持仓明细
int QCTPTraderSpi::ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

// 请求查询客户通知
int QCTPTraderSpi::ReqQryNotice(CThostFtdcQryNoticeField* pQryNotice, int nRequestID)
{
    return this->pUserApi->ReqQryNotice(pQryNotice, nRequestID);
}

// 请求查询结算信息确认
int QCTPTraderSpi::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID)
{
    return this->pUserApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

// 请求查询投资者持仓明细
int QCTPTraderSpi::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

// 请求查询保证金监管系统经纪公司资金账户密钥
int QCTPTraderSpi::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
    return this->pUserApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

// 请求查询仓单折抵信息
int QCTPTraderSpi::ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID)
{
    return this->pUserApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

// 请求查询投资者品种/跨品种保证金
int QCTPTraderSpi::ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

// 请求查询交易所保证金率
int QCTPTraderSpi::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

// 请求查询交易所调整保证金率
int QCTPTraderSpi::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

// 请求查询汇率
int QCTPTraderSpi::ReqQryExchangeRate(CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID)
{
    return this->pUserApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

// 请求查询二级代理操作员银期权限
int QCTPTraderSpi::ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

// 请求查询产品报价汇率
int QCTPTraderSpi::ReqQryProductExchRate(CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID)
{
    return this->pUserApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

// 请求查询产品组
int QCTPTraderSpi::ReqQryProductGroup(CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID)
{
    return this->pUserApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

// 请求查询做市商合约手续费率
int QCTPTraderSpi::ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID)
{
    return this->pUserApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

// 请求查询做市商期权合约手续费
int QCTPTraderSpi::ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

// 请求查询报单手续费
int QCTPTraderSpi::ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

// 请求查询资金账户
int QCTPTraderSpi::ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

// 请求查询二级代理商资金校验模式
int QCTPTraderSpi::ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

// 请求查询二级代理商信息
int QCTPTraderSpi::ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
    return this->pUserApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

// 请求查询期权交易成本
int QCTPTraderSpi::ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
    return this->pUserApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

// 请求查询期权合约手续费
int QCTPTraderSpi::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
    return this->pUserApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

// 请求查询执行宣告
int QCTPTraderSpi::ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
    return this->pUserApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

// 请求查询询价
int QCTPTraderSpi::ReqQryForQuote(CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID)
{
    return this->pUserApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

// 请求查询报价
int QCTPTraderSpi::ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
    return this->pUserApi->ReqQryQuote(pQryQuote, nRequestID);
}

// 请求查询期权自对冲
int QCTPTraderSpi::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
    return this->pUserApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

// 请求查询投资单元
int QCTPTraderSpi::ReqQryInvestUnit(CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
    return this->pUserApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

// 请求查询组合合约安全系数
int QCTPTraderSpi::ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
    return this->pUserApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

// 请求查询申请组合
int QCTPTraderSpi::ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
    return this->pUserApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

// 请求查询转帐流水
int QCTPTraderSpi::ReqQryTransferSerial(CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID)
{
    return this->pUserApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

// 请求查询银期签约关系
int QCTPTraderSpi::ReqQryAccountregister(CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID)
{
    return this->pUserApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

// 请求查询签约银行
int QCTPTraderSpi::ReqQryContractBank(CThostFtdcQryContractBankField* pQryContractBank, int nRequestID)
{
    return this->pUserApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

// 请求查询预埋单
int QCTPTraderSpi::ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
    return this->pUserApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

// 请求查询预埋撤单
int QCTPTraderSpi::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
    return this->pUserApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

// 请求查询交易通知
int QCTPTraderSpi::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID)
{
    return this->pUserApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

// 请求查询经纪公司交易参数
int QCTPTraderSpi::ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID)
{
    return this->pUserApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

// 请求查询经纪公司交易算法
int QCTPTraderSpi::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
    return this->pUserApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

// 请求查询监控中心用户令牌
int QCTPTraderSpi::ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
    return this->pUserApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

// 期货发起银行资金转期货请求
int QCTPTraderSpi::ReqFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return this->pUserApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

// 期货发起期货资金转银行请求
int QCTPTraderSpi::ReqFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID)
{
    return this->pUserApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

// 期货发起查询银行余额请求
int QCTPTraderSpi::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
    return this->pUserApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

// 请求查询分类合约
int QCTPTraderSpi::ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

// 请求组合优惠比例
int QCTPTraderSpi::ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
    return this->pUserApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

// 投资者风险结算持仓查询
int QCTPTraderSpi::ReqQryRiskSettleInvstPosition(CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
    return this->pUserApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

// 风险结算产品查询
int QCTPTraderSpi::ReqQryRiskSettleProductStatus(CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
    return this->pUserApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}

// SPBM期货合约参数查询
int QCTPTraderSpi::ReqQrySPBMFutureParameter(CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMFutureParameter(pQrySPBMFutureParameter, nRequestID);
}

// SPBM期权合约参数查询
int QCTPTraderSpi::ReqQrySPBMOptionParameter(CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMOptionParameter(pQrySPBMOptionParameter, nRequestID);
}

// SPBM品种内对锁仓折扣参数查询
int QCTPTraderSpi::ReqQrySPBMIntraParameter(CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMIntraParameter(pQrySPBMIntraParameter, nRequestID);
}

// SPBM跨品种抵扣参数查询
int QCTPTraderSpi::ReqQrySPBMInterParameter(CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMInterParameter(pQrySPBMInterParameter, nRequestID);
}

// SPBM组合保证金套餐查询
int QCTPTraderSpi::ReqQrySPBMPortfDefinition(CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMPortfDefinition(pQrySPBMPortfDefinition, nRequestID);
}

// 投资者SPBM套餐选择查询
int QCTPTraderSpi::ReqQrySPBMInvestorPortfDef(CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMInvestorPortfDef(pQrySPBMInvestorPortfDef, nRequestID);
}

// 投资者新型组合保证金系数查询
int QCTPTraderSpi::ReqQryInvestorPortfMarginRatio(CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorPortfMarginRatio(pQryInvestorPortfMarginRatio, nRequestID);
}

// 投资者产品SPBM明细查询
int QCTPTraderSpi::ReqQryInvestorProdSPBMDetail(CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProdSPBMDetail(pQryInvestorProdSPBMDetail, nRequestID);
}

// 投资者商品组SPMM记录查询
int QCTPTraderSpi::ReqQryInvestorCommoditySPMMMargin(CThostFtdcQryInvestorCommoditySPMMMarginField* pQryInvestorCommoditySPMMMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorCommoditySPMMMargin(pQryInvestorCommoditySPMMMargin, nRequestID);
}

// 投资者商品群SPMM记录查询
int QCTPTraderSpi::ReqQryInvestorCommodityGroupSPMMMargin(CThostFtdcQryInvestorCommodityGroupSPMMMarginField* pQryInvestorCommodityGroupSPMMMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorCommodityGroupSPMMMargin(pQryInvestorCommodityGroupSPMMMargin, nRequestID);
}

// SPMM合约参数查询
int QCTPTraderSpi::ReqQrySPMMInstParam(CThostFtdcQrySPMMInstParamField* pQrySPMMInstParam, int nRequestID)
{
    return this->pUserApi->ReqQrySPMMInstParam(pQrySPMMInstParam, nRequestID);
}

// SPMM产品参数查询
int QCTPTraderSpi::ReqQrySPMMProductParam(CThostFtdcQrySPMMProductParamField* pQrySPMMProductParam, int nRequestID)
{
    return this->pUserApi->ReqQrySPMMProductParam(pQrySPMMProductParam, nRequestID);
}

// SPBM附加跨品种抵扣参数查询
int QCTPTraderSpi::ReqQrySPBMAddOnInterParameter(CThostFtdcQrySPBMAddOnInterParameterField* pQrySPBMAddOnInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQrySPBMAddOnInterParameter(pQrySPBMAddOnInterParameter, nRequestID);
}

// RCAMS产品组合信息查询
int QCTPTraderSpi::ReqQryRCAMSCombProductInfo(CThostFtdcQryRCAMSCombProductInfoField* pQryRCAMSCombProductInfo, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSCombProductInfo(pQryRCAMSCombProductInfo, nRequestID);
}

// RCAMS同合约风险对冲参数查询
int QCTPTraderSpi::ReqQryRCAMSInstrParameter(CThostFtdcQryRCAMSInstrParameterField* pQryRCAMSInstrParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSInstrParameter(pQryRCAMSInstrParameter, nRequestID);
}

// RCAMS品种内风险对冲参数查询
int QCTPTraderSpi::ReqQryRCAMSIntraParameter(CThostFtdcQryRCAMSIntraParameterField* pQryRCAMSIntraParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSIntraParameter(pQryRCAMSIntraParameter, nRequestID);
}

// RCAMS跨品种风险折抵参数查询
int QCTPTraderSpi::ReqQryRCAMSInterParameter(CThostFtdcQryRCAMSInterParameterField* pQryRCAMSInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSInterParameter(pQryRCAMSInterParameter, nRequestID);
}

// RCAMS空头期权风险调整参数查询
int QCTPTraderSpi::ReqQryRCAMSShortOptAdjustParam(CThostFtdcQryRCAMSShortOptAdjustParamField* pQryRCAMSShortOptAdjustParam, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSShortOptAdjustParam(pQryRCAMSShortOptAdjustParam, nRequestID);
}

// RCAMS策略组合持仓查询
int QCTPTraderSpi::ReqQryRCAMSInvestorCombPosition(CThostFtdcQryRCAMSInvestorCombPositionField* pQryRCAMSInvestorCombPosition, int nRequestID)
{
    return this->pUserApi->ReqQryRCAMSInvestorCombPosition(pQryRCAMSInvestorCombPosition, nRequestID);
}

// 投资者品种RCAMS保证金查询
int QCTPTraderSpi::ReqQryInvestorProdRCAMSMargin(CThostFtdcQryInvestorProdRCAMSMarginField* pQryInvestorProdRCAMSMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProdRCAMSMargin(pQryInvestorProdRCAMSMargin, nRequestID);
}

// RULE合约保证金参数查询
int QCTPTraderSpi::ReqQryRULEInstrParameter(CThostFtdcQryRULEInstrParameterField* pQryRULEInstrParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRULEInstrParameter(pQryRULEInstrParameter, nRequestID);
}

// RULE品种内对锁仓折扣参数查询
int QCTPTraderSpi::ReqQryRULEIntraParameter(CThostFtdcQryRULEIntraParameterField* pQryRULEIntraParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRULEIntraParameter(pQryRULEIntraParameter, nRequestID);
}

// RULE跨品种抵扣参数查询
int QCTPTraderSpi::ReqQryRULEInterParameter(CThostFtdcQryRULEInterParameterField* pQryRULEInterParameter, int nRequestID)
{
    return this->pUserApi->ReqQryRULEInterParameter(pQryRULEInterParameter, nRequestID);
}

// 投资者产品RULE保证金查询
int QCTPTraderSpi::ReqQryInvestorProdRULEMargin(CThostFtdcQryInvestorProdRULEMarginField* pQryInvestorProdRULEMargin, int nRequestID)
{
    return this->pUserApi->ReqQryInvestorProdRULEMargin(pQryInvestorProdRULEMargin, nRequestID);
}
