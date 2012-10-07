#ifndef QPID_FRAMING_CLUSTERCONFIGCHANGEBODY_H
#define QPID_FRAMING_CLUSTERCONFIGCHANGEBODY_H
/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

///
/// This file was automatically generated from the AMQP specification.
/// Do not edit.
///


#include "qpid/framing/AMQMethodBody.h"
#include "qpid/framing/AMQP_ServerOperations.h"
#include "qpid/framing/MethodBodyConstVisitor.h"
#include "qpid/framing/ModelMethod.h"

#include <ostream>
#include "qpid/framing/amqp_types_full.h"
#include "qpid/framing/reply_exceptions.h"
#include "qpid/CommonImportExport.h"

namespace qpid {
namespace framing {

class QPID_COMMON_CLASS_EXTERN ClusterConfigChangeBody : public ModelMethod {
    std::string members;
    std::string joined;
    std::string left;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x80;
    static const MethodId METHOD_ID = 0x11;
    ClusterConfigChangeBody(
        ProtocolVersion, const std::string& _members,
        const std::string& _joined,
        const std::string& _left) : 
        members(_members),
        joined(_joined),
        left(_left),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        if (members.size() >= 65536) throw IllegalArgumentException("Value for members is too large");
        if (joined.size() >= 65536) throw IllegalArgumentException("Value for joined is too large");
        if (left.size() >= 65536) throw IllegalArgumentException("Value for left is too large");
    }
    ClusterConfigChangeBody(ProtocolVersion=ProtocolVersion())  : flags(0) {}
    
    QPID_COMMON_EXTERN void setMembers(const std::string& _members);
    QPID_COMMON_EXTERN const std::string& getMembers() const;
    QPID_COMMON_EXTERN bool hasMembers() const;
    QPID_COMMON_EXTERN void clearMembersFlag();
    QPID_COMMON_EXTERN void setJoined(const std::string& _joined);
    QPID_COMMON_EXTERN const std::string& getJoined() const;
    QPID_COMMON_EXTERN bool hasJoined() const;
    QPID_COMMON_EXTERN void clearJoinedFlag();
    QPID_COMMON_EXTERN void setLeft(const std::string& _left);
    QPID_COMMON_EXTERN const std::string& getLeft() const;
    QPID_COMMON_EXTERN bool hasLeft() const;
    QPID_COMMON_EXTERN void clearLeftFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.configChange(getMembers(), getJoined(), getLeft());
    }

    using  AMQMethodBody::accept;
    void accept(MethodBodyConstVisitor& v) const { v.visit(*this); }
    boost::intrusive_ptr<AMQBody> clone() const { return BodyFactory::copy(*this); }

    ClassId amqpClassId() const { return CLASS_ID; }
    MethodId amqpMethodId() const { return METHOD_ID; }
    bool isContentBearing() const { return  false; }
    bool resultExpected() const { return  false; }
    bool responseExpected() const { return  false; }
    QPID_COMMON_EXTERN void encode(Buffer&) const;
    QPID_COMMON_EXTERN void decode(Buffer&, uint32_t=0);
    QPID_COMMON_EXTERN void encodeStructBody(Buffer&) const;
    QPID_COMMON_EXTERN void decodeStructBody(Buffer&, uint32_t=0);
    QPID_COMMON_EXTERN uint32_t encodedSize() const;
    QPID_COMMON_EXTERN uint32_t bodySize() const;
    QPID_COMMON_EXTERN void print(std::ostream& out) const;
}; /* class ClusterConfigChangeBody */

}}
#endif  /*!QPID_FRAMING_CLUSTERCONFIGCHANGEBODY_H*/
