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


#include "qpid/framing/ClusterReadyBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ClusterReadyBody::setUrl(const std::string& _url) {
    url = _url;
    flags |= (1 << 8);
    if (url.size() >= 65536) throw IllegalArgumentException("Value for url is too large");
}
const std::string& ClusterReadyBody::getUrl() const { return url; }
bool ClusterReadyBody::hasUrl() const { return flags & (1 << 8); }
void ClusterReadyBody::clearUrlFlag() { flags &= ~(1 << 8); }

void ClusterReadyBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(url);
}

void ClusterReadyBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterReadyBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(url);
}

void ClusterReadyBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterReadyBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + url.size();
    return total;
}

uint32_t ClusterReadyBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterReadyBody::print(std::ostream& out) const
{
    out << "{ClusterReadyBody: ";
    if (flags & (1 << 8))
        out << "url=" << url << "; ";
    out << "}";
}
