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


#include "qpid/framing/ClusterErrorCheckBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterErrorCheckBody::setType(uint8_t _type) {
    type = _type;
    flags |= (1 << 8);
}
uint8_t ClusterErrorCheckBody::getType() const { return type; }
bool ClusterErrorCheckBody::hasType() const { return flags & (1 << 8); }
void ClusterErrorCheckBody::clearTypeFlag() { flags &= ~(1 << 8); }

void ClusterErrorCheckBody::setFrameSeq(const SequenceNumber& _frameSeq) {
    frameSeq = _frameSeq;
    flags |= (1 << 9);
}
SequenceNumber ClusterErrorCheckBody::getFrameSeq() const { return frameSeq; }
bool ClusterErrorCheckBody::hasFrameSeq() const { return flags & (1 << 9); }
void ClusterErrorCheckBody::clearFrameSeqFlag() { flags &= ~(1 << 9); }

void ClusterErrorCheckBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putOctet(type);
    if (flags & (1 << 9))
        frameSeq.encode(buffer);
}

void ClusterErrorCheckBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterErrorCheckBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        type = buffer.getOctet();
    if (flags & (1 << 9))
        frameSeq.decode(buffer);
}

void ClusterErrorCheckBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterErrorCheckBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1;//type
    if (flags & (1 << 9))
        total += frameSeq.encodedSize();
    return total;
}

uint32_t ClusterErrorCheckBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterErrorCheckBody::print(std::ostream& out) const
{
    out << "{ClusterErrorCheckBody: ";
    if (flags & (1 << 8))
        out << "type=" << (int) type << "; ";
    if (flags & (1 << 9))
        out << "frame-seq=" << frameSeq << "; ";
    out << "}";
}
