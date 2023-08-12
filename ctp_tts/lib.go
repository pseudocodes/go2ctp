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

package ctp_tts

/*
#cgo linux LDFLAGS: -fPIC -L. -L${SRCDIR}/lib/v6.6.9_20220920/lin64 -ldl -Wl,-rpath=${SRCDIR}/lib/v6.6.9_20220920/lin64
#cgo linux CPPFLAGS: -fPIC -I. -I${SRCDIR}/lib/v6.6.9_20220920/

#cgo darwin LDFLAGS: -L. -L${SRCDIR}/lib/v6.6.9_20220920/mac_arm64/ -ldl
#cgo darwin CPPFLAGS: -I. -I${SRCDIR}/lib/v6.6.9_20220920/

*/
import "C"
