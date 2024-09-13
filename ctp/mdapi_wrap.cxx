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

const char* _wrap_CThostFtdcMdApi_GetApiVersion(QCTPMdSpi* ptr)
{
    return ptr->GetApiVersion();
}

void _wrap_CThostFtdcMdApi_Release(QCTPMdSpi* ptr)
{
    return ptr->Release();
}

void _wrap_CThostFtdcMdApi_Init(QCTPMdSpi* ptr)
{
    return ptr->Init();
}

int _wrap_CThostFtdcMdApi_Join(QCTPMdSpi* ptr)
{
    return ptr->Join();
}

const char* _wrap_CThostFtdcMdApi_GetTradingDay(QCTPMdSpi* ptr)
{
    return ptr->GetTradingDay();
}

void _wrap_CThostFtdcMdApi_RegisterFront(QCTPMdSpi* ptr, char* pszFrontAddress)
{
    return ptr->RegisterFront(pszFrontAddress);
}

void _wrap_CThostFtdcMdApi_RegisterNameServer(QCTPMdSpi* ptr, char* pszNsAddress)
{
    return ptr->RegisterNameServer(pszNsAddress);
}

void _wrap_CThostFtdcMdApi_RegisterFensUserInfo(QCTPMdSpi* ptr, CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return ptr->RegisterFensUserInfo(pFensUserInfo);
}

void _wrap_CThostFtdcMdApi_RegisterSpi(QCTPMdSpi* ptr, CThostFtdcMdSpi* pSpi)
{
    return ptr->RegisterSpi(pSpi);
}

int _wrap_CThostFtdcMdApi_SubscribeMarketData(QCTPMdSpi* ptr, char** ppInstrumentID, int nCount)
{
    return ptr->SubscribeMarketData(ppInstrumentID, nCount);
}

int _wrap_CThostFtdcMdApi_UnSubscribeMarketData(QCTPMdSpi* ptr, char** ppInstrumentID, int nCount)
{
    return ptr->UnSubscribeMarketData(ppInstrumentID, nCount);
}

int _wrap_CThostFtdcMdApi_SubscribeForQuoteRsp(QCTPMdSpi* ptr, char** ppInstrumentID, int nCount)
{
    return ptr->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

int _wrap_CThostFtdcMdApi_UnSubscribeForQuoteRsp(QCTPMdSpi* ptr, char** ppInstrumentID, int nCount)
{
    return ptr->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

int _wrap_CThostFtdcMdApi_ReqUserLogin(QCTPMdSpi* ptr, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return ptr->ReqUserLogin(pReqUserLoginField, nRequestID);
}

int _wrap_CThostFtdcMdApi_ReqUserLogout(QCTPMdSpi* ptr, CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return ptr->ReqUserLogout(pUserLogout, nRequestID);
}

int _wrap_CThostFtdcMdApi_ReqQryMulticastInstrument(QCTPMdSpi* ptr, CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID)
{
    return ptr->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}

#ifdef __cplusplus
}
#endif

extern "C" void wrapMdOnFrontConnected(uintptr_t);
void QCTPMdSpi::OnFrontConnected()
{
    wrapMdOnFrontConnected(gUserApi);
}

extern "C" void wrapMdOnFrontDisconnected(uintptr_t, int);
void QCTPMdSpi::OnFrontDisconnected(int nReason)
{
    wrapMdOnFrontDisconnected(gUserApi, nReason);
}

extern "C" void wrapMdOnHeartBeatWarning(uintptr_t, int);
void QCTPMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
    wrapMdOnHeartBeatWarning(gUserApi, nTimeLapse);
}

extern "C" void wrapMdOnRspUserLogin(uintptr_t, CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUserLogin(gUserApi, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspUserLogout(uintptr_t, CThostFtdcUserLogoutField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUserLogout(gUserApi, pUserLogout, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspQryMulticastInstrument(uintptr_t, CThostFtdcMulticastInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspQryMulticastInstrument(gUserApi, pMulticastInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspError(uintptr_t, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspError(gUserApi, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspSubMarketData(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspSubMarketData(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspUnSubMarketData(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUnSubMarketData(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspSubForQuoteRsp(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspSubForQuoteRsp(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRspUnSubForQuoteRsp(uintptr_t, CThostFtdcSpecificInstrumentField*, CThostFtdcRspInfoField*, int, bool);
void QCTPMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    wrapMdOnRspUnSubForQuoteRsp(gUserApi, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

extern "C" void wrapMdOnRtnDepthMarketData(uintptr_t, CThostFtdcDepthMarketDataField*);
void QCTPMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
    wrapMdOnRtnDepthMarketData(gUserApi, pDepthMarketData);
}

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

const char* QCTPMdSpi::GetApiVersion()
{
    return this->pUserApi->GetApiVersion();
}

void QCTPMdSpi::Release()
{
    return this->pUserApi->Release();
}

void QCTPMdSpi::Init()
{
    return this->pUserApi->Init();
}

int QCTPMdSpi::Join()
{
    return this->pUserApi->Join();
}

const char* QCTPMdSpi::GetTradingDay()
{
    return this->pUserApi->GetTradingDay();
}

void QCTPMdSpi::RegisterFront(char* pszFrontAddress)
{
    return this->pUserApi->RegisterFront(pszFrontAddress);
}

void QCTPMdSpi::RegisterNameServer(char* pszNsAddress)
{
    return this->pUserApi->RegisterNameServer(pszNsAddress);
}

void QCTPMdSpi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
    return this->pUserApi->RegisterFensUserInfo(pFensUserInfo);
}

void QCTPMdSpi::RegisterSpi(CThostFtdcMdSpi* pSpi)
{
    return this->pUserApi->RegisterSpi(pSpi);
}

int QCTPMdSpi::SubscribeMarketData(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->SubscribeMarketData(ppInstrumentID, nCount);
}

int QCTPMdSpi::UnSubscribeMarketData(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

int QCTPMdSpi::SubscribeForQuoteRsp(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

int QCTPMdSpi::UnSubscribeForQuoteRsp(char** ppInstrumentID, int nCount)
{
    return this->pUserApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

int QCTPMdSpi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID)
{
    return this->pUserApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

int QCTPMdSpi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID)
{
    return this->pUserApi->ReqUserLogout(pUserLogout, nRequestID);
}

int QCTPMdSpi::ReqQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID)
{
    return this->pUserApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}
