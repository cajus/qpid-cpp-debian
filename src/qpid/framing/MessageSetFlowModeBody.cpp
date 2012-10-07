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


#include "qpid/framing/MessageSetFlowModeBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageSetFlowModeBody::setDestination(const std::string& _destination) {
    destination = _destination;
    flags |= (1 << 8);
    if (destination.size() >= 256) throw IllegalArgumentException("Value for destination is too large");
}
const std::string& MessageSetFlowModeBody::getDestination() const { return destination; }
bool MessageSetFlowModeBody::hasDestination() const { return flags & (1 << 8); }
void MessageSetFlowModeBody::clearDestinationFlag() { flags &= ~(1 << 8); }

void MessageSetFlowModeBody::setFlowMode(uint8_t _flowMode) {
    flowMode = _flowMode;
    flags |= (1 << 9);
}
uint8_t MessageSetFlowModeBody::getFlowMode() const { return flowMode; }
bool MessageSetFlowModeBody::hasFlowMode() const { return flags & (1 << 9); }
void MessageSetFlowModeBody::clearFlowModeFlag() { flags &= ~(1 << 9); }

void MessageSetFlowModeBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(destination);
    if (flags & (1 << 9))
        buffer.putOctet(flowMode);
}

void MessageSetFlowModeBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageSetFlowModeBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(destination);
    if (flags & (1 << 9))
        flowMode = buffer.getOctet();
}

void MessageSetFlowModeBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageSetFlowModeBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + destination.size();
    if (flags & (1 << 9))
        total += 1;//flowMode
    return total;
}

uint32_t MessageSetFlowModeBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageSetFlowModeBody::print(std::ostream& out) const
{
    out << "{MessageSetFlowModeBody: ";
    if (flags & (1 << 8))
        out << "destination=" << destination << "; ";
    if (flags & (1 << 9))
        out << "flow-mode=" << (int) flowMode << "; ";
    out << "}";
}
