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


#include "qpid/framing/ClusterConnectionDtxBufferRefBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConnectionDtxBufferRefBody::setXid(const std::string& _xid) {
    xid = _xid;
    flags |= (1 << 8);
    if (xid.size() >= 65536) throw IllegalArgumentException("Value for xid is too large");
}
const std::string& ClusterConnectionDtxBufferRefBody::getXid() const { return xid; }
bool ClusterConnectionDtxBufferRefBody::hasXid() const { return flags & (1 << 8); }
void ClusterConnectionDtxBufferRefBody::clearXidFlag() { flags &= ~(1 << 8); }

void ClusterConnectionDtxBufferRefBody::setIndex(uint32_t _index) {
    index = _index;
    flags |= (1 << 9);
}
uint32_t ClusterConnectionDtxBufferRefBody::getIndex() const { return index; }
bool ClusterConnectionDtxBufferRefBody::hasIndex() const { return flags & (1 << 9); }
void ClusterConnectionDtxBufferRefBody::clearIndexFlag() { flags &= ~(1 << 9); }

void ClusterConnectionDtxBufferRefBody::setSuspended(bool _suspended) {
    if (_suspended) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool ClusterConnectionDtxBufferRefBody::getSuspended() const { return flags & (1 << 10); }

void ClusterConnectionDtxBufferRefBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(xid);
    if (flags & (1 << 9))
        buffer.putLong(index);
}

void ClusterConnectionDtxBufferRefBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionDtxBufferRefBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(xid);
    if (flags & (1 << 9))
        index = buffer.getLong();
}

void ClusterConnectionDtxBufferRefBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionDtxBufferRefBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + xid.size();
    if (flags & (1 << 9))
        total += 4;//index
    return total;
}

uint32_t ClusterConnectionDtxBufferRefBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionDtxBufferRefBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionDtxBufferRefBody: ";
    if (flags & (1 << 8))
        out << "xid=" << xid << "; ";
    if (flags & (1 << 9))
        out << "index=" << index << "; ";
    if (flags & (1 << 10))
        out << "suspended=" << getSuspended() << "; ";
    out << "}";
}
