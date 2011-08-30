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


#include "qpid/framing/ClusterConnectionAddQueueListenerBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionAddQueueListenerBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
}
const std::string& ClusterConnectionAddQueueListenerBody::getQueue() const { return queue; }
bool ClusterConnectionAddQueueListenerBody::hasQueue() const { return flags & (1 << 8); }
void ClusterConnectionAddQueueListenerBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ClusterConnectionAddQueueListenerBody::setConsumer(uint32_t _consumer) {
    consumer = _consumer;
    flags |= (1 << 9);
}
uint32_t ClusterConnectionAddQueueListenerBody::getConsumer() const { return consumer; }
bool ClusterConnectionAddQueueListenerBody::hasConsumer() const { return flags & (1 << 9); }
void ClusterConnectionAddQueueListenerBody::clearConsumerFlag() { flags &= ~(1 << 9); }

void ClusterConnectionAddQueueListenerBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putLong(consumer);
}

void ClusterConnectionAddQueueListenerBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionAddQueueListenerBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        consumer = buffer.getLong();
}

void ClusterConnectionAddQueueListenerBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionAddQueueListenerBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 4;//consumer
    return total;
}

uint32_t ClusterConnectionAddQueueListenerBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionAddQueueListenerBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionAddQueueListenerBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "consumer=" << consumer << "; ";
    out << "}";
}
