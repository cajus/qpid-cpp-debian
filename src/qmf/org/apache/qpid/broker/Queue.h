
#ifndef _MANAGEMENT_ORG_APACHE_QPID_BROKER_QUEUE_
#define _MANAGEMENT_ORG_APACHE_QPID_BROKER_QUEUE_

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

#include "qpid/management/ManagementObject.h"
#include "qmf/BrokerImportExport.h"

namespace qpid {
    namespace management {
        class ManagementAgent;
    }
}

namespace qmf {
namespace org {
namespace apache {
namespace qpid {
namespace broker {


QPID_BROKER_CLASS_EXTERN class Queue : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_altExchange = 0;
    static const uint8_t presenceMask_altExchange = 1;



    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string name;
    bool durable;
    bool autoDelete;
    bool exclusive;
    ::qpid::types::Variant::Map arguments;
    ::qpid::management::ObjectId altExchange;

    // Statistics
    uint32_t  consumerCount;
    uint32_t  consumerCountHigh;
    uint32_t  consumerCountLow;
    uint32_t  bindingCount;
    uint32_t  bindingCountHigh;
    uint32_t  bindingCountLow;
    uint32_t  unackedMessages;
    uint32_t  unackedMessagesHigh;
    uint32_t  unackedMessagesLow;
    bool  flowStopped;


    // Per-Thread Statistics

 public:    
    struct PerThreadStats {
        uint64_t  msgTotalEnqueues;
        uint64_t  msgTotalDequeues;
        uint64_t  msgTxnEnqueues;
        uint64_t  msgTxnDequeues;
        uint64_t  msgPersistEnqueues;
        uint64_t  msgPersistDequeues;
        uint64_t  msgDepth;
        uint64_t  byteDepth;
        uint64_t  byteTotalEnqueues;
        uint64_t  byteTotalDequeues;
        uint64_t  byteTxnEnqueues;
        uint64_t  byteTxnDequeues;
        uint64_t  bytePersistEnqueues;
        uint64_t  bytePersistDequeues;
        uint64_t  msgFtdEnqueues;
        uint64_t  msgFtdDequeues;
        uint64_t  byteFtdEnqueues;
        uint64_t  byteFtdDequeues;
        uint64_t  msgFtdDepth;
        uint64_t  byteFtdDepth;
        uint64_t  releases;
        uint64_t  acquires;
        uint64_t  discardsTtl;
        uint64_t  discardsRing;
        uint64_t  discardsLvq;
        uint64_t  discardsOverflow;
        uint64_t  discardsSubscriber;
        uint64_t  discardsPurge;
        uint64_t  reroutes;
        uint64_t  messageLatencyCount;
        uint64_t  messageLatencyTotal;
        uint64_t  messageLatencyMin;
        uint64_t  messageLatencyMax;
        uint32_t  flowStoppedCount;

    };
 private:

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->msgTotalEnqueues = 0;
            threadStats->msgTotalDequeues = 0;
            threadStats->msgTxnEnqueues = 0;
            threadStats->msgTxnDequeues = 0;
            threadStats->msgPersistEnqueues = 0;
            threadStats->msgPersistDequeues = 0;
            threadStats->msgDepth = 0;
            threadStats->byteDepth = 0;
            threadStats->byteTotalEnqueues = 0;
            threadStats->byteTotalDequeues = 0;
            threadStats->byteTxnEnqueues = 0;
            threadStats->byteTxnDequeues = 0;
            threadStats->bytePersistEnqueues = 0;
            threadStats->bytePersistDequeues = 0;
            threadStats->msgFtdEnqueues = 0;
            threadStats->msgFtdDequeues = 0;
            threadStats->byteFtdEnqueues = 0;
            threadStats->byteFtdDequeues = 0;
            threadStats->msgFtdDepth = 0;
            threadStats->byteFtdDepth = 0;
            threadStats->releases = 0;
            threadStats->acquires = 0;
            threadStats->discardsTtl = 0;
            threadStats->discardsRing = 0;
            threadStats->discardsLvq = 0;
            threadStats->discardsOverflow = 0;
            threadStats->discardsSubscriber = 0;
            threadStats->discardsPurge = 0;
            threadStats->reroutes = 0;
            threadStats->messageLatencyCount = 0;
            threadStats->messageLatencyMin   = std::numeric_limits<uint64_t>::max();
            threadStats->messageLatencyMax   = std::numeric_limits<uint64_t>::min();
            threadStats->messageLatencyTotal = 0;
            threadStats->flowStoppedCount = 0;

        }
        return threadStats;
    }

