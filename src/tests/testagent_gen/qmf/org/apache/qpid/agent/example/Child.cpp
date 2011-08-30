
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
#include "qpid/agent/ManagementAgent.h"
#include "Child.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::agent::example;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Child::packageName  = string ("org.apache.qpid.agent.example");
string  Child::className    = string ("child");
uint8_t Child::md5Sum[MD5_LEN]   =
    {0x3a,0x7e,0x8b,0xa1,0xe8,0xe2,0x8a,0xb0,0xcc,0x57,0xbb,0xed,0xe1,0xf,0x7a,0x9c};

Child::Child (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    ParentRef = _parent->GetManagementObject ()->getObjectId ();



    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Child::~Child ()
{

    for (int idx = 0; idx < maxThreads; idx++)
        if (perThreadStatsArray[idx] != 0)
            delete perThreadStatsArray[idx];
    delete[] perThreadStatsArray;

}

namespace {
    const string NAME("name");
    const string TYPE("type");
    const string ACCESS("access");
    const string IS_INDEX("index");
    const string IS_OPTIONAL("optional");
    const string UNIT("unit");
    const string MIN("min");
    const string MAX("max");
    const string MAXLEN("maxlen");
    const string DESC("desc");
    const string ARGCOUNT("argCount");
    const string ARGS("args");
    const string DIR("dir");
    const string DEFAULT("default");
}

void Child::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Child::writeSchema (std::string& schema)
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);
    ::qpid::types::Variant::Map ft;

    // Schema class header:
    buf.putOctet       (CLASS_KIND_TABLE);
    buf.putShortString (packageName); // Package Name
    buf.putShortString (className);   // Class Name
    buf.putBin128      (md5Sum);      // Schema Hash
    buf.putShort       (2); // Config Element Count
    buf.putShort       (1); // Inst Element Count
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "ParentRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "count";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "tick";
    ft[DESC] = "Counter that increases monotonically";
    buf.putMap(ft);


    // Methods
    ft.clear();
    ft[NAME] =  "delete";
    ft[ARGCOUNT] = 0;
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}


void Child::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->count = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->count += threadStats->count;

        }
    }
}



std::string Child::getKey() const
{
    std::stringstream key;

    key << ParentRef.getV2Key() << ",";
    key << name;
    return key.str();
}



void Child::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["ParentRef"] = ::qpid::types::Variant(ParentRef);
    _map["name"] = ::qpid::types::Variant(name);

    }

    if (includeStatistics) {
        instChanged = false;


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["count"] = ::qpid::types::Variant(totals.count);


    // Maintenance of hi-lo statistics


    }
}

void Child::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("ParentRef")) != _map.end()) {
        ParentRef = _i->second;
    }
    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    }

}

void Child::doMethod (string& methodName, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "delete") {
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_DELETE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_DELETE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
