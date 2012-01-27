
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
#include "Queue.h"
#include "ArgsQueuePurge.h"
#include "ArgsQueueReroute.h"

#include <iostream>
#include <sstream>

using namespace qmf::org::apache::qpid::broker;
using           qpid::management::ManagementAgent;
using           qpid::management::Manageable;
using           qpid::management::ManagementObject;
using           qpid::management::Args;
using           qpid::management::Mutex;
using           std::string;

string  Queue::packageName  = string ("org.apache.qpid.broker");
string  Queue::className    = string ("queue");
uint8_t Queue::md5Sum[MD5_LEN]   =
    {0x3,0xf4,0xbc,0x66,0xbf,0xe,0x0,0x49,0x1d,0xa6,0x6f,0x26,0x9,0x7d,0x5b,0x95};

Queue::Queue (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name, bool _durable, bool _autoDelete, bool _exclusive) :
    ManagementObject(_core),name(_name),durable(_durable),autoDelete(_autoDelete),exclusive(_exclusive)
{
    vhostRef = _parent->GetManagementObject ()->getObjectId ();
    arguments = ::qpid::types::Variant::Map();
    altExchange = ::qpid::management::ObjectId();
    consumerCount = 0;
    consumerCountHigh = 0;
    consumerCountLow  = 0;
    bindingCount = 0;
    bindingCountHigh = 0;
    bindingCountLow  = 0;
    unackedMessages = 0;
    unackedMessagesHigh = 0;
    unackedMessagesLow  = 0;
    flowStopped = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Queue::~Queue ()
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

void Queue::registerSelf(ManagementAgent* agent)
{
    agent->registerClass(packageName, className, md5Sum, writeSchema);
}

void Queue::writeSchema (std::string& schema)
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
    buf.putShort       (29); // Inst Element Count
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
    ft[NAME] = "durable";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "autoDelete";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "exclusive";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RC;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "arguments";
    ft[TYPE] = TYPE_FTABLE;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Arguments supplied in queue.declare";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "altExchange";
    ft[TYPE] = TYPE_REF;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 1;
    buf.putMap(ft);


    // Statistics
    ft.clear();
    ft[NAME] = "msgTotalEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total messages enqueued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTotalDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total messages dequeued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTxnEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Transactional messages enqueued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTxnDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Transactional messages dequeued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgPersistEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Persistent messages enqueued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgPersistDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Persistent messages dequeued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgDepth";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Current size of queue in messages";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteDepth";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Current size of queue in bytes";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTotalEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total messages enqueued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTotalDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total messages dequeued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTxnEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Transactional messages enqueued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTxnDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Transactional messages dequeued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bytePersistEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Persistent messages enqueued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bytePersistDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Persistent messages dequeued";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "consumerCount";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "consumer";
    ft[DESC] = "Current consumers on queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "consumerCountHigh";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "consumer";
    ft[DESC] = "Current consumers on queue (High)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "consumerCountLow";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "consumer";
    ft[DESC] = "Current consumers on queue (Low)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bindingCount";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "binding";
    ft[DESC] = "Current bindings";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bindingCountHigh";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "binding";
    ft[DESC] = "Current bindings (High)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bindingCountLow";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "binding";
    ft[DESC] = "Current bindings (Low)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "unackedMessages";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "message";
    ft[DESC] = "Messages consumed but not yet acked";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "unackedMessagesHigh";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "message";
    ft[DESC] = "Messages consumed but not yet acked (High)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "unackedMessagesLow";
    ft[TYPE] = TYPE_U32;
    ft[UNIT] = "message";
    ft[DESC] = "Messages consumed but not yet acked (Low)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "messageLatencySamples";
    ft[TYPE] = TYPE_DELTATIME;
    ft[UNIT] = "nanosecond";
    ft[DESC] = "Broker latency through this queue (Samples)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "messageLatencyMin";
    ft[TYPE] = TYPE_DELTATIME;
    ft[UNIT] = "nanosecond";
    ft[DESC] = "Broker latency through this queue (Min)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "messageLatencyMax";
    ft[TYPE] = TYPE_DELTATIME;
    ft[UNIT] = "nanosecond";
    ft[DESC] = "Broker latency through this queue (Max)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "messageLatencyAverage";
    ft[TYPE] = TYPE_DELTATIME;
    ft[UNIT] = "nanosecond";
    ft[DESC] = "Broker latency through this queue (Average)";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "flowStopped";
    ft[TYPE] = TYPE_BOOL;
    ft[DESC] = "Flow control active.";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "flowStoppedCount";
    ft[TYPE] = TYPE_U32;
    ft[DESC] = "Number of times flow control was activated for this queue";
    buf.putMap(ft);


    // Methods
    ft.clear();
    ft[NAME] =  "purge";
    ft[ARGCOUNT] = 2;
    ft[DESC] = "Discard all or some messages on a queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "request";
    ft[TYPE] = TYPE_U32;
    ft[DIR] = "I";
    ft[DESC] = "0 for all messages or n>0 for n messages";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "filter";
    ft[TYPE] = TYPE_FTABLE;
    ft[DIR] = "I";
    ft[DEFAULT] = "{}";
    ft[DESC] = "if specified, purge only those messages matching this filter";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] =  "reroute";
    ft[ARGCOUNT] = 4;
    ft[DESC] = "Remove all or some messages on this queue and route them to an exchange";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "request";
    ft[TYPE] = TYPE_U32;
    ft[DIR] = "I";
    ft[DESC] = "0 for all messages or n>0 for n messages";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "useAltExchange";
    ft[TYPE] = TYPE_BOOL;
    ft[DIR] = "I";
    ft[DESC] = "Iff true, use the queue's configured alternate exchange; iff false, use exchange named in the 'exchange' argument";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "exchange";
    ft[TYPE] = TYPE_SSTR;
    ft[DIR] = "I";
    ft[DESC] = "Name of the exchange to route the messages through";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "filter";
    ft[TYPE] = TYPE_FTABLE;
    ft[DIR] = "I";
    ft[DEFAULT] = "{}";
    ft[DESC] = "if specified, reroute only those messages matching this filter";
    buf.putMap(ft);


    {
        uint32_t _len = buf.getPosition();
        buf.reset();
        buf.getRawData(schema, _len);
    }
}


