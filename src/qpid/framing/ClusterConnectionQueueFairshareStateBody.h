#ifndef QPID_FRAMING_CLUSTERCONNECTIONQUEUEFAIRSHARESTATEBODY_H
#define QPID_FRAMING_CLUSTERCONNECTIONQUEUEFAIRSHARESTATEBODY_H
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
#include "qpid/CommonImportExport.h"

namespace qpid {
namespace framing {

class QPID_COMMON_CLASS_EXTERN ClusterConnectionQueueFairshareStateBody : public ModelMethod {
    std::string queue;
    uint8_t position;
    uint8_t count;
    uint16_t flags;
public:
    static const ClassId CLASS_ID = 0x81;
    static const MethodId METHOD_ID = 0x38;
    ClusterConnectionQueueFairshareStateBody(
        ProtocolVersion, const std::string& _queue,
        uint8_t _position,
        uint8_t _count) : 
        queue(_queue),
        position(_position),
        count(_count),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
    }
    ClusterConnectionQueueFairshareStateBody(ProtocolVersion=ProtocolVersion())  : position(0), count(0), flags(0) {}
    
    QPID_COMMON_EXTERN void setQueue(const std::string& _queue);
    QPID_COMMON_EXTERN const std::string& getQueue() const;
    QPID_COMMON_EXTERN bool hasQueue() const;
    QPID_COMMON_EXTERN void clearQueueFlag();
    QPID_COMMON_EXTERN void setPosition(uint8_t _position);
    QPID_COMMON_EXTERN uint8_t getPosition() const;
    QPID_COMMON_EXTERN bool hasPosition() const;
    QPID_COMMON_EXTERN void clearPositionFlag();
    QPID_COMMON_EXTERN void setCount(uint8_t _count);
    QPID_COMMON_EXTERN uint8_t getCount() const;
    QPID_COMMON_EXTERN bool hasCount() const;
    QPID_COMMON_EXTERN void clearCountFlag();
    typedef void ResultType;

    template <class T> ResultType invoke(T& invocable) const {
        return invocable.queueFairshareState(getQueue(), getPosition(), getCount());
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
}; /* class ClusterConnectionQueueFairshareStateBody */

}}
#endif  /*!QPID_FRAMING_CLUSTERCONNECTIONQUEUEFAIRSHARESTATEBODY_H*/
