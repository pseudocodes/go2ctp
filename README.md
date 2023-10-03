Go2ctp
==========================================
## Sample
参考 sample 目录中的代码
### market data sample
```go
type baseSpi struct {
	ctp_tts.BaseMdSpi
	// ctp.BaseMdSpi
	mdapi ctp_tts.MdApi
}

func CreateBaseSpi() *baseSpi {
	s := &baseSpi{}
	return s
}

func (s *baseSpi) OnFrontConnected() {
	log.Printf("OnFrontConnected\n")

	loginR := &thost.CThostFtdcReqUserLoginField{}
	copy(loginR.BrokerID[:], "9999")
	copy(loginR.UserID[:], "2011")

	ret := s.mdapi.ReqUserLogin(loginR, 1)

	log.Printf("user log: %v\n", ret)
}

func (s *baseSpi) OnHeartBeatWarning(timelapse int) {
	log.Printf("OnHeartBeatWarning: %v\n", timelapse)
}

func (s *baseSpi) OnFrontDisconnected(nReason int) {
	log.Printf("OnFrontDisconnected: %v\n", nReason)
}

func (s *baseSpi) OnRspUserLogin(pRspUserLogin *thost.CThostFtdcRspUserLoginField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("RspUserLogin: %+v\nRspInfo: %+v\n", pRspUserLogin, nil)
	s.mdapi.SubscribeMarketData("ag2310")
}

func (s *baseSpi) OnRspSubMarketData(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {

	log.Printf("instrumentID: %+v\n  RspInfo: %+v\n", pSpecificInstrument, nil)
}

func (s *baseSpi) OnRtnDepthMarketData(pDepthMarketData *thost.CThostFtdcDepthMarketDataField) {
	log.Printf("OnRtnDeptMarketData\n")
}

func (s *baseSpi) OnRspError(pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("RspInfo: %+v\n", pRspInfo.ErrorID)

}

func main() {
	var mdapi ctp_tts.MdApi
	if runtime.GOOS == "darwin" {
		mdapi = ctp_tts.CreateMdApi(ctp_tts.MdDynamicLibPath("../../ctp_tts/lib/v6.6.9_20220920/mac_arm64/libthostmduserapi_se.dylib"), ctp_tts.MdFlowPath("./data/"), ctp_tts.MdUsingUDP(false), ctp_tts.MdMultiCast(false))
	} else if runtime.GOOS == "linux" {
		mdapi = ctp_tts.CreateMdApi(ctp_tts.MdDynamicLibPath("../../ctp_tts/lib/v6.6.9_20220920/lin64/thostmduserapi_se.so"), ctp_tts.MdFlowPath("./data/"), ctp_tts.MdUsingUDP(false), ctp_tts.MdMultiCast(false))
	}

	baseSpi := CreateBaseSpi()
	baseSpi.mdapi = mdapi
	mdapi.RegisterSpi(baseSpi)

	mdapi.RegisterFront("tcp://121.37.80.177:20004")
	mdapi.Init()

	println(mdapi.GetApiVersion())
	println(mdapi.GetTradingDay())

	// mdapi.Join()
	for {
		time.Sleep(10 * time.Second)
	}

}

```


## FAQ
> Q: 为什么在有了 [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp) 项目之后又开启了 *go2ctp* 项目
> 
> A: 发现前项目使用后切换平台 (MacOS), 使用 OpenCTP TTS 系统，以及穿透式认证时(使用 CP 版本) 比较不方便，在静态编译封装的方式下只能将不同的平台库放在不同的分支下，再加上未来对 *ctp-mini* 的支持，就在本项目集中对不同平台的 CTP 库进行集中提供

