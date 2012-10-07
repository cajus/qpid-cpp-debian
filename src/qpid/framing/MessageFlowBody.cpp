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


#include "qpid/framing/MessageFlowBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageFlowBody::setDestination(const std::string& _destination) {
    destination = _destination;
    flags |= (1 << 8);
    if (destination.size() >= 256) throw IllegalArgumentException("Value for destination is too large");
}
const std::string& MessageFlowBody::getDestination() const { return destination; }
bool MessageFlowBody::hasDestination() const { return flags & (1 << 8); }
void MessageFlowBody::clearDestinationFlag() { flags &= ~(1 << 8); }

void MessageFlowBody::setUnit(uint8_t _unit) {
    unit = _unit;
    flags |= (1 << 9);
}
uint8_t MessageFlowBody::getUnit() const { return unit; }
bool MessageFlowBody::hasUnit() const { return flags & (1 << 9); }
void MessageFlowBody::clearUnitFlag() { flags &= ~(1 << 9); }

void MessageFlowBody::setValue(uint32_t _value) {
    value = _value;
    flags |= (1 << 10);
}
uint32_t MessageFlowBody::getValue() const { return value; }
bool MessageFlowBody::hasValue() const { return flags & (1 << 10); }
void MessageFlowBody::clearValueFlag() { flags &= ~(1 << 10); }

void MessageFlowBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(destination);
    if (flags & (1 << 9))
        buffer.putOctet(unit);
    if (flags & (1 << 10))
        buffer.putLong(value);
}

void MessageFlowBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageFlowBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(destination);
    if (flags & (1 << 9))
        unit = buffer.getOctet();
    if (flags & (1 << 10))
        value = buffer.getLong();
}

void MessageFlowBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageFlowBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + destination.size();
    if (flags & (1 << 9))
        total += 1;//unit
    if (flags & (1 << 10))
        total += 4;//value
    return total;
}

uint32_t MessageFlowBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageFlowBody::print(std::ostream& out) const
{
    out << "{MessageFlowBody: ";
    if (flags & (1 << 8))
        out << "destination=" << destination << "; ";
    if (flags & (1 << 9))
        out << "unit=" << (int) unit << "; ";
    if (flags & (1 << 10))
        out << "value=" << value << "; ";
    out << "}";
}
