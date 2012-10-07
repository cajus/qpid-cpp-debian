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


#include "qpid/framing/FileQosBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FileQosBody::setPrefetchSize(uint32_t _prefetchSize) {
    prefetchSize = _prefetchSize;
    flags |= (1 << 8);
}
uint32_t FileQosBody::getPrefetchSize() const { return prefetchSize; }
bool FileQosBody::hasPrefetchSize() const { return flags & (1 << 8); }
void FileQosBody::clearPrefetchSizeFlag() { flags &= ~(1 << 8); }

void FileQosBody::setPrefetchCount(uint16_t _prefetchCount) {
    prefetchCount = _prefetchCount;
    flags |= (1 << 9);
}
uint16_t FileQosBody::getPrefetchCount() const { return prefetchCount; }
bool FileQosBody::hasPrefetchCount() const { return flags & (1 << 9); }
void FileQosBody::clearPrefetchCountFlag() { flags &= ~(1 << 9); }

void FileQosBody::setGlobal(bool _global) {
    if (_global) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool FileQosBody::getGlobal() const { return flags & (1 << 10); }

void FileQosBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLong(prefetchSize);
    if (flags & (1 << 9))
        buffer.putShort(prefetchCount);
}

void FileQosBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void FileQosBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        prefetchSize = buffer.getLong();
    if (flags & (1 << 9))
        prefetchCount = buffer.getShort();
}

void FileQosBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t FileQosBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 4;//prefetchSize
    if (flags & (1 << 9))
        total += 2;//prefetchCount
    return total;
}

uint32_t FileQosBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void FileQosBody::print(std::ostream& out) const
{
    out << "{FileQosBody: ";
    if (flags & (1 << 8))
        out << "prefetch-size=" << prefetchSize << "; ";
    if (flags & (1 << 9))
        out << "prefetch-count=" << prefetchCount << "; ";
    if (flags & (1 << 10))
        out << "global=" << getGlobal() << "; ";
    out << "}";
}
