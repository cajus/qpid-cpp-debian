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


#include "qpid/framing/ClusterConnectionManagementSetupStateBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionManagementSetupStateBody::setObjectNum(uint64_t _objectNum) {
    objectNum = _objectNum;
    flags |= (1 << 8);
}
uint64_t ClusterConnectionManagementSetupStateBody::getObjectNum() const { return objectNum; }
bool ClusterConnectionManagementSetupStateBody::hasObjectNum() const { return flags & (1 << 8); }
void ClusterConnectionManagementSetupStateBody::clearObjectNumFlag() { flags &= ~(1 << 8); }

void ClusterConnectionManagementSetupStateBody::setBootSequence(uint16_t _bootSequence) {
    bootSequence = _bootSequence;
    flags |= (1 << 9);
}
uint16_t ClusterConnectionManagementSetupStateBody::getBootSequence() const { return bootSequence; }
bool ClusterConnectionManagementSetupStateBody::hasBootSequence() const { return flags & (1 << 9); }
void ClusterConnectionManagementSetupStateBody::clearBootSequenceFlag() { flags &= ~(1 << 9); }

void ClusterConnectionManagementSetupStateBody::setBrokerId(const Uuid& _brokerId) {
    brokerId = _brokerId;
    flags |= (1 << 10);
}
const Uuid& ClusterConnectionManagementSetupStateBody::getBrokerId() const { return brokerId; }
bool ClusterConnectionManagementSetupStateBody::hasBrokerId() const { return flags & (1 << 10); }
void ClusterConnectionManagementSetupStateBody::clearBrokerIdFlag() { flags &= ~(1 << 10); }

void ClusterConnectionManagementSetupStateBody::setVendor(const std::string& _vendor) {
    vendor = _vendor;
    flags |= (1 << 11);
}
const std::string& ClusterConnectionManagementSetupStateBody::getVendor() const { return vendor; }
bool ClusterConnectionManagementSetupStateBody::hasVendor() const { return flags & (1 << 11); }
void ClusterConnectionManagementSetupStateBody::clearVendorFlag() { flags &= ~(1 << 11); }

void ClusterConnectionManagementSetupStateBody::setProduct(const std::string& _product) {
    product = _product;
    flags |= (1 << 12);
}
const std::string& ClusterConnectionManagementSetupStateBody::getProduct() const { return product; }
bool ClusterConnectionManagementSetupStateBody::hasProduct() const { return flags & (1 << 12); }
void ClusterConnectionManagementSetupStateBody::clearProductFlag() { flags &= ~(1 << 12); }

void ClusterConnectionManagementSetupStateBody::setInstance(const std::string& _instance) {
    instance = _instance;
    flags |= (1 << 13);
}
const std::string& ClusterConnectionManagementSetupStateBody::getInstance() const { return instance; }
bool ClusterConnectionManagementSetupStateBody::hasInstance() const { return flags & (1 << 13); }
void ClusterConnectionManagementSetupStateBody::clearInstanceFlag() { flags &= ~(1 << 13); }

void ClusterConnectionManagementSetupStateBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        buffer.putLongLong(objectNum);
    if (flags & (1 << 9))
        buffer.putShort(bootSequence);
    if (flags & (1 << 10))
        brokerId.encode(buffer);
    if (flags & (1 << 11))
        buffer.putLongString(vendor);
    if (flags & (1 << 12))
        buffer.putLongString(product);
    if (flags & (1 << 13))
        buffer.putLongString(instance);
}

void ClusterConnectionManagementSetupStateBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionManagementSetupStateBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        objectNum = buffer.getLongLong();
    if (flags & (1 << 9))
        bootSequence = buffer.getShort();
    if (flags & (1 << 10))
        brokerId.decode(buffer);
    if (flags & (1 << 11))
        buffer.getLongString(vendor);
    if (flags & (1 << 12))
        buffer.getLongString(product);
    if (flags & (1 << 13))
        buffer.getLongString(instance);
}

void ClusterConnectionManagementSetupStateBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionManagementSetupStateBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += 8;//objectNum
    if (flags & (1 << 9))
        total += 2;//bootSequence
    if (flags & (1 << 10))
        total += brokerId.encodedSize();
    if (flags & (1 << 11))
        total += 4 + vendor.size();
    if (flags & (1 << 12))
        total += 4 + product.size();
    if (flags & (1 << 13))
        total += 4 + instance.size();
    return total;
}

uint32_t ClusterConnectionManagementSetupStateBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionManagementSetupStateBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionManagementSetupStateBody: ";
    if (flags & (1 << 8))
        out << "objectNum=" << objectNum << "; ";
    if (flags & (1 << 9))
        out << "bootSequence=" << bootSequence << "; ";
    if (flags & (1 << 10))
        out << "broker-id=" << brokerId << "; ";
    if (flags & (1 << 11))
        out << "vendor=" << vendor << "; ";
    if (flags & (1 << 12))
        out << "product=" << product << "; ";
    if (flags & (1 << 13))
        out << "instance=" << instance << "; ";
    out << "}";
}
