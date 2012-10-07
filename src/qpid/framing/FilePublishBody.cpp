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


#include "qpid/framing/FilePublishBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FilePublishBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 8);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& FilePublishBody::getExchange() const { return exchange; }
bool FilePublishBody::hasExchange() const { return flags & (1 << 8); }
void FilePublishBody::clearExchangeFlag() { flags &= ~(1 << 8); }

void FilePublishBody::setRoutingKey(const std::string& _routingKey) {
    routingKey = _routingKey;
    flags |= (1 << 9);
    if (routingKey.size() >= 256) throw IllegalArgumentException("Value for routingKey is too large");
}
const std::string& FilePublishBody::getRoutingKey() const { return routingKey; }
bool FilePublishBody::hasRoutingKey() const { return flags & (1 << 9); }
void FilePublishBody::clearRoutingKeyFlag() { flags &= ~(1 << 9); }

void FilePublishBody::setMandatory(bool _mandatory) {
    if (_mandatory) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool FilePublishBody::getMandatory() const { return flags & (1 << 10); }

void FilePublishBody::setImmediate(bool _immediate) {
    if (_immediate) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool FilePublishBody::getImmediate() const { return flags & (1 << 11); }

void FilePublishBody::setIdentifier(const std::string& _identifier) {
    identifier = _identifier;
    flags |= (1 << 12);
    if (identifier.size() >= 256) throw IllegalArgumentException("Value for identifier is too large");
}
const std::string& FilePublishBody::getIdentifier() const { return identifier; }
bool FilePublishBody::hasIdentifier() const { return flags & (1 << 12); }
void FilePublishBody::clearIdentifierFlag() { flags &= ~(1 << 12); }

void FilePublishBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(exchange);
    if (flags & (1 << 9))
        buffer.putShortString(routingKey);
    if (flags & (1 << 12))
        buffer.putShortString(identifier);
}

void FilePublishBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void FilePublishBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(exchange);
    if (flags & (1 << 9))
        buffer.getShortString(routingKey);
    if (flags & (1 << 12))
        buffer.getShortString(identifier);
}

void FilePublishBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t FilePublishBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + exchange.size();
    if (flags & (1 << 9))
        total += 1 + routingKey.size();
    if (flags & (1 << 12))
        total += 1 + identifier.size();
    return total;
}

uint32_t FilePublishBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void FilePublishBody::print(std::ostream& out) const
{
    out << "{FilePublishBody: ";
    if (flags & (1 << 8))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 9))
        out << "routing-key=" << routingKey << "; ";
    if (flags & (1 << 10))
        out << "mandatory=" << getMandatory() << "; ";
    if (flags & (1 << 11))
        out << "immediate=" << getImmediate() << "; ";
    if (flags & (1 << 12))
        out << "identifier=" << identifier << "; ";
    out << "}";
}
