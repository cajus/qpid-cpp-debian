
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
#include "Memory.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Memory::packageName  = string ("org.apache.qpid.broker");
string  Memory::className    = string ("memory");
uint8_t Memory::md5Sum[MD5_LEN]   =
    {0x4c,0x4b,0xf,0x36,0x8,0xca,0xdf,0xd5,0xf3,0x1,0x90,0x39,0x36,0x59,0x86,0x68};

Memory::Memory (ManagementAgent*, Manageable* _core, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    
    malloc_arena = 0;
    malloc_ordblks = 0;
    malloc_hblks = 0;
    malloc_hblkhd = 0;
    malloc_uordblks = 0;
    malloc_fordblks = 0;
    malloc_keepcost = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


}

Memory::~Memory ()
{

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

void Memory::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Memory::writeSchema (std::string& schema)
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
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Index for the broker at this agent";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_arena";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "Total size of memory allocated with `sbrk' by `malloc', in bytes";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_ordblks";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "The number of chunks not in use";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_hblks";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "Total number of chunks allocated with `mmap'";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_hblkhd";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "Total size of memory allocated with `mmap', in bytes";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_uordblks";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "Total size of memory occupied by chunks handed out by `malloc'";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_fordblks";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "Total size of memory occupied by free (not in use) chunks";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "malloc_keepcost";
    ft[TYPE] = TYPE_U64;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "The size of the top-most releasable chunk that normally borders the end of the heap";
    buf.putMap(ft);


    // Statistics

    // Methods

    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t Memory::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 1;

    size += (1 + name.length());  // name
    if (presenceMask[presenceByte_malloc_arena] & presenceMask_malloc_arena) {
        size += 8;  // malloc_arena
    }
    if (presenceMask[presenceByte_malloc_ordblks] & presenceMask_malloc_ordblks) {
        size += 8;  // malloc_ordblks
    }
    if (presenceMask[presenceByte_malloc_hblks] & presenceMask_malloc_hblks) {
        size += 8;  // malloc_hblks
    }
    if (presenceMask[presenceByte_malloc_hblkhd] & presenceMask_malloc_hblkhd) {
        size += 8;  // malloc_hblkhd
    }
    if (presenceMask[presenceByte_malloc_uordblks] & presenceMask_malloc_uordblks) {
        size += 8;  // malloc_uordblks
    }
    if (presenceMask[presenceByte_malloc_fordblks] & presenceMask_malloc_fordblks) {
        size += 8;  // malloc_fordblks
    }
    if (presenceMask[presenceByte_malloc_keepcost] & presenceMask_malloc_keepcost) {
        size += 8;  // malloc_keepcost
    }

    return size;
}

void Memory::readProperties (const std::string& _sBuf)
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

    buf.getShortString(name);
    if (presenceMask[presenceByte_malloc_arena] & presenceMask_malloc_arena) {
        malloc_arena = buf.getLongLong();
    }
    if (presenceMask[presenceByte_malloc_ordblks] & presenceMask_malloc_ordblks) {
        malloc_ordblks = buf.getLongLong();
    }
    if (presenceMask[presenceByte_malloc_hblks] & presenceMask_malloc_hblks) {
        malloc_hblks = buf.getLongLong();
    }
    if (presenceMask[presenceByte_malloc_hblkhd] & presenceMask_malloc_hblkhd) {
        malloc_hblkhd = buf.getLongLong();
    }
    if (presenceMask[presenceByte_malloc_uordblks] & presenceMask_malloc_uordblks) {
        malloc_uordblks = buf.getLongLong();
    }
    if (presenceMask[presenceByte_malloc_fordblks] & presenceMask_malloc_fordblks) {
        malloc_fordblks = buf.getLongLong();
    }
    if (presenceMask[presenceByte_malloc_keepcost] & presenceMask_malloc_keepcost) {
        malloc_keepcost = buf.getLongLong();
    }


    delete [] _tmpBuf;
}

