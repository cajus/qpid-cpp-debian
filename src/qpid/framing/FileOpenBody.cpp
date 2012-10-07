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


#include "qpid/framing/FileOpenBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FileOpenBody::setIdentifier(const std::string& _identifier) {
    identifier = _identifier;
    flags |= (1 << 8);
    if (identifier.size() >= 256) throw IllegalArgumentException("Value for identifier is too large");
}
const std::string& FileOpenBody::getIdentifier() const { return identifier; }
bool FileOpenBody::hasIdentifier() const { return flags & (1 << 8); }
void FileOpenBody::clearIdentifierFlag() { flags &= ~(1 << 8); }

void FileOpenBody::setContentSize(uint64_t _contentSize) {
    contentSize = _contentSize;
    flags |= (1 << 9);
}
uint64_t FileOpenBody::getContentSize() const { return contentSize; }
bool FileOpenBody::hasContentSize() const { return flags & (1 << 9); }
void FileOpenBody::clearContentSizeFlag() { flags &= ~(1 << 9); }

void FileOpenBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(identifier);
    if (flags & (1 << 9))
        buffer.putLongLong(contentSize);
}

void FileOpenBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void FileOpenBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(identifier);
    if (flags & (1 << 9))
        contentSize = buffer.getLongLong();
}

void FileOpenBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t FileOpenBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + identifier.size();
    if (flags & (1 << 9))
        total += 8;//contentSize
    return total;
}

uint32_t FileOpenBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void FileOpenBody::print(std::ostream& out) const
{
    out << "{FileOpenBody: ";
    if (flags & (1 << 8))
        out << "identifier=" << identifier << "; ";
    if (flags & (1 << 9))
        out << "content-size=" << contentSize << "; ";
    out << "}";
}
