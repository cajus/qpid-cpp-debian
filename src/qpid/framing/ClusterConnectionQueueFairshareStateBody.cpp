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


#include "qpid/framing/ClusterConnectionQueueFairshareStateBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConnectionQueueFairshareStateBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& ClusterConnectionQueueFairshareStateBody::getQueue() const { return queue; }
bool ClusterConnectionQueueFairshareStateBody::hasQueue() const { return flags & (1 << 8); }
void ClusterConnectionQueueFairshareStateBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ClusterConnectionQueueFairshareStateBody::setPosition(uint8_t _position) {
    position = _position;
    flags |= (1 << 9);
}
uint8_t ClusterConnectionQueueFairshareStateBody::getPosition() const { return position; }
bool ClusterConnectionQueueFairshareStateBody::hasPosition() const { return flags & (1 << 9); }
void ClusterConnectionQueueFairshareStateBody::clearPositionFlag() { flags &= ~(1 << 9); }

void ClusterConnectionQueueFairshareStateBody::setCount(uint8_t _count) {
    count = _count;
    flags |= (1 << 10);
}
uint8_t ClusterConnectionQueueFairshareStateBody::getCount() const { return count; }
bool ClusterConnectionQueueFairshareStateBody::hasCount() const { return flags & (1 << 10); }
void ClusterConnectionQueueFairshareStateBody::clearCountFlag() { flags &= ~(1 << 10); }

void ClusterConnectionQueueFairshareStateBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putOctet(position);
    if (flags & (1 << 10))
        buffer.putOctet(count);
}

void ClusterConnectionQueueFairshareStateBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionQueueFairshareStateBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        position = buffer.getOctet();
    if (flags & (1 << 10))
        count = buffer.getOctet();
}

void ClusterConnectionQueueFairshareStateBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionQueueFairshareStateBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1;//position
    if (flags & (1 << 10))
        total += 1;//count
    return total;
}

uint32_t ClusterConnectionQueueFairshareStateBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionQueueFairshareStateBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionQueueFairshareStateBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "position=" << (int) position << "; ";
    if (flags & (1 << 10))
        out << "count=" << (int) count << "; ";
    out << "}";
}
