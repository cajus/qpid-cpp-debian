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


#include "qpid/framing/ClusterConnectionMembershipBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConnectionMembershipBody::setJoiners(const FieldTable& _joiners) {
    joiners = _joiners;
    flags |= (1 << 8);
}
const FieldTable& ClusterConnectionMembershipBody::getJoiners() const { return joiners; }
FieldTable& ClusterConnectionMembershipBody::getJoiners() {
    flags |= (1 << 8);
    return joiners;
}
bool ClusterConnectionMembershipBody::hasJoiners() const { return flags & (1 << 8); }
void ClusterConnectionMembershipBody::clearJoinersFlag() { flags &= ~(1 << 8); }

void ClusterConnectionMembershipBody::setMembers(const FieldTable& _members) {
    members = _members;
    flags |= (1 << 9);
}
const FieldTable& ClusterConnectionMembershipBody::getMembers() const { return members; }
FieldTable& ClusterConnectionMembershipBody::getMembers() {
    flags |= (1 << 9);
    return members;
}
bool ClusterConnectionMembershipBody::hasMembers() const { return flags & (1 << 9); }
void ClusterConnectionMembershipBody::clearMembersFlag() { flags &= ~(1 << 9); }

void ClusterConnectionMembershipBody::setFrameSeq(const SequenceNumber& _frameSeq) {
    frameSeq = _frameSeq;
    flags |= (1 << 10);
}
SequenceNumber ClusterConnectionMembershipBody::getFrameSeq() const { return frameSeq; }
bool ClusterConnectionMembershipBody::hasFrameSeq() const { return flags & (1 << 10); }
void ClusterConnectionMembershipBody::clearFrameSeqFlag() { flags &= ~(1 << 10); }

void ClusterConnectionMembershipBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        joiners.encode(buffer);
    if (flags & (1 << 9))
        members.encode(buffer);
    if (flags & (1 << 10))
        frameSeq.encode(buffer);
}

void ClusterConnectionMembershipBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionMembershipBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        joiners.decode(buffer);
    if (flags & (1 << 9))
        members.decode(buffer);
    if (flags & (1 << 10))
        frameSeq.decode(buffer);
}

void ClusterConnectionMembershipBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionMembershipBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += joiners.encodedSize();
    if (flags & (1 << 9))
        total += members.encodedSize();
    if (flags & (1 << 10))
        total += frameSeq.encodedSize();
    return total;
}

uint32_t ClusterConnectionMembershipBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionMembershipBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionMembershipBody: ";
    if (flags & (1 << 8))
        out << "joiners=" << joiners << "; ";
    if (flags & (1 << 9))
        out << "members=" << members << "; ";
    if (flags & (1 << 10))
        out << "frame-seq=" << frameSeq << "; ";
    out << "}";
}
