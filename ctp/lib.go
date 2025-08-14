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

package ctp

/*
#cgo linux LDFLAGS: -fPIC -L. -L${SRCDIR}/lib/v6.7.11_20250617_api_traderapi_se_linux64 -Wl,-rpath=${SRCDIR}/lib/v6.7.11_20250617_api_traderapi_se_linux64 -l:thostmduserapi_se.so -l:thosttraderapi_se.so -lstdc++
#cgo linux CXXFLAGS: -std=c++11
#cgo linux CPPFLAGS: -fPIC -I. -I${SRCDIR}/lib/v6.7.11_20250617_api_traderapi_se_linux64/
*/
import "C"
import (
	"github.com/pseudocodes/go2ctp/thost"
)

const (
	defaultFlowPath         = ""
	defaultIsUsingUdp       = false
	defaultIsMulticast      = false
	defaultIsProductionMode = true
)

type MdOption func(api *MdApi)

func MdFlowPath(path string) MdOption {
	return func(api *MdApi) {
		api.flowPath = path
	}
}

func MdUsingUDP(usingudp bool) MdOption {
	return func(api *MdApi) {
		api.usingUDP = usingudp
	}
}

func MdMultiCast(multicast bool) MdOption {
	return func(api *MdApi) {
		api.multicast = multicast
	}
}

func MdProductionMode(production bool) MdOption {
	return func(api *MdApi) {
		api.production = production
	}
}

type MdApi struct {
	apiPtr uintptr
	spi    thost.MdSpi

	flowPath   string
	usingUDP   bool
	multicast  bool
	production bool
}

type TraderOption func(api *TraderApi)

func TraderFlowPath(path string) TraderOption {
	return func(api *TraderApi) {
		api.flowPath = path
	}
}

func TraderSystemInfo(systemInfo []byte, length int) TraderOption {
	return func(api *TraderApi) {
		api.length = length
		copy(api.systemInfo[:], systemInfo)
	}
}

func TraderProductionMode(production bool) TraderOption {
	return func(api *TraderApi) {
		api.production = production
	}
}

type TraderApi struct {
	apiPtr uintptr
	spi    thost.TraderSpi

	length     int
	systemInfo [273]byte

	flowPath   string
	production bool
}
