
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
#include "Bridge.h"

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

string  Bridge::packageName  = string ("org.apache.qpid.broker");
string  Bridge::className    = string ("bridge");
uint8_t Bridge::md5Sum[MD5_LEN]   =
    {0xca,0xa6,0x69,0xd2,0xa8,0x12,0x9,0x1f,0x12,0xbc,0x0,0xb9,0x4d,0x57,0xc6,0xf5};

Bridge::Bridge (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name, bool _durable, const std::string& _src, const std::string& _dest, const std::string& _key, bool _srcIsQueue, bool _srcIsLocal, const std::string& _tag, const std::string& _excludes, bool _dynamic, uint16_t _sync) :
    ManagementObject(_core),name(_name),durable(_durable),src(_src),dest(_dest),key(_key),srcIsQueue(_srcIsQueue),srcIsLocal(_srcIsLocal),tag(_tag),excludes(_excludes),dynamic(_dynamic),sync(_sync)
{
    linkRef = _parent->GetManagementObject ()->getObjectId ();
    channelId = 0;



}

Bridge::~Bridge ()
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

void Bridge::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Bridge::writeSchema (std::string& schema)
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
    buf.putShort       (13); // Config Element Count
    buf.putShort       (0); // Inst Element Count
    buf.putShort       (1); // Method Count

    // Properties
    ft.clear();
    ft[NAME] = "linkRef";
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
    ft[NAME] = "channelId";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "durable";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "src";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "dest";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "key";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "srcIsQueue";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "srcIsLocal";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "tag";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "excludes";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "dynamic";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "sync";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);


    // Statistics

    // Methods
    ft.clear();
    ft[NAME] =  "close";
    ft[ARGCOUNT] = 0;
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t Bridge::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 16;  // linkRef
    size += (1 + name.length());  // name
    size += 2;  // channelId
    size += 1;  // durable
    size += (1 + src.length());  // src
    size += (1 + dest.length());  // dest
    size += (2 + key.length());  // key
    size += 1;  // srcIsQueue
    size += 1;  // srcIsLocal
    size += (1 + tag.length());  // tag
    size += (1 + excludes.length());  // excludes
    size += 1;  // dynamic
    size += 2;  // sync

    return size;
}

void Bridge::readProperties (const std::string& _sBuf)
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


    {std::string _s; buf.getRawData(_s, linkRef.encodedSize()); linkRef.decode(_s);};
    buf.getShortString(name);
    channelId = buf.getShort();
    durable = buf.getOctet()==1;
    buf.getShortString(src);
    buf.getShortString(dest);
    buf.getMediumString(key);
    srcIsQueue = buf.getOctet()==1;
    srcIsLocal = buf.getOctet()==1;
    buf.getShortString(tag);
    buf.getShortString(excludes);
    dynamic = buf.getOctet()==1;
    sync = buf.getShort();


    delete [] _tmpBuf;
}

void Bridge::writeProperties (std::string& _sBuf) const
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



    {std::string _s; linkRef.encode(_s); buf.putRawData(_s);};
    buf.putShortString(name);
    buf.putShort(channelId);
    buf.putOctet(durable?1:0);
    buf.putShortString(src);
    buf.putShortString(dest);
    buf.putMediumString(key);
    buf.putOctet(srcIsQueue?1:0);
    buf.putOctet(srcIsLocal?1:0);
    buf.putShortString(tag);
    buf.putShortString(excludes);
    buf.putOctet(dynamic?1:0);
    buf.putShort(sync);


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Bridge::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

void Bridge::doMethod (string& methodName, const string&, string& outStr, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;

    bool _matched = false;

    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer outBuf(_msgChars, _bufSize);


    if (methodName == "close") {
        _matched = true;
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_CLOSE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_CLOSE, ioArgs, text);
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

std::string Bridge::getKey() const
{
    std::stringstream key;

    key << linkRef.getV2Key() << ",";
    key << name;
    return key.str();
}



void Bridge::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["linkRef"] = ::qpid::types::Variant(linkRef);
    _map["name"] = ::qpid::types::Variant(name);
    _map["channelId"] = ::qpid::types::Variant(channelId);
    _map["durable"] = ::qpid::types::Variant(durable);
    _map["src"] = ::qpid::types::Variant(src);
    _map["dest"] = ::qpid::types::Variant(dest);
    _map["key"] = ::qpid::types::Variant(key);
    _map["srcIsQueue"] = ::qpid::types::Variant(srcIsQueue);
    _map["srcIsLocal"] = ::qpid::types::Variant(srcIsLocal);
    _map["tag"] = ::qpid::types::Variant(tag);
    _map["excludes"] = ::qpid::types::Variant(excludes);
    _map["dynamic"] = ::qpid::types::Variant(dynamic);
    _map["sync"] = ::qpid::types::Variant(sync);

    }

    if (includeStatistics) {
        instChanged = false;






    // Maintenance of hi-lo statistics


    }
}

void Bridge::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("linkRef")) != _map.end()) {
        linkRef = _i->second;
    } else {
        linkRef = ::qpid::management::ObjectId();
    }
    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    } else {
        name = "";
    }
    if ((_i = _map.find("channelId")) != _map.end()) {
        channelId = _i->second;
    } else {
        channelId = 0;
    }
    if ((_i = _map.find("durable")) != _map.end()) {
        durable = _i->second;
    } else {
        durable = false;
    }
    if ((_i = _map.find("src")) != _map.end()) {
        src = (_i->second).getString();
    } else {
        src = "";
    }
    if ((_i = _map.find("dest")) != _map.end()) {
        dest = (_i->second).getString();
    } else {
        dest = "";
    }
    if ((_i = _map.find("key")) != _map.end()) {
        key = (_i->second).getString();
    } else {
        key = "";
    }
    if ((_i = _map.find("srcIsQueue")) != _map.end()) {
        srcIsQueue = _i->second;
    } else {
        srcIsQueue = false;
    }
    if ((_i = _map.find("srcIsLocal")) != _map.end()) {
        srcIsLocal = _i->second;
    } else {
        srcIsLocal = false;
    }
    if ((_i = _map.find("tag")) != _map.end()) {
        tag = (_i->second).getString();
    } else {
        tag = "";
    }
    if ((_i = _map.find("excludes")) != _map.end()) {
        excludes = (_i->second).getString();
    } else {
        excludes = "";
    }
    if ((_i = _map.find("dynamic")) != _map.end()) {
        dynamic = _i->second;
    } else {
        dynamic = false;
    }
    if ((_i = _map.find("sync")) != _map.end()) {
        sync = _i->second;
    } else {
        sync = 0;
    }

}

void Bridge::doMethod (string& methodName, const ::qpid::types::Variant::Map&, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "close") {
        ::qpid::management::ArgsNone ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_CLOSE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_CLOSE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
