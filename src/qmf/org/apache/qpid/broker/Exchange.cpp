
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
#include "Exchange.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Exchange::packageName  = string ("org.apache.qpid.broker");
string  Exchange::className    = string ("exchange");
uint8_t Exchange::md5Sum[MD5_LEN]   =
    {0xc9,0xbb,0x43,0xdf,0x44,0xac,0x63,0xd5,0xcc,0x1c,0x6a,0x3,0x20,0x25,0xc9,0x7d};

Exchange::Exchange (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    type = "";
    durable = 0;
    autoDelete = 0;
    altExchange = ::qpid::management::ObjectId();
    arguments = ::qpid::types::Variant::Map();
    producerCount = 0;
    producerCountHigh = 0;
    producerCountLow  = 0;
    bindingCount = 0;
    bindingCountHigh = 0;
    bindingCountLow  = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Exchange::~Exchange ()
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

void Exchange::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Exchange::writeSchema (std::string& schema)
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
    buf.putShort       (7); // Config Element Count
    buf.putShort       (12); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "vhostRef";
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
    ft[NAME] = "type";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "durable";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "autoDelete";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "altExchange";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "arguments";
    ft[TYPE] = TYPE_FTABLE;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Arguments supplied in exchange.declare";
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "producerCount";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Current producers on exchange";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "producerCountHigh";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Current producers on exchange (High)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "producerCountLow";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Current producers on exchange (Low)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bindingCount";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Current bindings";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bindingCountHigh";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Current bindings (High)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bindingCountLow";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Current bindings (Low)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgReceives";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Total messages received";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgDrops";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Total messages dropped (no matching key)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgRoutes";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Total routed messages";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteReceives";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Total bytes received";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteDrops";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Total bytes dropped (no matching key)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteRoutes";
    ft[TYPE] = TYPE_U64;
    ft[DESC] = "Total routed bytes";
    buf.putMap(ft);


    // Methods

    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}


void Exchange::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->msgReceives = 0;
    totals->msgDrops = 0;
    totals->msgRoutes = 0;
    totals->byteReceives = 0;
    totals->byteDrops = 0;
    totals->byteRoutes = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->msgReceives += threadStats->msgReceives;
            totals->msgDrops += threadStats->msgDrops;
            totals->msgRoutes += threadStats->msgRoutes;
            totals->byteReceives += threadStats->byteReceives;
            totals->byteDrops += threadStats->byteDrops;
            totals->byteRoutes += threadStats->byteRoutes;

        }
    }
}



uint32_t Exchange::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 1;

    size += 16;  // vhostRef
    size += (1 + name.length());  // name
    size += (1 + type.length());  // type
    size += 1;  // durable
    size += 1;  // autoDelete
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        size += 16;  // altExchange
    }
    size += ::qpid::amqp_0_10::MapCodec::encodedSize(arguments);  // arguments

    return size;
}

void Exchange::readProperties (const std::string& _sBuf)
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

    {std::string _s; buf.getRawData(_s, vhostRef.encodedSize()); vhostRef.decode(_s);};
    buf.getShortString(name);
    buf.getShortString(type);
    durable = buf.getOctet()==1;
    autoDelete = buf.getOctet()==1;
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        {std::string _s; buf.getRawData(_s, altExchange.encodedSize()); altExchange.decode(_s);};
    }
    buf.getMap(arguments);


    delete [] _tmpBuf;
}

void Exchange::writeProperties (std::string& _sBuf) const
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

    {std::string _s; vhostRef.encode(_s); buf.putRawData(_s);};
    buf.putShortString(name);
    buf.putShortString(type);
    buf.putOctet(durable?1:0);
    buf.putOctet(autoDelete?1:0);
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        {std::string _s; altExchange.encode(_s); buf.putRawData(_s);};
    }
    buf.putMap(arguments);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Exchange::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

    buf.putLong(producerCount);
    buf.putLong(producerCountHigh);
    buf.putLong(producerCountLow);
    buf.putLong(bindingCount);
    buf.putLong(bindingCountHigh);
    buf.putLong(bindingCountLow);
    buf.putLongLong(totals.msgReceives);
    buf.putLongLong(totals.msgDrops);
    buf.putLongLong(totals.msgRoutes);
    buf.putLongLong(totals.byteReceives);
    buf.putLongLong(totals.byteDrops);
    buf.putLongLong(totals.byteRoutes);


    // Maintenance of hi-lo statistics
    producerCountHigh = producerCount;
    producerCountLow  = producerCount;
    bindingCountHigh = bindingCount;
    bindingCountLow  = bindingCount;



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Exchange::doMethod (string&, const string&, string& outStr, const string&)
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

std::string Exchange::getKey() const
{
    std::stringstream key;

    key << name;
    return key.str();
}



void Exchange::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["vhostRef"] = ::qpid::types::Variant(vhostRef);
    _map["name"] = ::qpid::types::Variant(name);
    _map["type"] = ::qpid::types::Variant(type);
    _map["durable"] = ::qpid::types::Variant(durable);
    _map["autoDelete"] = ::qpid::types::Variant(autoDelete);
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        _map["altExchange"] = ::qpid::types::Variant(altExchange);
    }
    _map["arguments"] = ::qpid::types::Variant(arguments);

    }

    if (includeStatistics) {
        instChanged = false;


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["producerCount"] = ::qpid::types::Variant(producerCount);
    _map["producerCountHigh"] = ::qpid::types::Variant(producerCountHigh);
    _map["producerCountLow"] = ::qpid::types::Variant(producerCountLow);
    _map["bindingCount"] = ::qpid::types::Variant(bindingCount);
    _map["bindingCountHigh"] = ::qpid::types::Variant(bindingCountHigh);
    _map["bindingCountLow"] = ::qpid::types::Variant(bindingCountLow);
    _map["msgReceives"] = ::qpid::types::Variant(totals.msgReceives);
    _map["msgDrops"] = ::qpid::types::Variant(totals.msgDrops);
    _map["msgRoutes"] = ::qpid::types::Variant(totals.msgRoutes);
    _map["byteReceives"] = ::qpid::types::Variant(totals.byteReceives);
    _map["byteDrops"] = ::qpid::types::Variant(totals.byteDrops);
    _map["byteRoutes"] = ::qpid::types::Variant(totals.byteRoutes);


    // Maintenance of hi-lo statistics
    producerCountHigh = producerCount;
    producerCountLow  = producerCount;
    bindingCountHigh = bindingCount;
    bindingCountLow  = bindingCount;


    }
}

void Exchange::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    bool _found;

    if ((_i = _map.find("vhostRef")) != _map.end()) {
        vhostRef = _i->second;
    }
    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    }
    if ((_i = _map.find("type")) != _map.end()) {
        type = (_i->second).getString();
    }
    if ((_i = _map.find("durable")) != _map.end()) {
        durable = _i->second;
    }
    if ((_i = _map.find("autoDelete")) != _map.end()) {
        autoDelete = _i->second;
    }
    _found = false;
    if ((_i = _map.find("altExchange")) != _map.end()) {
        altExchange = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_altExchange] |= presenceMask_altExchange;
    }
    if ((_i = _map.find("arguments")) != _map.end()) {
        arguments = (_i->second).asMap();
    }

}

void Exchange::doMethod (string&, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string&)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
