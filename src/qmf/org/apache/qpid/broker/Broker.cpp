
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
    {0x51,0x39,0x10,0x71,0x15,0x43,0xcd,0xa4,0xe,0xae,0x70,0x15,0x2a,0xf2,0xca,0x82};

Broker::Broker (ManagementAgent*, Manageable* _core, ::qpid::management::Manageable* _parent, const std::string& _name) :
    ManagementObject(_core),name(_name)
{
    systemRef = _parent->GetManagementObject ()->getObjectId ();
    port = 0;
    workerThreads = 0;
    maxConns = 0;
    connBacklog = 0;
    stagingThreshold = 0;
    mgmtPublish = 0;
    mgmtPubInterval = 0;
    version = "";
    dataDir = "";
    uptime = 0;


    // Optional properties start out not-present
    for (uint8_t idx = 0; idx < 1; idx++)
        presenceMask[idx] = 0;


    perThreadStatsArray = new struct PerThreadStats*[maxThreads];
    for (int idx = 0; idx < maxThreads; idx++)
        perThreadStatsArray[idx] = 0;

}

Broker::~Broker ()
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
    buf.putShort       (11); // Config Element Count
    buf.putShort       (34); // Inst Element Count
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
    ft[NAME] = "mgmtPublish";
    ft[TYPE] = TYPE_BOOL;
    ft[ACCESS] = ACCESS_RO;
    ft[IS_INDEX] = 0;
    ft[IS_OPTIONAL] = 0;
    ft[DESC] = "Broker's management agent sends unsolicited data on the publish interval";
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

    ft.clear();
    ft[NAME] = "queueCount";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "queue";
    ft[DESC] = "Number of queues in the broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTotalEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total messages enqueued to broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTotalDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total messages dequeued from broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTotalEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total bytes enqueued to broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTotalDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total bytes dequeued from broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgDepth";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Current number of messages on queues in broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteDepth";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Current number of bytes on queues in broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgPersistEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total persistent messages enqueued to broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgPersistDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total persistent messages dequeued from broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bytePersistEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total persistent bytes enqueued to broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "bytePersistDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total persistent bytes dequeued from broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTxnEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total transactional messages enqueued to broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgTxnDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total transactional messages dequeued from broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTxnEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total transactional bytes enqueued to broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteTxnDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total transactional bytes dequeued from broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgFtdEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total message bodies released from memory and flowed-to-disk on broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgFtdDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Total message bodies dequeued from the broker having been flowed-to-disk";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteFtdEnqueues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total bytes released from memory and flowed-to-disk on broker";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteFtdDequeues";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Total bytes dequeued from the broker having been flowed-to-disk";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "msgFtdDepth";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Current number of messages flowed-to-disk";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "byteFtdDepth";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "octet";
    ft[DESC] = "Current number of bytes flowed-to-disk";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "releases";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Acquired messages reinserted into the queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "acquires";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages acquired from the queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsNoRoute";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to no-route from exchange";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsTtl";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to TTL expiration";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsRing";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to ring-queue overflow";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsLvq";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to LVQ insert";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsOverflow";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to reject-policy overflow";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsSubscriber";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to subscriber reject";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "discardsPurge";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages discarded due to management purge";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "reroutes";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages dequeued to management re-route";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "abandoned";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages left in a deleted queue";
    buf.putMap(ft);

    ft.clear();
    ft[NAME] = "abandonedViaAlt";
    ft[TYPE] = TYPE_U64;
    ft[UNIT] = "message";
    ft[DESC] = "Messages routed to alternate exchange from a deleted queue";
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


