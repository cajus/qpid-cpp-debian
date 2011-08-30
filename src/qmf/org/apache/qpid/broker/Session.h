
#ifndef _MANAGEMENT_SESSION_
#define _MANAGEMENT_SESSION_

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


class Session : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_expireTime = 0;
    static const uint8_t presenceMask_expireTime = 1;
    static const uint8_t presenceByte_maxClientRate = 0;
    static const uint8_t presenceMask_maxClientRate = 2;



    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string name;
    uint16_t channelId;
    ::qpid::management::ObjectId connectionRef;
    uint32_t detachedLifespan;
    bool attached;
    int64_t expireTime;
    uint32_t maxClientRate;

    // Statistics


    // Per-Thread Statistics
    struct PerThreadStats {
        uint32_t  framesOutstanding;
        uint64_t  TxnStarts;
        uint64_t  TxnCommits;
        uint64_t  TxnRejects;
        uint32_t  TxnCount;
        uint32_t  clientCredit;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->framesOutstanding = 0;
            threadStats->TxnStarts = 0;
            threadStats->TxnCommits = 0;
            threadStats->TxnRejects = 0;
            threadStats->TxnCount = 0;
            threadStats->clientCredit = 0;

        }
        return threadStats;
    }

    void aggregatePerThreadStats(struct PerThreadStats*) const;

  public:
    static void writeSchema(std::string& schema);
    void mapEncodeValues(::qpid::types::Variant::Map& map,
                         bool includeProperties=true,
                         bool includeStatistics=true);
    void mapDecodeValues(const ::qpid::types::Variant::Map& map);
    void doMethod(std::string&           methodName,
                  const ::qpid::types::Variant::Map& inMap,
                  ::qpid::types::Variant::Map& outMap,
                  const std::string& userId);
    std::string getKey() const;

    uint32_t writePropertiesSize() const;
    void readProperties(const std::string& buf);
    void writeProperties(std::string& buf) const;
    void writeStatistics(std::string& buf, bool skipHeaders = false);
    void doMethod(std::string& methodName,
                  const std::string& inBuf,
                  std::string& outBuf,
                  const std::string& userId);


    writeSchemaCall_t getWriteSchemaCall() { return writeSchema; }


    Session(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name);
    ~Session();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_SOLICITACK = 1;
    static const uint32_t METHOD_DETACH = 2;
    static const uint32_t METHOD_RESETLIFESPAN = 3;
    static const uint32_t METHOD_CLOSE = 4;

    // Accessor Methods
    inline void set_channelId (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        channelId = val;
        configChanged = true;
    }
    inline uint16_t get_channelId() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return channelId;
    }
    inline void set_connectionRef (const ::qpid::management::ObjectId& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        connectionRef = val;
        configChanged = true;
    }
    inline const ::qpid::management::ObjectId& get_connectionRef() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return connectionRef;
    }
    inline void set_detachedLifespan (uint32_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        detachedLifespan = val;
        configChanged = true;
    }
    inline uint32_t get_detachedLifespan() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return detachedLifespan;
    }
    inline void set_attached (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        attached = val;
        configChanged = true;
    }
    inline bool get_attached() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return attached;
    }
    inline void set_expireTime (int64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        expireTime = val;
        presenceMask[presenceByte_expireTime] |= presenceMask_expireTime;
        configChanged = true;
    }
    inline int64_t get_expireTime() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return expireTime;
    }
    inline void clr_expireTime() {
        presenceMask[presenceByte_expireTime] &= ~presenceMask_expireTime;
        configChanged = true;
    }
    inline bool isSet_expireTime() {
        return (presenceMask[presenceByte_expireTime] & presenceMask_expireTime) != 0;
    }
    inline void set_maxClientRate (uint32_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        maxClientRate = val;
        presenceMask[presenceByte_maxClientRate] |= presenceMask_maxClientRate;
        configChanged = true;
    }
    inline uint32_t get_maxClientRate() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return maxClientRate;
    }
    inline void clr_maxClientRate() {
        presenceMask[presenceByte_maxClientRate] &= ~presenceMask_maxClientRate;
        configChanged = true;
    }
    inline bool isSet_maxClientRate() {
        return (presenceMask[presenceByte_maxClientRate] & presenceMask_maxClientRate) != 0;
    }
    inline void inc_framesOutstanding (uint32_t by = 1) {
        getThreadStats()->framesOutstanding += by;
        instChanged = true;
    }
    inline void dec_framesOutstanding (uint32_t by = 1) {
        getThreadStats()->framesOutstanding -= by;
        instChanged = true;
    }
    inline void inc_TxnStarts (uint64_t by = 1) {
        getThreadStats()->TxnStarts += by;
        instChanged = true;
    }
    inline void dec_TxnStarts (uint64_t by = 1) {
        getThreadStats()->TxnStarts -= by;
        instChanged = true;
    }
    inline void inc_TxnCommits (uint64_t by = 1) {
        getThreadStats()->TxnCommits += by;
        instChanged = true;
    }
    inline void dec_TxnCommits (uint64_t by = 1) {
        getThreadStats()->TxnCommits -= by;
        instChanged = true;
    }
    inline void inc_TxnRejects (uint64_t by = 1) {
        getThreadStats()->TxnRejects += by;
        instChanged = true;
    }
    inline void dec_TxnRejects (uint64_t by = 1) {
        getThreadStats()->TxnRejects -= by;
        instChanged = true;
    }
    inline void inc_TxnCount (uint32_t by = 1) {
        getThreadStats()->TxnCount += by;
        instChanged = true;
    }
    inline void dec_TxnCount (uint32_t by = 1) {
        getThreadStats()->TxnCount -= by;
        instChanged = true;
    }
    inline void inc_clientCredit (uint32_t by = 1) {
        getThreadStats()->clientCredit += by;
        instChanged = true;
    }
    inline void dec_clientCredit (uint32_t by = 1) {
        getThreadStats()->clientCredit -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_SESSION_*/