void Queue::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->msgTotalEnqueues = 0;
    totals->msgTotalDequeues = 0;
    totals->msgTxnEnqueues = 0;
    totals->msgTxnDequeues = 0;
    totals->msgPersistEnqueues = 0;
    totals->msgPersistDequeues = 0;
    totals->msgDepth = 0;
    totals->byteDepth = 0;
    totals->byteTotalEnqueues = 0;
    totals->byteTotalDequeues = 0;
    totals->byteTxnEnqueues = 0;
    totals->byteTxnDequeues = 0;
    totals->bytePersistEnqueues = 0;
    totals->bytePersistDequeues = 0;
    totals->messageLatencyCount = 0;
    totals->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
    totals->messageLatencyMax   = std::numeric_limits<uint64_t>::min();
    totals->messageLatencyTotal = 0;
    totals->flowStoppedCount = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->msgTotalEnqueues += threadStats->msgTotalEnqueues;
            totals->msgTotalDequeues += threadStats->msgTotalDequeues;
            totals->msgTxnEnqueues += threadStats->msgTxnEnqueues;
            totals->msgTxnDequeues += threadStats->msgTxnDequeues;
            totals->msgPersistEnqueues += threadStats->msgPersistEnqueues;
            totals->msgPersistDequeues += threadStats->msgPersistDequeues;
            totals->msgDepth += threadStats->msgDepth;
            totals->byteDepth += threadStats->byteDepth;
            totals->byteTotalEnqueues += threadStats->byteTotalEnqueues;
            totals->byteTotalDequeues += threadStats->byteTotalDequeues;
            totals->byteTxnEnqueues += threadStats->byteTxnEnqueues;
            totals->byteTxnDequeues += threadStats->byteTxnDequeues;
            totals->bytePersistEnqueues += threadStats->bytePersistEnqueues;
            totals->bytePersistDequeues += threadStats->bytePersistDequeues;
            totals->messageLatencyCount += threadStats->messageLatencyCount;
            if (totals->messageLatencyMin > threadStats->messageLatencyMin)
                totals->messageLatencyMin = threadStats->messageLatencyMin;
            if (totals->messageLatencyMax < threadStats->messageLatencyMax)
                totals->messageLatencyMax = threadStats->messageLatencyMax;
            totals->messageLatencyTotal += threadStats->messageLatencyTotal;
            totals->flowStoppedCount += threadStats->flowStoppedCount;

        }
    }
}



