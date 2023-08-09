package thost

type THOST_TE_RESUME_TYPE int32

const (
	THOST_TERT_RESTART THOST_TE_RESUME_TYPE = 0
	THOST_TERT_RESUME  THOST_TE_RESUME_TYPE = 1
	THOST_TERT_QUICK   THOST_TE_RESUME_TYPE = 2
	THOST_TERT_NONE    THOST_TE_RESUME_TYPE = 3
)

// 价格类型
type TThostFtdcPriceType float64

// 比率类型
type TThostFtdcRatioType float64

// 资金类型
type TThostFtdcMoneyType float64

// 大额数量类型
type TThostFtdcLargeVolumeType float64

// 基础商品乘数类型
type TThostFtdcUnderlyingMultipleType float64

// 业务参数代码值类型
type TThostFtdcAMLOpParamValueType float64

// 反洗钱资金类型
type TThostFtdcAMLMoneyType float64

// 交易金额（元）类型
type TThostFtdcTradeAmountType float64

// 应收客户费用（元）类型
type TThostFtdcCustFeeType float64

// 应收期货公司费用（元）类型
type TThostFtdcFutureFeeType float64

// 单笔最高限额类型
type TThostFtdcSingleMaxAmtType float64

// 单笔最低限额类型
type TThostFtdcSingleMinAmtType float64

// 每日累计转帐额度类型
type TThostFtdcTotalAmtType float64

// 各种换汇金额类型
type TThostFtdcFBEAmtType float64

// 换汇汇率类型
type TThostFtdcExRateType float64

// 资金类型
type TThostFtdcCSRCMoneyType float64

// 价格类型
type TThostFtdcCSRCPriceType float64

// 执行价类型
type TThostFtdcCSRCStrikePriceType float64

// 币种单位数量类型
type TThostFtdcCurrencyUnitType float64

// 汇率类型
type TThostFtdcExchangeRateType float64

// 资金类型
type TThostFtdcBigMoneyType float64

// 期货风险值类型
type TThostFtdcRiskValueType float64

// 折扣率类型
type TThostFtdcDiscountRatioType float64

// 序列系列号类型
type TThostFtdcSequenceSeriesType int16

// 通讯时段编号类型
type TThostFtdcCommPhaseNoType int16

// 交易所交易员代码类型
type TThostFtdcTraderIDType [21]byte

// 投资者代码类型
type TThostFtdcInvestorIDType [13]byte

// 经纪公司代码类型
type TThostFtdcBrokerIDType [11]byte

// 经纪公司简称类型
type TThostFtdcBrokerAbbrType [9]byte

// 经纪公司名称类型
type TThostFtdcBrokerNameType [81]byte

// 合约在交易所的代码类型
type TThostFtdcOldExchangeInstIDType [31]byte

// 合约在交易所的代码类型
type TThostFtdcExchangeInstIDType [81]byte

// 报单引用类型
type TThostFtdcOrderRefType [13]byte

// 会员代码类型
type TThostFtdcParticipantIDType [11]byte

// 用户代码类型
type TThostFtdcUserIDType [16]byte

// 密码类型
type TThostFtdcPasswordType [41]byte

// 交易编码类型
type TThostFtdcClientIDType [11]byte

// 合约代码类型
type TThostFtdcInstrumentIDType [81]byte

// 合约代码类型
type TThostFtdcOldInstrumentIDType [31]byte

// 合约标识码类型
type TThostFtdcInstrumentCodeType [31]byte

// 市场代码类型
type TThostFtdcMarketIDType [31]byte

// 产品名称类型
type TThostFtdcProductNameType [21]byte

// 交易所代码类型
type TThostFtdcExchangeIDType [9]byte

// 交易所名称类型
type TThostFtdcExchangeNameType [61]byte

// 交易所简称类型
type TThostFtdcExchangeAbbrType [9]byte

// 交易所标志类型
type TThostFtdcExchangeFlagType [2]byte

// Mac地址类型
type TThostFtdcMacAddressType [21]byte

// 系统编号类型
type TThostFtdcSystemIDType [21]byte

// 客户登录备注2类型
type TThostFtdcClientLoginRemarkType [151]byte

// 日期类型
type TThostFtdcDateType [9]byte

// 时间类型
type TThostFtdcTimeType [9]byte

// 长时间类型
type TThostFtdcLongTimeType [13]byte

// 合约名称类型
type TThostFtdcInstrumentNameType [21]byte

// 结算组代码类型
type TThostFtdcSettlementGroupIDType [9]byte

// 报单编号类型
type TThostFtdcOrderSysIDType [21]byte

// 成交编号类型
type TThostFtdcTradeIDType [21]byte

// DB命令类型类型
type TThostFtdcCommandTypeType [65]byte

// IP地址类型
type TThostFtdcOldIPAddressType [16]byte

// IP地址类型
type TThostFtdcIPAddressType [33]byte

// 产品信息类型
type TThostFtdcProductInfoType [11]byte

// 协议信息类型
type TThostFtdcProtocolInfoType [11]byte

// 业务单元类型
type TThostFtdcBusinessUnitType [21]byte

// 出入金流水号类型
type TThostFtdcDepositSeqNoType [15]byte

// 证件号码类型
type TThostFtdcIdentifiedCardNoType [51]byte

// 本地报单编号类型
type TThostFtdcOrderLocalIDType [13]byte

// 用户名称类型
type TThostFtdcUserNameType [81]byte

// 参与人名称类型
type TThostFtdcPartyNameType [81]byte

// 错误信息类型
type TThostFtdcErrorMsgType [81]byte

// 字段名类型
type TThostFtdcFieldNameType [2049]byte

// 字段内容类型
type TThostFtdcFieldContentType [2049]byte

// 系统名称类型
type TThostFtdcSystemNameType [41]byte

// 消息正文类型
type TThostFtdcContentType [501]byte

// 组合开平标志类型
type TThostFtdcCombOffsetFlagType [5]byte

// 组合投机套保标志类型
type TThostFtdcCombHedgeFlagType [5]byte

// 序列编号类型
type TThostFtdcSequenceLabelType [2]byte

// 合同编号类型
type TThostFtdcContractCodeType [41]byte

// 市类型
type TThostFtdcCityType [51]byte

// 是否股民类型
type TThostFtdcIsStockType [11]byte

// 渠道类型
type TThostFtdcChannelType [51]byte

// 通讯地址类型
type TThostFtdcAddressType [101]byte

// 邮政编码类型
type TThostFtdcZipCodeType [7]byte

// 联系电话类型
type TThostFtdcTelephoneType [41]byte

// 传真类型
type TThostFtdcFaxType [41]byte

// 手机类型
type TThostFtdcMobileType [41]byte

// 电子邮件类型
type TThostFtdcEMailType [41]byte

// 备注类型
type TThostFtdcMemoType [161]byte

// 企业代码类型
type TThostFtdcCompanyCodeType [51]byte

// 网站地址类型
type TThostFtdcWebsiteType [51]byte

// 税务登记号类型
type TThostFtdcTaxNoType [31]byte

// 属性代码类型
type TThostFtdcPropertyIDType [33]byte

// 属性名称类型
type TThostFtdcPropertyNameType [65]byte

// 营业执照号类型
type TThostFtdcLicenseNoType [51]byte

// 经纪人代码类型
type TThostFtdcAgentIDType [13]byte

// 经纪人名称类型
type TThostFtdcAgentNameType [41]byte

// 经纪人组代码类型
type TThostFtdcAgentGroupIDType [13]byte

// 经纪人组名称类型
type TThostFtdcAgentGroupNameType [41]byte

// 参数代码值类型
type TThostFtdcSettlementParamValueType [256]byte

// 计数器代码类型
type TThostFtdcCounterIDType [33]byte

// 投资者分组名称类型
type TThostFtdcInvestorGroupNameType [41]byte

// 牌号类型
type TThostFtdcBrandCodeType [257]byte

// 仓库类型
type TThostFtdcWarehouseType [257]byte

// 产期类型
type TThostFtdcProductDateType [41]byte

// 等级类型
type TThostFtdcGradeType [41]byte

// 类别类型
type TThostFtdcClassifyType [41]byte

// 货位类型
type TThostFtdcPositionType [41]byte

// 产地类型
type TThostFtdcYieldlyType [41]byte

// 公定重量类型
type TThostFtdcWeightType [41]byte

// 文件名称类型
type TThostFtdcFileNameType [257]byte

// 上传文件类型类型
type TThostFtdcUploadModeType [21]byte

// 投资者帐号类型
type TThostFtdcAccountIDType [13]byte

// 银行统一标识类型类型
type TThostFtdcBankFlagType [4]byte

// 银行账户类型
type TThostFtdcBankAccountType [41]byte

// 银行账户的开户人名称类型
type TThostFtdcOpenNameType [61]byte

// 银行账户的开户行类型
type TThostFtdcOpenBankType [101]byte

// 银行名称类型
type TThostFtdcBankNameType [101]byte

// 发布路径类型
type TThostFtdcPublishPathType [257]byte

// 操作员代码类型
type TThostFtdcOperatorIDType [65]byte

// 月份提前数组类型
type TThostFtdcAdvanceMonthArrayType [13]byte

// 日期表达式类型
type TThostFtdcDateExprType [1025]byte

// 合约代码表达式类型
type TThostFtdcInstrumentIDExprType [41]byte

// 合约名称表达式类型
type TThostFtdcInstrumentNameExprType [41]byte

// 日志级别类型
type TThostFtdcLogLevelType [33]byte

// 存储过程名称类型
type TThostFtdcProcessNameType [257]byte

// 操作摘要类型
type TThostFtdcOperationMemoType [1025]byte

// 票据号类型
type TThostFtdcBillNoType [15]byte

// 票据名称类型
type TThostFtdcBillNameType [33]byte

// 枚举值代码类型
type TThostFtdcEnumValueIDType [65]byte

// 枚举值类型类型
type TThostFtdcEnumValueTypeType [33]byte

// 枚举值名称类型
type TThostFtdcEnumValueLabelType [65]byte

// 枚举值结果类型
type TThostFtdcEnumValueResultType [33]byte

// 限定值类型类型
type TThostFtdcRangeIntTypeType [33]byte

// 限定值下限类型
type TThostFtdcRangeIntFromType [33]byte

// 限定值上限类型
type TThostFtdcRangeIntToType [33]byte

// 功能代码类型
type TThostFtdcFunctionIDType [25]byte

// 功能编码类型
type TThostFtdcFunctionValueCodeType [257]byte

// 功能名称类型
type TThostFtdcFunctionNameType [65]byte

// 角色编号类型
type TThostFtdcRoleIDType [11]byte

// 角色名称类型
type TThostFtdcRoleNameType [41]byte

// 描述类型
type TThostFtdcDescriptionType [401]byte

// 组合编号类型
type TThostFtdcCombineIDType [25]byte

// 组合类型类型
type TThostFtdcCombineTypeType [25]byte

// 盈亏算法说明类型
type TThostFtdcCommentType [31]byte

// 版本号类型
type TThostFtdcVersionType [4]byte

// 交易代码类型
type TThostFtdcTradeCodeType [7]byte

// 交易日期类型
type TThostFtdcTradeDateType [9]byte

// 交易时间类型
type TThostFtdcTradeTimeType [9]byte

// 发起方流水号类型
type TThostFtdcTradeSerialType [9]byte

// 期货公司代码类型
type TThostFtdcFutureIDType [11]byte

// 银行代码类型
type TThostFtdcBankIDType [4]byte

// 银行分中心代码类型
type TThostFtdcBankBrchIDType [5]byte

// 分中心代码类型
type TThostFtdcBankBranchIDType [11]byte

// 交易柜员类型
type TThostFtdcOperNoType [17]byte

// 渠道标志类型
type TThostFtdcDeviceIDType [3]byte

// 记录数类型
type TThostFtdcRecordNumType [7]byte

// 期货资金账号类型
type TThostFtdcFutureAccountType [22]byte

// 期货资金密码类型
type TThostFtdcFutureAccPwdType [17]byte

// 币种类型
type TThostFtdcCurrencyCodeType [4]byte

// 响应代码类型
type TThostFtdcRetCodeType [5]byte

// 响应信息类型
type TThostFtdcRetInfoType [129]byte

// 银行总余额类型
type TThostFtdcTradeAmtType [20]byte

// 银行可用余额类型
type TThostFtdcUseAmtType [20]byte

// 银行可取余额类型
type TThostFtdcFetchAmtType [20]byte

// 证件号码类型
type TThostFtdcCertCodeType [21]byte

// 资金项目编号类型
type TThostFtdcFundProjectIDType [5]byte

// 职业类型
type TThostFtdcProfessionType [101]byte

// 国籍类型
type TThostFtdcNationalType [31]byte

// 省类型
type TThostFtdcProvinceType [51]byte

// 区类型
type TThostFtdcRegionType [16]byte

// 国家类型
type TThostFtdcCountryType [16]byte

// 营业执照类型
type TThostFtdcLicenseNOType [33]byte

// 企业性质类型
type TThostFtdcCompanyTypeType [16]byte

// 经营范围类型
type TThostFtdcBusinessScopeType [1001]byte

// 注册资本币种类型
type TThostFtdcCapitalCurrencyType [4]byte

// 营业部编号类型
type TThostFtdcBranchIDType [9]byte

// 域名类型
type TThostFtdcBrokerDNSType [256]byte

// 语句类型
type TThostFtdcSentenceType [501]byte

// 结算账户类型
type TThostFtdcClearAccountType [33]byte

// 结算账户类型
type TThostFtdcOrganNOType [6]byte

// 结算账户联行号类型
type TThostFtdcClearbarchIDType [6]byte

// 用户事件信息类型
type TThostFtdcUserEventInfoType [1025]byte

// 预埋报单编号类型
type TThostFtdcParkedOrderIDType [13]byte

// 预埋撤单编号类型
type TThostFtdcParkedOrderActionIDType [13]byte

// 影像类型名称类型
type TThostFtdcPhotoTypeNameType [41]byte

// 影像类型代码类型
type TThostFtdcPhotoTypeIDType [5]byte

// 影像名称类型
type TThostFtdcPhotoNameType [161]byte

// 交易报告类型标识类型
type TThostFtdcReportTypeIDType [3]byte

// 交易特征代码类型
type TThostFtdcCharacterIDType [5]byte

// 参数代码类型
type TThostFtdcAMLParamIDType [21]byte

// 投资者类型类型
type TThostFtdcAMLInvestorTypeType [3]byte

// 证件类型类型
type TThostFtdcAMLIdCardTypeType [3]byte

// 资金进出方向类型
type TThostFtdcAMLTradeDirectType [3]byte

// 资金进出方式类型
type TThostFtdcAMLTradeModelType [3]byte

// 客户身份证件/证明文件类型类型
type TThostFtdcAMLCustomerCardTypeType [81]byte

// 金融机构网点名称类型
type TThostFtdcAMLInstitutionNameType [65]byte

// 金融机构网点所在地区行政区划代码类型
type TThostFtdcAMLDistrictIDType [7]byte

// 金融机构网点与大额交易的关系类型
type TThostFtdcAMLRelationShipType [3]byte

// 金融机构网点代码类型类型
type TThostFtdcAMLInstitutionTypeType [3]byte

// 金融机构网点代码类型
type TThostFtdcAMLInstitutionIDType [13]byte

// 账户类型类型
type TThostFtdcAMLAccountTypeType [5]byte

// 交易方式类型
type TThostFtdcAMLTradingTypeType [7]byte

// 涉外收支交易分类与代码类型
type TThostFtdcAMLTransactClassType [7]byte

// 资金收付标识类型
type TThostFtdcAMLCapitalIOType [3]byte

// 交易地点类型
type TThostFtdcAMLSiteType [10]byte

// 资金用途类型
type TThostFtdcAMLCapitalPurposeType [129]byte

// 报文类型类型
type TThostFtdcAMLReportTypeType [2]byte

// 编号类型
type TThostFtdcAMLSerialNoType [5]byte

// 状态类型
type TThostFtdcAMLStatusType [2]byte

// 业务标识号类型
type TThostFtdcAMLSeqCodeType [65]byte

// AML文件名类型
type TThostFtdcAMLFileNameType [257]byte

// 密钥类型(保证金监管)类型
type TThostFtdcCFMMCKeyType [21]byte

// 令牌类型(保证金监管)类型
type TThostFtdcCFMMCTokenType [21]byte

// 报文名称类型
type TThostFtdcAMLReportNameType [81]byte

// 个人姓名类型
type TThostFtdcIndividualNameType [51]byte

// 币种代码类型
type TThostFtdcCurrencyIDType [4]byte

// 客户编号类型
type TThostFtdcCustNumberType [36]byte

// 机构编码类型
type TThostFtdcOrganCodeType [36]byte

// 机构名称类型
type TThostFtdcOrganNameType [71]byte

// 上级机构编码,即期货公司总部、银行总行类型
type TThostFtdcSuperOrganCodeType [12]byte

// 分支机构类型
type TThostFtdcSubBranchIDType [31]byte

// 分支机构名称类型
type TThostFtdcSubBranchNameType [71]byte

// 机构网点号类型
type TThostFtdcBranchNetCodeType [31]byte

// 机构网点名称类型
type TThostFtdcBranchNetNameType [71]byte

// 机构标识类型
type TThostFtdcOrganFlagType [2]byte

// 银行对期货公司的编码类型
type TThostFtdcBankCodingForFutureType [33]byte

// 银行对返回码的定义类型
type TThostFtdcBankReturnCodeType [7]byte

// 银期转帐平台对返回码的定义类型
type TThostFtdcPlateReturnCodeType [5]byte

// 银行分支机构编码类型
type TThostFtdcBankSubBranchIDType [31]byte

// 期货分支机构编码类型
type TThostFtdcFutureBranchIDType [31]byte

// 返回代码类型
type TThostFtdcReturnCodeType [7]byte

// 操作员类型
type TThostFtdcOperatorCodeType [17]byte

// 机构结算帐户机构号类型
type TThostFtdcClearDepIDType [6]byte

// 机构结算帐户联行号类型
type TThostFtdcClearBrchIDType [6]byte

// 机构结算帐户名称类型
type TThostFtdcClearNameType [71]byte

// 银行帐户名称类型
type TThostFtdcBankAccountNameType [71]byte

// 机构投资人账号机构号类型
type TThostFtdcInvDepIDType [6]byte

// 机构投资人联行号类型
type TThostFtdcInvBrchIDType [6]byte

// 信息格式版本类型
type TThostFtdcMessageFormatVersionType [36]byte

// 摘要类型
type TThostFtdcDigestType [36]byte

// 认证数据类型
type TThostFtdcAuthenticDataType [129]byte

// 密钥类型
type TThostFtdcPasswordKeyType [129]byte

// 期货帐户名称类型
type TThostFtdcFutureAccountNameType [129]byte

// 手机类型
type TThostFtdcMobilePhoneType [21]byte

// 期货公司主密钥类型
type TThostFtdcFutureMainKeyType [129]byte

// 期货公司工作密钥类型
type TThostFtdcFutureWorkKeyType [129]byte

// 期货公司传输密钥类型
type TThostFtdcFutureTransKeyType [129]byte

// 银行主密钥类型
type TThostFtdcBankMainKeyType [129]byte

// 银行工作密钥类型
type TThostFtdcBankWorkKeyType [129]byte

// 银行传输密钥类型
type TThostFtdcBankTransKeyType [129]byte

// 银行服务器描述信息类型
type TThostFtdcBankServerDescriptionType [129]byte

// 附加信息类型
type TThostFtdcAddInfoType [129]byte

// 返回码描述类型
type TThostFtdcDescrInfoForReturnCodeType [129]byte

// 国家代码类型
type TThostFtdcCountryCodeType [21]byte

// 银行流水号类型
type TThostFtdcBankSerialType [13]byte

// 服务名类型
type TThostFtdcServiceNameType [61]byte

// 银行自己的编码类型
type TThostFtdcBankIDByBankType [21]byte

// 银行操作员号类型
type TThostFtdcBankOperNoType [4]byte

// 银行客户号类型
type TThostFtdcBankCustNoType [21]byte

// FBT表名类型
type TThostFtdcTableNameType [61]byte

// FBT表操作主键名类型
type TThostFtdcPKNameType [201]byte

// FBT表操作主键值类型
type TThostFtdcPKValueType [501]byte

// 同步目标编号类型
type TThostFtdcTargetIDType [4]byte

// 各种换汇时间类型
type TThostFtdcFBETimeType [7]byte

