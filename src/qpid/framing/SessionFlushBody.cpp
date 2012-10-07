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


#include "qpid/framing/SessionFlushBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void SessionFlushBody::setExpected(bool _expected) {
    if (_expected) flags |= (1 << 8);
    else flags &= ~(1 << 8);
}
bool SessionFlushBody::getExpected() const { return flags & (1 << 8); }

void SessionFlushBody::setConfirmed(bool _confirmed) {
    if (_confirmed) flags |= (1 << 9);
    else flags &= ~(1 << 9);
}
bool SessionFlushBody::getConfirmed() const { return flags & (1 << 9); }

void SessionFlushBody::setCompleted(bool _completed) {
    if (_completed) flags |= (1 << 10);
    else flags &= ~(1 << 10);
}
bool SessionFlushBody::getCompleted() const { return flags & (1 << 10); }

void SessionFlushBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
}

void SessionFlushBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void SessionFlushBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
}

void SessionFlushBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t SessionFlushBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    return total;
}

uint32_t SessionFlushBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void SessionFlushBody::print(std::ostream& out) const
{
    out << "{SessionFlushBody: ";
    if (flags & (1 << 8))
        out << "expected=" << getExpected() << "; ";
    if (flags & (1 << 9))
        out << "confirmed=" << getConfirmed() << "; ";
    if (flags & (1 << 10))
        out << "completed=" << getCompleted() << "; ";
    out << "}";
}
