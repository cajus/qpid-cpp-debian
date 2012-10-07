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


#include "qpid/framing/ExchangeBoundResult.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExchangeBoundResult::setExchangeNotFound(bool _exchangeNotFound) {
    if (_exchangeNotFound) flags |= (1 << 8);
    else flags &= ~(1 << 8);
}
bool ExchangeBoundResult::getExchangeNotFound() const { return flags & (1 << 8); }

void ExchangeBoundResult::setQueueNotFound(bool _queueNotFound) {
    if (_queueNotFound) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ExchangeBoundResult::getQueueNotFound() const { return flags & (1 << 9); }

void ExchangeBoundResult::setQueueNotMatched(bool _queueNotMatched) {
    if (_queueNotMatched) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool ExchangeBoundResult::getQueueNotMatched() const { return flags & (1 << 10); }

void ExchangeBoundResult::setKeyNotMatched(bool _keyNotMatched) {
    if (_keyNotMatched) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool ExchangeBoundResult::getKeyNotMatched() const { return flags & (1 << 11); }

void ExchangeBoundResult::setArgsNotMatched(bool _argsNotMatched) {
    if (_argsNotMatched) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool ExchangeBoundResult::getArgsNotMatched() const { return flags & (1 << 12); }

void ExchangeBoundResult::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
}

void ExchangeBoundResult::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void ExchangeBoundResult::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
}

void ExchangeBoundResult::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t ExchangeBoundResult::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    return total;
}

uint32_t ExchangeBoundResult::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void ExchangeBoundResult::print(std::ostream& out) const
{
    out << "{ExchangeBoundResult: ";
    if (flags & (1 << 8))
        out << "exchange-not-found=" << getExchangeNotFound() << "; ";
    if (flags & (1 << 9))
        out << "queue-not-found=" << getQueueNotFound() << "; ";
    if (flags & (1 << 10))
        out << "queue-not-matched=" << getQueueNotMatched() << "; ";
    if (flags & (1 << 11))
        out << "key-not-matched=" << getKeyNotMatched() << "; ";
    if (flags & (1 << 12))
        out << "args-not-matched=" << getArgsNotMatched() << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const ExchangeBoundResult& s) 
    {
      s.print(out);
      return out;
    }

}
}
