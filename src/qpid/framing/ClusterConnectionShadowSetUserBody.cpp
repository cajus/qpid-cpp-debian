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


#include "qpid/framing/ClusterConnectionShadowSetUserBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterConnectionShadowSetUserBody::setUserId(const std::string& _userId) {
    userId = _userId;
    flags |= (1 << 8);
    if (userId.size() >= 65536) throw IllegalArgumentException("Value for userId is too large");
}
const std::string& ClusterConnectionShadowSetUserBody::getUserId() const { return userId; }
bool ClusterConnectionShadowSetUserBody::hasUserId() const { return flags & (1 << 8); }
void ClusterConnectionShadowSetUserBody::clearUserIdFlag() { flags &= ~(1 << 8); }

void ClusterConnectionShadowSetUserBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(userId);
}

void ClusterConnectionShadowSetUserBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionShadowSetUserBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(userId);
}

void ClusterConnectionShadowSetUserBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionShadowSetUserBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + userId.size();
    return total;
}

uint32_t ClusterConnectionShadowSetUserBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionShadowSetUserBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionShadowSetUserBody: ";
    if (flags & (1 << 8))
        out << "user-id=" << userId << "; ";
    out << "}";
}