// 换汇银行行号类型
type TThostFtdcFBEBankNoType [13]byte

// 换汇凭证号类型
type TThostFtdcFBECertNoType [13]byte

// 换汇银行账户类型
type TThostFtdcFBEBankAccountType [33]byte

// 换汇银行账户名类型
type TThostFtdcFBEBankAccountNameType [61]byte

// 换汇业务类型类型
type TThostFtdcFBEBusinessTypeType [3]byte

// 换汇附言类型
type TThostFtdcFBEPostScriptType [61]byte

// 换汇备注类型
type TThostFtdcFBERemarkType [71]byte

// 换汇返回信息类型
type TThostFtdcFBERtnMsgType [61]byte

// 换汇扩展信息类型
type TThostFtdcFBEExtendMsgType [61]byte

// 换汇记账流水号类型
type TThostFtdcFBEBusinessSerialType [31]byte

// 换汇流水号类型
type TThostFtdcFBESystemSerialType [21]byte

// 换汇账户开户行类型
type TThostFtdcFBEOpenBankType [61]byte

// 换汇相关文件名类型
type TThostFtdcFBEFileNameType [21]byte

// 换汇批次号类型
type TThostFtdcFBEBatchSerialType [21]byte

// 客户风险通知消息类型
type TThostFtdcRiskNofityInfoType [257]byte

// 强平场景编号类型
type TThostFtdcForceCloseSceneIdType [24]byte

// 多个产品代码,用+分隔,如cu+zn类型
type TThostFtdcInstrumentIDsType [101]byte

// 参数名类型
type TThostFtdcParamNameType [41]byte

// 参数值类型
type TThostFtdcParamValueType [41]byte

// 行业编码类型
type TThostFtdcIndustryIDType [17]byte

// 特有信息编号类型
type TThostFtdcQuestionIDType [5]byte

// 特有信息说明类型
type TThostFtdcQuestionContentType [41]byte

// 选项编号类型
type TThostFtdcOptionIDType [13]byte

// 选项说明类型
type TThostFtdcOptionContentType [61]byte

// 业务流水号类型
type TThostFtdcProcessIDType [33]byte

// 流程状态类型
type TThostFtdcUOAProcessStatusType [3]byte

// 流程功能类型类型
type TThostFtdcProcessTypeType [3]byte

// 客户分类码类型
type TThostFtdcClientClassifyType [11]byte

// 单位性质类型
type TThostFtdcUOAOrganTypeType [11]byte

// 国家代码类型
type TThostFtdcUOACountryCodeType [11]byte

// 区号类型
type TThostFtdcAreaCodeType [11]byte

// 监控中心为客户分配的代码类型
type TThostFtdcFuturesIDType [21]byte

// 日期类型
type TThostFtdcCffmcDateType [11]byte

// 时间类型
type TThostFtdcCffmcTimeType [11]byte

// 组织机构代码类型
type TThostFtdcNocIDType [21]byte

// 业务操作类型类型
type TThostFtdcEventTypeType [33]byte

// 模型名称类型
type TThostFtdcRateTemplateNameType [61]byte

// 用于查询的投资属性字段类型
type TThostFtdcPropertyStringType [2049]byte

// 模型代码类型
type TThostFtdcRateTemplateIDType [9]byte

// 风险度类型
type TThostFtdcRiskRateType [21]byte

// 号段规则名称类型
type TThostFtdcInvestorIDRuleNameType [61]byte

// 号段规则表达式类型
type TThostFtdcInvestorIDRuleExprType [513]byte

// 令牌密钥类型
type TThostFtdcAuthKeyType [41]byte

// 序列号类型
type TThostFtdcSerialNumberType [17]byte

// 动态令牌提供商类型
type TThostFtdcOTPVendorsIDType [2]byte

// 动态令牌提供商名称类型
type TThostFtdcOTPVendorsNameType [61]byte

// 时间跨度类型
type TThostFtdcTimeSpanType [9]byte

// 动态令牌导入批次编号类型
type TThostFtdcImportSequenceIDType [17]byte

// 产品标识类型
type TThostFtdcUserProductIDType [33]byte

// 产品名称类型
type TThostFtdcUserProductNameType [65]byte

// 产品说明类型
type TThostFtdcUserProductMemoType [129]byte

// 新增或变更标志类型
type TThostFtdcCSRCCancelFlagType [2]byte

// 日期类型
type TThostFtdcCSRCDateType [11]byte

// 客户名称类型
type TThostFtdcCSRCInvestorNameType [201]byte

// 客户名称类型
type TThostFtdcCSRCOpenInvestorNameType [101]byte

// 客户代码类型
type TThostFtdcCSRCInvestorIDType [13]byte

// 证件号码类型
type TThostFtdcCSRCIdentifiedCardNoType [51]byte

// 交易编码类型
type TThostFtdcCSRCClientIDType [11]byte

// 银行标识类型
type TThostFtdcCSRCBankFlagType [3]byte

// 银行账户类型
type TThostFtdcCSRCBankAccountType [23]byte

// 开户人类型
type TThostFtdcCSRCOpenNameType [401]byte

// 说明类型
type TThostFtdcCSRCMemoType [101]byte

// 时间类型
type TThostFtdcCSRCTimeType [11]byte

// 成交流水号类型
type TThostFtdcCSRCTradeIDType [21]byte

// 合约代码类型
type TThostFtdcCSRCExchangeInstIDType [31]byte

// 质押品名称类型
type TThostFtdcCSRCMortgageNameType [7]byte

// 事由类型
type TThostFtdcCSRCReasonType [3]byte

// 是否为非结算会员类型
type TThostFtdcIsSettlementType [2]byte

// 期权类型类型
type TThostFtdcCSRCOptionsTypeType [2]byte

// 标的品种类型
type TThostFtdcCSRCTargetProductIDType [3]byte

// 标的合约类型
type TThostFtdcCSRCTargetInstrIDType [31]byte

// 手续费率模板名称类型
type TThostFtdcCommModelNameType [161]byte

// 手续费率模板备注类型
type TThostFtdcCommModelMemoType [1025]byte

// 代理经纪公司代码类型
type TThostFtdcAgentBrokerIDType [13]byte

// 交易中心名称类型
type TThostFtdcDRIdentityNameType [65]byte

// DBLink标识号类型
type TThostFtdcDBLinkIDType [31]byte

// 风险度类型
type TThostFtdcSRiskRateType [21]byte

// 休眠状态类型
type TThostFtdcCSRCFreezeStatusType [2]byte

// 模板代码类型
type TThostFtdcRightTemplateIDType [9]byte

// 模板名称类型
type TThostFtdcRightTemplateNameType [61]byte

// 反洗钱数据抽取审核流程类型
type TThostFtdcAmlCheckFlowType [2]byte

// 数据类型类型
type TThostFtdcDataTypeType [129]byte

// 结算配置代码类型
type TThostFtdcSettleManagerIDType [33]byte

// 结算配置名称类型
type TThostFtdcSettleManagerNameType [129]byte

// 核对结果说明类型
type TThostFtdcCheckResultMemoType [1025]byte

// 功能链接类型
type TThostFtdcFunctionUrlType [1025]byte

// 客户端认证信息类型
type TThostFtdcAuthInfoType [129]byte

// 客户端认证码类型
type TThostFtdcAuthCodeType [17]byte

// 工具代码类型
type TThostFtdcToolIDType [9]byte

// 工具名称类型
type TThostFtdcToolNameType [81]byte

// 币种名称类型
type TThostFtdcCurrencyNameType [31]byte

// 币种符号类型
type TThostFtdcCurrencySignType [4]byte

// 凭证号类型
type TThostFtdcCurrExchCertNoType [13]byte

// 批次号类型
type TThostFtdcBatchSerialNoType [21]byte

// 换汇页面控制类型
type TThostFtdcPageControlType [2]byte

// 换汇需确认信息类型
type TThostFtdcCurrencySwapMemoType [101]byte

// 工作单位类型
type TThostFtdcWorkPlaceType [101]byte

// 经营期限类型
type TThostFtdcBusinessPeriodType [21]byte

// 网址类型
type TThostFtdcWebSiteType [101]byte

// 统一开户证件类型类型
type TThostFtdcUOAIdCardTypeType [3]byte

// 开户模式类型
type TThostFtdcClientModeType [3]byte

// 投资者全称类型
type TThostFtdcInvestorFullNameType [101]byte

// 境外中介机构ID类型
type TThostFtdcUOABrokerIDType [11]byte

// 邮政编码类型
type TThostFtdcUOAZipCodeType [11]byte

// 电子邮箱类型
type TThostFtdcUOAEMailType [101]byte

// 城市类型
type TThostFtdcOldCityType [41]byte

// 法人代表证件号码类型
type TThostFtdcCorporateIdentifiedCardNoType [101]byte

// 分户管理资产编码类型
type TThostFtdcLedgerManageIDType [51]byte

// 投资品种类型
type TThostFtdcInvestVarietyType [101]byte

// 账户类别类型
type TThostFtdcBankAccountTypeType [2]byte

// 开户银行类型
type TThostFtdcLedgerManageBankType [101]byte

// 开户营业部类型
type TThostFtdcCffexDepartmentNameType [101]byte

// 营业部代码类型
type TThostFtdcCffexDepartmentCodeType [9]byte

// 说明类型
type TThostFtdcCSRCMemo1Type [41]byte

// 代理资产管理业务的期货公司全称类型
type TThostFtdcAssetmgrCFullNameType [101]byte

// 资产管理业务批文号类型
type TThostFtdcAssetmgrApprovalNOType [51]byte

// 资产管理业务负责人姓名类型
type TThostFtdcAssetmgrMgrNameType [401]byte

// 机构类型类型
type TThostFtdcCSRCAmTypeType [5]byte

// 国籍类型
type TThostFtdcCSRCNationalType [4]byte

// 二级代理ID类型
type TThostFtdcCSRCSecAgentIDType [11]byte

// 投资账户类型
type TThostFtdcAmAccountType [23]byte

// 计量单位类型
type TThostFtdcUOMType [11]byte

// 上期所合约生命周期状态类型
type TThostFtdcSHFEInstLifePhaseType [3]byte

// 产品类型类型
type TThostFtdcSHFEProductClassType [11]byte

// 价格小数位类型
type TThostFtdcPriceDecimalType [2]byte

// 平值期权标志类型
type TThostFtdcInTheMoneyFlagType [2]byte

// 套利合约代码类型
type TThostFtdcCombinInstrIDType [61]byte

// 各腿结算价类型
type TThostFtdcCombinSettlePriceType [61]byte

// 换汇业务种类类型
type TThostFtdcSwapBusinessTypeType [3]byte

// 执行宣告系统编号类型
type TThostFtdcExecOrderSysIDType [21]byte

// 执行时间类型
type TThostFtdcStrikeTimeType [13]byte

// 登录备注类型
type TThostFtdcLoginRemarkType [36]byte

// 投资单元代码类型
type TThostFtdcInvestUnitIDType [17]byte

// 公告类型类型
type TThostFtdcNewsTypeType [3]byte

// 消息摘要类型
type TThostFtdcAbstractType [81]byte

// 消息来源类型
type TThostFtdcComeFromType [21]byte

// WEB地址类型
type TThostFtdcURLLinkType [201]byte

// 长个人姓名类型
type TThostFtdcLongIndividualNameType [161]byte

// 长换汇银行账户名类型
type TThostFtdcLongFBEBankAccountNameType [161]byte

// 日期时间类型
type TThostFtdcDateTimeType [17]byte

// 随机串类型
type TThostFtdcRandomStringType [17]byte

// App代码类型
type TThostFtdcAppIDType [33]byte

// 交易终端系统信息类型
type TThostFtdcClientSystemInfoType [273]byte

// 系统外部信息类型
type TThostFtdcAdditionalInfoType [261]byte

// base64交易终端系统信息类型
type TThostFtdcBase64ClientSystemInfoType [365]byte

// base64系统外部信息类型
type TThostFtdcBase64AdditionalInfoType [349]byte

// 图片验证信息类型
type TThostFtdcCaptchaInfoType [2561]byte

// 握手数据内容类型
type TThostFtdcHandshakeDataType [301]byte

// api与front通信密钥版本号类型
type TThostFtdcCryptoKeyVersionType [31]byte

// 交易软件商ID类型
type TThostFtdcSoftwareProviderIDType [22]byte

// 信息采集时间类型
type TThostFtdcCollectTimeType [21]byte

// OTC交易员代码类型
type TThostFtdcOTCTraderIDType [31]byte

// 握手数据内容类型
type TThostFtdcIDBNameType [100]byte

// 追平描述类型
type TThostFtdcSyncDescriptionType [257]byte

// IP端口类型
type TThostFtdcIPPortType int32

// 报单操作引用类型
type TThostFtdcOrderActionRefType int32

// 安装数量类型
type TThostFtdcInstallCountType int32

// 安装编号类型
type TThostFtdcInstallIDType int32

// 错误代码类型
type TThostFtdcErrorIDType int32

// 结算编号类型
type TThostFtdcSettlementIDType int32

// 数量类型
type TThostFtdcVolumeType int32

// 前置编号类型
type TThostFtdcFrontIDType int32

// 会话编号类型
type TThostFtdcSessionIDType int32

// 序号类型
type TThostFtdcSequenceNoType int32

// DB命令序号类型
type TThostFtdcCommandNoType int32

// 时间（毫秒）类型
type TThostFtdcMillisecType int32

// 时间（秒）类型
type TThostFtdcSecType int32

// 合约数量乘数类型
type TThostFtdcVolumeMultipleType int32

// 交易阶段编号类型
type TThostFtdcTradingSegmentSNType int32

// 请求编号类型
type TThostFtdcRequestIDType int32

// 年份类型
type TThostFtdcYearType int32

// 月份类型
type TThostFtdcMonthType int32

// 布尔型类型
type TThostFtdcBoolType int32

// 优先级类型
type TThostFtdcPriorityType int32

// 分项资金流水号类型
type TThostFtdcSubEntryFundNoType int32

// 月份数量类型
type TThostFtdcMonthCountType int32

// 发起方流水号类型
type TThostFtdcTradeSerialNoType int32

// 单腿编号类型
type TThostFtdcLegIDType int32

// 单腿乘数类型
type TThostFtdcLegMultipleType int32

// 派生层数类型
type TThostFtdcImplyLevelType int32

// 主题代码类型
type TThostFtdcTopicIDType int32

// 反洗钱资金类型
type TThostFtdcAMLFileAmountType int32

// 流水号类型
type TThostFtdcSerialType int32

// 平台流水号类型
type TThostFtdcPlateSerialType int32

// 被冲正交易流水号类型
type TThostFtdcCorrectSerialType int32

// 期货公司流水号类型
type TThostFtdcFutureSerialType int32

// 应用标识类型
type TThostFtdcApplicationIDType int32

// 银行代理标识类型
type TThostFtdcBankProxyIDType int32

// 银期转帐核心系统标识类型
type TThostFtdcFBTCoreIDType int32

// 服务端口号类型
type TThostFtdcServerPortType int32

// 已经冲正次数类型
type TThostFtdcRepealedTimesType int32

// 冲正时间间隔类型
type TThostFtdcRepealTimeIntervalType int32

// 每日累计转帐次数类型
type TThostFtdcTotalTimesType int32

// 请求ID类型
type TThostFtdcFBTRequestIDType int32

// 交易ID类型
type TThostFtdcTIDType int32

// 服务编号类型
type TThostFtdcServiceIDType int32

// 服务线路编号类型
type TThostFtdcServiceLineNoType int32

// 通讯API指针类型
type TThostFtdcCommApiPointerType int32

// 递增的序列号类型
type TThostFtdcDBOPSeqNoType int32

// 换汇交易总笔数类型
type TThostFtdcFBETotalExCntType int32

// 参数代码类型
type TThostFtdcParamIDType int32

// 流水号类型
type TThostFtdcSeqNoType int32

// 交易所返回码类型
type TThostFtdcExReturnCodeType int32

// 查询深度类型
type TThostFtdcQueryDepthType int32

// 数据中心代码类型
type TThostFtdcDataCenterIDType int32

// 操作次数类型
type TThostFtdcCheckNoType int32

// 时间戳类型
type TThostFtdcTimestampType int32

// 上次OTP漂移值类型
type TThostFtdcLastDriftType int32

// 上次OTP成功值类型
type TThostFtdcLastSuccessType int32

// 组合成交类型类型
type TThostFtdcComTypeType int32

// 交易中心代码类型
type TThostFtdcDRIdentityIDType int32

// 序号类型
type TThostFtdcSequenceNo12Type int32

// 记录数类型
type TThostFtdcRecordCountType int32

// 优先级类型
type TThostFtdcDCEPriorityType int32

// 成交组号类型
type TThostFtdcTradeGroupIDType int32

// 是否校验开户可用资金类型
type TThostFtdcIsCheckPrepaType int32

// 执行序号类型
type TThostFtdcStrikeSequenceType int32

// 公告编号类型
type TThostFtdcBulletinIDType int32

// 系统信息长度类型
type TThostFtdcSystemInfoLenType int32

// 补充信息长度类型
type TThostFtdcAdditionalInfoLenType int32

// 当前可用的认证模式，0代表无需认证模式 A从低位开始最后一位代表图片验证码，倒数第二位代表动态口令，倒数第三位代表短信验证码类型
type TThostFtdcCurrentAuthMethodType int32

// 图片验证信息长度类型
type TThostFtdcCaptchaInfoLenType int32

// 用户短信验证码的编号类型
type TThostFtdcUserTextSeqType int32

// 握手数据内容长度类型
type TThostFtdcHandshakeDataLenType int32

// 公钥版本号类型
type TThostFtdcRsaKeyVersionType int32

// 查询频率类型
type TThostFtdcQueryFreqType int32

// 交易所属性类型
type TThostFtdcExchangePropertyType byte

// 正常
const THOST_FTDC_EXP_Normal = '0'

// 根据成交生成报单
const THOST_FTDC_EXP_GenOrderByTrade = '1'

// 证件类型类型
type TThostFtdcIdCardTypeType byte

// 组织机构代码
const THOST_FTDC_ICT_EID = '0'

// 中国公民身份证
const THOST_FTDC_ICT_IDCard = '1'

// 军官证
const THOST_FTDC_ICT_OfficerIDCard = '2'

// 警官证
const THOST_FTDC_ICT_PoliceIDCard = '3'

// 士兵证
const THOST_FTDC_ICT_SoldierIDCard = '4'

// 户口簿
const THOST_FTDC_ICT_HouseholdRegister = '5'

// 护照
const THOST_FTDC_ICT_Passport = '6'

// 台胞证
const THOST_FTDC_ICT_TaiwanCompatriotIDCard = '7'

// 回乡证
const THOST_FTDC_ICT_HomeComingCard = '8'

// 营业执照号
const THOST_FTDC_ICT_LicenseNo = '9'

// 税务登记号/当地纳税ID
const THOST_FTDC_ICT_TaxNo = 'A'

// 港澳居民来往内地通行证
const THOST_FTDC_ICT_HMMainlandTravelPermit = 'B'

// 台湾居民来往大陆通行证
const THOST_FTDC_ICT_TwMainlandTravelPermit = 'C'

// 驾照
const THOST_FTDC_ICT_DrivingLicense = 'D'

// 当地社保ID
const THOST_FTDC_ICT_SocialID = 'F'

// 当地身份证
const THOST_FTDC_ICT_LocalID = 'G'

// 商业登记证
const THOST_FTDC_ICT_BusinessRegistration = 'H'

// 港澳永久性居民身份证
const THOST_FTDC_ICT_HKMCIDCard = 'I'

// 人行开户许可证
const THOST_FTDC_ICT_AccountsPermits = 'J'

// 外国人永久居留证
const THOST_FTDC_ICT_FrgPrmtRdCard = 'K'

// 资管产品备案函
const THOST_FTDC_ICT_CptMngPrdLetter = 'L'

// 统一社会信用代码
const THOST_FTDC_ICT_UniformSocialCreditCode = 'N'

// 机构成立证明文件
const THOST_FTDC_ICT_CorporationCertNo = 'O'

// 其他证件
const THOST_FTDC_ICT_OtherCard = 'x'

// 投资者范围类型
type TThostFtdcInvestorRangeType byte

// 所有
const THOST_FTDC_IR_All = '1'

// 投资者组
const THOST_FTDC_IR_Group = '2'

// 单一投资者
const THOST_FTDC_IR_Single = '3'

