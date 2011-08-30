
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
#include "Cluster.h"
#include "ArgsClusterStopClusterNode.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::cluster;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Cluster::packageName  = string ("org.apache.qpid.cluster");
string  Cluster::className    = string ("cluster");
uint8_t Cluster::md5Sum[MD5_LEN]   =
    {0x21,0x76,0xfa,0xed,0xc1,0x65,0x9,0x13,0x77,0x40,0x17,0xf7,0xd1,0x4f,0xcc,0xa1};

Cluster::Cluster (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _clusterName, const std::string& _publishedURL) :
    ManagementObject(_core),clusterName(_clusterName),publishedURL(_publishedURL)
{
    brokerRef = _parent->GetManagementObject ()->getObjectId ();
    clusterID = "";
    memberID = "";
    clusterSize = 0;
    status = "";
    members = "";
    memberIDs = "";



}

Cluster::~Cluster ()
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

void Cluster::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Cluster::writeSchema (std::string& schema)
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
    buf.putShort       (9); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (2); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "brokerRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 1;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "clusterName";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Name of cluster this server is a member of";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "clusterID";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Globally unique ID (UUID) for this cluster instance";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "memberID";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "ID of this member of the cluster";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "publishedURL";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "URL this node advertizes itself as";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "clusterSize";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Number of brokers currently in the cluster";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "status";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Cluster node status (STALLED,ACTIVE,JOINING)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "members";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "List of member URLs delimited by ';'";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "memberIDs";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "List of member IDs delimited by ';'";
    buf.putMap(ft);


    // Statistics

    // Methods
    ft.clear();
    ft[NAME] =  "stopClusterNode";
    ft[ARGCOUNT] = 1;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "brokerId";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "stopFullCluster";
    ft[ARGCOUNT] = 0;
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t Cluster::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 16;  // brokerRef
    size += (1 + clusterName.length());  // clusterName
    size += (1 + clusterID.length());  // clusterID
    size += (1 + memberID.length());  // memberID
    size += (1 + publishedURL.length());  // publishedURL
    size += 2;  // clusterSize
    size += (1 + status.length());  // status
    size += (2 + members.length());  // members
    size += (2 + memberIDs.length());  // memberIDs

    return size;
}

void Cluster::readProperties (const std::string& _sBuf)
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
    buf.getShortString(clusterName);
    buf.getShortString(clusterID);
    buf.getShortString(memberID);
    buf.getShortString(publishedURL);
    clusterSize = buf.getShort();
    buf.getShortString(status);
    buf.getMediumString(members);
    buf.getMediumString(memberIDs);


    delete [] _tmpBuf;
}

void Cluster::writeProperties (std::string& _sBuf) const
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
    buf.putShortString(clusterName);
    buf.putShortString(clusterID);
    buf.putShortString(memberID);
    buf.putShortString(publishedURL);
    buf.putShort(clusterSize);
    buf.putShortString(status);
    buf.putMediumString(members);
    buf.putMediumString(memberIDs);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Cluster::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

void Cluster::doMethod (string& methodName, const string& inStr, string& outStr, const string& userId)
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

    if (methodName == "stopClusterNode") {
        _matched = true;
        ArgsClusterStopClusterNode ioArgs;
        inBuf.getShortString(ioArgs.i_brokerId);
        bool allow = coreObject->AuthorizeMethod(METHOD_STOPCLUSTERNODE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_STOPCLUSTERNODE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "stopFullCluster") {
        _matched = true;
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_STOPFULLCLUSTER, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_STOPFULLCLUSTER, ioArgs, text);
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

std::string Cluster::getKey() const
{
    std::stringstream key;

    key << brokerRef.getV2Key();
    return key.str();
}



void Cluster::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["brokerRef"] = ::qpid::types::Variant(brokerRef);
    _map["clusterName"] = ::qpid::types::Variant(clusterName);
    _map["clusterID"] = ::qpid::types::Variant(clusterID);
    _map["memberID"] = ::qpid::types::Variant(memberID);
    _map["publishedURL"] = ::qpid::types::Variant(publishedURL);
    _map["clusterSize"] = ::qpid::types::Variant(clusterSize);
    _map["status"] = ::qpid::types::Variant(status);
    _map["members"] = ::qpid::types::Variant(members);
    _map["memberIDs"] = ::qpid::types::Variant(memberIDs);

    }

    if (includeStatistics) {
        instChanged = false;






    // Maintenance of hi-lo statistics


    }
}

void Cluster::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("brokerRef")) != _map.end()) {
        brokerRef = _i->second;
    }
    if ((_i = _map.find("clusterName")) != _map.end()) {
        clusterName = (_i->second).getString();
    }
    if ((_i = _map.find("clusterID")) != _map.end()) {
        clusterID = (_i->second).getString();
    }
    if ((_i = _map.find("memberID")) != _map.end()) {
        memberID = (_i->second).getString();
    }
    if ((_i = _map.find("publishedURL")) != _map.end()) {
        publishedURL = (_i->second).getString();
    }
    if ((_i = _map.find("clusterSize")) != _map.end()) {
        clusterSize = _i->second;
    }
    if ((_i = _map.find("status")) != _map.end()) {
        status = (_i->second).getString();
    }
    if ((_i = _map.find("members")) != _map.end()) {
        members = (_i->second).getString();
    }
    if ((_i = _map.find("memberIDs")) != _map.end()) {
        memberIDs = (_i->second).getString();
    }

}

void Cluster::doMethod (string& methodName, const ::qpid::types::Variant::Map& inMap, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "stopClusterNode") {
        ArgsClusterStopClusterNode ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("brokerId")) != inMap.end()) {
            ioArgs.i_brokerId = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_STOPCLUSTERNODE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_STOPCLUSTERNODE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "stopFullCluster") {
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_STOPFULLCLUSTER, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_STOPFULLCLUSTER, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
