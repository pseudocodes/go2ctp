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

#ifndef _TRADERAPI_WRAP_H_
#define _TRADERAPI_WRAP_H_

class QCTPTraderSpi : public CThostFtdcTraderSpi {
public:
    QCTPTraderSpi(CThostFtdcTraderApi* pUserApi);
    QCTPTraderSpi(CThostFtdcTraderApi* pUserApi, uintptr_t gUserApi);
    QCTPTraderSpi();
    ~QCTPTraderSpi() { }

    // 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    void OnFrontConnected();

    // 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    ///@param nReason 错误原因
    ///        0x1001 网络读失败
    ///        0x1002 网络写失败
    ///        0x2001 接收心跳超时
    ///        0x2002 发送心跳失败
    ///        0x2003 收到错误报文
    void OnFrontDisconnected(int nReason);

    // 心跳超时警告。当长时间未收到报文时，该方法被调用。
    ///@param nTimeLapse 距离上次接收报文的时间
    void OnHeartBeatWarning(int nTimeLapse);

    // 客户端认证响应
    void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 登录请求响应
    void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 登出请求响应
    void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 用户口令更新请求响应
    void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 资金账户口令更新请求响应
    void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 查询用户当前支持的认证模式的回复
    void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 获取图形验证码请求的回复
    void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 获取短信验证码请求的回复
    void OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 报单录入请求响应
    void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 预埋单录入请求响应
    void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 预埋撤单录入请求响应
    void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 报单操作请求响应
    void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 查询最大报单数量响应
    void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 投资者结算结果确认响应
    void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 删除预埋单响应
    void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 删除预埋撤单响应
    void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 执行宣告录入请求响应
    void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 执行宣告操作请求响应
    void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 询价录入请求响应
    void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 报价录入请求响应
    void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 报价操作请求响应
    void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 批量报单操作请求响应
    void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 期权自对冲录入请求响应
    void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 期权自对冲操作请求响应
    void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 申请组合录入请求响应
    void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询报单响应
    void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询成交响应
    void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资者持仓响应
    void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询资金账户响应
    void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资者响应
    void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询交易编码响应
    void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询合约保证金率响应
    void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询合约手续费率响应
    void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询交易所响应
    void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询产品响应
    void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询合约响应
    void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询行情响应
    void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资者结算结果响应
    void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询转帐银行响应
    void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资者持仓明细响应
    void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询客户通知响应
    void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询结算信息确认响应
    void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资者持仓明细响应
    void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 查询保证金监管系统经纪公司资金账户密钥响应
    void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询仓单折抵信息响应
    void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资者品种/跨品种保证金响应
    void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询交易所保证金率响应
    void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询交易所调整保证金率响应
    void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询汇率响应
    void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询二级代理操作员银期权限响应
    void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询产品报价汇率
    void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询产品组
    void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询做市商合约手续费率响应
    void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询做市商期权合约手续费响应
    void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询报单手续费响应
    void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询资金账户响应
    void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询二级代理商资金校验模式响应
    void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询二级代理商信息响应
    void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询期权交易成本响应
    void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询期权合约手续费响应
    void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询执行宣告响应
    void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询询价响应
    void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询报价响应
    void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询期权自对冲响应
    void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询投资单元响应
    void OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询组合合约安全系数响应
    void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询申请组合响应
    void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询转帐流水响应
    void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询银期签约关系响应
    void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 错误应答
    void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 报单通知
    void OnRtnOrder(CThostFtdcOrderField* pOrder);

    // 成交通知
    void OnRtnTrade(CThostFtdcTradeField* pTrade);

