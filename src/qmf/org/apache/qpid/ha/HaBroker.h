
#ifndef _MANAGEMENT_ORG_APACHE_QPID_HA_HABROKER_
#define _MANAGEMENT_ORG_APACHE_QPID_HA_HABROKER_

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
namespace ha {


QPID_BROKER_CLASS_EXTERN class HaBroker : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];


    // Properties
    std::string name;
    std::string status;
    std::string brokers;
    std::string publicBrokers;
    uint16_t expectedBackups;

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


    QPID_BROKER_EXTERN HaBroker(
        ::qpid::management::ManagementAgent* agent,
        ::qpid::management::Manageable* coreObject, const std::string& _name);

    QPID_BROKER_EXTERN ~HaBroker();

    

    QPID_BROKER_EXTERN static void registerSelf(
        ::qpid::management::ManagementAgent* agent);

    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    QPID_BROKER_EXTERN static const uint32_t METHOD_PROMOTE = 1;
    QPID_BROKER_EXTERN static const uint32_t METHOD_SETBROKERS = 2;
    QPID_BROKER_EXTERN static const uint32_t METHOD_SETPUBLICBROKERS = 3;
    QPID_BROKER_EXTERN static const uint32_t METHOD_SETEXPECTEDBACKUPS = 4;
    QPID_BROKER_EXTERN static const uint32_t METHOD_REPLICATE = 5;

    // Accessor Methods
    inline void set_status (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        status = val;
        configChanged = true;
    }
    inline const std::string& get_status() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return status;
    }
    inline void set_brokers (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        brokers = val;
        configChanged = true;
    }
    inline const std::string& get_brokers() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return brokers;
    }
    inline void set_publicBrokers (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        publicBrokers = val;
        configChanged = true;
    }
    inline const std::string& get_publicBrokers() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return publicBrokers;
    }
    inline void set_expectedBackups (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        expectedBackups = val;
        configChanged = true;
    }
    inline uint16_t get_expectedBackups() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return expectedBackups;
    }



};

}}}}}

#endif  /*!_MANAGEMENT_HABROKER_*/
