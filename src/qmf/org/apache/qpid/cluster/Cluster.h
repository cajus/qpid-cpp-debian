
#ifndef _MANAGEMENT_CLUSTER_
#define _MANAGEMENT_CLUSTER_

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
namespace cluster {


class Cluster : public ::qpid::management::ManagementObject
{
  private:

    static std::string packageName;
    static std::string className;
    static uint8_t     md5Sum[MD5_LEN];


    // Properties
    ::qpid::management::ObjectId brokerRef;
    std::string clusterName;
    std::string clusterID;
    std::string memberID;
    std::string publishedURL;
    uint16_t clusterSize;
    std::string status;
    std::string members;
    std::string memberIDs;

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


    Cluster(::qpid::management::ManagementAgent* agent,
                            ::qpid::management::Manageable* coreObject, ::qpid::management::Manageable* _parent, const std::string& _clusterName, const std::string& _publishedURL);
    ~Cluster();

    

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getClassName() const { return className; }
    uint8_t* getMd5Sum() const { return md5Sum; }

    // Method IDs
    static const uint32_t METHOD_STOPCLUSTERNODE = 1;
    static const uint32_t METHOD_STOPFULLCLUSTER = 2;

    // Accessor Methods
    inline void set_clusterID (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        clusterID = val;
        configChanged = true;
    }
    inline const std::string& get_clusterID() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return clusterID;
    }
    inline void set_memberID (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        memberID = val;
        configChanged = true;
    }
    inline const std::string& get_memberID() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return memberID;
    }
    inline void set_clusterSize (uint16_t val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        clusterSize = val;
        configChanged = true;
    }
    inline uint16_t get_clusterSize() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return clusterSize;
    }
    inline void set_status (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        status = val;
        configChanged = true;
    }
    inline const std::string& get_status() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return status;
    }
    inline void set_members (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        members = val;
        configChanged = true;
    }
    inline const std::string& get_members() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return members;
    }
    inline void set_memberIDs (const std::string& val) {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        memberIDs = val;
        configChanged = true;
    }
    inline const std::string& get_memberIDs() {
        ::qpid::management::Mutex::ScopedLock mutex(accessLock);
        return memberIDs;
    }

};

}}}}}

#endif  /*!_MANAGEMENT_CLUSTER_*/
