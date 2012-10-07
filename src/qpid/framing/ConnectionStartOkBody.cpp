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


#include "qpid/framing/ConnectionStartOkBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionStartOkBody::setClientProperties(const FieldTable& _clientProperties) {
    clientProperties = _clientProperties;
    flags |= (1 << 8);
}
const FieldTable& ConnectionStartOkBody::getClientProperties() const { return clientProperties; }
FieldTable& ConnectionStartOkBody::getClientProperties() {
    flags |= (1 << 8);
    return clientProperties;
}
bool ConnectionStartOkBody::hasClientProperties() const { return flags & (1 << 8); }
void ConnectionStartOkBody::clearClientPropertiesFlag() { flags &= ~(1 << 8); }

void ConnectionStartOkBody::setMechanism(const std::string& _mechanism) {
    mechanism = _mechanism;
    flags |= (1 << 9);
    if (mechanism.size() >= 256) throw IllegalArgumentException("Value for mechanism is too large");
}
const std::string& ConnectionStartOkBody::getMechanism() const { return mechanism; }
bool ConnectionStartOkBody::hasMechanism() const { return flags & (1 << 9); }
void ConnectionStartOkBody::clearMechanismFlag() { flags &= ~(1 << 9); }

void ConnectionStartOkBody::setResponse(const std::string& _response) {
    response = _response;
    flags |= (1 << 10);
}
const std::string& ConnectionStartOkBody::getResponse() const { return response; }
bool ConnectionStartOkBody::hasResponse() const { return flags & (1 << 10); }
void ConnectionStartOkBody::clearResponseFlag() { flags &= ~(1 << 10); }

void ConnectionStartOkBody::setLocale(const std::string& _locale) {
    locale = _locale;
    flags |= (1 << 11);
    if (locale.size() >= 256) throw IllegalArgumentException("Value for locale is too large");
}
const std::string& ConnectionStartOkBody::getLocale() const { return locale; }
bool ConnectionStartOkBody::hasLocale() const { return flags & (1 << 11); }
void ConnectionStartOkBody::clearLocaleFlag() { flags &= ~(1 << 11); }

void ConnectionStartOkBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        clientProperties.encode(buffer);
    if (flags & (1 << 9))
        buffer.putShortString(mechanism);
    if (flags & (1 << 10))
        buffer.putLongString(response);
    if (flags & (1 << 11))
        buffer.putShortString(locale);
}

void ConnectionStartOkBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionStartOkBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        clientProperties.decode(buffer);
    if (flags & (1 << 9))
        buffer.getShortString(mechanism);
    if (flags & (1 << 10))
        buffer.getLongString(response);
    if (flags & (1 << 11))
        buffer.getShortString(locale);
}

void ConnectionStartOkBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionStartOkBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += clientProperties.encodedSize();
    if (flags & (1 << 9))
        total += 1 + mechanism.size();
    if (flags & (1 << 10))
        total += 4 + response.size();
    if (flags & (1 << 11))
        total += 1 + locale.size();
    return total;
}

uint32_t ConnectionStartOkBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionStartOkBody::print(std::ostream& out) const
{
    out << "{ConnectionStartOkBody: ";
    if (flags & (1 << 8))
        out << "client-properties=" << clientProperties << "; ";
    if (flags & (1 << 9))
        out << "mechanism=" << mechanism << "; ";
    if (flags & (1 << 10))
        out << "response=" << "xxxxxx" << "; ";
    if (flags & (1 << 11))
        out << "locale=" << locale << "; ";
    out << "}";
}
