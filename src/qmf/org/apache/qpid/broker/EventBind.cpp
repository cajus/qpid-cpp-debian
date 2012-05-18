
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
#include "EventBind.h"

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  EventBind::packageName  = string ("org.apache.qpid.broker");
string  EventBind::eventName    = string ("bind");
uint8_t EventBind::md5Sum[16]   =
    {0x4,0x2a,0xf4,0x9f,0xee,0xa7,0x5c,0xd1,0xa,0xc1,0x10,0xb0,0xe0,0x57,0x3c,0xab};

EventBind::EventBind (const std::string& _rhost,
        const std::string& _user,
        const std::string& _exName,
        const std::string& _qName,
        const std::string& _key,
        const ::qpid::types::Variant::Map& _args) :
    rhost(_rhost),
    user(_user),
    exName(_exName),
    qName(_qName),
    key(_key),
    args(_args)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventBind::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventBind::writeSchema (std::string& schema)
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
    buf.putShort       (6); // Argument Count

    // Arguments
    ft.clear();
    ft[NAME] = "rhost";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Address (i.e. DNS name, IP address, etc.) of a remotely connected host";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "user";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Authentication identity";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "exName";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Name of an exchange";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "qName";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Name of a queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "key";
    ft[TYPE] = TYPE_LSTR;
    ft[DESC] = "Key text used for routing or binding";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "args";
    ft[TYPE] = TYPE_FTABLE;
    ft[DESC] = "Supplemental arguments or parameters supplied";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}

void EventBind::encode(std::string& _sBuf) const
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    buf.putShortString(rhost);
    buf.putShortString(user);
    buf.putShortString(exName);
    buf.putShortString(qName);
    buf.putMediumString(key);
    buf.putMap(args);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void EventBind::mapEncode(::qpid::types::Variant::Map& map) const
{
    using namespace ::qpid::types;
    map["rhost"] = ::qpid::types::Variant(rhost);
    map["user"] = ::qpid::types::Variant(user);
    map["exName"] = ::qpid::types::Variant(exName);
    map["qName"] = ::qpid::types::Variant(qName);
    map["key"] = ::qpid::types::Variant(key);
    map["args"] = ::qpid::types::Variant(args);

}

bool EventBind::match(const std::string& evt, const std::string& pkg)
{
    return eventName == evt && packageName == pkg;
}
