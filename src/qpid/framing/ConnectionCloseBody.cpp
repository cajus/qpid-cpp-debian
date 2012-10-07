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


#include "qpid/framing/ConnectionCloseBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionCloseBody::setReplyCode(uint16_t _replyCode) {
    replyCode = _replyCode;
    flags |= (1 << 8);
}
uint16_t ConnectionCloseBody::getReplyCode() const { return replyCode; }
bool ConnectionCloseBody::hasReplyCode() const { return flags & (1 << 8); }
void ConnectionCloseBody::clearReplyCodeFlag() { flags &= ~(1 << 8); }

void ConnectionCloseBody::setReplyText(const std::string& _replyText) {
    replyText = _replyText;
    flags |= (1 << 9);
    if (replyText.size() >= 256) throw IllegalArgumentException("Value for replyText is too large");
}
const std::string& ConnectionCloseBody::getReplyText() const { return replyText; }
bool ConnectionCloseBody::hasReplyText() const { return flags & (1 << 9); }
void ConnectionCloseBody::clearReplyTextFlag() { flags &= ~(1 << 9); }

void ConnectionCloseBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(replyCode);
    if (flags & (1 << 9))
        buffer.putShortString(replyText);
}

void ConnectionCloseBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionCloseBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        replyCode = buffer.getShort();
    if (flags & (1 << 9))
        buffer.getShortString(replyText);
}

void ConnectionCloseBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionCloseBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 2;//replyCode
    if (flags & (1 << 9))
        total += 1 + replyText.size();
    return total;
}

uint32_t ConnectionCloseBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionCloseBody::print(std::ostream& out) const
{
    out << "{ConnectionCloseBody: ";
    if (flags & (1 << 8))
        out << "reply-code=" << replyCode << "; ";
    if (flags & (1 << 9))
        out << "reply-text=" << replyText << "; ";
    out << "}";
}
