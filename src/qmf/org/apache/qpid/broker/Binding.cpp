
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
#include "Binding.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Binding::packageName  = string ("org.apache.qpid.broker");
string  Binding::className    = string ("binding");
uint8_t Binding::md5Sum[MD5_LEN]   =
    {0x79,0x31,0x1b,0xb,0x40,0x77,0x92,0xc0,0x20,0x1,0x79,0xe7,0x52,0x25,0xda,0xa3};

Binding::Binding (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const ::qpid::management::ObjectId& _queueRef, const std::string& _bindingKey, const ::qpid::types::Variant::Map& _arguments) :
    ManagementObject(_core),queueRef(_queueRef),bindingKey(_bindingKey),arguments(_arguments)
{
    exchangeRef = _parent->GetManagementObject ()->getObjectId ();
    origin = "";


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Binding::~Binding ()
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

void Binding::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Binding::writeSchema (std::string& schema)
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
    buf.putShort       (5); // Config Element Count
    buf.putShort       (1); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "exchangeRef";
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
    ft[NAME] = "bindingKey";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "arguments";
    ft[TYPE] = TYPE_FTABLE;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "origin";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "msgMatched";
    ft[TYPE] = TYPE_U64;
    buf.putMap(ft);


    // Methods

    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}


void Binding::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->msgMatched = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->msgMatched += threadStats->msgMatched;

        }
    }
}



uint32_t Binding::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 1;

    size += 16;  // exchangeRef
    size += 16;  // queueRef
    size += (2 + bindingKey.length());  // bindingKey
    size += ::qpid::amqp_0_10::MapCodec::encodedSize(arguments);  // arguments
    if (presenceMask[presenceByte_origin] & presenceMask_origin) {
        size += (1 + origin.length());  // origin
    }

    return size;
}

void Binding::readProperties (const std::string& _sBuf)
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


    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = buf.getOctet();

    {std::string _s; buf.getRawData(_s, exchangeRef.encodedSize()); exchangeRef.decode(_s);};
    {std::string _s; buf.getRawData(_s, queueRef.encodedSize()); queueRef.decode(_s);};
    buf.getMediumString(bindingKey);
    buf.getMap(arguments);
    if (presenceMask[presenceByte_origin] & presenceMask_origin) {
        buf.getShortString(origin);
    }


    delete [] _tmpBuf;
}

void Binding::writeProperties (std::string& _sBuf) const
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



    for (uint8_t idx = 0; idx < 1; idx++)
        buf.putOctet(presenceMask[idx]);

    {std::string _s; exchangeRef.encode(_s); buf.putRawData(_s);};
    {std::string _s; queueRef.encode(_s); buf.putRawData(_s);};
    buf.putMediumString(bindingKey);
    buf.putMap(arguments);
    if (presenceMask[presenceByte_origin] & presenceMask_origin) {
        buf.putShortString(origin);
    }


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Binding::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

    buf.putLongLong(totals.msgMatched);


    // Maintenance of hi-lo statistics



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Binding::doMethod (string&, const string&, string& outStr, const string&)
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

std::string Binding::getKey() const
{
    std::stringstream key;

    key << exchangeRef.getV2Key() << ",";
    key << queueRef.getV2Key() << ",";
    key << bindingKey;
    return key.str();
}



void Binding::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["exchangeRef"] = ::qpid::types::Variant(exchangeRef);
    _map["queueRef"] = ::qpid::types::Variant(queueRef);
    _map["bindingKey"] = ::qpid::types::Variant(bindingKey);
    _map["arguments"] = ::qpid::types::Variant(arguments);
    if (presenceMask[presenceByte_origin] & presenceMask_origin) {
        _map["origin"] = ::qpid::types::Variant(origin);
    }

    }

    if (includeStatistics) {
        instChanged = false;


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["msgMatched"] = ::qpid::types::Variant(totals.msgMatched);


    // Maintenance of hi-lo statistics


    }
}

void Binding::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    bool _found;

    if ((_i = _map.find("exchangeRef")) != _map.end()) {
        exchangeRef = _i->second;
    }
    if ((_i = _map.find("queueRef")) != _map.end()) {
        queueRef = _i->second;
    }
    if ((_i = _map.find("bindingKey")) != _map.end()) {
        bindingKey = (_i->second).getString();
    }
    if ((_i = _map.find("arguments")) != _map.end()) {
        arguments = (_i->second).asMap();
    }
    _found = false;
    if ((_i = _map.find("origin")) != _map.end()) {
        origin = (_i->second).getString();
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_origin] |= presenceMask_origin;
    }

}

void Binding::doMethod (string&, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string&)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
