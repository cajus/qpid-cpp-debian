
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
#include "ArgsHaBrokerSetBrokersUrl.h"
#include "ArgsHaBrokerSetPublicUrl.h"
#include "ArgsHaBrokerReplicate.h"

#include <iostream>
#include <sstream>
#include <string.h>

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
    {0xac,0xdc,0x2e,0xf2,0xf7,0x96,0xfb,0xd4,0x22,0xea,0x8e,0xe3,0x8b,0xb4,0xef,0x49};

HaBroker::HaBroker (ManagementAgent*, Manageable* _core, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    
    status = "";
    brokersUrl = "";
    publicUrl = "";
    replicateDefault = "";
    members = ::qpid::types::Variant::List();
    systemId = ::qpid::types::Uuid();



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
    buf.putShort       (7); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (4); // Method Count

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
    ft[NAME] = "brokersUrl";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "URL with address of each broker in the cluster.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "publicUrl";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "URL advertized to clients to connect to the cluster.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "replicateDefault";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Replication for queues/exchanges with no qpid.replicate argument";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "members";
    ft[TYPE] = TYPE_LIST;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "List of brokers in the cluster";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "systemId";
    ft[TYPE] = TYPE_UUID;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Identifies the system.";
    buf.putMap(ft);


    // Statistics

    // Methods
    ft.clear();
    ft[NAME] =  "promote";
    ft[ARGCOUNT] = 0;
    ft[DESC] = "Promote a backup broker to primary.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setBrokersUrl";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "URL listing each broker in the cluster.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "url";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setPublicUrl";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "URL advertized to clients.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "url";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "replicate";
    ft[ARGCOUNT] = 2;
    ft[DESC] = "Replicate individual queue from remote broker.";
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
    size += (1 + brokersUrl.length());  // brokersUrl
    size += (1 + publicUrl.length());  // publicUrl
    size += (1 + replicateDefault.length());  // replicateDefault
    size += ::qpid::amqp_0_10::ListCodec::encodedSize(members);  // members
    size += 16;  // systemId

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
    buf.getShortString(brokersUrl);
    buf.getShortString(publicUrl);
    buf.getShortString(replicateDefault);
    buf.getList(members);
    { unsigned char d[16]; buf.getRawData(d, 16); systemId = ::qpid::types::Uuid(d); };


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
    buf.putShortString(brokersUrl);
    buf.putShortString(publicUrl);
    buf.putShortString(replicateDefault);
    buf.putList(members);
    buf.putRawData(systemId.data(), 16);


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

    if (methodName == "setBrokersUrl") {
        _matched = true;
        ArgsHaBrokerSetBrokersUrl ioArgs;
        inBuf.getShortString(ioArgs.i_url);
        bool allow = coreObject->AuthorizeMethod(METHOD_SETBROKERSURL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETBROKERSURL, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "setPublicUrl") {
        _matched = true;
        ArgsHaBrokerSetPublicUrl ioArgs;
        inBuf.getShortString(ioArgs.i_url);
        bool allow = coreObject->AuthorizeMethod(METHOD_SETPUBLICURL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETPUBLICURL, ioArgs, text);
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
    _map["brokersUrl"] = ::qpid::types::Variant(brokersUrl);
    _map["publicUrl"] = ::qpid::types::Variant(publicUrl);
    _map["replicateDefault"] = ::qpid::types::Variant(replicateDefault);
    _map["members"] = ::qpid::types::Variant(members);
    _map["systemId"] = ::qpid::types::Variant(::qpid::types::Uuid((systemId).data()));

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
    } else {
        name = "";
    }
    if ((_i = _map.find("status")) != _map.end()) {
        status = (_i->second).getString();
    } else {
        status = "";
    }
    if ((_i = _map.find("brokersUrl")) != _map.end()) {
        brokersUrl = (_i->second).getString();
    } else {
        brokersUrl = "";
    }
    if ((_i = _map.find("publicUrl")) != _map.end()) {
        publicUrl = (_i->second).getString();
    } else {
        publicUrl = "";
    }
    if ((_i = _map.find("replicateDefault")) != _map.end()) {
        replicateDefault = (_i->second).getString();
    } else {
        replicateDefault = "";
    }
    if ((_i = _map.find("members")) != _map.end()) {
        members = (_i->second).asList();
    } else {
        members = ::qpid::types::Variant::List();
    }
    if ((_i = _map.find("systemId")) != _map.end()) {
        systemId = (_i->second).asUuid().data();
    } else {
        systemId = ::qpid::types::Uuid();
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

    if (methodName == "setBrokersUrl") {
        ArgsHaBrokerSetBrokersUrl ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("url")) != inMap.end()) {
            ioArgs.i_url = (_i->second).getString();
        } else {
            ioArgs.i_url = "";
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETBROKERSURL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETBROKERSURL, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "setPublicUrl") {
        ArgsHaBrokerSetPublicUrl ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("url")) != inMap.end()) {
            ioArgs.i_url = (_i->second).getString();
        } else {
            ioArgs.i_url = "";
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETPUBLICURL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETPUBLICURL, ioArgs, text);
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
        } else {
            ioArgs.i_broker = "";
        }
        if ((_i = inMap.find("queue")) != inMap.end()) {
            ioArgs.i_queue = (_i->second).getString();
        } else {
            ioArgs.i_queue = "";
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
