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

#ifndef _API_VERSION_H_
#define _API_VERSION_H_

// CTP_SE_API_VERSION: 本仓库封装对应的 CTP API 版本号，全仓库唯一来源。
// 与 ctp/lib/v6.7.13_20260225_api_traderapi_se_* 版本目录保持一致，升级 CTP 库时需同步修改。
//
// 仅 Windows 平台使用：官方 MSVC 构建的 dll 未导出静态成员 GetApiVersion，
// 也不带 VS_VERSION_INFO 资源，运行期无从查询，故 GetApiVersion() 以该编译期值兜底；
// Linux/macOS 的 GetApiVersion() 走库内真实接口 (如 "v6.7.13_20260225 14:16:30.12079")。
#define CTP_SE_API_VERSION "6.7.13"

#endif // _API_VERSION_H_
