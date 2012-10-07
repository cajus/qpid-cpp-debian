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


#include "qpid/framing/ExchangeDeclareBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExchangeDeclareBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 8);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& ExchangeDeclareBody::getExchange() const { return exchange; }
bool ExchangeDeclareBody::hasExchange() const { return flags & (1 << 8); }
void ExchangeDeclareBody::clearExchangeFlag() { flags &= ~(1 << 8); }

void ExchangeDeclareBody::setType(const std::string& _type) {
    type = _type;
    flags |= (1 << 9);
    if (type.size() >= 256) throw IllegalArgumentException("Value for type is too large");
}
const std::string& ExchangeDeclareBody::getType() const { return type; }
bool ExchangeDeclareBody::hasType() const { return flags & (1 << 9); }
void ExchangeDeclareBody::clearTypeFlag() { flags &= ~(1 << 9); }

void ExchangeDeclareBody::setAlternateExchange(const std::string& _alternateExchange) {
    alternateExchange = _alternateExchange;
    flags |= (1 << 10);
    if (alternateExchange.size() >= 256) throw IllegalArgumentException("Value for alternateExchange is too large");
}
const std::string& ExchangeDeclareBody::getAlternateExchange() const { return alternateExchange; }
bool ExchangeDeclareBody::hasAlternateExchange() const { return flags & (1 << 10); }
void ExchangeDeclareBody::clearAlternateExchangeFlag() { flags &= ~(1 << 10); }

void ExchangeDeclareBody::setPassive(bool _passive) {
    if (_passive) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool ExchangeDeclareBody::getPassive() const { return flags & (1 << 11); }

void ExchangeDeclareBody::setDurable(bool _durable) {
    if (_durable) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool ExchangeDeclareBody::getDurable() const { return flags & (1 << 12); }

void ExchangeDeclareBody::setAutoDelete(bool _autoDelete) {
    if (_autoDelete) flags |= (1 << 13);
    else flags &= ~(1 << 13);
}
bool ExchangeDeclareBody::getAutoDelete() const { return flags & (1 << 13); }

void ExchangeDeclareBody::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 14);
}
const FieldTable& ExchangeDeclareBody::getArguments() const { return arguments; }
FieldTable& ExchangeDeclareBody::getArguments() {
    flags |= (1 << 14);
    return arguments;
}
bool ExchangeDeclareBody::hasArguments() const { return flags & (1 << 14); }
void ExchangeDeclareBody::clearArgumentsFlag() { flags &= ~(1 << 14); }

void ExchangeDeclareBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(exchange);
    if (flags & (1 << 9))
        buffer.putShortString(type);
    if (flags & (1 << 10))
        buffer.putShortString(alternateExchange);
    if (flags & (1 << 14))
        arguments.encode(buffer);
}

void ExchangeDeclareBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExchangeDeclareBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(exchange);
    if (flags & (1 << 9))
        buffer.getShortString(type);
    if (flags & (1 << 10))
        buffer.getShortString(alternateExchange);
    if (flags & (1 << 14))
        arguments.decode(buffer);
}

void ExchangeDeclareBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExchangeDeclareBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + exchange.size();
    if (flags & (1 << 9))
        total += 1 + type.size();
    if (flags & (1 << 10))
        total += 1 + alternateExchange.size();
    if (flags & (1 << 14))
        total += arguments.encodedSize();
    return total;
}

uint32_t ExchangeDeclareBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExchangeDeclareBody::print(std::ostream& out) const
{
    out << "{ExchangeDeclareBody: ";
    if (flags & (1 << 8))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 9))
        out << "type=" << type << "; ";
    if (flags & (1 << 10))
        out << "alternate-exchange=" << alternateExchange << "; ";
    if (flags & (1 << 11))
        out << "passive=" << getPassive() << "; ";
    if (flags & (1 << 12))
        out << "durable=" << getDurable() << "; ";
    if (flags & (1 << 13))
        out << "auto-delete=" << getAutoDelete() << "; ";
    if (flags & (1 << 14))
        out << "arguments=" << arguments << "; ";
    out << "}";
}
