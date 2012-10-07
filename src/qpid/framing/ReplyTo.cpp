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


#include "qpid/framing/ReplyTo.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ReplyTo::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 8);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& ReplyTo::getExchange() const { return exchange; }
bool ReplyTo::hasExchange() const { return flags & (1 << 8); }
void ReplyTo::clearExchangeFlag() { flags &= ~(1 << 8); }

void ReplyTo::setRoutingKey(const std::string& _routingKey) {
    routingKey = _routingKey;
    flags |= (1 << 9);
    if (routingKey.size() >= 256) throw IllegalArgumentException("Value for routingKey is too large");
}
const std::string& ReplyTo::getRoutingKey() const { return routingKey; }
bool ReplyTo::hasRoutingKey() const { return flags & (1 << 9); }
void ReplyTo::clearRoutingKeyFlag() { flags &= ~(1 << 9); }

void ReplyTo::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(exchange);
    if (flags & (1 << 9))
        buffer.putShortString(routingKey);
}

void ReplyTo::encode(Buffer& buffer) const
{
    buffer.putShort(bodySize());
    encodeStructBody(buffer);
}

void ReplyTo::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(exchange);
    if (flags & (1 << 9))
        buffer.getShortString(routingKey);
}

void ReplyTo::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getShort();
    decodeStructBody(buffer);
}

uint32_t ReplyTo::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 1 + exchange.size();
    if (flags & (1 << 9))
        total += 1 + routingKey.size();
    return total;
}

uint32_t ReplyTo::encodedSize() const {
    uint32_t total = bodySize();
total += 2/*size field*/;
    return total;
}

void ReplyTo::print(std::ostream& out) const
{
    out << "{ReplyTo: ";
    if (flags & (1 << 8))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 9))
        out << "routing-key=" << routingKey << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const ReplyTo& s) 
    {
      s.print(out);
      return out;
    }

}
}
