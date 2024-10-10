# Go2ctp

上海期货信息技术 CTP 接口 go 语言原生封装，支持生产，测评，OpenCTP, LocalCTP 版本, 适配 Linux, MacOS

对应 Rust 语言封装查看 **[ctp2rs](https://github.com/pseudocodes/ctp2rs/)** 项目


## Sample

### 静态依赖
```go

package main

import (
	"log"
	"os"
	"time"

	"github.com/pseudocodes/go2ctp/ctp"
	"github.com/pseudocodes/go2ctp/thost"
)

func init() {
	log.SetFlags(log.LstdFlags | log.Lshortfile)
}

type baseSpi struct {
	brokerID   string
	investorID string
	password   string

	ctp.BaseMdSpi
	mdapi thost.MdApi
}

func CreateBaseSpi() *baseSpi {
	s := &baseSpi{
		brokerID:   "9999",
		investorID: os.Getenv("SIMNOW_USER_ID"),       // <- 环境变量设置
		password:   os.Getenv("SIMNOW_USER_PASSWORD"), // <- 环境变量设置
	}
	return s
}

func (s *baseSpi) OnFrontConnected() {
	log.Printf("OnFrontConnected\n")

	loginR := &thost.CThostFtdcReqUserLoginField{}
	copy(loginR.BrokerID[:], []byte(s.brokerID))
	copy(loginR.UserID[:], []byte(s.investorID))

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
	s.mdapi.SubscribeMarketData("ag2408")
}

func (s *baseSpi) OnRspSubMarketData(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("instrumentID: %+v\n  RspInfo: %+v\n", pSpecificInstrument, nil)
}

func (s *baseSpi) OnRtnDepthMarketData(pDepthMarketData *thost.CThostFtdcDepthMarketDataField) {
	log.Printf("OnRtnDeptMarketData: %s\n", string(pDepthMarketData.InstrumentID[:7]))
}

func (s *baseSpi) OnRspError(pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("RspInfo: %+v\n", pRspInfo.ErrorID)
}

func main() {
	mdapi := ctp.CreateMdApi(ctp.MdFlowPath("./data/"), ctp.MdUsingUDP(false), ctp.MdMultiCast(false))
	baseSpi := CreateBaseSpi()
	baseSpi.mdapi = mdapi
	mdapi.RegisterSpi(baseSpi)

	mdapi.RegisterFront("tcp://180.168.146.187:10211")

	mdapi.Init()

	println(mdapi.GetApiVersion())
	println(mdapi.GetTradingDay())
	// mdapi.Join()
	//
	for {
		time.Sleep(10 * time.Second)
	}
}

```

### 动态库
```go
package main

import (
	"log"
	"os"
	"time"
	"runtime"

	"github.com/pseudocodes/go2ctp/ctp_dyn"
	"github.com/pseudocodes/go2ctp/thost"
)

func init() {
	log.SetFlags(log.LstdFlags | log.Lshortfile)
}

type baseSpi struct {
	brokerID   string
	investorID string
	password   string

	ctp.BaseMdSpi
	mdapi thost.MdApi
}

func CreateBaseSpi() *baseSpi {
	s := &baseSpi{
		brokerID:   "9999",
		investorID: os.Getenv("SIMNOW_USER_ID"),       // <- 环境变量设置
		password:   os.Getenv("SIMNOW_USER_PASSWORD"), // <- 环境变量设置
	}
	return s
}

func (s *baseSpi) OnFrontConnected() {
	log.Printf("OnFrontConnected\n")

	loginR := &thost.CThostFtdcReqUserLoginField{}
	copy(loginR.BrokerID[:], []byte(s.brokerID))
	copy(loginR.UserID[:], []byte(s.investorID))

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
	s.mdapi.SubscribeMarketData("ag2408")
}

func (s *baseSpi) OnRspSubMarketData(pSpecificInstrument *thost.CThostFtdcSpecificInstrumentField, pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("instrumentID: %+v\n  RspInfo: %+v\n", pSpecificInstrument, nil)
}

func (s *baseSpi) OnRtnDepthMarketData(pDepthMarketData *thost.CThostFtdcDepthMarketDataField) {
	log.Printf("OnRtnDeptMarketData: %s\n", string(pDepthMarketData.InstrumentID[:7]))
}

func (s *baseSpi) OnRspError(pRspInfo *thost.CThostFtdcRspInfoField, nRequestID int, bIsLast bool) {
	log.Printf("RspInfo: %+v\n", pRspInfo.ErrorID)
}

func main() {
	var (
		mdapi     thost.MdApi
		frontAddr string
		
		CTPLibPathMacos = "/the/user/path/to/thostmduserapi_se.framework/thostmduserapi_se"
		CTPLibPathLinux = "/the/user/path/to/thostmduserapi_se.so"
		TTSLibPathMacos = "/the/user/path/to/openctp/thostmduserapi_se.dylib"
	)
	if runtime.GOOS == "darwin" {
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(CTPLibPathMacos), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		frontAddr = SimnowFront
	} else if runtime.GOOS == "linux" {
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(CTPLibPathLinux), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		frontAddr = SimnowFront
	}

	baseSpi := CreateBaseSpi()
	baseSpi.mdapi = mdapi
	mdapi.RegisterSpi(baseSpi)

	mdapi.RegisterFront(frontAddr)

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
**Q.01**: 为什么在有了 [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp) 项目之后又开启了 *go2ctp* 项目
 
**A.01**: 发现前项目使用后切换平台 (MacOS), 使用 OpenCTP TTS 系统，以及穿透式认证时(使用 CP 版本) 比较不方便，在静态编译封装的方式下只能将不同的平台库放在不同的分支下，再加上未来对 *ctp-mini* 的支持，就在本项目集中对不同平台的 CTP 库进行集中提供

**Q.02**: 与 [*github.com/hankchan/goctp*](https://github.com/hankchan/goctp) 项目有什么区别

**A.02**: 该项目最早来自 *github.com/qerio/goctp*，是最早可用的完整 golang 版本 ctp 封装，利用 *go build* 对 *swig* 的自动化编译支持，对 CTP 的头文件进行解析并生成中间代码参与编译，一般大家使用的 goctp 封装 **80%** 都来自该项目的衍生品
> 该项目的问题：
> 1. swig 展开后的中间代码高达十几万行，编译比较慢，约超过 5 分钟
> 2. 早期更新 CTP 库版本时，需要修改部分 CTP 头文件内容，例如行情接口 `SubscribeMarketData` 的合约参数声明方式需要修改，否则 *swig* 在生成接口时无法生成 `__goslice__` 模式的参数，该问题 [#749](https://github.com/swig/swig/issues/749) 2016 年提出, 直到 2022 年 swig 才修复 
> 3. 由于(1) 中的原因，在开发时 IDE 的提示无法及时给出，同时 `swig` 生成的接口代码以及使用方式并不友好
> 4. Debug 跟踪困难;

> 本项目解决的问题：
> * 简洁封装代码，不采用 swig，不对原始 API 文件进行修改;
> * 完全原生 go 语法类型支持，编译速度快，接口提示友好，保留原始文档注释说明;
> * Debug 跟踪方便;

**Q.03**: 与 [*github.com/haifengat/goctp*](https://github.com/haifengat/goctp) 项目有什么区别

**A.03**: 海风提供的 goctp 的封装对 golang 的特性应用得最好， [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp) 也参考了该项目的一些细节, 提供 lite 接口的封装; 感谢这个项目在 golang 封装 ctp api 方向的探索

> 该项目的问题：
> * v1 版本的封装比较乱，使用方式与传统的调用方式有出入;
> * v1 版本一个进程程序只能创建一个 mdapi 和 traderapi 实例，这是该版本最大的问题 ;
> * v2 版本对一些交易基础功能提供了进一步的抽象封装;
> * v2 版本在 v1 版本的基础上做了增强，改用 map 来存储实例指针与对应对象 [quote.go](https://github.com/haifengat/goctp/blob/4f6f9df33fba15d28bf55209fc8111057c9546c7/quote.go#L113C14-L113C45), 可能出于使用频度的考虑，该 map 并未上锁，而 swig 展开代码对使用的 map 进行了并发锁处理；
> * 切换平台库依然不方便，v1 与 v2 版本都是通过拓展 clang 代码二次封装 so 库，绑定官方版本 API 库，如涉及切换平台库或穿透式认证场景时，还需用户自行编译动态库以及维护该 repo 的分支，对开发能力较弱的用户不友好；该项目对进一步的平台化开发支持有限；
 
> 本项目解决问题：
> * 封装层数低，只提供一次 cgo 桥接转换，不涉及数据深拷贝
> * 运行时多个 API 实例共存，不同平台的 API 实例可以同时存在一个进程空间中，例如可以同时连接实盘， SIMNOW， OPENCTP
> * 全局指针 map 采用了标准库中的 cgo.Handle 无并发问题

**Q.04**: 为什么不提供 Windows 平台支持

**A.04**: 开发者没有 Windows 环境，不想装虚拟机，有兴趣的开发者可以提 PR

**Q.05**: ctp 目录和 ctp_dyn 目录的封装有什么不同

**A.05**: 
> * ctp 的封装来自 [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp), 剔除了 *lite* 和 *convert* 相关代码，原则上只提供一层封装，直接桥接 cgo 空间回调过来的数据
> * ctp 目录属于静态编译链接，其他项目采用该目录下的代码，依赖的动态库的路径会在编译构建期完成初始绑定，默认路径为 go2ctp 库的存放路径，只部署二进制程序在 Linux 环境需要设置 LD_LIBRARY_PATH 环境变量来提供依赖的 ctp 动态库路径; MacOS 环境一般不用再独立设置 `@rpath`，推荐 MacOS 环境采用 ctp_dyn 依赖
> * ctp_dyn 封装方式采用了读取动态库符号的方式，通过在运行时提供动态库的路径，完成 API 实例对象的生成和绑定，理论上 ctp_dyn 的封装方式更灵活方便，可以通过配置的方式动态的替换 linux 下不同平台的库，包括官方生产和测评版本，rohan(融航)，openctp-tts 平台，无需再编译项目代码. ctp_dyn 同时支持 openctp 的 MacOS 版本 dylib
> * ctp_dyn 使用需要用户明确提供动态库地址，部署时需要动态库与二进制程序一起部署
>

**Q.06**: MacOS 环境下上期 CTP 编译运行问题

**A.06**: 相关信息如下
> *	官方从 CTP 6.7.0 版本开始提供 `.framework` 的动态库，而不像 OpenCTP 那样采用 `.dylib` 来提供支持
> *	官方打包发布的 `framework` 包可能有设置问题，包中软连接变成文本文件，如果直接引入该 `framework` 至 `Xcode` 项目会造成无法编译
> * `framework` 静态编译时就需要设定 `@rpath` 路径，运行二进制文件时才能获得动态库的路径，在这种场景下，更合适的方式还是采用动态库 `dlopen` 方式, 
> * MacOS 命令行下可以直接编译源代码程序并链接 `framework`，首次运行启动之后请到`系统设置->隐私与安全性->安全性` 标签中对 `thostmduserapi_se` 以及 `thosttraderapi_se` 这两个文件进行信任允许操作

**Q.07**: OpenCTP 与上期 CTP 在 MacOS 环境的区别

**A.07**: 相关信息如下
> * 上期 CTP MacOS 环境与 Linux 环境的区别主要在于 `CThostFtdcTraderApi` 中的 `ReqUserLogin` 接口参数不同, MacOS 对应接口比 Linux 多了两个穿透式信息的参数
```cpp
// Linux 接口
virtual int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) = 0;

