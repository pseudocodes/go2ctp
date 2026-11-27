//go:build windows && amd64

package ctp_purego

import (
	"errors"
	"unsafe"

	"github.com/ebitengine/purego"
	"golang.org/x/sys/windows"
)

const mdFactoryName = "?CreateFtdcMdApi@CThostFtdcMdApi@@SAPEAV1@PEBD_N1_N@Z"
const mdVersionName = "?GetApiVersion@CThostFtdcMdApi@@SAPEBDXZ"

const traderFactoryName = "?CreateFtdcTraderApi@CThostFtdcTraderApi@@SAPEAV1@PEBD_N@Z"
const traderVersionName = "?GetApiVersion@CThostFtdcTraderApi@@SAPEBDXZ"

func loadLibrary(path string) (uintptr, error) {
	h, err := windows.LoadLibraryEx(path, 0, windows.LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR|windows.LOAD_LIBRARY_SEARCH_DEFAULT_DIRS)
	return uintptr(h), err
}

func findSymbol(lib uintptr, name string) (uintptr, error) {
	return windows.GetProcAddress(windows.Handle(lib), name)
}

func closeLibrary(lib uintptr) error { return windows.FreeLibrary(windows.Handle(lib)) }

var virtualAlloc = windows.NewLazySystemDLL("kernel32.dll").NewProc("VirtualAlloc")

func allocSPI[S any]() (*S, func(), error) {
	var allocate func(uintptr, uintptr, uint32, uint32) *S
	purego.RegisterFunc(&allocate, virtualAlloc.Addr())
	spi := allocate(0, unsafe.Sizeof(*new(S)), windows.MEM_RESERVE|windows.MEM_COMMIT, windows.PAGE_READWRITE)
	if spi == nil {
		return nil, nil, errors.New("VirtualAlloc failed for CTP SPI")
	}
	return spi, func() { _ = windows.VirtualFree(uintptr(unsafe.Pointer(spi)), 0, windows.MEM_RELEASE) }, nil
}