// 投资者范围类型
type TThostFtdcDepartmentRangeType byte

// 所有
const THOST_FTDC_DR_All = '1'

// 组织架构
const THOST_FTDC_DR_Group = '2'

// 单一投资者
const THOST_FTDC_DR_Single = '3'

// 数据同步状态类型
type TThostFtdcDataSyncStatusType byte

// 未同步
const THOST_FTDC_DS_Asynchronous = '1'

// 同步中
const THOST_FTDC_DS_Synchronizing = '2'

// 已同步
const THOST_FTDC_DS_Synchronized = '3'

// 经纪公司数据同步状态类型
type TThostFtdcBrokerDataSyncStatusType byte

// 已同步
const THOST_FTDC_BDS_Synchronized = '1'

// 同步中
const THOST_FTDC_BDS_Synchronizing = '2'

// 交易所连接状态类型
type TThostFtdcExchangeConnectStatusType byte

// 没有任何连接
const THOST_FTDC_ECS_NoConnection = '1'

// 已经发出合约查询请求
const THOST_FTDC_ECS_QryInstrumentSent = '2'

// 已经获取信息
const THOST_FTDC_ECS_GotInformation = '9'

// 交易所交易员连接状态类型
type TThostFtdcTraderConnectStatusType byte

// 没有任何连接
const THOST_FTDC_TCS_NotConnected = '1'

// 已经连接
const THOST_FTDC_TCS_Connected = '2'

// 已经发出合约查询请求
const THOST_FTDC_TCS_QryInstrumentSent = '3'

// 订阅私有流
const THOST_FTDC_TCS_SubPrivateFlow = '4'

// 功能代码类型
type TThostFtdcFunctionCodeType byte

// 数据异步化
const THOST_FTDC_FC_DataAsync = '1'

// 强制用户登出
const THOST_FTDC_FC_ForceUserLogout = '2'

// 变更管理用户口令
const THOST_FTDC_FC_UserPasswordUpdate = '3'

// 变更经纪公司口令
const THOST_FTDC_FC_BrokerPasswordUpdate = '4'

// 变更投资者口令
const THOST_FTDC_FC_InvestorPasswordUpdate = '5'

// 报单插入
const THOST_FTDC_FC_OrderInsert = '6'

// 报单操作
const THOST_FTDC_FC_OrderAction = '7'

// 同步系统数据
const THOST_FTDC_FC_SyncSystemData = '8'

// 同步经纪公司数据
const THOST_FTDC_FC_SyncBrokerData = '9'

// 批量同步经纪公司数据
const THOST_FTDC_FC_BachSyncBrokerData = 'A'

// 超级查询
const THOST_FTDC_FC_SuperQuery = 'B'

// 预埋报单插入
const THOST_FTDC_FC_ParkedOrderInsert = 'C'

// 预埋报单操作
const THOST_FTDC_FC_ParkedOrderAction = 'D'

// 同步动态令牌
const THOST_FTDC_FC_SyncOTP = 'E'

// 删除未知单
const THOST_FTDC_FC_DeleteOrder = 'F'

// 经纪公司功能代码类型
type TThostFtdcBrokerFunctionCodeType byte

// 强制用户登出
const THOST_FTDC_BFC_ForceUserLogout = '1'

// 变更用户口令
const THOST_FTDC_BFC_UserPasswordUpdate = '2'

// 同步经纪公司数据
const THOST_FTDC_BFC_SyncBrokerData = '3'

// 批量同步经纪公司数据
const THOST_FTDC_BFC_BachSyncBrokerData = '4'

// 报单插入
const THOST_FTDC_BFC_OrderInsert = '5'

// 报单操作
const THOST_FTDC_BFC_OrderAction = '6'

// 全部查询
const THOST_FTDC_BFC_AllQuery = '7'

// 系统功能：登入/登出/修改密码等
const THOST_FTDC_BFC_log = 'a'

// 基本查询：查询基础数据，如合约，交易所等常量
const THOST_FTDC_BFC_BaseQry = 'b'

// 交易查询：如查成交，委托
const THOST_FTDC_BFC_TradeQry = 'c'

// 交易功能：报单，撤单
const THOST_FTDC_BFC_Trade = 'd'

// 银期转账
const THOST_FTDC_BFC_Virement = 'e'

// 风险监控
const THOST_FTDC_BFC_Risk = 'f'

// 查询/管理：查询会话，踢人等
const THOST_FTDC_BFC_Session = 'g'

// 风控通知控制
const THOST_FTDC_BFC_RiskNoticeCtl = 'h'

// 风控通知发送
const THOST_FTDC_BFC_RiskNotice = 'i'

// 察看经纪公司资金权限
const THOST_FTDC_BFC_BrokerDeposit = 'j'

// 资金查询
const THOST_FTDC_BFC_QueryFund = 'k'

// 报单查询
const THOST_FTDC_BFC_QueryOrder = 'l'

// 成交查询
const THOST_FTDC_BFC_QueryTrade = 'm'

// 持仓查询
const THOST_FTDC_BFC_QueryPosition = 'n'

// 行情查询
const THOST_FTDC_BFC_QueryMarketData = 'o'

// 用户事件查询
const THOST_FTDC_BFC_QueryUserEvent = 'p'

// 风险通知查询
const THOST_FTDC_BFC_QueryRiskNotify = 'q'

// 出入金查询
const THOST_FTDC_BFC_QueryFundChange = 'r'

// 投资者信息查询
const THOST_FTDC_BFC_QueryInvestor = 's'

// 交易编码查询
const THOST_FTDC_BFC_QueryTradingCode = 't'

// 强平
const THOST_FTDC_BFC_ForceClose = 'u'

// 压力测试
const THOST_FTDC_BFC_PressTest = 'v'

// 权益反算
const THOST_FTDC_BFC_RemainCalc = 'w'

// 净持仓保证金指标
const THOST_FTDC_BFC_NetPositionInd = 'x'

// 风险预算
const THOST_FTDC_BFC_RiskPredict = 'y'

// 数据导出
const THOST_FTDC_BFC_DataExport = 'z'

// 风控指标设置
const THOST_FTDC_BFC_RiskTargetSetup = 'A'

// 行情预警
const THOST_FTDC_BFC_MarketDataWarn = 'B'

// 业务通知查询
const THOST_FTDC_BFC_QryBizNotice = 'C'

// 业务通知模板设置
const THOST_FTDC_BFC_CfgBizNotice = 'D'

// 同步动态令牌
const THOST_FTDC_BFC_SyncOTP = 'E'

// 发送业务通知
const THOST_FTDC_BFC_SendBizNotice = 'F'

// 风险级别标准设置
const THOST_FTDC_BFC_CfgRiskLevelStd = 'G'

// 交易终端应急功能
const THOST_FTDC_BFC_TbCommand = 'H'

// 删除未知单
const THOST_FTDC_BFC_DeleteOrder = 'J'

// 预埋报单插入
const THOST_FTDC_BFC_ParkedOrderInsert = 'K'

// 预埋报单操作
const THOST_FTDC_BFC_ParkedOrderAction = 'L'

// 资金不够仍允许行权
const THOST_FTDC_BFC_ExecOrderNoCheck = 'M'

// 指定
const THOST_FTDC_BFC_Designate = 'N'

// 证券处置
const THOST_FTDC_BFC_StockDisposal = 'O'

// 席位资金预警
const THOST_FTDC_BFC_BrokerDepositWarn = 'Q'

// 备兑不足预警
const THOST_FTDC_BFC_CoverWarn = 'S'

// 行权试算
const THOST_FTDC_BFC_PreExecOrder = 'T'

// 行权交收风险
const THOST_FTDC_BFC_ExecOrderRisk = 'P'

// 持仓限额预警
const THOST_FTDC_BFC_PosiLimitWarn = 'U'

// 持仓限额查询
const THOST_FTDC_BFC_QryPosiLimit = 'V'

// 银期签到签退
const THOST_FTDC_BFC_FBSign = 'W'

// 银期签约解约
const THOST_FTDC_BFC_FBAccount = 'X'

// 报单操作状态类型
type TThostFtdcOrderActionStatusType byte

// 已经提交
const THOST_FTDC_OAS_Submitted = 'a'

// 已经接受
const THOST_FTDC_OAS_Accepted = 'b'

// 已经被拒绝
const THOST_FTDC_OAS_Rejected = 'c'

// 报单状态类型
type TThostFtdcOrderStatusType byte

// 全部成交
const THOST_FTDC_OST_AllTraded = '0'

// 部分成交还在队列中
const THOST_FTDC_OST_PartTradedQueueing = '1'

// 部分成交不在队列中
const THOST_FTDC_OST_PartTradedNotQueueing = '2'

// 未成交还在队列中
const THOST_FTDC_OST_NoTradeQueueing = '3'

// 未成交不在队列中
const THOST_FTDC_OST_NoTradeNotQueueing = '4'

// 撤单
const THOST_FTDC_OST_Canceled = '5'

// 未知
const THOST_FTDC_OST_Unknown = 'a'

// 尚未触发
const THOST_FTDC_OST_NotTouched = 'b'

// 已触发
const THOST_FTDC_OST_Touched = 'c'

// 报单提交状态类型
type TThostFtdcOrderSubmitStatusType byte

// 已经提交
const THOST_FTDC_OSS_InsertSubmitted = '0'

// 撤单已经提交
const THOST_FTDC_OSS_CancelSubmitted = '1'

// 修改已经提交
const THOST_FTDC_OSS_ModifySubmitted = '2'

// 已经接受
const THOST_FTDC_OSS_Accepted = '3'

// 报单已经被拒绝
const THOST_FTDC_OSS_InsertRejected = '4'

// 撤单已经被拒绝
const THOST_FTDC_OSS_CancelRejected = '5'

// 改单已经被拒绝
const THOST_FTDC_OSS_ModifyRejected = '6'

// 持仓日期类型
type TThostFtdcPositionDateType byte

// 今日持仓
const THOST_FTDC_PSD_Today = '1'

// 历史持仓
const THOST_FTDC_PSD_History = '2'

// 持仓日期类型类型
type TThostFtdcPositionDateTypeType byte

// 使用历史持仓
const THOST_FTDC_PDT_UseHistory = '1'

// 不使用历史持仓
const THOST_FTDC_PDT_NoUseHistory = '2'

// 交易角色类型
type TThostFtdcTradingRoleType byte

// 代理
const THOST_FTDC_ER_Broker = '1'

// 自营
const THOST_FTDC_ER_Host = '2'

// 做市商
const THOST_FTDC_ER_Maker = '3'

// 产品类型类型
type TThostFtdcProductClassType byte

// 期货
const THOST_FTDC_PC_Futures = '1'

// 期货期权
const THOST_FTDC_PC_Options = '2'

// 组合
const THOST_FTDC_PC_Combination = '3'

// 即期
const THOST_FTDC_PC_Spot = '4'

// 期转现
const THOST_FTDC_PC_EFP = '5'

// 现货期权
const THOST_FTDC_PC_SpotOption = '6'

//  TAS合约
const THOST_FTDC_PC_TAS = '7'

// 金属指数
const THOST_FTDC_PC_MI = 'I'

// 产品类型类型
type TThostFtdcAPIProductClassType byte

// 期货单一合约
const THOST_FTDC_APC_FutureSingle = '1'

// 期权单一合约
const THOST_FTDC_APC_OptionSingle = '2'

// 可交易期货(含期货组合和期货单一合约)
const THOST_FTDC_APC_Futures = '3'

// 可交易期权(含期权组合和期权单一合约)
const THOST_FTDC_APC_Options = '4'

// 可下单组合（目前包含DCE和ZCE的期货组合）
const THOST_FTDC_APC_TradingComb = '5'

// 可申请的组合（dce可以申请的组合合约 包含dce可以交易的合约）
const THOST_FTDC_APC_UnTradingComb = '6'

// 所有可以交易合约
const THOST_FTDC_APC_AllTrading = '7'

// 所有合约（包含不能交易合约 慎用）
const THOST_FTDC_APC_All = '8'

// 合约生命周期状态类型
type TThostFtdcInstLifePhaseType byte

// 未上市
const THOST_FTDC_IP_NotStart = '0'

// 上市
const THOST_FTDC_IP_Started = '1'

// 停牌
const THOST_FTDC_IP_Pause = '2'

// 到期
const THOST_FTDC_IP_Expired = '3'

// 买卖方向类型
type TThostFtdcDirectionType byte

// 买
const THOST_FTDC_D_Buy = '0'

// 卖
const THOST_FTDC_D_Sell = '1'

// 持仓类型类型
type TThostFtdcPositionTypeType byte

// 净持仓
const THOST_FTDC_PT_Net = '1'

// 综合持仓
const THOST_FTDC_PT_Gross = '2'

// 持仓多空方向类型
type TThostFtdcPosiDirectionType byte

// 净
const THOST_FTDC_PD_Net = '1'

// 多头
const THOST_FTDC_PD_Long = '2'

// 空头
const THOST_FTDC_PD_Short = '3'

// 系统结算状态类型
type TThostFtdcSysSettlementStatusType byte

// 不活跃
const THOST_FTDC_SS_NonActive = '1'

// 启动
const THOST_FTDC_SS_Startup = '2'

// 操作
const THOST_FTDC_SS_Operating = '3'

// 结算
const THOST_FTDC_SS_Settlement = '4'

// 结算完成
const THOST_FTDC_SS_SettlementFinished = '5'

// 费率属性类型
type TThostFtdcRatioAttrType byte

// 交易费率
const THOST_FTDC_RA_Trade = '0'

// 结算费率
const THOST_FTDC_RA_Settlement = '1'

// 投机套保标志类型
type TThostFtdcHedgeFlagType byte

// 投机
const THOST_FTDC_HF_Speculation = '1'

// 套利
const THOST_FTDC_HF_Arbitrage = '2'

// 套保
const THOST_FTDC_HF_Hedge = '3'

// 做市商
const THOST_FTDC_HF_MarketMaker = '5'

// 第一腿投机第二腿套保 大商所专用
const THOST_FTDC_HF_SpecHedge = '6'

// 第一腿套保第二腿投机  大商所专用
const THOST_FTDC_HF_HedgeSpec = '7'

// 投机套保标志类型
type TThostFtdcBillHedgeFlagType byte

// 投机
const THOST_FTDC_BHF_Speculation = '1'

// 套利
const THOST_FTDC_BHF_Arbitrage = '2'

// 套保
const THOST_FTDC_BHF_Hedge = '3'

// 交易编码类型类型
type TThostFtdcClientIDTypeType byte

// 投机
const THOST_FTDC_CIDT_Speculation = '1'

// 套利
const THOST_FTDC_CIDT_Arbitrage = '2'

// 套保
const THOST_FTDC_CIDT_Hedge = '3'

// 做市商
const THOST_FTDC_CIDT_MarketMaker = '5'

// 报单价格条件类型
type TThostFtdcOrderPriceTypeType byte

// 任意价
const THOST_FTDC_OPT_AnyPrice = '1'

// 限价
const THOST_FTDC_OPT_LimitPrice = '2'

// 最优价
const THOST_FTDC_OPT_BestPrice = '3'

// 最新价
const THOST_FTDC_OPT_LastPrice = '4'

// 最新价浮动上浮1个ticks
const THOST_FTDC_OPT_LastPricePlusOneTicks = '5'

// 最新价浮动上浮2个ticks
const THOST_FTDC_OPT_LastPricePlusTwoTicks = '6'

// 最新价浮动上浮3个ticks
const THOST_FTDC_OPT_LastPricePlusThreeTicks = '7'

// 卖一价
const THOST_FTDC_OPT_AskPrice1 = '8'

// 卖一价浮动上浮1个ticks
const THOST_FTDC_OPT_AskPrice1PlusOneTicks = '9'

// 卖一价浮动上浮2个ticks
const THOST_FTDC_OPT_AskPrice1PlusTwoTicks = 'A'

// 卖一价浮动上浮3个ticks
const THOST_FTDC_OPT_AskPrice1PlusThreeTicks = 'B'

// 买一价
const THOST_FTDC_OPT_BidPrice1 = 'C'

// 买一价浮动上浮1个ticks
const THOST_FTDC_OPT_BidPrice1PlusOneTicks = 'D'

// 买一价浮动上浮2个ticks
const THOST_FTDC_OPT_BidPrice1PlusTwoTicks = 'E'

// 买一价浮动上浮3个ticks
const THOST_FTDC_OPT_BidPrice1PlusThreeTicks = 'F'

// 五档价
const THOST_FTDC_OPT_FiveLevelPrice = 'G'

// 开平标志类型
type TThostFtdcOffsetFlagType byte

// 开仓
const THOST_FTDC_OF_Open = '0'

// 平仓
const THOST_FTDC_OF_Close = '1'

// 强平
const THOST_FTDC_OF_ForceClose = '2'

// 平今
const THOST_FTDC_OF_CloseToday = '3'

// 平昨
const THOST_FTDC_OF_CloseYesterday = '4'

// 强减
const THOST_FTDC_OF_ForceOff = '5'

// 本地强平
const THOST_FTDC_OF_LocalForceClose = '6'

// 强平原因类型
type TThostFtdcForceCloseReasonType byte

// 非强平
const THOST_FTDC_FCC_NotForceClose = '0'

// 资金不足
const THOST_FTDC_FCC_LackDeposit = '1'

// 客户超仓
const THOST_FTDC_FCC_ClientOverPositionLimit = '2'

// 会员超仓
const THOST_FTDC_FCC_MemberOverPositionLimit = '3'

// 持仓非整数倍
const THOST_FTDC_FCC_NotMultiple = '4'

// 违规
const THOST_FTDC_FCC_Violation = '5'

// 其它
const THOST_FTDC_FCC_Other = '6'

// 自然人临近交割
const THOST_FTDC_FCC_PersonDeliv = '7'

// 报单类型类型
type TThostFtdcOrderTypeType byte

// 正常
const THOST_FTDC_ORDT_Normal = '0'

// 报价衍生
const THOST_FTDC_ORDT_DeriveFromQuote = '1'

// 组合衍生
const THOST_FTDC_ORDT_DeriveFromCombination = '2'

// 组合报单
const THOST_FTDC_ORDT_Combination = '3'

// 条件单
const THOST_FTDC_ORDT_ConditionalOrder = '4'

// 互换单
const THOST_FTDC_ORDT_Swap = '5'

// 大宗交易成交衍生
const THOST_FTDC_ORDT_DeriveFromBlockTrade = '6'

// 期转现成交衍生
const THOST_FTDC_ORDT_DeriveFromEFPTrade = '7'

// 有效期类型类型
type TThostFtdcTimeConditionType byte

// 立即完成，否则撤销
const THOST_FTDC_TC_IOC = '1'

// 本节有效
const THOST_FTDC_TC_GFS = '2'

// 当日有效
const THOST_FTDC_TC_GFD = '3'

// 指定日期前有效
const THOST_FTDC_TC_GTD = '4'

// 撤销前有效
const THOST_FTDC_TC_GTC = '5'

// 集合竞价有效
const THOST_FTDC_TC_GFA = '6'

// 成交量类型类型
type TThostFtdcVolumeConditionType byte

// 任何数量
const THOST_FTDC_VC_AV = '1'

// 最小数量
const THOST_FTDC_VC_MV = '2'

// 全部数量
const THOST_FTDC_VC_CV = '3'

// 触发条件类型
type TThostFtdcContingentConditionType byte

// 立即
const THOST_FTDC_CC_Immediately = '1'

// 止损
const THOST_FTDC_CC_Touch = '2'

// 止赢
const THOST_FTDC_CC_TouchProfit = '3'

// 预埋单
const THOST_FTDC_CC_ParkedOrder = '4'

// 最新价大于条件价
const THOST_FTDC_CC_LastPriceGreaterThanStopPrice = '5'

// 最新价大于等于条件价
const THOST_FTDC_CC_LastPriceGreaterEqualStopPrice = '6'

// 最新价小于条件价
const THOST_FTDC_CC_LastPriceLesserThanStopPrice = '7'

// 最新价小于等于条件价
const THOST_FTDC_CC_LastPriceLesserEqualStopPrice = '8'

// 卖一价大于条件价
const THOST_FTDC_CC_AskPriceGreaterThanStopPrice = '9'

// 卖一价大于等于条件价
const THOST_FTDC_CC_AskPriceGreaterEqualStopPrice = 'A'

// 卖一价小于条件价
const THOST_FTDC_CC_AskPriceLesserThanStopPrice = 'B'

