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


#include "qpid/framing/ExchangeDeleteBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExchangeDeleteBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 8);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& ExchangeDeleteBody::getExchange() const { return exchange; }
bool ExchangeDeleteBody::hasExchange() const { return flags & (1 << 8); }
void ExchangeDeleteBody::clearExchangeFlag() { flags &= ~(1 << 8); }

void ExchangeDeleteBody::setIfUnused(bool _ifUnused) {
    if (_ifUnused) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ExchangeDeleteBody::getIfUnused() const { return flags & (1 << 9); }

void ExchangeDeleteBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(exchange);
}

void ExchangeDeleteBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExchangeDeleteBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(exchange);
}

void ExchangeDeleteBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExchangeDeleteBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + exchange.size();
    return total;
}

uint32_t ExchangeDeleteBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExchangeDeleteBody::print(std::ostream& out) const
{
    out << "{ExchangeDeleteBody: ";
    if (flags & (1 << 8))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 9))
        out << "if-unused=" << getIfUnused() << "; ";
    out << "}";
}
