# Changelog

## [Unreleased] - 2026-09-03

### Added

- 新增 Windows 平台支持 (windows/amd64，cgo + MinGW-w64，无需 WSL)
- 新增 Windows 平台 CTP SDK v6.7.13_20260225 (`ctp/lib/v6.7.13_20260225_api_traderapi_se_win64`)，含官方 MSVC 构建的 `thosttraderapi_se.dll` / `thostmduserapi_se.dll`；v6.7.13 起 Windows 与 Linux SDK 头文件逐 token 一致，编译期直接复用 linux 目录的 UTF-8 头文件，不冗余拷贝
- `ctp_dyn` 新增 `dlfcn_win32.h`：以 `LoadLibraryExW` / `GetProcAddress` 实现 `dlopen` / `dlsym` / `dlclose` / `dlerror` 兼容层，支持运行时加载官方/融航/OpenCTP-fts 等任意 Windows 路径的 CTP dll (含中文及相对路径)
- `ctp` / `ctp_dyn` 补充 `#cgo windows` 编译指令；sample 增加 Windows 动态库路径分支与前置地址环境变量覆盖 (`SIMNOW_TD_FRONT` / `SIMNOW_MD_FRONT`)
- `ctp` / `ctp_dyn` 新增 `nocgo.go` (`//go:build !cgo`)：cgo 被禁用 (无 C 工具链 / CGO_ENABLED=0 / 交叉编译) 时以单条显式编译报错 (`undefined: CgoRequired_...`) 取代成片误导性的 `undefined: ctp_dyn.CreateMdApi` 符号错误
- Windows 下编译产物使用 `-static`，仅依赖系统 UCRT，部署时只需 go 可执行文件 + ctp dll

### Changed

- Windows 下 `CreateFtdcMdApi` / `CreateFtdcTraderApi` 运行期以 MSVC 修饰名 (`?CreateFtdcMdApi@CThostFtdcMdApi@@SAPEAV1@PEBD_N1_N@Z` / `?CreateFtdcTraderApi@CThostFtdcTraderApi@@SAPEAV1@PEBD_N@Z`) 经 `GetProcAddress` 解析 (MinGW 的 Itanium 修饰名无法链接 MSVC import lib)，其余接口均为虚函数调用，无链接期符号依赖；`ctp` 包在 Windows 下要求 dll 与可执行文件同目录部署
- Windows 版 DLL 未导出静态成员 `GetApiVersion`，Windows 平台返回编译期版本号 `6.7.13` (Linux 返回 `v6.7.13_20260225 14:16:30.12079` 完整构建戳)
- 更新 README：平台支持表、FAQ A.04 (不再拒绝 Windows 支持)、Windows 编译与部署说明
- 仅支持 windows/amd64：32 位构建在编译期 `#error` 拒绝 (32 位 stdcall 修饰名与调用约定差异)

### comment

- 官方 Windows SDK 头文件与 Linux 版逐 token 一致 (结构体无 `long` 类型，LLP64/LP64 布局无差异)；CTP 的 Spi 类无虚析构函数、Api 类析构为非虚，MSVC 与 MinGW 的虚表槽位排布完全重合，MinGW 编译的 SPI 子类可被 MSVC 构建的 dll 直接经虚表回调 (实测 SimNow 7x24 登录/报单/行情全链路通过)
- 编译需要 MinGW-w64 工具链（任选一种发行版：winlibs x86_64-posix-seh-ucrt 或 MSYS2 `mingw-w64-ucrt-x86_64-toolchain`，两者 ABI 相同、可互换），`CGO_ENABLED=1` 即可，无其它构建要求

## [Unreleased] - 2026-08-08

### Added

- 新增 MacOS 平台 CTP SDK v6.7.13_MacOS_20260529 (`ctp/lib/v6.7.13_MacOS_20260529`)，framework 为 x86_64 + arm64 universal
- `ctp` package 恢复 `#cgo darwin` 静态链接配置，通过 `-F` / `-framework` / `-rpath` 绑定新版 framework
- `ctp_dyn` package 补充 `#cgo darwin` 头文件路径，默认与 `tts`/`openctp` 两种构建均可在 MacOS 下编译
- 新增 `.clang-format` 固定 wrap 代码风格 (等价 WebKit 预设)，并在 `ctp/lib/` 下以 `DisableFormat` 排除官方 SDK 头文件，避免编辑器 format-on-save 产生大规模无关重排

