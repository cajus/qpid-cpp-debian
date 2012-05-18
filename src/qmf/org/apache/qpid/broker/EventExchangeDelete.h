
#ifndef _MANAGEMENT_EXCHANGEDELETE_
#define _MANAGEMENT_EXCHANGEDELETE_

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

#include "qpid/management/ManagementEvent.h"
#include "qmf/BrokerImportExport.h"

namespace qmf {
namespace org {
namespace apache {
namespace qpid {
namespace broker {


QPID_BROKER_CLASS_EXTERN class EventExchangeDelete : public ::qpid::management::ManagementEvent
{
  private:
    static void writeSchema (std::string& schema);
    static std::string packageName;
    static std::string eventName;
    static uint8_t md5Sum[MD5_LEN];

    const std::string& rhost;
    const std::string& user;
    const std::string& exName;


  public:
    writeSchemaCall_t getWriteSchemaCall(void) { return writeSchema; }

    QPID_BROKER_EXTERN EventExchangeDelete(const std::string& _rhost,
        const std::string& _user,
        const std::string& _exName);
    QPID_BROKER_EXTERN ~EventExchangeDelete() {};

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getEventName() const { return eventName; }
    uint8_t* getMd5Sum() const { return md5Sum; }
    uint8_t getSeverity() const { return 6; }
    QPID_BROKER_EXTERN void encode(std::string& buffer) const;
    QPID_BROKER_EXTERN void mapEncode(::qpid::types::Variant::Map& map) const;

    QPID_BROKER_EXTERN static bool match(const std::string& evt, const std::string& pkg);
};

}}}}}

#endif  /*!_MANAGEMENT_EXCHANGEDELETE_*/
