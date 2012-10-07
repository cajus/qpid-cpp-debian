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


#include "qpid/framing/ExchangeBoundBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExchangeBoundBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 8);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& ExchangeBoundBody::getExchange() const { return exchange; }
bool ExchangeBoundBody::hasExchange() const { return flags & (1 << 8); }
void ExchangeBoundBody::clearExchangeFlag() { flags &= ~(1 << 8); }

void ExchangeBoundBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 9);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& ExchangeBoundBody::getQueue() const { return queue; }
bool ExchangeBoundBody::hasQueue() const { return flags & (1 << 9); }
void ExchangeBoundBody::clearQueueFlag() { flags &= ~(1 << 9); }

void ExchangeBoundBody::setBindingKey(const std::string& _bindingKey) {
    bindingKey = _bindingKey;
    flags |= (1 << 10);
    if (bindingKey.size() >= 256) throw IllegalArgumentException("Value for bindingKey is too large");
}
const std::string& ExchangeBoundBody::getBindingKey() const { return bindingKey; }
bool ExchangeBoundBody::hasBindingKey() const { return flags & (1 << 10); }
void ExchangeBoundBody::clearBindingKeyFlag() { flags &= ~(1 << 10); }

void ExchangeBoundBody::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 11);
}
const FieldTable& ExchangeBoundBody::getArguments() const { return arguments; }
FieldTable& ExchangeBoundBody::getArguments() {
    flags |= (1 << 11);
    return arguments;
}
bool ExchangeBoundBody::hasArguments() const { return flags & (1 << 11); }
void ExchangeBoundBody::clearArgumentsFlag() { flags &= ~(1 << 11); }

void ExchangeBoundBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(exchange);
    if (flags & (1 << 9))
        buffer.putShortString(queue);
    if (flags & (1 << 10))
        buffer.putShortString(bindingKey);
    if (flags & (1 << 11))
        arguments.encode(buffer);
}

void ExchangeBoundBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExchangeBoundBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(exchange);
    if (flags & (1 << 9))
        buffer.getShortString(queue);
    if (flags & (1 << 10))
        buffer.getShortString(bindingKey);
    if (flags & (1 << 11))
        arguments.decode(buffer);
}

void ExchangeBoundBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExchangeBoundBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + exchange.size();
    if (flags & (1 << 9))
        total += 1 + queue.size();
    if (flags & (1 << 10))
        total += 1 + bindingKey.size();
    if (flags & (1 << 11))
        total += arguments.encodedSize();
    return total;
}

uint32_t ExchangeBoundBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExchangeBoundBody::print(std::ostream& out) const
{
    out << "{ExchangeBoundBody: ";
    if (flags & (1 << 8))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 9))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 10))
        out << "binding-key=" << bindingKey << "; ";
    if (flags & (1 << 11))
        out << "arguments=" << arguments << "; ";
    out << "}";
}
