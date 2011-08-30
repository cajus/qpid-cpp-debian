
#ifndef _MANAGEMENT_SYSTEM_
#define _MANAGEMENT_SYSTEM_

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


class System : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];


    // Properties
    ::qpid::types::Uuid systemId;
    std::string osName;
    std::string nodeName;
    std::string release;
    std::string version;
    std::string machine;

    // Statistics


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

    // Stub for getInstChanged.  There are no statistics in this class.
    bool getInstChanged() { return false; }
    bool hasInst() { return false; }


    System(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, const ::qpid::types::Uuid& _systemId);
    ~System();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs

    // Accessor Methods
    inline void set_osName (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        osName = val;
        configChanged = true;
    }
    inline const std::string& get_osName() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return osName;
    }
    inline void set_nodeName (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        nodeName = val;
        configChanged = true;
    }
    inline const std::string& get_nodeName() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return nodeName;
    }
    inline void set_release (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        release = val;
        configChanged = true;
    }
    inline const std::string& get_release() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return release;
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
    inline void set_machine (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        machine = val;
        configChanged = true;
    }
    inline const std::string& get_machine() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return machine;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_SYSTEM_*/
