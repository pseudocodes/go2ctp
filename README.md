# Go2ctp

上海期货信息技术 CTP 接口 go 语言原生封装，支持生产，测评，OpenCTP, LocalCTP 版本, 适配 Linux, MacOS, Windows

对应 Rust 语言封装查看 **[Ctp2rs](https://github.com/pseudocodes/ctp2rs/)** 项目

当前主分支对应 CTP 版本为 `v6.7.13`

| 平台    | 库目录                                              | 说明                                                                                    |
| ------- | --------------------------------------------------- | --------------------------------------------------------------------------------------- |
| Linux   | `ctp/lib/v6.7.13_20260225_api_traderapi_se_linux64` | `thosttraderapi_se.so` / `thostmduserapi_se.so`                                         |
| MacOS   | `ctp/lib/v6.7.13_MacOS_20260529`                    | `thosttraderapi_se.framework` / `thostmduserapi_se.framework`，x86_64 + arm64 universal |
| Windows | `ctp/lib/v6.7.13_20260225_api_traderapi_se_win64`   | `thosttraderapi_se.dll` / `thostmduserapi_se.dll`，amd64 (仅 64 位)                     |

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
		CTPLibPathWindows = "C:\\the\\user\\path\\to\\thostmduserapi_se.dll"
		TTSLibPathMacos = "/the/user/path/to/openctp/thostmduserapi_se.dylib"
	)
	if runtime.GOOS == "darwin" {
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(CTPLibPathMacos), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		frontAddr = SimnowFront
	} else if runtime.GOOS == "linux" {
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(CTPLibPathLinux), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
		frontAddr = SimnowFront
	} else if runtime.GOOS == "windows" {
		mdapi = ctp_dyn.CreateMdApi(ctp_dyn.MdDynamicLibPath(CTPLibPathWindows), ctp_dyn.MdFlowPath("./data/"), ctp_dyn.MdUsingUDP(false), ctp_dyn.MdMultiCast(false))
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

**Q.04**: Windows 平台如何编译与部署

**A.04**: 自 v6.7.13 起本项目原生支持 Windows (windows/amd64)，无需 WSL。要点如下
> * **编译工具链**: cgo + **MinGW-w64 工具链（任选一种发行版：winlibs 或 MSYS2 UCRT64）**，无需安装 Visual Studio / MSVC
>   * **MinGW-w64 与 WinLibs 的关系**: [MinGW-w64](https://www.mingw-w64.org/) 是工程/运行时本身（Windows 头文件 + UCRT + libstdc++ 移植 + 导入库），官方只发布源码；[WinLibs](https://winlibs.com/)、MSYS2、scoop/choco 等都是对它的**打包分发**，ABI 相同、产物可互换。[官网下载页](https://www.mingw-w64.org/downloads/) 的 "Pre-built toolchains" 列出 Arch Linux / Fedora / Debian / Cygwin 等众多平台，是因为同一工具链存在两种宿主形态：**Linux/macOS 上的交叉编译器**（如 `x86_64-w64-mingw32-g++`，在 Linux/CI 上编出 Windows exe，本项目 WSL 交叉编译走的就是这条路径）与 **Windows 原生工具链**（本机 go build 需要此类，对应 WinLibs / MSYS2 条目）。本项目 Windows 本机编译推荐 WinLibs：
>     * 下载选择（winlibs.com Download 一节，**不要**用页面顶部 "don't know" 快捷链接，那是 MSVCRT 版）：**UCRT runtime → 最新 "GCC x.x.x (POSIX threads) + MinGW-w64 x.x.x (UCRT)" → Win64 → Zip archive**，文件名形如 `winlibs-x86_64-posix-seh-gcc-16.2.0-mingw-w64ucrt-14.0.0-r1.zip`（要点：UCRT 而非 MSVCRT、x86_64 而非 i686、posix 线程而非 mcf/win32、不带 LLVM 的精简版）
>     * 安装：zip 顶层自带 `mingw64` 目录，解压到目标位置（如 `C:\myapp`）得到 `C:\myapp\mingw64\bin\g++.exe` 即可
>     * MSYS2：`pacman -S mingw-w64-ucrt-x86_64-toolchain`，滚动更新、生态庞大 (cmake/ninja/各库)，适合长期 Windows 开发环境
>     * 名称字段含义：`ucrt` = 链接 Win10+ 系统 Universal C Runtime；`posix` = 线程模型（std::thread 完整支持）；`seh` = x64 异常展开模型（64 位下唯一选择，dwarf/mcf 只属于 32 位）
> * **环境搭建 (一次性)**: 将工具链 `bin` 目录（注意必须含 `\bin`）加入 PATH 并**重开终端**，cgo 即自动启用；`where gcc` 能找到即配置成功。也可不依赖 PATH，用绝对路径固化：`go env -w CGO_ENABLED=1 CC=<安装目录>\bin\gcc.exe CXX=<安装目录>\bin\g++.exe`；两者任选，若日后迁移/更换工具链安装位置，记得同步更新 `go env -w CC=… CXX=…`（或删除恢复自动检测：`go env -u CC CXX`）
> * **报 `undefined: ctp_dyn.CreateMdApi` / `undefined: ctp.CreateTraderApi` 等成片符号不存在**：说明 cgo 被禁用，`ctp` / `ctp_dyn` 包中含 `import "C"` 的实现文件全部被排除、包成了空壳。根因几乎都是 gcc 不在 PATH (`go env CGO_ENABLED` 解析为 0)。注意 **cgo 的自动检测只识别 PATH 中的 `gcc`，`go env -w CC=<绝对路径>` 不会触发自动启用**。本项目已内置 `!cgo` 提示文件，禁用 cgo 构建时会直接报 `undefined: CgoRequired_PutGccOnPath_OrSetCGOENABLED1_SeeREADME`，按上述方法配置即可
> * **编译**: gcc 在 PATH 后正常 `go build` 即可（`CGO_ENABLED=1`，Windows amd64 检测到 gcc 后默认开启）；仅支持 64 位，32 位 (GOARCH=386) 编译期报错；构建整个 sample 建议用包路径形式 `go build ./sample/simple_market`
> * **ABI 说明**: 官方 Windows CTP dll 由 MSVC 构建。CTP 的 Spi 类没有声明虚析构函数、Api 类析构为非虚，且 Windows 与 Linux SDK 头文件逐 token 一致（结构体无 `long` 类型），因此 MinGW 编译的 SPI 子类与虚表调用和 MSVC dll 的槽位排布完全兼容；唯一例外是 `CreateFtdcMdApi` / `CreateFtdcTraderApi` 这类**静态成员函数**（Itanium 与 MSVC 修饰名不同，无法链接），本项目在 Windows 下改为运行期 `LoadLibrary` + `GetProcAddress`（MSVC 修饰名）解析
> * **`ctp` 包部署**: 生成的可执行文件需与 `thosttraderapi_se.dll` / `thostmduserapi_se.dll`（位于 `ctp/lib/v6.7.13_20260225_api_traderapi_se_win64`）**同目录**放置（Windows 无 rpath，运行期按模块名在应用目录查找）
> * **`ctp_dyn` 包部署**: 与 Linux/MacOS 一致，用户以路径显式传入 dll，路径可含中文（内部按 UTF-8 → UTF-16 转换后 `LoadLibraryExW` 加载）
> * **`GetApiVersion()`**: Windows 版 dll 未导出该静态函数，Windows 平台返回编译期版本号 `6.7.13`（Linux 返回带构建戳的完整版本串），如需以运行期实际加载库为准（如 OpenCTP-fts 换库）请注意该差异
> * **exe 依赖**: 编译已带 `-static -static-libgcc -static-libstdc++`，产物仅依赖系统 UCRT，无需随带 mingw 的 dll；CTP dll 自身仅依赖系统库，无需 VC++ 运行库

**Q.05**: ctp 目录和 ctp_dyn 目录的封装有什么不同

**A.05**: 
> * ctp 的封装来自 [*pseudocodes/goctp*](https://github.com/pseudocodes/goctp), 剔除了 *lite* 和 *convert* 相关代码，原则上只提供一层封装，直接桥接 cgo 空间回调过来的数据
> * ctp 目录属于静态编译链接，其他项目采用该目录下的代码，依赖的动态库的路径会在编译构建期完成初始绑定，默认路径为 go2ctp 库的存放路径，只部署二进制程序在 Linux 环境需要设置 LD_LIBRARY_PATH 环境变量来提供依赖的 ctp 动态库路径; MacOS 环境一般不用再独立设置 `@rpath`，推荐 MacOS 环境采用 ctp_dyn 依赖; Windows 环境由于 dll 无法使用 rpath，`ctp` 包改为运行期按模块名加载，将官方 dll 与可执行文件同目录部署即可
> * ctp_dyn 封装方式采用了读取动态库符号的方式，通过在运行时提供动态库的路径，完成 API 实例对象的生成和绑定，理论上 ctp_dyn 的封装方式更灵活方便，可以通过配置的方式动态的替换 linux 下不同平台的库，包括官方生产和测评版本，rohan(融航)，openctp-tts 平台，无需再编译项目代码. ctp_dyn 同时支持 openctp 的 MacOS 版本 dylib 与 Windows 版本 dll
> * ctp_dyn 使用需要用户明确提供动态库地址，部署时需要动态库与二进制程序一起部署
>

**Q.06**: MacOS 环境下上期 CTP 编译运行问题

**A.06**: 相关信息如下
> *	官方从 CTP 6.7.0 版本开始提供 `.framework` 的动态库，而不像 OpenCTP 那样采用 `.dylib` 来提供支持
> *	官方打包发布的 `framework` 包可能有设置问题，包中软连接变成文本文件，如果直接引入该 `framework` 至 `Xcode` 项目会造成无法编译；本项目内置的 `v6.7.13_MacOS_20260529` 包中软连接正常，无需额外处理
> * `framework` 静态编译时就需要设定 `@rpath` 路径，运行二进制文件时才能获得动态库的路径，在这种场景下，更合适的方式还是采用动态库 `dlopen` 方式, 
> * MacOS 命令行下可以直接编译源代码程序并链接 `framework`，首次运行启动之后请到`系统设置->隐私与安全性->安全性` 标签中对 `thostmduserapi_se` 以及 `thosttraderapi_se` 这两个文件进行信任允许操作

**Q.07**: OpenCTP 与上期 CTP 在 MacOS 环境的区别

**A.07**: 相关信息如下
> * **自 `v6.7.13` 起该差异已不存在**：官方 MacOS 版本 SDK 的 `ReqUserLogin` 已与 Linux 统一为两参数接口，穿透式认证的终端信息统一通过 `RegisterUserSystemInfo` / `SubmitUserSystemInfo` 上报。因此本项目 `v6.7.13` 分支不再对 `ReqUserLogin` 做平台分支处理，`ctp.TraderSystemInfo` / `ctp_dyn.TraderSystemInfo` 选项以及 wrap 层的 `ReqUserLoginMac` 仅为兼容旧调用保留，实际不再向登录接口传递 `length` / `systemInfo`
> * `v6.7.13` 之前的历史差异说明：上期 CTP MacOS 环境与 Linux 环境的区别主要在于 `CThostFtdcTraderApi` 中的 `ReqUserLogin` 接口参数不同, MacOS 对应接口比 Linux 多了两个穿透式信息的参数
```cpp
// Linux 接口
virtual int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) = 0;

// MacOS 接口 (v6.7.13 之前)
virtual int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID, TThostFtdcSystemInfoLenType length, TThostFtdcClientSystemInfoType systemInfo) = 0;
```
> * OpenCTP 提供的 MacOS 的头文件接口一直与 Linux 统一，即 `ReqUserLogin` 采用两参数接口，封装 `go2ctp` 过程中与 [@krenx](https://github.com/krenx1983) 沟通过这个问题，对方当时未有计划提供对标接口支持; 现在两者接口已一致，但 OpenCTP 在 MacOS 下提供的是 `.dylib` 而非 `.framework`，静态链接的 ctp package 绑定的是官方 `framework`，因此 MacOS 环境下使用 OpenCTP 库时仍请采用 ctp_dyn package，编译指令如下 

```shell
?> cd sample/simple_trader && go build -tags openctp

# 或者
?> cd sample/simple_trader && go build -tags tts
```

**Q.08**: ctp_dyn 高版本的封装(6.7.7) 是否兼容低版本 (6.7.2) 的动态库

**A.08**: 相关信息 
* CTP `v6.7.7` 版本在 `RegisterFront` 增加了新方法，破坏了 `v6.7.2` 版本之前的类方法的内存布局排序, 因此 `v6.7.7` 的封装不兼容 `v6.7.2`
* 实测 linux 环境中 `v6.7.2` 封装文件能支持 CTP 动态库版本到 `v6.5.1`, 高版本的 API 无法在低版本动态库调用时使用
*  `6.7.7` 分支 `ctp_dyn` 不兼容 `6.7.2` 版本的 ctp/openctp 的动态库, 如果高版本封装加载了低版本动态库，程序编译运行之后会发生卡死或提示出错； 
* `6.7.11` 分支 `ctp_dyn` 不兼容之前任何版本；
* `6.7.13` 分支 `ctp_dyn` 不兼容之前任何版本，该版本新增了多个虚函数并调整了 `SubscribePrivateTopic` 的参数，类方法内存布局与 `6.7.11` 不同；MacOS 与 Linux 的封装代码自该版本起完全一致；
* 存在能够强制加载低版本动态库函数的封装方案，但是考虑到生产环境下应不隐藏风险，尽早抛出错误的原则，未采用强制加载的封装方案.
* 此外，请注意开发环境的区别，不要在 MacOS 环境下加载 so 动态库


## 注意事项
* 使用 ctp_dyn 时请对齐分支版本以及动态库版本
* MacOS 环境下如出现编译后运行无响应，可以排查系统以及 Go 版本
* Windows 环境仅支持 windows/amd64 (32 位编译期报错)，编译需 MinGW-w64 工具链 (详见 FAQ A.04)；`ctp` 包部署时 dll 必须与可执行文件同目录，`ctp_dyn` 包按路径显式传入 dll
* Windows 下 `GetApiVersion()` 返回编译期版本号 `6.7.13` (官方 Windows dll 未导出该静态函数)，与 Linux 返回的完整构建戳存在差异

 
## 同类项目

| 项目地址                                                                                                                   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | 推荐指数 |
| -------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------- |
| https://github.com/gaxxx/ctp                                                                                               | 最早 golang 版本的 ctp 封装，作者发布在水木论坛，在这个项目中 <br> 可以观察到 go 早期版本的封装编译指令                                                                                                                                                                                                                                                                                                                                                                                        | ☆☆☆☆☆    |
| https://github.com/pseudocodes/goctp                                                                                       | 含 DataCollect 封装支持，提供 go 类型结构的 convert 转换方法                                                                                                                                                                                                                                                                                                                                                                                                                                   | ★★★★☆    |
| https://github.com/haifengat/goctp <br> [https://gitee.com/haifengat/goctp/v2](https://gitee.com/haifengat/goctp/tree/v2/) | 描述见 FAQ.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | ★★★★☆    |
| https://github.com/hankchan/goctp                                                                                          | 描述见 FAQ.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | ★★★☆☆    |
| https://github.com/mayiweb/goctp                                                                                           | 源自 https://github.com/hankchan/goctp                                                                                                                                                                                                                                                                                                                                                                                                                                                         | ★★★☆☆    |
| https://github.com/kkqy/ctp-go                                                                                             | a. 对 CTP 的版本处理与 `A.01` 中的描述相同，不同版本放置于不同分支下 <br> b. 该项目将 Swig 编译后展开的代码直接放置于项目中，有 FAQ 中 `A.02` 中描述的问题，该项目文档也说明了编译速度慢的问题 <br> c. CTP 结构体创建在 c 内存空间侧，需要手动自行回收                                                                                                                                                                                                                                         | ★★☆☆☆    |
| https://github.com/ztrade/ctp                                                                                              | a. 项目整体布局类似 https://github.com/pseudocodes/goctp, 细节在于 wrapper 代码中将 Api 和 Spi 的 C++ 类分别进行了独立封装，与 SWIG 的展开代码类似 <br> b. 调用 Api 接口时 C 内存空间侧申请一次内存并拷贝结构体数据，Spi 回调侧 go 内存空间侧申请一次内存并拷贝结构体，相较本项目整体多了两次内存申请以及数据深拷贝                                                                                                                                                                            | ★★★★☆    |
| https://github.com/etveritas/ctp-wrapper/                                                                                  | a. 采用了与 [ftdc2_ctp](https://github.com/shawn666liu/ftdc2c_ctp) 类似的方案，先用一层封装代码将 C++ 接口暴露为纯 C 接口，然后基于 C 接口的封装库实现 Go/Python 的进一步 FFI 封装;<br> b. go FFI 封装思路类似 `go2ctp/ctp_dyn` 但未采用 cgo 进行代码桥接，而是采用了 `purego` 库将 API 以及 SPI 回调函数与 c 库符号一一注册绑定的形式来实现虚表映射，将 cgo 封装代码的工作推到了 c 库构建的代码中, <br> c. 项目适合开发者 DIY 构建其他语言的 CTP FFI 项目, 项目布局不适合作为 go 的稳定库引用 | ★★★★☆    |


## Base on `go2ctp`
* https://github.com/pseudocodes/goctp_l3_estimate
  *  订单簿可视化展示
* https://github.com/pseudocodes/light-trader
* https://github.com/pseudocodes/open-md-gateway-go
	* 高性能期货行情数据网关，兼容 [`DIFF`](https://doc.shinnytech.com/diff/latest/general.html) 协议 
* https://github.com/pseudocodes/datacollect
    * CTP 客户端系统信息采集库封装 
* alpha-trade-gateway (incoming)


## TODO
* 更丰富的使用样例
* 扩展封装，提供高阶功能


## Reference
 【1】[*github.com/pseudocodes/goctp*](https://github.com/pseudocodes/goctp)   

 【2】[*github.com/haifengat/goctp*](https://github.com/haifengat/goctp)

 【3】[*github.com/hankchan/goctp*](https://github.com/hankchan/goctp) 

## 免责声明
本项目明确拒绝对产品做任何明示或暗示的担保。由于软件系统开发本身的复杂性，无法保证本项目完全没有错误。如选择使用本项目表示您同意错误和/或遗漏的存在，在任何情况下本项目对于直接、间接、特殊的、偶然的、或间接产生的、使用或无法使用本项目进行交易和投资造成的盈亏、直接或间接引起的赔偿、损失、债务或是任何交易中止均不承担责任和义务。
