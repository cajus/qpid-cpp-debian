
#ifndef _MANAGEMENT_ORG_APACHE_QPID_BROKER_LINK_
#define _MANAGEMENT_ORG_APACHE_QPID_BROKER_LINK_

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


QPID_BROKER_CLASS_EXTERN class Link : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];


    // Properties
    ::qpid::management::ObjectId vhostRef;
    std::string name;
    std::string host;
    uint16_t port;
    std::string transport;
    bool durable;
    ::qpid::management::ObjectId connectionRef;

    // Statistics
    std::string  state;
    std::string  lastError;


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


    QPID_BROKER_EXTERN Link(
        ::qpid::management::ManagementAgent* agent,
        ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _name, bool _durable);

    QPID_BROKER_EXTERN ~Link();

    

    QPID_BROKER_EXTERN static void registerSelf(
        ::qpid::management::ManagementAgent* agent);

    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    QPID_BROKER_EXTERN static const uint32_t METHOD_CLOSE = 1;
    QPID_BROKER_EXTERN static const uint32_t METHOD_BRIDGE = 2;

    // Accessor Methods
    inline void set_host (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        host = val;
        configChanged = true;
    }
    inline const std::string& get_host() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return host;
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
    inline void set_transport (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        transport = val;
        configChanged = true;
    }
    inline const std::string& get_transport() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return transport;
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
    inline void set_state (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        state = val;
        instChanged = true;
    }
    inline const std::string& get_state() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return state;
    }
    inline void set_lastError (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        lastError = val;
        instChanged = true;
    }
    inline const std::string& get_lastError() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return lastError;
    }



};

}}}}}

#endif  /*!_MANAGEMENT_LINK_*/
