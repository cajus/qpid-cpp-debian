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


#include "qpid/framing/ClusterConnectionQueuePositionBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConnectionQueuePositionBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& ClusterConnectionQueuePositionBody::getQueue() const { return queue; }
bool ClusterConnectionQueuePositionBody::hasQueue() const { return flags & (1 << 8); }
void ClusterConnectionQueuePositionBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ClusterConnectionQueuePositionBody::setPosition(const SequenceNumber& _position) {
    position = _position;
    flags |= (1 << 9);
}
SequenceNumber ClusterConnectionQueuePositionBody::getPosition() const { return position; }
bool ClusterConnectionQueuePositionBody::hasPosition() const { return flags & (1 << 9); }
void ClusterConnectionQueuePositionBody::clearPositionFlag() { flags &= ~(1 << 9); }

void ClusterConnectionQueuePositionBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        position.encode(buffer);
}

void ClusterConnectionQueuePositionBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionQueuePositionBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        position.decode(buffer);
}

void ClusterConnectionQueuePositionBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionQueuePositionBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += position.encodedSize();
    return total;
}

uint32_t ClusterConnectionQueuePositionBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionQueuePositionBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionQueuePositionBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "position=" << position << "; ";
    out << "}";
}
