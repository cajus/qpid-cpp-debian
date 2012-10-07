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


#include "qpid/framing/StreamProperties.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void StreamProperties::setContentType(const std::string& _contentType) {
    contentType = _contentType;
    flags |= (1 << 8);
    if (contentType.size() >= 256) throw IllegalArgumentException("Value for contentType is too large");
}
const std::string& StreamProperties::getContentType() const { return contentType; }
bool StreamProperties::hasContentType() const { return flags & (1 << 8); }
void StreamProperties::clearContentTypeFlag() { flags &= ~(1 << 8); }

void StreamProperties::setContentEncoding(const std::string& _contentEncoding) {
    contentEncoding = _contentEncoding;
    flags |= (1 << 9);
    if (contentEncoding.size() >= 256) throw IllegalArgumentException("Value for contentEncoding is too large");
}
const std::string& StreamProperties::getContentEncoding() const { return contentEncoding; }
bool StreamProperties::hasContentEncoding() const { return flags & (1 << 9); }
void StreamProperties::clearContentEncodingFlag() { flags &= ~(1 << 9); }

void StreamProperties::setHeaders(const FieldTable& _headers) {
    headers = _headers;
    flags |= (1 << 10);
}
const FieldTable& StreamProperties::getHeaders() const { return headers; }
FieldTable& StreamProperties::getHeaders() {
    flags |= (1 << 10);
    return headers;
}
bool StreamProperties::hasHeaders() const { return flags & (1 << 10); }
void StreamProperties::clearHeadersFlag() { flags &= ~(1 << 10); }

void StreamProperties::setPriority(uint8_t _priority) {
    priority = _priority;
    flags |= (1 << 11);
}
uint8_t StreamProperties::getPriority() const { return priority; }
bool StreamProperties::hasPriority() const { return flags & (1 << 11); }
void StreamProperties::clearPriorityFlag() { flags &= ~(1 << 11); }

void StreamProperties::setTimestamp(uint64_t _timestamp) {
    timestamp = _timestamp;
    flags |= (1 << 12);
}
uint64_t StreamProperties::getTimestamp() const { return timestamp; }
bool StreamProperties::hasTimestamp() const { return flags & (1 << 12); }
void StreamProperties::clearTimestampFlag() { flags &= ~(1 << 12); }

void StreamProperties::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(contentType);
    if (flags & (1 << 9))
        buffer.putShortString(contentEncoding);
    if (flags & (1 << 10))
        headers.encode(buffer);
    if (flags & (1 << 11))
        buffer.putOctet(priority);
    if (flags & (1 << 12))
        buffer.putLongLong(timestamp);
}

void StreamProperties::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void StreamProperties::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(contentType);
    if (flags & (1 << 9))
        buffer.getShortString(contentEncoding);
    if (flags & (1 << 10))
        headers.decode(buffer);
    if (flags & (1 << 11))
        priority = buffer.getOctet();
    if (flags & (1 << 12))
        timestamp = buffer.getLongLong();
}

void StreamProperties::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t StreamProperties::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 1 + contentType.size();
    if (flags & (1 << 9))
        total += 1 + contentEncoding.size();
    if (flags & (1 << 10))
        total += headers.encodedSize();
    if (flags & (1 << 11))
        total += 1;//priority
    if (flags & (1 << 12))
        total += 8;//timestamp
    return total;
}

uint32_t StreamProperties::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void StreamProperties::print(std::ostream& out) const
{
    out << "{StreamProperties: ";
    if (flags & (1 << 8))
        out << "content-type=" << contentType << "; ";
    if (flags & (1 << 9))
        out << "content-encoding=" << contentEncoding << "; ";
    if (flags & (1 << 10))
        out << "headers=" << headers << "; ";
    if (flags & (1 << 11))
        out << "priority=" << (int) priority << "; ";
    if (flags & (1 << 12))
        out << "timestamp=" << timestamp << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const StreamProperties& s) 
    {
      s.print(out);
      return out;
    }

}
}
