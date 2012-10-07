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


#include "qpid/framing/FileRejectBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FileRejectBody::setDeliveryTag(uint64_t _deliveryTag) {
    deliveryTag = _deliveryTag;
    flags |= (1 << 8);
}
uint64_t FileRejectBody::getDeliveryTag() const { return deliveryTag; }
bool FileRejectBody::hasDeliveryTag() const { return flags & (1 << 8); }
void FileRejectBody::clearDeliveryTagFlag() { flags &= ~(1 << 8); }

void FileRejectBody::setRequeue(bool _requeue) {
    if (_requeue) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool FileRejectBody::getRequeue() const { return flags & (1 << 9); }

void FileRejectBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongLong(deliveryTag);
}

void FileRejectBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void FileRejectBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        deliveryTag = buffer.getLongLong();
}

void FileRejectBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t FileRejectBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 8;//deliveryTag
    return total;
}

uint32_t FileRejectBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void FileRejectBody::print(std::ostream& out) const
{
    out << "{FileRejectBody: ";
    if (flags & (1 << 8))
        out << "delivery-tag=" << deliveryTag << "; ";
    if (flags & (1 << 9))
        out << "requeue=" << getRequeue() << "; ";
    out << "}";
}
