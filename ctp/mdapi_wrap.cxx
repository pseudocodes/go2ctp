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

#include "mdapi_wrap.h"

typedef long long intgo;
typedef struct
{
    char* p;
    int64_t n;
} _gostring_;

typedef struct
{
    void* array;
    int64_t len;
    int64_t cap;
} _goslice_;

#ifdef __cplusplus
extern "C" {
#endif
QCTPMdSpi* _wrap_CThostFtdcMdApi_CreateFtdcMdApi()
{
    CThostFtdcMdApi* pUserApi = CThostFtdcMdApi::CreateFtdcMdApi("./data/", false);
    QCTPMdSpi* pUserSpi = new QCTPMdSpi(pUserApi);
    pUserSpi->RegisterSpi(pUserSpi);
    return pUserSpi;
}

QCTPMdSpi* _wrap_CThostFtdcMdApi_CreateFtdcMdApi2(uintptr_t gUserApi, const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
{
    // printf("go_user_api %lu\n", gUserApi);
    CThostFtdcMdApi* pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
    QCTPMdSpi* pUserSpi = new QCTPMdSpi(pUserApi, gUserApi);
    pUserSpi->RegisterSpi(pUserSpi);
    return pUserSpi;
}

// 获取API的版本信息
///@retrun 获取到的版本号
const char* _wrap_CThostFtdcMdApi_GetApiVersion(QCTPMdSpi* pMdApi)
{
    return pMdApi->GetApiVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void _wrap_CThostFtdcMdApi_Release(QCTPMdSpi* pMdApi)
{
    return pMdApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void _wrap_CThostFtdcMdApi_Init(QCTPMdSpi* pMdApi)
{
    return pMdApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int _wrap_CThostFtdcMdApi_Join(QCTPMdSpi* pMdApi)
{
    return pMdApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* _wrap_CThostFtdcMdApi_GetTradingDay(QCTPMdSpi* pMdApi)
{
    return pMdApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void _wrap_CThostFtdcMdApi_RegisterFront(QCTPMdSpi* pMdApi, char* pszFrontAddress)
{
    return pMdApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void _wrap_CThostFtdcMdApi_RegisterNameServer(QCTPMdSpi* pMdApi, char* pszNsAddress)
{
    return pMdApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void _wrap_CThostFtdcMdApi_RegisterFensUserInfo(QCTPMdSpi* pMdApi, CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return pMdApi->RegisterFensUserInfo(pFensUserInfo);
}

/// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void _wrap_CThostFtdcMdApi_RegisterSpi(QCTPMdSpi* pMdApi, CThostFtdcMdSpi* pSpi)
{
    return pMdApi->RegisterSpi(pSpi);
}

// 订阅行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_CThostFtdcMdApi_SubscribeMarketData(QCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->SubscribeMarketData(ppInstrumentID, nCount);
}

// 退订行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_CThostFtdcMdApi_UnSubscribeMarketData(QCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

// 订阅询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_CThostFtdcMdApi_SubscribeForQuoteRsp(QCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 退订询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_CThostFtdcMdApi_UnSubscribeForQuoteRsp(QCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 用户登录请求
int _wrap_CThostFtdcMdApi_ReqUserLogin(QCTPMdSpi* pMdApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    int ret = pMdApi->ReqUserLogin(pReqUserLoginField, nRequestID);
    printf("req_user_login: %d", ret);
    return ret;
}

// 登出请求
int _wrap_CThostFtdcMdApi_ReqUserLogout(QCTPMdSpi* pMdApi, CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return pMdApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 请求查询组播合约
int _wrap_CThostFtdcMdApi_ReqQryMulticastInstrument(QCTPMdSpi* pMdApi, CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID)
{
    return pMdApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}

#ifdef __cplusplus
}
#endif

// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
extern "C" void wrapMdOnFrontConnected(uintptr_t);
void QCTPMdSpi::OnFrontConnected()
{
    wrapMdOnFrontConnected(gUserApi);
}

// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
extern "C" void wrapMdOnFrontDisconnected(uintptr_t, int);
void QCTPMdSpi::OnFrontDisconnected(int nReason)
{
    wrapMdOnFrontDisconnected(gUserApi, nReason);
}

// 心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
extern "C" void wrapMdOnHeartBeatWarning(uintptr_t, int);
void QCTPMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
    wrapMdOnHeartBeatWarning(gUserApi, nTimeLapse);
}

// 登录请求响应
extern "C" void wrapMdOnRspUserLogin(uintptr_t, CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUserLogin(gUserApi, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

// 登出请求响应
extern "C" void wrapMdOnRspUserLogout(uintptr_t, CThostFtdcUserLogoutField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUserLogout(gUserApi, pUserLogout, pRspInfo, nRequestID, bIsLast);
}

// 请求查询组播合约响应
extern "C" void wrapMdOnRspQryMulticastInstrument(uintptr_t, CThostFtdcMulticastInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspQryMulticastInstrument(gUserApi, pMulticastInstrument, pRspInfo, nRequestID, bIsLast);
}

// 错误应答
extern "C" void wrapMdOnRspError(uintptr_t, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspError(gUserApi, pRspInfo, nRequestID, bIsLast);
}

// 订阅行情应答
extern "C" void wrapMdOnRspSubMarketData(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspSubMarketData(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 取消订阅行情应答
extern "C" void wrapMdOnRspUnSubMarketData(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUnSubMarketData(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 订阅询价应答
extern "C" void wrapMdOnRspSubForQuoteRsp(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspSubForQuoteRsp(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 取消订阅询价应答
extern "C" void wrapMdOnRspUnSubForQuoteRsp(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUnSubForQuoteRsp(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 深度行情通知
extern "C" void wrapMdOnRtnDepthMarketData(uintptr_t, CThostFtdcDepthMarketDataField*);
void QCTPMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
    wrapMdOnRtnDepthMarketData(gUserApi, pDepthMarketData);
}

// 询价通知
extern "C" void wrapMdOnRtnForQuoteRsp(uintptr_t, CThostFtdcForQuoteRspField*);
void QCTPMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    wrapMdOnRtnForQuoteRsp(gUserApi, pForQuoteRsp);
}

QCTPMdSpi::QCTPMdSpi(CThostFtdcMdApi* pUserApi)
{
    this->pUserApi = pUserApi;
}

QCTPMdSpi::QCTPMdSpi(CThostFtdcMdApi* pUserApi, uintptr_t gUserApi)
{
    this->pUserApi = pUserApi;
    this->gUserApi = gUserApi;
}

uintptr_t _wrap_CThostFtdcMdApi_DestroyUserMdApi(QCTPMdSpi* pMdApi)
{
    delete (pMdApi);
    return 0;
}

// 获取API的版本信息
///@retrun 获取到的版本号
const char* QCTPMdSpi::GetApiVersion()
{
    return this->pUserApi->GetApiVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void QCTPMdSpi::Release()
{
    this->pUserApi->RegisterSpi(NULL);
    return this->pUserApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void QCTPMdSpi::Init()
{
    this->pUserApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int QCTPMdSpi::Join()
{
    return this->pUserApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* QCTPMdSpi::GetTradingDay()
{
    return this->pUserApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void QCTPMdSpi::RegisterFront(char* pszFrontAddress)
{
    this->pUserApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void QCTPMdSpi::RegisterNameServer(char* pszNsAddress)
{
    this->pUserApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void QCTPMdSpi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
    this->pUserApi->RegisterFensUserInfo(pFensUserInfo);
}

// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void QCTPMdSpi::RegisterSpi(CThostFtdcMdSpi* pSpi)
{
    this->pUserApi->RegisterSpi(pSpi);
}

// 订阅行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int QCTPMdSpi::SubscribeMarketData(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->SubscribeMarketData(ppInstrumentID, nCount);
}

// 退订行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int QCTPMdSpi::UnSubscribeMarketData(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

// 订阅询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int QCTPMdSpi::SubscribeForQuoteRsp(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 退订询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int QCTPMdSpi::UnSubscribeForQuoteRsp(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 用户登录请求
int QCTPMdSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

// 登出请求
int QCTPMdSpi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return this->pUserApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 请求查询组播合约
int QCTPMdSpi::ReqQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}
