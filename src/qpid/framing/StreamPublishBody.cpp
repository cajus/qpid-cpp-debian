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


#include "qpid/framing/StreamPublishBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void StreamPublishBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 8);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& StreamPublishBody::getExchange() const { return exchange; }
bool StreamPublishBody::hasExchange() const { return flags & (1 << 8); }
void StreamPublishBody::clearExchangeFlag() { flags &= ~(1 << 8); }

void StreamPublishBody::setRoutingKey(const std::string& _routingKey) {
    routingKey = _routingKey;
    flags |= (1 << 9);
    if (routingKey.size() >= 256) throw IllegalArgumentException("Value for routingKey is too large");
}
const std::string& StreamPublishBody::getRoutingKey() const { return routingKey; }
bool StreamPublishBody::hasRoutingKey() const { return flags & (1 << 9); }
void StreamPublishBody::clearRoutingKeyFlag() { flags &= ~(1 << 9); }

void StreamPublishBody::setMandatory(bool _mandatory) {
    if (_mandatory) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool StreamPublishBody::getMandatory() const { return flags & (1 << 10); }

void StreamPublishBody::setImmediate(bool _immediate) {
    if (_immediate) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool StreamPublishBody::getImmediate() const { return flags & (1 << 11); }

void StreamPublishBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(exchange);
    if (flags & (1 << 9))
        buffer.putShortString(routingKey);
}

void StreamPublishBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void StreamPublishBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(exchange);
    if (flags & (1 << 9))
        buffer.getShortString(routingKey);
}

void StreamPublishBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t StreamPublishBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + exchange.size();
    if (flags & (1 << 9))
        total += 1 + routingKey.size();
    return total;
}

uint32_t StreamPublishBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void StreamPublishBody::print(std::ostream& out) const
{
    out << "{StreamPublishBody: ";
    if (flags & (1 << 8))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 9))
        out << "routing-key=" << routingKey << "; ";
    if (flags & (1 << 10))
        out << "mandatory=" << getMandatory() << "; ";
    if (flags & (1 << 11))
        out << "immediate=" << getImmediate() << "; ";
    out << "}";
}
