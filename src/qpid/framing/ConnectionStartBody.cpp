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


#include "qpid/framing/ConnectionStartBody.h"
#include "qpid/framing/Buffer.h"

using namespace qpid::framing;

void ConnectionStartBody::setServerProperties(const FieldTable& _serverProperties) {
    serverProperties = _serverProperties;
    flags |= (1 << 8);
}
const FieldTable& ConnectionStartBody::getServerProperties() const { return serverProperties; }
FieldTable& ConnectionStartBody::getServerProperties() {
    flags |= (1 << 8);
    return serverProperties;
}
bool ConnectionStartBody::hasServerProperties() const { return flags & (1 << 8); }
void ConnectionStartBody::clearServerPropertiesFlag() { flags &= ~(1 << 8); }

void ConnectionStartBody::setMechanisms(const Array& _mechanisms) {
    mechanisms = _mechanisms;
    flags |= (1 << 9);
}
const Array& ConnectionStartBody::getMechanisms() const { return mechanisms; }
bool ConnectionStartBody::hasMechanisms() const { return flags & (1 << 9); }
void ConnectionStartBody::clearMechanismsFlag() { flags &= ~(1 << 9); }

void ConnectionStartBody::setLocales(const Array& _locales) {
    locales = _locales;
    flags |= (1 << 10);
}
const Array& ConnectionStartBody::getLocales() const { return locales; }
bool ConnectionStartBody::hasLocales() const { return flags & (1 << 10); }
void ConnectionStartBody::clearLocalesFlag() { flags &= ~(1 << 10); }

void ConnectionStartBody::encodeStructBody(Buffer& buffer) const
{
    buffer.putShort(flags);
    if (flags & (1 << 8))
        serverProperties.encode(buffer);
    if (flags & (1 << 9))
        mechanisms.encode(buffer);
    if (flags & (1 << 10))
        locales.encode(buffer);
}

void ConnectionStartBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ConnectionStartBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
    flags = buffer.getShort();
    if (flags & (1 << 8))
        serverProperties.decode(buffer);
    if (flags & (1 << 9))
        mechanisms.decode(buffer);
    if (flags & (1 << 10))
        locales.decode(buffer);
}

void ConnectionStartBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ConnectionStartBody::bodySize() const
{
    uint32_t total = 0;
    total += 2;
    if (flags & (1 << 8))
        total += serverProperties.encodedSize();
    if (flags & (1 << 9))
        total += mechanisms.encodedSize();
    if (flags & (1 << 10))
        total += locales.encodedSize();
    return total;
}

uint32_t ConnectionStartBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ConnectionStartBody::print(std::ostream& out) const
{
    out << "{ConnectionStartBody: ";
    if (flags & (1 << 8))
        out << "server-properties=" << serverProperties << "; ";
    if (flags & (1 << 9))
        out << "mechanisms=" << mechanisms << "; ";
    if (flags & (1 << 10))
        out << "locales=" << locales << "; ";
    out << "}";
}
