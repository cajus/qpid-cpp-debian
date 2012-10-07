
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
#include "Link.h"
#include "ArgsLinkBridge.h"

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

string  Link::packageName  = string ("org.apache.qpid.broker");
string  Link::className    = string ("link");
uint8_t Link::md5Sum[MD5_LEN]   =
    {0x77,0x7c,0x70,0x3b,0x8d,0xb3,0x8e,0x55,0x14,0x1c,0x63,0xcb,0x4f,0x2f,0xf2,0x52};

Link::Link (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name, bool _durable) :
    ManagementObject(_core),name(_name),durable(_durable)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    host = "";
    port = 0;
    transport = "";
    connectionRef = ::qpid::management::ObjectId();
    state = "";
    lastError = "";



}

Link::~Link ()
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

void Link::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Link::writeSchema (std::string& schema)
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
    buf.putShort       (2); // Inst Element Count
    buf.putShort       (2); // Method Count

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
    ft[NAME] = "host";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "port";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "transport";
    ft[TYPE] = TYPE_SSTR;
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
    ft[NAME] = "connectionRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "state";
    ft[TYPE] = TYPE_SSTR;
    ft[DESC] = "Operational state of the link";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "lastError";
    ft[TYPE] = TYPE_LSTR;
    ft[DESC] = "Reason link is not operational";
    buf.putMap(ft);


    // Methods
    ft.clear();
    ft[NAME] =  "close";
    ft[ARGCOUNT] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "bridge";
    ft[ARGCOUNT] = 10;
    ft[DESC] = "Bridge messages over the link";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "durable";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "src";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "dest";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "key";
    ft[TYPE] = TYPE_LSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "tag";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "excludes";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "srcIsQueue";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "srcIsLocal";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "dynamic";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "sync";
    ft[TYPE] = TYPE_U16;
    ft[DIR] = "I";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t Link::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 16;  // vhostRef
    size += (1 + name.length());  // name
    size += (1 + host.length());  // host
    size += 2;  // port
    size += (1 + transport.length());  // transport
    size += 1;  // durable
    size += 16;  // connectionRef

    return size;
}

void Link::readProperties (const std::string& _sBuf)
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


    {std::string _s; buf.getRawData(_s, vhostRef.encodedSize()); vhostRef.decode(_s);};
    buf.getShortString(name);
    buf.getShortString(host);
    port = buf.getShort();
    buf.getShortString(transport);
    durable = buf.getOctet()==1;
    {std::string _s; buf.getRawData(_s, connectionRef.encodedSize()); connectionRef.decode(_s);};


    delete [] _tmpBuf;
}

void Link::writeProperties (std::string& _sBuf) const
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



    {std::string _s; vhostRef.encode(_s); buf.putRawData(_s);};
    buf.putShortString(name);
    buf.putShortString(host);
    buf.putShort(port);
    buf.putShortString(transport);
    buf.putOctet(durable?1:0);
    {std::string _s; connectionRef.encode(_s); buf.putRawData(_s);};


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Link::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

    buf.putShortString(state);
    buf.putMediumString(lastError);


    // Maintenance of hi-lo statistics



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Link::doMethod (string& methodName, const string& inStr, string& outStr, const string& userId)
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

    if (methodName == "bridge") {
        _matched = true;
        ArgsLinkBridge ioArgs;
        ioArgs.i_durable = inBuf.getOctet()==1;
        inBuf.getShortString(ioArgs.i_src);
        inBuf.getShortString(ioArgs.i_dest);
        inBuf.getMediumString(ioArgs.i_key);
        inBuf.getShortString(ioArgs.i_tag);
        inBuf.getShortString(ioArgs.i_excludes);
        ioArgs.i_srcIsQueue = inBuf.getOctet()==1;
        ioArgs.i_srcIsLocal = inBuf.getOctet()==1;
        ioArgs.i_dynamic = inBuf.getOctet()==1;
        ioArgs.i_sync = inBuf.getShort();
        bool allow = coreObject->AuthorizeMethod(METHOD_BRIDGE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_BRIDGE, ioArgs, text);
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

std::string Link::getKey() const
{
    std::stringstream key;

    key << name;
    return key.str();
}



void Link::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["vhostRef"] = ::qpid::types::Variant(vhostRef);
    _map["name"] = ::qpid::types::Variant(name);
    _map["host"] = ::qpid::types::Variant(host);
    _map["port"] = ::qpid::types::Variant(port);
    _map["transport"] = ::qpid::types::Variant(transport);
    _map["durable"] = ::qpid::types::Variant(durable);
    _map["connectionRef"] = ::qpid::types::Variant(connectionRef);

    }

    if (includeStatistics) {
        instChanged = false;




    _map["state"] = ::qpid::types::Variant(state);
    _map["lastError"] = ::qpid::types::Variant(lastError);


    // Maintenance of hi-lo statistics


    }
}

