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


#include "qpid/framing/ClusterDeliverToQueueBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterDeliverToQueueBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 65536) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& ClusterDeliverToQueueBody::getQueue() const { return queue; }
bool ClusterDeliverToQueueBody::hasQueue() const { return flags & (1 << 8); }
void ClusterDeliverToQueueBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ClusterDeliverToQueueBody::setMessage(const std::string& _message) {
    message = _message;
    flags |= (1 << 9);
}
const std::string& ClusterDeliverToQueueBody::getMessage() const { return message; }
bool ClusterDeliverToQueueBody::hasMessage() const { return flags & (1 << 9); }
void ClusterDeliverToQueueBody::clearMessageFlag() { flags &= ~(1 << 9); }

void ClusterDeliverToQueueBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(queue);
    if (flags & (1 << 9))
        buffer.putLongString(message);
}

void ClusterDeliverToQueueBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterDeliverToQueueBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(queue);
    if (flags & (1 << 9))
        buffer.getLongString(message);
}

void ClusterDeliverToQueueBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterDeliverToQueueBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + queue.size();
    if (flags & (1 << 9))
        total += 4 + message.size();
    return total;
}

uint32_t ClusterDeliverToQueueBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterDeliverToQueueBody::print(std::ostream& out) const
{
    out << "{ClusterDeliverToQueueBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "message=" << message << "; ";
    out << "}";
}