void Broker::aggregatePerThreadStats(struct PerThreadStats* totals) const
{
    totals->queueCount = 0;
    totals->msgTotalEnqueues = 0;
    totals->msgTotalDequeues = 0;
    totals->byteTotalEnqueues = 0;
    totals->byteTotalDequeues = 0;
    totals->msgDepth = 0;
    totals->byteDepth = 0;
    totals->msgPersistEnqueues = 0;
    totals->msgPersistDequeues = 0;
    totals->bytePersistEnqueues = 0;
    totals->bytePersistDequeues = 0;
    totals->msgTxnEnqueues = 0;
    totals->msgTxnDequeues = 0;
    totals->byteTxnEnqueues = 0;
    totals->byteTxnDequeues = 0;
    totals->msgFtdEnqueues = 0;
    totals->msgFtdDequeues = 0;
    totals->byteFtdEnqueues = 0;
    totals->byteFtdDequeues = 0;
    totals->msgFtdDepth = 0;
    totals->byteFtdDepth = 0;
    totals->releases = 0;
    totals->acquires = 0;
    totals->discardsNoRoute = 0;
    totals->discardsTtl = 0;
    totals->discardsRing = 0;
    totals->discardsLvq = 0;
    totals->discardsOverflow = 0;
    totals->discardsSubscriber = 0;
    totals->discardsPurge = 0;
    totals->reroutes = 0;
    totals->abandoned = 0;
    totals->abandonedViaAlt = 0;

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
            totals->queueCount += threadStats->queueCount;
            totals->msgTotalEnqueues += threadStats->msgTotalEnqueues;
            totals->msgTotalDequeues += threadStats->msgTotalDequeues;
            totals->byteTotalEnqueues += threadStats->byteTotalEnqueues;
            totals->byteTotalDequeues += threadStats->byteTotalDequeues;
            totals->msgDepth += threadStats->msgDepth;
            totals->byteDepth += threadStats->byteDepth;
            totals->msgPersistEnqueues += threadStats->msgPersistEnqueues;
            totals->msgPersistDequeues += threadStats->msgPersistDequeues;
            totals->bytePersistEnqueues += threadStats->bytePersistEnqueues;
            totals->bytePersistDequeues += threadStats->bytePersistDequeues;
            totals->msgTxnEnqueues += threadStats->msgTxnEnqueues;
            totals->msgTxnDequeues += threadStats->msgTxnDequeues;
            totals->byteTxnEnqueues += threadStats->byteTxnEnqueues;
            totals->byteTxnDequeues += threadStats->byteTxnDequeues;
            totals->msgFtdEnqueues += threadStats->msgFtdEnqueues;
            totals->msgFtdDequeues += threadStats->msgFtdDequeues;
            totals->byteFtdEnqueues += threadStats->byteFtdEnqueues;
            totals->byteFtdDequeues += threadStats->byteFtdDequeues;
            totals->msgFtdDepth += threadStats->msgFtdDepth;
            totals->byteFtdDepth += threadStats->byteFtdDepth;
            totals->releases += threadStats->releases;
            totals->acquires += threadStats->acquires;
            totals->discardsNoRoute += threadStats->discardsNoRoute;
            totals->discardsTtl += threadStats->discardsTtl;
            totals->discardsRing += threadStats->discardsRing;
            totals->discardsLvq += threadStats->discardsLvq;
            totals->discardsOverflow += threadStats->discardsOverflow;
            totals->discardsSubscriber += threadStats->discardsSubscriber;
            totals->discardsPurge += threadStats->discardsPurge;
            totals->reroutes += threadStats->reroutes;
            totals->abandoned += threadStats->abandoned;
            totals->abandonedViaAlt += threadStats->abandonedViaAlt;

        }
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
    size += 1;  // mgmtPublish
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
    mgmtPublish = buf.getOctet()==1;
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
    buf.putOctet(mgmtPublish?1:0);
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

    for (int idx = 0; idx < maxThreads; idx++) {
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats != 0) {
        threadStats->msgDepth = (uint64_t) (threadStats->msgTotalEnqueues - threadStats->msgTotalDequeues);
        threadStats->byteDepth = (uint64_t) (threadStats->byteTotalEnqueues - threadStats->byteTotalDequeues);
        threadStats->msgFtdDepth = (uint64_t) (threadStats->msgFtdEnqueues - threadStats->msgFtdDequeues);
        threadStats->byteFtdDepth = (uint64_t) (threadStats->byteFtdEnqueues - threadStats->byteFtdDequeues);

        }
    }


    struct PerThreadStats totals;
    aggregatePerThreadStats(&totals);


    if (!skipHeaders) {
        std::string _tbuf;
        writeTimestamps (_tbuf);
        buf.putRawData(_tbuf);
    }

    buf.putLongLong(uptime);
    buf.putLongLong(totals.queueCount);
    buf.putLongLong(totals.msgTotalEnqueues);
    buf.putLongLong(totals.msgTotalDequeues);
    buf.putLongLong(totals.byteTotalEnqueues);
    buf.putLongLong(totals.byteTotalDequeues);
    buf.putLongLong(totals.msgDepth);
    buf.putLongLong(totals.byteDepth);
    buf.putLongLong(totals.msgPersistEnqueues);
    buf.putLongLong(totals.msgPersistDequeues);
    buf.putLongLong(totals.bytePersistEnqueues);
    buf.putLongLong(totals.bytePersistDequeues);
    buf.putLongLong(totals.msgTxnEnqueues);
    buf.putLongLong(totals.msgTxnDequeues);
    buf.putLongLong(totals.byteTxnEnqueues);
    buf.putLongLong(totals.byteTxnDequeues);
    buf.putLongLong(totals.msgFtdEnqueues);
    buf.putLongLong(totals.msgFtdDequeues);
    buf.putLongLong(totals.byteFtdEnqueues);
    buf.putLongLong(totals.byteFtdDequeues);
    buf.putLongLong(totals.msgFtdDepth);
    buf.putLongLong(totals.byteFtdDepth);
    buf.putLongLong(totals.releases);
    buf.putLongLong(totals.acquires);
    buf.putLongLong(totals.discardsNoRoute);
    buf.putLongLong(totals.discardsTtl);
    buf.putLongLong(totals.discardsRing);
    buf.putLongLong(totals.discardsLvq);
    buf.putLongLong(totals.discardsOverflow);
    buf.putLongLong(totals.discardsSubscriber);
    buf.putLongLong(totals.discardsPurge);
    buf.putLongLong(totals.reroutes);
    buf.putLongLong(totals.abandoned);
    buf.putLongLong(totals.abandonedViaAlt);


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
    _map["mgmtPublish"] = ::qpid::types::Variant(mgmtPublish);
    _map["mgmtPubInterval"] = ::qpid::types::Variant(mgmtPubInterval);
    _map["version"] = ::qpid::types::Variant(version);
    if (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) {
        _map["dataDir"] = ::qpid::types::Variant(dataDir);
    }

    }

    if (includeStatistics) {
        instChanged = false;

        for (int idx = 0; idx < maxThreads; idx++) {
            struct PerThreadStats* threadStats = perThreadStatsArray[idx];
            if (threadStats != 0) {
        threadStats->msgDepth = (uint64_t) (threadStats->msgTotalEnqueues - threadStats->msgTotalDequeues);
        threadStats->byteDepth = (uint64_t) (threadStats->byteTotalEnqueues - threadStats->byteTotalDequeues);
        threadStats->msgFtdDepth = (uint64_t) (threadStats->msgFtdEnqueues - threadStats->msgFtdDequeues);
        threadStats->byteFtdDepth = (uint64_t) (threadStats->byteFtdEnqueues - threadStats->byteFtdDequeues);

            }
        }


        struct PerThreadStats totals;
        aggregatePerThreadStats(&totals);



    _map["uptime"] = ::qpid::types::Variant(uptime);
    _map["queueCount"] = ::qpid::types::Variant(totals.queueCount);
    _map["msgTotalEnqueues"] = ::qpid::types::Variant(totals.msgTotalEnqueues);
    _map["msgTotalDequeues"] = ::qpid::types::Variant(totals.msgTotalDequeues);
    _map["byteTotalEnqueues"] = ::qpid::types::Variant(totals.byteTotalEnqueues);
    _map["byteTotalDequeues"] = ::qpid::types::Variant(totals.byteTotalDequeues);
    _map["msgDepth"] = ::qpid::types::Variant(totals.msgDepth);
    _map["byteDepth"] = ::qpid::types::Variant(totals.byteDepth);
    _map["msgPersistEnqueues"] = ::qpid::types::Variant(totals.msgPersistEnqueues);
    _map["msgPersistDequeues"] = ::qpid::types::Variant(totals.msgPersistDequeues);
    _map["bytePersistEnqueues"] = ::qpid::types::Variant(totals.bytePersistEnqueues);
    _map["bytePersistDequeues"] = ::qpid::types::Variant(totals.bytePersistDequeues);
    _map["msgTxnEnqueues"] = ::qpid::types::Variant(totals.msgTxnEnqueues);
    _map["msgTxnDequeues"] = ::qpid::types::Variant(totals.msgTxnDequeues);
    _map["byteTxnEnqueues"] = ::qpid::types::Variant(totals.byteTxnEnqueues);
    _map["byteTxnDequeues"] = ::qpid::types::Variant(totals.byteTxnDequeues);
    _map["msgFtdEnqueues"] = ::qpid::types::Variant(totals.msgFtdEnqueues);
    _map["msgFtdDequeues"] = ::qpid::types::Variant(totals.msgFtdDequeues);
    _map["byteFtdEnqueues"] = ::qpid::types::Variant(totals.byteFtdEnqueues);
    _map["byteFtdDequeues"] = ::qpid::types::Variant(totals.byteFtdDequeues);
    _map["msgFtdDepth"] = ::qpid::types::Variant(totals.msgFtdDepth);
    _map["byteFtdDepth"] = ::qpid::types::Variant(totals.byteFtdDepth);
    _map["releases"] = ::qpid::types::Variant(totals.releases);
    _map["acquires"] = ::qpid::types::Variant(totals.acquires);
    _map["discardsNoRoute"] = ::qpid::types::Variant(totals.discardsNoRoute);
    _map["discardsTtl"] = ::qpid::types::Variant(totals.discardsTtl);
    _map["discardsRing"] = ::qpid::types::Variant(totals.discardsRing);
    _map["discardsLvq"] = ::qpid::types::Variant(totals.discardsLvq);
    _map["discardsOverflow"] = ::qpid::types::Variant(totals.discardsOverflow);
    _map["discardsSubscriber"] = ::qpid::types::Variant(totals.discardsSubscriber);
    _map["discardsPurge"] = ::qpid::types::Variant(totals.discardsPurge);
    _map["reroutes"] = ::qpid::types::Variant(totals.reroutes);
    _map["abandoned"] = ::qpid::types::Variant(totals.abandoned);
    _map["abandonedViaAlt"] = ::qpid::types::Variant(totals.abandonedViaAlt);


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
    if ((_i = _map.find("mgmtPublish")) != _map.end()) {
        mgmtPublish = _i->second;
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
