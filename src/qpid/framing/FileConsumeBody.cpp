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


#include "qpid/framing/FileConsumeBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void FileConsumeBody::setQueue(const std::string& _queue) {
    queue = _queue;
    flags |= (1 << 8);
    if (queue.size() >= 256) throw IllegalArgumentException("Value for queue is too large");
}
const std::string& FileConsumeBody::getQueue() const { return queue; }
bool FileConsumeBody::hasQueue() const { return flags & (1 << 8); }
void FileConsumeBody::clearQueueFlag() { flags &= ~(1 << 8); }

void FileConsumeBody::setConsumerTag(const std::string& _consumerTag) {
    consumerTag = _consumerTag;
    flags |= (1 << 9);
    if (consumerTag.size() >= 256) throw IllegalArgumentException("Value for consumerTag is too large");
}
const std::string& FileConsumeBody::getConsumerTag() const { return consumerTag; }
bool FileConsumeBody::hasConsumerTag() const { return flags & (1 << 9); }
void FileConsumeBody::clearConsumerTagFlag() { flags &= ~(1 << 9); }

void FileConsumeBody::setNoLocal(bool _noLocal) {
    if (_noLocal) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool FileConsumeBody::getNoLocal() const { return flags & (1 << 10); }

void FileConsumeBody::setNoAck(bool _noAck) {
    if (_noAck) flags |= (1 << 11);
    else flags &= ~(1 << 11);
}
bool FileConsumeBody::getNoAck() const { return flags & (1 << 11); }

void FileConsumeBody::setExclusive(bool _exclusive) {
    if (_exclusive) flags |= (1 << 12);
    else flags &= ~(1 << 12);
}
bool FileConsumeBody::getExclusive() const { return flags & (1 << 12); }

void FileConsumeBody::setNowait(bool _nowait) {
    if (_nowait) flags |= (1 << 13);
    else flags &= ~(1 << 13);
}
bool FileConsumeBody::getNowait() const { return flags & (1 << 13); }

void FileConsumeBody::setArguments(const FieldTable& _arguments) {
    arguments = _arguments;
    flags |= (1 << 14);
}
const FieldTable& FileConsumeBody::getArguments() const { return arguments; }
FieldTable& FileConsumeBody::getArguments() {
    flags |= (1 << 14);
    return arguments;
}
bool FileConsumeBody::hasArguments() const { return flags & (1 << 14); }
void FileConsumeBody::clearArgumentsFlag() { flags &= ~(1 << 14); }

void FileConsumeBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShortString(queue);
    if (flags & (1 << 9))
        buffer.putShortString(consumerTag);
    if (flags & (1 << 14))
        arguments.encode(buffer);
}

void FileConsumeBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void FileConsumeBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        buffer.getShortString(queue);
    if (flags & (1 << 9))
        buffer.getShortString(consumerTag);
    if (flags & (1 << 14))
        arguments.decode(buffer);
}

void FileConsumeBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t FileConsumeBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 1 + queue.size();
    if (flags & (1 << 9))
        total += 1 + consumerTag.size();
    if (flags & (1 << 14))
        total += arguments.encodedSize();
    return total;
}

uint32_t FileConsumeBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void FileConsumeBody::print(std::ostream& out) const
{
    out << "{FileConsumeBody: ";
    if (flags & (1 << 8))
        out << "queue=" << queue << "; ";
    if (flags & (1 << 9))
        out << "consumer-tag=" << consumerTag << "; ";
    if (flags & (1 << 10))
        out << "no-local=" << getNoLocal() << "; ";
    if (flags & (1 << 11))
        out << "no-ack=" << getNoAck() << "; ";
    if (flags & (1 << 12))
        out << "exclusive=" << getExclusive() << "; ";
    if (flags & (1 << 13))
        out << "nowait=" << getNowait() << "; ";
    if (flags & (1 << 14))
        out << "arguments=" << arguments << "; ";
    out << "}";
}