// 卖一价小于等于条件价
const THOST_FTDC_CC_AskPriceLesserEqualStopPrice = 'C'

// 买一价大于条件价
const THOST_FTDC_CC_BidPriceGreaterThanStopPrice = 'D'

// 买一价大于等于条件价
const THOST_FTDC_CC_BidPriceGreaterEqualStopPrice = 'E'

// 买一价小于条件价
const THOST_FTDC_CC_BidPriceLesserThanStopPrice = 'F'

// 买一价小于等于条件价
const THOST_FTDC_CC_BidPriceLesserEqualStopPrice = 'H'

// 操作标志类型
type TThostFtdcActionFlagType byte

// 删除
const THOST_FTDC_AF_Delete = '0'

// 修改
const THOST_FTDC_AF_Modify = '3'

// 交易权限类型
type TThostFtdcTradingRightType byte

// 可以交易
const THOST_FTDC_TR_Allow = '0'

// 只能平仓
const THOST_FTDC_TR_CloseOnly = '1'

// 不能交易
const THOST_FTDC_TR_Forbidden = '2'

// 报单来源类型
type TThostFtdcOrderSourceType byte

// 来自参与者
const THOST_FTDC_OSRC_Participant = '0'

// 来自管理员
const THOST_FTDC_OSRC_Administrator = '1'

// 成交类型类型
type TThostFtdcTradeTypeType byte

// 组合持仓拆分为单一持仓,初始化不应包含该类型的持仓
const THOST_FTDC_TRDT_SplitCombination = '#'

// 普通成交
const THOST_FTDC_TRDT_Common = '0'

// 期权执行
const THOST_FTDC_TRDT_OptionsExecution = '1'

//  OTC成交
const THOST_FTDC_TRDT_OTC = '2'

// 期转现衍生成交
const THOST_FTDC_TRDT_EFPDerived = '3'

// 组合衍生成交
const THOST_FTDC_TRDT_CombinationDerived = '4'

// 大宗交易成交
const THOST_FTDC_TRDT_BlockTrade = '5'

// 特殊持仓明细标识类型
type TThostFtdcSpecPosiTypeType byte

// 普通持仓明细
const THOST_FTDC_SPOST_Common = '#'

//  TAS合约成交产生的标的合约持仓明细
const THOST_FTDC_SPOST_Tas = '0'

// 成交价来源类型
type TThostFtdcPriceSourceType byte

// 前成交价
const THOST_FTDC_PSRC_LastPrice = '0'

// 买委托价
const THOST_FTDC_PSRC_Buy = '1'

// 卖委托价
const THOST_FTDC_PSRC_Sell = '2'

// 场外成交价
const THOST_FTDC_PSRC_OTC = '3'

// 合约交易状态类型
type TThostFtdcInstrumentStatusType byte

// 开盘前
const THOST_FTDC_IS_BeforeTrading = '0'

// 非交易
const THOST_FTDC_IS_NoTrading = '1'

// 连续交易
const THOST_FTDC_IS_Continous = '2'

// 集合竞价报单
const THOST_FTDC_IS_AuctionOrdering = '3'

// 集合竞价价格平衡
const THOST_FTDC_IS_AuctionBalance = '4'

// 集合竞价撮合
const THOST_FTDC_IS_AuctionMatch = '5'

// 收盘
const THOST_FTDC_IS_Closed = '6'

// 品种进入交易状态原因类型
type TThostFtdcInstStatusEnterReasonType byte

// 自动切换
const THOST_FTDC_IER_Automatic = '1'

// 手动切换
const THOST_FTDC_IER_Manual = '2'

// 熔断
const THOST_FTDC_IER_Fuse = '3'

// 处理状态类型
type TThostFtdcBatchStatusType byte

// 未上传
const THOST_FTDC_BS_NoUpload = '1'

// 已上传
const THOST_FTDC_BS_Uploaded = '2'

// 审核失败
const THOST_FTDC_BS_Failed = '3'

// 按品种返还方式类型
type TThostFtdcReturnStyleType byte

// 按所有品种
const THOST_FTDC_RS_All = '1'

// 按品种
const THOST_FTDC_RS_ByProduct = '2'

// 返还模式类型
type TThostFtdcReturnPatternType byte

// 按成交手数
const THOST_FTDC_RP_ByVolume = '1'

// 按留存手续费
const THOST_FTDC_RP_ByFeeOnHand = '2'

// 返还级别类型
type TThostFtdcReturnLevelType byte

// 级别1
const THOST_FTDC_RL_Level1 = '1'

// 级别2
const THOST_FTDC_RL_Level2 = '2'

// 级别3
const THOST_FTDC_RL_Level3 = '3'

// 级别4
const THOST_FTDC_RL_Level4 = '4'

// 级别5
const THOST_FTDC_RL_Level5 = '5'

// 级别6
const THOST_FTDC_RL_Level6 = '6'

// 级别7
const THOST_FTDC_RL_Level7 = '7'

// 级别8
const THOST_FTDC_RL_Level8 = '8'

// 级别9
const THOST_FTDC_RL_Level9 = '9'

// 返还标准类型
type TThostFtdcReturnStandardType byte

// 分阶段返还
const THOST_FTDC_RSD_ByPeriod = '1'

// 按某一标准
const THOST_FTDC_RSD_ByStandard = '2'

// 质押类型类型
type TThostFtdcMortgageTypeType byte

// 质出
const THOST_FTDC_MT_Out = '0'

// 质入
const THOST_FTDC_MT_In = '1'

// 投资者结算参数代码类型
type TThostFtdcInvestorSettlementParamIDType byte

// 质押比例
const THOST_FTDC_ISPI_MortgageRatio = '4'

// 保证金算法
const THOST_FTDC_ISPI_MarginWay = '5'

// 结算单结存是否包含质押
const THOST_FTDC_ISPI_BillDeposit = '9'

// 交易所结算参数代码类型
type TThostFtdcExchangeSettlementParamIDType byte

// 质押比例
const THOST_FTDC_ESPI_MortgageRatio = '1'

// 分项资金导入项
const THOST_FTDC_ESPI_OtherFundItem = '2'

// 分项资金入交易所出入金
const THOST_FTDC_ESPI_OtherFundImport = '3'

// 中金所开户最低可用金额
const THOST_FTDC_ESPI_CFFEXMinPrepa = '6'

// 郑商所结算方式
const THOST_FTDC_ESPI_CZCESettlementType = '7'

// 交易所交割手续费收取方式
const THOST_FTDC_ESPI_ExchDelivFeeMode = '9'

// 投资者交割手续费收取方式
const THOST_FTDC_ESPI_DelivFeeMode = '0'

// 郑商所组合持仓保证金收取方式
const THOST_FTDC_ESPI_CZCEComMarginType = 'A'

// 大商所套利保证金是否优惠
const THOST_FTDC_ESPI_DceComMarginType = 'B'

// 虚值期权保证金优惠比率
const THOST_FTDC_ESPI_OptOutDisCountRate = 'a'

// 最低保障系数
const THOST_FTDC_ESPI_OptMiniGuarantee = 'b'

// 系统参数代码类型
type TThostFtdcSystemParamIDType byte

// 投资者代码最小长度
const THOST_FTDC_SPI_InvestorIDMinLength = '1'

// 投资者帐号代码最小长度
const THOST_FTDC_SPI_AccountIDMinLength = '2'

// 投资者开户默认登录权限
const THOST_FTDC_SPI_UserRightLogon = '3'

// 投资者交易结算单成交汇总方式
const THOST_FTDC_SPI_SettlementBillTrade = '4'

// 统一开户更新交易编码方式
const THOST_FTDC_SPI_TradingCode = '5'

// 结算是否判断存在未复核的出入金和分项资金
const THOST_FTDC_SPI_CheckFund = '6'

// 是否启用手续费模板数据权限
const THOST_FTDC_SPI_CommModelRight = '7'

// 是否启用保证金率模板数据权限
const THOST_FTDC_SPI_MarginModelRight = '9'

// 是否规范用户才能激活
const THOST_FTDC_SPI_IsStandardActive = '8'

// 上传的交易所结算文件路径
const THOST_FTDC_SPI_UploadSettlementFile = 'U'

// 上报保证金监控中心文件路径
const THOST_FTDC_SPI_DownloadCSRCFile = 'D'

// 生成的结算单文件路径
const THOST_FTDC_SPI_SettlementBillFile = 'S'

// 证监会文件标识
const THOST_FTDC_SPI_CSRCOthersFile = 'C'

// 投资者照片路径
const THOST_FTDC_SPI_InvestorPhoto = 'P'

// 全结经纪公司上传文件路径
const THOST_FTDC_SPI_CSRCData = 'R'

// 开户密码录入方式
const THOST_FTDC_SPI_InvestorPwdModel = 'I'

// 投资者中金所结算文件下载路径
const THOST_FTDC_SPI_CFFEXInvestorSettleFile = 'F'

// 投资者代码编码方式
const THOST_FTDC_SPI_InvestorIDType = 'a'

// 休眠户最高权益
const THOST_FTDC_SPI_FreezeMaxReMain = 'r'

// 手续费相关操作实时上场开关
const THOST_FTDC_SPI_IsSync = 'A'

// 解除开仓权限限制
const THOST_FTDC_SPI_RelieveOpenLimit = 'O'

// 是否规范用户才能休眠
const THOST_FTDC_SPI_IsStandardFreeze = 'X'

// 郑商所是否开放所有品种套保交易
const THOST_FTDC_SPI_CZCENormalProductHedge = 'B'

// 交易系统参数代码类型
type TThostFtdcTradeParamIDType byte

// 系统加密算法
const THOST_FTDC_TPID_EncryptionStandard = 'E'

// 系统风险算法
const THOST_FTDC_TPID_RiskMode = 'R'

// 系统风险算法是否全局 0-否 1-是
const THOST_FTDC_TPID_RiskModeGlobal = 'G'

// 密码加密算法
const THOST_FTDC_TPID_modeEncode = 'P'

// 价格小数位数参数
const THOST_FTDC_TPID_tickMode = 'T'

// 用户最大会话数
const THOST_FTDC_TPID_SingleUserSessionMaxNum = 'S'

// 最大连续登录失败数
const THOST_FTDC_TPID_LoginFailMaxNum = 'L'

// 是否强制认证
const THOST_FTDC_TPID_IsAuthForce = 'A'

// 是否冻结证券持仓
const THOST_FTDC_TPID_IsPosiFreeze = 'F'

// 是否限仓
const THOST_FTDC_TPID_IsPosiLimit = 'M'

// 郑商所询价时间间隔
const THOST_FTDC_TPID_ForQuoteTimeInterval = 'Q'

// 是否期货限仓
const THOST_FTDC_TPID_IsFuturePosiLimit = 'B'

// 是否期货下单频率限制
const THOST_FTDC_TPID_IsFutureOrderFreq = 'C'

// 行权冻结是否计算盈利
const THOST_FTDC_TPID_IsExecOrderProfit = 'H'

// 银期开户是否验证开户银行卡号是否是预留银行账户
const THOST_FTDC_TPID_IsCheckBankAcc = 'I'

// 弱密码最后修改日期
const THOST_FTDC_TPID_PasswordDeadLine = 'J'

// 强密码校验
const THOST_FTDC_TPID_IsStrongPassword = 'K'

// 自有资金质押比
const THOST_FTDC_TPID_BalanceMorgage = 'a'

// 最小密码长度
const THOST_FTDC_TPID_MinPwdLen = 'O'

//  IP当日最大登陆失败次数
const THOST_FTDC_TPID_LoginFailMaxNumForIP = 'U'

// 密码有效期
const THOST_FTDC_TPID_PasswordPeriod = 'V'

// 文件标识类型
type TThostFtdcFileIDType byte

// 资金数据
const THOST_FTDC_FI_SettlementFund = 'F'

// 成交数据
const THOST_FTDC_FI_Trade = 'T'

// 投资者持仓数据
const THOST_FTDC_FI_InvestorPosition = 'P'

// 投资者分项资金数据
const THOST_FTDC_FI_SubEntryFund = 'O'

// 组合持仓数据
const THOST_FTDC_FI_CZCECombinationPos = 'C'

// 上报保证金监控中心数据
const THOST_FTDC_FI_CSRCData = 'R'

// 郑商所平仓了结数据
const THOST_FTDC_FI_CZCEClose = 'L'

// 郑商所非平仓了结数据
const THOST_FTDC_FI_CZCENoClose = 'N'

// 持仓明细数据
const THOST_FTDC_FI_PositionDtl = 'D'

// 期权执行文件
const THOST_FTDC_FI_OptionStrike = 'S'

// 结算价比对文件
const THOST_FTDC_FI_SettlementPriceComparison = 'M'

// 上期所非持仓变动明细
const THOST_FTDC_FI_NonTradePosChange = 'B'

// 文件上传类型类型
type TThostFtdcFileTypeType byte

// 结算
const THOST_FTDC_FUT_Settlement = '0'

// 核对
const THOST_FTDC_FUT_Check = '1'

// 文件格式类型
type TThostFtdcFileFormatType byte

// 文本文件(.txt)
const THOST_FTDC_FFT_Txt = '0'

// 压缩文件(.zip)
const THOST_FTDC_FFT_Zip = '1'

//  DBF文件(.dbf)
const THOST_FTDC_FFT_DBF = '2'

// 文件状态类型
type TThostFtdcFileUploadStatusType byte

// 上传成功
const THOST_FTDC_FUS_SucceedUpload = '1'

// 上传失败
const THOST_FTDC_FUS_FailedUpload = '2'

// 导入成功
const THOST_FTDC_FUS_SucceedLoad = '3'

// 导入部分成功
const THOST_FTDC_FUS_PartSucceedLoad = '4'

// 导入失败
const THOST_FTDC_FUS_FailedLoad = '5'

// 移仓方向类型
type TThostFtdcTransferDirectionType byte

// 移出
const THOST_FTDC_TD_Out = '0'

// 移入
const THOST_FTDC_TD_In = '1'

// 特殊的创建规则类型
type TThostFtdcSpecialCreateRuleType byte

// 没有特殊创建规则
const THOST_FTDC_SC_NoSpecialRule = '0'

// 不包含春节
const THOST_FTDC_SC_NoSpringFestival = '1'

// 挂牌基准价类型类型
type TThostFtdcBasisPriceTypeType byte

// 上一合约结算价
const THOST_FTDC_IPT_LastSettlement = '1'

// 上一合约收盘价
const THOST_FTDC_IPT_LaseClose = '2'

// 产品生命周期状态类型
type TThostFtdcProductLifePhaseType byte

// 活跃
const THOST_FTDC_PLP_Active = '1'

// 不活跃
const THOST_FTDC_PLP_NonActive = '2'

// 注销
const THOST_FTDC_PLP_Canceled = '3'

// 交割方式类型
type TThostFtdcDeliveryModeType byte

// 现金交割
const THOST_FTDC_DM_CashDeliv = '1'

// 实物交割
const THOST_FTDC_DM_CommodityDeliv = '2'

// 出入金类型类型
type TThostFtdcFundIOTypeType byte

// 出入金
const THOST_FTDC_FIOT_FundIO = '1'

// 银期转帐
const THOST_FTDC_FIOT_Transfer = '2'

// 银期换汇
const THOST_FTDC_FIOT_SwapCurrency = '3'

// 资金类型类型
type TThostFtdcFundTypeType byte

// 银行存款
const THOST_FTDC_FT_Deposite = '1'

// 分项资金
const THOST_FTDC_FT_ItemFund = '2'

// 公司调整
const THOST_FTDC_FT_Company = '3'

// 资金内转
const THOST_FTDC_FT_InnerTransfer = '4'

// 出入金方向类型
type TThostFtdcFundDirectionType byte

// 入金
const THOST_FTDC_FD_In = '1'

// 出金
const THOST_FTDC_FD_Out = '2'

// 资金状态类型
type TThostFtdcFundStatusType byte

// 已录入
const THOST_FTDC_FS_Record = '1'

// 已复核
const THOST_FTDC_FS_Check = '2'

// 已冲销
const THOST_FTDC_FS_Charge = '3'

// 发布状态类型
type TThostFtdcPublishStatusType byte

// 未发布
const THOST_FTDC_PS_None = '1'

// 正在发布
const THOST_FTDC_PS_Publishing = '2'

// 已发布
const THOST_FTDC_PS_Published = '3'

// 系统状态类型
type TThostFtdcSystemStatusType byte

// 不活跃
const THOST_FTDC_ES_NonActive = '1'

// 启动
const THOST_FTDC_ES_Startup = '2'

// 交易开始初始化
const THOST_FTDC_ES_Initialize = '3'

// 交易完成初始化
const THOST_FTDC_ES_Initialized = '4'

// 收市开始
const THOST_FTDC_ES_Close = '5'

// 收市完成
const THOST_FTDC_ES_Closed = '6'

// 结算
const THOST_FTDC_ES_Settlement = '7'

// 结算状态类型
type TThostFtdcSettlementStatusType byte

// 初始
const THOST_FTDC_STS_Initialize = '0'

// 结算中
const THOST_FTDC_STS_Settlementing = '1'

// 已结算
const THOST_FTDC_STS_Settlemented = '2'

// 结算完成
const THOST_FTDC_STS_Finished = '3'

// 投资者类型类型
type TThostFtdcInvestorTypeType byte

// 自然人
const THOST_FTDC_CT_Person = '0'

// 法人
const THOST_FTDC_CT_Company = '1'

// 投资基金
const THOST_FTDC_CT_Fund = '2'

// 特殊法人
const THOST_FTDC_CT_SpecialOrgan = '3'

// 资管户
const THOST_FTDC_CT_Asset = '4'

// 经纪公司类型类型
type TThostFtdcBrokerTypeType byte

// 交易会员
const THOST_FTDC_BT_Trade = '0'

// 交易结算会员
const THOST_FTDC_BT_TradeSettle = '1'

// 风险等级类型
type TThostFtdcRiskLevelType byte

// 低风险客户
const THOST_FTDC_FAS_Low = '1'

// 普通客户
const THOST_FTDC_FAS_Normal = '2'

// 关注客户
const THOST_FTDC_FAS_Focus = '3'

// 风险客户
const THOST_FTDC_FAS_Risk = '4'

// 手续费收取方式类型
type TThostFtdcFeeAcceptStyleType byte

// 按交易收取
const THOST_FTDC_FAS_ByTrade = '1'

// 按交割收取
const THOST_FTDC_FAS_ByDeliv = '2'

// 不收
const THOST_FTDC_FAS_None = '3'

// 按指定手续费收取
const THOST_FTDC_FAS_FixFee = '4'

// 密码类型类型
type TThostFtdcPasswordTypeType byte

// 交易密码
const THOST_FTDC_PWDT_Trade = '1'

// 资金密码
const THOST_FTDC_PWDT_Account = '2'

// 盈亏算法类型
type TThostFtdcAlgorithmType byte

// 浮盈浮亏都计算
const THOST_FTDC_AG_All = '1'

// 浮盈不计，浮亏计
const THOST_FTDC_AG_OnlyLost = '2'

// 浮盈计，浮亏不计
const THOST_FTDC_AG_OnlyGain = '3'

// 浮盈浮亏都不计算
const THOST_FTDC_AG_None = '4'

// 是否包含平仓盈利类型
type TThostFtdcIncludeCloseProfitType byte

// 包含平仓盈利
const THOST_FTDC_ICP_Include = '0'

// 不包含平仓盈利
const THOST_FTDC_ICP_NotInclude = '2'

// 是否受可提比例限制类型
type TThostFtdcAllWithoutTradeType byte

// 无仓无成交不受可提比例限制
const THOST_FTDC_AWT_Enable = '0'

// 受可提比例限制
const THOST_FTDC_AWT_Disable = '2'

// 无仓不受可提比例限制
const THOST_FTDC_AWT_NoHoldEnable = '3'

// 资金密码核对标志类型
type TThostFtdcFuturePwdFlagType byte

// 不核对
const THOST_FTDC_FPWD_UnCheck = '0'

// 核对
const THOST_FTDC_FPWD_Check = '1'

// 银期转账类型类型
type TThostFtdcTransferTypeType byte

// 银行转期货
const THOST_FTDC_TT_BankToFuture = '0'

// 期货转银行
const THOST_FTDC_TT_FutureToBank = '1'

// 转账有效标志类型
type TThostFtdcTransferValidFlagType byte

// 无效或失败
const THOST_FTDC_TVF_Invalid = '0'

