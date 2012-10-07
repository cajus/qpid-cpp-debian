#ifndef QPID_FRAMING_CLUSTERCONNECTIONDTXBUFFERREFBODY_H
#define QPID_FRAMING_CLUSTERCONNECTIONDTXBUFFERREFBODY_H
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

class QPID_COMMON_CLASS_EXTERN ClusterConnectionDtxBufferRefBody : public ModelMethod {
    std::string xid;
    uint32_t index;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x81;
    static const MethodId METHOD_ID = 0x1D;
    ClusterConnectionDtxBufferRefBody(
        ProtocolVersion, const std::string& _xid,
        uint32_t _index,
        bool _suspended) : 
        xid(_xid),
        index(_index),
        flags(0){
        setSuspended(_suspended);
        flags |= (1 << 8);
        flags |= (1 << 9);
        if (xid.size() >= 65536) throw IllegalArgumentException("Value for xid is too large");
    }
    ClusterConnectionDtxBufferRefBody(ProtocolVersion=ProtocolVersion())  : index(0), flags(0) {}
    
    QPID_COMMON_EXTERN void setXid(const std::string& _xid);
    QPID_COMMON_EXTERN const std::string& getXid() const;
    QPID_COMMON_EXTERN bool hasXid() const;
    QPID_COMMON_EXTERN void clearXidFlag();
    QPID_COMMON_EXTERN void setIndex(uint32_t _index);
    QPID_COMMON_EXTERN uint32_t getIndex() const;
    QPID_COMMON_EXTERN bool hasIndex() const;
    QPID_COMMON_EXTERN void clearIndexFlag();
    QPID_COMMON_EXTERN void setSuspended(bool _suspended);
    QPID_COMMON_EXTERN bool getSuspended() const;
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.dtxBufferRef(getXid(), getIndex(), getSuspended());
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
}; /* class ClusterConnectionDtxBufferRefBody */

}}
#endif  /*!QPID_FRAMING_CLUSTERCONNECTIONDTXBUFFERREFBODY_H*/
