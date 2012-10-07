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


#include "qpid/framing/ClusterConfigChangeBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConfigChangeBody::setMembers(const std::string& _members) {
    members = _members;
    flags |= (1 << 8);
    if (members.size() >= 65536) throw IllegalArgumentException("Value for members is too large");
}
const std::string& ClusterConfigChangeBody::getMembers() const { return members; }
bool ClusterConfigChangeBody::hasMembers() const { return flags & (1 << 8); }
void ClusterConfigChangeBody::clearMembersFlag() { flags &= ~(1 << 8); }

void ClusterConfigChangeBody::setJoined(const std::string& _joined) {
    joined = _joined;
    flags |= (1 << 9);
    if (joined.size() >= 65536) throw IllegalArgumentException("Value for joined is too large");
}
const std::string& ClusterConfigChangeBody::getJoined() const { return joined; }
bool ClusterConfigChangeBody::hasJoined() const { return flags & (1 << 9); }
void ClusterConfigChangeBody::clearJoinedFlag() { flags &= ~(1 << 9); }

void ClusterConfigChangeBody::setLeft(const std::string& _left) {
    left = _left;
    flags |= (1 << 10);
    if (left.size() >= 65536) throw IllegalArgumentException("Value for left is too large");
}
const std::string& ClusterConfigChangeBody::getLeft() const { return left; }
bool ClusterConfigChangeBody::hasLeft() const { return flags & (1 << 10); }
void ClusterConfigChangeBody::clearLeftFlag() { flags &= ~(1 << 10); }

void ClusterConfigChangeBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(members);
    if (flags & (1 << 9))
        buffer.putMediumString(joined);
    if (flags & (1 << 10))
        buffer.putMediumString(left);
}

void ClusterConfigChangeBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConfigChangeBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(members);
    if (flags & (1 << 9))
        buffer.getMediumString(joined);
    if (flags & (1 << 10))
        buffer.getMediumString(left);
}

void ClusterConfigChangeBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConfigChangeBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + members.size();
    if (flags & (1 << 9))
        total += 2 + joined.size();
    if (flags & (1 << 10))
        total += 2 + left.size();
    return total;
}

uint32_t ClusterConfigChangeBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConfigChangeBody::print(std::ostream& out) const
{
    out << "{ClusterConfigChangeBody: ";
    if (flags & (1 << 8))
        out << "members=" << members << "; ";
    if (flags & (1 << 9))
        out << "joined=" << joined << "; ";
    if (flags & (1 << 10))
        out << "left=" << left << "; ";
    out << "}";
}
