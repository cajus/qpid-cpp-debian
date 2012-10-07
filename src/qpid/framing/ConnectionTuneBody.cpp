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


#include "qpid/framing/ConnectionTuneBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionTuneBody::setChannelMax(uint16_t _channelMax) {
    channelMax = _channelMax;
    flags |= (1 << 8);
}
uint16_t ConnectionTuneBody::getChannelMax() const { return channelMax; }
bool ConnectionTuneBody::hasChannelMax() const { return flags & (1 << 8); }
void ConnectionTuneBody::clearChannelMaxFlag() { flags &= ~(1 << 8); }

void ConnectionTuneBody::setMaxFrameSize(uint16_t _maxFrameSize) {
    maxFrameSize = _maxFrameSize;
    flags |= (1 << 9);
}
uint16_t ConnectionTuneBody::getMaxFrameSize() const { return maxFrameSize; }
bool ConnectionTuneBody::hasMaxFrameSize() const { return flags & (1 << 9); }
void ConnectionTuneBody::clearMaxFrameSizeFlag() { flags &= ~(1 << 9); }

void ConnectionTuneBody::setHeartbeatMin(uint16_t _heartbeatMin) {
    heartbeatMin = _heartbeatMin;
    flags |= (1 << 10);
}
uint16_t ConnectionTuneBody::getHeartbeatMin() const { return heartbeatMin; }
bool ConnectionTuneBody::hasHeartbeatMin() const { return flags & (1 << 10); }
void ConnectionTuneBody::clearHeartbeatMinFlag() { flags &= ~(1 << 10); }

void ConnectionTuneBody::setHeartbeatMax(uint16_t _heartbeatMax) {
    heartbeatMax = _heartbeatMax;
    flags |= (1 << 11);
}
uint16_t ConnectionTuneBody::getHeartbeatMax() const { return heartbeatMax; }
bool ConnectionTuneBody::hasHeartbeatMax() const { return flags & (1 << 11); }
void ConnectionTuneBody::clearHeartbeatMaxFlag() { flags &= ~(1 << 11); }

void ConnectionTuneBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(channelMax);
    if (flags & (1 << 9))
        buffer.putShort(maxFrameSize);
    if (flags & (1 << 10))
        buffer.putShort(heartbeatMin);
    if (flags & (1 << 11))
        buffer.putShort(heartbeatMax);
}

void ConnectionTuneBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionTuneBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        channelMax = buffer.getShort();
    if (flags & (1 << 9))
        maxFrameSize = buffer.getShort();
    if (flags & (1 << 10))
        heartbeatMin = buffer.getShort();
    if (flags & (1 << 11))
        heartbeatMax = buffer.getShort();
}

void ConnectionTuneBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionTuneBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 2;//channelMax
    if (flags & (1 << 9))
        total += 2;//maxFrameSize
    if (flags & (1 << 10))
        total += 2;//heartbeatMin
    if (flags & (1 << 11))
        total += 2;//heartbeatMax
    return total;
}

uint32_t ConnectionTuneBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionTuneBody::print(std::ostream& out) const
{
    out << "{ConnectionTuneBody: ";
    if (flags & (1 << 8))
        out << "channel-max=" << channelMax << "; ";
    if (flags & (1 << 9))
        out << "max-frame-size=" << maxFrameSize << "; ";
    if (flags & (1 << 10))
        out << "heartbeat-min=" << heartbeatMin << "; ";
    if (flags & (1 << 11))
        out << "heartbeat-max=" << heartbeatMax << "; ";
    out << "}";
}
