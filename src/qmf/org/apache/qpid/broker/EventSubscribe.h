
#ifndef _MANAGEMENT_SUBSCRIBE_
#define _MANAGEMENT_SUBSCRIBE_

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

namespace qmf {
namespace org {
namespace apache {
namespace qpid {
namespace broker {


class EventSubscribe : public ::qpid::management::ManagementEvent
{
  private:
    static void writeSchema (std::string& schema);
    static std::string packageName;
    static std::string eventName;
    static uint8_t md5Sum[MD5_LEN];

    const std::string& rhost;
    const std::string& user;
    const std::string& qName;
    const std::string& dest;
    const bool excl;
    const ::qpid::types::Variant::Map& args;


  public:
    writeSchemaCall_t getWriteSchemaCall(void) { return writeSchema; }

    EventSubscribe(const std::string& _rhost,
        const std::string& _user,
        const std::string& _qName,
        const std::string& _dest,
        const bool _excl,
        const ::qpid::types::Variant::Map& _args);
    ~EventSubscribe() {};

    static void registerSelf(::qpid::management::ManagementAgent* agent);
    std::string& getPackageName() const { return packageName; }
    std::string& getEventName() const { return eventName; }
    uint8_t* getMd5Sum() const { return md5Sum; }
    uint8_t getSeverity() const { return 6; }
    void encode(std::string& buffer) const;
    void mapEncode(::qpid::types::Variant::Map& map) const;
};

}}}}}

#endif  /*!_MANAGEMENT_SUBSCRIBE_*/
