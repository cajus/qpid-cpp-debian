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


#include "qpid/framing/DtxGetTimeoutResult.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void DtxGetTimeoutResult::setTimeout(uint32_t _timeout) {
    timeout = _timeout;
    flags |= (1 << 8);
}
uint32_t DtxGetTimeoutResult::getTimeout() const { return timeout; }
bool DtxGetTimeoutResult::hasTimeout() const { return flags & (1 << 8); }
void DtxGetTimeoutResult::clearTimeoutFlag() { flags &= ~(1 << 8); }

void DtxGetTimeoutResult::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLong(timeout);
}

void DtxGetTimeoutResult::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void DtxGetTimeoutResult::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        timeout = buffer.getLong();
}

void DtxGetTimeoutResult::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t DtxGetTimeoutResult::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 4;//timeout
    return total;
}

uint32_t DtxGetTimeoutResult::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void DtxGetTimeoutResult::print(std::ostream& out) const
{
    out << "{DtxGetTimeoutResult: ";
    if (flags & (1 << 8))
        out << "timeout=" << timeout << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const DtxGetTimeoutResult& s) 
    {
      s.print(out);
      return out;
    }

}
}