    void aggregatePerThreadStats(struct PerThreadStats*) const;

  public:
    QPID_BROKER_EXTERN static void writeSchema(std::string& schema);
    QPID_BROKER_EXTERN void mapEncodeValues(::qpid::types::Variant::Map& map,
                                          bool includeProperties=true,
                                          bool includeStatistics=true);
    QPID_BROKER_EXTERN void mapDecodeValues(const ::qpid::types::Variant::Map& map);
    QPID_BROKER_EXTERN void doMethod(std::string&           methodName,
                                   const ::qpid::types::Variant::Map& inMap,
                                   ::qpid::types::Variant::Map& outMap,
                                   const std::string& userId);
    QPID_BROKER_EXTERN std::string getKey() const;

    QPID_BROKER_EXTERN uint32_t writePropertiesSize() const;
    QPID_BROKER_EXTERN void readProperties(const std::string& buf);
    QPID_BROKER_EXTERN void writeProperties(std::string& buf) const;
    QPID_BROKER_EXTERN void writeStatistics(std::string& buf, bool skipHeaders = false);
    QPID_BROKER_EXTERN void doMethod(std::string& methodName,
                                   const std::string& inBuf,
                                   std::string& outBuf,
                                   const std::string& userId);


    writeSchemaCall_t getWriteSchemaCall() { return writeSchema; }


    QPID_BROKER_EXTERN Queue(
        ::qpid::management::ManagementAgent* agent,
        ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name, bool _durable, bool _autoDelete, bool _exclusive);

    QPID_BROKER_EXTERN ~Queue();

    

    QPID_BROKER_EXTERN static void registerSelf(
        ::qpid::management::ManagementAgent* agent);

    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    QPID_BROKER_EXTERN static const uint32_t METHOD_PURGE = 1;
    QPID_BROKER_EXTERN static const uint32_t METHOD_REROUTE = 2;

