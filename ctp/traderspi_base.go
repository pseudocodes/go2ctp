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

package ctp

import (
	"github.com/pseudocodes/go2ctp/thost"
)

var _ thost.TraderSpi = &BaseTraderSpi{}

type BaseTraderSpi struct {

	// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	OnFrontConnectedCallback func()

	// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	OnFrontDisconnectedCallback func(int)

	// 心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	OnHeartBeatWarningCallback func(int)

	// 客户端认证响应
	OnRspAuthenticateCallback func(*thost.CThostFtdcRspAuthenticateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 登录请求响应
	OnRspUserLoginCallback func(*thost.CThostFtdcRspUserLoginField, *thost.CThostFtdcRspInfoField, int, bool)

	// 登出请求响应
	OnRspUserLogoutCallback func(*thost.CThostFtdcUserLogoutField, *thost.CThostFtdcRspInfoField, int, bool)

	// 用户口令更新请求响应
	OnRspUserPasswordUpdateCallback func(*thost.CThostFtdcUserPasswordUpdateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 资金账户口令更新请求响应
	OnRspTradingAccountPasswordUpdateCallback func(*thost.CThostFtdcTradingAccountPasswordUpdateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 查询用户当前支持的认证模式的回复
	OnRspUserAuthMethodCallback func(*thost.CThostFtdcRspUserAuthMethodField, *thost.CThostFtdcRspInfoField, int, bool)

	// 获取图形验证码请求的回复
	OnRspGenUserCaptchaCallback func(*thost.CThostFtdcRspGenUserCaptchaField, *thost.CThostFtdcRspInfoField, int, bool)

	// 获取短信验证码请求的回复
	OnRspGenUserTextCallback func(*thost.CThostFtdcRspGenUserTextField, *thost.CThostFtdcRspInfoField, int, bool)

	// 报单录入请求响应
	OnRspOrderInsertCallback func(*thost.CThostFtdcInputOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 预埋单录入请求响应
	OnRspParkedOrderInsertCallback func(*thost.CThostFtdcParkedOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 预埋撤单录入请求响应
	OnRspParkedOrderActionCallback func(*thost.CThostFtdcParkedOrderActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 报单操作请求响应
	OnRspOrderActionCallback func(*thost.CThostFtdcInputOrderActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 查询最大报单数量响应
	OnRspQryMaxOrderVolumeCallback func(*thost.CThostFtdcQryMaxOrderVolumeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 投资者结算结果确认响应
	OnRspSettlementInfoConfirmCallback func(*thost.CThostFtdcSettlementInfoConfirmField, *thost.CThostFtdcRspInfoField, int, bool)

	// 删除预埋单响应
	OnRspRemoveParkedOrderCallback func(*thost.CThostFtdcRemoveParkedOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 删除预埋撤单响应
	OnRspRemoveParkedOrderActionCallback func(*thost.CThostFtdcRemoveParkedOrderActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 执行宣告录入请求响应
	OnRspExecOrderInsertCallback func(*thost.CThostFtdcInputExecOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 执行宣告操作请求响应
	OnRspExecOrderActionCallback func(*thost.CThostFtdcInputExecOrderActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 询价录入请求响应
	OnRspForQuoteInsertCallback func(*thost.CThostFtdcInputForQuoteField, *thost.CThostFtdcRspInfoField, int, bool)

	// 报价录入请求响应
	OnRspQuoteInsertCallback func(*thost.CThostFtdcInputQuoteField, *thost.CThostFtdcRspInfoField, int, bool)

	// 报价操作请求响应
	OnRspQuoteActionCallback func(*thost.CThostFtdcInputQuoteActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 批量报单操作请求响应
	OnRspBatchOrderActionCallback func(*thost.CThostFtdcInputBatchOrderActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 期权自对冲录入请求响应
	OnRspOptionSelfCloseInsertCallback func(*thost.CThostFtdcInputOptionSelfCloseField, *thost.CThostFtdcRspInfoField, int, bool)

	// 期权自对冲操作请求响应
	OnRspOptionSelfCloseActionCallback func(*thost.CThostFtdcInputOptionSelfCloseActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 申请组合录入请求响应
	OnRspCombActionInsertCallback func(*thost.CThostFtdcInputCombActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询报单响应
	OnRspQryOrderCallback func(*thost.CThostFtdcOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询成交响应
	OnRspQryTradeCallback func(*thost.CThostFtdcTradeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资者持仓响应
	OnRspQryInvestorPositionCallback func(*thost.CThostFtdcInvestorPositionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询资金账户响应
	OnRspQryTradingAccountCallback func(*thost.CThostFtdcTradingAccountField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资者响应
	OnRspQryInvestorCallback func(*thost.CThostFtdcInvestorField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询交易编码响应
	OnRspQryTradingCodeCallback func(*thost.CThostFtdcTradingCodeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询合约保证金率响应
	OnRspQryInstrumentMarginRateCallback func(*thost.CThostFtdcInstrumentMarginRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询合约手续费率响应
	OnRspQryInstrumentCommissionRateCallback func(*thost.CThostFtdcInstrumentCommissionRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询交易所响应
	OnRspQryExchangeCallback func(*thost.CThostFtdcExchangeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询产品响应
	OnRspQryProductCallback func(*thost.CThostFtdcProductField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询合约响应
	OnRspQryInstrumentCallback func(*thost.CThostFtdcInstrumentField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询行情响应
	OnRspQryDepthMarketDataCallback func(*thost.CThostFtdcDepthMarketDataField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资者结算结果响应
	OnRspQrySettlementInfoCallback func(*thost.CThostFtdcSettlementInfoField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询转帐银行响应
	OnRspQryTransferBankCallback func(*thost.CThostFtdcTransferBankField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资者持仓明细响应
	OnRspQryInvestorPositionDetailCallback func(*thost.CThostFtdcInvestorPositionDetailField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询客户通知响应
	OnRspQryNoticeCallback func(*thost.CThostFtdcNoticeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询结算信息确认响应
	OnRspQrySettlementInfoConfirmCallback func(*thost.CThostFtdcSettlementInfoConfirmField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资者持仓明细响应
	OnRspQryInvestorPositionCombineDetailCallback func(*thost.CThostFtdcInvestorPositionCombineDetailField, *thost.CThostFtdcRspInfoField, int, bool)

	// 查询保证金监管系统经纪公司资金账户密钥响应
	OnRspQryCFMMCTradingAccountKeyCallback func(*thost.CThostFtdcCFMMCTradingAccountKeyField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询仓单折抵信息响应
	OnRspQryEWarrantOffsetCallback func(*thost.CThostFtdcEWarrantOffsetField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资者品种/跨品种保证金响应
	OnRspQryInvestorProductGroupMarginCallback func(*thost.CThostFtdcInvestorProductGroupMarginField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询交易所保证金率响应
	OnRspQryExchangeMarginRateCallback func(*thost.CThostFtdcExchangeMarginRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询交易所调整保证金率响应
	OnRspQryExchangeMarginRateAdjustCallback func(*thost.CThostFtdcExchangeMarginRateAdjustField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询汇率响应
	OnRspQryExchangeRateCallback func(*thost.CThostFtdcExchangeRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询二级代理操作员银期权限响应
	OnRspQrySecAgentACIDMapCallback func(*thost.CThostFtdcSecAgentACIDMapField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询产品报价汇率
	OnRspQryProductExchRateCallback func(*thost.CThostFtdcProductExchRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询产品组
	OnRspQryProductGroupCallback func(*thost.CThostFtdcProductGroupField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询做市商合约手续费率响应
	OnRspQryMMInstrumentCommissionRateCallback func(*thost.CThostFtdcMMInstrumentCommissionRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询做市商期权合约手续费响应
	OnRspQryMMOptionInstrCommRateCallback func(*thost.CThostFtdcMMOptionInstrCommRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询报单手续费响应
	OnRspQryInstrumentOrderCommRateCallback func(*thost.CThostFtdcInstrumentOrderCommRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询资金账户响应
	OnRspQrySecAgentTradingAccountCallback func(*thost.CThostFtdcTradingAccountField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询二级代理商资金校验模式响应
	OnRspQrySecAgentCheckModeCallback func(*thost.CThostFtdcSecAgentCheckModeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询二级代理商信息响应
	OnRspQrySecAgentTradeInfoCallback func(*thost.CThostFtdcSecAgentTradeInfoField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询期权交易成本响应
	OnRspQryOptionInstrTradeCostCallback func(*thost.CThostFtdcOptionInstrTradeCostField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询期权合约手续费响应
	OnRspQryOptionInstrCommRateCallback func(*thost.CThostFtdcOptionInstrCommRateField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询执行宣告响应
	OnRspQryExecOrderCallback func(*thost.CThostFtdcExecOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询询价响应
	OnRspQryForQuoteCallback func(*thost.CThostFtdcForQuoteField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询报价响应
	OnRspQryQuoteCallback func(*thost.CThostFtdcQuoteField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询期权自对冲响应
	OnRspQryOptionSelfCloseCallback func(*thost.CThostFtdcOptionSelfCloseField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询投资单元响应
	OnRspQryInvestUnitCallback func(*thost.CThostFtdcInvestUnitField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询组合合约安全系数响应
	OnRspQryCombInstrumentGuardCallback func(*thost.CThostFtdcCombInstrumentGuardField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询申请组合响应
	OnRspQryCombActionCallback func(*thost.CThostFtdcCombActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询转帐流水响应
	OnRspQryTransferSerialCallback func(*thost.CThostFtdcTransferSerialField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询银期签约关系响应
	OnRspQryAccountregisterCallback func(*thost.CThostFtdcAccountregisterField, *thost.CThostFtdcRspInfoField, int, bool)

	// 错误应答
	OnRspErrorCallback func(*thost.CThostFtdcRspInfoField, int, bool)

	// 报单通知
	OnRtnOrderCallback func(*thost.CThostFtdcOrderField)

	// 成交通知
	OnRtnTradeCallback func(*thost.CThostFtdcTradeField)

	// 报单录入错误回报
	OnErrRtnOrderInsertCallback func(*thost.CThostFtdcInputOrderField, *thost.CThostFtdcRspInfoField)

	// 报单操作错误回报
	OnErrRtnOrderActionCallback func(*thost.CThostFtdcOrderActionField, *thost.CThostFtdcRspInfoField)

	// 合约交易状态通知
	OnRtnInstrumentStatusCallback func(*thost.CThostFtdcInstrumentStatusField)

	// 交易所公告通知
	OnRtnBulletinCallback func(*thost.CThostFtdcBulletinField)

	// 交易通知
	OnRtnTradingNoticeCallback func(*thost.CThostFtdcTradingNoticeInfoField)

	// 提示条件单校验错误
	OnRtnErrorConditionalOrderCallback func(*thost.CThostFtdcErrorConditionalOrderField)

	// 执行宣告通知
	OnRtnExecOrderCallback func(*thost.CThostFtdcExecOrderField)

	// 执行宣告录入错误回报
	OnErrRtnExecOrderInsertCallback func(*thost.CThostFtdcInputExecOrderField, *thost.CThostFtdcRspInfoField)

	// 执行宣告操作错误回报
	OnErrRtnExecOrderActionCallback func(*thost.CThostFtdcExecOrderActionField, *thost.CThostFtdcRspInfoField)

	// 询价录入错误回报
	OnErrRtnForQuoteInsertCallback func(*thost.CThostFtdcInputForQuoteField, *thost.CThostFtdcRspInfoField)

	// 报价通知
	OnRtnQuoteCallback func(*thost.CThostFtdcQuoteField)

	// 报价录入错误回报
	OnErrRtnQuoteInsertCallback func(*thost.CThostFtdcInputQuoteField, *thost.CThostFtdcRspInfoField)

	// 报价操作错误回报
	OnErrRtnQuoteActionCallback func(*thost.CThostFtdcQuoteActionField, *thost.CThostFtdcRspInfoField)

	// 询价通知
	OnRtnForQuoteRspCallback func(*thost.CThostFtdcForQuoteRspField)

	// 保证金监控中心用户令牌
	OnRtnCFMMCTradingAccountTokenCallback func(*thost.CThostFtdcCFMMCTradingAccountTokenField)

	// 批量报单操作错误回报
	OnErrRtnBatchOrderActionCallback func(*thost.CThostFtdcBatchOrderActionField, *thost.CThostFtdcRspInfoField)

	// 期权自对冲通知
	OnRtnOptionSelfCloseCallback func(*thost.CThostFtdcOptionSelfCloseField)

	// 期权自对冲录入错误回报
	OnErrRtnOptionSelfCloseInsertCallback func(*thost.CThostFtdcInputOptionSelfCloseField, *thost.CThostFtdcRspInfoField)

	// 期权自对冲操作错误回报
	OnErrRtnOptionSelfCloseActionCallback func(*thost.CThostFtdcOptionSelfCloseActionField, *thost.CThostFtdcRspInfoField)

	// 申请组合通知
	OnRtnCombActionCallback func(*thost.CThostFtdcCombActionField)

	// 申请组合录入错误回报
	OnErrRtnCombActionInsertCallback func(*thost.CThostFtdcInputCombActionField, *thost.CThostFtdcRspInfoField)

	// 请求查询签约银行响应
	OnRspQryContractBankCallback func(*thost.CThostFtdcContractBankField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询预埋单响应
	OnRspQryParkedOrderCallback func(*thost.CThostFtdcParkedOrderField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询预埋撤单响应
	OnRspQryParkedOrderActionCallback func(*thost.CThostFtdcParkedOrderActionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询交易通知响应
	OnRspQryTradingNoticeCallback func(*thost.CThostFtdcTradingNoticeField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询经纪公司交易参数响应
	OnRspQryBrokerTradingParamsCallback func(*thost.CThostFtdcBrokerTradingParamsField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询经纪公司交易算法响应
	OnRspQryBrokerTradingAlgosCallback func(*thost.CThostFtdcBrokerTradingAlgosField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求查询监控中心用户令牌
	OnRspQueryCFMMCTradingAccountTokenCallback func(*thost.CThostFtdcQueryCFMMCTradingAccountTokenField, *thost.CThostFtdcRspInfoField, int, bool)

	// 银行发起银行资金转期货通知
	OnRtnFromBankToFutureByBankCallback func(*thost.CThostFtdcRspTransferField)

	// 银行发起期货资金转银行通知
	OnRtnFromFutureToBankByBankCallback func(*thost.CThostFtdcRspTransferField)

	// 银行发起冲正银行转期货通知
	OnRtnRepealFromBankToFutureByBankCallback func(*thost.CThostFtdcRspRepealField)

	// 银行发起冲正期货转银行通知
	OnRtnRepealFromFutureToBankByBankCallback func(*thost.CThostFtdcRspRepealField)

	// 期货发起银行资金转期货通知
	OnRtnFromBankToFutureByFutureCallback func(*thost.CThostFtdcRspTransferField)

	// 期货发起期货资金转银行通知
	OnRtnFromFutureToBankByFutureCallback func(*thost.CThostFtdcRspTransferField)

	// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromBankToFutureByFutureManualCallback func(*thost.CThostFtdcRspRepealField)

	// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromFutureToBankByFutureManualCallback func(*thost.CThostFtdcRspRepealField)

	// 期货发起查询银行余额通知
	OnRtnQueryBankBalanceByFutureCallback func(*thost.CThostFtdcNotifyQueryAccountField)

	// 期货发起银行资金转期货错误回报
	OnErrRtnBankToFutureByFutureCallback func(*thost.CThostFtdcReqTransferField, *thost.CThostFtdcRspInfoField)

	// 期货发起期货资金转银行错误回报
	OnErrRtnFutureToBankByFutureCallback func(*thost.CThostFtdcReqTransferField, *thost.CThostFtdcRspInfoField)

	// 系统运行时期货端手工发起冲正银行转期货错误回报
	OnErrRtnRepealBankToFutureByFutureManualCallback func(*thost.CThostFtdcReqRepealField, *thost.CThostFtdcRspInfoField)

	// 系统运行时期货端手工发起冲正期货转银行错误回报
	OnErrRtnRepealFutureToBankByFutureManualCallback func(*thost.CThostFtdcReqRepealField, *thost.CThostFtdcRspInfoField)

	// 期货发起查询银行余额错误回报
	OnErrRtnQueryBankBalanceByFutureCallback func(*thost.CThostFtdcReqQueryAccountField, *thost.CThostFtdcRspInfoField)

	// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromBankToFutureByFutureCallback func(*thost.CThostFtdcRspRepealField)

	// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	OnRtnRepealFromFutureToBankByFutureCallback func(*thost.CThostFtdcRspRepealField)

	// 期货发起银行资金转期货应答
	OnRspFromBankToFutureByFutureCallback func(*thost.CThostFtdcReqTransferField, *thost.CThostFtdcRspInfoField, int, bool)

	// 期货发起期货资金转银行应答
	OnRspFromFutureToBankByFutureCallback func(*thost.CThostFtdcReqTransferField, *thost.CThostFtdcRspInfoField, int, bool)

	// 期货发起查询银行余额应答
	OnRspQueryBankAccountMoneyByFutureCallback func(*thost.CThostFtdcReqQueryAccountField, *thost.CThostFtdcRspInfoField, int, bool)

	// 银行发起银期开户通知
	OnRtnOpenAccountByBankCallback func(*thost.CThostFtdcOpenAccountField)

	// 银行发起银期销户通知
	OnRtnCancelAccountByBankCallback func(*thost.CThostFtdcCancelAccountField)

	// 银行发起变更银行账号通知
	OnRtnChangeAccountByBankCallback func(*thost.CThostFtdcChangeAccountField)

	// 请求查询分类合约响应
	OnRspQryClassifiedInstrumentCallback func(*thost.CThostFtdcInstrumentField, *thost.CThostFtdcRspInfoField, int, bool)

	// 请求组合优惠比例响应
	OnRspQryCombPromotionParamCallback func(*thost.CThostFtdcCombPromotionParamField, *thost.CThostFtdcRspInfoField, int, bool)

	// 投资者风险结算持仓查询响应
	OnRspQryRiskSettleInvstPositionCallback func(*thost.CThostFtdcRiskSettleInvstPositionField, *thost.CThostFtdcRspInfoField, int, bool)

	// 风险结算产品查询响应
	OnRspQryRiskSettleProductStatusCallback func(*thost.CThostFtdcRiskSettleProductStatusField, *thost.CThostFtdcRspInfoField, int, bool)
}

// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
func (s *BaseTraderSpi) OnFrontConnected() {
	if s.OnFrontConnectedCallback != nil {
		s.OnFrontConnectedCallback()
	}
}

// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
// /@param nReason 错误原因
// /        0x1001 网络读失败
// /        0x1002 网络写失败
// /        0x2001 接收心跳超时
// /        0x2002 发送心跳失败
// /        0x2003 收到错误报文
func (s *BaseTraderSpi) OnFrontDisconnected(nReason int) {
	if s.OnFrontDisconnectedCallback != nil {
		s.OnFrontDisconnectedCallback(nReason)
	}
}

// 心跳超时警告。当长时间未收到报文时，该方法被调用。
// /@param nTimeLapse 距离上次接收报文的时间
func (s *BaseTraderSpi) OnHeartBeatWarning(nTimeLapse int) {
	if s.OnHeartBeatWarningCallback != nil {
		s.OnHeartBeatWarningCallback(nTimeLapse)
	}
}

// 客户端认证响应
func (s *BaseTraderSpi) OnRspAuthenticate(pRspAuthenticateField *thost.CThostFtdcRspAuthenticateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspAuthenticateCallback != nil {
		s.OnRspAuthenticateCallback(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast)
	}
}

// 登录请求响应
func (s *BaseTraderSpi) OnRspUserLogin(pRspUserLogin *thost.CThostFtdcRspUserLoginField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspUserLoginCallback != nil {
		s.OnRspUserLoginCallback(pRspUserLogin, pRspInfo, nRequestID, bIsLast)
	}
}

// 登出请求响应
func (s *BaseTraderSpi) OnRspUserLogout(pUserLogout *thost.CThostFtdcUserLogoutField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspUserLogoutCallback != nil {
		s.OnRspUserLogoutCallback(pUserLogout, pRspInfo, nRequestID, bIsLast)
	}
}

// 用户口令更新请求响应
func (s *BaseTraderSpi) OnRspUserPasswordUpdate(pUserPasswordUpdate *thost.CThostFtdcUserPasswordUpdateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspUserPasswordUpdateCallback != nil {
		s.OnRspUserPasswordUpdateCallback(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast)
	}
}

// 资金账户口令更新请求响应
func (s *BaseTraderSpi) OnRspTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate *thost.CThostFtdcTradingAccountPasswordUpdateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspTradingAccountPasswordUpdateCallback != nil {
		s.OnRspTradingAccountPasswordUpdateCallback(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast)
	}
}

// 查询用户当前支持的认证模式的回复
func (s *BaseTraderSpi) OnRspUserAuthMethod(pRspUserAuthMethod *thost.CThostFtdcRspUserAuthMethodField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspUserAuthMethodCallback != nil {
		s.OnRspUserAuthMethodCallback(pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast)
	}
}

// 获取图形验证码请求的回复
func (s *BaseTraderSpi) OnRspGenUserCaptcha(pRspGenUserCaptcha *thost.CThostFtdcRspGenUserCaptchaField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspGenUserCaptchaCallback != nil {
		s.OnRspGenUserCaptchaCallback(pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast)
	}
}

// 获取短信验证码请求的回复
func (s *BaseTraderSpi) OnRspGenUserText(pRspGenUserText *thost.CThostFtdcRspGenUserTextField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspGenUserTextCallback != nil {
		s.OnRspGenUserTextCallback(pRspGenUserText, pRspInfo, nRequestID, bIsLast)
	}
}

// 报单录入请求响应
func (s *BaseTraderSpi) OnRspOrderInsert(pInputOrder *thost.CThostFtdcInputOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspOrderInsertCallback != nil {
		s.OnRspOrderInsertCallback(pInputOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 预埋单录入请求响应
func (s *BaseTraderSpi) OnRspParkedOrderInsert(pParkedOrder *thost.CThostFtdcParkedOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspParkedOrderInsertCallback != nil {
		s.OnRspParkedOrderInsertCallback(pParkedOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 预埋撤单录入请求响应
func (s *BaseTraderSpi) OnRspParkedOrderAction(pParkedOrderAction *thost.CThostFtdcParkedOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspParkedOrderActionCallback != nil {
		s.OnRspParkedOrderActionCallback(pParkedOrderAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 报单操作请求响应
func (s *BaseTraderSpi) OnRspOrderAction(pInputOrderAction *thost.CThostFtdcInputOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspOrderActionCallback != nil {
		s.OnRspOrderActionCallback(pInputOrderAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 查询最大报单数量响应
func (s *BaseTraderSpi) OnRspQryMaxOrderVolume(pQryMaxOrderVolume *thost.CThostFtdcQryMaxOrderVolumeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryMaxOrderVolumeCallback != nil {
		s.OnRspQryMaxOrderVolumeCallback(pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast)
	}
}

// 投资者结算结果确认响应
func (s *BaseTraderSpi) OnRspSettlementInfoConfirm(pSettlementInfoConfirm *thost.CThostFtdcSettlementInfoConfirmField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspSettlementInfoConfirmCallback != nil {
		s.OnRspSettlementInfoConfirmCallback(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast)
	}
}

// 删除预埋单响应
func (s *BaseTraderSpi) OnRspRemoveParkedOrder(pRemoveParkedOrder *thost.CThostFtdcRemoveParkedOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspRemoveParkedOrderCallback != nil {
		s.OnRspRemoveParkedOrderCallback(pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 删除预埋撤单响应
func (s *BaseTraderSpi) OnRspRemoveParkedOrderAction(pRemoveParkedOrderAction *thost.CThostFtdcRemoveParkedOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspRemoveParkedOrderActionCallback != nil {
		s.OnRspRemoveParkedOrderActionCallback(pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 执行宣告录入请求响应
func (s *BaseTraderSpi) OnRspExecOrderInsert(pInputExecOrder *thost.CThostFtdcInputExecOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspExecOrderInsertCallback != nil {
		s.OnRspExecOrderInsertCallback(pInputExecOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 执行宣告操作请求响应
func (s *BaseTraderSpi) OnRspExecOrderAction(pInputExecOrderAction *thost.CThostFtdcInputExecOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspExecOrderActionCallback != nil {
		s.OnRspExecOrderActionCallback(pInputExecOrderAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 询价录入请求响应
func (s *BaseTraderSpi) OnRspForQuoteInsert(pInputForQuote *thost.CThostFtdcInputForQuoteField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspForQuoteInsertCallback != nil {
		s.OnRspForQuoteInsertCallback(pInputForQuote, pRspInfo, nRequestID, bIsLast)
	}
}

// 报价录入请求响应
func (s *BaseTraderSpi) OnRspQuoteInsert(pInputQuote *thost.CThostFtdcInputQuoteField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQuoteInsertCallback != nil {
		s.OnRspQuoteInsertCallback(pInputQuote, pRspInfo, nRequestID, bIsLast)
	}
}

// 报价操作请求响应
func (s *BaseTraderSpi) OnRspQuoteAction(pInputQuoteAction *thost.CThostFtdcInputQuoteActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQuoteActionCallback != nil {
		s.OnRspQuoteActionCallback(pInputQuoteAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 批量报单操作请求响应
func (s *BaseTraderSpi) OnRspBatchOrderAction(pInputBatchOrderAction *thost.CThostFtdcInputBatchOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspBatchOrderActionCallback != nil {
		s.OnRspBatchOrderActionCallback(pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 期权自对冲录入请求响应
func (s *BaseTraderSpi) OnRspOptionSelfCloseInsert(pInputOptionSelfClose *thost.CThostFtdcInputOptionSelfCloseField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspOptionSelfCloseInsertCallback != nil {
		s.OnRspOptionSelfCloseInsertCallback(pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast)
	}
}

// 期权自对冲操作请求响应
func (s *BaseTraderSpi) OnRspOptionSelfCloseAction(pInputOptionSelfCloseAction *thost.CThostFtdcInputOptionSelfCloseActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspOptionSelfCloseActionCallback != nil {
		s.OnRspOptionSelfCloseActionCallback(pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 申请组合录入请求响应
func (s *BaseTraderSpi) OnRspCombActionInsert(pInputCombAction *thost.CThostFtdcInputCombActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspCombActionInsertCallback != nil {
		s.OnRspCombActionInsertCallback(pInputCombAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询报单响应
func (s *BaseTraderSpi) OnRspQryOrder(pOrder *thost.CThostFtdcOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryOrderCallback != nil {
		s.OnRspQryOrderCallback(pOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询成交响应
func (s *BaseTraderSpi) OnRspQryTrade(pTrade *thost.CThostFtdcTradeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryTradeCallback != nil {
		s.OnRspQryTradeCallback(pTrade, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资者持仓响应
func (s *BaseTraderSpi) OnRspQryInvestorPosition(pInvestorPosition *thost.CThostFtdcInvestorPositionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInvestorPositionCallback != nil {
		s.OnRspQryInvestorPositionCallback(pInvestorPosition, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询资金账户响应
func (s *BaseTraderSpi) OnRspQryTradingAccount(pTradingAccount *thost.CThostFtdcTradingAccountField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryTradingAccountCallback != nil {
		s.OnRspQryTradingAccountCallback(pTradingAccount, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资者响应
func (s *BaseTraderSpi) OnRspQryInvestor(pInvestor *thost.CThostFtdcInvestorField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInvestorCallback != nil {
		s.OnRspQryInvestorCallback(pInvestor, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询交易编码响应
func (s *BaseTraderSpi) OnRspQryTradingCode(pTradingCode *thost.CThostFtdcTradingCodeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryTradingCodeCallback != nil {
		s.OnRspQryTradingCodeCallback(pTradingCode, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询合约保证金率响应
func (s *BaseTraderSpi) OnRspQryInstrumentMarginRate(pInstrumentMarginRate *thost.CThostFtdcInstrumentMarginRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInstrumentMarginRateCallback != nil {
		s.OnRspQryInstrumentMarginRateCallback(pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询合约手续费率响应
func (s *BaseTraderSpi) OnRspQryInstrumentCommissionRate(pInstrumentCommissionRate *thost.CThostFtdcInstrumentCommissionRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInstrumentCommissionRateCallback != nil {
		s.OnRspQryInstrumentCommissionRateCallback(pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询交易所响应
func (s *BaseTraderSpi) OnRspQryExchange(pExchange *thost.CThostFtdcExchangeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryExchangeCallback != nil {
		s.OnRspQryExchangeCallback(pExchange, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询产品响应
func (s *BaseTraderSpi) OnRspQryProduct(pProduct *thost.CThostFtdcProductField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryProductCallback != nil {
		s.OnRspQryProductCallback(pProduct, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询合约响应
func (s *BaseTraderSpi) OnRspQryInstrument(pInstrument *thost.CThostFtdcInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInstrumentCallback != nil {
		s.OnRspQryInstrumentCallback(pInstrument, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询行情响应
func (s *BaseTraderSpi) OnRspQryDepthMarketData(pDepthMarketData *thost.CThostFtdcDepthMarketDataField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryDepthMarketDataCallback != nil {
		s.OnRspQryDepthMarketDataCallback(pDepthMarketData, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资者结算结果响应
func (s *BaseTraderSpi) OnRspQrySettlementInfo(pSettlementInfo *thost.CThostFtdcSettlementInfoField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQrySettlementInfoCallback != nil {
		s.OnRspQrySettlementInfoCallback(pSettlementInfo, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询转帐银行响应
func (s *BaseTraderSpi) OnRspQryTransferBank(pTransferBank *thost.CThostFtdcTransferBankField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryTransferBankCallback != nil {
		s.OnRspQryTransferBankCallback(pTransferBank, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资者持仓明细响应
func (s *BaseTraderSpi) OnRspQryInvestorPositionDetail(pInvestorPositionDetail *thost.CThostFtdcInvestorPositionDetailField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInvestorPositionDetailCallback != nil {
		s.OnRspQryInvestorPositionDetailCallback(pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询客户通知响应
func (s *BaseTraderSpi) OnRspQryNotice(pNotice *thost.CThostFtdcNoticeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryNoticeCallback != nil {
		s.OnRspQryNoticeCallback(pNotice, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询结算信息确认响应
func (s *BaseTraderSpi) OnRspQrySettlementInfoConfirm(pSettlementInfoConfirm *thost.CThostFtdcSettlementInfoConfirmField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQrySettlementInfoConfirmCallback != nil {
		s.OnRspQrySettlementInfoConfirmCallback(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资者持仓明细响应
func (s *BaseTraderSpi) OnRspQryInvestorPositionCombineDetail(pInvestorPositionCombineDetail *thost.CThostFtdcInvestorPositionCombineDetailField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInvestorPositionCombineDetailCallback != nil {
		s.OnRspQryInvestorPositionCombineDetailCallback(pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast)
	}
}

// 查询保证金监管系统经纪公司资金账户密钥响应
func (s *BaseTraderSpi) OnRspQryCFMMCTradingAccountKey(pCFMMCTradingAccountKey *thost.CThostFtdcCFMMCTradingAccountKeyField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryCFMMCTradingAccountKeyCallback != nil {
		s.OnRspQryCFMMCTradingAccountKeyCallback(pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询仓单折抵信息响应
func (s *BaseTraderSpi) OnRspQryEWarrantOffset(pEWarrantOffset *thost.CThostFtdcEWarrantOffsetField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryEWarrantOffsetCallback != nil {
		s.OnRspQryEWarrantOffsetCallback(pEWarrantOffset, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资者品种/跨品种保证金响应
func (s *BaseTraderSpi) OnRspQryInvestorProductGroupMargin(pInvestorProductGroupMargin *thost.CThostFtdcInvestorProductGroupMarginField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInvestorProductGroupMarginCallback != nil {
		s.OnRspQryInvestorProductGroupMarginCallback(pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询交易所保证金率响应
func (s *BaseTraderSpi) OnRspQryExchangeMarginRate(pExchangeMarginRate *thost.CThostFtdcExchangeMarginRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryExchangeMarginRateCallback != nil {
		s.OnRspQryExchangeMarginRateCallback(pExchangeMarginRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询交易所调整保证金率响应
func (s *BaseTraderSpi) OnRspQryExchangeMarginRateAdjust(pExchangeMarginRateAdjust *thost.CThostFtdcExchangeMarginRateAdjustField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryExchangeMarginRateAdjustCallback != nil {
		s.OnRspQryExchangeMarginRateAdjustCallback(pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询汇率响应
func (s *BaseTraderSpi) OnRspQryExchangeRate(pExchangeRate *thost.CThostFtdcExchangeRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryExchangeRateCallback != nil {
		s.OnRspQryExchangeRateCallback(pExchangeRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询二级代理操作员银期权限响应
func (s *BaseTraderSpi) OnRspQrySecAgentACIDMap(pSecAgentACIDMap *thost.CThostFtdcSecAgentACIDMapField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQrySecAgentACIDMapCallback != nil {
		s.OnRspQrySecAgentACIDMapCallback(pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询产品报价汇率
func (s *BaseTraderSpi) OnRspQryProductExchRate(pProductExchRate *thost.CThostFtdcProductExchRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryProductExchRateCallback != nil {
		s.OnRspQryProductExchRateCallback(pProductExchRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询产品组
func (s *BaseTraderSpi) OnRspQryProductGroup(pProductGroup *thost.CThostFtdcProductGroupField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryProductGroupCallback != nil {
		s.OnRspQryProductGroupCallback(pProductGroup, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询做市商合约手续费率响应
func (s *BaseTraderSpi) OnRspQryMMInstrumentCommissionRate(pMMInstrumentCommissionRate *thost.CThostFtdcMMInstrumentCommissionRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryMMInstrumentCommissionRateCallback != nil {
		s.OnRspQryMMInstrumentCommissionRateCallback(pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询做市商期权合约手续费响应
func (s *BaseTraderSpi) OnRspQryMMOptionInstrCommRate(pMMOptionInstrCommRate *thost.CThostFtdcMMOptionInstrCommRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryMMOptionInstrCommRateCallback != nil {
		s.OnRspQryMMOptionInstrCommRateCallback(pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询报单手续费响应
func (s *BaseTraderSpi) OnRspQryInstrumentOrderCommRate(pInstrumentOrderCommRate *thost.CThostFtdcInstrumentOrderCommRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInstrumentOrderCommRateCallback != nil {
		s.OnRspQryInstrumentOrderCommRateCallback(pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询资金账户响应
func (s *BaseTraderSpi) OnRspQrySecAgentTradingAccount(pTradingAccount *thost.CThostFtdcTradingAccountField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQrySecAgentTradingAccountCallback != nil {
		s.OnRspQrySecAgentTradingAccountCallback(pTradingAccount, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询二级代理商资金校验模式响应
func (s *BaseTraderSpi) OnRspQrySecAgentCheckMode(pSecAgentCheckMode *thost.CThostFtdcSecAgentCheckModeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQrySecAgentCheckModeCallback != nil {
		s.OnRspQrySecAgentCheckModeCallback(pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询二级代理商信息响应
func (s *BaseTraderSpi) OnRspQrySecAgentTradeInfo(pSecAgentTradeInfo *thost.CThostFtdcSecAgentTradeInfoField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQrySecAgentTradeInfoCallback != nil {
		s.OnRspQrySecAgentTradeInfoCallback(pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询期权交易成本响应
func (s *BaseTraderSpi) OnRspQryOptionInstrTradeCost(pOptionInstrTradeCost *thost.CThostFtdcOptionInstrTradeCostField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryOptionInstrTradeCostCallback != nil {
		s.OnRspQryOptionInstrTradeCostCallback(pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询期权合约手续费响应
func (s *BaseTraderSpi) OnRspQryOptionInstrCommRate(pOptionInstrCommRate *thost.CThostFtdcOptionInstrCommRateField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryOptionInstrCommRateCallback != nil {
		s.OnRspQryOptionInstrCommRateCallback(pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询执行宣告响应
func (s *BaseTraderSpi) OnRspQryExecOrder(pExecOrder *thost.CThostFtdcExecOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryExecOrderCallback != nil {
		s.OnRspQryExecOrderCallback(pExecOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询询价响应
func (s *BaseTraderSpi) OnRspQryForQuote(pForQuote *thost.CThostFtdcForQuoteField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryForQuoteCallback != nil {
		s.OnRspQryForQuoteCallback(pForQuote, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询报价响应
func (s *BaseTraderSpi) OnRspQryQuote(pQuote *thost.CThostFtdcQuoteField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryQuoteCallback != nil {
		s.OnRspQryQuoteCallback(pQuote, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询期权自对冲响应
func (s *BaseTraderSpi) OnRspQryOptionSelfClose(pOptionSelfClose *thost.CThostFtdcOptionSelfCloseField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryOptionSelfCloseCallback != nil {
		s.OnRspQryOptionSelfCloseCallback(pOptionSelfClose, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询投资单元响应
func (s *BaseTraderSpi) OnRspQryInvestUnit(pInvestUnit *thost.CThostFtdcInvestUnitField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryInvestUnitCallback != nil {
		s.OnRspQryInvestUnitCallback(pInvestUnit, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询组合合约安全系数响应
func (s *BaseTraderSpi) OnRspQryCombInstrumentGuard(pCombInstrumentGuard *thost.CThostFtdcCombInstrumentGuardField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryCombInstrumentGuardCallback != nil {
		s.OnRspQryCombInstrumentGuardCallback(pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询申请组合响应
func (s *BaseTraderSpi) OnRspQryCombAction(pCombAction *thost.CThostFtdcCombActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryCombActionCallback != nil {
		s.OnRspQryCombActionCallback(pCombAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询转帐流水响应
func (s *BaseTraderSpi) OnRspQryTransferSerial(pTransferSerial *thost.CThostFtdcTransferSerialField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryTransferSerialCallback != nil {
		s.OnRspQryTransferSerialCallback(pTransferSerial, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询银期签约关系响应
func (s *BaseTraderSpi) OnRspQryAccountregister(pAccountregister *thost.CThostFtdcAccountregisterField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryAccountregisterCallback != nil {
		s.OnRspQryAccountregisterCallback(pAccountregister, pRspInfo, nRequestID, bIsLast)
	}
}

// 错误应答
func (s *BaseTraderSpi) OnRspError(pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspErrorCallback != nil {
		s.OnRspErrorCallback(pRspInfo, nRequestID, bIsLast)
	}
}

// 报单通知
func (s *BaseTraderSpi) OnRtnOrder(pOrder *thost.CThostFtdcOrderField) {
	if s.OnRtnOrderCallback != nil {
		s.OnRtnOrderCallback(pOrder)
	}
}

// 成交通知
func (s *BaseTraderSpi) OnRtnTrade(pTrade *thost.CThostFtdcTradeField) {
	if s.OnRtnTradeCallback != nil {
		s.OnRtnTradeCallback(pTrade)
	}
}

// 报单录入错误回报
func (s *BaseTraderSpi) OnErrRtnOrderInsert(pInputOrder *thost.CThostFtdcInputOrderField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnOrderInsertCallback != nil {
		s.OnErrRtnOrderInsertCallback(pInputOrder, pRspInfo)
	}
}

// 报单操作错误回报
func (s *BaseTraderSpi) OnErrRtnOrderAction(pOrderAction *thost.CThostFtdcOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnOrderActionCallback != nil {
		s.OnErrRtnOrderActionCallback(pOrderAction, pRspInfo)
	}
}

// 合约交易状态通知
func (s *BaseTraderSpi) OnRtnInstrumentStatus(pInstrumentStatus *thost.CThostFtdcInstrumentStatusField) {
	if s.OnRtnInstrumentStatusCallback != nil {
		s.OnRtnInstrumentStatusCallback(pInstrumentStatus)
	}
}

// 交易所公告通知
func (s *BaseTraderSpi) OnRtnBulletin(pBulletin *thost.CThostFtdcBulletinField) {
	if s.OnRtnBulletinCallback != nil {
		s.OnRtnBulletinCallback(pBulletin)
	}
}

// 交易通知
func (s *BaseTraderSpi) OnRtnTradingNotice(pTradingNoticeInfo *thost.CThostFtdcTradingNoticeInfoField) {
	if s.OnRtnTradingNoticeCallback != nil {
		s.OnRtnTradingNoticeCallback(pTradingNoticeInfo)
	}
}

// 提示条件单校验错误
func (s *BaseTraderSpi) OnRtnErrorConditionalOrder(pErrorConditionalOrder *thost.CThostFtdcErrorConditionalOrderField) {
	if s.OnRtnErrorConditionalOrderCallback != nil {
		s.OnRtnErrorConditionalOrderCallback(pErrorConditionalOrder)
	}
}

// 执行宣告通知
func (s *BaseTraderSpi) OnRtnExecOrder(pExecOrder *thost.CThostFtdcExecOrderField) {
	if s.OnRtnExecOrderCallback != nil {
		s.OnRtnExecOrderCallback(pExecOrder)
	}
}

// 执行宣告录入错误回报
func (s *BaseTraderSpi) OnErrRtnExecOrderInsert(pInputExecOrder *thost.CThostFtdcInputExecOrderField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnExecOrderInsertCallback != nil {
		s.OnErrRtnExecOrderInsertCallback(pInputExecOrder, pRspInfo)
	}
}

// 执行宣告操作错误回报
func (s *BaseTraderSpi) OnErrRtnExecOrderAction(pExecOrderAction *thost.CThostFtdcExecOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnExecOrderActionCallback != nil {
		s.OnErrRtnExecOrderActionCallback(pExecOrderAction, pRspInfo)
	}
}

// 询价录入错误回报
func (s *BaseTraderSpi) OnErrRtnForQuoteInsert(pInputForQuote *thost.CThostFtdcInputForQuoteField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnForQuoteInsertCallback != nil {
		s.OnErrRtnForQuoteInsertCallback(pInputForQuote, pRspInfo)
	}
}

// 报价通知
func (s *BaseTraderSpi) OnRtnQuote(pQuote *thost.CThostFtdcQuoteField) {
	if s.OnRtnQuoteCallback != nil {
		s.OnRtnQuoteCallback(pQuote)
	}
}

// 报价录入错误回报
func (s *BaseTraderSpi) OnErrRtnQuoteInsert(pInputQuote *thost.CThostFtdcInputQuoteField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnQuoteInsertCallback != nil {
		s.OnErrRtnQuoteInsertCallback(pInputQuote, pRspInfo)
	}
}

// 报价操作错误回报
func (s *BaseTraderSpi) OnErrRtnQuoteAction(pQuoteAction *thost.CThostFtdcQuoteActionField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnQuoteActionCallback != nil {
		s.OnErrRtnQuoteActionCallback(pQuoteAction, pRspInfo)
	}
}

// 询价通知
func (s *BaseTraderSpi) OnRtnForQuoteRsp(pForQuoteRsp *thost.CThostFtdcForQuoteRspField) {
	if s.OnRtnForQuoteRspCallback != nil {
		s.OnRtnForQuoteRspCallback(pForQuoteRsp)
	}
}

// 保证金监控中心用户令牌
func (s *BaseTraderSpi) OnRtnCFMMCTradingAccountToken(pCFMMCTradingAccountToken *thost.CThostFtdcCFMMCTradingAccountTokenField) {
	if s.OnRtnCFMMCTradingAccountTokenCallback != nil {
		s.OnRtnCFMMCTradingAccountTokenCallback(pCFMMCTradingAccountToken)
	}
}

// 批量报单操作错误回报
func (s *BaseTraderSpi) OnErrRtnBatchOrderAction(pBatchOrderAction *thost.CThostFtdcBatchOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnBatchOrderActionCallback != nil {
		s.OnErrRtnBatchOrderActionCallback(pBatchOrderAction, pRspInfo)
	}
}

// 期权自对冲通知
func (s *BaseTraderSpi) OnRtnOptionSelfClose(pOptionSelfClose *thost.CThostFtdcOptionSelfCloseField) {
	if s.OnRtnOptionSelfCloseCallback != nil {
		s.OnRtnOptionSelfCloseCallback(pOptionSelfClose)
	}
}

// 期权自对冲录入错误回报
func (s *BaseTraderSpi) OnErrRtnOptionSelfCloseInsert(pInputOptionSelfClose *thost.CThostFtdcInputOptionSelfCloseField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnOptionSelfCloseInsertCallback != nil {
		s.OnErrRtnOptionSelfCloseInsertCallback(pInputOptionSelfClose, pRspInfo)
	}
}

// 期权自对冲操作错误回报
func (s *BaseTraderSpi) OnErrRtnOptionSelfCloseAction(pOptionSelfCloseAction *thost.CThostFtdcOptionSelfCloseActionField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnOptionSelfCloseActionCallback != nil {
		s.OnErrRtnOptionSelfCloseActionCallback(pOptionSelfCloseAction, pRspInfo)
	}
}

// 申请组合通知
func (s *BaseTraderSpi) OnRtnCombAction(pCombAction *thost.CThostFtdcCombActionField) {
	if s.OnRtnCombActionCallback != nil {
		s.OnRtnCombActionCallback(pCombAction)
	}
}

// 申请组合录入错误回报
func (s *BaseTraderSpi) OnErrRtnCombActionInsert(pInputCombAction *thost.CThostFtdcInputCombActionField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnCombActionInsertCallback != nil {
		s.OnErrRtnCombActionInsertCallback(pInputCombAction, pRspInfo)
	}
}

// 请求查询签约银行响应
func (s *BaseTraderSpi) OnRspQryContractBank(pContractBank *thost.CThostFtdcContractBankField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryContractBankCallback != nil {
		s.OnRspQryContractBankCallback(pContractBank, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询预埋单响应
func (s *BaseTraderSpi) OnRspQryParkedOrder(pParkedOrder *thost.CThostFtdcParkedOrderField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryParkedOrderCallback != nil {
		s.OnRspQryParkedOrderCallback(pParkedOrder, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询预埋撤单响应
func (s *BaseTraderSpi) OnRspQryParkedOrderAction(pParkedOrderAction *thost.CThostFtdcParkedOrderActionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryParkedOrderActionCallback != nil {
		s.OnRspQryParkedOrderActionCallback(pParkedOrderAction, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询交易通知响应
func (s *BaseTraderSpi) OnRspQryTradingNotice(pTradingNotice *thost.CThostFtdcTradingNoticeField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryTradingNoticeCallback != nil {
		s.OnRspQryTradingNoticeCallback(pTradingNotice, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询经纪公司交易参数响应
func (s *BaseTraderSpi) OnRspQryBrokerTradingParams(pBrokerTradingParams *thost.CThostFtdcBrokerTradingParamsField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryBrokerTradingParamsCallback != nil {
		s.OnRspQryBrokerTradingParamsCallback(pBrokerTradingParams, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询经纪公司交易算法响应
func (s *BaseTraderSpi) OnRspQryBrokerTradingAlgos(pBrokerTradingAlgos *thost.CThostFtdcBrokerTradingAlgosField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryBrokerTradingAlgosCallback != nil {
		s.OnRspQryBrokerTradingAlgosCallback(pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求查询监控中心用户令牌
func (s *BaseTraderSpi) OnRspQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken *thost.CThostFtdcQueryCFMMCTradingAccountTokenField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQueryCFMMCTradingAccountTokenCallback != nil {
		s.OnRspQueryCFMMCTradingAccountTokenCallback(pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast)
	}
}

// 银行发起银行资金转期货通知
func (s *BaseTraderSpi) OnRtnFromBankToFutureByBank(pRspTransfer *thost.CThostFtdcRspTransferField) {
	if s.OnRtnFromBankToFutureByBankCallback != nil {
		s.OnRtnFromBankToFutureByBankCallback(pRspTransfer)
	}
}

// 银行发起期货资金转银行通知
func (s *BaseTraderSpi) OnRtnFromFutureToBankByBank(pRspTransfer *thost.CThostFtdcRspTransferField) {
	if s.OnRtnFromFutureToBankByBankCallback != nil {
		s.OnRtnFromFutureToBankByBankCallback(pRspTransfer)
	}
}

// 银行发起冲正银行转期货通知
func (s *BaseTraderSpi) OnRtnRepealFromBankToFutureByBank(pRspRepeal *thost.CThostFtdcRspRepealField) {
	if s.OnRtnRepealFromBankToFutureByBankCallback != nil {
		s.OnRtnRepealFromBankToFutureByBankCallback(pRspRepeal)
	}
}

// 银行发起冲正期货转银行通知
func (s *BaseTraderSpi) OnRtnRepealFromFutureToBankByBank(pRspRepeal *thost.CThostFtdcRspRepealField) {
	if s.OnRtnRepealFromFutureToBankByBankCallback != nil {
		s.OnRtnRepealFromFutureToBankByBankCallback(pRspRepeal)
	}
}

// 期货发起银行资金转期货通知
func (s *BaseTraderSpi) OnRtnFromBankToFutureByFuture(pRspTransfer *thost.CThostFtdcRspTransferField) {
	if s.OnRtnFromBankToFutureByFutureCallback != nil {
		s.OnRtnFromBankToFutureByFutureCallback(pRspTransfer)
	}
}

// 期货发起期货资金转银行通知
func (s *BaseTraderSpi) OnRtnFromFutureToBankByFuture(pRspTransfer *thost.CThostFtdcRspTransferField) {
	if s.OnRtnFromFutureToBankByFutureCallback != nil {
		s.OnRtnFromFutureToBankByFutureCallback(pRspTransfer)
	}
}

// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
func (s *BaseTraderSpi) OnRtnRepealFromBankToFutureByFutureManual(pRspRepeal *thost.CThostFtdcRspRepealField) {
	if s.OnRtnRepealFromBankToFutureByFutureManualCallback != nil {
		s.OnRtnRepealFromBankToFutureByFutureManualCallback(pRspRepeal)
	}
}

// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
func (s *BaseTraderSpi) OnRtnRepealFromFutureToBankByFutureManual(pRspRepeal *thost.CThostFtdcRspRepealField) {
	if s.OnRtnRepealFromFutureToBankByFutureManualCallback != nil {
		s.OnRtnRepealFromFutureToBankByFutureManualCallback(pRspRepeal)
	}
}

// 期货发起查询银行余额通知
func (s *BaseTraderSpi) OnRtnQueryBankBalanceByFuture(pNotifyQueryAccount *thost.CThostFtdcNotifyQueryAccountField) {
	if s.OnRtnQueryBankBalanceByFutureCallback != nil {
		s.OnRtnQueryBankBalanceByFutureCallback(pNotifyQueryAccount)
	}
}

// 期货发起银行资金转期货错误回报
func (s *BaseTraderSpi) OnErrRtnBankToFutureByFuture(pReqTransfer *thost.CThostFtdcReqTransferField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnBankToFutureByFutureCallback != nil {
		s.OnErrRtnBankToFutureByFutureCallback(pReqTransfer, pRspInfo)
	}
}

// 期货发起期货资金转银行错误回报
func (s *BaseTraderSpi) OnErrRtnFutureToBankByFuture(pReqTransfer *thost.CThostFtdcReqTransferField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnFutureToBankByFutureCallback != nil {
		s.OnErrRtnFutureToBankByFutureCallback(pReqTransfer, pRspInfo)
	}
}

// 系统运行时期货端手工发起冲正银行转期货错误回报
func (s *BaseTraderSpi) OnErrRtnRepealBankToFutureByFutureManual(pReqRepeal *thost.CThostFtdcReqRepealField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnRepealBankToFutureByFutureManualCallback != nil {
		s.OnErrRtnRepealBankToFutureByFutureManualCallback(pReqRepeal, pRspInfo)
	}
}

// 系统运行时期货端手工发起冲正期货转银行错误回报
func (s *BaseTraderSpi) OnErrRtnRepealFutureToBankByFutureManual(pReqRepeal *thost.CThostFtdcReqRepealField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnRepealFutureToBankByFutureManualCallback != nil {
		s.OnErrRtnRepealFutureToBankByFutureManualCallback(pReqRepeal, pRspInfo)
	}
}

// 期货发起查询银行余额错误回报
func (s *BaseTraderSpi) OnErrRtnQueryBankBalanceByFuture(pReqQueryAccount *thost.CThostFtdcReqQueryAccountField, pRspInfo *thost.CThostFtdcRspInfoField) {
	if s.OnErrRtnQueryBankBalanceByFutureCallback != nil {
		s.OnErrRtnQueryBankBalanceByFutureCallback(pReqQueryAccount, pRspInfo)
	}
}

// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
func (s *BaseTraderSpi) OnRtnRepealFromBankToFutureByFuture(pRspRepeal *thost.CThostFtdcRspRepealField) {
	if s.OnRtnRepealFromBankToFutureByFutureCallback != nil {
		s.OnRtnRepealFromBankToFutureByFutureCallback(pRspRepeal)
	}
}

// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
func (s *BaseTraderSpi) OnRtnRepealFromFutureToBankByFuture(pRspRepeal *thost.CThostFtdcRspRepealField) {
	if s.OnRtnRepealFromFutureToBankByFutureCallback != nil {
		s.OnRtnRepealFromFutureToBankByFutureCallback(pRspRepeal)
	}
}

// 期货发起银行资金转期货应答
func (s *BaseTraderSpi) OnRspFromBankToFutureByFuture(pReqTransfer *thost.CThostFtdcReqTransferField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspFromBankToFutureByFutureCallback != nil {
		s.OnRspFromBankToFutureByFutureCallback(pReqTransfer, pRspInfo, nRequestID, bIsLast)
	}
}

// 期货发起期货资金转银行应答
func (s *BaseTraderSpi) OnRspFromFutureToBankByFuture(pReqTransfer *thost.CThostFtdcReqTransferField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspFromFutureToBankByFutureCallback != nil {
		s.OnRspFromFutureToBankByFutureCallback(pReqTransfer, pRspInfo, nRequestID, bIsLast)
	}
}

// 期货发起查询银行余额应答
func (s *BaseTraderSpi) OnRspQueryBankAccountMoneyByFuture(pReqQueryAccount *thost.CThostFtdcReqQueryAccountField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQueryBankAccountMoneyByFutureCallback != nil {
		s.OnRspQueryBankAccountMoneyByFutureCallback(pReqQueryAccount, pRspInfo, nRequestID, bIsLast)
	}
}

// 银行发起银期开户通知
func (s *BaseTraderSpi) OnRtnOpenAccountByBank(pOpenAccount *thost.CThostFtdcOpenAccountField) {
	if s.OnRtnOpenAccountByBankCallback != nil {
		s.OnRtnOpenAccountByBankCallback(pOpenAccount)
	}
}

// 银行发起银期销户通知
func (s *BaseTraderSpi) OnRtnCancelAccountByBank(pCancelAccount *thost.CThostFtdcCancelAccountField) {
	if s.OnRtnCancelAccountByBankCallback != nil {
		s.OnRtnCancelAccountByBankCallback(pCancelAccount)
	}
}

// 银行发起变更银行账号通知
func (s *BaseTraderSpi) OnRtnChangeAccountByBank(pChangeAccount *thost.CThostFtdcChangeAccountField) {
	if s.OnRtnChangeAccountByBankCallback != nil {
		s.OnRtnChangeAccountByBankCallback(pChangeAccount)
	}
}

// 请求查询分类合约响应
func (s *BaseTraderSpi) OnRspQryClassifiedInstrument(pInstrument *thost.CThostFtdcInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryClassifiedInstrumentCallback != nil {
		s.OnRspQryClassifiedInstrumentCallback(pInstrument, pRspInfo, nRequestID, bIsLast)
	}
}

// 请求组合优惠比例响应
func (s *BaseTraderSpi) OnRspQryCombPromotionParam(pCombPromotionParam *thost.CThostFtdcCombPromotionParamField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryCombPromotionParamCallback != nil {
		s.OnRspQryCombPromotionParamCallback(pCombPromotionParam, pRspInfo, nRequestID, bIsLast)
	}
}

// 投资者风险结算持仓查询响应
func (s *BaseTraderSpi) OnRspQryRiskSettleInvstPosition(pRiskSettleInvstPosition *thost.CThostFtdcRiskSettleInvstPositionField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryRiskSettleInvstPositionCallback != nil {
		s.OnRspQryRiskSettleInvstPositionCallback(pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast)
	}
}

// 风险结算产品查询响应
func (s *BaseTraderSpi) OnRspQryRiskSettleProductStatus(pRiskSettleProductStatus *thost.CThostFtdcRiskSettleProductStatusField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	if s.OnRspQryRiskSettleProductStatusCallback != nil {
		s.OnRspQryRiskSettleProductStatusCallback(pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast)
	}
}
