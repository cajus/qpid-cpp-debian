
#ifndef _MANAGEMENT_ACL_
#define _MANAGEMENT_ACL_

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
namespace acl {


class Acl : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];


    // Properties
    ::qpid::management::ObjectId brokerRef;
    std::string policyFile;
    bool enforcingAcl;
    bool transferAcl;
    int64_t lastAclLoad;

    // Statistics


    // Per-Thread Statistics
    struct PerThreadStats {
        uint64_t  aclDenyCount;

    };

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->aclDenyCount = 0;

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


    Acl(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent);
    ~Acl();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_RELOADACLFILE = 1;

    // Accessor Methods
    inline void set_brokerRef (const ::qpid::management::ObjectId& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        brokerRef = val;
        configChanged = true;
    }
    inline const ::qpid::management::ObjectId& get_brokerRef() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return brokerRef;
    }
    inline void set_policyFile (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        policyFile = val;
        configChanged = true;
    }
    inline const std::string& get_policyFile() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return policyFile;
    }
    inline void set_enforcingAcl (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        enforcingAcl = val;
        configChanged = true;
    }
    inline bool get_enforcingAcl() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return enforcingAcl;
    }
    inline void set_transferAcl (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        transferAcl = val;
        configChanged = true;
    }
    inline bool get_transferAcl() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return transferAcl;
    }
    inline void set_lastAclLoad (int64_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        lastAclLoad = val;
        configChanged = true;
    }
    inline int64_t get_lastAclLoad() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return lastAclLoad;
    }
    inline void inc_aclDenyCount (uint64_t by = 1) {
        getThreadStats()->aclDenyCount += by;
        instChanged = true;
    }
    inline void dec_aclDenyCount (uint64_t by = 1) {
        getThreadStats()->aclDenyCount -= by;
        instChanged = true;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_ACL_*/
