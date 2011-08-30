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


#include "qpid/framing/ClusterConnectionAnnounceBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionAnnounceBody::setManagementId(const std::string& _managementId) {
    managementId = _managementId;
    flags |= (1 << 8);
}
const std::string& ClusterConnectionAnnounceBody::getManagementId() const { return managementId; }
bool ClusterConnectionAnnounceBody::hasManagementId() const { return flags & (1 << 8); }
void ClusterConnectionAnnounceBody::clearManagementIdFlag() { flags &= ~(1 << 8); }

void ClusterConnectionAnnounceBody::setSsf(uint32_t _ssf) {
    ssf = _ssf;
    flags |= (1 << 9);
}
uint32_t ClusterConnectionAnnounceBody::getSsf() const { return ssf; }
bool ClusterConnectionAnnounceBody::hasSsf() const { return flags & (1 << 9); }
void ClusterConnectionAnnounceBody::clearSsfFlag() { flags &= ~(1 << 9); }

void ClusterConnectionAnnounceBody::setAuthid(const std::string& _authid) {
    authid = _authid;
    flags |= (1 << 10);
}
const std::string& ClusterConnectionAnnounceBody::getAuthid() const { return authid; }
bool ClusterConnectionAnnounceBody::hasAuthid() const { return flags & (1 << 10); }
void ClusterConnectionAnnounceBody::clearAuthidFlag() { flags &= ~(1 << 10); }

void ClusterConnectionAnnounceBody::setNodict(bool _nodict) {
    if (_nodict) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool ClusterConnectionAnnounceBody::getNodict() const { return flags & (1 << 11); }

void ClusterConnectionAnnounceBody::setUsername(const std::string& _username) {
    username = _username;
    flags |= (1 << 12);
}
const std::string& ClusterConnectionAnnounceBody::getUsername() const { return username; }
bool ClusterConnectionAnnounceBody::hasUsername() const { return flags & (1 << 12); }
void ClusterConnectionAnnounceBody::clearUsernameFlag() { flags &= ~(1 << 12); }

void ClusterConnectionAnnounceBody::setInitialFrames(const std::string& _initialFrames) {
    initialFrames = _initialFrames;
    flags |= (1 << 13);
}
const std::string& ClusterConnectionAnnounceBody::getInitialFrames() const { return initialFrames; }
bool ClusterConnectionAnnounceBody::hasInitialFrames() const { return flags & (1 << 13); }
void ClusterConnectionAnnounceBody::clearInitialFramesFlag() { flags &= ~(1 << 13); }

void ClusterConnectionAnnounceBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putMediumString(managementId);
    if (flags & (1 << 9))
        buffer.putLong(ssf);
    if (flags & (1 << 10))
        buffer.putMediumString(authid);
    if (flags & (1 << 12))
        buffer.putLongString(username);
    if (flags & (1 << 13))
        buffer.putLongString(initialFrames);
}

void ClusterConnectionAnnounceBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionAnnounceBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getMediumString(managementId);
    if (flags & (1 << 9))
        ssf = buffer.getLong();
    if (flags & (1 << 10))
        buffer.getMediumString(authid);
    if (flags & (1 << 12))
        buffer.getLongString(username);
    if (flags & (1 << 13))
        buffer.getLongString(initialFrames);
}

void ClusterConnectionAnnounceBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionAnnounceBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2 + managementId.size();
    if (flags & (1 << 9))
        total += 4;//ssf
    if (flags & (1 << 10))
        total += 2 + authid.size();
    if (flags & (1 << 12))
        total += 4 + username.size();
    if (flags & (1 << 13))
        total += 4 + initialFrames.size();
    return total;
}

uint32_t ClusterConnectionAnnounceBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionAnnounceBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionAnnounceBody: ";
    if (flags & (1 << 8))
        out << "management-id=" << managementId << "; ";
    if (flags & (1 << 9))
        out << "ssf=" << ssf << "; ";
    if (flags & (1 << 10))
        out << "authid=" << authid << "; ";
    if (flags & (1 << 11))
        out << "nodict=" << getNodict() << "; ";
    if (flags & (1 << 12))
        out << "username=" << username << "; ";
    if (flags & (1 << 13))
        out << "initial-frames=" << initialFrames << "; ";
    out << "}";
}
