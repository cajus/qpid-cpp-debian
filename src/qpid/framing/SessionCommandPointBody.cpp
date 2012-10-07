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


#include "qpid/framing/SessionCommandPointBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void SessionCommandPointBody::setCommandId(const SequenceNumber& _commandId) {
    commandId = _commandId;
    flags |= (1 << 8);
}
SequenceNumber SessionCommandPointBody::getCommandId() const { return commandId; }
bool SessionCommandPointBody::hasCommandId() const { return flags & (1 << 8); }
void SessionCommandPointBody::clearCommandIdFlag() { flags &= ~(1 << 8); }

void SessionCommandPointBody::setCommandOffset(uint64_t _commandOffset) {
    commandOffset = _commandOffset;
    flags |= (1 << 9);
}
uint64_t SessionCommandPointBody::getCommandOffset() const { return commandOffset; }
bool SessionCommandPointBody::hasCommandOffset() const { return flags & (1 << 9); }
void SessionCommandPointBody::clearCommandOffsetFlag() { flags &= ~(1 << 9); }

void SessionCommandPointBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        commandId.encode(buffer);
    if (flags & (1 << 9))
        buffer.putLongLong(commandOffset);
}

void SessionCommandPointBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void SessionCommandPointBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        commandId.decode(buffer);
    if (flags & (1 << 9))
        commandOffset = buffer.getLongLong();
}

void SessionCommandPointBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t SessionCommandPointBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += commandId.encodedSize();
    if (flags & (1 << 9))
        total += 8;//commandOffset
    return total;
}

uint32_t SessionCommandPointBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void SessionCommandPointBody::print(std::ostream& out) const
{
    out << "{SessionCommandPointBody: ";
    if (flags & (1 << 8))
        out << "command-id=" << commandId << "; ";
    if (flags & (1 << 9))
        out << "command-offset=" << commandOffset << "; ";
    out << "}";
}
