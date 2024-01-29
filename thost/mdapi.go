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

package thost

type MdSpi interface {

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	OnFrontConnected()

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	OnFrontDisconnected(nReason int)

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	OnHeartBeatWarning(nTimeLapse int)

	///登录请求响应
	OnRspUserLogin(pRspUserLogin *CThostFtdcRspUserLoginField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///登出请求响应
	OnRspUserLogout(pUserLogout *CThostFtdcUserLogoutField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询组播合约响应
	OnRspQryMulticastInstrument(pMulticastInstrument *CThostFtdcMulticastInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///错误应答
	OnRspError(pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///订阅行情应答
	OnRspSubMarketData(pSpecificInstrument *CThostFtdcSpecificInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///取消订阅行情应答
	OnRspUnSubMarketData(pSpecificInstrument *CThostFtdcSpecificInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///订阅询价应答
	OnRspSubForQuoteRsp(pSpecificInstrument *CThostFtdcSpecificInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///取消订阅询价应答
	OnRspUnSubForQuoteRsp(pSpecificInstrument *CThostFtdcSpecificInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///深度行情通知
	OnRtnDepthMarketData(pDepthMarketData *CThostFtdcDepthMarketDataField)

	///询价通知
	OnRtnForQuoteRsp(pForQuoteRsp *CThostFtdcForQuoteRspField)
}

type MdApi interface {

	///获取API的版本信息
	///@retrun 获取到的版本号
	GetApiVersion() string

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	Release()

	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	Init()

	///等待接口线程结束运行
	///@return 线程退出代码
	Join() int

	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	GetTradingDay() string

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	RegisterFront(frontAddress string)

	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterNameServer优先于RegisterFront
	RegisterNameServer(nsAddress string)

	///注册名字服务器用户信息
	///@param pFensUserInfo：用户信息。
	RegisterFensUserInfo(pFensUserInfo *CThostFtdcFensUserInfoField)

	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	RegisterSpi(pSpi MdSpi)

	///订阅行情。
	///@param ppInstrumentID 合约ID
	///@param nCount 要订阅/退订行情的合约个数
	///@remark
	SubscribeMarketData(instrumentIDs ...string) int

	///退订行情。
	///@param ppInstrumentID 合约ID
	///@param nCount 要订阅/退订行情的合约个数
	///@remark
	UnSubscribeMarketData(instrumentIDs ...string) int

	///订阅询价。
	///@param ppInstrumentID 合约ID
	///@param nCount 要订阅/退订行情的合约个数
	///@remark
	SubscribeForQuoteRsp(instrumentIDs ...string) int

	///退订询价。
	///@param ppInstrumentID 合约ID
	///@param nCount 要订阅/退订行情的合约个数
	///@remark
	UnSubscribeForQuoteRsp(instrumentIDs ...string) int

	///用户登录请求
	ReqUserLogin(pReqUserLoginField *CThostFtdcReqUserLoginField, nRequestID int) int

	///登出请求
	ReqUserLogout(pUserLogout *CThostFtdcUserLogoutField, nRequestID int) int

	///请求查询组播合约
	ReqQryMulticastInstrument(pQryMulticastInstrument *CThostFtdcQryMulticastInstrumentField, nRequestID int) int
}
