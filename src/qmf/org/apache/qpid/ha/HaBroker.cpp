
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
#include "HaBroker.h"
#include "ArgsHaBrokerSetBrokers.h"
#include "ArgsHaBrokerSetPublicBrokers.h"
#include "ArgsHaBrokerSetExpectedBackups.h"
#include "ArgsHaBrokerReplicate.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::ha;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  HaBroker::packageName  = string ("org.apache.qpid.ha");
string  HaBroker::className    = string ("habroker");
uint8_t HaBroker::md5Sum[MD5_LEN]   =
    {0xc6,0x81,0xdf,0x94,0x41,0xcb,0xc4,0xfd,0x90,0x59,0xd7,0x94,0xe3,0x47,0xdf,0x80};

HaBroker::HaBroker (ManagementAgent*, Manageable* _core, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    
    status = "";
    brokers = "";
    publicBrokers = "";
    expectedBackups = 0;



}

HaBroker::~HaBroker ()
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

void HaBroker::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void HaBroker::writeSchema (std::string& schema)
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
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (5); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Primary Key";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "status";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "HA status: primary or backup";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "brokers";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Multiple-address URL used by HA brokers to connect to each other.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "publicBrokers";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Multiple-address URL used by clients to connect to the HA brokers.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "expectedBackups";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Number of HA backup brokers expected.";
    buf.putMap(ft);


    // Statistics

    // Methods
    ft.clear();
    ft[NAME] =  "promote";
    ft[ARGCOUNT] = 0;
    ft[DESC] = "Promote a backup broker to primary.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setBrokers";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Set URL for HA brokers to connect to each other.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "url";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setPublicBrokers";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Set URL for clients to connect to  HA brokers";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "url";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setExpectedBackups";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Set number of backups expected";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "expectedBackups";
    ft[TYPE] = TYPE_U16;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "replicate";
    ft[ARGCOUNT] = 2;
    ft[DESC] = "Replicate from a remote queue to the local broker.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "broker";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "queue";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t HaBroker::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += (1 + name.length());  // name
    size += (1 + status.length());  // status
    size += (1 + brokers.length());  // brokers
    size += (1 + publicBrokers.length());  // publicBrokers
    size += 2;  // expectedBackups

    return size;
}

void HaBroker::readProperties (const std::string& _sBuf)
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


    buf.getShortString(name);
    buf.getShortString(status);
    buf.getShortString(brokers);
    buf.getShortString(publicBrokers);
    expectedBackups = buf.getShort();


    delete [] _tmpBuf;
}

void HaBroker::writeProperties (std::string& _sBuf) const
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



    buf.putShortString(name);
    buf.putShortString(status);
    buf.putShortString(brokers);
    buf.putShortString(publicBrokers);
    buf.putShort(expectedBackups);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void HaBroker::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

void HaBroker::doMethod (string& methodName, const string& inStr, string& outStr, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;

    bool _matched = false;

    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer outBuf(_msgChars, _bufSize);


    char *_tmpBuf = new char[inStr.length()];
    memcpy(_tmpBuf, inStr.data(), inStr.length());
    ::qpid::management::Buffer inBuf(_tmpBuf, inStr.length());

    if (methodName == "promote") {
        _matched = true;
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_PROMOTE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_PROMOTE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "setBrokers") {
        _matched = true;
        ArgsHaBrokerSetBrokers ioArgs;
        inBuf.getShortString(ioArgs.i_url);
        bool allow = coreObject->AuthorizeMethod(METHOD_SETBROKERS, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETBROKERS, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "setPublicBrokers") {
        _matched = true;
        ArgsHaBrokerSetPublicBrokers ioArgs;
        inBuf.getShortString(ioArgs.i_url);
        bool allow = coreObject->AuthorizeMethod(METHOD_SETPUBLICBROKERS, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETPUBLICBROKERS, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "setExpectedBackups") {
        _matched = true;
        ArgsHaBrokerSetExpectedBackups ioArgs;
        ioArgs.i_expectedBackups = inBuf.getShort();
        bool allow = coreObject->AuthorizeMethod(METHOD_SETEXPECTEDBACKUPS, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETEXPECTEDBACKUPS, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "replicate") {
        _matched = true;
        ArgsHaBrokerReplicate ioArgs;
        inBuf.getShortString(ioArgs.i_broker);
        inBuf.getShortString(ioArgs.i_queue);
        bool allow = coreObject->AuthorizeMethod(METHOD_REPLICATE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_REPLICATE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    delete [] _tmpBuf;


    if (!_matched) {
        outBuf.putLong(status);
        outBuf.putShortString(Manageable::StatusText(status, text));
    }

    uint32_t _bufLen = outBuf.getPosition();
    outBuf.reset();

    outBuf.getRawData(outStr, _bufLen);
}

std::string HaBroker::getKey() const
{
    std::stringstream key;

    key << name;
    return key.str();
}



void HaBroker::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["name"] = ::qpid::types::Variant(name);
    _map["status"] = ::qpid::types::Variant(status);
    _map["brokers"] = ::qpid::types::Variant(brokers);
    _map["publicBrokers"] = ::qpid::types::Variant(publicBrokers);
    _map["expectedBackups"] = ::qpid::types::Variant(expectedBackups);

    }

    if (includeStatistics) {
        instChanged = false;






    // Maintenance of hi-lo statistics


    }
}

void HaBroker::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    }
    if ((_i = _map.find("status")) != _map.end()) {
        status = (_i->second).getString();
    }
    if ((_i = _map.find("brokers")) != _map.end()) {
        brokers = (_i->second).getString();
    }
    if ((_i = _map.find("publicBrokers")) != _map.end()) {
        publicBrokers = (_i->second).getString();
    }
    if ((_i = _map.find("expectedBackups")) != _map.end()) {
        expectedBackups = _i->second;
    }

}

void HaBroker::doMethod (string& methodName, const ::qpid::types::Variant::Map& inMap, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "promote") {
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_PROMOTE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_PROMOTE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "setBrokers") {
        ArgsHaBrokerSetBrokers ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("url")) != inMap.end()) {
            ioArgs.i_url = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETBROKERS, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETBROKERS, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "setPublicBrokers") {
        ArgsHaBrokerSetPublicBrokers ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("url")) != inMap.end()) {
            ioArgs.i_url = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETPUBLICBROKERS, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETPUBLICBROKERS, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "setExpectedBackups") {
        ArgsHaBrokerSetExpectedBackups ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("expectedBackups")) != inMap.end()) {
            ioArgs.i_expectedBackups = _i->second;
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETEXPECTEDBACKUPS, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETEXPECTEDBACKUPS, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "replicate") {
        ArgsHaBrokerReplicate ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("broker")) != inMap.end()) {
            ioArgs.i_broker = (_i->second).getString();
        }
        if ((_i = inMap.find("queue")) != inMap.end()) {
            ioArgs.i_queue = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_REPLICATE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_REPLICATE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
