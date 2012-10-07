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


#include "qpid/framing/MessageTransferBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageTransferBody::setDestination(const std::string& _destination) {
    destination = _destination;
    flags |= (1 << 8);
    if (destination.size() >= 256) throw IllegalArgumentException("Value for destination is too large");
}
const std::string& MessageTransferBody::getDestination() const { return destination; }
bool MessageTransferBody::hasDestination() const { return flags & (1 << 8); }
void MessageTransferBody::clearDestinationFlag() { flags &= ~(1 << 8); }

void MessageTransferBody::setAcceptMode(uint8_t _acceptMode) {
    acceptMode = _acceptMode;
    flags |= (1 << 9);
}
uint8_t MessageTransferBody::getAcceptMode() const { return acceptMode; }
bool MessageTransferBody::hasAcceptMode() const { return flags & (1 << 9); }
void MessageTransferBody::clearAcceptModeFlag() { flags &= ~(1 << 9); }

void MessageTransferBody::setAcquireMode(uint8_t _acquireMode) {
    acquireMode = _acquireMode;
    flags |= (1 << 10);
}
uint8_t MessageTransferBody::getAcquireMode() const { return acquireMode; }
bool MessageTransferBody::hasAcquireMode() const { return flags & (1 << 10); }
void MessageTransferBody::clearAcquireModeFlag() { flags &= ~(1 << 10); }

void MessageTransferBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(destination);
    if (flags & (1 << 9))
        buffer.putOctet(acceptMode);
    if (flags & (1 << 10))
        buffer.putOctet(acquireMode);
}

void MessageTransferBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageTransferBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(destination);
    if (flags & (1 << 9))
        acceptMode = buffer.getOctet();
    if (flags & (1 << 10))
        acquireMode = buffer.getOctet();
}

void MessageTransferBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageTransferBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + destination.size();
    if (flags & (1 << 9))
        total += 1;//acceptMode
    if (flags & (1 << 10))
        total += 1;//acquireMode
    return total;
}

uint32_t MessageTransferBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageTransferBody::print(std::ostream& out) const
{
    out << "{MessageTransferBody: ";
    if (flags & (1 << 8))
        out << "destination=" << destination << "; ";
    if (flags & (1 << 9))
        out << "accept-mode=" << (int) acceptMode << "; ";
    if (flags & (1 << 10))
        out << "acquire-mode=" << (int) acquireMode << "; ";
    out << "}";
}
