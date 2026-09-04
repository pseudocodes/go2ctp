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

#ifndef _DLFCN_WIN32_H_
#define _DLFCN_WIN32_H_

// dlopen/dlsym/dlclose/dlerror 的 Win32 兼容层。
//
// MinGW-w64 不提供 POSIX dlfcn.h, 此处以 LoadLibraryExW/GetProcAddress 实现。
// 注意:
//   * Go 侧传入的动态库路径为 UTF-8 编码且可能是相对路径, 需先转 UTF-16
//     并用 GetFullPathNameW 归一化为绝对路径 (LOAD_WITH_ALTERED_SEARCH_PATH
//     要求绝对路径, 同时保证被加载 dll 的依赖优先在其所在目录解析);
//   * 符号名使用 MSVC 修饰名 (如 ?CreateFtdcMdApi@CThostFtdcMdApi@@...),
//     与 dll 导出表一致, 由调用方按平台给出。

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

#define RTLD_NOW 0

static const char* dlerror(void)
{
    static char buf[128];
    sprintf(buf, "win32 loader error: %lu", GetLastError());
    return buf;
}

static void* dlopen(const char* filename, int flag)
{
    int wlen;
    WCHAR* wpath;
    WCHAR* wfull;
    DWORD n;
    HMODULE h;

    (void)flag;
    if (filename == NULL) {
        return NULL;
    }
    wlen = MultiByteToWideChar(CP_UTF8, 0, filename, -1, NULL, 0);
    if (wlen <= 0) {
        SetLastError((DWORD)wlen);
        return NULL;
    }
    wpath = (WCHAR*)malloc(sizeof(WCHAR) * (size_t)wlen);
    if (wpath == NULL) {
        return NULL;
    }
    MultiByteToWideChar(CP_UTF8, 0, filename, -1, wpath, wlen);

    n = GetFullPathNameW(wpath, 0, NULL, NULL);
    if (n == 0) {
        free(wpath);
        return NULL;
    }
    wfull = (WCHAR*)malloc(sizeof(WCHAR) * (size_t)n);
    if (wfull == NULL) {
        free(wpath);
        return NULL;
    }
    if (GetFullPathNameW(wpath, n, wfull, NULL) == 0) {
        free(wpath);
        free(wfull);
        return NULL;
    }
    h = LoadLibraryExW(wfull, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    free(wpath);
    free(wfull);
    return (void*)h;
}

static void* dlsym(void* handle, const char* name)
{
    return (void*)GetProcAddress((HMODULE)handle, name);
}

static int dlclose(void* handle)
{
    return FreeLibrary((HMODULE)handle) ? 0 : -1;
}

#endif // _DLFCN_WIN32_H_