### Changed

- MacOS 版本 SDK 的 `ReqUserLogin` 自 v6.7.13 起已与 Linux 统一为两参数接口，移除 `ctp` / `ctp_dyn` 中 `#ifdef __APPLE__` 及 `runtime.GOOS == "darwin"` 的平台分支
  - wrap 层 `ReqUserLoginMac` 与 `TraderSystemInfo` 选项仅为兼容旧调用保留，`length` / `systemInfo` 不再传递给登录接口，穿透式信息请使用 `RegisterUserSystemInfo` / `SubmitUserSystemInfo`
- 修正 `ctp_dyn/lib_tts.go` 中仍指向已删除的 v6.7.11 目录的 linux 头文件路径
- 修正 `ctp_dyn` 动态库路径校验：扩展名比较缺少前导点，且 MacOS framework 二进制不带扩展名
- 更新 sample 中 MacOS 动态库路径至新版 framework
- 更新 README：版本号、平台库目录对照表、FAQ A.06 / A.07 / A.08

## [Unreleased] - 2026-04-03

### Changed

- 新增分支 6.7.13 对应官方 CTP 库版本 v6.7.13_20260225
- 同步更新 ctp 和 ctp_dyn 封装代码
- master 分支对应最新 CTP 版本

### Added

- 新增 TraderSpi 回调接口: OnRtnPrivateSeqNo, OnRspGenSMSCode, 套利确认系列 (OnRspSpdApply 等), 套保确认系列 (OnRspHedgeCfm 等)
- 新增 TraderApi 请求方法: ReqGenSMSCode, 套利确认系列 (ReqSpdApply 等), 套保确认系列 (ReqHedgeCfm 等)
- SubscribePrivateTopic 接口新增可选参数 nSeqNo，支持从指定序号开始重传私有流
- 新增枚举值 THOST_TERT_RESUME_FROM_SEQ_NO
- 新增数据类型: DeviceTagType, SMSCodeType, SMSContentType, SMSPhoneType, ApplyStatusType, CmbTypeType


## [Unreleased] - 2026-01-25
- 更新分支 6.7.11 更新封装代码
- master 分支对应最新 CTP 版本
- 更新 README 文档


## [Unreleased] - 2025-08-13
- 更新分支 6.7.11 对应官方 CTP 库版本
- 更新封装代码
- master 分支对应最新 CTP 版本
- 更新 README 文档


## [Unreleased] - 2024-09-13

### Changed

- 更新分支 6.7.7 对应官方 CTP 库版本
- 更新封装代码
- master 分支对应最新 CTP 版本
- 更新 README 文档

### comment
- 采用 libclang 重写了封装代码生成脚本
- 取消 ctp-mini golang 封装计划


## [Unreleased] - 2024-07-07

### Changed

- 更新分支 6.7.2 对应官方 CTP 版本
- 删除 ctp_cp 评测 package 目录，评测接入采用 ctp_dyn
- ctp_tts 更名为 ctp_dyn 
- master 分支对应最新 CTP 版本
- 更新 README 文档

### comment
- 为精简项目，除 CTP 头文件，非必要不再提供对应版本的库文件
- openctp 以及 CTP_CP 评测库请自行下载
- 推荐使用 ctp_dyn，不强制依赖库文件以及库文件路径，动态库可配置
- openctp 编译需添加参数，详见 FAQ


## [Unreleased] - 2024-04-05

### Changed

- Release 接口增加清空 RegisterSpi 操作
- 更新 README 文档


## [Unreleased] - 2024-03-11

### Changed

- 更新 README 文档，添加同类项目对比说明

## [Unreleased] - 2024-02-26

### Changed

- 修复某些 Linux 环境下 `uintptr_t` 在编译中无法识别的问题
- 调整 `linguist-language`


## [Unreleased] - 2024-01-29

### Changed

- TdApi 与 MdApi 接口定义文件移入 thost 目录, 各子目录对外接口统一
- 调整 Sample 样例代码

