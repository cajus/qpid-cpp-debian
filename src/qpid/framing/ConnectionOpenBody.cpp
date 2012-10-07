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


#include "qpid/framing/ConnectionOpenBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionOpenBody::setVirtualHost(const std::string& _virtualHost) {
    virtualHost = _virtualHost;
    flags |= (1 << 8);
    if (virtualHost.size() >= 256) throw IllegalArgumentException("Value for virtualHost is too large");
}
const std::string& ConnectionOpenBody::getVirtualHost() const { return virtualHost; }
bool ConnectionOpenBody::hasVirtualHost() const { return flags & (1 << 8); }
void ConnectionOpenBody::clearVirtualHostFlag() { flags &= ~(1 << 8); }

void ConnectionOpenBody::setCapabilities(const Array& _capabilities) {
    capabilities = _capabilities;
    flags |= (1 << 9);
}
const Array& ConnectionOpenBody::getCapabilities() const { return capabilities; }
bool ConnectionOpenBody::hasCapabilities() const { return flags & (1 << 9); }
void ConnectionOpenBody::clearCapabilitiesFlag() { flags &= ~(1 << 9); }

void ConnectionOpenBody::setInsist(bool _insist) {
    if (_insist) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool ConnectionOpenBody::getInsist() const { return flags & (1 << 10); }

void ConnectionOpenBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(virtualHost);
    if (flags & (1 << 9))
        capabilities.encode(buffer);
}

void ConnectionOpenBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionOpenBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(virtualHost);
    if (flags & (1 << 9))
        capabilities.decode(buffer);
}

void ConnectionOpenBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionOpenBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 1 + virtualHost.size();
    if (flags & (1 << 9))
        total += capabilities.encodedSize();
    return total;
}

uint32_t ConnectionOpenBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionOpenBody::print(std::ostream& out) const
{
    out << "{ConnectionOpenBody: ";
    if (flags & (1 << 8))
        out << "virtual-host=" << virtualHost << "; ";
    if (flags & (1 << 9))
        out << "capabilities=" << capabilities << "; ";
    if (flags & (1 << 10))
        out << "insist=" << getInsist() << "; ";
    out << "}";
}
