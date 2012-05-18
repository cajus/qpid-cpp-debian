
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
#include "EventQueueDeclare.h"

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  EventQueueDeclare::packageName  = string ("org.apache.qpid.broker");
string  EventQueueDeclare::eventName    = string ("queueDeclare");
uint8_t EventQueueDeclare::md5Sum[16]   =
    {0x81,0xc1,0x4a,0x6d,0x4e,0x35,0xa,0x72,0x44,0xdb,0x7f,0x8a,0x9,0xd0,0x64,0x6e};

EventQueueDeclare::EventQueueDeclare (const std::string& _rhost,
        const std::string& _user,
        const std::string& _qName,
        const bool _durable,
        const bool _excl,
        const bool _autoDel,
        const std::string& _altEx,
        const ::qpid::types::Variant::Map& _args,
        const std::string& _disp) :
    rhost(_rhost),
    user(_user),
    qName(_qName),
    durable(_durable),
    excl(_excl),
    autoDel(_autoDel),
    altEx(_altEx),
    args(_args),
    disp(_disp)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventQueueDeclare::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventQueueDeclare::writeSchema (std::string& schema)
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
    buf.putShort       (9); // Argument Count

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
    ft[NAME] = "qName";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Name of a queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "durable";
    ft[TYPE] = TYPE_BOOL;
    ft[DESC] = "Created object is durable";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "excl";
    ft[TYPE] = TYPE_BOOL;
    ft[DESC] = "Created object is exclusive for the use of the owner only";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "autoDel";
    ft[TYPE] = TYPE_BOOL;
    ft[DESC] = "Created object is automatically deleted when no longer in use";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "altEx";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Name of the alternate exchange";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "args";
    ft[TYPE] = TYPE_FTABLE;
    ft[DESC] = "Supplemental arguments or parameters supplied";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "disp";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Disposition of a declaration: 'created' if object was created, 'existing' if object already existed";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}

void EventQueueDeclare::encode(std::string& _sBuf) const
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    buf.putShortString(rhost);
    buf.putShortString(user);
    buf.putShortString(qName);
    buf.putOctet(durable?1:0);
    buf.putOctet(excl?1:0);
    buf.putOctet(autoDel?1:0);
    buf.putShortString(altEx);
    buf.putMap(args);
    buf.putShortString(disp);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void EventQueueDeclare::mapEncode(::qpid::types::Variant::Map& map) const
{
    using namespace ::qpid::types;
    map["rhost"] = ::qpid::types::Variant(rhost);
    map["user"] = ::qpid::types::Variant(user);
    map["qName"] = ::qpid::types::Variant(qName);
    map["durable"] = ::qpid::types::Variant(durable);
    map["excl"] = ::qpid::types::Variant(excl);
    map["autoDel"] = ::qpid::types::Variant(autoDel);
    map["altEx"] = ::qpid::types::Variant(altEx);
    map["args"] = ::qpid::types::Variant(args);
    map["disp"] = ::qpid::types::Variant(disp);

}

bool EventQueueDeclare::match(const std::string& evt, const std::string& pkg)
{
    return eventName == evt && packageName == pkg;
}
