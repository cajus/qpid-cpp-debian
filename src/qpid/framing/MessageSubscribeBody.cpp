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


#include "qpid/framing/MessageSubscribeBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageSubscribeBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& MessageSubscribeBody::getQueue() const { return queue; }
bool MessageSubscribeBody::hasQueue() const { return flags & (1 << 8); }
void MessageSubscribeBody::clearQueueFlag() { flags &= ~(1 << 8); }

void MessageSubscribeBody::setDestination(const std::string& _destination) {
    destination = _destination;
    flags |= (1 << 9);
    if (destination.size() >= 256) throw IllegalArgumentException("Value for destination is too large");
}
const std::string& MessageSubscribeBody::getDestination() const { return destination; }
bool MessageSubscribeBody::hasDestination() const { return flags & (1 << 9); }
void MessageSubscribeBody::clearDestinationFlag() { flags &= ~(1 << 9); }

void MessageSubscribeBody::setAcceptMode(uint8_t _acceptMode) {
    acceptMode = _acceptMode;
    flags |= (1 << 10);
}
uint8_t MessageSubscribeBody::getAcceptMode() const { return acceptMode; }
bool MessageSubscribeBody::hasAcceptMode() const { return flags & (1 << 10); }
void MessageSubscribeBody::clearAcceptModeFlag() { flags &= ~(1 << 10); }

void MessageSubscribeBody::setAcquireMode(uint8_t _acquireMode) {
    acquireMode = _acquireMode;
    flags |= (1 << 11);
}
uint8_t MessageSubscribeBody::getAcquireMode() const { return acquireMode; }
bool MessageSubscribeBody::hasAcquireMode() const { return flags & (1 << 11); }
void MessageSubscribeBody::clearAcquireModeFlag() { flags &= ~(1 << 11); }

void MessageSubscribeBody::setExclusive(bool _exclusive) {
    if (_exclusive) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool MessageSubscribeBody::getExclusive() const { return flags & (1 << 12); }

void MessageSubscribeBody::setResumeId(const std::string& _resumeId) {
    resumeId = _resumeId;
    flags |= (1 << 13);
    if (resumeId.size() >= 65536) throw IllegalArgumentException("Value for resumeId is too large");
}
const std::string& MessageSubscribeBody::getResumeId() const { return resumeId; }
bool MessageSubscribeBody::hasResumeId() const { return flags & (1 << 13); }
void MessageSubscribeBody::clearResumeIdFlag() { flags &= ~(1 << 13); }

void MessageSubscribeBody::setResumeTtl(uint64_t _resumeTtl) {
    resumeTtl = _resumeTtl;
    flags |= (1 << 14);
}
uint64_t MessageSubscribeBody::getResumeTtl() const { return resumeTtl; }
bool MessageSubscribeBody::hasResumeTtl() const { return flags & (1 << 14); }
void MessageSubscribeBody::clearResumeTtlFlag() { flags &= ~(1 << 14); }

void MessageSubscribeBody::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 15);
}
const FieldTable& MessageSubscribeBody::getArguments() const { return arguments; }
FieldTable& MessageSubscribeBody::getArguments() {
    flags |= (1 << 15);
    return arguments;
}
bool MessageSubscribeBody::hasArguments() const { return flags & (1 << 15); }
void MessageSubscribeBody::clearArgumentsFlag() { flags &= ~(1 << 15); }

void MessageSubscribeBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putShortString(destination);
    if (flags & (1 << 10))
        buffer.putOctet(acceptMode);
    if (flags & (1 << 11))
        buffer.putOctet(acquireMode);
    if (flags & (1 << 13))
        buffer.putMediumString(resumeId);
    if (flags & (1 << 14))
        buffer.putLongLong(resumeTtl);
    if (flags & (1 << 15))
        arguments.encode(buffer);
}

void MessageSubscribeBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageSubscribeBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        buffer.getShortString(destination);
    if (flags & (1 << 10))
        acceptMode = buffer.getOctet();
    if (flags & (1 << 11))
        acquireMode = buffer.getOctet();
    if (flags & (1 << 13))
        buffer.getMediumString(resumeId);
    if (flags & (1 << 14))
        resumeTtl = buffer.getLongLong();
    if (flags & (1 << 15))
        arguments.decode(buffer);
}

void MessageSubscribeBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageSubscribeBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1 + destination.size();
    if (flags & (1 << 10))
        total += 1;//acceptMode
    if (flags & (1 << 11))
        total += 1;//acquireMode
    if (flags & (1 << 13))
        total += 2 + resumeId.size();
    if (flags & (1 << 14))
        total += 8;//resumeTtl
    if (flags & (1 << 15))
        total += arguments.encodedSize();
    return total;
}

uint32_t MessageSubscribeBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageSubscribeBody::print(std::ostream& out) const
{
    out << "{MessageSubscribeBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "destination=" << destination << "; ";
    if (flags & (1 << 10))
        out << "accept-mode=" << (int) acceptMode << "; ";
    if (flags & (1 << 11))
        out << "acquire-mode=" << (int) acquireMode << "; ";
    if (flags & (1 << 12))
        out << "exclusive=" << getExclusive() << "; ";
    if (flags & (1 << 13))
        out << "resume-id=" << resumeId << "; ";
    if (flags & (1 << 14))
        out << "resume-ttl=" << resumeTtl << "; ";
    if (flags & (1 << 15))
        out << "arguments=" << arguments << "; ";
    out << "}";
}
