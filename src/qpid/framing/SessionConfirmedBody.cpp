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


#include "qpid/framing/SessionConfirmedBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void SessionConfirmedBody::setCommands(const SequenceSet& _commands) {
    commands = _commands;
    flags |= (1 << 8);
}
const SequenceSet& SessionConfirmedBody::getCommands() const { return commands; }
bool SessionConfirmedBody::hasCommands() const { return flags & (1 << 8); }
void SessionConfirmedBody::clearCommandsFlag() { flags &= ~(1 << 8); }

void SessionConfirmedBody::setFragments(const Array& _fragments) {
    fragments = _fragments;
    flags |= (1 << 9);
}
const Array& SessionConfirmedBody::getFragments() const { return fragments; }
bool SessionConfirmedBody::hasFragments() const { return flags & (1 << 9); }
void SessionConfirmedBody::clearFragmentsFlag() { flags &= ~(1 << 9); }

void SessionConfirmedBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        commands.encode(buffer);
    if (flags & (1 << 9))
        fragments.encode(buffer);
}

void SessionConfirmedBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void SessionConfirmedBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        commands.decode(buffer);
    if (flags & (1 << 9))
        fragments.decode(buffer);
}

void SessionConfirmedBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t SessionConfirmedBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += commands.encodedSize();
    if (flags & (1 << 9))
        total += fragments.encodedSize();
    return total;
}

uint32_t SessionConfirmedBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void SessionConfirmedBody::print(std::ostream& out) const
{
    out << "{SessionConfirmedBody: ";
    if (flags & (1 << 8))
        out << "commands=" << commands << "; ";
    if (flags & (1 << 9))
        out << "fragments=" << fragments << "; ";
    out << "}";
}
