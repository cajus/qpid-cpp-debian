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


#include "qpid/framing/ConnectionOpenOkBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionOpenOkBody::setKnownHosts(const Array& _knownHosts) {
    knownHosts = _knownHosts;
    flags |= (1 << 8);
}
const Array& ConnectionOpenOkBody::getKnownHosts() const { return knownHosts; }
bool ConnectionOpenOkBody::hasKnownHosts() const { return flags & (1 << 8); }
void ConnectionOpenOkBody::clearKnownHostsFlag() { flags &= ~(1 << 8); }

void ConnectionOpenOkBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        knownHosts.encode(buffer);
}

void ConnectionOpenOkBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionOpenOkBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        knownHosts.decode(buffer);
}

void ConnectionOpenOkBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionOpenOkBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += knownHosts.encodedSize();
    return total;
}

uint32_t ConnectionOpenOkBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionOpenOkBody::print(std::ostream& out) const
{
    out << "{ConnectionOpenOkBody: ";
    if (flags & (1 << 8))
        out << "known-hosts=" << knownHosts << "; ";
    out << "}";
}
