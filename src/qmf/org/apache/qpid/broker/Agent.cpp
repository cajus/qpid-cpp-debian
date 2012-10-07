
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
#include "Agent.h"

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

string  Agent::packageName  = string ("org.apache.qpid.broker");
string  Agent::className    = string ("agent");
uint8_t Agent::md5Sum[MD5_LEN]   =
    {0xa8,0x13,0xb1,0x5,0x63,0x14,0x4c,0x5,0x83,0xd4,0xcb,0xd5,0x37,0x31,0x3d,0x81};

Agent::Agent (ManagementAgent*, Manageable* _core) :
    ManagementObject(_core)
{
    
    connectionRef = ::qpid::management::ObjectId();
    label = "";
    registeredTo = ::qpid::management::ObjectId();
    systemId = ::qpid::types::Uuid();
    brokerBank = 0;
    agentBank = 0;



}

Agent::~Agent ()
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

void Agent::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Agent::writeSchema (std::string& schema)
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
    buf.putShort       (6); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (0); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "connectionRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "label";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Label for agent";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "registeredTo";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Broker agent is registered to";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "systemId";
    ft[TYPE] = TYPE_UUID;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Identifier of system where agent resides";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "brokerBank";
    ft[TYPE] = TYPE_U32;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Assigned object-id broker bank";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "agentBank";
    ft[TYPE] = TYPE_U32;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Assigned object-id agent bank";
    buf.putMap(ft);


    // Statistics

    // Methods

    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t Agent::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 16;  // connectionRef
    size += (1 + label.length());  // label
    size += 16;  // registeredTo
    size += 16;  // systemId
    size += 4;  // brokerBank
    size += 4;  // agentBank

    return size;
}

void Agent::readProperties (const std::string& _sBuf)
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


    {std::string _s; buf.getRawData(_s, connectionRef.encodedSize()); connectionRef.decode(_s);};
    buf.getShortString(label);
    {std::string _s; buf.getRawData(_s, registeredTo.encodedSize()); registeredTo.decode(_s);};
    { unsigned char d[16]; buf.getRawData(d, 16); systemId = ::qpid::types::Uuid(d); };
    brokerBank = buf.getLong();
    agentBank = buf.getLong();


    delete [] _tmpBuf;
}

void Agent::writeProperties (std::string& _sBuf) const
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



    {std::string _s; connectionRef.encode(_s); buf.putRawData(_s);};
    buf.putShortString(label);
    {std::string _s; registeredTo.encode(_s); buf.putRawData(_s);};
    buf.putRawData(systemId.data(), 16);
    buf.putLong(brokerBank);
    buf.putLong(agentBank);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Agent::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

void Agent::doMethod (string&, const string&, string& outStr, const string&)
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

std::string Agent::getKey() const
{
    std::stringstream key;

    key << connectionRef.getV2Key();
    return key.str();
}



void Agent::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["connectionRef"] = ::qpid::types::Variant(connectionRef);
    _map["label"] = ::qpid::types::Variant(label);
    _map["registeredTo"] = ::qpid::types::Variant(registeredTo);
    _map["systemId"] = ::qpid::types::Variant(::qpid::types::Uuid((systemId).data()));
    _map["brokerBank"] = ::qpid::types::Variant(brokerBank);
    _map["agentBank"] = ::qpid::types::Variant(agentBank);

    }

    if (includeStatistics) {
        instChanged = false;






    // Maintenance of hi-lo statistics


    }
}

void Agent::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("connectionRef")) != _map.end()) {
        connectionRef = _i->second;
    } else {
        connectionRef = ::qpid::management::ObjectId();
    }
    if ((_i = _map.find("label")) != _map.end()) {
        label = (_i->second).getString();
    } else {
        label = "";
    }
    if ((_i = _map.find("registeredTo")) != _map.end()) {
        registeredTo = _i->second;
    } else {
        registeredTo = ::qpid::management::ObjectId();
    }
    if ((_i = _map.find("systemId")) != _map.end()) {
        systemId = (_i->second).asUuid().data();
    } else {
        systemId = ::qpid::types::Uuid();
    }
    if ((_i = _map.find("brokerBank")) != _map.end()) {
        brokerBank = _i->second;
    } else {
        brokerBank = 0;
    }
    if ((_i = _map.find("agentBank")) != _map.end()) {
        agentBank = _i->second;
    } else {
        agentBank = 0;
    }

}

void Agent::doMethod (string&, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string&)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
