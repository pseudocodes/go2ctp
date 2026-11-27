//go:build (linux && amd64) || (darwin && (amd64 || arm64))

package ctp_purego

import (
	"unsafe"

	"github.com/ebitengine/purego"
	"golang.org/x/sys/unix"
)

const mdFactoryName = "_ZN15CThostFtdcMdApi15CreateFtdcMdApiEPKcbbb"
const mdVersionName = "_ZN15CThostFtdcMdApi13GetApiVersionEv"

const traderFactoryName = "_ZN19CThostFtdcTraderApi19CreateFtdcTraderApiEPKcb"
const traderVersionName = "_ZN19CThostFtdcTraderApi13GetApiVersionEv"

func loadLibrary(path string) (uintptr, error) {
	return purego.Dlopen(path, purego.RTLD_NOW|purego.RTLD_LOCAL)
}

func findSymbol(lib uintptr, name string) (uintptr, error) { return purego.Dlsym(lib, name) }

func closeLibrary(lib uintptr) error { return purego.Dlclose(lib) }

func allocSPI[S any]() (*S, func(), error) {
	buf, err := unix.Mmap(-1, 0, int(unsafe.Sizeof(*new(S))), unix.PROT_READ|unix.PROT_WRITE, unix.MAP_ANON|unix.MAP_PRIVATE)
	if err != nil {
		return nil, nil, err
	}
	return (*S)(unsafe.Pointer(&buf[0])), func() { _ = unix.Munmap(buf) }, nil
}
