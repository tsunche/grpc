// Copyright 2022 gRPC authors.
//
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

#include <grpc/support/port_platform.h>

#include "src/core/lib/event_engine/shim.h"

#include "src/core/lib/experiments/experiments.h"
#include "src/core/lib/iomgr/port.h"

namespace grpc_event_engine {
namespace experimental {

bool UseEventEngineClient() {
// TODO(hork, eryu): Adjust the ifdefs accordingly when event engines become
// available for other platforms.
#if defined(GRPC_POSIX_SOCKET_TCP) and !defined(GRPC_CFSTREAM)
  return grpc_core::IsEventEngineClientEnabled();
#else
  return false;
#endif
}

bool UseEventEngineListener() {
// TODO(hork, eryu): Adjust the ifdefs accordingly when event engines become
// available for other platforms.
#if defined(GRPC_POSIX_SOCKET_TCP) and !defined(GRPC_CFSTREAM)
  return grpc_core::IsEventEngineListenerEnabled();
#else
  return false;
#endif
}

bool EventEngineSupportsFd() {
#if defined(GRPC_POSIX_SOCKET_TCP) and !defined(GRPC_CFSTREAM)
  return true;
#else
  return false;
#endif
}

}  // namespace experimental
}  // namespace grpc_event_engine
