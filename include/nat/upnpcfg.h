/* Copyright (c) 2009 maidsafe.net limited
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    * Neither the name of the maidsafe.net limited nor the names of its
    contributors may be used to endorse or promote products derived from this
    software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <boost/function.hpp>
#include <string>
#include <map>

namespace upnp {

const int kSearchTime = 2;
const int kLeaseDuration = 900;
const int kRefreshThreshold = 10;
const char kClientName[] = "libsss-nat-upnp";

enum ProtocolType {
  kUdp = 0,
  kTcp = 1
};

// params: port, protocol
typedef boost::function<void(const int&, const ProtocolType&)> upnp_callback;

struct PortMapping {
  PortMapping(const int &port, const ProtocolType &protocol_)
    : internal_port(port)
    , external_port(port)
    , protocol(protocol_)
    , enabled(false)
    , last_refresh()
  {}

  PortMapping(int in_port, int out_port, const ProtocolType &protocol_)
    : internal_port(in_port)
    , external_port(out_port)
    , protocol(protocol_)
    , enabled(false)
    , last_refresh()
  {}

  int internal_port;
  int external_port;
  ProtocolType protocol;
  bool enabled;
  std::map<std::string, boost::uint32_t> last_refresh;
};

struct PortMappingExt : public PortMapping
{
  std::string internal_host;
  std::string external_host;
  std::string description;
  int duration{kLeaseDuration};

  PortMappingExt(const int &port, const ProtocolType &protocol_)
    : PortMapping(port, protocol_)
  {}
  PortMappingExt(int in_port, int out_port, const ProtocolType &protocol_)
    : PortMapping(in_port, out_port, protocol_)
  {}
};

}  // namespace upnp
