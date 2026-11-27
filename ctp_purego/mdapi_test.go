//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"testing"

	"github.com/pseudocodes/go2ctp/thost"
)

func TestSDK(t *testing.T) {
	path := os.Getenv("CTP_MD_LIBRARY")
	if path == "" {
		t.Skip("set CTP_MD_LIBRARY to the 6.7.13 SDK library")
	}
	api := CreateMdApi(MdDynamicLibPath(path), MdFlowPath(t.TempDir()+string(os.PathSeparator)))
	defer api.Release()
	t.Logf("SDK version %q", api.GetApiVersion())
	api.RegisterSpi(BaseMdSpi{})
	api.RegisterFront("tcp://127.0.0.1:1")
	api.Init()
	api.Release()
}

func TestLibraryPathIsRequired(t *testing.T) {
	missing := filepath.Join(t.TempDir(), "missing_api_sm.so")
	for _, tc := range []struct {
		name   string
		want   string
		create func()
	}{
		{"market/omitted", "library path is required", func() { CreateMdApi() }},
		{"trader/empty", "library path is required", func() { CreateTraderApi(TraderDynamicLibPath("")) }},
		{"market/missing", missing, func() { CreateMdApi(MdDynamicLibPath(missing)) }},
		{"trader/missing", missing, func() { CreateTraderApi(TraderDynamicLibPath(missing)) }},
	} {
		t.Run(tc.name, func(t *testing.T) {
			defer func() {
				if got := recover(); got == nil || !strings.Contains(fmt.Sprint(got), tc.want) {
					t.Fatalf("panic = %v, want %q", got, tc.want)
				}
			}()
			tc.create()
		})
	}
}

var _ thost.MdSpi = BaseMdSpi{}
