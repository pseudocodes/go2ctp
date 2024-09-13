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

//go:build !(tts || openctp)

package ctp_dyn

/*
#cgo linux LDFLAGS: -fPIC -L. -L${SRCDIR}/../ctp/lib/v6.7.7_20240607_api_traderapi_se_linux64 -ldl
#cgo linux CXXFLAGS: -std=c++11
#cgo linux CPPFLAGS: -fPIC -I. -I${SRCDIR}/../ctp/lib/v6.7.7_20240607_api_traderapi_se_linux64

#cgo darwin LDFLAGS: -L. -L${SRCDIR}/../ctp/lib/v6.7.7_MacOS_20240716/ -ldl
#cgo darwin CXXFLAGS: -std=c++11
#cgo darwin CPPFLAGS: -I. -I${SRCDIR}/../ctp/lib/v6.7.7_MacOS_20240716/include

*/
import "C"
