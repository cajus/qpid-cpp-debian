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


#include "qpid/framing/ClusterConnectionTxPublishBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionTxPublishBody::setQueues(const Array& _queues) {
    queues = _queues;
    flags |= (1 << 8);
}
const Array& ClusterConnectionTxPublishBody::getQueues() const { return queues; }
bool ClusterConnectionTxPublishBody::hasQueues() const { return flags & (1 << 8); }
void ClusterConnectionTxPublishBody::clearQueuesFlag() { flags &= ~(1 << 8); }

void ClusterConnectionTxPublishBody::setDelivered(bool _delivered) {
    if (_delivered) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ClusterConnectionTxPublishBody::getDelivered() const { return flags & (1 << 9); }

void ClusterConnectionTxPublishBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        queues.encode(buffer);
}

void ClusterConnectionTxPublishBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionTxPublishBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        queues.decode(buffer);
}

void ClusterConnectionTxPublishBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionTxPublishBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += queues.encodedSize();
    return total;
}

uint32_t ClusterConnectionTxPublishBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionTxPublishBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionTxPublishBody: ";
    if (flags & (1 << 8))
        out << "queues=" << queues << "; ";
    if (flags & (1 << 9))
        out << "delivered=" << getDelivered() << "; ";
    out << "}";
}
