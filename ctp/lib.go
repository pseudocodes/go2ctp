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
#cgo linux LDFLAGS: -fPIC -L. -L${SRCDIR}/lib/v6.7.2_20230913_api_traderapi_se_linux64 -Wl,-rpath=${SRCDIR}/lib/v6.7.2_20230913_api_traderapi_se_linux64  -l:thostmduserapi_se.so -l:thosttraderapi_se.so -lstdc++
#cgo linux CXXFLAGS: -std=c++11
#cgo linux CPPFLAGS: -fPIC -I. -I${SRCDIR}/lib/v6.7.2_20230913_api_traderapi_se_linux64/

#cgo darwin LDFLAGS: -L. -F${SRCDIR}/lib/v6.7.2_MacOS_20231016 -framework thostmduserapi_se -framework thosttraderapi_se -Wl,-rpath,${SRCDIR}/lib/v6.7.2_MacOS_20231016
#cgo darwin CXXFLAGS: -std=c++11
#cgo darwin CPPFLAGS: -I. -I${SRCDIR}/lib/v6.7.2_MacOS_20231016/include/

*/
import "C"
