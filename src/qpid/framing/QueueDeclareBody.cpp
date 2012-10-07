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


#include "qpid/framing/QueueDeclareBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void QueueDeclareBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& QueueDeclareBody::getQueue() const { return queue; }
bool QueueDeclareBody::hasQueue() const { return flags & (1 << 8); }
void QueueDeclareBody::clearQueueFlag() { flags &= ~(1 << 8); }

void QueueDeclareBody::setAlternateExchange(const std::string& _alternateExchange) {
    alternateExchange = _alternateExchange;
    flags |= (1 << 9);
    if (alternateExchange.size() >= 256) throw IllegalArgumentException("Value for alternateExchange is too large");
}
const std::string& QueueDeclareBody::getAlternateExchange() const { return alternateExchange; }
bool QueueDeclareBody::hasAlternateExchange() const { return flags & (1 << 9); }
void QueueDeclareBody::clearAlternateExchangeFlag() { flags &= ~(1 << 9); }

void QueueDeclareBody::setPassive(bool _passive) {
    if (_passive) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool QueueDeclareBody::getPassive() const { return flags & (1 << 10); }

void QueueDeclareBody::setDurable(bool _durable) {
    if (_durable) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool QueueDeclareBody::getDurable() const { return flags & (1 << 11); }

void QueueDeclareBody::setExclusive(bool _exclusive) {
    if (_exclusive) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool QueueDeclareBody::getExclusive() const { return flags & (1 << 12); }

void QueueDeclareBody::setAutoDelete(bool _autoDelete) {
    if (_autoDelete) flags |= (1 << 13);
    else flags &= ~(1 << 13);
}
bool QueueDeclareBody::getAutoDelete() const { return flags & (1 << 13); }

void QueueDeclareBody::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 14);
}
const FieldTable& QueueDeclareBody::getArguments() const { return arguments; }
FieldTable& QueueDeclareBody::getArguments() {
    flags |= (1 << 14);
    return arguments;
}
bool QueueDeclareBody::hasArguments() const { return flags & (1 << 14); }
void QueueDeclareBody::clearArgumentsFlag() { flags &= ~(1 << 14); }

void QueueDeclareBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putShortString(alternateExchange);
    if (flags & (1 << 14))
        arguments.encode(buffer);
}

void QueueDeclareBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void QueueDeclareBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        buffer.getShortString(alternateExchange);
    if (flags & (1 << 14))
        arguments.decode(buffer);
}

void QueueDeclareBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t QueueDeclareBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1 + alternateExchange.size();
    if (flags & (1 << 14))
        total += arguments.encodedSize();
    return total;
}

uint32_t QueueDeclareBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void QueueDeclareBody::print(std::ostream& out) const
{
    out << "{QueueDeclareBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "alternate-exchange=" << alternateExchange << "; ";
    if (flags & (1 << 10))
        out << "passive=" << getPassive() << "; ";
    if (flags & (1 << 11))
        out << "durable=" << getDurable() << "; ";
    if (flags & (1 << 12))
        out << "exclusive=" << getExclusive() << "; ";
    if (flags & (1 << 13))
        out << "auto-delete=" << getAutoDelete() << "; ";
    if (flags & (1 << 14))
        out << "arguments=" << arguments << "; ";
    out << "}";
}
