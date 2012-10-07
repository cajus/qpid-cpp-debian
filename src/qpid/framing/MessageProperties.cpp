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


#include "qpid/framing/MessageProperties.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void MessageProperties::setContentLength(uint64_t _contentLength) {
    contentLength = _contentLength;
    flags |= (1 << 8);
}
uint64_t MessageProperties::getContentLength() const { return contentLength; }
bool MessageProperties::hasContentLength() const { return flags & (1 << 8); }
void MessageProperties::clearContentLengthFlag() { flags &= ~(1 << 8); }

void MessageProperties::setMessageId(const Uuid& _messageId) {
    messageId = _messageId;
    flags |= (1 << 9);
}
const Uuid& MessageProperties::getMessageId() const { return messageId; }
bool MessageProperties::hasMessageId() const { return flags & (1 << 9); }
void MessageProperties::clearMessageIdFlag() { flags &= ~(1 << 9); }

void MessageProperties::setCorrelationId(const std::string& _correlationId) {
    correlationId = _correlationId;
    flags |= (1 << 10);
    if (correlationId.size() >= 65536) throw IllegalArgumentException("Value for correlationId is too large");
}
const std::string& MessageProperties::getCorrelationId() const { return correlationId; }
bool MessageProperties::hasCorrelationId() const { return flags & (1 << 10); }
void MessageProperties::clearCorrelationIdFlag() { flags &= ~(1 << 10); }

void MessageProperties::setReplyTo(const ReplyTo& _replyTo) {
    replyTo = _replyTo;
    flags |= (1 << 11);
}
const ReplyTo& MessageProperties::getReplyTo() const { return replyTo; }
bool MessageProperties::hasReplyTo() const { return flags & (1 << 11); }
void MessageProperties::clearReplyToFlag() { flags &= ~(1 << 11); }

void MessageProperties::setContentType(const std::string& _contentType) {
    contentType = _contentType;
    flags |= (1 << 12);
    if (contentType.size() >= 256) throw IllegalArgumentException("Value for contentType is too large");
}
const std::string& MessageProperties::getContentType() const { return contentType; }
bool MessageProperties::hasContentType() const { return flags & (1 << 12); }
void MessageProperties::clearContentTypeFlag() { flags &= ~(1 << 12); }

void MessageProperties::setContentEncoding(const std::string& _contentEncoding) {
    contentEncoding = _contentEncoding;
    flags |= (1 << 13);
    if (contentEncoding.size() >= 256) throw IllegalArgumentException("Value for contentEncoding is too large");
}
const std::string& MessageProperties::getContentEncoding() const { return contentEncoding; }
bool MessageProperties::hasContentEncoding() const { return flags & (1 << 13); }
void MessageProperties::clearContentEncodingFlag() { flags &= ~(1 << 13); }

void MessageProperties::setUserId(const std::string& _userId) {
    userId = _userId;
    flags |= (1 << 14);
    if (userId.size() >= 65536) throw IllegalArgumentException("Value for userId is too large");
}
const std::string& MessageProperties::getUserId() const { return userId; }
bool MessageProperties::hasUserId() const { return flags & (1 << 14); }
void MessageProperties::clearUserIdFlag() { flags &= ~(1 << 14); }

void MessageProperties::setAppId(const std::string& _appId) {
    appId = _appId;
    flags |= (1 << 15);
    if (appId.size() >= 65536) throw IllegalArgumentException("Value for appId is too large");
}
const std::string& MessageProperties::getAppId() const { return appId; }
bool MessageProperties::hasAppId() const { return flags & (1 << 15); }
void MessageProperties::clearAppIdFlag() { flags &= ~(1 << 15); }

void MessageProperties::setApplicationHeaders(const FieldTable& _applicationHeaders) {
    applicationHeaders = _applicationHeaders;
    flags |= (1 << 0);
}
const FieldTable& MessageProperties::getApplicationHeaders() const { return applicationHeaders; }
FieldTable& MessageProperties::getApplicationHeaders() {
    flags |= (1 << 0);
    return applicationHeaders;
}
bool MessageProperties::hasApplicationHeaders() const { return flags & (1 << 0); }
void MessageProperties::clearApplicationHeadersFlag() { flags &= ~(1 << 0); }

