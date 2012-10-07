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


#include "qpid/framing/FileDeliverBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FileDeliverBody::setConsumerTag(const std::string& _consumerTag) {
    consumerTag = _consumerTag;
    flags |= (1 << 8);
    if (consumerTag.size() >= 256) throw IllegalArgumentException("Value for consumerTag is too large");
}
const std::string& FileDeliverBody::getConsumerTag() const { return consumerTag; }
bool FileDeliverBody::hasConsumerTag() const { return flags & (1 << 8); }
void FileDeliverBody::clearConsumerTagFlag() { flags &= ~(1 << 8); }

void FileDeliverBody::setDeliveryTag(uint64_t _deliveryTag) {
    deliveryTag = _deliveryTag;
    flags |= (1 << 9);
}
uint64_t FileDeliverBody::getDeliveryTag() const { return deliveryTag; }
bool FileDeliverBody::hasDeliveryTag() const { return flags & (1 << 9); }
void FileDeliverBody::clearDeliveryTagFlag() { flags &= ~(1 << 9); }

void FileDeliverBody::setRedelivered(bool _redelivered) {
    if (_redelivered) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool FileDeliverBody::getRedelivered() const { return flags & (1 << 10); }

void FileDeliverBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 11);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& FileDeliverBody::getExchange() const { return exchange; }
bool FileDeliverBody::hasExchange() const { return flags & (1 << 11); }
void FileDeliverBody::clearExchangeFlag() { flags &= ~(1 << 11); }

void FileDeliverBody::setRoutingKey(const std::string& _routingKey) {
    routingKey = _routingKey;
    flags |= (1 << 12);
    if (routingKey.size() >= 256) throw IllegalArgumentException("Value for routingKey is too large");
}
const std::string& FileDeliverBody::getRoutingKey() const { return routingKey; }
bool FileDeliverBody::hasRoutingKey() const { return flags & (1 << 12); }
void FileDeliverBody::clearRoutingKeyFlag() { flags &= ~(1 << 12); }

void FileDeliverBody::setIdentifier(const std::string& _identifier) {
    identifier = _identifier;
    flags |= (1 << 13);
    if (identifier.size() >= 256) throw IllegalArgumentException("Value for identifier is too large");
}
const std::string& FileDeliverBody::getIdentifier() const { return identifier; }
bool FileDeliverBody::hasIdentifier() const { return flags & (1 << 13); }
void FileDeliverBody::clearIdentifierFlag() { flags &= ~(1 << 13); }

void FileDeliverBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(consumerTag);
    if (flags & (1 << 9))
        buffer.putLongLong(deliveryTag);
    if (flags & (1 << 11))
        buffer.putShortString(exchange);
    if (flags & (1 << 12))
        buffer.putShortString(routingKey);
    if (flags & (1 << 13))
        buffer.putShortString(identifier);
}

void FileDeliverBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void FileDeliverBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(consumerTag);
    if (flags & (1 << 9))
        deliveryTag = buffer.getLongLong();
    if (flags & (1 << 11))
        buffer.getShortString(exchange);
    if (flags & (1 << 12))
        buffer.getShortString(routingKey);
    if (flags & (1 << 13))
        buffer.getShortString(identifier);
}

void FileDeliverBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t FileDeliverBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + consumerTag.size();
    if (flags & (1 << 9))
        total += 8;//deliveryTag
    if (flags & (1 << 11))
        total += 1 + exchange.size();
    if (flags & (1 << 12))
        total += 1 + routingKey.size();
    if (flags & (1 << 13))
        total += 1 + identifier.size();
    return total;
}

uint32_t FileDeliverBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void FileDeliverBody::print(std::ostream& out) const
{
    out << "{FileDeliverBody: ";
    if (flags & (1 << 8))
        out << "consumer-tag=" << consumerTag << "; ";
    if (flags & (1 << 9))
        out << "delivery-tag=" << deliveryTag << "; ";
    if (flags & (1 << 10))
        out << "redelivered=" << getRedelivered() << "; ";
    if (flags & (1 << 11))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 12))
        out << "routing-key=" << routingKey << "; ";
    if (flags & (1 << 13))
        out << "identifier=" << identifier << "; ";
    out << "}";
}
