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
#include "qpid/framing/AMQP_ServerProxy.h"
#include "qpid/framing/amqp_types_full.h"
#include "qpid/framing/ConnectionStartOkBody.h"
#include "qpid/framing/ConnectionSecureOkBody.h"
#include "qpid/framing/ConnectionTuneOkBody.h"
#include "qpid/framing/ConnectionOpenBody.h"
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
#include "qpid/framing/MessageAcquireBody.h"
#include "qpid/framing/MessageResumeBody.h"
#include "qpid/framing/MessageSubscribeBody.h"
#include "qpid/framing/MessageCancelBody.h"
#include "qpid/framing/MessageSetFlowModeBody.h"
#include "qpid/framing/MessageFlowBody.h"
#include "qpid/framing/MessageFlushBody.h"
#include "qpid/framing/MessageStopBody.h"
#include "qpid/framing/TxSelectBody.h"
#include "qpid/framing/TxCommitBody.h"
#include "qpid/framing/TxRollbackBody.h"
#include "qpid/framing/DtxSelectBody.h"
#include "qpid/framing/DtxStartBody.h"
#include "qpid/framing/DtxEndBody.h"
#include "qpid/framing/DtxCommitBody.h"
#include "qpid/framing/DtxForgetBody.h"
#include "qpid/framing/DtxGetTimeoutBody.h"
#include "qpid/framing/DtxPrepareBody.h"
#include "qpid/framing/DtxRecoverBody.h"
#include "qpid/framing/DtxRollbackBody.h"
#include "qpid/framing/DtxSetTimeoutBody.h"
#include "qpid/framing/ExchangeDeclareBody.h"
#include "qpid/framing/ExchangeDeleteBody.h"
#include "qpid/framing/ExchangeQueryBody.h"
#include "qpid/framing/ExchangeBindBody.h"
#include "qpid/framing/ExchangeUnbindBody.h"
#include "qpid/framing/ExchangeBoundBody.h"
#include "qpid/framing/QueueDeclareBody.h"
#include "qpid/framing/QueueDeleteBody.h"
#include "qpid/framing/QueuePurgeBody.h"
#include "qpid/framing/QueueQueryBody.h"
#include "qpid/framing/FileQosBody.h"
#include "qpid/framing/FileConsumeBody.h"
#include "qpid/framing/FileCancelBody.h"
#include "qpid/framing/FileOpenBody.h"
#include "qpid/framing/FileOpenOkBody.h"
#include "qpid/framing/FileStageBody.h"
#include "qpid/framing/FilePublishBody.h"
#include "qpid/framing/FileAckBody.h"
#include "qpid/framing/FileRejectBody.h"
#include "qpid/framing/StreamQosBody.h"
#include "qpid/framing/StreamConsumeBody.h"
#include "qpid/framing/StreamCancelBody.h"
#include "qpid/framing/StreamPublishBody.h"


