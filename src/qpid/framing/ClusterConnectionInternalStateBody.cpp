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


#include "qpid/framing/ClusterConnectionInternalStateBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConnectionInternalStateBody::setType(const std::string& _type) {
    type = _type;
    flags |= (1 << 8);
    if (type.size() >= 256) throw IllegalArgumentException("Value for type is too large");
}
const std::string& ClusterConnectionInternalStateBody::getType() const { return type; }
bool ClusterConnectionInternalStateBody::hasType() const { return flags & (1 << 8); }
void ClusterConnectionInternalStateBody::clearTypeFlag() { flags &= ~(1 << 8); }

void ClusterConnectionInternalStateBody::setName(const std::string& _name) {
    name = _name;
    flags |= (1 << 9);
    if (name.size() >= 256) throw IllegalArgumentException("Value for name is too large");
}
const std::string& ClusterConnectionInternalStateBody::getName() const { return name; }
bool ClusterConnectionInternalStateBody::hasName() const { return flags & (1 << 9); }
void ClusterConnectionInternalStateBody::clearNameFlag() { flags &= ~(1 << 9); }

void ClusterConnectionInternalStateBody::setState(const FieldTable& _state) {
    state = _state;
    flags |= (1 << 10);
}
const FieldTable& ClusterConnectionInternalStateBody::getState() const { return state; }
FieldTable& ClusterConnectionInternalStateBody::getState() {
    flags |= (1 << 10);
    return state;
}
bool ClusterConnectionInternalStateBody::hasState() const { return flags & (1 << 10); }
void ClusterConnectionInternalStateBody::clearStateFlag() { flags &= ~(1 << 10); }

void ClusterConnectionInternalStateBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(type);
    if (flags & (1 << 9))
        buffer.putShortString(name);
    if (flags & (1 << 10))
        state.encode(buffer);
}

void ClusterConnectionInternalStateBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionInternalStateBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(type);
    if (flags & (1 << 9))
        buffer.getShortString(name);
    if (flags & (1 << 10))
        state.decode(buffer);
}

void ClusterConnectionInternalStateBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionInternalStateBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + type.size();
    if (flags & (1 << 9))
        total += 1 + name.size();
    if (flags & (1 << 10))
        total += state.encodedSize();
    return total;
}

uint32_t ClusterConnectionInternalStateBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionInternalStateBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionInternalStateBody: ";
    if (flags & (1 << 8))
        out << "type=" << type << "; ";
    if (flags & (1 << 9))
        out << "name=" << name << "; ";
    if (flags & (1 << 10))
        out << "state=" << state << "; ";
    out << "}";
}
