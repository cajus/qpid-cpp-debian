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


#include "qpid/framing/ClusterInitialStatusBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterInitialStatusBody::setVersion(uint32_t _version) {
    version = _version;
    flags |= (1 << 8);
}
uint32_t ClusterInitialStatusBody::getVersion() const { return version; }
bool ClusterInitialStatusBody::hasVersion() const { return flags & (1 << 8); }
void ClusterInitialStatusBody::clearVersionFlag() { flags &= ~(1 << 8); }

void ClusterInitialStatusBody::setActive(bool _active) {
    if (_active) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool ClusterInitialStatusBody::getActive() const { return flags & (1 << 9); }

void ClusterInitialStatusBody::setClusterId(const Uuid& _clusterId) {
    clusterId = _clusterId;
    flags |= (1 << 10);
}
const Uuid& ClusterInitialStatusBody::getClusterId() const { return clusterId; }
bool ClusterInitialStatusBody::hasClusterId() const { return flags & (1 << 10); }
void ClusterInitialStatusBody::clearClusterIdFlag() { flags &= ~(1 << 10); }

void ClusterInitialStatusBody::setStoreState(uint8_t _storeState) {
    storeState = _storeState;
    flags |= (1 << 11);
}
uint8_t ClusterInitialStatusBody::getStoreState() const { return storeState; }
bool ClusterInitialStatusBody::hasStoreState() const { return flags & (1 << 11); }
void ClusterInitialStatusBody::clearStoreStateFlag() { flags &= ~(1 << 11); }

void ClusterInitialStatusBody::setShutdownId(const Uuid& _shutdownId) {
    shutdownId = _shutdownId;
    flags |= (1 << 12);
}
const Uuid& ClusterInitialStatusBody::getShutdownId() const { return shutdownId; }
bool ClusterInitialStatusBody::hasShutdownId() const { return flags & (1 << 12); }
void ClusterInitialStatusBody::clearShutdownIdFlag() { flags &= ~(1 << 12); }

void ClusterInitialStatusBody::setFirstConfig(const std::string& _firstConfig) {
    firstConfig = _firstConfig;
    flags |= (1 << 13);
}
const std::string& ClusterInitialStatusBody::getFirstConfig() const { return firstConfig; }
bool ClusterInitialStatusBody::hasFirstConfig() const { return flags & (1 << 13); }
void ClusterInitialStatusBody::clearFirstConfigFlag() { flags &= ~(1 << 13); }

void ClusterInitialStatusBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLong(version);
    if (flags & (1 << 10))
        clusterId.encode(buffer);
    if (flags & (1 << 11))
        buffer.putOctet(storeState);
    if (flags & (1 << 12))
        shutdownId.encode(buffer);
    if (flags & (1 << 13))
        buffer.putMediumString(firstConfig);
}

void ClusterInitialStatusBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterInitialStatusBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        version = buffer.getLong();
    if (flags & (1 << 10))
        clusterId.decode(buffer);
    if (flags & (1 << 11))
        storeState = buffer.getOctet();
    if (flags & (1 << 12))
        shutdownId.decode(buffer);
    if (flags & (1 << 13))
        buffer.getMediumString(firstConfig);
}

void ClusterInitialStatusBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterInitialStatusBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 4;//version
    if (flags & (1 << 10))
        total += clusterId.encodedSize();
    if (flags & (1 << 11))
        total += 1;//storeState
    if (flags & (1 << 12))
        total += shutdownId.encodedSize();
    if (flags & (1 << 13))
        total += 2 + firstConfig.size();
    return total;
}

uint32_t ClusterInitialStatusBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterInitialStatusBody::print(std::ostream& out) const
{
    out << "{ClusterInitialStatusBody: ";
    if (flags & (1 << 8))
        out << "version=" << version << "; ";
    if (flags & (1 << 9))
        out << "active=" << getActive() << "; ";
    if (flags & (1 << 10))
        out << "cluster-id=" << clusterId << "; ";
    if (flags & (1 << 11))
        out << "store-state=" << (int) storeState << "; ";
    if (flags & (1 << 12))
        out << "shutdown-id=" << shutdownId << "; ";
    if (flags & (1 << 13))
        out << "first-config=" << firstConfig << "; ";
    out << "}";
}