// 有效
const THOST_FTDC_TVF_Valid = '1'

// 冲正
const THOST_FTDC_TVF_Reverse = '2'

// 事由类型
type TThostFtdcReasonType byte

// 错单
const THOST_FTDC_RN_CD = '0'

// 资金在途
const THOST_FTDC_RN_ZT = '1'

// 其它
const THOST_FTDC_RN_QT = '2'

// 性别类型
type TThostFtdcSexType byte

// 未知
const THOST_FTDC_SEX_None = '0'

// 男
const THOST_FTDC_SEX_Man = '1'

// 女
const THOST_FTDC_SEX_Woman = '2'

// 用户类型类型
type TThostFtdcUserTypeType byte

// 投资者
const THOST_FTDC_UT_Investor = '0'

// 操作员
const THOST_FTDC_UT_Operator = '1'

// 管理员
const THOST_FTDC_UT_SuperUser = '2'

// 费率类型类型
type TThostFtdcRateTypeType byte

// 保证金率
const THOST_FTDC_RATETYPE_MarginRate = '2'

// 通知类型类型
type TThostFtdcNoteTypeType byte

// 交易结算单
const THOST_FTDC_NOTETYPE_TradeSettleBill = '1'

// 交易结算月报
const THOST_FTDC_NOTETYPE_TradeSettleMonth = '2'

// 追加保证金通知书
const THOST_FTDC_NOTETYPE_CallMarginNotes = '3'

// 强行平仓通知书
const THOST_FTDC_NOTETYPE_ForceCloseNotes = '4'

// 成交通知书
const THOST_FTDC_NOTETYPE_TradeNotes = '5'

// 交割通知书
const THOST_FTDC_NOTETYPE_DelivNotes = '6'

// 结算单方式类型
type TThostFtdcSettlementStyleType byte

// 逐日盯市
const THOST_FTDC_SBS_Day = '1'

// 逐笔对冲
const THOST_FTDC_SBS_Volume = '2'

// 结算单类型类型
type TThostFtdcSettlementBillTypeType byte

// 日报
const THOST_FTDC_ST_Day = '0'

// 月报
const THOST_FTDC_ST_Month = '1'

// 客户权限类型类型
type TThostFtdcUserRightTypeType byte

// 登录
const THOST_FTDC_URT_Logon = '1'

// 银期转帐
const THOST_FTDC_URT_Transfer = '2'

// 邮寄结算单
const THOST_FTDC_URT_EMail = '3'

// 传真结算单
const THOST_FTDC_URT_Fax = '4'

// 条件单
const THOST_FTDC_URT_ConditionOrder = '5'

// 保证金价格类型类型
type TThostFtdcMarginPriceTypeType byte

// 昨结算价
const THOST_FTDC_MPT_PreSettlementPrice = '1'

// 最新价
const THOST_FTDC_MPT_SettlementPrice = '2'

// 成交均价
const THOST_FTDC_MPT_AveragePrice = '3'

// 开仓价
const THOST_FTDC_MPT_OpenPrice = '4'

// 结算单生成状态类型
type TThostFtdcBillGenStatusType byte

// 未生成
const THOST_FTDC_BGS_None = '0'

// 生成中
const THOST_FTDC_BGS_NoGenerated = '1'

// 已生成
const THOST_FTDC_BGS_Generated = '2'

// 算法类型类型
type TThostFtdcAlgoTypeType byte

// 持仓处理算法
const THOST_FTDC_AT_HandlePositionAlgo = '1'

// 寻找保证金率算法
const THOST_FTDC_AT_FindMarginRateAlgo = '2'

// 持仓处理算法编号类型
type TThostFtdcHandlePositionAlgoIDType byte

// 基本
const THOST_FTDC_HPA_Base = '1'

// 大连商品交易所
const THOST_FTDC_HPA_DCE = '2'

// 郑州商品交易所
const THOST_FTDC_HPA_CZCE = '3'

// 寻找保证金率算法编号类型
type TThostFtdcFindMarginRateAlgoIDType byte

// 基本
const THOST_FTDC_FMRA_Base = '1'

// 大连商品交易所
const THOST_FTDC_FMRA_DCE = '2'

// 郑州商品交易所
const THOST_FTDC_FMRA_CZCE = '3'

// 资金处理算法编号类型
type TThostFtdcHandleTradingAccountAlgoIDType byte

// 基本
const THOST_FTDC_HTAA_Base = '1'

// 大连商品交易所
const THOST_FTDC_HTAA_DCE = '2'

// 郑州商品交易所
const THOST_FTDC_HTAA_CZCE = '3'

// 联系人类型类型
type TThostFtdcPersonTypeType byte

// 指定下单人
const THOST_FTDC_PST_Order = '1'

// 开户授权人
const THOST_FTDC_PST_Open = '2'

// 资金调拨人
const THOST_FTDC_PST_Fund = '3'

// 结算单确认人
const THOST_FTDC_PST_Settlement = '4'

// 法人
const THOST_FTDC_PST_Company = '5'

// 法人代表
const THOST_FTDC_PST_Corporation = '6'

// 投资者联系人
const THOST_FTDC_PST_LinkMan = '7'

// 分户管理资产负责人
const THOST_FTDC_PST_Ledger = '8'

// 托（保）管人
const THOST_FTDC_PST_Trustee = '9'

// 托（保）管机构法人代表
const THOST_FTDC_PST_TrusteeCorporation = 'A'

// 托（保）管机构开户授权人
const THOST_FTDC_PST_TrusteeOpen = 'B'

// 托（保）管机构联系人
const THOST_FTDC_PST_TrusteeContact = 'C'

// 境外自然人参考证件
const THOST_FTDC_PST_ForeignerRefer = 'D'

// 法人代表参考证件
const THOST_FTDC_PST_CorporationRefer = 'E'

// 查询范围类型
type TThostFtdcQueryInvestorRangeType byte

// 所有
const THOST_FTDC_QIR_All = '1'

// 查询分类
const THOST_FTDC_QIR_Group = '2'

// 单一投资者
const THOST_FTDC_QIR_Single = '3'

// 投资者风险状态类型
type TThostFtdcInvestorRiskStatusType byte

// 正常
const THOST_FTDC_IRS_Normal = '1'

// 警告
const THOST_FTDC_IRS_Warn = '2'

// 追保
const THOST_FTDC_IRS_Call = '3'

// 强平
const THOST_FTDC_IRS_Force = '4'

// 异常
const THOST_FTDC_IRS_Exception = '5'

// 用户事件类型类型
type TThostFtdcUserEventTypeType byte

// 登录
const THOST_FTDC_UET_Login = '1'

// 登出
const THOST_FTDC_UET_Logout = '2'

// 交易成功
const THOST_FTDC_UET_Trading = '3'

// 交易失败
const THOST_FTDC_UET_TradingError = '4'

// 修改密码
const THOST_FTDC_UET_UpdatePassword = '5'

// 客户端认证
const THOST_FTDC_UET_Authenticate = '6'

// 终端信息上报
const THOST_FTDC_UET_SubmitSysInfo = '7'

// 转账
const THOST_FTDC_UET_Transfer = '8'

// 其他
const THOST_FTDC_UET_Other = '9'

// 平仓方式类型
type TThostFtdcCloseStyleType byte

// 先开先平
const THOST_FTDC_ICS_Close = '0'

// 先平今再平昨
const THOST_FTDC_ICS_CloseToday = '1'

// 统计方式类型
type TThostFtdcStatModeType byte

// ----
const THOST_FTDC_SM_Non = '0'

// 按合约统计
const THOST_FTDC_SM_Instrument = '1'

// 按产品统计
const THOST_FTDC_SM_Product = '2'

// 按投资者统计
const THOST_FTDC_SM_Investor = '3'

// 预埋单状态类型
type TThostFtdcParkedOrderStatusType byte

// 未发送
const THOST_FTDC_PAOS_NotSend = '1'

// 已发送
const THOST_FTDC_PAOS_Send = '2'

// 已删除
const THOST_FTDC_PAOS_Deleted = '3'

// 处理状态类型
type TThostFtdcVirDealStatusType byte

// 正在处理
const THOST_FTDC_VDS_Dealing = '1'

// 处理成功
const THOST_FTDC_VDS_DeaclSucceed = '2'

// 原有系统代码类型
type TThostFtdcOrgSystemIDType byte

// 综合交易平台
const THOST_FTDC_ORGS_Standard = '0'

// 易盛系统
const THOST_FTDC_ORGS_ESunny = '1'

// 金仕达V6系统
const THOST_FTDC_ORGS_KingStarV6 = '2'

// 交易状态类型
type TThostFtdcVirTradeStatusType byte

// 正常处理中
const THOST_FTDC_VTS_NaturalDeal = '0'

// 成功结束
const THOST_FTDC_VTS_SucceedEnd = '1'

// 失败结束
const THOST_FTDC_VTS_FailedEND = '2'

// 异常中
const THOST_FTDC_VTS_Exception = '3'

// 已人工异常处理
const THOST_FTDC_VTS_ManualDeal = '4'

// 通讯异常 ，请人工处理
const THOST_FTDC_VTS_MesException = '5'

// 系统出错，请人工处理
const THOST_FTDC_VTS_SysException = '6'

// 银行帐户类型类型
type TThostFtdcVirBankAccTypeType byte

// 存折
const THOST_FTDC_VBAT_BankBook = '1'

// 储蓄卡
const THOST_FTDC_VBAT_BankCard = '2'

// 信用卡
const THOST_FTDC_VBAT_CreditCard = '3'

// 银行帐户类型类型
type TThostFtdcVirementStatusType byte

// 正常
const THOST_FTDC_VMS_Natural = '0'

// 销户
const THOST_FTDC_VMS_Canceled = '9'

// 有效标志类型
type TThostFtdcVirementAvailAbilityType byte

// 未确认
const THOST_FTDC_VAA_NoAvailAbility = '0'

// 有效
const THOST_FTDC_VAA_AvailAbility = '1'

// 冲正
const THOST_FTDC_VAA_Repeal = '2'

// 交易代码类型
type TThostFtdcVirementTradeCodeType byte

///银行发起银行资金转期货
const THOST_FTDC_VTC_BankBankToFuture = "102001"

///银行发起期货资金转银行
const THOST_FTDC_VTC_BankFutureToBank = "102002"

///期货发起银行资金转期货
const THOST_FTDC_VTC_FutureBankToFuture = "202001"

///期货发起期货资金转银行
const THOST_FTDC_VTC_FutureFutureToBank = "202002"

// Aml生成方式类型
type TThostFtdcAMLGenStatusType byte

// 程序生成
const THOST_FTDC_GEN_Program = '0'

// 人工生成
const THOST_FTDC_GEN_HandWork = '1'

// 动态密钥类别(保证金监管)类型
type TThostFtdcCFMMCKeyKindType byte

// 主动请求更新
const THOST_FTDC_CFMMCKK_REQUEST = 'R'

//  CFMMC自动更新
const THOST_FTDC_CFMMCKK_AUTO = 'A'

//  CFMMC手动更新
const THOST_FTDC_CFMMCKK_MANUAL = 'M'

// 证件类型类型
type TThostFtdcCertificationTypeType byte

// 身份证
const THOST_FTDC_CFT_IDCard = '0'

// 护照
const THOST_FTDC_CFT_Passport = '1'

// 军官证
const THOST_FTDC_CFT_OfficerIDCard = '2'

// 士兵证
const THOST_FTDC_CFT_SoldierIDCard = '3'

// 回乡证
const THOST_FTDC_CFT_HomeComingCard = '4'

// 户口簿
const THOST_FTDC_CFT_HouseholdRegister = '5'

// 营业执照号
const THOST_FTDC_CFT_LicenseNo = '6'

// 组织机构代码证
const THOST_FTDC_CFT_InstitutionCodeCard = '7'

// 临时营业执照号
const THOST_FTDC_CFT_TempLicenseNo = '8'

// 民办非企业登记证书
const THOST_FTDC_CFT_NoEnterpriseLicenseNo = '9'

// 其他证件
const THOST_FTDC_CFT_OtherCard = 'x'

// 主管部门批文
const THOST_FTDC_CFT_SuperDepAgree = 'a'

// 文件业务功能类型
type TThostFtdcFileBusinessCodeType byte

// 其他
const THOST_FTDC_FBC_Others = '0'

// 转账交易明细对账
const THOST_FTDC_FBC_TransferDetails = '1'

// 客户账户状态对账
const THOST_FTDC_FBC_CustAccStatus = '2'

// 账户类交易明细对账
const THOST_FTDC_FBC_AccountTradeDetails = '3'

// 期货账户信息变更明细对账
const THOST_FTDC_FBC_FutureAccountChangeInfoDetails = '4'

// 客户资金台账余额明细对账
const THOST_FTDC_FBC_CustMoneyDetail = '5'

// 客户销户结息明细对账
const THOST_FTDC_FBC_CustCancelAccountInfo = '6'

// 客户资金余额对账结果
const THOST_FTDC_FBC_CustMoneyResult = '7'

// 其它对账异常结果文件
const THOST_FTDC_FBC_OthersExceptionResult = '8'

// 客户结息净额明细
const THOST_FTDC_FBC_CustInterestNetMoneyDetails = '9'

// 客户资金交收明细
const THOST_FTDC_FBC_CustMoneySendAndReceiveDetails = 'a'

// 法人存管银行资金交收汇总
const THOST_FTDC_FBC_CorporationMoneyTotal = 'b'

// 主体间资金交收汇总
const THOST_FTDC_FBC_MainbodyMoneyTotal = 'c'

// 总分平衡监管数据
const THOST_FTDC_FBC_MainPartMonitorData = 'd'

// 存管银行备付金余额
const THOST_FTDC_FBC_PreparationMoney = 'e'

// 协办存管银行资金监管数据
const THOST_FTDC_FBC_BankMoneyMonitorData = 'f'

// 汇钞标志类型
type TThostFtdcCashExchangeCodeType byte

// 汇
const THOST_FTDC_CEC_Exchange = '1'

// 钞
const THOST_FTDC_CEC_Cash = '2'

// 是或否标识类型
type TThostFtdcYesNoIndicatorType byte

// 是
const THOST_FTDC_YNI_Yes = '0'

// 否
const THOST_FTDC_YNI_No = '1'

// 余额类型类型
type TThostFtdcBanlanceTypeType byte

// 当前余额
const THOST_FTDC_BLT_CurrentMoney = '0'

// 可用余额
const THOST_FTDC_BLT_UsableMoney = '1'

// 可取余额
const THOST_FTDC_BLT_FetchableMoney = '2'

// 冻结余额
const THOST_FTDC_BLT_FreezeMoney = '3'

// 性别类型
type TThostFtdcGenderType byte

// 未知状态
const THOST_FTDC_GD_Unknown = '0'

// 男
const THOST_FTDC_GD_Male = '1'

// 女
const THOST_FTDC_GD_Female = '2'

// 费用支付标志类型
type TThostFtdcFeePayFlagType byte

// 由受益方支付费用
const THOST_FTDC_FPF_BEN = '0'

// 由发送方支付费用
const THOST_FTDC_FPF_OUR = '1'

// 由发送方支付发起的费用，受益方支付接受的费用
const THOST_FTDC_FPF_SHA = '2'

// 密钥类型类型
type TThostFtdcPassWordKeyTypeType byte

// 交换密钥
const THOST_FTDC_PWKT_ExchangeKey = '0'

// 密码密钥
const THOST_FTDC_PWKT_PassWordKey = '1'

//  MAC密钥
const THOST_FTDC_PWKT_MACKey = '2'

// 报文密钥
const THOST_FTDC_PWKT_MessageKey = '3'

// 密码类型类型
type TThostFtdcFBTPassWordTypeType byte

// 查询
const THOST_FTDC_PWT_Query = '0'

// 取款
const THOST_FTDC_PWT_Fetch = '1'

// 转帐
const THOST_FTDC_PWT_Transfer = '2'

// 交易
const THOST_FTDC_PWT_Trade = '3'

// 加密方式类型
type TThostFtdcFBTEncryModeType byte

// 不加密
const THOST_FTDC_EM_NoEncry = '0'

//  DES
const THOST_FTDC_EM_DES = '1'

//  3DES
const THOST_FTDC_EM_3DES = '2'

// 银行冲正标志类型
type TThostFtdcBankRepealFlagType byte

// 银行无需自动冲正
const THOST_FTDC_BRF_BankNotNeedRepeal = '0'

// 银行待自动冲正
const THOST_FTDC_BRF_BankWaitingRepeal = '1'

// 银行已自动冲正
const THOST_FTDC_BRF_BankBeenRepealed = '2'

// 期商冲正标志类型
type TThostFtdcBrokerRepealFlagType byte

// 期商无需自动冲正
const THOST_FTDC_BRORF_BrokerNotNeedRepeal = '0'

// 期商待自动冲正
const THOST_FTDC_BRORF_BrokerWaitingRepeal = '1'

// 期商已自动冲正
const THOST_FTDC_BRORF_BrokerBeenRepealed = '2'

// 机构类别类型
type TThostFtdcInstitutionTypeType byte

// 银行
const THOST_FTDC_TS_Bank = '0'

// 期商
const THOST_FTDC_TS_Future = '1'

// 券商
const THOST_FTDC_TS_Store = '2'

// 最后分片标志类型
type TThostFtdcLastFragmentType byte

// 是最后分片
const THOST_FTDC_LF_Yes = '0'

// 不是最后分片
const THOST_FTDC_LF_No = '1'

// 银行账户状态类型
type TThostFtdcBankAccStatusType byte

// 正常
const THOST_FTDC_BAS_Normal = '0'

// 冻结
const THOST_FTDC_BAS_Freeze = '1'

// 挂失
const THOST_FTDC_BAS_ReportLoss = '2'

// 资金账户状态类型
type TThostFtdcMoneyAccountStatusType byte

// 正常
const THOST_FTDC_MAS_Normal = '0'

// 销户
const THOST_FTDC_MAS_Cancel = '1'

// 存管状态类型
type TThostFtdcManageStatusType byte

// 指定存管
const THOST_FTDC_MSS_Point = '0'

// 预指定
const THOST_FTDC_MSS_PrePoint = '1'

// 撤销指定
const THOST_FTDC_MSS_CancelPoint = '2'

// 应用系统类型类型
type TThostFtdcSystemTypeType byte

// 银期转帐
const THOST_FTDC_SYT_FutureBankTransfer = '0'

// 银证转帐
const THOST_FTDC_SYT_StockBankTransfer = '1'

// 第三方存管
const THOST_FTDC_SYT_TheThirdPartStore = '2'

// 银期转帐划转结果标志类型
type TThostFtdcTxnEndFlagType byte

// 正常处理中
const THOST_FTDC_TEF_NormalProcessing = '0'

// 成功结束
const THOST_FTDC_TEF_Success = '1'

// 失败结束
const THOST_FTDC_TEF_Failed = '2'

// 异常中
const THOST_FTDC_TEF_Abnormal = '3'

// 已人工异常处理
const THOST_FTDC_TEF_ManualProcessedForException = '4'

// 通讯异常 ，请人工处理
const THOST_FTDC_TEF_CommuFailedNeedManualProcess = '5'

// 系统出错，请人工处理
const THOST_FTDC_TEF_SysErrorNeedManualProcess = '6'

// 银期转帐服务处理状态类型
type TThostFtdcProcessStatusType byte

// 未处理
const THOST_FTDC_PSS_NotProcess = '0'

// 开始处理
const THOST_FTDC_PSS_StartProcess = '1'

// 处理完成
const THOST_FTDC_PSS_Finished = '2'

// 客户类型类型
type TThostFtdcCustTypeType byte

// 自然人
const THOST_FTDC_CUSTT_Person = '0'

// 机构户
const THOST_FTDC_CUSTT_Institution = '1'

// 银期转帐方向类型
type TThostFtdcFBTTransferDirectionType byte

// 入金，银行转期货
const THOST_FTDC_FBTTD_FromBankToFuture = '1'

// 出金，期货转银行
const THOST_FTDC_FBTTD_FromFutureToBank = '2'

// 开销户类别类型
type TThostFtdcOpenOrDestroyType byte

// 开户
const THOST_FTDC_OOD_Open = '1'

// 销户
const THOST_FTDC_OOD_Destroy = '0'

// 有效标志类型
type TThostFtdcAvailabilityFlagType byte

// 未确认
const THOST_FTDC_AVAF_Invalid = '0'

