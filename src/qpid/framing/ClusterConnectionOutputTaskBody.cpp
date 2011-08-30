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


#include "qpid/framing/ClusterConnectionOutputTaskBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionOutputTaskBody::setChannel(uint16_t _channel) {
    channel = _channel;
    flags |= (1 << 8);
}
uint16_t ClusterConnectionOutputTaskBody::getChannel() const { return channel; }
bool ClusterConnectionOutputTaskBody::hasChannel() const { return flags & (1 << 8); }
void ClusterConnectionOutputTaskBody::clearChannelFlag() { flags &= ~(1 << 8); }

void ClusterConnectionOutputTaskBody::setName(const std::string& _name) {
    name = _name;
    flags |= (1 << 9);
}
const std::string& ClusterConnectionOutputTaskBody::getName() const { return name; }
bool ClusterConnectionOutputTaskBody::hasName() const { return flags & (1 << 9); }
void ClusterConnectionOutputTaskBody::clearNameFlag() { flags &= ~(1 << 9); }

void ClusterConnectionOutputTaskBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(channel);
    if (flags & (1 << 9))
        buffer.putShortString(name);
}

void ClusterConnectionOutputTaskBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionOutputTaskBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        channel = buffer.getShort();
    if (flags & (1 << 9))
        buffer.getShortString(name);
}

void ClusterConnectionOutputTaskBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionOutputTaskBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2;//channel
    if (flags & (1 << 9))
        total += 1 + name.size();
    return total;
}

uint32_t ClusterConnectionOutputTaskBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionOutputTaskBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionOutputTaskBody: ";
    if (flags & (1 << 8))
        out << "channel=" << channel << "; ";
    if (flags & (1 << 9))
        out << "name=" << name << "; ";
    out << "}";
}