uint32_t Queue::writePropertiesSize() const
{
    uint32_t size = writeTimestampsSize();

    size += 1;

    size += 16;  // vhostRef
    size += (1 + name.length());  // name
    size += 1;  // durable
    size += 1;  // autoDelete
    size += 1;  // exclusive
    size += ::qpid::amqp_0_10::MapCodec::encodedSize(arguments);  // arguments
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        size += 16;  // altExchange
    }

    return size;
}

void Queue::readProperties (const std::string& _sBuf)
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
    durable = buf.getOctet()==1;
    autoDelete = buf.getOctet()==1;
    exclusive = buf.getOctet()==1;
    buf.getMap(arguments);
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        {std::string _s; buf.getRawData(_s, altExchange.encodedSize()); altExchange.decode(_s);};
    }


    delete [] _tmpBuf;
}

void Queue::writeProperties (std::string& _sBuf) const
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
    buf.putOctet(durable?1:0);
    buf.putOctet(autoDelete?1:0);
    buf.putOctet(exclusive?1:0);
    buf.putMap(arguments);
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        {std::string _s; altExchange.encode(_s); buf.putRawData(_s);};
    }


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Queue::writeStatistics (std::string& _sBuf, bool skipHeaders)
{
    const int _bufSize=65536;
    char _msgChars[_bufSize];
    ::qpid::management::Buffer buf(_msgChars, _bufSize);

    Mutex::ScopedLock mutex(accessLock);
    instChanged = false;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
        threadStats->msgDepth = (uint64_t) (threadStats->msgTotalEnqueues - threadStats->msgTotalDequeues);
        threadStats->byteDepth = (uint64_t) (threadStats->byteTotalEnqueues - threadStats->byteTotalDequeues);

        }
    }


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders) {
        std::string _tbuf;
        writeTimestamps (_tbuf);
        buf.putRawData(_tbuf);
    }

    buf.putLongLong(totals.msgTotalEnqueues);
    buf.putLongLong(totals.msgTotalDequeues);
    buf.putLongLong(totals.msgTxnEnqueues);
    buf.putLongLong(totals.msgTxnDequeues);
    buf.putLongLong(totals.msgPersistEnqueues);
    buf.putLongLong(totals.msgPersistDequeues);
    buf.putLongLong(totals.msgDepth);
    buf.putLongLong(totals.byteDepth);
    buf.putLongLong(totals.byteTotalEnqueues);
    buf.putLongLong(totals.byteTotalDequeues);
    buf.putLongLong(totals.byteTxnEnqueues);
    buf.putLongLong(totals.byteTxnDequeues);
    buf.putLongLong(totals.bytePersistEnqueues);
    buf.putLongLong(totals.bytePersistDequeues);
    buf.putLong(consumerCount);
    buf.putLong(consumerCountHigh);
    buf.putLong(consumerCountLow);
    buf.putLong(bindingCount);
    buf.putLong(bindingCountHigh);
    buf.putLong(bindingCountLow);
    buf.putLong(unackedMessages);
    buf.putLong(unackedMessagesHigh);
    buf.putLong(unackedMessagesLow);
    buf.putLongLong(totals.messageLatencyCount);
    buf.putLongLong(totals.messageLatencyCount ? totals.messageLatencyMin : 0);
    buf.putLongLong(totals.messageLatencyMax);
    buf.putLongLong(totals.messageLatencyCount ? totals.messageLatencyTotal / totals.messageLatencyCount : 0);
    buf.putOctet(flowStopped?1:0);
    buf.putLong(totals.flowStoppedCount);


    // Maintenance of hi-lo statistics
    consumerCountHigh = consumerCount;
    consumerCountLow  = consumerCount;
    bindingCountHigh = bindingCount;
    bindingCountLow  = bindingCount;
    unackedMessagesHigh = unackedMessages;
    unackedMessagesLow  = unackedMessages;


    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
        threadStats->messageLatencyCount = 0;
        threadStats->messageLatencyTotal = 0;
        threadStats->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
        threadStats->messageLatencyMax   = std::numeric_limits<uint64_t>::min();

        }
    }


    uint32_t _bufLen = buf.getPosition();
    buf.reset();

    buf.getRawData(_sBuf, _bufLen);
}

