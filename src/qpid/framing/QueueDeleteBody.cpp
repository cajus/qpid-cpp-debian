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


#include "qpid/framing/QueueDeleteBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void QueueDeleteBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& QueueDeleteBody::getQueue() const { return queue; }
bool QueueDeleteBody::hasQueue() const { return flags & (1 << 8); }
void QueueDeleteBody::clearQueueFlag() { flags &= ~(1 << 8); }

void QueueDeleteBody::setIfUnused(bool _ifUnused) {
    if (_ifUnused) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool QueueDeleteBody::getIfUnused() const { return flags & (1 << 9); }

void QueueDeleteBody::setIfEmpty(bool _ifEmpty) {
    if (_ifEmpty) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool QueueDeleteBody::getIfEmpty() const { return flags & (1 << 10); }

void QueueDeleteBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
}

void QueueDeleteBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void QueueDeleteBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
}

void QueueDeleteBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t QueueDeleteBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    return total;
}

uint32_t QueueDeleteBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void QueueDeleteBody::print(std::ostream& out) const
{
    out << "{QueueDeleteBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "if-unused=" << getIfUnused() << "; ";
    if (flags & (1 << 10))
        out << "if-empty=" << getIfEmpty() << "; ";
    out << "}";
}