// 有效
const THOST_FTDC_AVAF_Valid = '1'

// 冲正
const THOST_FTDC_AVAF_Repeal = '2'

// 机构类型类型
type TThostFtdcOrganTypeType byte

// 银行代理
const THOST_FTDC_OT_Bank = '1'

// 交易前置
const THOST_FTDC_OT_Future = '2'

// 银期转帐平台管理
const THOST_FTDC_OT_PlateForm = '9'

// 机构级别类型
type TThostFtdcOrganLevelType byte

// 银行总行或期商总部
const THOST_FTDC_OL_HeadQuarters = '1'

// 银行分中心或期货公司营业部
const THOST_FTDC_OL_Branch = '2'

// 协议类型类型
type TThostFtdcProtocalIDType byte

// 期商协议
const THOST_FTDC_PID_FutureProtocal = '0'

// 工行协议
const THOST_FTDC_PID_ICBCProtocal = '1'

// 农行协议
const THOST_FTDC_PID_ABCProtocal = '2'

// 中国银行协议
const THOST_FTDC_PID_CBCProtocal = '3'

// 建行协议
const THOST_FTDC_PID_CCBProtocal = '4'

// 交行协议
const THOST_FTDC_PID_BOCOMProtocal = '5'

// 银期转帐平台协议
const THOST_FTDC_PID_FBTPlateFormProtocal = 'X'

// 套接字连接方式类型
type TThostFtdcConnectModeType byte

// 短连接
const THOST_FTDC_CM_ShortConnect = '0'

// 长连接
const THOST_FTDC_CM_LongConnect = '1'

// 套接字通信方式类型
type TThostFtdcSyncModeType byte

// 异步
const THOST_FTDC_SRM_ASync = '0'

// 同步
const THOST_FTDC_SRM_Sync = '1'

// 银行帐号类型类型
type TThostFtdcBankAccTypeType byte

// 银行存折
const THOST_FTDC_BAT_BankBook = '1'

// 储蓄卡
const THOST_FTDC_BAT_SavingCard = '2'

// 信用卡
const THOST_FTDC_BAT_CreditCard = '3'

// 期货公司帐号类型类型
type TThostFtdcFutureAccTypeType byte

// 银行存折
const THOST_FTDC_FAT_BankBook = '1'

// 储蓄卡
const THOST_FTDC_FAT_SavingCard = '2'

// 信用卡
const THOST_FTDC_FAT_CreditCard = '3'

// 接入机构状态类型
type TThostFtdcOrganStatusType byte

// 启用
const THOST_FTDC_OS_Ready = '0'

// 签到
const THOST_FTDC_OS_CheckIn = '1'

// 签退
const THOST_FTDC_OS_CheckOut = '2'

// 对帐文件到达
const THOST_FTDC_OS_CheckFileArrived = '3'

// 对帐
const THOST_FTDC_OS_CheckDetail = '4'

// 日终清理
const THOST_FTDC_OS_DayEndClean = '5'

// 注销
const THOST_FTDC_OS_Invalid = '9'

// 建行收费模式类型
type TThostFtdcCCBFeeModeType byte

// 按金额扣收
const THOST_FTDC_CCBFM_ByAmount = '1'

// 按月扣收
const THOST_FTDC_CCBFM_ByMonth = '2'

// 通讯API类型类型
type TThostFtdcCommApiTypeType byte

// 客户端
const THOST_FTDC_CAPIT_Client = '1'

// 服务端
const THOST_FTDC_CAPIT_Server = '2'

// 交易系统的UserApi
const THOST_FTDC_CAPIT_UserApi = '3'

// 连接状态类型
type TThostFtdcLinkStatusType byte

// 已经连接
const THOST_FTDC_LS_Connected = '1'

// 没有连接
const THOST_FTDC_LS_Disconnected = '2'

// 密码核对标志类型
type TThostFtdcPwdFlagType byte

// 不核对
const THOST_FTDC_BPWDF_NoCheck = '0'

// 明文核对
const THOST_FTDC_BPWDF_BlankCheck = '1'

// 密文核对
const THOST_FTDC_BPWDF_EncryptCheck = '2'

// 期货帐号类型类型
type TThostFtdcSecuAccTypeType byte

// 资金帐号
const THOST_FTDC_SAT_AccountID = '1'

// 资金卡号
const THOST_FTDC_SAT_CardID = '2'

// 上海股东帐号
const THOST_FTDC_SAT_SHStockholderID = '3'

// 深圳股东帐号
const THOST_FTDC_SAT_SZStockholderID = '4'

// 转账交易状态类型
type TThostFtdcTransferStatusType byte

// 正常
const THOST_FTDC_TRFS_Normal = '0'

// 被冲正
const THOST_FTDC_TRFS_Repealed = '1'

// 发起方类型
type TThostFtdcSponsorTypeType byte

// 期商
const THOST_FTDC_SPTYPE_Broker = '0'

// 银行
const THOST_FTDC_SPTYPE_Bank = '1'

// 请求响应类别类型
type TThostFtdcReqRspTypeType byte

// 请求
const THOST_FTDC_REQRSP_Request = '0'

// 响应
const THOST_FTDC_REQRSP_Response = '1'

// 银期转帐用户事件类型类型
type TThostFtdcFBTUserEventTypeType byte

// 签到
const THOST_FTDC_FBTUET_SignIn = '0'

// 银行转期货
const THOST_FTDC_FBTUET_FromBankToFuture = '1'

// 期货转银行
const THOST_FTDC_FBTUET_FromFutureToBank = '2'

// 开户
const THOST_FTDC_FBTUET_OpenAccount = '3'

// 销户
const THOST_FTDC_FBTUET_CancelAccount = '4'

// 变更银行账户
const THOST_FTDC_FBTUET_ChangeAccount = '5'

// 冲正银行转期货
const THOST_FTDC_FBTUET_RepealFromBankToFuture = '6'

// 冲正期货转银行
const THOST_FTDC_FBTUET_RepealFromFutureToBank = '7'

// 查询银行账户
const THOST_FTDC_FBTUET_QueryBankAccount = '8'

// 查询期货账户
const THOST_FTDC_FBTUET_QueryFutureAccount = '9'

// 签退
const THOST_FTDC_FBTUET_SignOut = 'A'

// 密钥同步
const THOST_FTDC_FBTUET_SyncKey = 'B'

// 预约开户
const THOST_FTDC_FBTUET_ReserveOpenAccount = 'C'

// 撤销预约开户
const THOST_FTDC_FBTUET_CancelReserveOpenAccount = 'D'

// 预约开户确认
const THOST_FTDC_FBTUET_ReserveOpenAccountConfirm = 'E'

// 其他
const THOST_FTDC_FBTUET_Other = 'Z'

// 记录操作类型类型
type TThostFtdcDBOperationType byte

// 插入
const THOST_FTDC_DBOP_Insert = '0'

// 更新
const THOST_FTDC_DBOP_Update = '1'

// 删除
const THOST_FTDC_DBOP_Delete = '2'

// 同步标记类型
type TThostFtdcSyncFlagType byte

// 已同步
const THOST_FTDC_SYNF_Yes = '0'

// 未同步
const THOST_FTDC_SYNF_No = '1'

// 同步类型类型
type TThostFtdcSyncTypeType byte

// 一次同步
const THOST_FTDC_SYNT_OneOffSync = '0'

// 定时同步
const THOST_FTDC_SYNT_TimerSync = '1'

// 定时完全同步
const THOST_FTDC_SYNT_TimerFullSync = '2'

// 换汇方向类型
type TThostFtdcExDirectionType byte

// 结汇
const THOST_FTDC_FBEDIR_Settlement = '0'

// 售汇
const THOST_FTDC_FBEDIR_Sale = '1'

// 换汇成功标志类型
type TThostFtdcFBEResultFlagType byte

// 成功
const THOST_FTDC_FBERES_Success = '0'

// 账户余额不足
const THOST_FTDC_FBERES_InsufficientBalance = '1'

// 交易结果未知
const THOST_FTDC_FBERES_UnknownTrading = '8'

// 失败
const THOST_FTDC_FBERES_Fail = 'x'

// 换汇交易状态类型
type TThostFtdcFBEExchStatusType byte

// 正常
const THOST_FTDC_FBEES_Normal = '0'

// 交易重发
const THOST_FTDC_FBEES_ReExchange = '1'

// 换汇文件标志类型
type TThostFtdcFBEFileFlagType byte

// 数据包
const THOST_FTDC_FBEFG_DataPackage = '0'

// 文件
const THOST_FTDC_FBEFG_File = '1'

// 换汇已交易标志类型
type TThostFtdcFBEAlreadyTradeType byte

// 未交易
const THOST_FTDC_FBEAT_NotTrade = '0'

// 已交易
const THOST_FTDC_FBEAT_Trade = '1'

// 银期换汇用户事件类型类型
type TThostFtdcFBEUserEventTypeType byte

// 签到
const THOST_FTDC_FBEUET_SignIn = '0'

// 换汇
const THOST_FTDC_FBEUET_Exchange = '1'

// 换汇重发
const THOST_FTDC_FBEUET_ReExchange = '2'

// 银行账户查询
const THOST_FTDC_FBEUET_QueryBankAccount = '3'

// 换汇明细查询
const THOST_FTDC_FBEUET_QueryExchDetial = '4'

// 换汇汇总查询
const THOST_FTDC_FBEUET_QueryExchSummary = '5'

// 换汇汇率查询
const THOST_FTDC_FBEUET_QueryExchRate = '6'

// 对账文件通知
const THOST_FTDC_FBEUET_CheckBankAccount = '7'

// 签退
const THOST_FTDC_FBEUET_SignOut = '8'

// 其他
const THOST_FTDC_FBEUET_Other = 'Z'

// 换汇发送标志类型
type TThostFtdcFBEReqFlagType byte

// 未处理
const THOST_FTDC_FBERF_UnProcessed = '0'

// 等待发送
const THOST_FTDC_FBERF_WaitSend = '1'

// 发送成功
const THOST_FTDC_FBERF_SendSuccess = '2'

// 发送失败
const THOST_FTDC_FBERF_SendFailed = '3'

// 等待重发
const THOST_FTDC_FBERF_WaitReSend = '4'

// 风险通知类型类型
type TThostFtdcNotifyClassType byte

// 正常
const THOST_FTDC_NC_NOERROR = '0'

// 警示
const THOST_FTDC_NC_Warn = '1'

// 追保
const THOST_FTDC_NC_Call = '2'

// 强平
const THOST_FTDC_NC_Force = '3'

// 穿仓
const THOST_FTDC_NC_CHUANCANG = '4'

// 异常
const THOST_FTDC_NC_Exception = '5'

// 强平单类型类型
type TThostFtdcForceCloseTypeType byte

// 手工强平
const THOST_FTDC_FCT_Manual = '0'

// 单一投资者辅助强平
const THOST_FTDC_FCT_Single = '1'

// 批量投资者辅助强平
const THOST_FTDC_FCT_Group = '2'

// 风险通知途径类型
type TThostFtdcRiskNotifyMethodType byte

// 系统通知
const THOST_FTDC_RNM_System = '0'

// 短信通知
const THOST_FTDC_RNM_SMS = '1'

// 邮件通知
const THOST_FTDC_RNM_EMail = '2'

// 人工通知
const THOST_FTDC_RNM_Manual = '3'

// 风险通知状态类型
type TThostFtdcRiskNotifyStatusType byte

// 未生成
const THOST_FTDC_RNS_NotGen = '0'

// 已生成未发送
const THOST_FTDC_RNS_Generated = '1'

// 发送失败
const THOST_FTDC_RNS_SendError = '2'

// 已发送未接收
const THOST_FTDC_RNS_SendOk = '3'

// 已接收未确认
const THOST_FTDC_RNS_Received = '4'

// 已确认
const THOST_FTDC_RNS_Confirmed = '5'

// 风控用户操作事件类型
type TThostFtdcRiskUserEventType byte

// 导出数据
const THOST_FTDC_RUE_ExportData = '0'

// 条件单索引条件类型
type TThostFtdcConditionalOrderSortTypeType byte

// 使用最新价升序
const THOST_FTDC_COST_LastPriceAsc = '0'

// 使用最新价降序
const THOST_FTDC_COST_LastPriceDesc = '1'

// 使用卖价升序
const THOST_FTDC_COST_AskPriceAsc = '2'

// 使用卖价降序
const THOST_FTDC_COST_AskPriceDesc = '3'

// 使用买价升序
const THOST_FTDC_COST_BidPriceAsc = '4'

// 使用买价降序
const THOST_FTDC_COST_BidPriceDesc = '5'

// 报送状态类型
type TThostFtdcSendTypeType byte

// 未发送
const THOST_FTDC_UOAST_NoSend = '0'

// 已发送
const THOST_FTDC_UOAST_Sended = '1'

// 已生成
const THOST_FTDC_UOAST_Generated = '2'

// 报送失败
const THOST_FTDC_UOAST_SendFail = '3'

// 接收成功
const THOST_FTDC_UOAST_Success = '4'

// 接收失败
const THOST_FTDC_UOAST_Fail = '5'

// 取消报送
const THOST_FTDC_UOAST_Cancel = '6'

// 交易编码状态类型
type TThostFtdcClientIDStatusType byte

// 未申请
const THOST_FTDC_UOACS_NoApply = '1'

// 已提交申请
const THOST_FTDC_UOACS_Submited = '2'

// 已发送申请
const THOST_FTDC_UOACS_Sended = '3'

// 完成
const THOST_FTDC_UOACS_Success = '4'

// 拒绝
const THOST_FTDC_UOACS_Refuse = '5'

// 已撤销编码
const THOST_FTDC_UOACS_Cancel = '6'

// 特有信息类型类型
type TThostFtdcQuestionTypeType byte

// 单选
const THOST_FTDC_QT_Radio = '1'

// 多选
const THOST_FTDC_QT_Option = '2'

// 填空
const THOST_FTDC_QT_Blank = '3'

// 业务类型类型
type TThostFtdcBusinessTypeType byte

// 请求
const THOST_FTDC_BT_Request = '1'

// 应答
const THOST_FTDC_BT_Response = '2'

// 通知
const THOST_FTDC_BT_Notice = '3'

// 监控中心返回码类型
type TThostFtdcCfmmcReturnCodeType byte

// 成功
const THOST_FTDC_CRC_Success = '0'

// 该客户已经有流程在处理中
const THOST_FTDC_CRC_Working = '1'

// 监控中客户资料检查失败
const THOST_FTDC_CRC_InfoFail = '2'

// 监控中实名制检查失败
const THOST_FTDC_CRC_IDCardFail = '3'

// 其他错误
const THOST_FTDC_CRC_OtherFail = '4'

// 客户类型类型
type TThostFtdcClientTypeType byte

// 所有
const THOST_FTDC_CfMMCCT_All = '0'

// 个人
const THOST_FTDC_CfMMCCT_Person = '1'

// 单位
const THOST_FTDC_CfMMCCT_Company = '2'

// 其他
const THOST_FTDC_CfMMCCT_Other = '3'

// 特殊法人
const THOST_FTDC_CfMMCCT_SpecialOrgan = '4'

// 资管户
const THOST_FTDC_CfMMCCT_Asset = '5'

// 交易所编号类型
type TThostFtdcExchangeIDTypeType byte

// 上海期货交易所
const THOST_FTDC_EIDT_SHFE = 'S'

// 郑州商品交易所
const THOST_FTDC_EIDT_CZCE = 'Z'

// 大连商品交易所
const THOST_FTDC_EIDT_DCE = 'D'

// 中国金融期货交易所
const THOST_FTDC_EIDT_CFFEX = 'J'

// 上海国际能源交易中心股份有限公司
const THOST_FTDC_EIDT_INE = 'N'

// 交易编码类型类型
type TThostFtdcExClientIDTypeType byte

// 套保
const THOST_FTDC_ECIDT_Hedge = '1'

// 套利
const THOST_FTDC_ECIDT_Arbitrage = '2'

// 投机
const THOST_FTDC_ECIDT_Speculation = '3'

// 更新状态类型
type TThostFtdcUpdateFlagType byte

// 未更新
const THOST_FTDC_UF_NoUpdate = '0'

// 更新全部信息成功
const THOST_FTDC_UF_Success = '1'

// 更新全部信息失败
const THOST_FTDC_UF_Fail = '2'

// 更新交易编码成功
const THOST_FTDC_UF_TCSuccess = '3'

// 更新交易编码失败
const THOST_FTDC_UF_TCFail = '4'

// 已丢弃
const THOST_FTDC_UF_Cancel = '5'

// 申请动作类型
type TThostFtdcApplyOperateIDType byte

// 开户
const THOST_FTDC_AOID_OpenInvestor = '1'

// 修改身份信息
const THOST_FTDC_AOID_ModifyIDCard = '2'

// 修改一般信息
const THOST_FTDC_AOID_ModifyNoIDCard = '3'

// 申请交易编码
const THOST_FTDC_AOID_ApplyTradingCode = '4'

// 撤销交易编码
const THOST_FTDC_AOID_CancelTradingCode = '5'

// 销户
const THOST_FTDC_AOID_CancelInvestor = '6'

// 账户休眠
const THOST_FTDC_AOID_FreezeAccount = '8'

// 激活休眠账户
const THOST_FTDC_AOID_ActiveFreezeAccount = '9'

// 申请状态类型
type TThostFtdcApplyStatusIDType byte

// 未补全
const THOST_FTDC_ASID_NoComplete = '1'

// 已提交
const THOST_FTDC_ASID_Submited = '2'

// 已审核
const THOST_FTDC_ASID_Checked = '3'

// 已拒绝
const THOST_FTDC_ASID_Refused = '4'

// 已删除
const THOST_FTDC_ASID_Deleted = '5'

// 发送方式类型
type TThostFtdcSendMethodType byte

// 文件发送
const THOST_FTDC_UOASM_ByAPI = '1'

// 电子发送
const THOST_FTDC_UOASM_ByFile = '2'

// 操作方法类型
type TThostFtdcEventModeType byte

// 增加
const THOST_FTDC_EvM_ADD = '1'

// 修改
const THOST_FTDC_EvM_UPDATE = '2'

// 删除
const THOST_FTDC_EvM_DELETE = '3'

// 复核
const THOST_FTDC_EvM_CHECK = '4'

// 复制
const THOST_FTDC_EvM_COPY = '5'

// 注销
const THOST_FTDC_EvM_CANCEL = '6'

// 冲销
const THOST_FTDC_EvM_Reverse = '7'

// 统一开户申请自动发送类型
type TThostFtdcUOAAutoSendType byte

// 自动发送并接收
const THOST_FTDC_UOAA_ASR = '1'

// 自动发送，不自动接收
const THOST_FTDC_UOAA_ASNR = '2'

// 不自动发送，自动接收
const THOST_FTDC_UOAA_NSAR = '3'

// 不自动发送，也不自动接收
const THOST_FTDC_UOAA_NSR = '4'

// 流程ID类型
type TThostFtdcFlowIDType byte

// 投资者对应投资者组设置
const THOST_FTDC_EvM_InvestorGroupFlow = '1'

// 投资者手续费率设置
const THOST_FTDC_EvM_InvestorRate = '2'

// 投资者手续费率模板关系设置
const THOST_FTDC_EvM_InvestorCommRateModel = '3'

// 复核级别类型
type TThostFtdcCheckLevelType byte

// 零级复核
const THOST_FTDC_CL_Zero = '0'

// 一级复核
const THOST_FTDC_CL_One = '1'

// 二级复核
const THOST_FTDC_CL_Two = '2'

// 复核级别类型
type TThostFtdcCheckStatusType byte

// 未复核
const THOST_FTDC_CHS_Init = '0'

// 复核中
const THOST_FTDC_CHS_Checking = '1'

// 已复核
const THOST_FTDC_CHS_Checked = '2'

// 拒绝
const THOST_FTDC_CHS_Refuse = '3'

// 作废
const THOST_FTDC_CHS_Cancel = '4'

// 生效状态类型
type TThostFtdcUsedStatusType byte

// 未生效
const THOST_FTDC_CHU_Unused = '0'

// 已生效
const THOST_FTDC_CHU_Used = '1'

// 生效失败
const THOST_FTDC_CHU_Fail = '2'

// 账户来源类型
type TThostFtdcBankAcountOriginType byte

// 手工录入
const THOST_FTDC_BAO_ByAccProperty = '0'

// 银期转账
const THOST_FTDC_BAO_ByFBTransfer = '1'