    // 报单录入错误回报
    void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo);

    // 报单操作错误回报
    void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo);

    // 合约交易状态通知
    void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus);

    // 交易所公告通知
    void OnRtnBulletin(CThostFtdcBulletinField* pBulletin);

    // 交易通知
    void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo);

    // 提示条件单校验错误
    void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder);

    // 执行宣告通知
    void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder);

    // 执行宣告录入错误回报
    void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo);

    // 执行宣告操作错误回报
    void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo);

    // 询价录入错误回报
    void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo);

    // 报价通知
    void OnRtnQuote(CThostFtdcQuoteField* pQuote);

    // 报价录入错误回报
    void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo);

    // 报价操作错误回报
    void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo);

    // 询价通知
    void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp);

    // 保证金监控中心用户令牌
    void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken);

    // 批量报单操作错误回报
    void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo);

    // 期权自对冲通知
    void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose);

    // 期权自对冲录入错误回报
    void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo);

    // 期权自对冲操作错误回报
    void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo);

    // 申请组合通知
    void OnRtnCombAction(CThostFtdcCombActionField* pCombAction);

    // 申请组合录入错误回报
    void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo);

    // 请求查询签约银行响应
    void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询预埋单响应
    void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询预埋撤单响应
    void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询交易通知响应
    void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询经纪公司交易参数响应
    void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询经纪公司交易算法响应
    void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求查询监控中心用户令牌
    void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 银行发起银行资金转期货通知
    void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer);

    // 银行发起期货资金转银行通知
    void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer);

    // 银行发起冲正银行转期货通知
    void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal);

    // 银行发起冲正期货转银行通知
    void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal);

    // 期货发起银行资金转期货通知
    void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer);

    // 期货发起期货资金转银行通知
    void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer);

    // 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
    void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal);

    // 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
    void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal);

    // 期货发起查询银行余额通知
    void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount);

    // 期货发起银行资金转期货错误回报
    void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo);

    // 期货发起期货资金转银行错误回报
    void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo);

    // 系统运行时期货端手工发起冲正银行转期货错误回报
    void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo);

    // 系统运行时期货端手工发起冲正期货转银行错误回报
    void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo);

    // 期货发起查询银行余额错误回报
    void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo);

    // 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
    void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal);

    // 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
    void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal);

    // 期货发起银行资金转期货应答
    void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 期货发起期货资金转银行应答
    void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 期货发起查询银行余额应答
    void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 银行发起银期开户通知
    void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount);

    // 银行发起银期销户通知
    void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount);

    // 银行发起变更银行账号通知
    void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount);

    // 请求查询分类合约响应
    void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 请求组合优惠比例响应
    void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 投资者风险结算持仓查询响应
    void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 风险结算产品查询响应
    void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    // 创建TraderApi
    ///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
    ///@return 创建出的UserApi
    CThostFtdcTraderApi* CreateFtdcTraderApi(const char* pszFlowPath);

    // 获取API的版本信息
    ///@retrun 获取到的版本号
    const char* GetApiVersion();

    // 删除接口对象本身
    ///@remark 不再使用本接口对象时,调用该函数删除接口对象
    void Release();

    // 初始化
    ///@remark 初始化运行环境,只有调用后,接口才开始工作
    void Init();

    // 等待接口线程结束运行
    ///@return 线程退出代码
    int Join();

    // 获取当前交易日
    ///@retrun 获取到的交易日
    ///@remark 只有登录成功后,才能得到正确的交易日
    const char* GetTradingDay();

    // 注册前置机网络地址
    ///@param pszFrontAddress：前置机网络地址。
    ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
    ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
    void RegisterFront(char* pszFrontAddress);

    // 注册名字服务器网络地址
    ///@param pszNsAddress：名字服务器网络地址。
    ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
    ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
    ///@remark RegisterNameServer优先于RegisterFront
    void RegisterNameServer(char* pszNsAddress);

    // 注册名字服务器用户信息
    ///@param pFensUserInfo：用户信息。
    void RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo);

    // 注册回调接口
    ///@param pSpi 派生自回调接口类的实例
    void RegisterSpi(CThostFtdcTraderSpi* pSpi);

    // 订阅私有流。
    ///@param nResumeType 私有流重传方式
    ///        THOST_TERT_RESTART:从本交易日开始重传
    ///        THOST_TERT_RESUME:从上次收到的续传
    ///        THOST_TERT_QUICK:只传送登录后私有流的内容
    ///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
    void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

    // 订阅公共流。
    ///@param nResumeType 公共流重传方式
    ///        THOST_TERT_RESTART:从本交易日开始重传
    ///        THOST_TERT_RESUME:从上次收到的续传
    ///        THOST_TERT_QUICK:只传送登录后公共流的内容
    ///        THOST_TERT_NONE:取消订阅公共流
    ///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
    void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

    // 客户端认证请求
    int ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID);

    // 注册用户终端信息，用于中继服务器多连接模式
    /// 需要在终端认证成功后，用户登录前调用该接口
    int RegisterUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo);

    // 上报用户终端信息，用于中继服务器操作员登录模式
    /// 操作员登录后，可以多次调用该接口上报客户信息
    int SubmitUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo);

    // 用户登录请求
    int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);

    // 用户登录请求
    int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length, TThostFtdcClientSystemInfoType systemInfo);

    // 登出请求
    int ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID);

    // 用户口令更新请求
    int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID);

    // 资金账户口令更新请求
    int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID);

    // 查询用户当前支持的认证模式
    int ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID);

    // 用户发出获取图形验证码请求
    int ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID);

    // 用户发出获取短信验证码请求
    int ReqGenUserText(CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID);

    // 用户发出带有图片验证码的登陆请求
    int ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID);

    // 用户发出带有短信验证码的登陆请求
    int ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID);

    // 用户发出带有动态口令的登陆请求
    int ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID);

    // 报单录入请求
    int ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder, int nRequestID);

    // 预埋单录入请求
    int ReqParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, int nRequestID);

    // 预埋撤单录入请求
    int ReqParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID);

    // 报单操作请求
    int ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID);

    // 查询最大报单数量请求
    int ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID);

    // 投资者结算结果确认
    int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID);

    // 请求删除预埋单
    int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID);

    // 请求删除预埋撤单
    int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID);

    // 执行宣告录入请求
    int ReqExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID);

    // 执行宣告操作请求
    int ReqExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID);

    // 询价录入请求
    int ReqForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID);

    // 报价录入请求
    int ReqQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, int nRequestID);

    // 报价操作请求
    int ReqQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID);

    // 批量报单操作请求
    int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID);

    // 期权自对冲录入请求
    int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID);

    // 期权自对冲操作请求
    int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID);

    // 申请组合录入请求
    int ReqCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, int nRequestID);

    // 请求查询报单
    int ReqQryOrder(CThostFtdcQryOrderField* pQryOrder, int nRequestID);

    // 请求查询成交
    int ReqQryTrade(CThostFtdcQryTradeField* pQryTrade, int nRequestID);

    // 请求查询投资者持仓
    int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID);

    // 请求查询资金账户
    int ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);

    // 请求查询投资者
    int ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor, int nRequestID);

    // 请求查询交易编码
    int ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID);

    // 请求查询合约保证金率
    int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID);

    // 请求查询合约手续费率
    int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID);

    // 请求查询交易所
    int ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange, int nRequestID);

    // 请求查询产品
    int ReqQryProduct(CThostFtdcQryProductField* pQryProduct, int nRequestID);

    // 请求查询合约
    int ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID);

    // 请求查询行情
    int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID);

    // 请求查询投资者结算结果
    int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID);

    // 请求查询转帐银行
    int ReqQryTransferBank(CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID);

    // 请求查询投资者持仓明细
    int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID);

    // 请求查询客户通知
    int ReqQryNotice(CThostFtdcQryNoticeField* pQryNotice, int nRequestID);

    // 请求查询结算信息确认
    int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID);

    // 请求查询投资者持仓明细
    int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID);

    // 请求查询保证金监管系统经纪公司资金账户密钥
    int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID);

    // 请求查询仓单折抵信息
    int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID);

    // 请求查询投资者品种/跨品种保证金
    int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID);

    // 请求查询交易所保证金率
    int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID);

    // 请求查询交易所调整保证金率
    int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID);

    // 请求查询汇率
    int ReqQryExchangeRate(CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID);

    // 请求查询二级代理操作员银期权限
    int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID);

    // 请求查询产品报价汇率
    int ReqQryProductExchRate(CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID);

    // 请求查询产品组
    int ReqQryProductGroup(CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID);

    // 请求查询做市商合约手续费率
    int ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID);

    // 请求查询做市商期权合约手续费
    int ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID);

    // 请求查询报单手续费
    int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID);

    // 请求查询资金账户
    int ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);

    // 请求查询二级代理商资金校验模式
    int ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID);

    // 请求查询二级代理商信息
    int ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID);

    // 请求查询期权交易成本
    int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID);

    // 请求查询期权合约手续费
    int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID);

    // 请求查询执行宣告
    int ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID);

    // 请求查询询价
    int ReqQryForQuote(CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID);

    // 请求查询报价
    int ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID);

    // 请求查询期权自对冲
    int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID);

    // 请求查询投资单元
    int ReqQryInvestUnit(CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID);

    // 请求查询组合合约安全系数
    int ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID);

    // 请求查询申请组合
    int ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID);

    // 请求查询转帐流水
    int ReqQryTransferSerial(CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID);

    // 请求查询银期签约关系
    int ReqQryAccountregister(CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID);

    // 请求查询签约银行
    int ReqQryContractBank(CThostFtdcQryContractBankField* pQryContractBank, int nRequestID);

    // 请求查询预埋单
    int ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID);

    // 请求查询预埋撤单
    int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID);

    // 请求查询交易通知
    int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID);

    // 请求查询经纪公司交易参数
    int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID);

    // 请求查询经纪公司交易算法
    int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID);

    // 请求查询监控中心用户令牌
    int ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID);

    // 期货发起银行资金转期货请求
    int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID);

    // 期货发起期货资金转银行请求
    int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID);

    // 期货发起查询银行余额请求
    int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID);

    // 请求查询分类合约
    int ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID);

    // 请求组合优惠比例
    int ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID);

    // 投资者风险结算持仓查询
    int ReqQryRiskSettleInvstPosition(CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID);

    // 风险结算产品查询
    int ReqQryRiskSettleProductStatus(CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID);

private:
    CThostFtdcTraderApi* pUserApi;
    uintptr_t gUserApi;
};

#endif // end _TRADERAPI_WRAP_H_
