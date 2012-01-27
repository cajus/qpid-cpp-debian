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


#include "qpid/framing/ClusterConnectionSessionStateBody.h"
#include "qpid/framing/reply_exceptions.h"

using namespace qpid::framing;

void ClusterConnectionSessionStateBody::setReplayStart(const SequenceNumber& _replayStart) {
    replayStart = _replayStart;
    flags |= (1 << 8);
}
SequenceNumber ClusterConnectionSessionStateBody::getReplayStart() const { return replayStart; }
bool ClusterConnectionSessionStateBody::hasReplayStart() const { return flags & (1 << 8); }
void ClusterConnectionSessionStateBody::clearReplayStartFlag() { flags &= ~(1 << 8); }

void ClusterConnectionSessionStateBody::setCommandPoint(const SequenceNumber& _commandPoint) {
    commandPoint = _commandPoint;
    flags |= (1 << 9);
}
SequenceNumber ClusterConnectionSessionStateBody::getCommandPoint() const { return commandPoint; }
bool ClusterConnectionSessionStateBody::hasCommandPoint() const { return flags & (1 << 9); }
void ClusterConnectionSessionStateBody::clearCommandPointFlag() { flags &= ~(1 << 9); }

void ClusterConnectionSessionStateBody::setSentIncomplete(const SequenceSet& _sentIncomplete) {
    sentIncomplete = _sentIncomplete;
    flags |= (1 << 10);
}
const SequenceSet& ClusterConnectionSessionStateBody::getSentIncomplete() const { return sentIncomplete; }
bool ClusterConnectionSessionStateBody::hasSentIncomplete() const { return flags & (1 << 10); }
void ClusterConnectionSessionStateBody::clearSentIncompleteFlag() { flags &= ~(1 << 10); }

void ClusterConnectionSessionStateBody::setExpected(const SequenceNumber& _expected) {
    expected = _expected;
    flags |= (1 << 11);
}
SequenceNumber ClusterConnectionSessionStateBody::getExpected() const { return expected; }
bool ClusterConnectionSessionStateBody::hasExpected() const { return flags & (1 << 11); }
void ClusterConnectionSessionStateBody::clearExpectedFlag() { flags &= ~(1 << 11); }

void ClusterConnectionSessionStateBody::setReceived(const SequenceNumber& _received) {
    received = _received;
    flags |= (1 << 12);
}
SequenceNumber ClusterConnectionSessionStateBody::getReceived() const { return received; }
bool ClusterConnectionSessionStateBody::hasReceived() const { return flags & (1 << 12); }
void ClusterConnectionSessionStateBody::clearReceivedFlag() { flags &= ~(1 << 12); }

void ClusterConnectionSessionStateBody::setUnknownCompleted(const SequenceSet& _unknownCompleted) {
    unknownCompleted = _unknownCompleted;
    flags |= (1 << 13);
}
const SequenceSet& ClusterConnectionSessionStateBody::getUnknownCompleted() const { return unknownCompleted; }
bool ClusterConnectionSessionStateBody::hasUnknownCompleted() const { return flags & (1 << 13); }
void ClusterConnectionSessionStateBody::clearUnknownCompletedFlag() { flags &= ~(1 << 13); }

void ClusterConnectionSessionStateBody::setReceivedIncomplete(const SequenceSet& _receivedIncomplete) {
    receivedIncomplete = _receivedIncomplete;
    flags |= (1 << 14);
}
const SequenceSet& ClusterConnectionSessionStateBody::getReceivedIncomplete() const { return receivedIncomplete; }
bool ClusterConnectionSessionStateBody::hasReceivedIncomplete() const { return flags & (1 << 14); }
void ClusterConnectionSessionStateBody::clearReceivedIncompleteFlag() { flags &= ~(1 << 14); }

void ClusterConnectionSessionStateBody::setDtxSelected(bool _dtxSelected) {
    if (_dtxSelected) flags |= (1 << 15);
    else flags &= ~(1 << 15);
}
bool ClusterConnectionSessionStateBody::getDtxSelected() const { return flags & (1 << 15); }

void ClusterConnectionSessionStateBody::encodeStructBody(Buffer& buffer) const
{
encodeHeader(buffer);
    buffer.putShort(flags);
    if (flags & (1 << 8))
        replayStart.encode(buffer);
    if (flags & (1 << 9))
        commandPoint.encode(buffer);
    if (flags & (1 << 10))
        sentIncomplete.encode(buffer);
    if (flags & (1 << 11))
        expected.encode(buffer);
    if (flags & (1 << 12))
        received.encode(buffer);
    if (flags & (1 << 13))
        unknownCompleted.encode(buffer);
    if (flags & (1 << 14))
        receivedIncomplete.encode(buffer);
}

void ClusterConnectionSessionStateBody::encode(Buffer& buffer) const
{
    encodeStructBody(buffer);
}

void ClusterConnectionSessionStateBody::decodeStructBody(Buffer& buffer, uint32_t /*size*/)
{
decodeHeader(buffer);
    flags = buffer.getShort();
    if (flags & (1 << 8))
        replayStart.decode(buffer);
    if (flags & (1 << 9))
        commandPoint.decode(buffer);
    if (flags & (1 << 10))
        sentIncomplete.decode(buffer);
    if (flags & (1 << 11))
        expected.decode(buffer);
    if (flags & (1 << 12))
        received.decode(buffer);
    if (flags & (1 << 13))
        unknownCompleted.decode(buffer);
    if (flags & (1 << 14))
        receivedIncomplete.decode(buffer);
}

void ClusterConnectionSessionStateBody::decode(Buffer& buffer, uint32_t /*size*/)
{
    decodeStructBody(buffer);
}

uint32_t ClusterConnectionSessionStateBody::bodySize() const
{
    uint32_t total = 0;
total += headerSize();
    total += 2;
    if (flags & (1 << 8))
        total += replayStart.encodedSize();
    if (flags & (1 << 9))
        total += commandPoint.encodedSize();
    if (flags & (1 << 10))
        total += sentIncomplete.encodedSize();
    if (flags & (1 << 11))
        total += expected.encodedSize();
    if (flags & (1 << 12))
        total += received.encodedSize();
    if (flags & (1 << 13))
        total += unknownCompleted.encodedSize();
    if (flags & (1 << 14))
        total += receivedIncomplete.encodedSize();
    return total;
}

uint32_t ClusterConnectionSessionStateBody::encodedSize() const {
    uint32_t total = bodySize();
    return total;
}

void ClusterConnectionSessionStateBody::print(std::ostream& out) const
{
    out << "{ClusterConnectionSessionStateBody: ";
    if (flags & (1 << 8))
        out << "replay-start=" << replayStart << "; ";
    if (flags & (1 << 9))
        out << "command-point=" << commandPoint << "; ";
    if (flags & (1 << 10))
        out << "sent-incomplete=" << sentIncomplete << "; ";
    if (flags & (1 << 11))
        out << "expected=" << expected << "; ";
    if (flags & (1 << 12))
        out << "received=" << received << "; ";
    if (flags & (1 << 13))
        out << "unknown-completed=" << unknownCompleted << "; ";
    if (flags & (1 << 14))
        out << "received-incomplete=" << receivedIncomplete << "; ";
    if (flags & (1 << 15))
        out << "dtx-selected=" << getDtxSelected() << "; ";
    out << "}";
}
