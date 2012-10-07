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


#include "qpid/framing/StreamDeliverBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void StreamDeliverBody::setConsumerTag(const std::string& _consumerTag) {
    consumerTag = _consumerTag;
    flags |= (1 << 8);
    if (consumerTag.size() >= 256) throw IllegalArgumentException("Value for consumerTag is too large");
}
const std::string& StreamDeliverBody::getConsumerTag() const { return consumerTag; }
bool StreamDeliverBody::hasConsumerTag() const { return flags & (1 << 8); }
void StreamDeliverBody::clearConsumerTagFlag() { flags &= ~(1 << 8); }

void StreamDeliverBody::setDeliveryTag(uint64_t _deliveryTag) {
    deliveryTag = _deliveryTag;
    flags |= (1 << 9);
}
uint64_t StreamDeliverBody::getDeliveryTag() const { return deliveryTag; }
bool StreamDeliverBody::hasDeliveryTag() const { return flags & (1 << 9); }
void StreamDeliverBody::clearDeliveryTagFlag() { flags &= ~(1 << 9); }

void StreamDeliverBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 10);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& StreamDeliverBody::getExchange() const { return exchange; }
bool StreamDeliverBody::hasExchange() const { return flags & (1 << 10); }
void StreamDeliverBody::clearExchangeFlag() { flags &= ~(1 << 10); }

void StreamDeliverBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 11);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& StreamDeliverBody::getQueue() const { return queue; }
bool StreamDeliverBody::hasQueue() const { return flags & (1 << 11); }
void StreamDeliverBody::clearQueueFlag() { flags &= ~(1 << 11); }

void StreamDeliverBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(consumerTag);
    if (flags & (1 << 9))
        buffer.putLongLong(deliveryTag);
    if (flags & (1 << 10))
        buffer.putShortString(exchange);
    if (flags & (1 << 11))
        buffer.putShortString(queue);
}

void StreamDeliverBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void StreamDeliverBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(consumerTag);
    if (flags & (1 << 9))
        deliveryTag = buffer.getLongLong();
    if (flags & (1 << 10))
        buffer.getShortString(exchange);
    if (flags & (1 << 11))
        buffer.getShortString(queue);
}

void StreamDeliverBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t StreamDeliverBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + consumerTag.size();
    if (flags & (1 << 9))
        total += 8;//deliveryTag
    if (flags & (1 << 10))
        total += 1 + exchange.size();
    if (flags & (1 << 11))
        total += 1 + queue.size();
    return total;
}

uint32_t StreamDeliverBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void StreamDeliverBody::print(std::ostream& out) const
{
    out << "{StreamDeliverBody: ";
    if (flags & (1 << 8))
        out << "consumer-tag=" << consumerTag << "; ";
    if (flags & (1 << 9))
        out << "delivery-tag=" << deliveryTag << "; ";
    if (flags & (1 << 10))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 11))
        out << "queue=" << queue << "; ";
    out << "}";
}
