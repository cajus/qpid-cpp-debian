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


#include "qpid/framing/StreamReturnBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void StreamReturnBody::setReplyCode(uint16_t _replyCode) {
    replyCode = _replyCode;
    flags |= (1 << 8);
}
uint16_t StreamReturnBody::getReplyCode() const { return replyCode; }
bool StreamReturnBody::hasReplyCode() const { return flags & (1 << 8); }
void StreamReturnBody::clearReplyCodeFlag() { flags &= ~(1 << 8); }

void StreamReturnBody::setReplyText(const std::string& _replyText) {
    replyText = _replyText;
    flags |= (1 << 9);
    if (replyText.size() >= 256) throw IllegalArgumentException("Value for replyText is too large");
}
const std::string& StreamReturnBody::getReplyText() const { return replyText; }
bool StreamReturnBody::hasReplyText() const { return flags & (1 << 9); }
void StreamReturnBody::clearReplyTextFlag() { flags &= ~(1 << 9); }

void StreamReturnBody::setExchange(const std::string& _exchange) {
    exchange = _exchange;
    flags |= (1 << 10);
    if (exchange.size() >= 256) throw IllegalArgumentException("Value for exchange is too large");
}
const std::string& StreamReturnBody::getExchange() const { return exchange; }
bool StreamReturnBody::hasExchange() const { return flags & (1 << 10); }
void StreamReturnBody::clearExchangeFlag() { flags &= ~(1 << 10); }

void StreamReturnBody::setRoutingKey(const std::string& _routingKey) {
    routingKey = _routingKey;
    flags |= (1 << 11);
    if (routingKey.size() >= 256) throw IllegalArgumentException("Value for routingKey is too large");
}
const std::string& StreamReturnBody::getRoutingKey() const { return routingKey; }
bool StreamReturnBody::hasRoutingKey() const { return flags & (1 << 11); }
void StreamReturnBody::clearRoutingKeyFlag() { flags &= ~(1 << 11); }

void StreamReturnBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(replyCode);
    if (flags & (1 << 9))
        buffer.putShortString(replyText);
    if (flags & (1 << 10))
        buffer.putShortString(exchange);
    if (flags & (1 << 11))
        buffer.putShortString(routingKey);
}

void StreamReturnBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void StreamReturnBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        replyCode = buffer.getShort();
    if (flags & (1 << 9))
        buffer.getShortString(replyText);
    if (flags & (1 << 10))
        buffer.getShortString(exchange);
    if (flags & (1 << 11))
        buffer.getShortString(routingKey);
}

void StreamReturnBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t StreamReturnBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2;//replyCode
    if (flags & (1 << 9))
        total += 1 + replyText.size();
    if (flags & (1 << 10))
        total += 1 + exchange.size();
    if (flags & (1 << 11))
        total += 1 + routingKey.size();
    return total;
}

uint32_t StreamReturnBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void StreamReturnBody::print(std::ostream& out) const
{
    out << "{StreamReturnBody: ";
    if (flags & (1 << 8))
        out << "reply-code=" << replyCode << "; ";
    if (flags & (1 << 9))
        out << "reply-text=" << replyText << "; ";
    if (flags & (1 << 10))
        out << "exchange=" << exchange << "; ";
    if (flags & (1 << 11))
        out << "routing-key=" << routingKey << "; ";
    out << "}";
}
