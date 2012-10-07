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


#include "qpid/framing/ConnectionTuneOkBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionTuneOkBody::setChannelMax(uint16_t _channelMax) {
    channelMax = _channelMax;
    flags |= (1 << 8);
}
uint16_t ConnectionTuneOkBody::getChannelMax() const { return channelMax; }
bool ConnectionTuneOkBody::hasChannelMax() const { return flags & (1 << 8); }
void ConnectionTuneOkBody::clearChannelMaxFlag() { flags &= ~(1 << 8); }

void ConnectionTuneOkBody::setMaxFrameSize(uint16_t _maxFrameSize) {
    maxFrameSize = _maxFrameSize;
    flags |= (1 << 9);
}
uint16_t ConnectionTuneOkBody::getMaxFrameSize() const { return maxFrameSize; }
bool ConnectionTuneOkBody::hasMaxFrameSize() const { return flags & (1 << 9); }
void ConnectionTuneOkBody::clearMaxFrameSizeFlag() { flags &= ~(1 << 9); }

void ConnectionTuneOkBody::setHeartbeat(uint16_t _heartbeat) {
    heartbeat = _heartbeat;
    flags |= (1 << 10);
}
uint16_t ConnectionTuneOkBody::getHeartbeat() const { return heartbeat; }
bool ConnectionTuneOkBody::hasHeartbeat() const { return flags & (1 << 10); }
void ConnectionTuneOkBody::clearHeartbeatFlag() { flags &= ~(1 << 10); }

void ConnectionTuneOkBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(channelMax);
    if (flags & (1 << 9))
        buffer.putShort(maxFrameSize);
    if (flags & (1 << 10))
        buffer.putShort(heartbeat);
}

void ConnectionTuneOkBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionTuneOkBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        channelMax = buffer.getShort();
    if (flags & (1 << 9))
        maxFrameSize = buffer.getShort();
    if (flags & (1 << 10))
        heartbeat = buffer.getShort();
}

void ConnectionTuneOkBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionTuneOkBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 2;//channelMax
    if (flags & (1 << 9))
        total += 2;//maxFrameSize
    if (flags & (1 << 10))
        total += 2;//heartbeat
    return total;
}

uint32_t ConnectionTuneOkBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionTuneOkBody::print(std::ostream& out) const
{
    out << "{ConnectionTuneOkBody: ";
    if (flags & (1 << 8))
        out << "channel-max=" << channelMax << "; ";
    if (flags & (1 << 9))
        out << "max-frame-size=" << maxFrameSize << "; ";
    if (flags & (1 << 10))
        out << "heartbeat=" << heartbeat << "; ";
    out << "}";
}
