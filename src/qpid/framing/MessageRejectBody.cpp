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


#include "qpid/framing/MessageRejectBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageRejectBody::setTransfers(const SequenceSet& _transfers) {
    transfers = _transfers;
    flags |= (1 << 8);
}
const SequenceSet& MessageRejectBody::getTransfers() const { return transfers; }
bool MessageRejectBody::hasTransfers() const { return flags & (1 << 8); }
void MessageRejectBody::clearTransfersFlag() { flags &= ~(1 << 8); }

void MessageRejectBody::setCode(uint16_t _code) {
    code = _code;
    flags |= (1 << 9);
}
uint16_t MessageRejectBody::getCode() const { return code; }
bool MessageRejectBody::hasCode() const { return flags & (1 << 9); }
void MessageRejectBody::clearCodeFlag() { flags &= ~(1 << 9); }

void MessageRejectBody::setText(const std::string& _text) {
    text = _text;
    flags |= (1 << 10);
    if (text.size() >= 256) throw IllegalArgumentException("Value for text is too large");
}
const std::string& MessageRejectBody::getText() const { return text; }
bool MessageRejectBody::hasText() const { return flags & (1 << 10); }
void MessageRejectBody::clearTextFlag() { flags &= ~(1 << 10); }

void MessageRejectBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        transfers.encode(buffer);
    if (flags & (1 << 9))
        buffer.putShort(code);
    if (flags & (1 << 10))
        buffer.putShortString(text);
}

void MessageRejectBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageRejectBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        transfers.decode(buffer);
    if (flags & (1 << 9))
        code = buffer.getShort();
    if (flags & (1 << 10))
        buffer.getShortString(text);
}

void MessageRejectBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageRejectBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += transfers.encodedSize();
    if (flags & (1 << 9))
        total += 2;//code
    if (flags & (1 << 10))
        total += 1 + text.size();
    return total;
}

uint32_t MessageRejectBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageRejectBody::print(std::ostream& out) const
{
    out << "{MessageRejectBody: ";
    if (flags & (1 << 8))
        out << "transfers=" << transfers << "; ";
    if (flags & (1 << 9))
        out << "code=" << code << "; ";
    if (flags & (1 << 10))
        out << "text=" << text << "; ";
    out << "}";
}
