// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MDAPI_WRAP_H_
#define _MDAPI_WRAP_H_

#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"

class QCTPMdSpi : public CThostFtdcMdSpi {
public:
    QCTPMdSpi(CThostFtdcMdApi* pUserApi);
    QCTPMdSpi(CThostFtdcMdApi* pUserApi, uintptr_t gUserApi);
    QCTPMdSpi();

    /// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    void OnFrontConnected();

    /// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    ///@param nReason 错误原因
    ///         0x1001 网络读失败
    ///         0x1002 网络写失败
    ///         0x2001 接收心跳超时
    ///         0x2002 发送心跳失败
    ///         0x2003 收到错误报文
    void OnFrontDisconnected(int nReason);

    /// 心跳超时警告。当长时间未收到报文时，该方法被调用。
    ///@param nTimeLapse 距离上次接收报文的时间
    void OnHeartBeatWarning(int nTimeLapse);

    /// 登录请求响应
    void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 登出请求响应
    void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 请求查询组播合约响应
    void OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 错误应答
    void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 订阅行情应答
    void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 取消订阅行情应答
    void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 订阅询价应答
    void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 取消订阅询价应答
    void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    /// 深度行情通知
    void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData);

    /// 询价通知
    void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp);

    /// 获取API的版本信息
    ///@retrun 获取到的版本号
    const char* GetApiVersion();

    /// 删除接口对象本身
    ///@remark 不再使用本接口对象时,调用该函数删除接口对象
    void Release();

    /// 初始化
    ///@remark 初始化运行环境,只有调用后,接口才开始工作
    void Init();

    /// 等待接口线程结束运行
    ///@return 线程退出代码
    int Join();

    /// 获取当前交易日
    ///@retrun 获取到的交易日
    ///@remark 只有登录成功后,才能得到正确的交易日
    const char* GetTradingDay();

    /// 注册前置机网络地址
    ///@param pszFrontAddress：前置机网络地址。
    ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
    ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
    void RegisterFront(char* pszFrontAddress);

    /// 注册名字服务器网络地址
    ///@param pszNsAddress：名字服务器网络地址。
    ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
    ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
    ///@remark RegisterNameServer优先于RegisterFront
    void RegisterNameServer(char* pszNsAddress);

    /// 注册名字服务器用户信息
    ///@param pFensUserInfo：用户信息。
    void RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo);

    /// 注册回调接口
    ///@param pSpi 派生自回调接口类的实例
    void RegisterSpi(CThostFtdcMdSpi* pSpi);

    /// 订阅行情。
    ///@param ppInstrumentID 合约ID
    ///@param nCount 要订阅/退订行情的合约个数
    ///@remark
    int SubscribeMarketData(char** ppInstrumentID, int nCount);

    /// 退订行情。
    ///@param ppInstrumentID 合约ID
    ///@param nCount 要订阅/退订行情的合约个数
    ///@remark
    int UnSubscribeMarketData(char** ppInstrumentID, int nCount);

    /// 订阅询价。
    ///@param ppInstrumentID 合约ID
    ///@param nCount 要订阅/退订行情的合约个数
    ///@remark
    int SubscribeForQuoteRsp(char** ppInstrumentID, int nCount);

    /// 退订询价。
    ///@param ppInstrumentID 合约ID
    ///@param nCount 要订阅/退订行情的合约个数
    ///@remark
    int UnSubscribeForQuoteRsp(char** ppInstrumentID, int nCount);

    /// 用户登录请求
    int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);

    /// 登出请求
    int ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID);

    /// 请求查询组播合约
    int ReqQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID);

private:
    CThostFtdcMdApi* pUserApi;
    uintptr_t gUserApi;
};

#endif // end _MDAPI_WRAP_H_
