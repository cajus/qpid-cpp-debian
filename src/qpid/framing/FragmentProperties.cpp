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


#include "qpid/framing/FragmentProperties.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FragmentProperties::setFirst(bool _first) {
    if (_first) flags |= (1 << 8);
    else flags &= ~(1 << 8);
}
bool FragmentProperties::getFirst() const { return flags & (1 << 8); }

void FragmentProperties::setLast(bool _last) {
    if (_last) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool FragmentProperties::getLast() const { return flags & (1 << 9); }

void FragmentProperties::setFragmentSize(uint64_t _fragmentSize) {
    fragmentSize = _fragmentSize;
    flags |= (1 << 10);
}
uint64_t FragmentProperties::getFragmentSize() const { return fragmentSize; }
bool FragmentProperties::hasFragmentSize() const { return flags & (1 << 10); }
void FragmentProperties::clearFragmentSizeFlag() { flags &= ~(1 << 10); }

void FragmentProperties::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 10))
        buffer.putLongLong(fragmentSize);
}

void FragmentProperties::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void FragmentProperties::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 10))
        fragmentSize = buffer.getLongLong();
}

void FragmentProperties::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t FragmentProperties::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 10))
        total += 8;//fragmentSize
    return total;
}

uint32_t FragmentProperties::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void FragmentProperties::print(std::ostream& out) const
{
    out << "{FragmentProperties: ";
    if (flags & (1 << 8))
        out << "first=" << getFirst() << "; ";
    if (flags & (1 << 9))
        out << "last=" << getLast() << "; ";
    if (flags & (1 << 10))
        out << "fragment-size=" << fragmentSize << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const FragmentProperties& s) 
    {
      s.print(out);
      return out;
    }

}
}
