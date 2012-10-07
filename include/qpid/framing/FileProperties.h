#ifndef QPID_FRAMING_FILEPROPERTIES_H
#define QPID_FRAMING_FILEPROPERTIES_H
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



#include <ostream>
#include "qpid/framing/amqp_types_full.h"
#include "qpid/framing/reply_exceptions.h"
#include "qpid/CommonImportExport.h"

namespace qpid {
namespace framing {

class QPID_COMMON_CLASS_EXTERN FileProperties  {
    std::string contentType;
    std::string contentEncoding;
    FieldTable headers;
    uint8_t priority;
    std::string replyTo;
    std::string messageId;
    std::string filename;
    uint64_t timestamp;
    std::string clusterId;
    uint16_t flags;
public:
    static const uint16_t TYPE = 2305;
    FileProperties(
        const std::string& _contentType,
        const std::string& _contentEncoding,
        const FieldTable& _headers,
        uint8_t _priority,
        const std::string& _replyTo,
        const std::string& _messageId,
        const std::string& _filename,
        uint64_t _timestamp,
        const std::string& _clusterId) : 
        contentType(_contentType),
        contentEncoding(_contentEncoding),
        headers(_headers),
        priority(_priority),
        replyTo(_replyTo),
        messageId(_messageId),
        filename(_filename),
        timestamp(_timestamp),
        clusterId(_clusterId),
        flags(0){
        flags |= (1 << 8);
        flags |= (1 << 9);
        flags |= (1 << 10);
        flags |= (1 << 11);
        flags |= (1 << 12);
        flags |= (1 << 13);
        flags |= (1 << 14);
        flags |= (1 << 15);
        flags |= (1 << 0);
        if (contentType.size() >= 256) throw IllegalArgumentException("Value for contentType is too large");
        if (contentEncoding.size() >= 256) throw IllegalArgumentException("Value for contentEncoding is too large");
        if (replyTo.size() >= 256) throw IllegalArgumentException("Value for replyTo is too large");
        if (messageId.size() >= 256) throw IllegalArgumentException("Value for messageId is too large");
        if (filename.size() >= 256) throw IllegalArgumentException("Value for filename is too large");
        if (clusterId.size() >= 256) throw IllegalArgumentException("Value for clusterId is too large");
    }
    FileProperties()  : priority(0), timestamp(0), flags(0) {}
    
    QPID_COMMON_EXTERN void setContentType(const std::string& _contentType);
    QPID_COMMON_EXTERN const std::string& getContentType() const;
    QPID_COMMON_EXTERN bool hasContentType() const;
    QPID_COMMON_EXTERN void clearContentTypeFlag();
    QPID_COMMON_EXTERN void setContentEncoding(const std::string& _contentEncoding);
    QPID_COMMON_EXTERN const std::string& getContentEncoding() const;
    QPID_COMMON_EXTERN bool hasContentEncoding() const;
    QPID_COMMON_EXTERN void clearContentEncodingFlag();
    QPID_COMMON_EXTERN void setHeaders(const FieldTable& _headers);
    QPID_COMMON_EXTERN const FieldTable& getHeaders() const;
    QPID_COMMON_EXTERN FieldTable& getHeaders();
    QPID_COMMON_EXTERN bool hasHeaders() const;
    QPID_COMMON_EXTERN void clearHeadersFlag();
    QPID_COMMON_EXTERN void setPriority(uint8_t _priority);
    QPID_COMMON_EXTERN uint8_t getPriority() const;
    QPID_COMMON_EXTERN bool hasPriority() const;
    QPID_COMMON_EXTERN void clearPriorityFlag();
    QPID_COMMON_EXTERN void setReplyTo(const std::string& _replyTo);
    QPID_COMMON_EXTERN const std::string& getReplyTo() const;
    QPID_COMMON_EXTERN bool hasReplyTo() const;
    QPID_COMMON_EXTERN void clearReplyToFlag();
    QPID_COMMON_EXTERN void setMessageId(const std::string& _messageId);
    QPID_COMMON_EXTERN const std::string& getMessageId() const;
    QPID_COMMON_EXTERN bool hasMessageId() const;
    QPID_COMMON_EXTERN void clearMessageIdFlag();
    QPID_COMMON_EXTERN void setFilename(const std::string& _filename);
    QPID_COMMON_EXTERN const std::string& getFilename() const;
    QPID_COMMON_EXTERN bool hasFilename() const;
    QPID_COMMON_EXTERN void clearFilenameFlag();
    QPID_COMMON_EXTERN void setTimestamp(uint64_t _timestamp);
    QPID_COMMON_EXTERN uint64_t getTimestamp() const;
    QPID_COMMON_EXTERN bool hasTimestamp() const;
    QPID_COMMON_EXTERN void clearTimestampFlag();
    QPID_COMMON_EXTERN void setClusterId(const std::string& _clusterId);
    QPID_COMMON_EXTERN const std::string& getClusterId() const;
    QPID_COMMON_EXTERN bool hasClusterId() const;
    QPID_COMMON_EXTERN void clearClusterIdFlag();
    QPID_COMMON_EXTERN friend std::ostream& operator<<(std::ostream&, const FileProperties&);
    QPID_COMMON_EXTERN void encode(Buffer&) const;
    QPID_COMMON_EXTERN void decode(Buffer&, uint32_t=0);
    QPID_COMMON_EXTERN void encodeStructBody(Buffer&) const;
    QPID_COMMON_EXTERN void decodeStructBody(Buffer&, uint32_t=0);
    QPID_COMMON_EXTERN uint32_t encodedSize() const;
    QPID_COMMON_EXTERN uint32_t bodySize() const;
    QPID_COMMON_EXTERN void print(std::ostream& out) const;
}; /* class FileProperties */

}}
#endif  /*!QPID_FRAMING_FILEPROPERTIES_H*/
