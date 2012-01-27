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


#include "qpid/framing/ClusterConnectionDtxWorkRecordBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionDtxWorkRecordBody::setXid(const std::string& _xid) {
    xid = _xid;
    flags |= (1 << 8);
}
const std::string& ClusterConnectionDtxWorkRecordBody::getXid() const { return xid; }
bool ClusterConnectionDtxWorkRecordBody::hasXid() const { return flags & (1 << 8); }
void ClusterConnectionDtxWorkRecordBody::clearXidFlag() { flags &= ~(1 << 8); }

void ClusterConnectionDtxWorkRecordBody::setPrepared(bool _prepared) {
    if (_prepared) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ClusterConnectionDtxWorkRecordBody::getPrepared() const { return flags & (1 << 9); }

void ClusterConnectionDtxWorkRecordBody::setTimeout(uint32_t _timeout) {
    timeout = _timeout;
    flags |= (1 << 10);
}
uint32_t ClusterConnectionDtxWorkRecordBody::getTimeout() const { return timeout; }
bool ClusterConnectionDtxWorkRecordBody::hasTimeout() const { return flags & (1 << 10); }
void ClusterConnectionDtxWorkRecordBody::clearTimeoutFlag() { flags &= ~(1 << 10); }

void ClusterConnectionDtxWorkRecordBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(xid);
    if (flags & (1 << 10))
        buffer.putLong(timeout);
}

void ClusterConnectionDtxWorkRecordBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionDtxWorkRecordBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(xid);
    if (flags & (1 << 10))
        timeout = buffer.getLong();
}

void ClusterConnectionDtxWorkRecordBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionDtxWorkRecordBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + xid.size();
    if (flags & (1 << 10))
        total += 4;//timeout
    return total;
}

uint32_t ClusterConnectionDtxWorkRecordBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionDtxWorkRecordBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionDtxWorkRecordBody: ";
    if (flags & (1 << 8))
        out << "xid=" << xid << "; ";
    if (flags & (1 << 9))
        out << "prepared=" << getPrepared() << "; ";
    if (flags & (1 << 10))
        out << "timeout=" << timeout << "; ";
    out << "}";
}
