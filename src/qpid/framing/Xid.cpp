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


#include "qpid/framing/Xid.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void Xid::setFormat(uint32_t _format) {
    format = _format;
    flags |= (1 << 8);
}
uint32_t Xid::getFormat() const { return format; }
bool Xid::hasFormat() const { return flags & (1 << 8); }
void Xid::clearFormatFlag() { flags &= ~(1 << 8); }

void Xid::setGlobalId(const std::string& _globalId) {
    globalId = _globalId;
    flags |= (1 << 9);
    if (globalId.size() >= 256) throw IllegalArgumentException("Value for globalId is too large");
}
const std::string& Xid::getGlobalId() const { return globalId; }
bool Xid::hasGlobalId() const { return flags & (1 << 9); }
void Xid::clearGlobalIdFlag() { flags &= ~(1 << 9); }

void Xid::setBranchId(const std::string& _branchId) {
    branchId = _branchId;
    flags |= (1 << 10);
    if (branchId.size() >= 256) throw IllegalArgumentException("Value for branchId is too large");
}
const std::string& Xid::getBranchId() const { return branchId; }
bool Xid::hasBranchId() const { return flags & (1 << 10); }
void Xid::clearBranchIdFlag() { flags &= ~(1 << 10); }

void Xid::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLong(format);
    if (flags & (1 << 9))
        buffer.putShortString(globalId);
    if (flags & (1 << 10))
        buffer.putShortString(branchId);
}

void Xid::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void Xid::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        format = buffer.getLong();
    if (flags & (1 << 9))
        buffer.getShortString(globalId);
    if (flags & (1 << 10))
        buffer.getShortString(branchId);
}

void Xid::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t Xid::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 4;//format
    if (flags & (1 << 9))
        total += 1 + globalId.size();
    if (flags & (1 << 10))
        total += 1 + branchId.size();
    return total;
}

uint32_t Xid::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void Xid::print(std::ostream& out) const
{
    out << "{Xid: ";
    if (flags & (1 << 8))
        out << "format=" << format << "; ";
    if (flags & (1 << 9))
        out << "global-id=" << globalId << "; ";
    if (flags & (1 << 10))
        out << "branch-id=" << branchId << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const Xid& s) 
    {
      s.print(out);
      return out;
    }

}
}