void Memory::writeProperties (std::string& _sBuf) const
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

    buf.putShortString(name);
    if (presenceMask[presenceByte_malloc_arena] & presenceMask_malloc_arena) {
        buf.putLongLong(malloc_arena);
    }
    if (presenceMask[presenceByte_malloc_ordblks] & presenceMask_malloc_ordblks) {
        buf.putLongLong(malloc_ordblks);
    }
    if (presenceMask[presenceByte_malloc_hblks] & presenceMask_malloc_hblks) {
        buf.putLongLong(malloc_hblks);
    }
    if (presenceMask[presenceByte_malloc_hblkhd] & presenceMask_malloc_hblkhd) {
        buf.putLongLong(malloc_hblkhd);
    }
    if (presenceMask[presenceByte_malloc_uordblks] & presenceMask_malloc_uordblks) {
        buf.putLongLong(malloc_uordblks);
    }
    if (presenceMask[presenceByte_malloc_fordblks] & presenceMask_malloc_fordblks) {
        buf.putLongLong(malloc_fordblks);
    }
    if (presenceMask[presenceByte_malloc_keepcost] & presenceMask_malloc_keepcost) {
        buf.putLongLong(malloc_keepcost);
    }


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Memory::writeStatistics (std::string& _sBuf, bool skipHeaders)
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    Mutex::ScopedLock mutex(accessLock);
    instChanged = false;



    if (!skipHeaders) {
        std::string _tbuf;
        writeTimestamps (_tbuf);
        buf.putRawData(_tbuf);
    }



    // Maintenance of hi-lo statistics



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Memory::doMethod (string&, const string&, string& outStr, const string&)
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

std::string Memory::getKey() const
{
    std::stringstream key;

    key << name;
    return key.str();
}



void Memory::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["name"] = ::qpid::types::Variant(name);
    if (presenceMask[presenceByte_malloc_arena] & presenceMask_malloc_arena) {
        _map["malloc_arena"] = ::qpid::types::Variant(malloc_arena);
    }
    if (presenceMask[presenceByte_malloc_ordblks] & presenceMask_malloc_ordblks) {
        _map["malloc_ordblks"] = ::qpid::types::Variant(malloc_ordblks);
    }
    if (presenceMask[presenceByte_malloc_hblks] & presenceMask_malloc_hblks) {
        _map["malloc_hblks"] = ::qpid::types::Variant(malloc_hblks);
    }
    if (presenceMask[presenceByte_malloc_hblkhd] & presenceMask_malloc_hblkhd) {
        _map["malloc_hblkhd"] = ::qpid::types::Variant(malloc_hblkhd);
    }
    if (presenceMask[presenceByte_malloc_uordblks] & presenceMask_malloc_uordblks) {
        _map["malloc_uordblks"] = ::qpid::types::Variant(malloc_uordblks);
    }
    if (presenceMask[presenceByte_malloc_fordblks] & presenceMask_malloc_fordblks) {
        _map["malloc_fordblks"] = ::qpid::types::Variant(malloc_fordblks);
    }
    if (presenceMask[presenceByte_malloc_keepcost] & presenceMask_malloc_keepcost) {
        _map["malloc_keepcost"] = ::qpid::types::Variant(malloc_keepcost);
    }

    }

    if (includeStatistics) {
        instChanged = false;






    // Maintenance of hi-lo statistics


    }
}

void Memory::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    bool _found;

    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    }
    _found = false;
    if ((_i = _map.find("malloc_arena")) != _map.end()) {
        malloc_arena = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_arena] |= presenceMask_malloc_arena;
    }
    _found = false;
    if ((_i = _map.find("malloc_ordblks")) != _map.end()) {
        malloc_ordblks = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_ordblks] |= presenceMask_malloc_ordblks;
    }
    _found = false;
    if ((_i = _map.find("malloc_hblks")) != _map.end()) {
        malloc_hblks = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_hblks] |= presenceMask_malloc_hblks;
    }
    _found = false;
    if ((_i = _map.find("malloc_hblkhd")) != _map.end()) {
        malloc_hblkhd = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_hblkhd] |= presenceMask_malloc_hblkhd;
    }
    _found = false;
    if ((_i = _map.find("malloc_uordblks")) != _map.end()) {
        malloc_uordblks = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_uordblks] |= presenceMask_malloc_uordblks;
    }
    _found = false;
    if ((_i = _map.find("malloc_fordblks")) != _map.end()) {
        malloc_fordblks = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_fordblks] |= presenceMask_malloc_fordblks;
    }
    _found = false;
    if ((_i = _map.find("malloc_keepcost")) != _map.end()) {
        malloc_keepcost = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_malloc_keepcost] |= presenceMask_malloc_keepcost;
    }

}

void Memory::doMethod (string&, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string&)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
