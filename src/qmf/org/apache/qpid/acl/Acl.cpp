
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
#include "Acl.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::acl;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Acl::packageName  = string ("org.apache.qpid.acl");
string  Acl::className    = string ("acl");
uint8_t Acl::md5Sum[MD5_LEN]   =
    {0x20,0x69,0x0,0xd5,0xad,0xca,0x4,0xb4,0x32,0xad,0x81,0xdc,0x9b,0xb4,0xf2,0x46};

Acl::Acl (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent) :
    ManagementObject(_core)
{
    brokerRef = _parent->GetManagementObject ()->getObjectId ();
    policyFile = "";
    enforcingAcl = 0;
    transferAcl = 0;
    lastAclLoad = 0;



    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Acl::~Acl ()
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

void Acl::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Acl::writeSchema (std::string& schema)
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
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "brokerRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "policyFile";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Name of the policy file";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "enforcingAcl";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Currently Enforcing ACL";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "transferAcl";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Any transfer ACL rules in force";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "lastAclLoad";
    ft[TYPE] = TYPE_ABSTIME;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Timestamp of last successful load of ACL";
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "aclDenyCount";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "request";
    ft[DESC] = "Number of ACL requests denied";
    buf.putMap(ft);


    // Methods
    ft.clear();
    ft[NAME] =  "reloadACLFile";
    ft[ARGCOUNT] = 0;
    ft[DESC] = "Reload the ACL file";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}


void Acl::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->aclDenyCount = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->aclDenyCount += threadStats->aclDenyCount;

        }
    }
}



uint32_t Acl::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 16;  // brokerRef
    size += (2 + policyFile.length());  // policyFile
    size += 1;  // enforcingAcl
    size += 1;  // transferAcl
    size += 8;  // lastAclLoad

    return size;
}

void Acl::readProperties (const std::string& _sBuf)
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


    {std::string _s; buf.getRawData(_s, brokerRef.encodedSize()); brokerRef.decode(_s);};
    buf.getMediumString(policyFile);
    enforcingAcl = buf.getOctet()==1;
    transferAcl = buf.getOctet()==1;
    lastAclLoad = buf.getLongLong();


    delete [] _tmpBuf;
}

void Acl::writeProperties (std::string& _sBuf) const
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



    {std::string _s; brokerRef.encode(_s); buf.putRawData(_s);};
    buf.putMediumString(policyFile);
    buf.putOctet(enforcingAcl?1:0);
    buf.putOctet(transferAcl?1:0);
    buf.putLongLong(lastAclLoad);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Acl::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

    buf.putLongLong(totals.aclDenyCount);


    // Maintenance of hi-lo statistics



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Acl::doMethod (string& methodName, const string&, string& outStr, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;

    bool _matched = false;

    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer outBuf(_msgChars, _bufSize);


    if (methodName == "reloadACLFile") {
        _matched = true;
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_RELOADACLFILE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_RELOADACLFILE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }


    if (!_matched) {
        outBuf.putLong(status);
        outBuf.putShortString(Manageable::StatusText(status, text));
    }

    uint32_t _bufLen = outBuf.getPosition();
    outBuf.reset();

    outBuf.getRawData(outStr, _bufLen);
}

std::string Acl::getKey() const
{
    std::stringstream key;

    key << brokerRef.getV2Key();
    return key.str();
}



void Acl::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["brokerRef"] = ::qpid::types::Variant(brokerRef);
    _map["policyFile"] = ::qpid::types::Variant(policyFile);
    _map["enforcingAcl"] = ::qpid::types::Variant(enforcingAcl);
    _map["transferAcl"] = ::qpid::types::Variant(transferAcl);
    _map["lastAclLoad"] = ::qpid::types::Variant(lastAclLoad);

    }

    if (includeStatistics) {
        instChanged = false;


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["aclDenyCount"] = ::qpid::types::Variant(totals.aclDenyCount);


    // Maintenance of hi-lo statistics


    }
}

void Acl::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("brokerRef")) != _map.end()) {
        brokerRef = _i->second;
    }
    if ((_i = _map.find("policyFile")) != _map.end()) {
        policyFile = (_i->second).getString();
    }
    if ((_i = _map.find("enforcingAcl")) != _map.end()) {
        enforcingAcl = _i->second;
    }
    if ((_i = _map.find("transferAcl")) != _map.end()) {
        transferAcl = _i->second;
    }
    if ((_i = _map.find("lastAclLoad")) != _map.end()) {
        lastAclLoad = _i->second;
    }

}

void Acl::doMethod (string& methodName, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "reloadACLFile") {
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_RELOADACLFILE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_RELOADACLFILE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
