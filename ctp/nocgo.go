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

//go:build !cgo

package ctp

// 本包的全部实现 (wrap 层) 依赖 cgo。当 cgo 被禁用时 (CGO_ENABLED=0、
// PATH 中找不到 C/C++ 编译器、或交叉编译到无工具链的目标平台)，
// 含 `import "C"` 的文件会被整体排除，导致包内没有任何导出符号，
// 上层代码只能看到成片的 "undefined: ctp.CreateMdApi" 之类误导性报错。
// 本文件在 !cgo 时参与编译，用一个语义自明的未定义标识符把真实原因
// 变成一条编译期提示:
//
//	undefined: CgoRequired_PutGccOnPath_OrSetCGOENABLED1_SeeREADME
//
// 修复方法 (Windows 为例，详见 README FAQ A.04):
//   - 安装 MinGW-w64 (winlibs UCRT 或 MSYS2 ucrt64 toolchain)，把其 bin 目录加入 PATH
//     (cgo 自动检测只识别 PATH 中的 gcc，go env -w CC=<绝对路径> 不会触发自动启用)
//   - 或显式 CGO_ENABLED=1 并保证 CC/CXX 可用
var _ = CgoRequired_PutGccOnPath_OrSetCGOENABLED1_SeeREADME