> Q: 与 [*github.com/hankchan/goctp*](https://github.com/hankchan/goctp) 项目有什么区别
> 
> A: 该项目最早来自 *github.com/qerio/goctp*，是最早可用的完整 golang 版本 ctp 封装，利用 *go build* 对 *swig* 的自动化编译支持，对 CTP 的头文件进行解析并生成中间代码参与编译，一般大家使用的 goctp 封装 **80%** 都来自该项目的衍生品
> 该项目的问题：
> 1. swig 展开后的中间代码高达十几万行，编译比较慢，约超过 5 分钟
> 2. 早期更新 CTP 库版本时，需要修改部分 CTP 头文件内容，例如行情接口 `SubscribeMarketData` 的合约参数声明方式需要修改，否则 *swig* 在生成接口时无法生成 `__goslice__` 模式的参数，该问题直到最近 swig 才修复？
> 3. 由于(1) 中的原因，在开发时 IDE 的提示无法及时给出，同时 `swig` 生成的接口代码以及使用方式并不友好
> 4. Debug 跟踪困难;
> 
> 本项目解决的问题：
> * 简洁封装代码，不采用 swig，不对原始 API 文件进行修改;
> * 完全原生 go 语法类型支持，编译速度快，接口提示友好，保留原始文档注释说明;
> * Debug 跟踪方便;

> Q: 与 [*github.com/haifengat/goctp*](https://github.com/haifengat/goctp) 项目有什么区别
> 
> A: 海风提供的 goctp 的封装对 golang 的特性应用得最好， [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp) 也参考了该项目的一些细节, 提供 lite 接口的封装; 感谢这个项目在 golang 封装 ctp api 方向的探索
> 
> 该项目的问题：
> * v1 版本的封装比较乱，使用方式与传统的调用方式有出入;
> * v2 版本进行了进一步的抽象封装，提供了一些交易基础功能;
> * v1 版本一个进程程序只能创建一个 mdapi 和 traderapi 实例，这是该版本最大的问题 ;
> * v2 版本在 v1 版本的基础上做了增强，改用 map 来存储实例指针与对应对象 [quote.go](https://github.com/haifengat/goctp/blob/4f6f9df33fba15d28bf55209fc8111057c9546c7/quote.go#L113C14-L113C45) 可能出于使用频度的考虑，该 map 并未上锁，而 swig 展开代码对使用的 map 进行了并发锁处理；
> * 切换平台库依然不方便，v1 与 v2 版本都是通过拓展 clang 代码二次封装 so 库，绑定官方版本 API 库，如涉及切换平台库或穿透式认证场景时，还需用户自行编译动态库以及维护该 repo 的分支，对开发能力较弱的用户不友好；该项目对进一步的平台化开发支持有限；
> 
> 本项目解决问题：
> * 封装层数低，只提供一次 cgo 桥接转换，不涉及数据深拷贝
> * 运行时多个 API 实例共存，不同平台的 API 实例可以同时存在一个进程空间中，例如可以同时连接实盘， SIMNOW， OPENCTP
> * 全局指针 map 采用了标准库中的 cgo.Handle 无并发问题

> Q: 为什么不提供 Windows 平台支持
> 
> A: 开发者没有 Windows 环境，不想装虚拟机，大家可以提 PR

> Q: ctp 目录和 ctp_tts目录的封装有什么不同
> 
> A: 
> * ctp 的封装来自 [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp), 剔除了 *lite* 和 *convert* 相关代码，原则上只提供一层封装，直接桥接 Cgo 空间回调过来的数据
> * ctp 目录属于静态编译链接，其他项目采用该目录下的代码，依赖的动态库的路径会在编译构建期完成初始绑定，默认路径为 go2ctp 库的存放路径，只部署二进制程序在 Linux 环境需要设置 LD_LIBRARY_PATH 环境变量来提供依赖的 ctp 动态库路径，MacOS 环境同理
> * ctp_tts 封装方式采用了读取动态库符号的方式，通过在运行时提供动态库的路径，完成 API 实例对象的生成和绑定，理论上 ctp_tts 的封装方式更灵活方便，可以通过配置的方式动态的替换 linux 下不同平台的库，包括官方生产和测评版本，rohan(融航)，openctp-tts 平台，无需再编译项目代码. ctp-tts 同时支持 openctp 的 MacOS 版本 dylib
> * ctp_tts 使用需要用户明确提供动态库地址，部署时需要动态库与二进制程序一起部署

## TODO
* ctp-mini 支持
* 更丰富的使用样例
* DataCollect 库支持
* 扩展封装，提供高阶功能

## Reference
 【1】[*github.com/pseudocodes/goctp*](https://github.com/pseudocodes/goctp)   

 【2】[*github.com/haifengat/goctp*](https://github.com/haifengat/goctp)

 【3】[*github.com/hankchan/goctp*](https://github.com/hankchan/goctp) 

## 免责声明
本项目明确拒绝对产品做任何明示或暗示的担保。由于软件系统开发本身的复杂性，无法保证本项目完全没有错误。如选择使用本项目表示您同意错误和/或遗漏的存在，在任何情况下本项目对于直接、间接、特殊的、偶然的、或间接产生的、使用或无法使用本项目进行交易和投资造成的盈亏、直接或间接引起的赔偿、损失、债务或是任何交易中止均不承担责任和义务。

此声明永久有效