void MessageProperties::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongLong(contentLength);
    if (flags & (1 << 9))
        messageId.encode(buffer);
    if (flags & (1 << 10))
        buffer.putMediumString(correlationId);
    if (flags & (1 << 11))
        replyTo.encode(buffer);
    if (flags & (1 << 12))
        buffer.putShortString(contentType);
    if (flags & (1 << 13))
        buffer.putShortString(contentEncoding);
    if (flags & (1 << 14))
        buffer.putMediumString(userId);
    if (flags & (1 << 15))
        buffer.putMediumString(appId);
    if (flags & (1 << 0))
        applicationHeaders.encode(buffer);
}

void MessageProperties::encode(Buffer& buffer) const
{
    buffer.putLong(bodySize() + 2/*typecode*/);
    buffer.putShort(TYPE);
    encodeStructBody(buffer);
}

void MessageProperties::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        contentLength = buffer.getLongLong();
    if (flags & (1 << 9))
        messageId.decode(buffer);
    if (flags & (1 << 10))
        buffer.getMediumString(correlationId);
    if (flags & (1 << 11))
        replyTo.decode(buffer);
    if (flags & (1 << 12))
        buffer.getShortString(contentType);
    if (flags & (1 << 13))
        buffer.getShortString(contentEncoding);
    if (flags & (1 << 14))
        buffer.getMediumString(userId);
    if (flags & (1 << 15))
        buffer.getMediumString(appId);
    if (flags & (1 << 0))
        applicationHeaders.decode(buffer);
}

void MessageProperties::decode(Buffer& buffer, uint32_t /*size*/)
{
    buffer.getLong();
    if (TYPE != buffer.getShort()) throw FramingErrorException("Bad type code for struct");
    decodeStructBody(buffer);
}

uint32_t MessageProperties::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += 8;//contentLength
    if (flags & (1 << 9))
        total += messageId.encodedSize();
    if (flags & (1 << 10))
        total += 2 + correlationId.size();
    if (flags & (1 << 11))
        total += replyTo.encodedSize();
    if (flags & (1 << 12))
        total += 1 + contentType.size();
    if (flags & (1 << 13))
        total += 1 + contentEncoding.size();
    if (flags & (1 << 14))
        total += 2 + userId.size();
    if (flags & (1 << 15))
        total += 2 + appId.size();
    if (flags & (1 << 0))
        total += applicationHeaders.encodedSize();
    return total;
}

uint32_t MessageProperties::encodedSize() const {
    uint32_t total = bodySize();
total += 4/*size field*/;
total += 2/*typecode*/;
    return total;
}

void MessageProperties::print(std::ostream& out) const
{
    out << "{MessageProperties: ";
    if (flags & (1 << 8))
        out << "content-length=" << contentLength << "; ";
    if (flags & (1 << 9))
        out << "message-id=" << messageId << "; ";
    if (flags & (1 << 10))
        out << "correlation-id=" << correlationId << "; ";
    if (flags & (1 << 11))
        out << "reply-to=" << replyTo << "; ";
    if (flags & (1 << 12))
        out << "content-type=" << contentType << "; ";
    if (flags & (1 << 13))
        out << "content-encoding=" << contentEncoding << "; ";
    if (flags & (1 << 14))
        out << "user-id=" << userId << "; ";
    if (flags & (1 << 15))
        out << "app-id=" << appId << "; ";
    if (flags & (1 << 0))
        out << "application-headers=" << applicationHeaders << "; ";
    out << "}";
}
namespace qpid{
namespace framing{

    std::ostream& operator<<(std::ostream& out, const MessageProperties& s) 
    {
      s.print(out);
      return out;
    }

}
}
