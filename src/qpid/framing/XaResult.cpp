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


#include "qpid/framing/XaResult.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void XaResult::setStatus(uint16_t _status) {
    status = _status;
    flags |= (1 << 8);
}
uint16_t XaResult::getStatus() const { return status; }
bool XaResult::hasStatus() const { return flags & (1 << 8); }
void XaResult::clearStatusFlag() { flags &= ~(1 << 8); }

void XaResult::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(status);
}

void XaResult::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void XaResult::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        status = buffer.getShort();
}

void XaResult::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t XaResult::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 2;//status
    return total;
}

uint32_t XaResult::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void XaResult::print(std::ostream& out) const
{
    out << "{XaResult: ";
    if (flags & (1 << 8))
        out << "status=" << status << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const XaResult& s) 
    {
      s.print(out);
      return out;
    }

}
}
