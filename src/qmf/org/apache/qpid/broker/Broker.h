
#ifndef _MANAGEMENT_ORG_APACHE_QPID_BROKER_BROKER_
#define _MANAGEMENT_ORG_APACHE_QPID_BROKER_BROKER_

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


QPID_BROKER_CLASS_EXTERN class Broker : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_dataDir = 0;
    static const uint8_t presenceMask_dataDir = 1;



    // Properties
    std::string name;
    ::qpid::management::ObjectId systemRef;
    uint16_t port;
    uint16_t workerThreads;
    uint16_t maxConns;
    uint16_t connBacklog;
    uint32_t stagingThreshold;
    bool mgmtPublish;
    uint16_t mgmtPubInterval;
    std::string version;
    std::string dataDir;

    // Statistics
    uint64_t  uptime;


    // Per-Thread Statistics

 public:    
    struct PerThreadStats {
        uint64_t  queueCount;
        uint64_t  msgTotalEnqueues;
        uint64_t  msgTotalDequeues;
        uint64_t  byteTotalEnqueues;
        uint64_t  byteTotalDequeues;
        uint64_t  msgDepth;
        uint64_t  byteDepth;
        uint64_t  msgPersistEnqueues;
        uint64_t  msgPersistDequeues;
        uint64_t  bytePersistEnqueues;
        uint64_t  bytePersistDequeues;
        uint64_t  msgTxnEnqueues;
        uint64_t  msgTxnDequeues;
        uint64_t  byteTxnEnqueues;
        uint64_t  byteTxnDequeues;
        uint64_t  msgFtdEnqueues;
        uint64_t  msgFtdDequeues;
        uint64_t  byteFtdEnqueues;
        uint64_t  byteFtdDequeues;
        uint64_t  msgFtdDepth;
        uint64_t  byteFtdDepth;
        uint64_t  releases;
        uint64_t  acquires;
        uint64_t  discardsNoRoute;
        uint64_t  discardsTtl;
        uint64_t  discardsRing;
        uint64_t  discardsLvq;
        uint64_t  discardsOverflow;
        uint64_t  discardsSubscriber;
        uint64_t  discardsPurge;
        uint64_t  reroutes;
        uint64_t  abandoned;
        uint64_t  abandonedViaAlt;

    };
 private:

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->queueCount = 0;
            threadStats->msgTotalEnqueues = 0;
            threadStats->msgTotalDequeues = 0;
            threadStats->byteTotalEnqueues = 0;
            threadStats->byteTotalDequeues = 0;
            threadStats->msgDepth = 0;
            threadStats->byteDepth = 0;
            threadStats->msgPersistEnqueues = 0;
            threadStats->msgPersistDequeues = 0;
            threadStats->bytePersistEnqueues = 0;
            threadStats->bytePersistDequeues = 0;
            threadStats->msgTxnEnqueues = 0;
            threadStats->msgTxnDequeues = 0;
            threadStats->byteTxnEnqueues = 0;
            threadStats->byteTxnDequeues = 0;
            threadStats->msgFtdEnqueues = 0;
            threadStats->msgFtdDequeues = 0;
            threadStats->byteFtdEnqueues = 0;
            threadStats->byteFtdDequeues = 0;
            threadStats->msgFtdDepth = 0;
            threadStats->byteFtdDepth = 0;
            threadStats->releases = 0;
            threadStats->acquires = 0;
            threadStats->discardsNoRoute = 0;
            threadStats->discardsTtl = 0;
            threadStats->discardsRing = 0;
            threadStats->discardsLvq = 0;
            threadStats->discardsOverflow = 0;
            threadStats->discardsSubscriber = 0;
            threadStats->discardsPurge = 0;
            threadStats->reroutes = 0;
            threadStats->abandoned = 0;
            threadStats->abandonedViaAlt = 0;

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


    QPID_BROKER_EXTERN Broker(
        ::qpid::management::ManagementAgent* agent,
        ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name);

    QPID_BROKER_EXTERN ~Broker();

    

    QPID_BROKER_EXTERN static void registerSelf(
        ::qpid::management::ManagementAgent* agent);

    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    QPID_BROKER_EXTERN static const uint32_t METHOD_ECHO = 1;
    QPID_BROKER_EXTERN static const uint32_t METHOD_CONNECT = 2;
    QPID_BROKER_EXTERN static const uint32_t METHOD_QUEUEMOVEMESSAGES = 3;
    QPID_BROKER_EXTERN static const uint32_t METHOD_SETLOGLEVEL = 4;
    QPID_BROKER_EXTERN static const uint32_t METHOD_GETLOGLEVEL = 5;
    QPID_BROKER_EXTERN static const uint32_t METHOD_GETTIMESTAMPCONFIG = 6;
    QPID_BROKER_EXTERN static const uint32_t METHOD_SETTIMESTAMPCONFIG = 7;
    QPID_BROKER_EXTERN static const uint32_t METHOD_CREATE = 8;
    QPID_BROKER_EXTERN static const uint32_t METHOD_DELETE = 9;
    QPID_BROKER_EXTERN static const uint32_t METHOD_QUERY = 10;

    // Accessor Methods
    inline void set_systemRef (const ::qpid::management::ObjectId& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        systemRef = val;
        configChanged = true;
    }
    inline const ::qpid::management::ObjectId& get_systemRef() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return systemRef;
    }
    inline void set_port (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        port = val;
        configChanged = true;
    }
    inline uint16_t get_port() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return port;
    }
    inline void set_workerThreads (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        workerThreads = val;
        configChanged = true;
    }
    inline uint16_t get_workerThreads() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return workerThreads;
    }
    inline void set_maxConns (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        maxConns = val;
        configChanged = true;
    }
    inline uint16_t get_maxConns() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return maxConns;
    }
    inline void set_connBacklog (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        connBacklog = val;
        configChanged = true;
    }
    inline uint16_t get_connBacklog() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return connBacklog;
    }
    inline void set_stagingThreshold (uint32_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        stagingThreshold = val;
        configChanged = true;
    }
    inline uint32_t get_stagingThreshold() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return stagingThreshold;
    }
    inline void set_mgmtPublish (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        mgmtPublish = val;
        configChanged = true;
    }
    inline bool get_mgmtPublish() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return mgmtPublish;
    }
    inline void set_mgmtPubInterval (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        mgmtPubInterval = val;
        configChanged = true;
    }
    inline uint16_t get_mgmtPubInterval() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return mgmtPubInterval;
    }
    inline void set_version (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        version = val;
        configChanged = true;
    }
    inline const std::string& get_version() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return version;
    }
    inline void set_dataDir (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        dataDir = val;
        presenceMask[presenceByte_dataDir] |= presenceMask_dataDir;
        configChanged = true;
    }
    inline const std::string& get_dataDir() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return dataDir;
    }
    inline void clr_dataDir() {
        presenceMask[presenceByte_dataDir] &= ~presenceMask_dataDir;
        configChanged = true;
    }
    inline bool isSet_dataDir() {
        return (presenceMask[presenceByte_dataDir] & presenceMask_dataDir) != 0;
    }
    inline void set_uptime (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        uptime = val;
        instChanged = true;
    }
    inline uint64_t get_uptime() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return uptime;
    }
    inline void inc_queueCount (uint64_t by = 1) {
        getThreadStats()->queueCount += by;
        instChanged = true;
    }
    inline void dec_queueCount (uint64_t by = 1) {
        getThreadStats()->queueCount -= by;
        instChanged = true;
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
    inline void inc_discardsNoRoute (uint64_t by = 1) {
        getThreadStats()->discardsNoRoute += by;
        instChanged = true;
    }
    inline void dec_discardsNoRoute (uint64_t by = 1) {
        getThreadStats()->discardsNoRoute -= by;
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
    inline void inc_abandoned (uint64_t by = 1) {
        getThreadStats()->abandoned += by;
        instChanged = true;
    }
    inline void dec_abandoned (uint64_t by = 1) {
        getThreadStats()->abandoned -= by;
        instChanged = true;
    }
    inline void inc_abandonedViaAlt (uint64_t by = 1) {
        getThreadStats()->abandonedViaAlt += by;
        instChanged = true;
    }
    inline void dec_abandonedViaAlt (uint64_t by = 1) {
        getThreadStats()->abandonedViaAlt -= by;
        instChanged = true;
    }



    struct PerThreadStats* getStatistics() { return getThreadStats(); }
    void statisticsUpdated() { instChanged = true; }

};

}}}}}

#endif  /*!_MANAGEMENT_BROKER_*/
