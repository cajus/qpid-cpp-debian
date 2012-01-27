
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
#include "Broker.h"
#include "ArgsBrokerEcho.h"
#include "ArgsBrokerConnect.h"
#include "ArgsBrokerQueueMoveMessages.h"
#include "ArgsBrokerSetLogLevel.h"
#include "ArgsBrokerGetLogLevel.h"
#include "ArgsBrokerGetTimestampConfig.h"
#include "ArgsBrokerSetTimestampConfig.h"
#include "ArgsBrokerCreate.h"
#include "ArgsBrokerDelete.h"
#include "ArgsBrokerQuery.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Broker::packageName  = string ("org.apache.qpid.broker");
string  Broker::className    = string ("broker");
uint8_t Broker::md5Sum[MD5_LEN]   =
    {0x16,0x6e,0x9a,0xf1,0x1,0x60,0xe9,0x73,0x58,0x4,0x57,0x97,0x58,0x50,0x8a,0x1f};

Broker::Broker (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    systemRef = _parent->GetManagementObject ()->getObjectId ();
    port = 0;
    workerThreads = 0;
    maxConns = 0;
    connBacklog = 0;
    stagingThreshold = 0;
    mgmtPubInterval = 0;
    version = "";
    dataDir = "";
    uptime = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


}

Broker::~Broker ()
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

void Broker::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Broker::writeSchema (std::string& schema)
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
    buf.putShort       (10); // Config Element Count
    buf.putShort       (1); // Inst Element Count
    buf.putShort       (10); // Method Count

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
    ft[NAME] = "systemRef";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "System ID";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "port";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "TCP Port for AMQP Service";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "workerThreads";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Thread pool size";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "maxConns";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Maximum allowed connections";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "connBacklog";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Connection backlog limit for listening socket";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "stagingThreshold";
    ft[TYPE] = TYPE_U32;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Broker stages messages over this size to disk";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "mgmtPubInterval";
    ft[TYPE] = TYPE_U16;
    ft[ACCESS] = ACCESS_RW;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[UNIT] = "second";
    ft[MIN] = 1;
    ft[DESC] = "Interval for management broadcasts";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "version";
    ft[TYPE] = TYPE_SSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Running software version";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "dataDir";
    ft[TYPE] = TYPE_LSTR;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    ft[DESC] = "Persistent configuration storage location";
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "uptime";
    ft[TYPE] = TYPE_DELTATIME;
    buf.putMap(ft);


    // Methods
    ft.clear();
    ft[NAME] =  "echo";
    ft[ARGCOUNT] = 2;
    ft[DESC] = "Request a response to test the path to the management broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "sequence";
    ft[TYPE] = TYPE_U32;
    ft[DIR] = "IO";
    ft[DEFAULT] = "0";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "body";
    ft[TYPE] = TYPE_LSTR;
    ft[DIR] = "IO";
    ft[DEFAULT] = "";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "connect";
    ft[ARGCOUNT] = 7;
    ft[DESC] = "Establish a connection to another broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "host";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "port";
    ft[TYPE] = TYPE_U32;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "durable";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "authMechanism";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "username";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "password";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "transport";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "queueMoveMessages";
    ft[ARGCOUNT] = 4;
    ft[DESC] = "Move messages from one queue to another";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "srcQueue";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "Source queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "destQueue";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "Destination queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "qty";
    ft[TYPE] = TYPE_U32;
    ft[DIR] = "I";
    ft[DESC] = "# of messages to move. 0 means all messages";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "filter";
    ft[TYPE] = TYPE_FTABLE;
    ft[DIR] = "I";
    ft[DEFAULT] = "{}";
    ft[DESC] = "if specified, move only those messages matching this filter";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setLogLevel";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Set the log level";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "level";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "getLogLevel";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Get the current log level";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "level";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "O";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "getTimestampConfig";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Get the message timestamping configuration";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "receive";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "O";
    ft[DESC] = "True if received messages are timestamped.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "setTimestampConfig";
    ft[ARGCOUNT] = 1;
    ft[DESC] = "Set the message timestamping configuration";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "receive";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    ft[DESC] = "Set true to enable timestamping received messages.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "create";
    ft[ARGCOUNT] = 4;
    ft[DESC] = "Create an object of the specified type";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "type";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "The type of object to create";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "The name of the object to create";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "properties";
    ft[TYPE] = TYPE_FTABLE;
    ft[DIR] = "I";
    ft[DESC] = "Type specific object properties";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "strict";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    ft[DESC] = "If specified, treat unrecognised object properties as an error";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "delete";
    ft[ARGCOUNT] = 3;
    ft[DESC] = "Delete an object of the specified type";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "type";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "The type of object to delete";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "The name of the object to delete";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "options";
    ft[TYPE] = TYPE_FTABLE;
    ft[DIR] = "I";
    ft[DESC] = "Type specific object options for deletion";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "query";
    ft[ARGCOUNT] = 3;
    ft[DESC] = "Query the current state of an object.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "type";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "The type of object to query.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "name";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "The name of the object to query";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "results";
    ft[TYPE] = TYPE_FTABLE;
    ft[DIR] = "O";
    ft[DESC] = "A snapshot of the object's state.";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}