// MacOS 接口
virtual int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length, TThostFtdcClientSystemInfoType systemInfo) = 0;
```
> * OpenCTP 提供的 MacOS 的头文件接口与 Linux 统一，即 `ReqUserLogin` 采用两参数接口，封装 `go2ctp` 过程中与 [@krenx](https://github.com/krenx1983) 沟通过这个问题，对方当时未有计划提供对标接口支持, 因此本项目在 MacOS 环境下编译 OpenCTP 相关库时，请采用 ctp_dyn pacakge，编译指令如下 

```shell
?> cd sample/simple_trader && go build -tags openctp

# 或者
?> cd sample/simple_trader && go build -tags tts
```

**Q.08**: ctp_dyn 高版本的封装(6.7.7) 是否兼容低版本 (6.7.2) 的动态库

**A.08**: 当前的封装方式不支持高版本封装加载低版本动态库，如 6.7.7 分支 `ctp_dyn` 不应加载 6.7.2 版本的 ctp/openctp 的动态库, 如果发生该种行为，程序编译运行之后会发生卡死或提示出错； 
确实有能够强制加载低版本动态库函数的封装方案，但是考虑到生产环境下应不隐藏风险，尽早抛出错误的原则，未采用强制加载的封装方案.
此外，请注意开发环境的区别，不要在 Macosx 环境下加载 so 动态库


## 注意事项
* 使用 ctp_dyn 时请对齐分支版本以及动态库版本
* Macosx 环境下如出现编译后运行无响应，可以排查系统以及 Go 版本

 
## 同类项目

| 项目地址    | Description | 推荐指数 | 
| --------- | ----------- |---------|
| https://github.com/gaxxx/ctp | 最早 golang 版本的 ctp 封装，作者发布在水木论坛，在这个项目中 <br> 可以观察到 go 早期版本的封装编译指令 | ☆☆☆☆☆ |
| https://github.com/pseudocodes/goctp   | 含 DataCollect 封装支持，提供 go 类型结构的 convert 转换方法   | ★★★★☆ |
| https://github.com/haifengat/goctp <br> [https://gitee.com/haifengat/goctp/v2](https://gitee.com/haifengat/goctp/tree/v2/) | 描述见 FAQ. | ★★★★☆|
| https://github.com/hankchan/goctp | 描述见 FAQ. | ★★★☆☆ |
| https://github.com/mayiweb/goctp | 源自 https://github.com/hankchan/goctp | ★★★☆☆ |
| https://github.com/kkqy/ctp-go | a. 对 CTP 的版本处理与 `A.01` 中的描述相同，不同版本放置于不同分支下 <br> b. 该项目将 Swig 编译后展开的代码直接放置于项目中，有 FAQ 中 `A.02` 中描述的问题，该项目文档也说明了编译速度慢的问题 <br> c. CTP 结构体创建在 c 内存空间侧，需要手动自行回收  |★★☆☆☆|
| https://github.com/ztrade/ctp| a. 项目整体布局类似 https://github.com/pseudocodes/goctp, 细节在于 wrapper 代码中将 Api 和 Spi 的 C++ 类分别进行了独立封装，与 SWIG 的展开代码类似 <br> b. 调用 Api 接口时 C 内存空间侧申请一次内存并拷贝结构体数据，Spi 回调侧 go 内存空间侧申请一次内存并拷贝结构体，相较本项目整体多了两次内存申请以及数据深拷贝 | ★★★★☆ |


## Base on `go2ctp`
* https://github.com/pseudocodes/light-trader
* alpha-trade-gateway (incoming)

## TODO
* 更丰富的使用样例
* 扩展封装，提供高阶功能
* CTP 版本与 GO 项目大版本同步 ？



## Reference
 【1】[*github.com/pseudocodes/goctp*](https://github.com/pseudocodes/goctp)   

 【2】[*github.com/haifengat/goctp*](https://github.com/haifengat/goctp)

 【3】[*github.com/hankchan/goctp*](https://github.com/hankchan/goctp) 

## 免责声明
本项目明确拒绝对产品做任何明示或暗示的担保。由于软件系统开发本身的复杂性，无法保证本项目完全没有错误。如选择使用本项目表示您同意错误和/或遗漏的存在，在任何情况下本项目对于直接、间接、特殊的、偶然的、或间接产生的、使用或无法使用本项目进行交易和投资造成的盈亏、直接或间接引起的赔偿、损失、债务或是任何交易中止均不承担责任和义务。

此声明永久有效