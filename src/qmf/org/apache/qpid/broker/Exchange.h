
#ifndef _MANAGEMENT_EXCHANGE_
#define _MANAGEMENT_EXCHANGE_

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


class Exchange : public ::qpid::management::ManagementObject
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
    std::string type;
    bool durable;
    bool autoDelete;
    ::qpid::management::ObjectId altExchange;
    ::qpid::types::Variant::Map arguments;

    // Statistics
    uint32_t  producerCount;
    uint32_t  producerCountHigh;
    uint32_t  producerCountLow;
    uint32_t  bindingCount;
    uint32_t  bindingCountHigh;
    uint32_t  bindingCountLow;


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  msgReceives;
        uint64_t  msgDrops;
        uint64_t  msgRoutes;
        uint64_t  byteReceives;
        uint64_t  byteDrops;
        uint64_t  byteRoutes;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->msgReceives = 0;
            threadStats->msgDrops = 0;
            threadStats->msgRoutes = 0;
            threadStats->byteReceives = 0;
            threadStats->byteDrops = 0;
            threadStats->byteRoutes = 0;

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


    Exchange(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name);
    ~Exchange();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs

    // Accessor Methods
    inline void set_type (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        type = val;
        configChanged = true;
    }
    inline const std::string& get_type() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return type;
    }
    inline void set_durable (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        durable = val;
        configChanged = true;
    }
    inline bool get_durable() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return durable;
    }
    inline void set_autoDelete (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        autoDelete = val;
        configChanged = true;
    }
    inline bool get_autoDelete() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return autoDelete;
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
    inline void set_arguments (const ::qpid::types::Variant::Map& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        arguments = val;
        configChanged = true;
    }
    inline const ::qpid::types::Variant::Map& get_arguments() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return arguments;
    }
    inline void inc_producerCount (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        producerCount += by;
        if (producerCountHigh < producerCount)
            producerCountHigh = producerCount;
        instChanged = true;
    }
    inline void dec_producerCount (uint32_t by = 1) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        producerCount -= by;
        if (producerCountLow > producerCount)
            producerCountLow = producerCount;
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
    inline void inc_msgReceives (uint64_t by = 1) {
        getThreadStats()->msgReceives += by;
        instChanged = true;
    }
    inline void dec_msgReceives (uint64_t by = 1) {
        getThreadStats()->msgReceives -= by;
        instChanged = true;
    }
    inline void inc_msgDrops (uint64_t by = 1) {
        getThreadStats()->msgDrops += by;
        instChanged = true;
    }
    inline void dec_msgDrops (uint64_t by = 1) {
        getThreadStats()->msgDrops -= by;
        instChanged = true;
    }
    inline void inc_msgRoutes (uint64_t by = 1) {
        getThreadStats()->msgRoutes += by;
        instChanged = true;
    }
    inline void dec_msgRoutes (uint64_t by = 1) {
        getThreadStats()->msgRoutes -= by;
        instChanged = true;
    }
    inline void inc_byteReceives (uint64_t by = 1) {
        getThreadStats()->byteReceives += by;
        instChanged = true;
    }
    inline void dec_byteReceives (uint64_t by = 1) {
        getThreadStats()->byteReceives -= by;
        instChanged = true;
    }
    inline void inc_byteDrops (uint64_t by = 1) {
        getThreadStats()->byteDrops += by;
        instChanged = true;
    }
    inline void dec_byteDrops (uint64_t by = 1) {
        getThreadStats()->byteDrops -= by;
        instChanged = true;
    }
    inline void inc_byteRoutes (uint64_t by = 1) {
        getThreadStats()->byteRoutes += by;
        instChanged = true;
    }
    inline void dec_byteRoutes (uint64_t by = 1) {
        getThreadStats()->byteRoutes -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_EXCHANGE_*/
