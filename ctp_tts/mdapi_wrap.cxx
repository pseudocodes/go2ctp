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
#include <stdint.h>
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

#include "mdapi_wrap.h"

const char* MdApiCreateSymbol = "_ZN15CThostFtdcMdApi15CreateFtdcMdApiEPKcbb";
const char* MdApiVersionSymbol = "_ZN15CThostFtdcMdApi13GetApiVersionEv";

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
TTSCTPMdSpi* _wrap_tts_CThostFtdcMdApi_CreateFtdcMdApi()
{
    // CThostFtdcMdApi* pUserApi = CThostFtdcMdApi::CreateFtdcMdApi("./data/", false);
    // TTSCTPMdSpi* pUserSpi = new TTSCTPMdSpi(pUserApi);
    // pUserSpi->RegisterSpi(pUserSpi);
    // return pUserSpi;
    return nullptr;
}

TTSCTPMdSpi* _wrap_tts_CThostFtdcMdApi_CreateFtdcMdApi2(uintptr_t gUserApi, const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
{
    // printf("go_user_api %lu\n", gUserApi);
    // CThostFtdcMdApi* pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
    // TTSCTPMdSpi* pUserSpi = new TTSCTPMdSpi(pUserApi, gUserApi);
    // TTSCTPMdSpi* pUserSpi = new TTSCTPMdSpi(gUserApi, pszDLLPath, pszFlowPath, bIsUsingUdp, bIsMulticast);
    // pUserSpi->RegisterSpi(pUserSpi);
    return nullptr;
}

TTSCTPMdSpi* _wrap_tts_CThostFtdcMdApi_CreateFtdcMdApi3(uintptr_t gUserApi, const char* pszDLLPath, const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
{
    // printf("go_user_api %lu\n", gUserApi);
    // CThostFtdcMdApi* pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
    // TTSCTPMdSpi* pUserSpi = new TTSCTPMdSpi(pUserApi, gUserApi);
    TTSCTPMdSpi* pUserSpi = new TTSCTPMdSpi(gUserApi, pszDLLPath, pszFlowPath, bIsUsingUdp, bIsMulticast);
    pUserSpi->RegisterSpi(pUserSpi);
    return pUserSpi;
}

// 获取API的版本信息
///@retrun 获取到的版本号
const char* _wrap_tts_CThostFtdcMdApi_GetApiVersion(TTSCTPMdSpi* pMdApi)
{
    return pMdApi->GetApiVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void _wrap_tts_CThostFtdcMdApi_Release(TTSCTPMdSpi* pMdApi)
{
    return pMdApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void _wrap_tts_CThostFtdcMdApi_Init(TTSCTPMdSpi* pMdApi)
{
    return pMdApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int _wrap_tts_CThostFtdcMdApi_Join(TTSCTPMdSpi* pMdApi)
{
    return pMdApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* _wrap_tts_CThostFtdcMdApi_GetTradingDay(TTSCTPMdSpi* pMdApi)
{
    return pMdApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void _wrap_tts_CThostFtdcMdApi_RegisterFront(TTSCTPMdSpi* pMdApi, char* pszFrontAddress)
{
    return pMdApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void _wrap_tts_CThostFtdcMdApi_RegisterNameServer(TTSCTPMdSpi* pMdApi, char* pszNsAddress)
{
    return pMdApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void _wrap_tts_CThostFtdcMdApi_RegisterFensUserInfo(TTSCTPMdSpi* pMdApi, CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return pMdApi->RegisterFensUserInfo(pFensUserInfo);
}

// 订阅行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_tts_CThostFtdcMdApi_SubscribeMarketData(TTSCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->SubscribeMarketData(ppInstrumentID, nCount);
}

// 退订行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_tts_CThostFtdcMdApi_UnSubscribeMarketData(TTSCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

// 订阅询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_tts_CThostFtdcMdApi_SubscribeForQuoteRsp(TTSCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 退订询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int _wrap_tts_CThostFtdcMdApi_UnSubscribeForQuoteRsp(TTSCTPMdSpi* pMdApi, char** ppInstrumentID, int nCount)
{
    return pMdApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 用户登录请求
int _wrap_tts_CThostFtdcMdApi_ReqUserLogin(TTSCTPMdSpi* pMdApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    int ret = pMdApi->ReqUserLogin(pReqUserLoginField, nRequestID);
    printf("req_user_login: %d", ret);
    return ret;
}

// 登出请求
int _wrap_tts_CThostFtdcMdApi_ReqUserLogout(TTSCTPMdSpi* pMdApi, CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return pMdApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 请求查询组播合约
int _wrap_tts_CThostFtdcMdApi_ReqQryMulticastInstrument(TTSCTPMdSpi* pMdApi, CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID)
{
    return pMdApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}

#ifdef __cplusplus
}
#endif

// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
extern "C" void wrap_tts_MdOnFrontConnected(uintptr_t);
void TTSCTPMdSpi::OnFrontConnected()
{
    wrap_tts_MdOnFrontConnected(gUserApi);
}

// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
extern "C" void wrap_tts_MdOnFrontDisconnected(uintptr_t, int);
void TTSCTPMdSpi::OnFrontDisconnected(int nReason)
{
    wrap_tts_MdOnFrontDisconnected(gUserApi, nReason);
}

// 心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
extern "C" void wrap_tts_MdOnHeartBeatWarning(uintptr_t, int);
void TTSCTPMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
    wrap_tts_MdOnHeartBeatWarning(gUserApi, nTimeLapse);
}

// 登录请求响应
extern "C" void wrap_tts_MdOnRspUserLogin(uintptr_t, CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspUserLogin(gUserApi, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

// 登出请求响应
extern "C" void wrap_tts_MdOnRspUserLogout(uintptr_t, CThostFtdcUserLogoutField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspUserLogout(gUserApi, pUserLogout, pRspInfo, nRequestID, bIsLast);
}

// 请求查询组播合约响应
extern "C" void wrap_tts_MdOnRspQryMulticastInstrument(uintptr_t, CThostFtdcMulticastInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspQryMulticastInstrument(gUserApi, pMulticastInstrument, pRspInfo, nRequestID, bIsLast);
}

// 错误应答
extern "C" void wrap_tts_MdOnRspError(uintptr_t, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspError(gUserApi, pRspInfo, nRequestID, bIsLast);
}

// 订阅行情应答
extern "C" void wrap_tts_MdOnRspSubMarketData(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspSubMarketData(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 取消订阅行情应答
extern "C" void wrap_tts_MdOnRspUnSubMarketData(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspUnSubMarketData(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 订阅询价应答
extern "C" void wrap_tts_MdOnRspSubForQuoteRsp(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspSubForQuoteRsp(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 取消订阅询价应答
extern "C" void wrap_tts_MdOnRspUnSubForQuoteRsp(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void TTSCTPMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrap_tts_MdOnRspUnSubForQuoteRsp(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

// 深度行情通知
extern "C" void wrap_tts_MdOnRtnDepthMarketData(uintptr_t, CThostFtdcDepthMarketDataField*);
void TTSCTPMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
    wrap_tts_MdOnRtnDepthMarketData(gUserApi, pDepthMarketData);
}

// 询价通知
extern "C" void wrap_tts_MdOnRtnForQuoteRsp(uintptr_t, CThostFtdcForQuoteRspField*);
void TTSCTPMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    wrap_tts_MdOnRtnForQuoteRsp(gUserApi, pForQuoteRsp);
}

TTSCTPMdSpi::TTSCTPMdSpi(CThostFtdcMdApi* pUserApi)
{
    this->pUserApi = pUserApi;
}

TTSCTPMdSpi::TTSCTPMdSpi(CThostFtdcMdApi* pUserApi, uintptr_t gUserApi)
{
    this->pUserApi = pUserApi;
    this->gUserApi = gUserApi;
}

TTSCTPMdSpi::TTSCTPMdSpi(uintptr_t gUserApi, const char* pszDLLPath, const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast)
{
    typedef CThostFtdcMdApi* (*MdApiCreator)(const char*, const bool, const bool);
    dllHandle = dlopen(pszDLLPath, RTLD_NOW);
    if (dllHandle == nullptr) {
        fprintf(stderr, "[%s] dlopen error: %s\n", pszDLLPath, dlerror());
        exit(-1);
    }
    MdApiCreator mdcreator = (MdApiCreator)dlsym(dllHandle, MdApiCreateSymbol);
    if (mdcreator == nullptr) {
        fprintf(stderr, "[%s] dlsym error: %s\n", pszDLLPath, dlerror());
        exit(-1);
    }
    this->pUserApi = mdcreator(pszFlowPath, bIsUsingUdp, bIsMulticast);
    this->gUserApi = gUserApi;
}

TTSCTPMdSpi::~TTSCTPMdSpi()
{
    if (this->pUserApi) {
        this->pUserApi->RegisterSpi(nullptr);
        this->pUserApi->Release();
        this->pUserApi = nullptr;
        dlclose(dllHandle);
    }
}

uintptr_t _wrap_tts_CThostFtdcMdApi_DestroyUserMdApi(TTSCTPMdSpi* pMdApi)
{
    delete (pMdApi);
    return 0;
}

// 获取API的版本信息
///@retrun 获取到的版本号
const char* TTSCTPMdSpi::GetApiVersion()
{
    typedef const char* (*GetApiVersion)();
    GetApiVersion getVersion = (GetApiVersion)dlsym(this->dllHandle, MdApiVersionSymbol);
    // return this->pUserApi->GetApiVersion();
    return getVersion();
}

// 删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void TTSCTPMdSpi::Release()
{
    this->pUserApi->RegisterSpi(NULL);
    return this->pUserApi->Release();
}

// 初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void TTSCTPMdSpi::Init()
{
    this->pUserApi->Init();
}

// 等待接口线程结束运行
///@return 线程退出代码
int TTSCTPMdSpi::Join()
{
    return this->pUserApi->Join();
}

// 获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* TTSCTPMdSpi::GetTradingDay()
{
    return this->pUserApi->GetTradingDay();
}

// 注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void TTSCTPMdSpi::RegisterFront(char* pszFrontAddress)
{
    this->pUserApi->RegisterFront(pszFrontAddress);
}

// 注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void TTSCTPMdSpi::RegisterNameServer(char* pszNsAddress)
{
    this->pUserApi->RegisterNameServer(pszNsAddress);
}

// 注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void TTSCTPMdSpi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
    this->pUserApi->RegisterFensUserInfo(pFensUserInfo);
}

// 注册回调接口
///@param pSpi 派生自回调接口类的实例
void TTSCTPMdSpi::RegisterSpi(CThostFtdcMdSpi* pSpi)
{
    this->pUserApi->RegisterSpi(pSpi);
}

// 订阅行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int TTSCTPMdSpi::SubscribeMarketData(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->SubscribeMarketData(ppInstrumentID, nCount);
}

// 退订行情。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int TTSCTPMdSpi::UnSubscribeMarketData(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

// 订阅询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int TTSCTPMdSpi::SubscribeForQuoteRsp(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 退订询价。
///@param ppInstrumentID 合约ID
///@param nCount 要订阅/退订行情的合约个数
///@remark
int TTSCTPMdSpi::UnSubscribeForQuoteRsp(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

// 用户登录请求
int TTSCTPMdSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

// 登出请求
int TTSCTPMdSpi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return this->pUserApi->ReqUserLogout(pUserLogout, nRequestID);
}

// 请求查询组播合约
int TTSCTPMdSpi::ReqQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}