namespace qpid {
namespace framing {

AMQP_ServerProxy::AMQP_ServerProxy(FrameHandler& f) :
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

void AMQP_ServerProxy::Connection::startOk(const FieldTable& clientProperties, const std::string& mechanism, const std::string& response, const std::string& locale)
{
    send(ConnectionStartOkBody(getVersion(), clientProperties, mechanism, response, locale));
}
void AMQP_ServerProxy::Connection::secureOk(const std::string& response)
{
    send(ConnectionSecureOkBody(getVersion(), response));
}
void AMQP_ServerProxy::Connection::tuneOk(uint16_t channelMax, uint16_t maxFrameSize, uint16_t heartbeat)
{
    send(ConnectionTuneOkBody(getVersion(), channelMax, maxFrameSize, heartbeat));
}
void AMQP_ServerProxy::Connection::open(const std::string& virtualHost, const Array& capabilities, bool insist)
{
    send(ConnectionOpenBody(getVersion(), virtualHost, capabilities, insist));
}
void AMQP_ServerProxy::Connection::heartbeat()
{
    send(ConnectionHeartbeatBody(getVersion()));
}
void AMQP_ServerProxy::Connection::close(uint16_t replyCode, const std::string& replyText)
{
    send(ConnectionCloseBody(getVersion(), replyCode, replyText));
}
void AMQP_ServerProxy::Connection::closeOk()
{
    send(ConnectionCloseOkBody(getVersion()));
}
void AMQP_ServerProxy::Session::attach(const std::string& name, bool force)
{
    send(SessionAttachBody(getVersion(), name, force));
}
void AMQP_ServerProxy::Session::attached(const std::string& name)
{
    send(SessionAttachedBody(getVersion(), name));
}
void AMQP_ServerProxy::Session::detach(const std::string& name)
{
    send(SessionDetachBody(getVersion(), name));
}
void AMQP_ServerProxy::Session::detached(const std::string& name, uint8_t code)
{
    send(SessionDetachedBody(getVersion(), name, code));
}
void AMQP_ServerProxy::Session::requestTimeout(uint32_t timeout)
{
    send(SessionRequestTimeoutBody(getVersion(), timeout));
}
void AMQP_ServerProxy::Session::timeout(uint32_t timeout)
{
    send(SessionTimeoutBody(getVersion(), timeout));
}
void AMQP_ServerProxy::Session::commandPoint(const SequenceNumber& commandId, uint64_t commandOffset)
{
    send(SessionCommandPointBody(getVersion(), commandId, commandOffset));
}
void AMQP_ServerProxy::Session::expected(const SequenceSet& commands, const Array& fragments)
{
    send(SessionExpectedBody(getVersion(), commands, fragments));
}
void AMQP_ServerProxy::Session::confirmed(const SequenceSet& commands, const Array& fragments)
{
    send(SessionConfirmedBody(getVersion(), commands, fragments));
}
void AMQP_ServerProxy::Session::completed(const SequenceSet& commands, bool timelyReply)
{
    send(SessionCompletedBody(getVersion(), commands, timelyReply));
}
void AMQP_ServerProxy::Session::knownCompleted(const SequenceSet& commands)
{
    send(SessionKnownCompletedBody(getVersion(), commands));
}
void AMQP_ServerProxy::Session::flush(bool expected, bool confirmed, bool completed)
{
    send(SessionFlushBody(getVersion(), expected, confirmed, completed));
}
void AMQP_ServerProxy::Session::gap(const SequenceSet& commands)
{
    send(SessionGapBody(getVersion(), commands));
}
void AMQP_ServerProxy::Execution::sync()
{
    send(ExecutionSyncBody(getVersion()));
}
void AMQP_ServerProxy::Execution::result(const SequenceNumber& commandId, const std::string& value)
{
    send(ExecutionResultBody(getVersion(), commandId, value));
}
void AMQP_ServerProxy::Execution::exception(uint16_t errorCode, const SequenceNumber& commandId, uint8_t classCode, uint8_t commandCode, uint8_t fieldIndex, const std::string& description, const FieldTable& errorInfo)
{
    send(ExecutionExceptionBody(getVersion(), errorCode, commandId, classCode, commandCode, fieldIndex, description, errorInfo));
}
void AMQP_ServerProxy::Message::transfer(const std::string& destination, uint8_t acceptMode, uint8_t acquireMode)
{
    send(MessageTransferBody(getVersion(), destination, acceptMode, acquireMode));
}
void AMQP_ServerProxy::Message::accept(const SequenceSet& transfers)
{
    send(MessageAcceptBody(getVersion(), transfers));
}
void AMQP_ServerProxy::Message::reject(const SequenceSet& transfers, uint16_t code, const std::string& text)
{
    send(MessageRejectBody(getVersion(), transfers, code, text));
}
void AMQP_ServerProxy::Message::release(const SequenceSet& transfers, bool setRedelivered)
{
    send(MessageReleaseBody(getVersion(), transfers, setRedelivered));
}
void AMQP_ServerProxy::Message::acquire(const SequenceSet& transfers)
{
    send(MessageAcquireBody(getVersion(), transfers));
}
void AMQP_ServerProxy::Message::resume(const std::string& destination, const std::string& resumeId)
{
    send(MessageResumeBody(getVersion(), destination, resumeId));
}
void AMQP_ServerProxy::Message::subscribe(const std::string& queue, const std::string& destination, uint8_t acceptMode, uint8_t acquireMode, bool exclusive, const std::string& resumeId, uint64_t resumeTtl, const FieldTable& arguments)
{
    send(MessageSubscribeBody(getVersion(), queue, destination, acceptMode, acquireMode, exclusive, resumeId, resumeTtl, arguments));
}
void AMQP_ServerProxy::Message::cancel(const std::string& destination)
{
    send(MessageCancelBody(getVersion(), destination));
}
void AMQP_ServerProxy::Message::setFlowMode(const std::string& destination, uint8_t flowMode)
{
    send(MessageSetFlowModeBody(getVersion(), destination, flowMode));
}
void AMQP_ServerProxy::Message::flow(const std::string& destination, uint8_t unit, uint32_t value)
{
    send(MessageFlowBody(getVersion(), destination, unit, value));
}
void AMQP_ServerProxy::Message::flush(const std::string& destination)
{
    send(MessageFlushBody(getVersion(), destination));
}
void AMQP_ServerProxy::Message::stop(const std::string& destination)
{
    send(MessageStopBody(getVersion(), destination));
}
void AMQP_ServerProxy::Tx::select()
{
    send(TxSelectBody(getVersion()));
}
void AMQP_ServerProxy::Tx::commit()
{
    send(TxCommitBody(getVersion()));
}
void AMQP_ServerProxy::Tx::rollback()
{
    send(TxRollbackBody(getVersion()));
}
void AMQP_ServerProxy::Dtx::select()
{
    send(DtxSelectBody(getVersion()));
}
void AMQP_ServerProxy::Dtx::start(const Xid& xid, bool join, bool resume)
{
    send(DtxStartBody(getVersion(), xid, join, resume));
}
void AMQP_ServerProxy::Dtx::end(const Xid& xid, bool fail, bool suspend)
{
    send(DtxEndBody(getVersion(), xid, fail, suspend));
}
void AMQP_ServerProxy::Dtx::commit(const Xid& xid, bool onePhase)
{
    send(DtxCommitBody(getVersion(), xid, onePhase));
}
void AMQP_ServerProxy::Dtx::forget(const Xid& xid)
{
    send(DtxForgetBody(getVersion(), xid));
}
void AMQP_ServerProxy::Dtx::getTimeout(const Xid& xid)
{
    send(DtxGetTimeoutBody(getVersion(), xid));
}
void AMQP_ServerProxy::Dtx::prepare(const Xid& xid)
{
    send(DtxPrepareBody(getVersion(), xid));
}
void AMQP_ServerProxy::Dtx::recover()
{
    send(DtxRecoverBody(getVersion()));
}
void AMQP_ServerProxy::Dtx::rollback(const Xid& xid)
{
    send(DtxRollbackBody(getVersion(), xid));
}
void AMQP_ServerProxy::Dtx::setTimeout(const Xid& xid, uint32_t timeout)
{
    send(DtxSetTimeoutBody(getVersion(), xid, timeout));
}
void AMQP_ServerProxy::Exchange::declare(const std::string& exchange, const std::string& type, const std::string& alternateExchange, bool passive, bool durable, bool autoDelete, const FieldTable& arguments)
{
    send(ExchangeDeclareBody(getVersion(), exchange, type, alternateExchange, passive, durable, autoDelete, arguments));
}
void AMQP_ServerProxy::Exchange::delete_(const std::string& exchange, bool ifUnused)
{
    send(ExchangeDeleteBody(getVersion(), exchange, ifUnused));
}
void AMQP_ServerProxy::Exchange::query(const std::string& name)
{
    send(ExchangeQueryBody(getVersion(), name));
}
void AMQP_ServerProxy::Exchange::bind(const std::string& queue, const std::string& exchange, const std::string& bindingKey, const FieldTable& arguments)
{
    send(ExchangeBindBody(getVersion(), queue, exchange, bindingKey, arguments));
}
void AMQP_ServerProxy::Exchange::unbind(const std::string& queue, const std::string& exchange, const std::string& bindingKey)
{
    send(ExchangeUnbindBody(getVersion(), queue, exchange, bindingKey));
}
void AMQP_ServerProxy::Exchange::bound(const std::string& exchange, const std::string& queue, const std::string& bindingKey, const FieldTable& arguments)
{
    send(ExchangeBoundBody(getVersion(), exchange, queue, bindingKey, arguments));
}
void AMQP_ServerProxy::Queue::declare(const std::string& queue, const std::string& alternateExchange, bool passive, bool durable, bool exclusive, bool autoDelete, const FieldTable& arguments)
{
    send(QueueDeclareBody(getVersion(), queue, alternateExchange, passive, durable, exclusive, autoDelete, arguments));
}
void AMQP_ServerProxy::Queue::delete_(const std::string& queue, bool ifUnused, bool ifEmpty)
{
    send(QueueDeleteBody(getVersion(), queue, ifUnused, ifEmpty));
}
void AMQP_ServerProxy::Queue::purge(const std::string& queue)
{
    send(QueuePurgeBody(getVersion(), queue));
}
void AMQP_ServerProxy::Queue::query(const std::string& queue)
{
    send(QueueQueryBody(getVersion(), queue));
}
void AMQP_ServerProxy::File::qos(uint32_t prefetchSize, uint16_t prefetchCount, bool global)
{
    send(FileQosBody(getVersion(), prefetchSize, prefetchCount, global));
}
void AMQP_ServerProxy::File::consume(const std::string& queue, const std::string& consumerTag, bool noLocal, bool noAck, bool exclusive, bool nowait, const FieldTable& arguments)
{
    send(FileConsumeBody(getVersion(), queue, consumerTag, noLocal, noAck, exclusive, nowait, arguments));
}
void AMQP_ServerProxy::File::cancel(const std::string& consumerTag)
{
    send(FileCancelBody(getVersion(), consumerTag));
}
void AMQP_ServerProxy::File::open(const std::string& identifier, uint64_t contentSize)
{
    send(FileOpenBody(getVersion(), identifier, contentSize));
}
void AMQP_ServerProxy::File::openOk(uint64_t stagedSize)
{
    send(FileOpenOkBody(getVersion(), stagedSize));
}
void AMQP_ServerProxy::File::stage()
{
    send(FileStageBody(getVersion()));
}
void AMQP_ServerProxy::File::publish(const std::string& exchange, const std::string& routingKey, bool mandatory, bool immediate, const std::string& identifier)
{
    send(FilePublishBody(getVersion(), exchange, routingKey, mandatory, immediate, identifier));
}
void AMQP_ServerProxy::File::ack(uint64_t deliveryTag, bool multiple)
{
    send(FileAckBody(getVersion(), deliveryTag, multiple));
}
void AMQP_ServerProxy::File::reject(uint64_t deliveryTag, bool requeue)
{
    send(FileRejectBody(getVersion(), deliveryTag, requeue));
}
void AMQP_ServerProxy::Stream::qos(uint32_t prefetchSize, uint16_t prefetchCount, uint32_t consumeRate, bool global)
{
    send(StreamQosBody(getVersion(), prefetchSize, prefetchCount, consumeRate, global));
}
void AMQP_ServerProxy::Stream::consume(const std::string& queue, const std::string& consumerTag, bool noLocal, bool exclusive, bool nowait, const FieldTable& arguments)
{
    send(StreamConsumeBody(getVersion(), queue, consumerTag, noLocal, exclusive, nowait, arguments));
}
void AMQP_ServerProxy::Stream::cancel(const std::string& consumerTag)
{
    send(StreamCancelBody(getVersion(), consumerTag));
}
void AMQP_ServerProxy::Stream::publish(const std::string& exchange, const std::string& routingKey, bool mandatory, bool immediate)
{
    send(StreamPublishBody(getVersion(), exchange, routingKey, mandatory, immediate));
}

}} // namespace qpid::framing

