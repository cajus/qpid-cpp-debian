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


#include "qpid/framing/ConnectionSecureBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionSecureBody::setChallenge(const std::string& _challenge) {
    challenge = _challenge;
    flags |= (1 << 8);
}
const std::string& ConnectionSecureBody::getChallenge() const { return challenge; }
bool ConnectionSecureBody::hasChallenge() const { return flags & (1 << 8); }
void ConnectionSecureBody::clearChallengeFlag() { flags &= ~(1 << 8); }

void ConnectionSecureBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongString(challenge);
}

void ConnectionSecureBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionSecureBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getLongString(challenge);
}

void ConnectionSecureBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionSecureBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 4 + challenge.size();
    return total;
}

uint32_t ConnectionSecureBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionSecureBody::print(std::ostream& out) const
{
    out << "{ConnectionSecureBody: ";
    if (flags & (1 << 8))
        out << "challenge=" << challenge << "; ";
    out << "}";
}