void Link::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    if ((_i = _map.find("vhostRef")) != _map.end()) {
        vhostRef = _i->second;
    } else {
        vhostRef = ::qpid::management::ObjectId();
    }
    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    } else {
        name = "";
    }
    if ((_i = _map.find("host")) != _map.end()) {
        host = (_i->second).getString();
    } else {
        host = "";
    }
    if ((_i = _map.find("port")) != _map.end()) {
        port = _i->second;
    } else {
        port = 0;
    }
    if ((_i = _map.find("transport")) != _map.end()) {
        transport = (_i->second).getString();
    } else {
        transport = "";
    }
    if ((_i = _map.find("durable")) != _map.end()) {
        durable = _i->second;
    } else {
        durable = false;
    }
    if ((_i = _map.find("connectionRef")) != _map.end()) {
        connectionRef = _i->second;
    } else {
        connectionRef = ::qpid::management::ObjectId();
    }

}

void Link::doMethod (string& methodName, const ::qpid::types::Variant::Map& inMap, ::qpid::types::Variant::Map& outMap, const string& userId)
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

    if (methodName == "bridge") {
        ArgsLinkBridge ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("durable")) != inMap.end()) {
            ioArgs.i_durable = _i->second;
        } else {
            ioArgs.i_durable = false;
        }
        if ((_i = inMap.find("src")) != inMap.end()) {
            ioArgs.i_src = (_i->second).getString();
        } else {
            ioArgs.i_src = "";
        }
        if ((_i = inMap.find("dest")) != inMap.end()) {
            ioArgs.i_dest = (_i->second).getString();
        } else {
            ioArgs.i_dest = "";
        }
        if ((_i = inMap.find("key")) != inMap.end()) {
            ioArgs.i_key = (_i->second).getString();
        } else {
            ioArgs.i_key = "";
        }
        if ((_i = inMap.find("tag")) != inMap.end()) {
            ioArgs.i_tag = (_i->second).getString();
        } else {
            ioArgs.i_tag = "";
        }
        if ((_i = inMap.find("excludes")) != inMap.end()) {
            ioArgs.i_excludes = (_i->second).getString();
        } else {
            ioArgs.i_excludes = "";
        }
        if ((_i = inMap.find("srcIsQueue")) != inMap.end()) {
            ioArgs.i_srcIsQueue = _i->second;
        } else {
            ioArgs.i_srcIsQueue = false;
        }
        if ((_i = inMap.find("srcIsLocal")) != inMap.end()) {
            ioArgs.i_srcIsLocal = _i->second;
        } else {
            ioArgs.i_srcIsLocal = false;
        }
        if ((_i = inMap.find("dynamic")) != inMap.end()) {
            ioArgs.i_dynamic = _i->second;
        } else {
            ioArgs.i_dynamic = false;
        }
        if ((_i = inMap.find("sync")) != inMap.end()) {
            ioArgs.i_sync = _i->second;
        } else {
            ioArgs.i_sync = 0;
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_BRIDGE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_BRIDGE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
