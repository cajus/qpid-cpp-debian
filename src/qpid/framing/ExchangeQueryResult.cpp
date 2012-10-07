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


#include "qpid/framing/ExchangeQueryResult.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExchangeQueryResult::setType(const std::string& _type) {
    type = _type;
    flags |= (1 << 8);
    if (type.size() >= 256) throw IllegalArgumentException("Value for type is too large");
}
const std::string& ExchangeQueryResult::getType() const { return type; }
bool ExchangeQueryResult::hasType() const { return flags & (1 << 8); }
void ExchangeQueryResult::clearTypeFlag() { flags &= ~(1 << 8); }

void ExchangeQueryResult::setDurable(bool _durable) {
    if (_durable) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ExchangeQueryResult::getDurable() const { return flags & (1 << 9); }

void ExchangeQueryResult::setNotFound(bool _notFound) {
    if (_notFound) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool ExchangeQueryResult::getNotFound() const { return flags & (1 << 10); }

void ExchangeQueryResult::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 11);
}
const FieldTable& ExchangeQueryResult::getArguments() const { return arguments; }
FieldTable& ExchangeQueryResult::getArguments() {
    flags |= (1 << 11);
    return arguments;
}
bool ExchangeQueryResult::hasArguments() const { return flags & (1 << 11); }
void ExchangeQueryResult::clearArgumentsFlag() { flags &= ~(1 << 11); }

void ExchangeQueryResult::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(type);
    if (flags & (1 << 11))
        arguments.encode(buffer);
}

void ExchangeQueryResult::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void ExchangeQueryResult::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(type);
    if (flags & (1 << 11))
        arguments.decode(buffer);
}

void ExchangeQueryResult::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t ExchangeQueryResult::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 1 + type.size();
    if (flags & (1 << 11))
        total += arguments.encodedSize();
    return total;
}

uint32_t ExchangeQueryResult::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void ExchangeQueryResult::print(std::ostream& out) const
{
    out << "{ExchangeQueryResult: ";
    if (flags & (1 << 8))
        out << "type=" << type << "; ";
    if (flags & (1 << 9))
        out << "durable=" << getDurable() << "; ";
    if (flags & (1 << 10))
        out << "not-found=" << getNotFound() << "; ";
    if (flags & (1 << 11))
        out << "arguments=" << arguments << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const ExchangeQueryResult& s) 
    {
      s.print(out);
      return out;
    }

}
}
