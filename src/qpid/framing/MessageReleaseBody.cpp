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


#include "qpid/framing/MessageReleaseBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageReleaseBody::setTransfers(const SequenceSet& _transfers) {
    transfers = _transfers;
    flags |= (1 << 8);
}
const SequenceSet& MessageReleaseBody::getTransfers() const { return transfers; }
bool MessageReleaseBody::hasTransfers() const { return flags & (1 << 8); }
void MessageReleaseBody::clearTransfersFlag() { flags &= ~(1 << 8); }

void MessageReleaseBody::setSetRedelivered(bool _setRedelivered) {
    if (_setRedelivered) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool MessageReleaseBody::getSetRedelivered() const { return flags & (1 << 9); }

void MessageReleaseBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        transfers.encode(buffer);
}

void MessageReleaseBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageReleaseBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        transfers.decode(buffer);
}

void MessageReleaseBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageReleaseBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += transfers.encodedSize();
    return total;
}

uint32_t MessageReleaseBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageReleaseBody::print(std::ostream& out) const
{
    out << "{MessageReleaseBody: ";
    if (flags & (1 << 8))
        out << "transfers=" << transfers << "; ";
    if (flags & (1 << 9))
        out << "set-redelivered=" << getSetRedelivered() << "; ";
    out << "}";
}
