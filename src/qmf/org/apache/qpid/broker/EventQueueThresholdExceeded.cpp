
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
#include "EventQueueThresholdExceeded.h"

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  EventQueueThresholdExceeded::packageName  = string ("org.apache.qpid.broker");
string  EventQueueThresholdExceeded::eventName    = string ("queueThresholdExceeded");
uint8_t EventQueueThresholdExceeded::md5Sum[16]   =
    {0x4f,0xdb,0x27,0x39,0xd,0x3e,0xe2,0x12,0x33,0xe6,0xf3,0xd3,0xf9,0xc7,0x4d,0x9e};

EventQueueThresholdExceeded::EventQueueThresholdExceeded (const std::string& _qName,
        const uint64_t _msgDepth,
        const uint64_t _byteDepth) :
    qName(_qName),
    msgDepth(_msgDepth),
    byteDepth(_byteDepth)
{}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
}

void EventQueueThresholdExceeded::registerSelf(ManagementAgent* agent)
{
    agent->registerEvent(packageName, eventName, md5Sum, writeSchema);
}

void EventQueueThresholdExceeded::writeSchema (std::string& schema)
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
    buf.putShort       (3); // Argument Count

    // Arguments
    ft.clear();
    ft[NAME] = "qName";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Name of a queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgDepth";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Current size of queue in messages";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteDepth";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Current size of queue in bytes";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}

void EventQueueThresholdExceeded::encode(std::string& _sBuf) const
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    buf.putShortString(qName);
    buf.putLongLong(msgDepth);
    buf.putLongLong(byteDepth);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void EventQueueThresholdExceeded::mapEncode(::qpid::types::Variant::Map& map) const
{
    using namespace ::qpid::types;
    map["qName"] = ::qpid::types::Variant(qName);
    map["msgDepth"] = ::qpid::types::Variant(msgDepth);
    map["byteDepth"] = ::qpid::types::Variant(byteDepth);

}

bool EventQueueThresholdExceeded::match(const std::string& evt, const std::string& pkg)
{
    return eventName == evt && packageName == pkg;
}