// 结算单月报成交汇总方式类型
type TThostFtdcMonthBillTradeSumType byte

// 同日同合约
const THOST_FTDC_MBTS_ByInstrument = '0'

// 同日同合约同价格
const THOST_FTDC_MBTS_ByDayInsPrc = '1'

// 同合约
const THOST_FTDC_MBTS_ByDayIns = '2'

// 银期交易代码枚举类型
type TThostFtdcFBTTradeCodeEnumType byte

///银行发起银行转期货
const THOST_FTDC_FTC_BankLaunchBankToBroker = "102001"

///期货发起银行转期货
const THOST_FTDC_FTC_BrokerLaunchBankToBroker = "202001"

///银行发起期货转银行
const THOST_FTDC_FTC_BankLaunchBrokerToBank = "102002"

///期货发起期货转银行
const THOST_FTDC_FTC_BrokerLaunchBrokerToBank = "202002"

// 动态令牌类型类型
type TThostFtdcOTPTypeType byte

// 无动态令牌
const THOST_FTDC_OTP_NONE = '0'

// 时间令牌
const THOST_FTDC_OTP_TOTP = '1'

// 动态令牌状态类型
type TThostFtdcOTPStatusType byte

// 未使用
const THOST_FTDC_OTPS_Unused = '0'

// 已使用
const THOST_FTDC_OTPS_Used = '1'

// 注销
const THOST_FTDC_OTPS_Disuse = '2'

// 经济公司用户类型类型
type TThostFtdcBrokerUserTypeType byte

// 投资者
const THOST_FTDC_BUT_Investor = '1'

// 操作员
const THOST_FTDC_BUT_BrokerUser = '2'

// 期货类型类型
type TThostFtdcFutureTypeType byte

// 商品期货
const THOST_FTDC_FUTT_Commodity = '1'

// 金融期货
const THOST_FTDC_FUTT_Financial = '2'

// 资金管理操作类型类型
type TThostFtdcFundEventTypeType byte

// 转账限额
const THOST_FTDC_FET_Restriction = '0'

// 当日转账限额
const THOST_FTDC_FET_TodayRestriction = '1'

// 期商流水
const THOST_FTDC_FET_Transfer = '2'

// 资金冻结
const THOST_FTDC_FET_Credit = '3'

// 投资者可提资金比例
const THOST_FTDC_FET_InvestorWithdrawAlm = '4'

// 单个银行帐户转账限额
const THOST_FTDC_FET_BankRestriction = '5'

// 银期签约账户
const THOST_FTDC_FET_Accountregister = '6'

// 交易所出入金
const THOST_FTDC_FET_ExchangeFundIO = '7'

// 投资者出入金
const THOST_FTDC_FET_InvestorFundIO = '8'

// 资金账户来源类型
type TThostFtdcAccountSourceTypeType byte

// 银期同步
const THOST_FTDC_AST_FBTransfer = '0'

// 手工录入
const THOST_FTDC_AST_ManualEntry = '1'

// 交易编码来源类型
type TThostFtdcCodeSourceTypeType byte

// 统一开户(已规范)
const THOST_FTDC_CST_UnifyAccount = '0'

// 手工录入(未规范)
const THOST_FTDC_CST_ManualEntry = '1'

// 操作员范围类型
type TThostFtdcUserRangeType byte

// 所有
const THOST_FTDC_UR_All = '0'

// 单一操作员
const THOST_FTDC_UR_Single = '1'

// 交易统计表按客户统计方式类型
type TThostFtdcByGroupType byte

// 按投资者统计
const THOST_FTDC_BG_Investor = '2'

// 按类统计
const THOST_FTDC_BG_Group = '1'

// 交易统计表按范围统计方式类型
type TThostFtdcTradeSumStatModeType byte

// 按合约统计
const THOST_FTDC_TSSM_Instrument = '1'

// 按产品统计
const THOST_FTDC_TSSM_Product = '2'

// 按交易所统计
const THOST_FTDC_TSSM_Exchange = '3'

// 日期表达式设置类型类型
type TThostFtdcExprSetModeType byte

// 相对已有规则设置
const THOST_FTDC_ESM_Relative = '1'

// 典型设置
const THOST_FTDC_ESM_Typical = '2'

// 投资者范围类型
type TThostFtdcRateInvestorRangeType byte

// 公司标准
const THOST_FTDC_RIR_All = '1'

// 模板
const THOST_FTDC_RIR_Model = '2'

// 单一投资者
const THOST_FTDC_RIR_Single = '3'

// 主次用系统数据同步状态类型
type TThostFtdcSyncDataStatusType byte

// 未同步
const THOST_FTDC_SDS_Initialize = '0'

// 同步中
const THOST_FTDC_SDS_Settlementing = '1'

// 已同步
const THOST_FTDC_SDS_Settlemented = '2'

// 成交来源类型
type TThostFtdcTradeSourceType byte

// 来自交易所普通回报
const THOST_FTDC_TSRC_NORMAL = '0'

// 来自查询
const THOST_FTDC_TSRC_QUERY = '1'

// 产品合约统计方式类型
type TThostFtdcFlexStatModeType byte

// 产品统计
const THOST_FTDC_FSM_Product = '1'

// 交易所统计
const THOST_FTDC_FSM_Exchange = '2'

// 统计所有
const THOST_FTDC_FSM_All = '3'

// 投资者范围统计方式类型
type TThostFtdcByInvestorRangeType byte

// 属性统计
const THOST_FTDC_BIR_Property = '1'

// 统计所有
const THOST_FTDC_BIR_All = '2'

// 投资者范围类型
type TThostFtdcPropertyInvestorRangeType byte

// 所有
const THOST_FTDC_PIR_All = '1'

// 投资者属性
const THOST_FTDC_PIR_Property = '2'

// 单一投资者
const THOST_FTDC_PIR_Single = '3'

// 文件状态类型
type TThostFtdcFileStatusType byte

// 未生成
const THOST_FTDC_FIS_NoCreate = '0'

// 已生成
const THOST_FTDC_FIS_Created = '1'

// 生成失败
const THOST_FTDC_FIS_Failed = '2'

// 文件生成方式类型
type TThostFtdcFileGenStyleType byte

// 下发
const THOST_FTDC_FGS_FileTransmit = '0'

// 生成
const THOST_FTDC_FGS_FileGen = '1'

// 系统日志操作方法类型
type TThostFtdcSysOperModeType byte

// 增加
const THOST_FTDC_SoM_Add = '1'

// 修改
const THOST_FTDC_SoM_Update = '2'

// 删除
const THOST_FTDC_SoM_Delete = '3'

// 复制
const THOST_FTDC_SoM_Copy = '4'

// 激活
const THOST_FTDC_SoM_AcTive = '5'

// 注销
const THOST_FTDC_SoM_CanCel = '6'

// 重置
const THOST_FTDC_SoM_ReSet = '7'

// 系统日志操作类型类型
type TThostFtdcSysOperTypeType byte

// 修改操作员密码
const THOST_FTDC_SoT_UpdatePassword = '0'

// 操作员组织架构关系
const THOST_FTDC_SoT_UserDepartment = '1'

// 角色管理
const THOST_FTDC_SoT_RoleManager = '2'

// 角色功能设置
const THOST_FTDC_SoT_RoleFunction = '3'

// 基础参数设置
const THOST_FTDC_SoT_BaseParam = '4'

// 设置操作员
const THOST_FTDC_SoT_SetUserID = '5'

// 用户角色设置
const THOST_FTDC_SoT_SetUserRole = '6'

// 用户IP限制
const THOST_FTDC_SoT_UserIpRestriction = '7'

// 组织架构管理
const THOST_FTDC_SoT_DepartmentManager = '8'

// 组织架构向查询分类复制
const THOST_FTDC_SoT_DepartmentCopy = '9'

// 交易编码管理
const THOST_FTDC_SoT_Tradingcode = 'A'

// 投资者状态维护
const THOST_FTDC_SoT_InvestorStatus = 'B'

// 投资者权限管理
const THOST_FTDC_SoT_InvestorAuthority = 'C'

// 属性设置
const THOST_FTDC_SoT_PropertySet = 'D'

// 重置投资者密码
const THOST_FTDC_SoT_ReSetInvestorPasswd = 'E'

// 投资者个性信息维护
const THOST_FTDC_SoT_InvestorPersonalityInfo = 'F'

// 上报数据查询类型类型
type TThostFtdcCSRCDataQueyTypeType byte

// 查询当前交易日报送的数据
const THOST_FTDC_CSRCQ_Current = '0'

// 查询历史报送的代理经纪公司的数据
const THOST_FTDC_CSRCQ_History = '1'

// 休眠状态类型
type TThostFtdcFreezeStatusType byte

// 活跃
const THOST_FTDC_FRS_Normal = '1'

// 休眠
const THOST_FTDC_FRS_Freeze = '0'

// 规范状态类型
type TThostFtdcStandardStatusType byte

// 已规范
const THOST_FTDC_STST_Standard = '0'

// 未规范
const THOST_FTDC_STST_NonStandard = '1'

// 配置类型类型
type TThostFtdcRightParamTypeType byte

// 休眠户
const THOST_FTDC_RPT_Freeze = '1'

// 激活休眠户
const THOST_FTDC_RPT_FreezeActive = '2'

// 开仓权限限制
const THOST_FTDC_RPT_OpenLimit = '3'

// 解除开仓权限限制
const THOST_FTDC_RPT_RelieveOpenLimit = '4'

// 反洗钱审核表数据状态类型
type TThostFtdcDataStatusType byte

// 正常
const THOST_FTDC_AMLDS_Normal = '0'

// 已删除
const THOST_FTDC_AMLDS_Deleted = '1'

// 审核状态类型
type TThostFtdcAMLCheckStatusType byte

// 未复核
const THOST_FTDC_AMLCHS_Init = '0'

// 复核中
const THOST_FTDC_AMLCHS_Checking = '1'

// 已复核
const THOST_FTDC_AMLCHS_Checked = '2'

// 拒绝上报
const THOST_FTDC_AMLCHS_RefuseReport = '3'

// 日期类型类型
type TThostFtdcAmlDateTypeType byte

// 检查日期
const THOST_FTDC_AMLDT_DrawDay = '0'

// 发生日期
const THOST_FTDC_AMLDT_TouchDay = '1'

// 审核级别类型
type TThostFtdcAmlCheckLevelType byte

// 零级审核
const THOST_FTDC_AMLCL_CheckLevel0 = '0'

// 一级审核
const THOST_FTDC_AMLCL_CheckLevel1 = '1'

// 二级审核
const THOST_FTDC_AMLCL_CheckLevel2 = '2'

// 三级审核
const THOST_FTDC_AMLCL_CheckLevel3 = '3'

// 导出文件类型类型
type TThostFtdcExportFileTypeType byte

//  CSV
const THOST_FTDC_EFT_CSV = '0'

//  Excel
const THOST_FTDC_EFT_EXCEL = '1'

//  DBF
const THOST_FTDC_EFT_DBF = '2'

// 结算配置类型类型
type TThostFtdcSettleManagerTypeType byte

// 结算前准备
const THOST_FTDC_SMT_Before = '1'

// 结算
const THOST_FTDC_SMT_Settlement = '2'

// 结算后核对
const THOST_FTDC_SMT_After = '3'

// 结算后处理
const THOST_FTDC_SMT_Settlemented = '4'

// 结算配置等级类型
type TThostFtdcSettleManagerLevelType byte

// 必要
const THOST_FTDC_SML_Must = '1'

// 警告
const THOST_FTDC_SML_Alarm = '2'

// 提示
const THOST_FTDC_SML_Prompt = '3'

// 不检查
const THOST_FTDC_SML_Ignore = '4'

// 模块分组类型
type TThostFtdcSettleManagerGroupType byte

// 交易所核对
const THOST_FTDC_SMG_Exhcange = '1'

// 内部核对
const THOST_FTDC_SMG_ASP = '2'

// 上报数据核对
const THOST_FTDC_SMG_CSRC = '3'

// 保值额度使用类型类型
type TThostFtdcLimitUseTypeType byte

// 可重复使用
const THOST_FTDC_LUT_Repeatable = '1'

// 不可重复使用
const THOST_FTDC_LUT_Unrepeatable = '2'

// 数据来源类型
type TThostFtdcDataResourceType byte

// 本系统
const THOST_FTDC_DAR_Settle = '1'

// 交易所
const THOST_FTDC_DAR_Exchange = '2'

// 报送数据
const THOST_FTDC_DAR_CSRC = '3'

// 保证金类型类型
type TThostFtdcMarginTypeType byte

// 交易所保证金率
const THOST_FTDC_MGT_ExchMarginRate = '0'

// 投资者保证金率
const THOST_FTDC_MGT_InstrMarginRate = '1'

// 投资者交易保证金率
const THOST_FTDC_MGT_InstrMarginRateTrade = '2'

// 生效类型类型
type TThostFtdcActiveTypeType byte

// 仅当日生效
const THOST_FTDC_ACT_Intraday = '1'

// 长期生效
const THOST_FTDC_ACT_Long = '2'

// 冲突保证金率类型类型
type TThostFtdcMarginRateTypeType byte

// 交易所保证金率
const THOST_FTDC_MRT_Exchange = '1'

// 投资者保证金率
const THOST_FTDC_MRT_Investor = '2'

// 投资者交易保证金率
const THOST_FTDC_MRT_InvestorTrade = '3'

// 备份数据状态类型
type TThostFtdcBackUpStatusType byte

// 未生成备份数据
const THOST_FTDC_BUS_UnBak = '0'

// 备份数据生成中
const THOST_FTDC_BUS_BakUp = '1'

// 已生成备份数据
const THOST_FTDC_BUS_BakUped = '2'

// 备份数据失败
const THOST_FTDC_BUS_BakFail = '3'

// 结算初始化状态类型
type TThostFtdcInitSettlementType byte

// 结算初始化未开始
const THOST_FTDC_SIS_UnInitialize = '0'

// 结算初始化中
const THOST_FTDC_SIS_Initialize = '1'

// 结算初始化完成
const THOST_FTDC_SIS_Initialized = '2'

// 报表数据生成状态类型
type TThostFtdcReportStatusType byte

// 未生成报表数据
const THOST_FTDC_SRS_NoCreate = '0'

// 报表数据生成中
const THOST_FTDC_SRS_Create = '1'

// 已生成报表数据
const THOST_FTDC_SRS_Created = '2'

// 生成报表数据失败
const THOST_FTDC_SRS_CreateFail = '3'

// 数据归档状态类型
type TThostFtdcSaveStatusType byte

// 归档未完成
const THOST_FTDC_SSS_UnSaveData = '0'

// 归档完成
const THOST_FTDC_SSS_SaveDatad = '1'

// 结算确认数据归档状态类型
type TThostFtdcSettArchiveStatusType byte

// 未归档数据
const THOST_FTDC_SAS_UnArchived = '0'

// 数据归档中
const THOST_FTDC_SAS_Archiving = '1'

// 已归档数据
const THOST_FTDC_SAS_Archived = '2'

// 归档数据失败
const THOST_FTDC_SAS_ArchiveFail = '3'

// CTP交易系统类型类型
type TThostFtdcCTPTypeType byte

// 未知类型
const THOST_FTDC_CTPT_Unkown = '0'

// 主中心
const THOST_FTDC_CTPT_MainCenter = '1'

// 备中心
const THOST_FTDC_CTPT_BackUp = '2'

// 平仓处理类型类型
type TThostFtdcCloseDealTypeType byte

// 正常
const THOST_FTDC_CDT_Normal = '0'

// 投机平仓优先
const THOST_FTDC_CDT_SpecFirst = '1'

// 货币质押资金可用范围类型
type TThostFtdcMortgageFundUseRangeType byte

// 不能使用
const THOST_FTDC_MFUR_None = '0'

// 用于保证金
const THOST_FTDC_MFUR_Margin = '1'

// 用于手续费、盈亏、保证金
const THOST_FTDC_MFUR_All = '2'

// 人民币方案3
const THOST_FTDC_MFUR_CNY3 = '3'

// 特殊产品类型类型
type TThostFtdcSpecProductTypeType byte

// 郑商所套保产品
const THOST_FTDC_SPT_CzceHedge = '1'

// 货币质押产品
const THOST_FTDC_SPT_IneForeignCurrency = '2'

// 大连短线开平仓产品
const THOST_FTDC_SPT_DceOpenClose = '3'

// 货币质押类型类型
type TThostFtdcFundMortgageTypeType byte

// 质押
const THOST_FTDC_FMT_Mortgage = '1'

// 解质
const THOST_FTDC_FMT_Redemption = '2'

// 投资者账户结算参数代码类型
type TThostFtdcAccountSettlementParamIDType byte

// 基础保证金
const THOST_FTDC_ASPI_BaseMargin = '1'

// 最低权益标准
const THOST_FTDC_ASPI_LowestInterest = '2'

// 货币质押方向类型
type TThostFtdcFundMortDirectionType byte

// 货币质入
const THOST_FTDC_FMD_In = '1'

// 货币质出
const THOST_FTDC_FMD_Out = '2'

// 换汇类别类型
type TThostFtdcBusinessClassType byte

// 盈利
const THOST_FTDC_BT_Profit = '0'

// 亏损
const THOST_FTDC_BT_Loss = '1'

// 其他
const THOST_FTDC_BT_Other = 'Z'

// 换汇数据来源类型
type TThostFtdcSwapSourceTypeType byte

// 手工
const THOST_FTDC_SST_Manual = '0'

// 自动生成
const THOST_FTDC_SST_Automatic = '1'

// 换汇类型类型
type TThostFtdcCurrExDirectionType byte

// 结汇
const THOST_FTDC_CED_Settlement = '0'

// 售汇
const THOST_FTDC_CED_Sale = '1'

// 申请状态类型
type TThostFtdcCurrencySwapStatusType byte

// 已录入
const THOST_FTDC_CSS_Entry = '1'

// 已审核
const THOST_FTDC_CSS_Approve = '2'

// 已拒绝
const THOST_FTDC_CSS_Refuse = '3'

// 已撤销
const THOST_FTDC_CSS_Revoke = '4'

// 已发送
const THOST_FTDC_CSS_Send = '5'

// 换汇成功
const THOST_FTDC_CSS_Success = '6'

// 换汇失败
const THOST_FTDC_CSS_Failure = '7'

// 换汇发送标志类型
type TThostFtdcReqFlagType byte

// 未发送
const THOST_FTDC_REQF_NoSend = '0'

// 发送成功
const THOST_FTDC_REQF_SendSuccess = '1'

// 发送失败
const THOST_FTDC_REQF_SendFailed = '2'

// 等待重发
const THOST_FTDC_REQF_WaitReSend = '3'

// 换汇返回成功标志类型
type TThostFtdcResFlagType byte

// 成功
const THOST_FTDC_RESF_Success = '0'

// 账户余额不足
const THOST_FTDC_RESF_InsuffiCient = '1'

// 交易结果未知
const THOST_FTDC_RESF_UnKnown = '8'

// 修改状态类型
type TThostFtdcExStatusType byte

// 修改前
const THOST_FTDC_EXS_Before = '0'

// 修改后
const THOST_FTDC_EXS_After = '1'

// 开户客户地域类型
type TThostFtdcClientRegionType byte

// 国内客户
const THOST_FTDC_CR_Domestic = '1'

// 港澳台客户
const THOST_FTDC_CR_GMT = '2'

// 国外客户
const THOST_FTDC_CR_Foreign = '3'

// 是否有董事会类型
type TThostFtdcHasBoardType byte

// 没有
const THOST_FTDC_HB_No = '0'

// 有
const THOST_FTDC_HB_Yes = '1'

// 启动模式类型
type TThostFtdcStartModeType byte

// 正常
const THOST_FTDC_SM_Normal = '1'

// 应急
const THOST_FTDC_SM_Emerge = '2'

// 恢复
const THOST_FTDC_SM_Restore = '3'

// 模型类型类型
type TThostFtdcTemplateTypeType byte

// 全量
const THOST_FTDC_TPT_Full = '1'

// 增量
const THOST_FTDC_TPT_Increment = '2'

// 备份
const THOST_FTDC_TPT_BackUp = '3'

// 登录模式类型
type TThostFtdcLoginModeType byte

// 交易
const THOST_FTDC_LM_Trade = '0'

// 转账
const THOST_FTDC_LM_Transfer = '1'

// 日历提示类型类型
type TThostFtdcPromptTypeType byte

