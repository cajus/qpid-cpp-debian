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


#include "qpid/framing/QueuePurgeBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void QueuePurgeBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& QueuePurgeBody::getQueue() const { return queue; }
bool QueuePurgeBody::hasQueue() const { return flags & (1 << 8); }
void QueuePurgeBody::clearQueueFlag() { flags &= ~(1 << 8); }

void QueuePurgeBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
}

void QueuePurgeBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void QueuePurgeBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
}

void QueuePurgeBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t QueuePurgeBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    return total;
}

uint32_t QueuePurgeBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void QueuePurgeBody::print(std::ostream& out) const
{
    out << "{QueuePurgeBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    out << "}";
}
