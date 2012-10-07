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


#include "qpid/framing/ExecutionExceptionBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ExecutionExceptionBody::setErrorCode(uint16_t _errorCode) {
    errorCode = _errorCode;
    flags |= (1 << 8);
}
uint16_t ExecutionExceptionBody::getErrorCode() const { return errorCode; }
bool ExecutionExceptionBody::hasErrorCode() const { return flags & (1 << 8); }
void ExecutionExceptionBody::clearErrorCodeFlag() { flags &= ~(1 << 8); }

void ExecutionExceptionBody::setCommandId(const SequenceNumber& _commandId) {
    commandId = _commandId;
    flags |= (1 << 9);
}
SequenceNumber ExecutionExceptionBody::getCommandId() const { return commandId; }
bool ExecutionExceptionBody::hasCommandId() const { return flags & (1 << 9); }
void ExecutionExceptionBody::clearCommandIdFlag() { flags &= ~(1 << 9); }

void ExecutionExceptionBody::setClassCode(uint8_t _classCode) {
    classCode = _classCode;
    flags |= (1 << 10);
}
uint8_t ExecutionExceptionBody::getClassCode() const { return classCode; }
bool ExecutionExceptionBody::hasClassCode() const { return flags & (1 << 10); }
void ExecutionExceptionBody::clearClassCodeFlag() { flags &= ~(1 << 10); }

void ExecutionExceptionBody::setCommandCode(uint8_t _commandCode) {
    commandCode = _commandCode;
    flags |= (1 << 11);
}
uint8_t ExecutionExceptionBody::getCommandCode() const { return commandCode; }
bool ExecutionExceptionBody::hasCommandCode() const { return flags & (1 << 11); }
void ExecutionExceptionBody::clearCommandCodeFlag() { flags &= ~(1 << 11); }

void ExecutionExceptionBody::setFieldIndex(uint8_t _fieldIndex) {
    fieldIndex = _fieldIndex;
    flags |= (1 << 12);
}
uint8_t ExecutionExceptionBody::getFieldIndex() const { return fieldIndex; }
bool ExecutionExceptionBody::hasFieldIndex() const { return flags & (1 << 12); }
void ExecutionExceptionBody::clearFieldIndexFlag() { flags &= ~(1 << 12); }

void ExecutionExceptionBody::setDescription(const std::string& _description) {
    description = _description;
    flags |= (1 << 13);
    if (description.size() >= 65536) throw IllegalArgumentException("Value for description is too large");
}
const std::string& ExecutionExceptionBody::getDescription() const { return description; }
bool ExecutionExceptionBody::hasDescription() const { return flags & (1 << 13); }
void ExecutionExceptionBody::clearDescriptionFlag() { flags &= ~(1 << 13); }

void ExecutionExceptionBody::setErrorInfo(const FieldTable& _errorInfo) {
    errorInfo = _errorInfo;
    flags |= (1 << 14);
}
const FieldTable& ExecutionExceptionBody::getErrorInfo() const { return errorInfo; }
FieldTable& ExecutionExceptionBody::getErrorInfo() {
    flags |= (1 << 14);
    return errorInfo;
}
bool ExecutionExceptionBody::hasErrorInfo() const { return flags & (1 << 14); }
void ExecutionExceptionBody::clearErrorInfoFlag() { flags &= ~(1 << 14); }

void ExecutionExceptionBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putShort(errorCode);
    if (flags & (1 << 9))
        commandId.encode(buffer);
    if (flags & (1 << 10))
        buffer.putOctet(classCode);
    if (flags & (1 << 11))
        buffer.putOctet(commandCode);
    if (flags & (1 << 12))
        buffer.putOctet(fieldIndex);
    if (flags & (1 << 13))
        buffer.putMediumString(description);
    if (flags & (1 << 14))
        errorInfo.encode(buffer);
}

void ExecutionExceptionBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ExecutionExceptionBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        errorCode = buffer.getShort();
    if (flags & (1 << 9))
        commandId.decode(buffer);
    if (flags & (1 << 10))
        classCode = buffer.getOctet();
    if (flags & (1 << 11))
        commandCode = buffer.getOctet();
    if (flags & (1 << 12))
        fieldIndex = buffer.getOctet();
    if (flags & (1 << 13))
        buffer.getMediumString(description);
    if (flags & (1 << 14))
        errorInfo.decode(buffer);
}

void ExecutionExceptionBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ExecutionExceptionBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 2;//errorCode
    if (flags & (1 << 9))
        total += commandId.encodedSize();
    if (flags & (1 << 10))
        total += 1;//classCode
    if (flags & (1 << 11))
        total += 1;//commandCode
    if (flags & (1 << 12))
        total += 1;//fieldIndex
    if (flags & (1 << 13))
        total += 2 + description.size();
    if (flags & (1 << 14))
        total += errorInfo.encodedSize();
    return total;
}

uint32_t ExecutionExceptionBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ExecutionExceptionBody::print(std::ostream& out) const
{
    out << "{ExecutionExceptionBody: ";
    if (flags & (1 << 8))
        out << "error-code=" << errorCode << "; ";
    if (flags & (1 << 9))
        out << "command-id=" << commandId << "; ";
    if (flags & (1 << 10))
        out << "class-code=" << (int) classCode << "; ";
    if (flags & (1 << 11))
        out << "command-code=" << (int) commandCode << "; ";
    if (flags & (1 << 12))
        out << "field-index=" << (int) fieldIndex << "; ";
    if (flags & (1 << 13))
        out << "description=" << description << "; ";
    if (flags & (1 << 14))
        out << "error-info=" << errorInfo << "; ";
    out << "}";
}
