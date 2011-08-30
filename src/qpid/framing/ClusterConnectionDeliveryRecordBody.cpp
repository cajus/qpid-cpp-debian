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


#include "qpid/framing/ClusterConnectionDeliveryRecordBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionDeliveryRecordBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
}
const std::string& ClusterConnectionDeliveryRecordBody::getQueue() const { return queue; }
bool ClusterConnectionDeliveryRecordBody::hasQueue() const { return flags & (1 << 8); }
void ClusterConnectionDeliveryRecordBody::clearQueueFlag() { flags &= ~(1 << 8); }

void ClusterConnectionDeliveryRecordBody::setPosition(const SequenceNumber& _position) {
    position = _position;
    flags |= (1 << 9);
}
SequenceNumber ClusterConnectionDeliveryRecordBody::getPosition() const { return position; }
bool ClusterConnectionDeliveryRecordBody::hasPosition() const { return flags & (1 << 9); }
void ClusterConnectionDeliveryRecordBody::clearPositionFlag() { flags &= ~(1 << 9); }

void ClusterConnectionDeliveryRecordBody::setTag(const std::string& _tag) {
    tag = _tag;
    flags |= (1 << 10);
}
const std::string& ClusterConnectionDeliveryRecordBody::getTag() const { return tag; }
bool ClusterConnectionDeliveryRecordBody::hasTag() const { return flags & (1 << 10); }
void ClusterConnectionDeliveryRecordBody::clearTagFlag() { flags &= ~(1 << 10); }

void ClusterConnectionDeliveryRecordBody::setId(const SequenceNumber& _id) {
    id = _id;
    flags |= (1 << 11);
}
SequenceNumber ClusterConnectionDeliveryRecordBody::getId() const { return id; }
bool ClusterConnectionDeliveryRecordBody::hasId() const { return flags & (1 << 11); }
void ClusterConnectionDeliveryRecordBody::clearIdFlag() { flags &= ~(1 << 11); }

void ClusterConnectionDeliveryRecordBody::setAcquired(bool _acquired) {
    if (_acquired) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool ClusterConnectionDeliveryRecordBody::getAcquired() const { return flags & (1 << 12); }

void ClusterConnectionDeliveryRecordBody::setAccepted(bool _accepted) {
    if (_accepted) flags |= (1 << 13);
    else flags &= ~(1 << 13);
}
bool ClusterConnectionDeliveryRecordBody::getAccepted() const { return flags & (1 << 13); }

void ClusterConnectionDeliveryRecordBody::setCancelled(bool _cancelled) {
    if (_cancelled) flags |= (1 << 14);
    else flags &= ~(1 << 14);
}
bool ClusterConnectionDeliveryRecordBody::getCancelled() const { return flags & (1 << 14); }

void ClusterConnectionDeliveryRecordBody::setCompleted(bool _completed) {
    if (_completed) flags |= (1 << 15);
    else flags &= ~(1 << 15);
}
bool ClusterConnectionDeliveryRecordBody::getCompleted() const { return flags & (1 << 15); }

void ClusterConnectionDeliveryRecordBody::setEnded(bool _ended) {
    if (_ended) flags |= (1 << 0);
    else flags &= ~(1 << 0);
}
bool ClusterConnectionDeliveryRecordBody::getEnded() const { return flags & (1 << 0); }

void ClusterConnectionDeliveryRecordBody::setWindowing(bool _windowing) {
    if (_windowing) flags |= (1 << 1);
    else flags &= ~(1 << 1);
}
bool ClusterConnectionDeliveryRecordBody::getWindowing() const { return flags & (1 << 1); }

void ClusterConnectionDeliveryRecordBody::setEnqueued(bool _enqueued) {
    if (_enqueued) flags |= (1 << 2);
    else flags &= ~(1 << 2);
}
bool ClusterConnectionDeliveryRecordBody::getEnqueued() const { return flags & (1 << 2); }

void ClusterConnectionDeliveryRecordBody::setCredit(uint32_t _credit) {
    credit = _credit;
    flags |= (1 << 3);
}
uint32_t ClusterConnectionDeliveryRecordBody::getCredit() const { return credit; }
bool ClusterConnectionDeliveryRecordBody::hasCredit() const { return flags & (1 << 3); }
void ClusterConnectionDeliveryRecordBody::clearCreditFlag() { flags &= ~(1 << 3); }

void ClusterConnectionDeliveryRecordBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        position.encode(buffer);
    if (flags & (1 << 10))
        buffer.putShortString(tag);
    if (flags & (1 << 11))
        id.encode(buffer);
    if (flags & (1 << 3))
        buffer.putLong(credit);
}

void ClusterConnectionDeliveryRecordBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionDeliveryRecordBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        position.decode(buffer);
    if (flags & (1 << 10))
        buffer.getShortString(tag);
    if (flags & (1 << 11))
        id.decode(buffer);
    if (flags & (1 << 3))
        credit = buffer.getLong();
}

void ClusterConnectionDeliveryRecordBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionDeliveryRecordBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += position.encodedSize();
    if (flags & (1 << 10))
        total += 1 + tag.size();
    if (flags & (1 << 11))
        total += id.encodedSize();
    if (flags & (1 << 3))
        total += 4;//credit
    return total;
}

uint32_t ClusterConnectionDeliveryRecordBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionDeliveryRecordBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionDeliveryRecordBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "position=" << position << "; ";
    if (flags & (1 << 10))
        out << "tag=" << tag << "; ";
    if (flags & (1 << 11))
        out << "id=" << id << "; ";
    if (flags & (1 << 12))
        out << "acquired=" << getAcquired() << "; ";
    if (flags & (1 << 13))
        out << "accepted=" << getAccepted() << "; ";
    if (flags & (1 << 14))
        out << "cancelled=" << getCancelled() << "; ";
    if (flags & (1 << 15))
        out << "completed=" << getCompleted() << "; ";
    if (flags & (1 << 0))
        out << "ended=" << getEnded() << "; ";
    if (flags & (1 << 1))
        out << "windowing=" << getWindowing() << "; ";
    if (flags & (1 << 2))
        out << "enqueued=" << getEnqueued() << "; ";
    if (flags & (1 << 3))
        out << "credit=" << credit << "; ";
    out << "}";
}
