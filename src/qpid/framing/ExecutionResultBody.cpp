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


#include "qpid/framing/ExecutionResultBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExecutionResultBody::setCommandId(const SequenceNumber& _commandId) {
    commandId = _commandId;
    flags |= (1 << 8);
}
SequenceNumber ExecutionResultBody::getCommandId() const { return commandId; }
bool ExecutionResultBody::hasCommandId() const { return flags & (1 << 8); }
void ExecutionResultBody::clearCommandIdFlag() { flags &= ~(1 << 8); }

void ExecutionResultBody::setValue(const std::string& _value) {
    value = _value;
    flags |= (1 << 9);
}
const std::string& ExecutionResultBody::getValue() const { return value; }
bool ExecutionResultBody::hasValue() const { return flags & (1 << 9); }
void ExecutionResultBody::clearValueFlag() { flags &= ~(1 << 9); }

void ExecutionResultBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        commandId.encode(buffer);
    if (flags & (1 << 9))
        buffer.putLongString(value);
}

void ExecutionResultBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExecutionResultBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        commandId.decode(buffer);
    if (flags & (1 << 9))
        buffer.getLongString(value);
}

void ExecutionResultBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExecutionResultBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += commandId.encodedSize();
    if (flags & (1 << 9))
        total += 4 + value.size();
    return total;
}

uint32_t ExecutionResultBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExecutionResultBody::print(std::ostream& out) const
{
    out << "{ExecutionResultBody: ";
    if (flags & (1 << 8))
        out << "command-id=" << commandId << "; ";
    if (flags & (1 << 9))
        out << "value=" << value << "; ";
    out << "}";
}
