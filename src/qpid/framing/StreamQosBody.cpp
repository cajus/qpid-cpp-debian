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


#include "qpid/framing/StreamQosBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void StreamQosBody::setPrefetchSize(uint32_t _prefetchSize) {
    prefetchSize = _prefetchSize;
    flags |= (1 << 8);
}
uint32_t StreamQosBody::getPrefetchSize() const { return prefetchSize; }
bool StreamQosBody::hasPrefetchSize() const { return flags & (1 << 8); }
void StreamQosBody::clearPrefetchSizeFlag() { flags &= ~(1 << 8); }

void StreamQosBody::setPrefetchCount(uint16_t _prefetchCount) {
    prefetchCount = _prefetchCount;
    flags |= (1 << 9);
}
uint16_t StreamQosBody::getPrefetchCount() const { return prefetchCount; }
bool StreamQosBody::hasPrefetchCount() const { return flags & (1 << 9); }
void StreamQosBody::clearPrefetchCountFlag() { flags &= ~(1 << 9); }

void StreamQosBody::setConsumeRate(uint32_t _consumeRate) {
    consumeRate = _consumeRate;
    flags |= (1 << 10);
}
uint32_t StreamQosBody::getConsumeRate() const { return consumeRate; }
bool StreamQosBody::hasConsumeRate() const { return flags & (1 << 10); }
void StreamQosBody::clearConsumeRateFlag() { flags &= ~(1 << 10); }

void StreamQosBody::setGlobal(bool _global) {
    if (_global) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool StreamQosBody::getGlobal() const { return flags & (1 << 11); }

void StreamQosBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLong(prefetchSize);
    if (flags & (1 << 9))
        buffer.putShort(prefetchCount);
    if (flags & (1 << 10))
        buffer.putLong(consumeRate);
}

void StreamQosBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void StreamQosBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        prefetchSize = buffer.getLong();
    if (flags & (1 << 9))
        prefetchCount = buffer.getShort();
    if (flags & (1 << 10))
        consumeRate = buffer.getLong();
}

void StreamQosBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t StreamQosBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 4;//prefetchSize
    if (flags & (1 << 9))
        total += 2;//prefetchCount
    if (flags & (1 << 10))
        total += 4;//consumeRate
    return total;
}

uint32_t StreamQosBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void StreamQosBody::print(std::ostream& out) const
{
    out << "{StreamQosBody: ";
    if (flags & (1 << 8))
        out << "prefetch-size=" << prefetchSize << "; ";
    if (flags & (1 << 9))
        out << "prefetch-count=" << prefetchCount << "; ";
    if (flags & (1 << 10))
        out << "consume-rate=" << consumeRate << "; ";
    if (flags & (1 << 11))
        out << "global=" << getGlobal() << "; ";
    out << "}";
}
