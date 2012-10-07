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


#include "qpid/framing/ConnectionRedirectBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionRedirectBody::setHost(const std::string& _host) {
    host = _host;
    flags |= (1 << 8);
    if (host.size() >= 65536) throw IllegalArgumentException("Value for host is too large");
}
const std::string& ConnectionRedirectBody::getHost() const { return host; }
bool ConnectionRedirectBody::hasHost() const { return flags & (1 << 8); }
void ConnectionRedirectBody::clearHostFlag() { flags &= ~(1 << 8); }

void ConnectionRedirectBody::setKnownHosts(const Array& _knownHosts) {
    knownHosts = _knownHosts;
    flags |= (1 << 9);
}
const Array& ConnectionRedirectBody::getKnownHosts() const { return knownHosts; }
bool ConnectionRedirectBody::hasKnownHosts() const { return flags & (1 << 9); }
void ConnectionRedirectBody::clearKnownHostsFlag() { flags &= ~(1 << 9); }

void ConnectionRedirectBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(host);
    if (flags & (1 << 9))
        knownHosts.encode(buffer);
}

void ConnectionRedirectBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionRedirectBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(host);
    if (flags & (1 << 9))
        knownHosts.decode(buffer);
}

void ConnectionRedirectBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionRedirectBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 2 + host.size();
    if (flags & (1 << 9))
        total += knownHosts.encodedSize();
    return total;
}

uint32_t ConnectionRedirectBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionRedirectBody::print(std::ostream& out) const
{
    out << "{ConnectionRedirectBody: ";
    if (flags & (1 << 8))
        out << "host=" << host << "; ";
    if (flags & (1 << 9))
        out << "known-hosts=" << knownHosts << "; ";
    out << "}";
}
