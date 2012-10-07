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


#include "qpid/framing/SessionDetachedBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void SessionDetachedBody::setName(const std::string& _name) {
    name = _name;
    flags |= (1 << 8);
    if (name.size() >= 65536) throw IllegalArgumentException("Value for name is too large");
}
const std::string& SessionDetachedBody::getName() const { return name; }
bool SessionDetachedBody::hasName() const { return flags & (1 << 8); }
void SessionDetachedBody::clearNameFlag() { flags &= ~(1 << 8); }

void SessionDetachedBody::setCode(uint8_t _code) {
    code = _code;
    flags |= (1 << 9);
}
uint8_t SessionDetachedBody::getCode() const { return code; }
bool SessionDetachedBody::hasCode() const { return flags & (1 << 9); }
void SessionDetachedBody::clearCodeFlag() { flags &= ~(1 << 9); }

void SessionDetachedBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(name);
    if (flags & (1 << 9))
        buffer.putOctet(code);
}

void SessionDetachedBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void SessionDetachedBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(name);
    if (flags & (1 << 9))
        code = buffer.getOctet();
}

void SessionDetachedBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t SessionDetachedBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 2 + name.size();
    if (flags & (1 << 9))
        total += 1;//code
    return total;
}

uint32_t SessionDetachedBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void SessionDetachedBody::print(std::ostream& out) const
{
    out << "{SessionDetachedBody: ";
    if (flags & (1 << 8))
        out << "name=" << name << "; ";
    if (flags & (1 << 9))
        out << "code=" << (int) code << "; ";
    out << "}";
}
