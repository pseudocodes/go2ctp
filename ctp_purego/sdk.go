//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"sync"

	"github.com/ebitengine/purego"
)

type sdkOptions struct {
	dllPath, flowPath string
	production        bool
}

// Match the SDK's flow path convention: a trailing separator denotes a directory;
// otherwise the last component is a file prefix.
func (o sdkOptions) prepareFlowPath() {
	if strings.IndexByte(o.flowPath, 0) >= 0 {
		panic("ctp_purego: NUL in flow path")
	}
	if o.flowPath != "" {
		if err := os.MkdirAll(filepath.Dir(o.flowPath), os.ModePerm); err != nil {
			panic(err)
		}
	}
}

type sdkSession[O, S any] struct {
	obj         *O
	spi         *S
	version     string
	library     uintptr
	freeSPI     func()
	releaseOnce sync.Once
}

func (s *sdkSession[O, S]) open(opts sdkOptions, factoryName, versionName string, initialize func(*S), create func(uintptr) *O) {
	if opts.dllPath == "" {
		panic("ctp_purego: SDK library path is required (MdDynamicLibPath or TraderDynamicLibPath)")
	}
	path, err := filepath.Abs(opts.dllPath)
	if err != nil {
		panic(err)
	}
	lib, err := loadLibrary(path)
	if err != nil {
		panic(fmt.Errorf("load %s: %w", path, err))
	}
	// Unwind partial construction when symbol lookup or version checks fail.
	defer func() {
		if s.obj == nil {
			if s.freeSPI != nil {
				s.freeSPI()
			}
			closeLibrary(lib)
		}
	}()
	lookup := func(name string) uintptr {
		addr, err := findSymbol(lib, name)
		if err != nil {
			panic(fmt.Errorf("find %s in %s: %w", name, path, err))
		}
		return addr
	}
	var version func() string
	purego.RegisterFunc(&version, lookup(versionName))
	s.version = version()
	release, _, _ := strings.Cut(strings.TrimPrefix(s.version, "v"), "_")
	if release != "6.7.13" {
		panic(fmt.Errorf("ctp_purego: unsupported SDK %q (want 6.7.13)", s.version))
	}
	factory := lookup(factoryName)
	opts.prepareFlowPath()
	s.spi, s.freeSPI, err = allocSPI[S]()
	if err != nil {
		panic(err)
	}
	initialize(s.spi)
	s.obj = create(factory)
	if s.obj == nil {
		panic(fmt.Errorf("CTP factory %s returned nil", factoryName))
	}
	s.library = lib
}

func (s *sdkSession[O, S]) GetApiVersion() string { return s.version }

// Release on the owner goroutine after other API calls finish. SDK release joins its callback threads.
func (s *sdkSession[O, S]) close(detach func(*O, *S), release func(*O)) {
	s.releaseOnce.Do(func() {
		receivers.Delete(s.spi)
		detach(s.obj, nil)
		release(s.obj)
		s.freeSPI()
		closeLibrary(s.library)
		s.obj = nil
		s.spi = nil
	})
}
