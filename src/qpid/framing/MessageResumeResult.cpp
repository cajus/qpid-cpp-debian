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


#include "qpid/framing/MessageResumeResult.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageResumeResult::setOffset(uint64_t _offset) {
    offset = _offset;
    flags |= (1 << 8);
}
uint64_t MessageResumeResult::getOffset() const { return offset; }
bool MessageResumeResult::hasOffset() const { return flags & (1 << 8); }
void MessageResumeResult::clearOffsetFlag() { flags &= ~(1 << 8); }

void MessageResumeResult::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongLong(offset);
}

void MessageResumeResult::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void MessageResumeResult::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        offset = buffer.getLongLong();
}

void MessageResumeResult::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t MessageResumeResult::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 8;//offset
    return total;
}

uint32_t MessageResumeResult::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void MessageResumeResult::print(std::ostream& out) const
{
    out << "{MessageResumeResult: ";
    if (flags & (1 << 8))
        out << "offset=" << offset << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const MessageResumeResult& s) 
    {
      s.print(out);
      return out;
    }

}
}
