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


#include "qpid/framing/MessageResumeBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageResumeBody::setDestination(const std::string& _destination) {
    destination = _destination;
    flags |= (1 << 8);
    if (destination.size() >= 256) throw IllegalArgumentException("Value for destination is too large");
}
const std::string& MessageResumeBody::getDestination() const { return destination; }
bool MessageResumeBody::hasDestination() const { return flags & (1 << 8); }
void MessageResumeBody::clearDestinationFlag() { flags &= ~(1 << 8); }

void MessageResumeBody::setResumeId(const std::string& _resumeId) {
    resumeId = _resumeId;
    flags |= (1 << 9);
    if (resumeId.size() >= 65536) throw IllegalArgumentException("Value for resumeId is too large");
}
const std::string& MessageResumeBody::getResumeId() const { return resumeId; }
bool MessageResumeBody::hasResumeId() const { return flags & (1 << 9); }
void MessageResumeBody::clearResumeIdFlag() { flags &= ~(1 << 9); }

void MessageResumeBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(destination);
    if (flags & (1 << 9))
        buffer.putMediumString(resumeId);
}

void MessageResumeBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void MessageResumeBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(destination);
    if (flags & (1 << 9))
        buffer.getMediumString(resumeId);
}

void MessageResumeBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t MessageResumeBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + destination.size();
    if (flags & (1 << 9))
        total += 2 + resumeId.size();
    return total;
}

uint32_t MessageResumeBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void MessageResumeBody::print(std::ostream& out) const
{
    out << "{MessageResumeBody: ";
    if (flags & (1 << 8))
        out << "destination=" << destination << "; ";
    if (flags & (1 << 9))
        out << "resume-id=" << resumeId << "; ";
    out << "}";
}
