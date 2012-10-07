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


#include "qpid/framing/Header.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void Header::setSync(bool _sync) {
    if (_sync) flags |= (1 << 0);
    else flags &= ~(1 << 0);
}
bool Header::getSync() const { return flags & (1 << 0); }

void Header::encodeStructBody(Buffer& buffer) const
{
    buffer.putOctet(flags);
}

void Header::encode(Buffer& buffer) const
{
    buffer.putOctet(bodySize());
    encodeStructBody(buffer);
}

void Header::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getOctet();
}

void Header::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getOctet();
    decodeStructBody(buffer);
}

uint32_t Header::bodySize() const
{
    uint32_t total = 0;
    total += 1;
    return total;
}

uint32_t Header::encodedSize() const {
    uint32_t total = bodySize();
total += 1/*size field*/;
    return total;
}

void Header::print(std::ostream& out) const
{
    out << "{Header: ";
    if (flags & (1 << 0))
        out << "sync=" << getSync() << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const Header& s) 
    {
      s.print(out);
      return out;
    }

}
}
