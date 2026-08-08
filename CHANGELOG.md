# Changelog

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

