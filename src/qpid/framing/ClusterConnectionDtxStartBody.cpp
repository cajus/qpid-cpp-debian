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


#include "qpid/framing/ClusterConnectionDtxStartBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionDtxStartBody::setXid(const std::string& _xid) {
    xid = _xid;
    flags |= (1 << 8);
}
const std::string& ClusterConnectionDtxStartBody::getXid() const { return xid; }
bool ClusterConnectionDtxStartBody::hasXid() const { return flags & (1 << 8); }
void ClusterConnectionDtxStartBody::clearXidFlag() { flags &= ~(1 << 8); }

void ClusterConnectionDtxStartBody::setEnded(bool _ended) {
    if (_ended) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ClusterConnectionDtxStartBody::getEnded() const { return flags & (1 << 9); }

void ClusterConnectionDtxStartBody::setSuspended(bool _suspended) {
    if (_suspended) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool ClusterConnectionDtxStartBody::getSuspended() const { return flags & (1 << 10); }

void ClusterConnectionDtxStartBody::setFailed(bool _failed) {
    if (_failed) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool ClusterConnectionDtxStartBody::getFailed() const { return flags & (1 << 11); }

void ClusterConnectionDtxStartBody::setExpired(bool _expired) {
    if (_expired) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool ClusterConnectionDtxStartBody::getExpired() const { return flags & (1 << 12); }

void ClusterConnectionDtxStartBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(xid);
}

void ClusterConnectionDtxStartBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionDtxStartBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(xid);
}

void ClusterConnectionDtxStartBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionDtxStartBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + xid.size();
    return total;
}

uint32_t ClusterConnectionDtxStartBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionDtxStartBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionDtxStartBody: ";
    if (flags & (1 << 8))
        out << "xid=" << xid << "; ";
    if (flags & (1 << 9))
        out << "ended=" << getEnded() << "; ";
    if (flags & (1 << 10))
        out << "suspended=" << getSuspended() << "; ";
    if (flags & (1 << 11))
        out << "failed=" << getFailed() << "; ";
    if (flags & (1 << 12))
        out << "expired=" << getExpired() << "; ";
    out << "}";
}