void Queue::doMethod (string& methodName, const string& inStr, string& outStr, const string& userId)
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

    if (methodName == "purge") {
        _matched = true;
        ArgsQueuePurge ioArgs;
        ioArgs.i_request = inBuf.getLong();
        inBuf.getMap(ioArgs.i_filter);
        bool allow = coreObject->AuthorizeMethod(METHOD_PURGE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_PURGE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outBuf.putLong        (status);
        outBuf.putMediumString(::qpid::management::Manageable::StatusText (status, text));
    }

    if (methodName == "reroute") {
        _matched = true;
        ArgsQueueReroute ioArgs;
        ioArgs.i_request = inBuf.getLong();
        ioArgs.i_useAltExchange = inBuf.getOctet()==1;
        inBuf.getShortString(ioArgs.i_exchange);
        inBuf.getMap(ioArgs.i_filter);
        bool allow = coreObject->AuthorizeMethod(METHOD_REROUTE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_REROUTE, ioArgs, text);
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

std::string Queue::getKey() const
{
    std::stringstream key;

    key << name;
    return key.str();
}



void Queue::mapEncodeValues (::qpid::types::Variant::Map& _map,
                                              bool includeProperties,
                                              bool includeStatistics)
{
    using namespace ::qpid::types;
    Mutex::ScopedLock mutex(accessLock);

    if (includeProperties) {
        configChanged = false;
    _map["vhostRef"] = ::qpid::types::Variant(vhostRef);
    _map["name"] = ::qpid::types::Variant(name);
    _map["durable"] = ::qpid::types::Variant(durable);
    _map["autoDelete"] = ::qpid::types::Variant(autoDelete);
    _map["exclusive"] = ::qpid::types::Variant(exclusive);
    _map["arguments"] = ::qpid::types::Variant(arguments);
    if (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) {
        _map["altExchange"] = ::qpid::types::Variant(altExchange);
    }

    }

    if (includeStatistics) {
        instChanged = false;

        for (int idx = 0; idx < maxThreads; idx++) {
            struct PerThreadStats* threadStats = perThreadStatsArray[idx];
            if (threadStats != 0) {
        threadStats->msgDepth = (uint64_t) (threadStats->msgTotalEnqueues - threadStats->msgTotalDequeues);
        threadStats->byteDepth = (uint64_t) (threadStats->byteTotalEnqueues - threadStats->byteTotalDequeues);

            }
        }


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["msgTotalEnqueues"] = ::qpid::types::Variant(totals.msgTotalEnqueues);
    _map["msgTotalDequeues"] = ::qpid::types::Variant(totals.msgTotalDequeues);
    _map["msgTxnEnqueues"] = ::qpid::types::Variant(totals.msgTxnEnqueues);
    _map["msgTxnDequeues"] = ::qpid::types::Variant(totals.msgTxnDequeues);
    _map["msgPersistEnqueues"] = ::qpid::types::Variant(totals.msgPersistEnqueues);
    _map["msgPersistDequeues"] = ::qpid::types::Variant(totals.msgPersistDequeues);
    _map["msgDepth"] = ::qpid::types::Variant(totals.msgDepth);
    _map["byteDepth"] = ::qpid::types::Variant(totals.byteDepth);
    _map["byteTotalEnqueues"] = ::qpid::types::Variant(totals.byteTotalEnqueues);
    _map["byteTotalDequeues"] = ::qpid::types::Variant(totals.byteTotalDequeues);
    _map["byteTxnEnqueues"] = ::qpid::types::Variant(totals.byteTxnEnqueues);
    _map["byteTxnDequeues"] = ::qpid::types::Variant(totals.byteTxnDequeues);
    _map["bytePersistEnqueues"] = ::qpid::types::Variant(totals.bytePersistEnqueues);
    _map["bytePersistDequeues"] = ::qpid::types::Variant(totals.bytePersistDequeues);
    _map["consumerCount"] = ::qpid::types::Variant(consumerCount);
    _map["consumerCountHigh"] = ::qpid::types::Variant(consumerCountHigh);
    _map["consumerCountLow"] = ::qpid::types::Variant(consumerCountLow);
    _map["bindingCount"] = ::qpid::types::Variant(bindingCount);
    _map["bindingCountHigh"] = ::qpid::types::Variant(bindingCountHigh);
    _map["bindingCountLow"] = ::qpid::types::Variant(bindingCountLow);
    _map["unackedMessages"] = ::qpid::types::Variant(unackedMessages);
    _map["unackedMessagesHigh"] = ::qpid::types::Variant(unackedMessagesHigh);
    _map["unackedMessagesLow"] = ::qpid::types::Variant(unackedMessagesLow);
    _map["messageLatencyCount"] = ::qpid::types::Variant(totals.messageLatencyCount);
    _map["messageLatencyMin"] = (totals.messageLatencyCount ? ::qpid::types::Variant(totals.messageLatencyMin) : ::qpid::types::Variant(0));
    _map["messageLatencyMax"] = ::qpid::types::Variant(totals.messageLatencyMax);
    _map["messageLatencyAvg"] = (totals.messageLatencyCount ? ::qpid::types::Variant((totals.messageLatencyTotal / totals.messageLatencyCount)) : ::qpid::types::Variant(0));
    _map["flowStopped"] = ::qpid::types::Variant(flowStopped);
    _map["flowStoppedCount"] = ::qpid::types::Variant(totals.flowStoppedCount);


    // Maintenance of hi-lo statistics
    consumerCountHigh = consumerCount;
    consumerCountLow  = consumerCount;
    bindingCountHigh = bindingCount;
    bindingCountLow  = bindingCount;
    unackedMessagesHigh = unackedMessages;
    unackedMessagesLow  = unackedMessages;


        for (int idx = 0; idx < maxThreads; idx++) {
            struct PerThreadStats* threadStats = perThreadStatsArray[idx];
            if (threadStats != 0) {
        threadStats->messageLatencyCount = 0;
        threadStats->messageLatencyTotal = 0;
        threadStats->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
        threadStats->messageLatencyMax   = std::numeric_limits<uint64_t>::min();

            }
        }

    }
}

void Queue::mapDecodeValues (const ::qpid::types::Variant::Map& _map)
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
    if ((_i = _map.find("durable")) != _map.end()) {
        durable = _i->second;
    }
    if ((_i = _map.find("autoDelete")) != _map.end()) {
        autoDelete = _i->second;
    }
    if ((_i = _map.find("exclusive")) != _map.end()) {
        exclusive = _i->second;
    }
    if ((_i = _map.find("arguments")) != _map.end()) {
        arguments = (_i->second).asMap();
    }
    _found = false;
    if ((_i = _map.find("altExchange")) != _map.end()) {
        altExchange = _i->second;
        _found = true;
    }
    if (_found) {
        presenceMask[presenceByte_altExchange] |= presenceMask_altExchange;
    }

}

void Queue::doMethod (string& methodName, const ::qpid::types::Variant::Map& inMap, ::qpid::types::Variant::Map& outMap, const string& userId)
{
    Manageable::status_t status = Manageable::STATUS_UNKNOWN_METHOD;
    std::string          text;


    if (methodName == "purge") {
        ArgsQueuePurge ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("request")) != inMap.end()) {
            ioArgs.i_request = _i->second;
        }
        if ((_i = inMap.find("filter")) != inMap.end()) {
            ioArgs.i_filter = (_i->second).asMap();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_PURGE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_PURGE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    if (methodName == "reroute") {
        ArgsQueueReroute ioArgs;
        ::qpid::types::Variant::Map::const_iterator _i;
        if ((_i = inMap.find("request")) != inMap.end()) {
            ioArgs.i_request = _i->second;
        }
        if ((_i = inMap.find("useAltExchange")) != inMap.end()) {
            ioArgs.i_useAltExchange = _i->second;
        }
        if ((_i = inMap.find("exchange")) != inMap.end()) {
            ioArgs.i_exchange = (_i->second).getString();
        }
        if ((_i = inMap.find("filter")) != inMap.end()) {
            ioArgs.i_filter = (_i->second).asMap();
        }
        bool allow = coreObject->AuthorizeMethod(METHOD_REROUTE, ioArgs, userId);
        if (allow)
            status = coreObject->ManagementMethod (METHOD_REROUTE, ioArgs, text);
        else
            status = Manageable::STATUS_FORBIDDEN;
        outMap["_status_code"] = (uint32_t) status;
        outMap["_status_text"] = ::qpid::management::Manageable::StatusText(status, text);
        return;
    }

    outMap["_status_code"] = (uint32_t) status;
    outMap["_status_text"] = Manageable::StatusText(status, text);
}
