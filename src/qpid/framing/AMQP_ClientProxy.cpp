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


#include <sstream>
#include "qpid/framing/AMQP_ClientProxy.h"
#include "qpid/framing/amqp_types_full.h"
#include "qpid/framing/ConnectionStartBody.h"
#include "qpid/framing/ConnectionSecureBody.h"
#include "qpid/framing/ConnectionTuneBody.h"
#include "qpid/framing/ConnectionOpenOkBody.h"
#include "qpid/framing/ConnectionRedirectBody.h"
#include "qpid/framing/ConnectionHeartbeatBody.h"
#include "qpid/framing/ConnectionCloseBody.h"
#include "qpid/framing/ConnectionCloseOkBody.h"
#include "qpid/framing/SessionAttachBody.h"
#include "qpid/framing/SessionAttachedBody.h"
#include "qpid/framing/SessionDetachBody.h"
#include "qpid/framing/SessionDetachedBody.h"
#include "qpid/framing/SessionRequestTimeoutBody.h"
#include "qpid/framing/SessionTimeoutBody.h"
#include "qpid/framing/SessionCommandPointBody.h"
#include "qpid/framing/SessionExpectedBody.h"
#include "qpid/framing/SessionConfirmedBody.h"
#include "qpid/framing/SessionCompletedBody.h"
#include "qpid/framing/SessionKnownCompletedBody.h"
#include "qpid/framing/SessionFlushBody.h"
#include "qpid/framing/SessionGapBody.h"
#include "qpid/framing/ExecutionSyncBody.h"
#include "qpid/framing/ExecutionResultBody.h"
#include "qpid/framing/ExecutionExceptionBody.h"
#include "qpid/framing/MessageTransferBody.h"
#include "qpid/framing/MessageAcceptBody.h"
#include "qpid/framing/MessageRejectBody.h"
#include "qpid/framing/MessageReleaseBody.h"
#include "qpid/framing/MessageResumeBody.h"
#include "qpid/framing/MessageSetFlowModeBody.h"
#include "qpid/framing/MessageFlowBody.h"
#include "qpid/framing/MessageStopBody.h"
#include "qpid/framing/FileQosOkBody.h"
#include "qpid/framing/FileConsumeOkBody.h"
#include "qpid/framing/FileOpenBody.h"
#include "qpid/framing/FileOpenOkBody.h"
#include "qpid/framing/FileStageBody.h"
#include "qpid/framing/FileReturnBody.h"
#include "qpid/framing/FileDeliverBody.h"
#include "qpid/framing/StreamQosOkBody.h"
#include "qpid/framing/StreamConsumeOkBody.h"
#include "qpid/framing/StreamReturnBody.h"
#include "qpid/framing/StreamDeliverBody.h"


