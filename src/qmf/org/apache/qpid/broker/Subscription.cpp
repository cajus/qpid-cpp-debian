
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
#include "Subscription.h"

#include <iostream>
#include <sstream>
#include <string.h>

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Subscription::packageName  = string ("org.apache.qpid.broker");
string  Subscription::className    = string ("subscription");
uint8_t Subscription::md5Sum[MD5_LEN]   =
    {0x7c,0xc0,0xee,0x44,0x57,0xd4,0x2e,0xd7,0x1a,0x4b,0x31,0x56,0xed,0x9a,0x43,0x43};

Subscription::Subscription (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const ::qpid::management::ObjectId& _queueRef, const std::string& _name, bool _browsing, bool _acknowledged, bool _exclusive, const ::qpid::types::Variant::Map& _arguments) :
    ManagementObject(_core),queueRef(_queueRef),name(_name),browsing(_browsing),acknowledged(_acknowledged),exclusive(_exclusive),arguments(_arguments)
{
    sessionRef = _parent->GetManagementObject ()->getObjectId ();
    creditMode = "";



    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Subscription::~Subscription ()
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

void Subscription::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Subscription::writeSchema (std::string& schema)
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
    buf.putShort       (8); // Config Element Count
    buf.putShort       (1); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "sessionRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "queueRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "browsing";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "acknowledged";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "exclusive";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "creditMode";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "WINDOW or CREDIT";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "arguments";
    ft[TYPE] = TYPE_FTABLE;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "delivered";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages delivered";
    buf.putMap(ft);


    // Methods

    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}


void Subscription::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->delivered = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->delivered += threadStats->delivered;

        }
    }
}



uint32_t Subscription::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 16;  // sessionRef
    size += 16;  // queueRef
    size += (1 + name.length());  // name
    size += 1;  // browsing
    size += 1;  // acknowledged
    size += 1;  // exclusive
    size += (1 + creditMode.length());  // creditMode
    size += ::qpid::amqp_0_10::MapCodec::encodedSize(arguments);  // arguments

    return size;
}

void Subscription::readProperties (const std::string& _sBuf)
{
    char *_tmpBuf = new char[_sBuf.length()];
    memcpy(_tmpBuf, _sBuf.data(), _sBuf.length());
    ::qpid::management::Buffer buf(_tmpBuf, _sBuf.length());
    Mutex::ScopedLock mutex(accessLock);

    {
        std::string _tbuf;
        buf.getRawData(_tbuf, writeTimestampsSize());
        readTimestamps(_tbuf);
    }


    {std::string _s; buf.getRawData(_s, sessionRef.encodedSize()); sessionRef.decode(_s);};
    {std::string _s; buf.getRawData(_s, queueRef.encodedSize()); queueRef.decode(_s);};
    buf.getShortString(name);
    browsing = buf.getOctet()==1;
    acknowledged = buf.getOctet()==1;
    exclusive = buf.getOctet()==1;
    buf.getShortString(creditMode);
    buf.getMap(arguments);


    delete [] _tmpBuf;
}

void Subscription::writeProperties (std::string& _sBuf) const
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    Mutex::ScopedLock mutex(accessLock);
    configChanged = false;

    {
        std::string _tbuf;
        writeTimestamps(_tbuf);
        buf.putRawData(_tbuf);
    }



    {std::string _s; sessionRef.encode(_s); buf.putRawData(_s);};
    {std::string _s; queueRef.encode(_s); buf.putRawData(_s);};
    buf.putShortString(name);
    buf.putOctet(browsing?1:0);
    buf.putOctet(acknowledged?1:0);
    buf.putOctet(exclusive?1:0);
    buf.putShortString(creditMode);
    buf.putMap(arguments);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Subscription::writeStatistics (std::string& _sBuf, bool skipHeaders)
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    Mutex::ScopedLock mutex(accessLock);
    instChanged = false;


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders) {
        std::string _tbuf;
        writeTimestamps (_tbuf);
        buf.putRawData(_tbuf);
    }

    buf.putLongLong(totals.delivered);


    // Maintenance of hi-lo statistics



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Subscription::doMethod (string&, const string&, string& outStr, const string&)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;

    bool _matched = false;

    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer outBuf(_msgChars, _bufSize);



    if (!_matched) {
        outBuf.putLong(status);
        outBuf.putShortString(Manageable::StatusText(status, text));
    }

    uint32_t _bufLen = outBuf.getPosition();
    outBuf.reset();

    outBuf.getRawData(outStr, _bufLen);
}

std::string Subscription::getKey() const
{
    std::stringstream key;

    key << sessionRef.getV2Key() << ",";
    key << queueRef.getV2Key() << ",";
    key << name;
    return key.str();
}



void Subscription::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["sessionRef"] = ::qpid::types::Variant(sessionRef);
    _map["queueRef"] = ::qpid::types::Variant(queueRef);
    _map["name"] = ::qpid::types::Variant(name);
    _map["browsing"] = ::qpid::types::Variant(browsing);
    _map["acknowledged"] = ::qpid::types::Variant(acknowledged);
    _map["exclusive"] = ::qpid::types::Variant(exclusive);
    _map["creditMode"] = ::qpid::types::Variant(creditMode);
    _map["arguments"] = ::qpid::types::Variant(arguments);

    }

    if (includeStatistics) {
        instChanged = false;


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["delivered"] = ::qpid::types::Variant(totals.delivered);


    // Maintenance of hi-lo statistics


    }
}

void Subscription::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("sessionRef")) != _map.end()) {
        sessionRef = _i->second;
    } else {
        sessionRef = ::qpid::management::ObjectId();
    }
    if ((_i = _map.find("queueRef")) != _map.end()) {
        queueRef = _i->second;
    } else {
        queueRef = ::qpid::management::ObjectId();
    }
    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    } else {
        name = "";
    }
    if ((_i = _map.find("browsing")) != _map.end()) {
        browsing = _i->second;
    } else {
        browsing = false;
    }
    if ((_i = _map.find("acknowledged")) != _map.end()) {
        acknowledged = _i->second;
    } else {
        acknowledged = false;
    }
    if ((_i = _map.find("exclusive")) != _map.end()) {
        exclusive = _i->second;
    } else {
        exclusive = false;
    }
    if ((_i = _map.find("creditMode")) != _map.end()) {
        creditMode = (_i->second).getString();
    } else {
        creditMode = "";
    }
    if ((_i = _map.find("arguments")) != _map.end()) {
        arguments = (_i->second).asMap();
    } else {
        arguments = ::qpid::types::Variant::Map();
    }

}

void Subscription::doMethod (string&, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string&)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
