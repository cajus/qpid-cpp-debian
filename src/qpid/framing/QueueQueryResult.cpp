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


#include "qpid/framing/QueueQueryResult.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void QueueQueryResult::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& QueueQueryResult::getQueue() const { return queue; }
bool QueueQueryResult::hasQueue() const { return flags & (1 << 8); }
void QueueQueryResult::clearQueueFlag() { flags &= ~(1 << 8); }

void QueueQueryResult::setAlternateExchange(const std::string& _alternateExchange) {
    alternateExchange = _alternateExchange;
    flags |= (1 << 9);
    if (alternateExchange.size() >= 256) throw IllegalArgumentException("Value for alternateExchange is too large");
}
const std::string& QueueQueryResult::getAlternateExchange() const { return alternateExchange; }
bool QueueQueryResult::hasAlternateExchange() const { return flags & (1 << 9); }
void QueueQueryResult::clearAlternateExchangeFlag() { flags &= ~(1 << 9); }

void QueueQueryResult::setDurable(bool _durable) {
    if (_durable) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool QueueQueryResult::getDurable() const { return flags & (1 << 10); }

void QueueQueryResult::setExclusive(bool _exclusive) {
    if (_exclusive) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool QueueQueryResult::getExclusive() const { return flags & (1 << 11); }

void QueueQueryResult::setAutoDelete(bool _autoDelete) {
    if (_autoDelete) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool QueueQueryResult::getAutoDelete() const { return flags & (1 << 12); }

void QueueQueryResult::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 13);
}
const FieldTable& QueueQueryResult::getArguments() const { return arguments; }
FieldTable& QueueQueryResult::getArguments() {
    flags |= (1 << 13);
    return arguments;
}
bool QueueQueryResult::hasArguments() const { return flags & (1 << 13); }
void QueueQueryResult::clearArgumentsFlag() { flags &= ~(1 << 13); }

void QueueQueryResult::setMessageCount(uint32_t _messageCount) {
    messageCount = _messageCount;
    flags |= (1 << 14);
}
uint32_t QueueQueryResult::getMessageCount() const { return messageCount; }
bool QueueQueryResult::hasMessageCount() const { return flags & (1 << 14); }
void QueueQueryResult::clearMessageCountFlag() { flags &= ~(1 << 14); }

void QueueQueryResult::setSubscriberCount(uint32_t _subscriberCount) {
    subscriberCount = _subscriberCount;
    flags |= (1 << 15);
}
uint32_t QueueQueryResult::getSubscriberCount() const { return subscriberCount; }
bool QueueQueryResult::hasSubscriberCount() const { return flags & (1 << 15); }
void QueueQueryResult::clearSubscriberCountFlag() { flags &= ~(1 << 15); }

void QueueQueryResult::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putShortString(alternateExchange);
    if (flags & (1 << 13))
        arguments.encode(buffer);
    if (flags & (1 << 14))
        buffer.putLong(messageCount);
    if (flags & (1 << 15))
        buffer.putLong(subscriberCount);
}

void QueueQueryResult::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void QueueQueryResult::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        buffer.getShortString(alternateExchange);
    if (flags & (1 << 13))
        arguments.decode(buffer);
    if (flags & (1 << 14))
        messageCount = buffer.getLong();
    if (flags & (1 << 15))
        subscriberCount = buffer.getLong();
}

void QueueQueryResult::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t QueueQueryResult::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1 + alternateExchange.size();
    if (flags & (1 << 13))
        total += arguments.encodedSize();
    if (flags & (1 << 14))
        total += 4;//messageCount
    if (flags & (1 << 15))
        total += 4;//subscriberCount
    return total;
}

uint32_t QueueQueryResult::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void QueueQueryResult::print(std::ostream& out) const
{
    out << "{QueueQueryResult: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "alternate-exchange=" << alternateExchange << "; ";
    if (flags & (1 << 10))
        out << "durable=" << getDurable() << "; ";
    if (flags & (1 << 11))
        out << "exclusive=" << getExclusive() << "; ";
    if (flags & (1 << 12))
        out << "auto-delete=" << getAutoDelete() << "; ";
    if (flags & (1 << 13))
        out << "arguments=" << arguments << "; ";
    if (flags & (1 << 14))
        out << "message-count=" << messageCount << "; ";
    if (flags & (1 << 15))
        out << "subscriber-count=" << subscriberCount << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const QueueQueryResult& s) 
    {
      s.print(out);
      return out;
    }

}
}
