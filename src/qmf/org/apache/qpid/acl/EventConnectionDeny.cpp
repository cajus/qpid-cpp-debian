
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//

// This source file was created by a code generator.
// Please do not edit.

#include "qpid/management/Manageable.h" 
#include "qpid/management/Buffer.h"
#include "qpid/types/Variant.h"
#include "qpid/amqp_0_10/Codecs.h"
#include "qpid/management/ManagementAgent.h"
#include "EventConnectionDeny.h"

using namespace qmf::org::apache::qpid::acl;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  EventConnectionDeny::packageName  = string ("org.apache.qpid.acl");
string  EventConnectionDeny::eventName    = string ("connectionDeny");
uint8_t EventConnectionDeny::md5Sum[16]   =
    {0xe7,0x58,0x17,0x2a,0xb,0xd2,0x5d,0x3b,0x74,0x0,0xd5,0x96,0xf4,0x24,0xc,0x4c};

EventConnectionDeny::EventConnectionDeny (const std::string& _userId,
        const std::string& _clientAddr) :
    userId(_userId),
    clientAddr(_clientAddr)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventConnectionDeny::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventConnectionDeny::writeSchema (std::string& schema)
{
    const int _bufSize = 65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);
    ::qpid::types::Variant::Map ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_EVENT);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (eventName);   // Event Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (2); // Argument Count

    // Arguments
    ft.clear();
    ft[NAME] = "userId";
    ft[TYPE] = TYPE_SSTR;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "clientAddr";
    ft[TYPE] = TYPE_SSTR;
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}

void EventConnectionDeny::encode(std::string& _sBuf) const
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    buf.putShortString(userId);
    buf.putShortString(clientAddr);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void EventConnectionDeny::mapEncode(::qpid::types::Variant::Map& map) const
{
    using namespace ::qpid::types;
    map["userId"] = ::qpid::types::Variant(userId);
    map["clientAddr"] = ::qpid::types::Variant(clientAddr);

}

bool EventConnectionDeny::match(const std::string& evt, const std::string& pkg)
{
    return eventName == evt && packageName == pkg;
}