uint32_t Broker::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 1;

    size += (1 + name.length());  // name
    size += 16;  // systemRef
    size += 2;  // port
    size += 2;  // workerThreads
    size += 2;  // maxConns
    size += 2;  // connBacklog
    size += 4;  // stagingThreshold
    size += 2;  // mgmtPubInterval
    size += (1 + version.length());  // version
    if (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) {
        size += (2 + dataDir.length());  // dataDir
    }

    return size;
}

void Broker::readProperties (const std::string& _sBuf)
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
    {std::string _s; buf.getRawData(_s, systemRef.encodedSize()); systemRef.decode(_s);};
    port = buf.getShort();
    workerThreads = buf.getShort();
    maxConns = buf.getShort();
    connBacklog = buf.getShort();
    stagingThreshold = buf.getLong();
    mgmtPubInterval = buf.getShort();
    buf.getShortString(version);
    if (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) {
        buf.getMediumString(dataDir);
    }


    delete [] _tmpBuf;
}

void Broker::writeProperties (std::string& _sBuf) const
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
    {std::string _s; systemRef.encode(_s); buf.putRawData(_s);};
    buf.putShort(port);
    buf.putShort(workerThreads);
    buf.putShort(maxConns);
    buf.putShort(connBacklog);
    buf.putLong(stagingThreshold);
    buf.putShort(mgmtPubInterval);
    buf.putShortString(version);
    if (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) {
        buf.putMediumString(dataDir);
    }


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Broker::writeStatistics (std::string& _sBuf, bool skipHeaders)
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

    buf.putLongLong(uptime);


    // Maintenance of hi-lo statistics



    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Broker::doMethod (string& methodName, const string& inStr, string& outStr, const string& userId)
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

    if (methodName == "echo") {
        _matched = true;
        ArgsBrokerEcho ioArgs;
        ioArgs.io_sequence = inBuf.getLong();
        inBuf.getMediumString(ioArgs.io_body);
        bool allow = coreObject->AuthorizeMethod(METHOD_ECHO, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_ECHO, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        outBuf.putLong(ioArgs.io_sequence);
        outBuf.putMediumString(ioArgs.io_body);
    }

    if (methodName == "connect") {
        _matched = true;
        ArgsBrokerConnect ioArgs;
        inBuf.getShortString(ioArgs.i_host);
        ioArgs.i_port = inBuf.getLong();
        ioArgs.i_durable = inBuf.getOctet()==1;
        inBuf.getShortString(ioArgs.i_authMechanism);
        inBuf.getShortString(ioArgs.i_username);
        inBuf.getShortString(ioArgs.i_password);
        inBuf.getShortString(ioArgs.i_transport);
        bool allow = coreObject->AuthorizeMethod(METHOD_CONNECT, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_CONNECT, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "queueMoveMessages") {
        _matched = true;
        ArgsBrokerQueueMoveMessages ioArgs;
        inBuf.getShortString(ioArgs.i_srcQueue);
        inBuf.getShortString(ioArgs.i_destQueue);
        ioArgs.i_qty = inBuf.getLong();
        inBuf.getMap(ioArgs.i_filter);
        bool allow = coreObject->AuthorizeMethod(METHOD_QUEUEMOVEMESSAGES, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_QUEUEMOVEMESSAGES, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "setLogLevel") {
        _matched = true;
        ArgsBrokerSetLogLevel ioArgs;
        inBuf.getShortString(ioArgs.i_level);
        bool allow = coreObject->AuthorizeMethod(METHOD_SETLOGLEVEL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETLOGLEVEL, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "getLogLevel") {
        _matched = true;
        ArgsBrokerGetLogLevel ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_GETLOGLEVEL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_GETLOGLEVEL, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        outBuf.putShortString(ioArgs.o_level);
    }

    if (methodName == "getTimestampConfig") {
        _matched = true;
        ArgsBrokerGetTimestampConfig ioArgs;
        bool allow = coreObject->AuthorizeMethod(METHOD_GETTIMESTAMPCONFIG, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_GETTIMESTAMPCONFIG, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        outBuf.putOctet(ioArgs.o_receive?1:0);
    }

    if (methodName == "setTimestampConfig") {
        _matched = true;
        ArgsBrokerSetTimestampConfig ioArgs;
        ioArgs.i_receive = inBuf.getOctet()==1;
        bool allow = coreObject->AuthorizeMethod(METHOD_SETTIMESTAMPCONFIG, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETTIMESTAMPCONFIG, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "create") {
        _matched = true;
        ArgsBrokerCreate ioArgs;
        inBuf.getShortString(ioArgs.i_type);
        inBuf.getShortString(ioArgs.i_name);
        inBuf.getMap(ioArgs.i_properties);
        ioArgs.i_strict = inBuf.getOctet()==1;
        bool allow = coreObject->AuthorizeMethod(METHOD_CREATE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_CREATE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "delete") {
        _matched = true;
        ArgsBrokerDelete ioArgs;
        inBuf.getShortString(ioArgs.i_type);
        inBuf.getShortString(ioArgs.i_name);
        inBuf.getMap(ioArgs.i_options);
        bool allow = coreObject->AuthorizeMethod(METHOD_DELETE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_DELETE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "query") {
        _matched = true;
        ArgsBrokerQuery ioArgs;
        inBuf.getShortString(ioArgs.i_type);
        inBuf.getShortString(ioArgs.i_name);
        bool allow = coreObject->AuthorizeMethod(METHOD_QUERY, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_QUERY, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
        outBuf.putMap(ioArgs.o_results);
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

std::string Broker::getKey() const
{
    std::stringstream key;

    key << name;
    return key.str();
}



void Broker::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["name"] = ::qpid::types::Variant(name);
    _map["systemRef"] = ::qpid::types::Variant(systemRef);
    _map["port"] = ::qpid::types::Variant(port);
    _map["workerThreads"] = ::qpid::types::Variant(workerThreads);
    _map["maxConns"] = ::qpid::types::Variant(maxConns);
    _map["connBacklog"] = ::qpid::types::Variant(connBacklog);
    _map["stagingThreshold"] = ::qpid::types::Variant(stagingThreshold);
    _map["mgmtPubInterval"] = ::qpid::types::Variant(mgmtPubInterval);
    _map["version"] = ::qpid::types::Variant(version);
    if (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) {
        _map["dataDir"] = ::qpid::types::Variant(dataDir);
    }

    }

    if (includeStatistics) {
        instChanged = false;




    _map["uptime"] = ::qpid::types::Variant(uptime);


    // Maintenance of hi-lo statistics


    }
}

void Broker::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
{
    ::qpid::types::Variant::Map::const_iterator _i;
    Mutex::ScopedLock mutex(accessLock);

    bool _found;

    if ((_i = _map.find("name")) != _map.end()) {
        name = (_i->second).getString();
    }
    if ((_i = _map.find("systemRef")) != _map.end()) {
        systemRef = _i->second;
    }
    if ((_i = _map.find("port")) != _map.end()) {
        port = _i->second;
    }
    if ((_i = _map.find("workerThreads")) != _map.end()) {
        workerThreads = _i->second;
    }
    if ((_i = _map.find("maxConns")) != _map.end()) {
        maxConns = _i->second;
    }
    if ((_i = _map.find("connBacklog")) != _map.end()) {
        connBacklog = _i->second;
    }
    if ((_i = _map.find("stagingThreshold")) != _map.end()) {
        stagingThreshold = _i->second;
    }
    if ((_i = _map.find("mgmtPubInterval")) != _map.end()) {
        mgmtPubInterval = _i->second;
    }
    if ((_i = _map.find("version")) != _map.end()) {
        version = (_i->second).getString();
    }
    _found = false;
    if ((_i = _map.find("dataDir")) != _map.end()) {
        dataDir = (_i->second).getString();
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_dataDir] |= presenceMask_dataDir;
    }

}

void Broker::doMethod (string& methodName, const ::qpid::types::Variant::Map& inMap, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "echo") {
        ArgsBrokerEcho ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("sequence")) != inMap.end()) {
            ioArgs.io_sequence = _i->second;
        }
        if ((_i = inMap.find("body")) != inMap.end()) {
            ioArgs.io_body = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_ECHO, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_ECHO, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        outMap["sequence"] = ::qpid::types::Variant(ioArgs.io_sequence);
        outMap["body"] = ::qpid::types::Variant(ioArgs.io_body);
        return;
    }

    if (methodName == "connect") {
        ArgsBrokerConnect ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("host")) != inMap.end()) {
            ioArgs.i_host = (_i->second).getString();
        }
        if ((_i = inMap.find("port")) != inMap.end()) {
            ioArgs.i_port = _i->second;
        }
        if ((_i = inMap.find("durable")) != inMap.end()) {
            ioArgs.i_durable = _i->second;
        }
        if ((_i = inMap.find("authMechanism")) != inMap.end()) {
            ioArgs.i_authMechanism = (_i->second).getString();
        }
        if ((_i = inMap.find("username")) != inMap.end()) {
            ioArgs.i_username = (_i->second).getString();
        }
        if ((_i = inMap.find("password")) != inMap.end()) {
            ioArgs.i_password = (_i->second).getString();
        }
        if ((_i = inMap.find("transport")) != inMap.end()) {
            ioArgs.i_transport = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_CONNECT, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_CONNECT, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "queueMoveMessages") {
        ArgsBrokerQueueMoveMessages ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("srcQueue")) != inMap.end()) {
            ioArgs.i_srcQueue = (_i->second).getString();
        }
        if ((_i = inMap.find("destQueue")) != inMap.end()) {
            ioArgs.i_destQueue = (_i->second).getString();
        }
        if ((_i = inMap.find("qty")) != inMap.end()) {
            ioArgs.i_qty = _i->second;
        }
        if ((_i = inMap.find("filter")) != inMap.end()) {
            ioArgs.i_filter = (_i->second).asMap();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_QUEUEMOVEMESSAGES, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_QUEUEMOVEMESSAGES, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "setLogLevel") {
        ArgsBrokerSetLogLevel ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("level")) != inMap.end()) {
            ioArgs.i_level = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETLOGLEVEL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETLOGLEVEL, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "getLogLevel") {
        ArgsBrokerGetLogLevel ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        bool allow = coreObject->AuthorizeMethod(METHOD_GETLOGLEVEL, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_GETLOGLEVEL, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        outMap["level"] = ::qpid::types::Variant(ioArgs.o_level);
        return;
    }

    if (methodName == "getTimestampConfig") {
        ArgsBrokerGetTimestampConfig ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        bool allow = coreObject->AuthorizeMethod(METHOD_GETTIMESTAMPCONFIG, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_GETTIMESTAMPCONFIG, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        outMap["receive"] = ::qpid::types::Variant(ioArgs.o_receive);
        return;
    }

    if (methodName == "setTimestampConfig") {
        ArgsBrokerSetTimestampConfig ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("receive")) != inMap.end()) {
            ioArgs.i_receive = _i->second;
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_SETTIMESTAMPCONFIG, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_SETTIMESTAMPCONFIG, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "create") {
        ArgsBrokerCreate ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("type")) != inMap.end()) {
            ioArgs.i_type = (_i->second).getString();
        }
        if ((_i = inMap.find("name")) != inMap.end()) {
            ioArgs.i_name = (_i->second).getString();
        }
        if ((_i = inMap.find("properties")) != inMap.end()) {
            ioArgs.i_properties = (_i->second).asMap();
        }
        if ((_i = inMap.find("strict")) != inMap.end()) {
            ioArgs.i_strict = _i->second;
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_CREATE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_CREATE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "delete") {
        ArgsBrokerDelete ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("type")) != inMap.end()) {
            ioArgs.i_type = (_i->second).getString();
        }
        if ((_i = inMap.find("name")) != inMap.end()) {
            ioArgs.i_name = (_i->second).getString();
        }
        if ((_i = inMap.find("options")) != inMap.end()) {
            ioArgs.i_options = (_i->second).asMap();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_DELETE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_DELETE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "query") {
        ArgsBrokerQuery ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("type")) != inMap.end()) {
            ioArgs.i_type = (_i->second).getString();
        }
        if ((_i = inMap.find("name")) != inMap.end()) {
            ioArgs.i_name = (_i->second).getString();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_QUERY, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_QUERY, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        outMap["results"] = ::qpid::types::Variant(ioArgs.o_results);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