    // Accessor Methods
    inline void set_arguments (const ::qpid::types::Variant::Map& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        arguments = val;
        configChanged = true;
    }
    inline const ::qpid::types::Variant::Map& get_arguments() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return arguments;
    }
    inline void set_altExchange (const ::qpid::management::ObjectId& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        altExchange = val;
        presenceMask[presenceByte_altExchange] |= presenceMask_altExchange;
        configChanged = true;
    }
    inline const ::qpid::management::ObjectId& get_altExchange() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return altExchange;
    }
    inline void clr_altExchange() {
        presenceMask[presenceByte_altExchange] &= ~presenceMask_altExchange;
        configChanged = true;
    }
    inline bool isSet_altExchange() {
        return (presenceMask[presenceByte_altExchange] & presenceMask_altExchange) != 0;
    }
    inline void inc_msgTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTotalEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTotalEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgTotalDequeues (uint64_t by = 1) {
        getThreadStats()->msgTotalDequeues += by;
        instChanged = true;
    }
    inline void dec_msgTotalDequeues (uint64_t by = 1) {
        getThreadStats()->msgTotalDequeues -= by;
        instChanged = true;
    }
    inline void inc_msgTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTxnEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->msgTxnEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgTxnDequeues (uint64_t by = 1) {
        getThreadStats()->msgTxnDequeues += by;
        instChanged = true;
    }
    inline void dec_msgTxnDequeues (uint64_t by = 1) {
        getThreadStats()->msgTxnDequeues -= by;
        instChanged = true;
    }
    inline void inc_msgPersistEnqueues (uint64_t by = 1) {
        getThreadStats()->msgPersistEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgPersistEnqueues (uint64_t by = 1) {
        getThreadStats()->msgPersistEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgPersistDequeues (uint64_t by = 1) {
        getThreadStats()->msgPersistDequeues += by;
        instChanged = true;
    }
    inline void dec_msgPersistDequeues (uint64_t by = 1) {
        getThreadStats()->msgPersistDequeues -= by;
        instChanged = true;
    }
    inline void inc_byteTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTotalEnqueues += by;
        instChanged = true;
    }
    inline void dec_byteTotalEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTotalEnqueues -= by;
        instChanged = true;
    }
    inline void inc_byteTotalDequeues (uint64_t by = 1) {
        getThreadStats()->byteTotalDequeues += by;
        instChanged = true;
    }
    inline void dec_byteTotalDequeues (uint64_t by = 1) {
        getThreadStats()->byteTotalDequeues -= by;
        instChanged = true;
    }
    inline void inc_byteTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTxnEnqueues += by;
        instChanged = true;
    }
    inline void dec_byteTxnEnqueues (uint64_t by = 1) {
        getThreadStats()->byteTxnEnqueues -= by;
        instChanged = true;
    }
    inline void inc_byteTxnDequeues (uint64_t by = 1) {
        getThreadStats()->byteTxnDequeues += by;
        instChanged = true;
    }
    inline void dec_byteTxnDequeues (uint64_t by = 1) {
        getThreadStats()->byteTxnDequeues -= by;
        instChanged = true;
    }
    inline void inc_bytePersistEnqueues (uint64_t by = 1) {
        getThreadStats()->bytePersistEnqueues += by;
        instChanged = true;
    }
    inline void dec_bytePersistEnqueues (uint64_t by = 1) {
        getThreadStats()->bytePersistEnqueues -= by;
        instChanged = true;
    }
    inline void inc_bytePersistDequeues (uint64_t by = 1) {
        getThreadStats()->bytePersistDequeues += by;
        instChanged = true;
    }
    inline void dec_bytePersistDequeues (uint64_t by = 1) {
        getThreadStats()->bytePersistDequeues -= by;
        instChanged = true;
    }
    inline void inc_msgFtdEnqueues (uint64_t by = 1) {
        getThreadStats()->msgFtdEnqueues += by;
        instChanged = true;
    }
    inline void dec_msgFtdEnqueues (uint64_t by = 1) {
        getThreadStats()->msgFtdEnqueues -= by;
        instChanged = true;
    }
    inline void inc_msgFtdDequeues (uint64_t by = 1) {
        getThreadStats()->msgFtdDequeues += by;
        instChanged = true;
    }
    inline void dec_msgFtdDequeues (uint64_t by = 1) {
        getThreadStats()->msgFtdDequeues -= by;
        instChanged = true;
    }
    inline void inc_byteFtdEnqueues (uint64_t by = 1) {
        getThreadStats()->byteFtdEnqueues += by;
        instChanged = true;
    }
    inline void dec_byteFtdEnqueues (uint64_t by = 1) {
        getThreadStats()->byteFtdEnqueues -= by;
        instChanged = true;
    }
    inline void inc_byteFtdDequeues (uint64_t by = 1) {
        getThreadStats()->byteFtdDequeues += by;
        instChanged = true;
    }
    inline void dec_byteFtdDequeues (uint64_t by = 1) {
        getThreadStats()->byteFtdDequeues -= by;
        instChanged = true;
    }
    inline void inc_releases (uint64_t by = 1) {
        getThreadStats()->releases += by;
        instChanged = true;
    }
    inline void dec_releases (uint64_t by = 1) {
        getThreadStats()->releases -= by;
        instChanged = true;
    }
    inline void inc_acquires (uint64_t by = 1) {
        getThreadStats()->acquires += by;
        instChanged = true;
    }
    inline void dec_acquires (uint64_t by = 1) {
        getThreadStats()->acquires -= by;
        instChanged = true;
    }
    inline void inc_discardsTtl (uint64_t by = 1) {
        getThreadStats()->discardsTtl += by;
        instChanged = true;
    }
    inline void dec_discardsTtl (uint64_t by = 1) {
        getThreadStats()->discardsTtl -= by;
        instChanged = true;
    }
    inline void inc_discardsRing (uint64_t by = 1) {
        getThreadStats()->discardsRing += by;
        instChanged = true;
    }
    inline void dec_discardsRing (uint64_t by = 1) {
        getThreadStats()->discardsRing -= by;
        instChanged = true;
    }
    inline void inc_discardsLvq (uint64_t by = 1) {
        getThreadStats()->discardsLvq += by;
        instChanged = true;
    }
    inline void dec_discardsLvq (uint64_t by = 1) {
        getThreadStats()->discardsLvq -= by;
        instChanged = true;
    }
    inline void inc_discardsOverflow (uint64_t by = 1) {
        getThreadStats()->discardsOverflow += by;
        instChanged = true;
    }
    inline void dec_discardsOverflow (uint64_t by = 1) {
        getThreadStats()->discardsOverflow -= by;
        instChanged = true;
    }
    inline void inc_discardsSubscriber (uint64_t by = 1) {
        getThreadStats()->discardsSubscriber += by;
        instChanged = true;
    }
    inline void dec_discardsSubscriber (uint64_t by = 1) {
        getThreadStats()->discardsSubscriber -= by;
        instChanged = true;
    }
    inline void inc_discardsPurge (uint64_t by = 1) {
        getThreadStats()->discardsPurge += by;
        instChanged = true;
    }
    inline void dec_discardsPurge (uint64_t by = 1) {
        getThreadStats()->discardsPurge -= by;
        instChanged = true;
    }
    inline void inc_reroutes (uint64_t by = 1) {
        getThreadStats()->reroutes += by;
        instChanged = true;
    }
    inline void dec_reroutes (uint64_t by = 1) {
        getThreadStats()->reroutes -= by;
        instChanged = true;
    }
    inline void inc_consumerCount (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        consumerCount += by;
        if (consumerCountHigh < consumerCount)
            consumerCountHigh = consumerCount;
        instChanged = true;
    }
    inline void dec_consumerCount (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        consumerCount -= by;
        if (consumerCountLow > consumerCount)
            consumerCountLow = consumerCount;
        instChanged = true;
    }
    inline void inc_bindingCount (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        bindingCount += by;
        if (bindingCountHigh < bindingCount)
            bindingCountHigh = bindingCount;
        instChanged = true;
    }
    inline void dec_bindingCount (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        bindingCount -= by;
        if (bindingCountLow > bindingCount)
            bindingCountLow = bindingCount;
        instChanged = true;
    }
    inline void inc_unackedMessages (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        unackedMessages += by;
        if (unackedMessagesHigh < unackedMessages)
            unackedMessagesHigh = unackedMessages;
        instChanged = true;
    }
    inline void dec_unackedMessages (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        unackedMessages -= by;
        if (unackedMessagesLow > unackedMessages)
            unackedMessagesLow = unackedMessages;
        instChanged = true;
    }
    inline void set_messageLatency (uint64_t val) {
        getThreadStats()->messageLatencyCount++;
        getThreadStats()->messageLatencyTotal += val;
        if (getThreadStats()->messageLatencyMin > val)
            getThreadStats()->messageLatencyMin = val;
        if (getThreadStats()->messageLatencyMax < val)
            getThreadStats()->messageLatencyMax = val;
        instChanged = true;
    }
    inline void set_flowStopped (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        flowStopped = val;
        instChanged = true;
    }
    inline bool get_flowStopped() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return flowStopped;
    }
    inline void inc_flowStoppedCount (uint32_t by = 1) {
        getThreadStats()->flowStoppedCount += by;
        instChanged = true;
    }
    inline void dec_flowStoppedCount (uint32_t by = 1) {
        getThreadStats()->flowStoppedCount -= by;
        instChanged = true;
    }



    struct PerThreadStats* getStatistics() { return getThreadStats(); }
    void statisticsUpdated() { instChanged = true; }

};

}}}}}

#endif  /*!_MANAGEMENT_QUEUE_*/
