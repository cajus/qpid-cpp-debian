
#ifndef _MANAGEMENT_ORG_APACHE_QPID_BROKER_MEMORY_
#define _MANAGEMENT_ORG_APACHE_QPID_BROKER_MEMORY_

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


QPID_BROKER_CLASS_EXTERN class Memory : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_malloc_arena = 0;
    static const uint8_t presenceMask_malloc_arena = 1;
    static const uint8_t presenceByte_malloc_ordblks = 0;
    static const uint8_t presenceMask_malloc_ordblks = 2;
    static const uint8_t presenceByte_malloc_hblks = 0;
    static const uint8_t presenceMask_malloc_hblks = 4;
    static const uint8_t presenceByte_malloc_hblkhd = 0;
    static const uint8_t presenceMask_malloc_hblkhd = 8;
    static const uint8_t presenceByte_malloc_uordblks = 0;
    static const uint8_t presenceMask_malloc_uordblks = 16;
    static const uint8_t presenceByte_malloc_fordblks = 0;
    static const uint8_t presenceMask_malloc_fordblks = 32;
    static const uint8_t presenceByte_malloc_keepcost = 0;
    static const uint8_t presenceMask_malloc_keepcost = 64;



    // Properties
    std::string name;
    uint64_t malloc_arena;
    uint64_t malloc_ordblks;
    uint64_t malloc_hblks;
    uint64_t malloc_hblkhd;
    uint64_t malloc_uordblks;
    uint64_t malloc_fordblks;
    uint64_t malloc_keepcost;

    // Statistics


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

    // Stub for getInstChanged.  There are no statistics in this class.
    bool getInstChanged() { return false; }
    bool hasInst() { return false; }


    QPID_BROKER_EXTERN Memory(
        ::qpid::management::ManagementAgent* agent,
        ::qpid::management::Manageable* coreObject, const std::string& _name);

    QPID_BROKER_EXTERN ~Memory();

    

    QPID_BROKER_EXTERN static void registerSelf(
        ::qpid::management::ManagementAgent* agent);

    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs

    // Accessor Methods
    inline void set_malloc_arena (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_arena = val;
        presenceMask[presenceByte_malloc_arena] |= presenceMask_malloc_arena;
        configChanged = true;
    }
    inline uint64_t get_malloc_arena() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_arena;
    }
    inline void clr_malloc_arena() {
        presenceMask[presenceByte_malloc_arena] &= ~presenceMask_malloc_arena;
        configChanged = true;
    }
    inline bool isSet_malloc_arena() {
        return (presenceMask[presenceByte_malloc_arena] & presenceMask_malloc_arena) != 0;
    }
    inline void set_malloc_ordblks (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_ordblks = val;
        presenceMask[presenceByte_malloc_ordblks] |= presenceMask_malloc_ordblks;
        configChanged = true;
    }
    inline uint64_t get_malloc_ordblks() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_ordblks;
    }
    inline void clr_malloc_ordblks() {
        presenceMask[presenceByte_malloc_ordblks] &= ~presenceMask_malloc_ordblks;
        configChanged = true;
    }
    inline bool isSet_malloc_ordblks() {
        return (presenceMask[presenceByte_malloc_ordblks] & presenceMask_malloc_ordblks) != 0;
    }
    inline void set_malloc_hblks (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_hblks = val;
        presenceMask[presenceByte_malloc_hblks] |= presenceMask_malloc_hblks;
        configChanged = true;
    }
    inline uint64_t get_malloc_hblks() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_hblks;
    }
    inline void clr_malloc_hblks() {
        presenceMask[presenceByte_malloc_hblks] &= ~presenceMask_malloc_hblks;
        configChanged = true;
    }
    inline bool isSet_malloc_hblks() {
        return (presenceMask[presenceByte_malloc_hblks] & presenceMask_malloc_hblks) != 0;
    }
    inline void set_malloc_hblkhd (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_hblkhd = val;
        presenceMask[presenceByte_malloc_hblkhd] |= presenceMask_malloc_hblkhd;
        configChanged = true;
    }
    inline uint64_t get_malloc_hblkhd() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_hblkhd;
    }
    inline void clr_malloc_hblkhd() {
        presenceMask[presenceByte_malloc_hblkhd] &= ~presenceMask_malloc_hblkhd;
        configChanged = true;
    }
    inline bool isSet_malloc_hblkhd() {
        return (presenceMask[presenceByte_malloc_hblkhd] & presenceMask_malloc_hblkhd) != 0;
    }
    inline void set_malloc_uordblks (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_uordblks = val;
        presenceMask[presenceByte_malloc_uordblks] |= presenceMask_malloc_uordblks;
        configChanged = true;
    }
    inline uint64_t get_malloc_uordblks() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_uordblks;
    }
    inline void clr_malloc_uordblks() {
        presenceMask[presenceByte_malloc_uordblks] &= ~presenceMask_malloc_uordblks;
        configChanged = true;
    }
    inline bool isSet_malloc_uordblks() {
        return (presenceMask[presenceByte_malloc_uordblks] & presenceMask_malloc_uordblks) != 0;
    }
    inline void set_malloc_fordblks (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_fordblks = val;
        presenceMask[presenceByte_malloc_fordblks] |= presenceMask_malloc_fordblks;
        configChanged = true;
    }
    inline uint64_t get_malloc_fordblks() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_fordblks;
    }
    inline void clr_malloc_fordblks() {
        presenceMask[presenceByte_malloc_fordblks] &= ~presenceMask_malloc_fordblks;
        configChanged = true;
    }
    inline bool isSet_malloc_fordblks() {
        return (presenceMask[presenceByte_malloc_fordblks] & presenceMask_malloc_fordblks) != 0;
    }
    inline void set_malloc_keepcost (uint64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        malloc_keepcost = val;
        presenceMask[presenceByte_malloc_keepcost] |= presenceMask_malloc_keepcost;
        configChanged = true;
    }
    inline uint64_t get_malloc_keepcost() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return malloc_keepcost;
    }
    inline void clr_malloc_keepcost() {
        presenceMask[presenceByte_malloc_keepcost] &= ~presenceMask_malloc_keepcost;
        configChanged = true;
    }
    inline bool isSet_malloc_keepcost() {
        return (presenceMask[presenceByte_malloc_keepcost] & presenceMask_malloc_keepcost) != 0;
    }



};

}}}}}

#endif  /*!_MANAGEMENT_MEMORY_*/
