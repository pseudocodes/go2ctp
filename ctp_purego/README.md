# 无 cgo 的 CTP 行情与交易接口

`ctp_purego` 为官方 CTP 6.7.13 提供 `thost.MdApi` 和 `thost.TraderApi`。构造函数和 option 名称与 `ctp_dyn` 一致，动态加载行情库和交易库时分别指定各自的路径。

```go
md := ctp_purego.CreateMdApi(
    ctp_purego.MdDynamicLibPath(mdLibrary),
    ctp_purego.MdFlowPath(mdFlow),
)
defer md.Release()
md.RegisterSpi(mdSpi)
md.RegisterFront(mdFront)
md.Init()
```

```go
td := ctp_purego.CreateTraderApi(
    ctp_purego.TraderDynamicLibPath(traderLibrary),
    ctp_purego.TraderFlowPath(traderFlow),
)
defer td.Release()
td.RegisterSpi(traderSpi)
td.SubscribePrivateTopic(thost.THOST_TERT_QUICK)
td.SubscribePublicTopic(thost.THOST_TERT_QUICK)
td.RegisterFront(traderFront)
td.Init()
// 从 OnFrontConnected 发起柜台要求的认证或登录。
```

默认使用生产模式。流文件路径末尾带分隔符时会创建对应目录，否则最后一段作为文件前缀。调用方必须通过 `MdDynamicLibPath` 或 `TraderDynamicLibPath` 指定实际库文件；相对路径从当前工作目录解析。文件可以使用 SDK 提供的名称（如 `*_api_sm.so` 或 `*_api_sm.dll`）。路径为空、库加载失败、SDK 版本不匹配或工厂初始化失败都会触发 panic。

可以复用已有的 `thost.MdSpi` 和 `thost.TraderSpi` 实现，也可以嵌入 `BaseMdSpi` 或 `BaseTraderSpi` 后覆盖关注的方法。SDK 拥有回调参数指向的内存，跨回调保留数据时请先复制。结束其他 API 调用后，从业务 goroutine 调用 `Release`；在回调线程内释放可能导致 SDK 等待自身退出。

交易绑定按 6.7.13 头文件覆盖 140 个虚方法、178 个原生回调。和 `ctp_dyn` 一样，`SubscribePrivateTopic` 的序号默认为 1，`TraderSystemInfo` 和 `ReqUserLogin` 的可变参数为旧代码保留；该版 SDK 通过 `RegisterUserSystemInfo`、`SubmitUserSystemInfo` 上报终端信息。

## 运行行情示例

从仓库根目录进入示例目录，再编译、运行：

```sh
cd sample/purego_market
CGO_ENABLED=0 go build -o purego_market .
./purego_market -front "tcp://182.254.243.31:40011" rb2701 ag2701
```

示例按当前 SimNow 配置读取 `SIMNOW_USER_0`、`SIMNOW_PASS_0`，登录成功后订阅命令行指定的合约。使用 `-lib` 或 `CTP_MD_LIBRARY` 可以覆盖默认行情库路径，按 Ctrl+C 退出。

## 运行交易示例

沿用行情示例的 `SIMNOW_USER_0` 和 `SIMNOW_PASS_0`。从仓库根目录进入示例目录：

```sh
cd sample/purego_trader
CGO_ENABLED=0 go build -o purego_trader .
./purego_trader
```

默认交易前置为 `tcp://182.254.243.31:40001`，BrokerID 为 `9999`，使用 SimNow 测试 AppID 和授权码。示例认证、登录后查询资金账户；可按行情示例的命令行格式追加合约，逐个查询合约信息：

```sh
./purego_trader -front "tcp://182.254.243.31:40001" rb2701 ag2701
```

使用 `-front` 或 `CTP_TRADER_FRONT` 可覆盖前置，`-lib` 或 `CTP_TRADER_LIBRARY` 可覆盖交易库路径。重连后会重新认证、登录并查询，按 Ctrl+C 退出。

## 验证绑定

从仓库根目录运行：

```sh
CGO_ENABLED=0 go test -count=1 -v ./ctp_purego
```

有 C++ 编译器时，测试会编译独立 SDK 替身，检查虚表槽位、请求参数、原生线程回调和多实例分发。Windows 的替身使用 MSVC 开发者终端。设置 `CTP_MD_LIBRARY` 和 `CTP_TRADER_LIBRARY` 为官方行情库和交易库的绝对路径，可同时运行本机回环验证，无需账号。

修改 SDK 头文件后，在仓库根目录执行 `go generate ./ctp_purego` 可重新生成交易绑定。生成器需要 Python 3，并核对 Linux 和 macOS 头文件的方法顺序及签名。
