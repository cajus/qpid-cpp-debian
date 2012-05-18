
#ifndef _MANAGEMENT_ORG_APACHE_QPID_BROKER_CONNECTION_
#define _MANAGEMENT_ORG_APACHE_QPID_BROKER_CONNECTION_

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


QPID_BROKER_CLASS_EXTERN class Connection : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];

    uint8_t presenceMask[1];
    static const uint8_t presenceByte_remoteProcessName = 0;
    static const uint8_t presenceMask_remoteProcessName = 1;
    static const uint8_t presenceByte_remotePid = 0;
    static const uint8_t presenceMask_remotePid = 2;
    static const uint8_t presenceByte_remoteParentPid = 0;
    static const uint8_t presenceMask_remoteParentPid = 4;



    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string address;
    bool incoming;
    bool SystemConnection;
    bool userProxyAuth;
    bool federationLink;
    std::string authIdentity;
    std::string remoteProcessName;
    uint32_t remotePid;
    uint32_t remoteParentPid;
    bool shadow;
    std::string saslMechanism;
    uint16_t saslSsf;

    // Statistics
    bool  closing;


    // Per-Thread Statistics

 public:    
    struct PerThreadStats {
        uint64_t  framesFromClient;
        uint64_t  framesToClient;
        uint64_t  bytesFromClient;
        uint64_t  bytesToClient;
        uint64_t  msgsFromClient;
        uint64_t  msgsToClient;

    };
 private:

    struct PerThreadStats** perThreadStatsArray;

    inline struct PerThreadStats* getThreadStats() {
        int idx = getThreadIndex();
        struct PerThreadStats* threadStats = perThreadStatsArray[idx];
        if (threadStats == 0) {
            threadStats = new(PerThreadStats);
            perThreadStatsArray[idx] = threadStats;
            threadStats->framesFromClient = 0;
            threadStats->framesToClient = 0;
            threadStats->bytesFromClient = 0;
            threadStats->bytesToClient = 0;
            threadStats->msgsFromClient = 0;
            threadStats->msgsToClient = 0;

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


    QPID_BROKER_EXTERN Connection(
        ::qpid::management::ManagementAgent* agent,
        ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _address, bool _incoming, bool _SystemConnection);

    QPID_BROKER_EXTERN ~Connection();

    

    QPID_BROKER_EXTERN static void registerSelf(
        ::qpid::management::ManagementAgent* agent);

    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    QPID_BROKER_EXTERN static const uint32_t METHOD_CLOSE = 1;

    // Accessor Methods
    inline void set_userProxyAuth (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        userProxyAuth = val;
        configChanged = true;
    }
    inline bool get_userProxyAuth() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return userProxyAuth;
    }
    inline void set_federationLink (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        federationLink = val;
        configChanged = true;
    }
    inline bool get_federationLink() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return federationLink;
    }
    inline void set_authIdentity (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        authIdentity = val;
        configChanged = true;
    }
    inline const std::string& get_authIdentity() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return authIdentity;
    }
    inline void set_remoteProcessName (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        remoteProcessName = val;
        presenceMask[presenceByte_remoteProcessName] |= presenceMask_remoteProcessName;
        configChanged = true;
    }
    inline const std::string& get_remoteProcessName() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return remoteProcessName;
    }
    inline void clr_remoteProcessName() {
        presenceMask[presenceByte_remoteProcessName] &= ~presenceMask_remoteProcessName;
        configChanged = true;
    }
    inline bool isSet_remoteProcessName() {
        return (presenceMask[presenceByte_remoteProcessName] & presenceMask_remoteProcessName) != 0;
    }
    inline void set_remotePid (uint32_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        remotePid = val;
        presenceMask[presenceByte_remotePid] |= presenceMask_remotePid;
        configChanged = true;
    }
    inline uint32_t get_remotePid() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return remotePid;
    }
    inline void clr_remotePid() {
        presenceMask[presenceByte_remotePid] &= ~presenceMask_remotePid;
        configChanged = true;
    }
    inline bool isSet_remotePid() {
        return (presenceMask[presenceByte_remotePid] & presenceMask_remotePid) != 0;
    }
    inline void set_remoteParentPid (uint32_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        remoteParentPid = val;
        presenceMask[presenceByte_remoteParentPid] |= presenceMask_remoteParentPid;
        configChanged = true;
    }
    inline uint32_t get_remoteParentPid() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return remoteParentPid;
    }
    inline void clr_remoteParentPid() {
        presenceMask[presenceByte_remoteParentPid] &= ~presenceMask_remoteParentPid;
        configChanged = true;
    }
    inline bool isSet_remoteParentPid() {
        return (presenceMask[presenceByte_remoteParentPid] & presenceMask_remoteParentPid) != 0;
    }
    inline void set_shadow (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        shadow = val;
        configChanged = true;
    }
    inline bool get_shadow() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return shadow;
    }
    inline void set_saslMechanism (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        saslMechanism = val;
        configChanged = true;
    }
    inline const std::string& get_saslMechanism() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return saslMechanism;
    }
    inline void set_saslSsf (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        saslSsf = val;
        configChanged = true;
    }
    inline uint16_t get_saslSsf() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return saslSsf;
    }
    inline void set_closing (bool val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        closing = val;
        instChanged = true;
    }
    inline bool get_closing() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return closing;
    }
    inline void inc_framesFromClient (uint64_t by = 1) {
        getThreadStats()->framesFromClient += by;
        instChanged = true;
    }
    inline void dec_framesFromClient (uint64_t by = 1) {
        getThreadStats()->framesFromClient -= by;
        instChanged = true;
    }
    inline void inc_framesToClient (uint64_t by = 1) {
        getThreadStats()->framesToClient += by;
        instChanged = true;
    }
    inline void dec_framesToClient (uint64_t by = 1) {
        getThreadStats()->framesToClient -= by;
        instChanged = true;
    }
    inline void inc_bytesFromClient (uint64_t by = 1) {
        getThreadStats()->bytesFromClient += by;
        instChanged = true;
    }
    inline void dec_bytesFromClient (uint64_t by = 1) {
        getThreadStats()->bytesFromClient -= by;
        instChanged = true;
    }
    inline void inc_bytesToClient (uint64_t by = 1) {
        getThreadStats()->bytesToClient += by;
        instChanged = true;
    }
    inline void dec_bytesToClient (uint64_t by = 1) {
        getThreadStats()->bytesToClient -= by;
        instChanged = true;
    }
    inline void inc_msgsFromClient (uint64_t by = 1) {
        getThreadStats()->msgsFromClient += by;
        instChanged = true;
    }
    inline void dec_msgsFromClient (uint64_t by = 1) {
        getThreadStats()->msgsFromClient -= by;
        instChanged = true;
    }
    inline void inc_msgsToClient (uint64_t by = 1) {
        getThreadStats()->msgsToClient += by;
        instChanged = true;
    }
    inline void dec_msgsToClient (uint64_t by = 1) {
        getThreadStats()->msgsToClient -= by;
        instChanged = true;
    }



    struct PerThreadStats* getStatistics() { return getThreadStats(); }
    void statisticsUpdated() { instChanged = true; }

};

}}}}}

#endif  /*!_MANAGEMENT_CONNECTION_*/
