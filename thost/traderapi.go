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

package thost

type TraderSpi interface {

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

	///客户端认证响应
	OnRspAuthenticate(pRspAuthenticateField *CThostFtdcRspAuthenticateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///登录请求响应
	OnRspUserLogin(pRspUserLogin *CThostFtdcRspUserLoginField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///登出请求响应
	OnRspUserLogout(pUserLogout *CThostFtdcUserLogoutField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///用户口令更新请求响应
	OnRspUserPasswordUpdate(pUserPasswordUpdate *CThostFtdcUserPasswordUpdateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///资金账户口令更新请求响应
	OnRspTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate *CThostFtdcTradingAccountPasswordUpdateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///查询用户当前支持的认证模式的回复
	OnRspUserAuthMethod(pRspUserAuthMethod *CThostFtdcRspUserAuthMethodField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///获取图形验证码请求的回复
	OnRspGenUserCaptcha(pRspGenUserCaptcha *CThostFtdcRspGenUserCaptchaField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///获取短信验证码请求的回复
	OnRspGenUserText(pRspGenUserText *CThostFtdcRspGenUserTextField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///报单录入请求响应
	OnRspOrderInsert(pInputOrder *CThostFtdcInputOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///预埋单录入请求响应
	OnRspParkedOrderInsert(pParkedOrder *CThostFtdcParkedOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///预埋撤单录入请求响应
	OnRspParkedOrderAction(pParkedOrderAction *CThostFtdcParkedOrderActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///报单操作请求响应
	OnRspOrderAction(pInputOrderAction *CThostFtdcInputOrderActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///查询最大报单数量响应
	OnRspQryMaxOrderVolume(pQryMaxOrderVolume *CThostFtdcQryMaxOrderVolumeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///投资者结算结果确认响应
	OnRspSettlementInfoConfirm(pSettlementInfoConfirm *CThostFtdcSettlementInfoConfirmField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///删除预埋单响应
	OnRspRemoveParkedOrder(pRemoveParkedOrder *CThostFtdcRemoveParkedOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///删除预埋撤单响应
	OnRspRemoveParkedOrderAction(pRemoveParkedOrderAction *CThostFtdcRemoveParkedOrderActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///执行宣告录入请求响应
	OnRspExecOrderInsert(pInputExecOrder *CThostFtdcInputExecOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///执行宣告操作请求响应
	OnRspExecOrderAction(pInputExecOrderAction *CThostFtdcInputExecOrderActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///询价录入请求响应
	OnRspForQuoteInsert(pInputForQuote *CThostFtdcInputForQuoteField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///报价录入请求响应
	OnRspQuoteInsert(pInputQuote *CThostFtdcInputQuoteField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///报价操作请求响应
	OnRspQuoteAction(pInputQuoteAction *CThostFtdcInputQuoteActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///批量报单操作请求响应
	OnRspBatchOrderAction(pInputBatchOrderAction *CThostFtdcInputBatchOrderActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///期权自对冲录入请求响应
	OnRspOptionSelfCloseInsert(pInputOptionSelfClose *CThostFtdcInputOptionSelfCloseField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///期权自对冲操作请求响应
	OnRspOptionSelfCloseAction(pInputOptionSelfCloseAction *CThostFtdcInputOptionSelfCloseActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///申请组合录入请求响应
	OnRspCombActionInsert(pInputCombAction *CThostFtdcInputCombActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询报单响应
	OnRspQryOrder(pOrder *CThostFtdcOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询成交响应
	OnRspQryTrade(pTrade *CThostFtdcTradeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资者持仓响应
	OnRspQryInvestorPosition(pInvestorPosition *CThostFtdcInvestorPositionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询资金账户响应
	OnRspQryTradingAccount(pTradingAccount *CThostFtdcTradingAccountField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资者响应
	OnRspQryInvestor(pInvestor *CThostFtdcInvestorField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询交易编码响应
	OnRspQryTradingCode(pTradingCode *CThostFtdcTradingCodeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询合约保证金率响应
	OnRspQryInstrumentMarginRate(pInstrumentMarginRate *CThostFtdcInstrumentMarginRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询合约手续费率响应
	OnRspQryInstrumentCommissionRate(pInstrumentCommissionRate *CThostFtdcInstrumentCommissionRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询交易所响应
	OnRspQryExchange(pExchange *CThostFtdcExchangeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询产品响应
	OnRspQryProduct(pProduct *CThostFtdcProductField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询合约响应
	OnRspQryInstrument(pInstrument *CThostFtdcInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询行情响应
	OnRspQryDepthMarketData(pDepthMarketData *CThostFtdcDepthMarketDataField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资者结算结果响应
	OnRspQrySettlementInfo(pSettlementInfo *CThostFtdcSettlementInfoField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询转帐银行响应
	OnRspQryTransferBank(pTransferBank *CThostFtdcTransferBankField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资者持仓明细响应
	OnRspQryInvestorPositionDetail(pInvestorPositionDetail *CThostFtdcInvestorPositionDetailField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询客户通知响应
	OnRspQryNotice(pNotice *CThostFtdcNoticeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询结算信息确认响应
	OnRspQrySettlementInfoConfirm(pSettlementInfoConfirm *CThostFtdcSettlementInfoConfirmField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资者持仓明细响应
	OnRspQryInvestorPositionCombineDetail(pInvestorPositionCombineDetail *CThostFtdcInvestorPositionCombineDetailField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///查询保证金监管系统经纪公司资金账户密钥响应
	OnRspQryCFMMCTradingAccountKey(pCFMMCTradingAccountKey *CThostFtdcCFMMCTradingAccountKeyField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询仓单折抵信息响应
	OnRspQryEWarrantOffset(pEWarrantOffset *CThostFtdcEWarrantOffsetField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资者品种/跨品种保证金响应
	OnRspQryInvestorProductGroupMargin(pInvestorProductGroupMargin *CThostFtdcInvestorProductGroupMarginField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询交易所保证金率响应
	OnRspQryExchangeMarginRate(pExchangeMarginRate *CThostFtdcExchangeMarginRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询交易所调整保证金率响应
	OnRspQryExchangeMarginRateAdjust(pExchangeMarginRateAdjust *CThostFtdcExchangeMarginRateAdjustField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询汇率响应
	OnRspQryExchangeRate(pExchangeRate *CThostFtdcExchangeRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询二级代理操作员银期权限响应
	OnRspQrySecAgentACIDMap(pSecAgentACIDMap *CThostFtdcSecAgentACIDMapField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询产品报价汇率
	OnRspQryProductExchRate(pProductExchRate *CThostFtdcProductExchRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询产品组
	OnRspQryProductGroup(pProductGroup *CThostFtdcProductGroupField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询做市商合约手续费率响应
	OnRspQryMMInstrumentCommissionRate(pMMInstrumentCommissionRate *CThostFtdcMMInstrumentCommissionRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询做市商期权合约手续费响应
	OnRspQryMMOptionInstrCommRate(pMMOptionInstrCommRate *CThostFtdcMMOptionInstrCommRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询报单手续费响应
	OnRspQryInstrumentOrderCommRate(pInstrumentOrderCommRate *CThostFtdcInstrumentOrderCommRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询资金账户响应
	OnRspQrySecAgentTradingAccount(pTradingAccount *CThostFtdcTradingAccountField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询二级代理商资金校验模式响应
	OnRspQrySecAgentCheckMode(pSecAgentCheckMode *CThostFtdcSecAgentCheckModeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询二级代理商信息响应
	OnRspQrySecAgentTradeInfo(pSecAgentTradeInfo *CThostFtdcSecAgentTradeInfoField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询期权交易成本响应
	OnRspQryOptionInstrTradeCost(pOptionInstrTradeCost *CThostFtdcOptionInstrTradeCostField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询期权合约手续费响应
	OnRspQryOptionInstrCommRate(pOptionInstrCommRate *CThostFtdcOptionInstrCommRateField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询执行宣告响应
	OnRspQryExecOrder(pExecOrder *CThostFtdcExecOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询询价响应
	OnRspQryForQuote(pForQuote *CThostFtdcForQuoteField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询报价响应
	OnRspQryQuote(pQuote *CThostFtdcQuoteField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询期权自对冲响应
	OnRspQryOptionSelfClose(pOptionSelfClose *CThostFtdcOptionSelfCloseField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询投资单元响应
	OnRspQryInvestUnit(pInvestUnit *CThostFtdcInvestUnitField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询组合合约安全系数响应
	OnRspQryCombInstrumentGuard(pCombInstrumentGuard *CThostFtdcCombInstrumentGuardField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询申请组合响应
	OnRspQryCombAction(pCombAction *CThostFtdcCombActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询转帐流水响应
	OnRspQryTransferSerial(pTransferSerial *CThostFtdcTransferSerialField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询银期签约关系响应
	OnRspQryAccountregister(pAccountregister *CThostFtdcAccountregisterField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///错误应答
	OnRspError(pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///报单通知
	OnRtnOrder(pOrder *CThostFtdcOrderField)

	///成交通知
	OnRtnTrade(pTrade *CThostFtdcTradeField)

	///报单录入错误回报
	OnErrRtnOrderInsert(pInputOrder *CThostFtdcInputOrderField, pRspInfo *CThostFtdcRspInfoField)

	///报单操作错误回报
	OnErrRtnOrderAction(pOrderAction *CThostFtdcOrderActionField, pRspInfo *CThostFtdcRspInfoField)

	///合约交易状态通知
	OnRtnInstrumentStatus(pInstrumentStatus *CThostFtdcInstrumentStatusField)

	///交易所公告通知
	OnRtnBulletin(pBulletin *CThostFtdcBulletinField)

	///交易通知
	OnRtnTradingNotice(pTradingNoticeInfo *CThostFtdcTradingNoticeInfoField)

	///提示条件单校验错误
	OnRtnErrorConditionalOrder(pErrorConditionalOrder *CThostFtdcErrorConditionalOrderField)

	///执行宣告通知
	OnRtnExecOrder(pExecOrder *CThostFtdcExecOrderField)

	///执行宣告录入错误回报
	OnErrRtnExecOrderInsert(pInputExecOrder *CThostFtdcInputExecOrderField, pRspInfo *CThostFtdcRspInfoField)

	///执行宣告操作错误回报
	OnErrRtnExecOrderAction(pExecOrderAction *CThostFtdcExecOrderActionField, pRspInfo *CThostFtdcRspInfoField)

	///询价录入错误回报
	OnErrRtnForQuoteInsert(pInputForQuote *CThostFtdcInputForQuoteField, pRspInfo *CThostFtdcRspInfoField)

	///报价通知
	OnRtnQuote(pQuote *CThostFtdcQuoteField)

	///报价录入错误回报
	OnErrRtnQuoteInsert(pInputQuote *CThostFtdcInputQuoteField, pRspInfo *CThostFtdcRspInfoField)

	///报价操作错误回报
	OnErrRtnQuoteAction(pQuoteAction *CThostFtdcQuoteActionField, pRspInfo *CThostFtdcRspInfoField)

	///询价通知
	OnRtnForQuoteRsp(pForQuoteRsp *CThostFtdcForQuoteRspField)

	///保证金监控中心用户令牌
	OnRtnCFMMCTradingAccountToken(pCFMMCTradingAccountToken *CThostFtdcCFMMCTradingAccountTokenField)

	///批量报单操作错误回报
	OnErrRtnBatchOrderAction(pBatchOrderAction *CThostFtdcBatchOrderActionField, pRspInfo *CThostFtdcRspInfoField)

	///期权自对冲通知
	OnRtnOptionSelfClose(pOptionSelfClose *CThostFtdcOptionSelfCloseField)

	///期权自对冲录入错误回报
	OnErrRtnOptionSelfCloseInsert(pInputOptionSelfClose *CThostFtdcInputOptionSelfCloseField, pRspInfo *CThostFtdcRspInfoField)

	///期权自对冲操作错误回报
	OnErrRtnOptionSelfCloseAction(pOptionSelfCloseAction *CThostFtdcOptionSelfCloseActionField, pRspInfo *CThostFtdcRspInfoField)

	///申请组合通知
	OnRtnCombAction(pCombAction *CThostFtdcCombActionField)

	///申请组合录入错误回报
	OnErrRtnCombActionInsert(pInputCombAction *CThostFtdcInputCombActionField, pRspInfo *CThostFtdcRspInfoField)

	///请求查询签约银行响应
	OnRspQryContractBank(pContractBank *CThostFtdcContractBankField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询预埋单响应
	OnRspQryParkedOrder(pParkedOrder *CThostFtdcParkedOrderField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询预埋撤单响应
	OnRspQryParkedOrderAction(pParkedOrderAction *CThostFtdcParkedOrderActionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询交易通知响应
	OnRspQryTradingNotice(pTradingNotice *CThostFtdcTradingNoticeField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询经纪公司交易参数响应
	OnRspQryBrokerTradingParams(pBrokerTradingParams *CThostFtdcBrokerTradingParamsField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询经纪公司交易算法响应
	OnRspQryBrokerTradingAlgos(pBrokerTradingAlgos *CThostFtdcBrokerTradingAlgosField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求查询监控中心用户令牌
	OnRspQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken *CThostFtdcQueryCFMMCTradingAccountTokenField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///银行发起银行资金转期货通知
	OnRtnFromBankToFutureByBank(pRspTransfer *CThostFtdcRspTransferField)

	///银行发起期货资金转银行通知
	OnRtnFromFutureToBankByBank(pRspTransfer *CThostFtdcRspTransferField)

	///银行发起冲正银行转期货通知
	OnRtnRepealFromBankToFutureByBank(pRspRepeal *CThostFtdcRspRepealField)

	///银行发起冲正期货转银行通知
	OnRtnRepealFromFutureToBankByBank(pRspRepeal *CThostFtdcRspRepealField)

	///期货发起银行资金转期货通知
	OnRtnFromBankToFutureByFuture(pRspTransfer *CThostFtdcRspTransferField)

	///期货发起期货资金转银行通知
	OnRtnFromFutureToBankByFuture(pRspTransfer *CThostFtdcRspTransferField)

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromBankToFutureByFutureManual(pRspRepeal *CThostFtdcRspRepealField)

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromFutureToBankByFutureManual(pRspRepeal *CThostFtdcRspRepealField)

	///期货发起查询银行余额通知
	OnRtnQueryBankBalanceByFuture(pNotifyQueryAccount *CThostFtdcNotifyQueryAccountField)

	///期货发起银行资金转期货错误回报
	OnErrRtnBankToFutureByFuture(pReqTransfer *CThostFtdcReqTransferField, pRspInfo *CThostFtdcRspInfoField)

	///期货发起期货资金转银行错误回报
	OnErrRtnFutureToBankByFuture(pReqTransfer *CThostFtdcReqTransferField, pRspInfo *CThostFtdcRspInfoField)

	///系统运行时期货端手工发起冲正银行转期货错误回报
	OnErrRtnRepealBankToFutureByFutureManual(pReqRepeal *CThostFtdcReqRepealField, pRspInfo *CThostFtdcRspInfoField)

	///系统运行时期货端手工发起冲正期货转银行错误回报
	OnErrRtnRepealFutureToBankByFutureManual(pReqRepeal *CThostFtdcReqRepealField, pRspInfo *CThostFtdcRspInfoField)

	///期货发起查询银行余额错误回报
	OnErrRtnQueryBankBalanceByFuture(pReqQueryAccount *CThostFtdcReqQueryAccountField, pRspInfo *CThostFtdcRspInfoField)

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromBankToFutureByFuture(pRspRepeal *CThostFtdcRspRepealField)

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromFutureToBankByFuture(pRspRepeal *CThostFtdcRspRepealField)

	///期货发起银行资金转期货应答
	OnRspFromBankToFutureByFuture(pReqTransfer *CThostFtdcReqTransferField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///期货发起期货资金转银行应答
	OnRspFromFutureToBankByFuture(pReqTransfer *CThostFtdcReqTransferField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///期货发起查询银行余额应答
	OnRspQueryBankAccountMoneyByFuture(pReqQueryAccount *CThostFtdcReqQueryAccountField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///银行发起银期开户通知
	OnRtnOpenAccountByBank(pOpenAccount *CThostFtdcOpenAccountField)

	///银行发起银期销户通知
	OnRtnCancelAccountByBank(pCancelAccount *CThostFtdcCancelAccountField)

	///银行发起变更银行账号通知
	OnRtnChangeAccountByBank(pChangeAccount *CThostFtdcChangeAccountField)

	///请求查询分类合约响应
	OnRspQryClassifiedInstrument(pInstrument *CThostFtdcInstrumentField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///请求组合优惠比例响应
	OnRspQryCombPromotionParam(pCombPromotionParam *CThostFtdcCombPromotionParamField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///投资者风险结算持仓查询响应
	OnRspQryRiskSettleInvstPosition(pRiskSettleInvstPosition *CThostFtdcRiskSettleInvstPositionField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)

	///风险结算产品查询响应
	OnRspQryRiskSettleProductStatus(pRiskSettleProductStatus *CThostFtdcRiskSettleProductStatusField, pRspInfo *CThostFtdcRspInfoField, nRequestID int, bIsLast bool)
}

type TraderApi interface {

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
	RegisterSpi(spi TraderSpi)

	///订阅私有流。
	///@param nResumeType 私有流重传方式
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	SubscribePrivateTopic(nResumeType THOST_TE_RESUME_TYPE)

	///订阅公共流。
	///@param nResumeType 公共流重传方式
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后公共流的内容
	///        THOST_TERT_NONE:取消订阅公共流
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	SubscribePublicTopic(nResumeType THOST_TE_RESUME_TYPE)

	///客户端认证请求
	ReqAuthenticate(pReqAuthenticateField *CThostFtdcReqAuthenticateField, nRequestID int) int

	///注册用户终端信息，用于中继服务器多连接模式
	///需要在终端认证成功后，用户登录前调用该接口
	RegisterUserSystemInfo(pUserSystemInfo *CThostFtdcUserSystemInfoField) int

	///上报用户终端信息，用于中继服务器操作员登录模式
	///操作员登录后，可以多次调用该接口上报客户信息
	SubmitUserSystemInfo(pUserSystemInfo *CThostFtdcUserSystemInfoField) int

	///用户登录请求
	ReqUserLogin(pReqUserLoginField *CThostFtdcReqUserLoginField, nRequestID int) int

	///登出请求
	ReqUserLogout(pUserLogout *CThostFtdcUserLogoutField, nRequestID int) int

	///用户口令更新请求
	ReqUserPasswordUpdate(pUserPasswordUpdate *CThostFtdcUserPasswordUpdateField, nRequestID int) int

	///资金账户口令更新请求
	ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate *CThostFtdcTradingAccountPasswordUpdateField, nRequestID int) int

	///查询用户当前支持的认证模式
	ReqUserAuthMethod(pReqUserAuthMethod *CThostFtdcReqUserAuthMethodField, nRequestID int) int

	///用户发出获取图形验证码请求
	ReqGenUserCaptcha(pReqGenUserCaptcha *CThostFtdcReqGenUserCaptchaField, nRequestID int) int

	///用户发出获取短信验证码请求
	ReqGenUserText(pReqGenUserText *CThostFtdcReqGenUserTextField, nRequestID int) int

	///用户发出带有图片验证码的登陆请求
	ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha *CThostFtdcReqUserLoginWithCaptchaField, nRequestID int) int

	///用户发出带有短信验证码的登陆请求
	ReqUserLoginWithText(pReqUserLoginWithText *CThostFtdcReqUserLoginWithTextField, nRequestID int) int

	///用户发出带有动态口令的登陆请求
	ReqUserLoginWithOTP(pReqUserLoginWithOTP *CThostFtdcReqUserLoginWithOTPField, nRequestID int) int

	///报单录入请求
	ReqOrderInsert(pInputOrder *CThostFtdcInputOrderField, nRequestID int) int

	///预埋单录入请求
	ReqParkedOrderInsert(pParkedOrder *CThostFtdcParkedOrderField, nRequestID int) int

	///预埋撤单录入请求
	ReqParkedOrderAction(pParkedOrderAction *CThostFtdcParkedOrderActionField, nRequestID int) int

	///报单操作请求
	ReqOrderAction(pInputOrderAction *CThostFtdcInputOrderActionField, nRequestID int) int

	///查询最大报单数量请求
	ReqQryMaxOrderVolume(pQryMaxOrderVolume *CThostFtdcQryMaxOrderVolumeField, nRequestID int) int

	///投资者结算结果确认
	ReqSettlementInfoConfirm(pSettlementInfoConfirm *CThostFtdcSettlementInfoConfirmField, nRequestID int) int

	///请求删除预埋单
	ReqRemoveParkedOrder(pRemoveParkedOrder *CThostFtdcRemoveParkedOrderField, nRequestID int) int

	///请求删除预埋撤单
	ReqRemoveParkedOrderAction(pRemoveParkedOrderAction *CThostFtdcRemoveParkedOrderActionField, nRequestID int) int

	///执行宣告录入请求
	ReqExecOrderInsert(pInputExecOrder *CThostFtdcInputExecOrderField, nRequestID int) int

	///执行宣告操作请求
	ReqExecOrderAction(pInputExecOrderAction *CThostFtdcInputExecOrderActionField, nRequestID int) int

	///询价录入请求
	ReqForQuoteInsert(pInputForQuote *CThostFtdcInputForQuoteField, nRequestID int) int

	///报价录入请求
	ReqQuoteInsert(pInputQuote *CThostFtdcInputQuoteField, nRequestID int) int

	///报价操作请求
	ReqQuoteAction(pInputQuoteAction *CThostFtdcInputQuoteActionField, nRequestID int) int

	///批量报单操作请求
	ReqBatchOrderAction(pInputBatchOrderAction *CThostFtdcInputBatchOrderActionField, nRequestID int) int

	///期权自对冲录入请求
	ReqOptionSelfCloseInsert(pInputOptionSelfClose *CThostFtdcInputOptionSelfCloseField, nRequestID int) int

	///期权自对冲操作请求
	ReqOptionSelfCloseAction(pInputOptionSelfCloseAction *CThostFtdcInputOptionSelfCloseActionField, nRequestID int) int

	///申请组合录入请求
	ReqCombActionInsert(pInputCombAction *CThostFtdcInputCombActionField, nRequestID int) int

	///请求查询报单
	ReqQryOrder(pQryOrder *CThostFtdcQryOrderField, nRequestID int) int

	///请求查询成交
	ReqQryTrade(pQryTrade *CThostFtdcQryTradeField, nRequestID int) int

	///请求查询投资者持仓
	ReqQryInvestorPosition(pQryInvestorPosition *CThostFtdcQryInvestorPositionField, nRequestID int) int

	///请求查询资金账户
	ReqQryTradingAccount(pQryTradingAccount *CThostFtdcQryTradingAccountField, nRequestID int) int

	///请求查询投资者
	ReqQryInvestor(pQryInvestor *CThostFtdcQryInvestorField, nRequestID int) int

	///请求查询交易编码
	ReqQryTradingCode(pQryTradingCode *CThostFtdcQryTradingCodeField, nRequestID int) int

	///请求查询合约保证金率
	ReqQryInstrumentMarginRate(pQryInstrumentMarginRate *CThostFtdcQryInstrumentMarginRateField, nRequestID int) int

	///请求查询合约手续费率
	ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate *CThostFtdcQryInstrumentCommissionRateField, nRequestID int) int

	///请求查询交易所
	ReqQryExchange(pQryExchange *CThostFtdcQryExchangeField, nRequestID int) int

	///请求查询产品
	ReqQryProduct(pQryProduct *CThostFtdcQryProductField, nRequestID int) int

	///请求查询合约
	ReqQryInstrument(pQryInstrument *CThostFtdcQryInstrumentField, nRequestID int) int

	///请求查询行情
	ReqQryDepthMarketData(pQryDepthMarketData *CThostFtdcQryDepthMarketDataField, nRequestID int) int

	///请求查询投资者结算结果
	ReqQrySettlementInfo(pQrySettlementInfo *CThostFtdcQrySettlementInfoField, nRequestID int) int

	///请求查询转帐银行
	ReqQryTransferBank(pQryTransferBank *CThostFtdcQryTransferBankField, nRequestID int) int

	///请求查询投资者持仓明细
	ReqQryInvestorPositionDetail(pQryInvestorPositionDetail *CThostFtdcQryInvestorPositionDetailField, nRequestID int) int

	///请求查询客户通知
	ReqQryNotice(pQryNotice *CThostFtdcQryNoticeField, nRequestID int) int

	///请求查询结算信息确认
	ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm *CThostFtdcQrySettlementInfoConfirmField, nRequestID int) int

	///请求查询投资者持仓明细
	ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail *CThostFtdcQryInvestorPositionCombineDetailField, nRequestID int) int

	///请求查询保证金监管系统经纪公司资金账户密钥
	ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey *CThostFtdcQryCFMMCTradingAccountKeyField, nRequestID int) int

	///请求查询仓单折抵信息
	ReqQryEWarrantOffset(pQryEWarrantOffset *CThostFtdcQryEWarrantOffsetField, nRequestID int) int

	///请求查询投资者品种/跨品种保证金
	ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin *CThostFtdcQryInvestorProductGroupMarginField, nRequestID int) int

	///请求查询交易所保证金率
	ReqQryExchangeMarginRate(pQryExchangeMarginRate *CThostFtdcQryExchangeMarginRateField, nRequestID int) int

	///请求查询交易所调整保证金率
	ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust *CThostFtdcQryExchangeMarginRateAdjustField, nRequestID int) int

	///请求查询汇率
	ReqQryExchangeRate(pQryExchangeRate *CThostFtdcQryExchangeRateField, nRequestID int) int

	///请求查询二级代理操作员银期权限
	ReqQrySecAgentACIDMap(pQrySecAgentACIDMap *CThostFtdcQrySecAgentACIDMapField, nRequestID int) int

	///请求查询产品报价汇率
	ReqQryProductExchRate(pQryProductExchRate *CThostFtdcQryProductExchRateField, nRequestID int) int

	///请求查询产品组
	ReqQryProductGroup(pQryProductGroup *CThostFtdcQryProductGroupField, nRequestID int) int

	///请求查询做市商合约手续费率
	ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate *CThostFtdcQryMMInstrumentCommissionRateField, nRequestID int) int

	///请求查询做市商期权合约手续费
	ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate *CThostFtdcQryMMOptionInstrCommRateField, nRequestID int) int

	///请求查询报单手续费
	ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate *CThostFtdcQryInstrumentOrderCommRateField, nRequestID int) int

	///请求查询资金账户
	ReqQrySecAgentTradingAccount(pQryTradingAccount *CThostFtdcQryTradingAccountField, nRequestID int) int

	///请求查询二级代理商资金校验模式
	ReqQrySecAgentCheckMode(pQrySecAgentCheckMode *CThostFtdcQrySecAgentCheckModeField, nRequestID int) int

	///请求查询二级代理商信息
	ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo *CThostFtdcQrySecAgentTradeInfoField, nRequestID int) int

	///请求查询期权交易成本
	ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost *CThostFtdcQryOptionInstrTradeCostField, nRequestID int) int

	///请求查询期权合约手续费
	ReqQryOptionInstrCommRate(pQryOptionInstrCommRate *CThostFtdcQryOptionInstrCommRateField, nRequestID int) int

	///请求查询执行宣告
	ReqQryExecOrder(pQryExecOrder *CThostFtdcQryExecOrderField, nRequestID int) int

	///请求查询询价
	ReqQryForQuote(pQryForQuote *CThostFtdcQryForQuoteField, nRequestID int) int

	///请求查询报价
	ReqQryQuote(pQryQuote *CThostFtdcQryQuoteField, nRequestID int) int

	///请求查询期权自对冲
	ReqQryOptionSelfClose(pQryOptionSelfClose *CThostFtdcQryOptionSelfCloseField, nRequestID int) int

	///请求查询投资单元
	ReqQryInvestUnit(pQryInvestUnit *CThostFtdcQryInvestUnitField, nRequestID int) int

	///请求查询组合合约安全系数
	ReqQryCombInstrumentGuard(pQryCombInstrumentGuard *CThostFtdcQryCombInstrumentGuardField, nRequestID int) int

	///请求查询申请组合
	ReqQryCombAction(pQryCombAction *CThostFtdcQryCombActionField, nRequestID int) int

	///请求查询转帐流水
	ReqQryTransferSerial(pQryTransferSerial *CThostFtdcQryTransferSerialField, nRequestID int) int

	///请求查询银期签约关系
	ReqQryAccountregister(pQryAccountregister *CThostFtdcQryAccountregisterField, nRequestID int) int

	///请求查询签约银行
	ReqQryContractBank(pQryContractBank *CThostFtdcQryContractBankField, nRequestID int) int

	///请求查询预埋单
	ReqQryParkedOrder(pQryParkedOrder *CThostFtdcQryParkedOrderField, nRequestID int) int

	///请求查询预埋撤单
	ReqQryParkedOrderAction(pQryParkedOrderAction *CThostFtdcQryParkedOrderActionField, nRequestID int) int

	///请求查询交易通知
	ReqQryTradingNotice(pQryTradingNotice *CThostFtdcQryTradingNoticeField, nRequestID int) int

	///请求查询经纪公司交易参数
	ReqQryBrokerTradingParams(pQryBrokerTradingParams *CThostFtdcQryBrokerTradingParamsField, nRequestID int) int

	///请求查询经纪公司交易算法
	ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos *CThostFtdcQryBrokerTradingAlgosField, nRequestID int) int

	///请求查询监控中心用户令牌
	ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken *CThostFtdcQueryCFMMCTradingAccountTokenField, nRequestID int) int

	///期货发起银行资金转期货请求
	ReqFromBankToFutureByFuture(pReqTransfer *CThostFtdcReqTransferField, nRequestID int) int

	///期货发起期货资金转银行请求
	ReqFromFutureToBankByFuture(pReqTransfer *CThostFtdcReqTransferField, nRequestID int) int

	///期货发起查询银行余额请求
	ReqQueryBankAccountMoneyByFuture(pReqQueryAccount *CThostFtdcReqQueryAccountField, nRequestID int) int

	///请求查询分类合约
	ReqQryClassifiedInstrument(pQryClassifiedInstrument *CThostFtdcQryClassifiedInstrumentField, nRequestID int) int

	///请求组合优惠比例
	ReqQryCombPromotionParam(pQryCombPromotionParam *CThostFtdcQryCombPromotionParamField, nRequestID int) int

	///投资者风险结算持仓查询
	ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition *CThostFtdcQryRiskSettleInvstPositionField, nRequestID int) int

	///风险结算产品查询
	ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus *CThostFtdcQryRiskSettleProductStatusField, nRequestID int) int
}