namespace qpid {
namespace framing {

AMQP_ClientProxy::AMQP_ClientProxy(FrameHandler& f) :
   Proxy(f),
    connectionProxy(f),
    sessionProxy(f),
    executionProxy(f),
    messageProxy(f),
    txProxy(f),
    dtxProxy(f),
    exchangeProxy(f),
    queueProxy(f),
    fileProxy(f),
    streamProxy(f),
    clusterProxy(f),
    clusterConnectionProxy(f){}

void AMQP_ClientProxy::Connection::start(const FieldTable& serverProperties, const Array& mechanisms, const Array& locales)
{
    send(ConnectionStartBody(getVersion(), serverProperties, mechanisms, locales));
}
void AMQP_ClientProxy::Connection::secure(const std::string& challenge)
{
    send(ConnectionSecureBody(getVersion(), challenge));
}
void AMQP_ClientProxy::Connection::tune(uint16_t channelMax, uint16_t maxFrameSize, uint16_t heartbeatMin, uint16_t heartbeatMax)
{
    send(ConnectionTuneBody(getVersion(), channelMax, maxFrameSize, heartbeatMin, heartbeatMax));
}
void AMQP_ClientProxy::Connection::openOk(const Array& knownHosts)
{
    send(ConnectionOpenOkBody(getVersion(), knownHosts));
}
void AMQP_ClientProxy::Connection::redirect(const std::string& host, const Array& knownHosts)
{
    send(ConnectionRedirectBody(getVersion(), host, knownHosts));
}
void AMQP_ClientProxy::Connection::heartbeat()
{
    send(ConnectionHeartbeatBody(getVersion()));
}
void AMQP_ClientProxy::Connection::close(uint16_t replyCode, const std::string& replyText)
{
    send(ConnectionCloseBody(getVersion(), replyCode, replyText));
}
void AMQP_ClientProxy::Connection::closeOk()
{
    send(ConnectionCloseOkBody(getVersion()));
}
void AMQP_ClientProxy::Session::attach(const std::string& name, bool force)
{
    send(SessionAttachBody(getVersion(), name, force));
}
void AMQP_ClientProxy::Session::attached(const std::string& name)
{
    send(SessionAttachedBody(getVersion(), name));
}
void AMQP_ClientProxy::Session::detach(const std::string& name)
{
    send(SessionDetachBody(getVersion(), name));
}
void AMQP_ClientProxy::Session::detached(const std::string& name, uint8_t code)
{
    send(SessionDetachedBody(getVersion(), name, code));
}
void AMQP_ClientProxy::Session::requestTimeout(uint32_t timeout)
{
    send(SessionRequestTimeoutBody(getVersion(), timeout));
}
void AMQP_ClientProxy::Session::timeout(uint32_t timeout)
{
    send(SessionTimeoutBody(getVersion(), timeout));
}
void AMQP_ClientProxy::Session::commandPoint(const SequenceNumber& commandId, uint64_t commandOffset)
{
    send(SessionCommandPointBody(getVersion(), commandId, commandOffset));
}
void AMQP_ClientProxy::Session::expected(const SequenceSet& commands, const Array& fragments)
{
    send(SessionExpectedBody(getVersion(), commands, fragments));
}
void AMQP_ClientProxy::Session::confirmed(const SequenceSet& commands, const Array& fragments)
{
    send(SessionConfirmedBody(getVersion(), commands, fragments));
}
void AMQP_ClientProxy::Session::completed(const SequenceSet& commands, bool timelyReply)
{
    send(SessionCompletedBody(getVersion(), commands, timelyReply));
}
void AMQP_ClientProxy::Session::knownCompleted(const SequenceSet& commands)
{
    send(SessionKnownCompletedBody(getVersion(), commands));
}
void AMQP_ClientProxy::Session::flush(bool expected, bool confirmed, bool completed)
{
    send(SessionFlushBody(getVersion(), expected, confirmed, completed));
}
void AMQP_ClientProxy::Session::gap(const SequenceSet& commands)
{
    send(SessionGapBody(getVersion(), commands));
}
void AMQP_ClientProxy::Execution::sync()
{
    send(ExecutionSyncBody(getVersion()));
}
void AMQP_ClientProxy::Execution::result(const SequenceNumber& commandId, const std::string& value)
{
    send(ExecutionResultBody(getVersion(), commandId, value));
}
void AMQP_ClientProxy::Execution::exception(uint16_t errorCode, const SequenceNumber& commandId, uint8_t classCode, uint8_t commandCode, uint8_t fieldIndex, const std::string& description, const FieldTable& errorInfo)
{
    send(ExecutionExceptionBody(getVersion(), errorCode, commandId, classCode, commandCode, fieldIndex, description, errorInfo));
}
void AMQP_ClientProxy::Message::transfer(const std::string& destination, uint8_t acceptMode, uint8_t acquireMode)
{
    send(MessageTransferBody(getVersion(), destination, acceptMode, acquireMode));
}
void AMQP_ClientProxy::Message::accept(const SequenceSet& transfers)
{
    send(MessageAcceptBody(getVersion(), transfers));
}
void AMQP_ClientProxy::Message::reject(const SequenceSet& transfers, uint16_t code, const std::string& text)
{
    send(MessageRejectBody(getVersion(), transfers, code, text));
}
void AMQP_ClientProxy::Message::release(const SequenceSet& transfers, bool setRedelivered)
{
    send(MessageReleaseBody(getVersion(), transfers, setRedelivered));
}
void AMQP_ClientProxy::Message::resume(const std::string& destination, const std::string& resumeId)
{
    send(MessageResumeBody(getVersion(), destination, resumeId));
}
void AMQP_ClientProxy::Message::setFlowMode(const std::string& destination, uint8_t flowMode)
{
    send(MessageSetFlowModeBody(getVersion(), destination, flowMode));
}
void AMQP_ClientProxy::Message::flow(const std::string& destination, uint8_t unit, uint32_t value)
{
    send(MessageFlowBody(getVersion(), destination, unit, value));
}
void AMQP_ClientProxy::Message::stop(const std::string& destination)
{
    send(MessageStopBody(getVersion(), destination));
}
void AMQP_ClientProxy::File::qosOk()
{
    send(FileQosOkBody(getVersion()));
}
void AMQP_ClientProxy::File::consumeOk(const std::string& consumerTag)
{
    send(FileConsumeOkBody(getVersion(), consumerTag));
}
void AMQP_ClientProxy::File::open(const std::string& identifier, uint64_t contentSize)
{
    send(FileOpenBody(getVersion(), identifier, contentSize));
}
void AMQP_ClientProxy::File::openOk(uint64_t stagedSize)
{
    send(FileOpenOkBody(getVersion(), stagedSize));
}
void AMQP_ClientProxy::File::stage()
{
    send(FileStageBody(getVersion()));
}
void AMQP_ClientProxy::File::return_(uint16_t replyCode, const std::string& replyText, const std::string& exchange, const std::string& routingKey)
{
    send(FileReturnBody(getVersion(), replyCode, replyText, exchange, routingKey));
}
void AMQP_ClientProxy::File::deliver(const std::string& consumerTag, uint64_t deliveryTag, bool redelivered, const std::string& exchange, const std::string& routingKey, const std::string& identifier)
{
    send(FileDeliverBody(getVersion(), consumerTag, deliveryTag, redelivered, exchange, routingKey, identifier));
}
void AMQP_ClientProxy::Stream::qosOk()
{
    send(StreamQosOkBody(getVersion()));
}
void AMQP_ClientProxy::Stream::consumeOk(const std::string& consumerTag)
{
    send(StreamConsumeOkBody(getVersion(), consumerTag));
}
void AMQP_ClientProxy::Stream::return_(uint16_t replyCode, const std::string& replyText, const std::string& exchange, const std::string& routingKey)
{
    send(StreamReturnBody(getVersion(), replyCode, replyText, exchange, routingKey));
}
void AMQP_ClientProxy::Stream::deliver(const std::string& consumerTag, uint64_t deliveryTag, const std::string& exchange, const std::string& queue)
{
    send(StreamDeliverBody(getVersion(), consumerTag, deliveryTag, exchange, queue));
}

}} // namespace qpid::framing

