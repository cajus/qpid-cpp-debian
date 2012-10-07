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


#include "qpid/framing/DeliveryProperties.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void DeliveryProperties::setDiscardUnroutable(bool _discardUnroutable) {
    if (_discardUnroutable) flags |= (1 << 8);
    else flags &= ~(1 << 8);
}
bool DeliveryProperties::getDiscardUnroutable() const { return flags & (1 << 8); }

void DeliveryProperties::setImmediate(bool _immediate) {
    if (_immediate) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool DeliveryProperties::getImmediate() const { return flags & (1 << 9); }

void DeliveryProperties::setRedelivered(bool _redelivered) {
    if (_redelivered) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool DeliveryProperties::getRedelivered() const { return flags & (1 << 10); }

void DeliveryProperties::setPriority(uint8_t _priority) {
    priority = _priority;
    flags |= (1 << 11);
}
uint8_t DeliveryProperties::getPriority() const { return priority; }
bool DeliveryProperties::hasPriority() const { return flags & (1 << 11); }
void DeliveryProperties::clearPriorityFlag() { flags &= ~(1 << 11); }

void DeliveryProperties::setDeliveryMode(uint8_t _deliveryMode) {
    deliveryMode = _deliveryMode;
    flags |= (1 << 12);
}
uint8_t DeliveryProperties::getDeliveryMode() const { return deliveryMode; }
bool DeliveryProperties::hasDeliveryMode() const { return flags & (1 << 12); }
void DeliveryProperties::clearDeliveryModeFlag() { flags &= ~(1 << 12); }

void DeliveryProperties::setTtl(uint64_t _ttl) {
    ttl = _ttl;
    flags |= (1 << 13);
}
uint64_t DeliveryProperties::getTtl() const { return ttl; }
bool DeliveryProperties::hasTtl() const { return flags & (1 << 13); }
void DeliveryProperties::clearTtlFlag() { flags &= ~(1 << 13); }

void DeliveryProperties::setTimestamp(uint64_t _timestamp) {
    timestamp = _timestamp;
    flags |= (1 << 14);
}
uint64_t DeliveryProperties::getTimestamp() const { return timestamp; }
bool DeliveryProperties::hasTimestamp() const { return flags & (1 << 14); }
void DeliveryProperties::clearTimestampFlag() { flags &= ~(1 << 14); }

void DeliveryProperties::setExpiration(uint64_t _expiration) {
    expiration = _expiration;
    flags |= (1 << 15);
}
uint64_t DeliveryProperties::getExpiration() const { return expiration; }
bool DeliveryProperties::hasExpiration() const { return flags & (1 << 15); }
void DeliveryProperties::clearExpirationFlag() { flags &= ~(1 << 15); }

void DeliveryProperties::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 0);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& DeliveryProperties::getExchange() const { return exchange; }
bool DeliveryProperties::hasExchange() const { return flags & (1 << 0); }
void DeliveryProperties::clearExchangeFlag() { flags &= ~(1 << 0); }

void DeliveryProperties::setRoutingKey(const std::string& _routingKey) {
    routingKey = _routingKey;
    flags |= (1 << 1);
    if (routingKey.size() >= 256) throw IllegalArgumentException("Value for routingKey is too large");
}
const std::string& DeliveryProperties::getRoutingKey() const { return routingKey; }
bool DeliveryProperties::hasRoutingKey() const { return flags & (1 << 1); }
void DeliveryProperties::clearRoutingKeyFlag() { flags &= ~(1 << 1); }

void DeliveryProperties::setResumeId(const std::string& _resumeId) {
    resumeId = _resumeId;
    flags |= (1 << 2);
    if (resumeId.size() >= 65536) throw IllegalArgumentException("Value for resumeId is too large");
}
const std::string& DeliveryProperties::getResumeId() const { return resumeId; }
bool DeliveryProperties::hasResumeId() const { return flags & (1 << 2); }
void DeliveryProperties::clearResumeIdFlag() { flags &= ~(1 << 2); }

void DeliveryProperties::setResumeTtl(uint64_t _resumeTtl) {
    resumeTtl = _resumeTtl;
    flags |= (1 << 3);
}
uint64_t DeliveryProperties::getResumeTtl() const { return resumeTtl; }
bool DeliveryProperties::hasResumeTtl() const { return flags & (1 << 3); }
void DeliveryProperties::clearResumeTtlFlag() { flags &= ~(1 << 3); }

void DeliveryProperties::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 11))
        buffer.putOctet(priority);
    if (flags & (1 << 12))
        buffer.putOctet(deliveryMode);
    if (flags & (1 << 13))
        buffer.putLongLong(ttl);
    if (flags & (1 << 14))
        buffer.putLongLong(timestamp);
    if (flags & (1 << 15))
        buffer.putLongLong(expiration);
    if (flags & (1 << 0))
        buffer.putShortString(exchange);
    if (flags & (1 << 1))
        buffer.putShortString(routingKey);
    if (flags & (1 << 2))
        buffer.putMediumString(resumeId);
    if (flags & (1 << 3))
        buffer.putLongLong(resumeTtl);
}