// 合约上下市
const THOST_FTDC_CPT_Instrument = '1'

// 保证金分段生效
const THOST_FTDC_CPT_Margin = '2'

// 是否有托管人类型
type TThostFtdcHasTrusteeType byte

// 有
const THOST_FTDC_HT_Yes = '1'

// 没有
const THOST_FTDC_HT_No = '0'

// 机构类型类型
type TThostFtdcAmTypeType byte

// 银行
const THOST_FTDC_AMT_Bank = '1'

// 证券公司
const THOST_FTDC_AMT_Securities = '2'

// 基金公司
const THOST_FTDC_AMT_Fund = '3'

// 保险公司
const THOST_FTDC_AMT_Insurance = '4'

// 信托公司
const THOST_FTDC_AMT_Trust = '5'

// 其他
const THOST_FTDC_AMT_Other = '9'

// 出入金类型类型
type TThostFtdcCSRCFundIOTypeType byte

// 出入金
const THOST_FTDC_CFIOT_FundIO = '0'

// 银期换汇
const THOST_FTDC_CFIOT_SwapCurrency = '1'

// 结算账户类型类型
type TThostFtdcCusAccountTypeType byte

// 期货结算账户
const THOST_FTDC_CAT_Futures = '1'

// 纯期货资管业务下的资管结算账户
const THOST_FTDC_CAT_AssetmgrFuture = '2'

// 综合类资管业务下的期货资管托管账户
const THOST_FTDC_CAT_AssetmgrTrustee = '3'

// 综合类资管业务下的资金中转账户
const THOST_FTDC_CAT_AssetmgrTransfer = '4'

// 通知语言类型类型
type TThostFtdcLanguageTypeType byte

// 中文
const THOST_FTDC_LT_Chinese = '1'

// 英文
const THOST_FTDC_LT_English = '2'

// 资产管理客户类型类型
type TThostFtdcAssetmgrClientTypeType byte

// 个人资管客户
const THOST_FTDC_AMCT_Person = '1'

// 单位资管客户
const THOST_FTDC_AMCT_Organ = '2'

// 特殊单位资管客户
const THOST_FTDC_AMCT_SpecialOrgan = '4'

// 投资类型类型
type TThostFtdcAssetmgrTypeType byte

// 期货类
const THOST_FTDC_ASST_Futures = '3'

// 综合类
const THOST_FTDC_ASST_SpecialOrgan = '4'

// 合约比较类型类型
type TThostFtdcCheckInstrTypeType byte

// 合约交易所不存在
const THOST_FTDC_CIT_HasExch = '0'

// 合约本系统不存在
const THOST_FTDC_CIT_HasATP = '1'

// 合约比较不一致
const THOST_FTDC_CIT_HasDiff = '2'

// 交割类型类型
type TThostFtdcDeliveryTypeType byte

// 手工交割
const THOST_FTDC_DT_HandDeliv = '1'

// 到期交割
const THOST_FTDC_DT_PersonDeliv = '2'

// 大额单边保证金算法类型
type TThostFtdcMaxMarginSideAlgorithmType byte

// 不使用大额单边保证金算法
const THOST_FTDC_MMSA_NO = '0'

// 使用大额单边保证金算法
const THOST_FTDC_MMSA_YES = '1'

// 资产管理客户类型类型
type TThostFtdcDAClientTypeType byte

// 自然人
const THOST_FTDC_CACT_Person = '0'

// 法人
const THOST_FTDC_CACT_Company = '1'

// 其他
const THOST_FTDC_CACT_Other = '2'

// 投资类型类型
type TThostFtdcUOAAssetmgrTypeType byte

// 期货类
const THOST_FTDC_UOAAT_Futures = '1'

// 综合类
const THOST_FTDC_UOAAT_SpecialOrgan = '2'

// 买卖方向类型
type TThostFtdcDirectionEnType byte

//  Buy
const THOST_FTDC_DEN_Buy = '0'

//  Sell
const THOST_FTDC_DEN_Sell = '1'

// 开平标志类型
type TThostFtdcOffsetFlagEnType byte

//  Position Opening
const THOST_FTDC_OFEN_Open = '0'

//  Position Close
const THOST_FTDC_OFEN_Close = '1'

//  Forced Liquidation
const THOST_FTDC_OFEN_ForceClose = '2'

//  Close Today
const THOST_FTDC_OFEN_CloseToday = '3'

//  Close Prev.
const THOST_FTDC_OFEN_CloseYesterday = '4'

//  Forced Reduction
const THOST_FTDC_OFEN_ForceOff = '5'

//  Local Forced Liquidation
const THOST_FTDC_OFEN_LocalForceClose = '6'

// 投机套保标志类型
type TThostFtdcHedgeFlagEnType byte

//  Speculation
const THOST_FTDC_HFEN_Speculation = '1'

//  Arbitrage
const THOST_FTDC_HFEN_Arbitrage = '2'

//  Hedge
const THOST_FTDC_HFEN_Hedge = '3'

// 出入金类型类型
type TThostFtdcFundIOTypeEnType byte

//  Deposit/Withdrawal
const THOST_FTDC_FIOTEN_FundIO = '1'

//  Bank-Futures Transfer
const THOST_FTDC_FIOTEN_Transfer = '2'

//  Bank-Futures FX Exchange
const THOST_FTDC_FIOTEN_SwapCurrency = '3'

// 资金类型类型
type TThostFtdcFundTypeEnType byte

//  Bank Deposit
const THOST_FTDC_FTEN_Deposite = '1'

//  Payment/Fee
const THOST_FTDC_FTEN_ItemFund = '2'

//  Brokerage Adj
const THOST_FTDC_FTEN_Company = '3'

//  Internal Transfer
const THOST_FTDC_FTEN_InnerTransfer = '4'

// 出入金方向类型
type TThostFtdcFundDirectionEnType byte

//  Deposit
const THOST_FTDC_FDEN_In = '1'

//  Withdrawal
const THOST_FTDC_FDEN_Out = '2'

// 货币质押方向类型
type TThostFtdcFundMortDirectionEnType byte

//  Pledge
const THOST_FTDC_FMDEN_In = '1'

//  Redemption
const THOST_FTDC_FMDEN_Out = '2'

// 期权类型类型
type TThostFtdcOptionsTypeType byte

// 看涨
const THOST_FTDC_CP_CallOptions = '1'

// 看跌
const THOST_FTDC_CP_PutOptions = '2'

// 执行方式类型
type TThostFtdcStrikeModeType byte

// 欧式
const THOST_FTDC_STM_Continental = '0'

// 美式
const THOST_FTDC_STM_American = '1'

// 百慕大
const THOST_FTDC_STM_Bermuda = '2'

// 执行类型类型
type TThostFtdcStrikeTypeType byte

// 自身对冲
const THOST_FTDC_STT_Hedge = '0'

// 匹配执行
const THOST_FTDC_STT_Match = '1'

// 中金所期权放弃执行申请类型类型
type TThostFtdcApplyTypeType byte

// 不执行数量
const THOST_FTDC_APPT_NotStrikeNum = '4'

// 放弃执行申请数据来源类型
type TThostFtdcGiveUpDataSourceType byte

// 系统生成
const THOST_FTDC_GUDS_Gen = '0'

// 手工添加
const THOST_FTDC_GUDS_Hand = '1'

// 执行结果类型
type TThostFtdcExecResultType byte

// 没有执行
const THOST_FTDC_OER_NoExec = 'n'

// 已经取消
const THOST_FTDC_OER_Canceled = 'c'

// 执行成功
const THOST_FTDC_OER_OK = '0'

// 期权持仓不够
const THOST_FTDC_OER_NoPosition = '1'

// 资金不够
const THOST_FTDC_OER_NoDeposit = '2'

// 会员不存在
const THOST_FTDC_OER_NoParticipant = '3'

// 客户不存在
const THOST_FTDC_OER_NoClient = '4'

// 合约不存在
const THOST_FTDC_OER_NoInstrument = '6'

// 没有执行权限
const THOST_FTDC_OER_NoRight = '7'

// 不合理的数量
const THOST_FTDC_OER_InvalidVolume = '8'

// 没有足够的历史成交
const THOST_FTDC_OER_NoEnoughHistoryTrade = '9'

// 未知
const THOST_FTDC_OER_Unknown = 'a'

// 组合类型类型
type TThostFtdcCombinationTypeType byte

// 期货组合
const THOST_FTDC_COMBT_Future = '0'

// 垂直价差BUL
const THOST_FTDC_COMBT_BUL = '1'

// 垂直价差BER
const THOST_FTDC_COMBT_BER = '2'

// 跨式组合
const THOST_FTDC_COMBT_STD = '3'

// 宽跨式组合
const THOST_FTDC_COMBT_STG = '4'

// 备兑组合
const THOST_FTDC_COMBT_PRT = '5'

// 时间价差组合
const THOST_FTDC_COMBT_CAS = '6'

// 期权对锁组合
const THOST_FTDC_COMBT_OPL = '7'

// 买备兑组合
const THOST_FTDC_COMBT_BFO = '8'

// 买入期权垂直价差组合
const THOST_FTDC_COMBT_BLS = '9'

// 卖出期权垂直价差组合
const THOST_FTDC_COMBT_BES = 'a'

// 组合类型类型
type TThostFtdcDceCombinationTypeType byte

// 期货对锁组合
const THOST_FTDC_DCECOMBT_SPL = '0'

// 期权对锁组合
const THOST_FTDC_DCECOMBT_OPL = '1'

// 期货跨期组合
const THOST_FTDC_DCECOMBT_SP = '2'

// 期货跨品种组合
const THOST_FTDC_DCECOMBT_SPC = '3'

// 买入期权垂直价差组合
const THOST_FTDC_DCECOMBT_BLS = '4'

// 卖出期权垂直价差组合
const THOST_FTDC_DCECOMBT_BES = '5'

// 期权日历价差组合
const THOST_FTDC_DCECOMBT_CAS = '6'

// 期权跨式组合
const THOST_FTDC_DCECOMBT_STD = '7'

// 期权宽跨式组合
const THOST_FTDC_DCECOMBT_STG = '8'

// 买入期货期权组合
const THOST_FTDC_DCECOMBT_BFO = '9'

// 卖出期货期权组合
const THOST_FTDC_DCECOMBT_SFO = 'a'

// 期权权利金价格类型类型
type TThostFtdcOptionRoyaltyPriceTypeType byte

// 昨结算价
const THOST_FTDC_ORPT_PreSettlementPrice = '1'

// 开仓价
const THOST_FTDC_ORPT_OpenPrice = '4'

// 最新价与昨结算价较大值
const THOST_FTDC_ORPT_MaxPreSettlementPrice = '5'

// 权益算法类型
type TThostFtdcBalanceAlgorithmType byte

// 不计算期权市值盈亏
const THOST_FTDC_BLAG_Default = '1'

// 计算期权市值亏损
const THOST_FTDC_BLAG_IncludeOptValLost = '2'

// 执行类型类型
type TThostFtdcActionTypeType byte

// 执行
const THOST_FTDC_ACTP_Exec = '1'

// 放弃
const THOST_FTDC_ACTP_Abandon = '2'

// 询价状态类型
type TThostFtdcForQuoteStatusType byte

// 已经提交
const THOST_FTDC_FQST_Submitted = 'a'

// 已经接受
const THOST_FTDC_FQST_Accepted = 'b'

// 已经被拒绝
const THOST_FTDC_FQST_Rejected = 'c'

// 取值方式类型
type TThostFtdcValueMethodType byte

// 按绝对值
const THOST_FTDC_VM_Absolute = '0'

// 按比率
const THOST_FTDC_VM_Ratio = '1'

// 期权行权后是否保留期货头寸的标记类型
type TThostFtdcExecOrderPositionFlagType byte

// 保留
const THOST_FTDC_EOPF_Reserve = '0'

// 不保留
const THOST_FTDC_EOPF_UnReserve = '1'

// 期权行权后生成的头寸是否自动平仓类型
type TThostFtdcExecOrderCloseFlagType byte

// 自动平仓
const THOST_FTDC_EOCF_AutoClose = '0'

// 免于自动平仓
const THOST_FTDC_EOCF_NotToClose = '1'

// 产品类型类型
type TThostFtdcProductTypeType byte

// 期货
const THOST_FTDC_PTE_Futures = '1'

// 期权
const THOST_FTDC_PTE_Options = '2'

// 郑商所结算文件名类型
type TThostFtdcCZCEUploadFileNameType byte

// ^\d{8}_zz_\d{4}
const THOST_FTDC_CUFN_CUFN_O = 'O'

// ^\d{8}成交表
const THOST_FTDC_CUFN_CUFN_T = 'T'

// ^\d{8}单腿持仓表new
const THOST_FTDC_CUFN_CUFN_P = 'P'

// ^\d{8}非平仓了结表
const THOST_FTDC_CUFN_CUFN_N = 'N'

// ^\d{8}平仓表
const THOST_FTDC_CUFN_CUFN_L = 'L'

// ^\d{8}资金表
const THOST_FTDC_CUFN_CUFN_F = 'F'

// ^\d{8}组合持仓表
const THOST_FTDC_CUFN_CUFN_C = 'C'

// ^\d{8}保证金参数表
const THOST_FTDC_CUFN_CUFN_M = 'M'

// 大商所结算文件名类型
type TThostFtdcDCEUploadFileNameType byte

// ^\d{8}_dl_\d{3}
const THOST_FTDC_DUFN_DUFN_O = 'O'

// ^\d{8}_成交表
const THOST_FTDC_DUFN_DUFN_T = 'T'

// ^\d{8}_持仓表
const THOST_FTDC_DUFN_DUFN_P = 'P'

// ^\d{8}_资金结算表
const THOST_FTDC_DUFN_DUFN_F = 'F'

// ^\d{8}_优惠组合持仓明细表
const THOST_FTDC_DUFN_DUFN_C = 'C'

// ^\d{8}_持仓明细表
const THOST_FTDC_DUFN_DUFN_D = 'D'

// ^\d{8}_保证金参数表
const THOST_FTDC_DUFN_DUFN_M = 'M'

// ^\d{8}_期权执行表
const THOST_FTDC_DUFN_DUFN_S = 'S'

// 上期所结算文件名类型
type TThostFtdcSHFEUploadFileNameType byte

// ^\d{4}_\d{8}_\d{8}_DailyFundChg
const THOST_FTDC_SUFN_SUFN_O = 'O'

// ^\d{4}_\d{8}_\d{8}_Trade
const THOST_FTDC_SUFN_SUFN_T = 'T'

// ^\d{4}_\d{8}_\d{8}_SettlementDetail
const THOST_FTDC_SUFN_SUFN_P = 'P'

// ^\d{4}_\d{8}_\d{8}_Capital
const THOST_FTDC_SUFN_SUFN_F = 'F'

// 中金所结算文件名类型
type TThostFtdcCFFEXUploadFileNameType byte

// ^\d{4}_SG\d{1}_\d{8}_\d{1}_Trade
const THOST_FTDC_CFUFN_SUFN_T = 'T'

// ^\d{4}_SG\d{1}_\d{8}_\d{1}_SettlementDetail
const THOST_FTDC_CFUFN_SUFN_P = 'P'

// ^\d{4}_SG\d{1}_\d{8}_\d{1}_Capital
const THOST_FTDC_CFUFN_SUFN_F = 'F'

// ^\d{4}_SG\d{1}_\d{8}_\d{1}_OptionExec
const THOST_FTDC_CFUFN_SUFN_S = 'S'

// 组合指令方向类型
type TThostFtdcCombDirectionType byte

// 申请组合
const THOST_FTDC_CMDR_Comb = '0'

// 申请拆分
const THOST_FTDC_CMDR_UnComb = '1'

// 操作员删组合单
const THOST_FTDC_CMDR_DelComb = '2'

// 行权偏移类型类型
type TThostFtdcStrikeOffsetTypeType byte

// 实值额
const THOST_FTDC_STOV_RealValue = '1'

// 盈利额
const THOST_FTDC_STOV_ProfitValue = '2'

// 实值比例
const THOST_FTDC_STOV_RealRatio = '3'

// 盈利比例
const THOST_FTDC_STOV_ProfitRatio = '4'

// 预约开户状态类型
type TThostFtdcReserveOpenAccStasType byte

// 等待处理中
const THOST_FTDC_ROAST_Processing = '0'

// 已撤销
const THOST_FTDC_ROAST_Cancelled = '1'

// 已开户
const THOST_FTDC_ROAST_Opened = '2'

// 无效请求
const THOST_FTDC_ROAST_Invalid = '3'

// 弱密码来源类型
type TThostFtdcWeakPasswordSourceType byte

// 弱密码库
const THOST_FTDC_WPSR_Lib = '1'

// 手工录入
const THOST_FTDC_WPSR_Manual = '2'

// 期权行权的头寸是否自对冲类型
type TThostFtdcOptSelfCloseFlagType byte

// 自对冲期权仓位
const THOST_FTDC_OSCF_CloseSelfOptionPosition = '1'

// 保留期权仓位
const THOST_FTDC_OSCF_ReserveOptionPosition = '2'

// 自对冲卖方履约后的期货仓位
const THOST_FTDC_OSCF_SellCloseSelfFuturePosition = '3'

// 保留卖方履约后的期货仓位
const THOST_FTDC_OSCF_ReserveFuturePosition = '4'

// 业务类型类型
type TThostFtdcBizTypeType byte

// 期货
const THOST_FTDC_BZTP_Future = '1'

// 证券
const THOST_FTDC_BZTP_Stock = '2'

// 用户App类型类型
type TThostFtdcAppTypeType byte

// 直连的投资者
const THOST_FTDC_APP_TYPE_Investor = '1'

// 为每个投资者都创建连接的中继
const THOST_FTDC_APP_TYPE_InvestorRelay = '2'

// 所有投资者共享一个操作员连接的中继
const THOST_FTDC_APP_TYPE_OperatorRelay = '3'

// 未知
const THOST_FTDC_APP_TYPE_UnKnown = '4'

// 应答类型类型
type TThostFtdcResponseValueType byte

// 检查成功
const THOST_FTDC_RV_Right = '0'

// 检查失败
const THOST_FTDC_RV_Refuse = '1'

// OTC成交类型类型
type TThostFtdcOTCTradeTypeType byte

// 大宗交易
const THOST_FTDC_OTC_TRDT_Block = '0'

// 期转现
const THOST_FTDC_OTC_TRDT_EFP = '1'

// 期现风险匹配方式类型
type TThostFtdcMatchTypeType byte

// 基点价值
const THOST_FTDC_OTC_MT_DV01 = '1'

// 面值
const THOST_FTDC_OTC_MT_ParValue = '2'

// 用户终端认证方式类型
type TThostFtdcAuthTypeType byte

// 白名单校验
const THOST_FTDC_AU_WHITE = '0'

// 黑名单校验
const THOST_FTDC_AU_BLACK = '1'

// 合约分类方式类型
type TThostFtdcClassTypeType byte

// 所有合约
const THOST_FTDC_INS_ALL = '0'

// 期货、即期、期转现、Tas、金属指数合约
const THOST_FTDC_INS_FUTURE = '1'

// 期货、现货期权合约
const THOST_FTDC_INS_OPTION = '2'

// 组合合约
const THOST_FTDC_INS_COMB = '3'

// 合约交易状态分类方式类型
type TThostFtdcTradingTypeType byte

// 所有状态
const THOST_FTDC_TD_ALL = '0'

// 交易
const THOST_FTDC_TD_TRADE = '1'

// 非交易
const THOST_FTDC_TD_UNTRADE = '2'

// 产品状态类型
type TThostFtdcProductStatusType byte

// 可交易
const THOST_FTDC_PS_tradeable = '1'

// 不可交易
const THOST_FTDC_PS_untradeable = '2'

// 追平状态类型
type TThostFtdcSyncDeltaStatusType byte

// 交易可读
const THOST_FTDC_SDS_Readable = '1'

// 交易在读
const THOST_FTDC_SDS_Reading = '2'

// 交易读取完成
const THOST_FTDC_SDS_Readend = '3'

// 追平失败 交易本地状态结算不存在
const THOST_FTDC_SDS_OptErr = 'e'

// 操作标志类型
type TThostFtdcActionDirectionType byte

// 增加
const THOST_FTDC_ACD_Add = '1'

// 删除
const THOST_FTDC_ACD_Del = '2'

// 更新
const THOST_FTDC_ACD_Upd = '3'

// 紧急程度类型
type TThostFtdcNewsUrgencyType byte
