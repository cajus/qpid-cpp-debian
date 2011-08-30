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


#include "qpid/framing/ClusterConnectionQueueObserverStateBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionQueueObserverStateBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
}
const std::string& ClusterConnectionQueueObserverStateBody::getQueue() const { return queue; }
bool ClusterConnectionQueueObserverStateBody::hasQueue() const { return flags & (1 << 8); }
void ClusterConnectionQueueObserverStateBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ClusterConnectionQueueObserverStateBody::setObserverId(const std::string& _observerId) {
    observerId = _observerId;
    flags |= (1 << 9);
}
const std::string& ClusterConnectionQueueObserverStateBody::getObserverId() const { return observerId; }
bool ClusterConnectionQueueObserverStateBody::hasObserverId() const { return flags & (1 << 9); }
void ClusterConnectionQueueObserverStateBody::clearObserverIdFlag() { flags &= ~(1 << 9); }

void ClusterConnectionQueueObserverStateBody::setState(const FieldTable& _state) {
    state = _state;
    flags |= (1 << 10);
}
const FieldTable& ClusterConnectionQueueObserverStateBody::getState() const { return state; }
FieldTable& ClusterConnectionQueueObserverStateBody::getState() {
    flags |= (1 << 10);
    return state;
}
bool ClusterConnectionQueueObserverStateBody::hasState() const { return flags & (1 << 10); }
void ClusterConnectionQueueObserverStateBody::clearStateFlag() { flags &= ~(1 << 10); }

void ClusterConnectionQueueObserverStateBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putShortString(observerId);
    if (flags & (1 << 10))
        state.encode(buffer);
}

void ClusterConnectionQueueObserverStateBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionQueueObserverStateBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        buffer.getShortString(observerId);
    if (flags & (1 << 10))
        state.decode(buffer);
}

void ClusterConnectionQueueObserverStateBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionQueueObserverStateBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1 + observerId.size();
    if (flags & (1 << 10))
        total += state.encodedSize();
    return total;
}

uint32_t ClusterConnectionQueueObserverStateBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionQueueObserverStateBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionQueueObserverStateBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "observer-id=" << observerId << "; ";
    if (flags & (1 << 10))
        out << "state=" << state << "; ";
    out << "}";
}