void DeliveryProperties::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void DeliveryProperties::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 11))
        priority = buffer.getOctet();
    if (flags & (1 << 12))
        deliveryMode = buffer.getOctet();
    if (flags & (1 << 13))
        ttl = buffer.getLongLong();
    if (flags & (1 << 14))
        timestamp = buffer.getLongLong();
    if (flags & (1 << 15))
        expiration = buffer.getLongLong();
    if (flags & (1 << 0))
        buffer.getShortString(exchange);
    if (flags & (1 << 1))
        buffer.getShortString(routingKey);
    if (flags & (1 << 2))
        buffer.getMediumString(resumeId);
    if (flags & (1 << 3))
        resumeTtl = buffer.getLongLong();
}

void DeliveryProperties::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t DeliveryProperties::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 11))
        total += 1;//priority
    if (flags & (1 << 12))
        total += 1;//deliveryMode
    if (flags & (1 << 13))
        total += 8;//ttl
    if (flags & (1 << 14))
        total += 8;//timestamp
    if (flags & (1 << 15))
        total += 8;//expiration
    if (flags & (1 << 0))
        total += 1 + exchange.size();
    if (flags & (1 << 1))
        total += 1 + routingKey.size();
    if (flags & (1 << 2))
        total += 2 + resumeId.size();
    if (flags & (1 << 3))
        total += 8;//resumeTtl
    return total;
}

uint32_t DeliveryProperties::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void DeliveryProperties::print(std::ostream& out) const
{
    out << "{DeliveryProperties: ";
    if (flags & (1 << 8))
        out << "discard-unroutable=" << getDiscardUnroutable() << "; ";
    if (flags & (1 << 9))
        out << "immediate=" << getImmediate() << "; ";
    if (flags & (1 << 10))
        out << "redelivered=" << getRedelivered() << "; ";
    if (flags & (1 << 11))
        out << "priority=" << (int) priority << "; ";
    if (flags & (1 << 12))
        out << "delivery-mode=" << (int) deliveryMode << "; ";
    if (flags & (1 << 13))
        out << "ttl=" << ttl << "; ";
    if (flags & (1 << 14))
        out << "timestamp=" << timestamp << "; ";
    if (flags & (1 << 15))
        out << "expiration=" << expiration << "; ";
    if (flags & (1 << 0))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 1))
        out << "routing-key=" << routingKey << "; ";
    if (flags & (1 << 2))
        out << "resume-id=" << resumeId << "; ";
    if (flags & (1 << 3))
        out << "resume-ttl=" << resumeTtl << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const DeliveryProperties& s) 
    {
      s.print(out);
      return out;
    }

}
}
