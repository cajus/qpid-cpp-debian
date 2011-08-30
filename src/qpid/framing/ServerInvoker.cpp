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


#include "qpid/framing/ServerInvoker.h"
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
#include "qpid/framing/FilePublishBody.h"
#include "qpid/framing/FileAckBody.h"
#include "qpid/framing/FileRejectBody.h"
#include "qpid/framing/StreamQosBody.h"
#include "qpid/framing/StreamConsumeBody.h"
#include "qpid/framing/StreamCancelBody.h"

namespace qpid {
namespace framing {

void AMQP_ServerOperations::Invoker::visit(const ConnectionStartOkBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ConnectionSecureOkBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ConnectionTuneOkBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ConnectionOpenBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ConnectionHeartbeatBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ConnectionCloseBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ConnectionCloseOkBody& body) {
    AMQP_ServerOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionAttachBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionAttachedBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionDetachBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionDetachedBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionRequestTimeoutBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionTimeoutBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionCommandPointBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionExpectedBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionConfirmedBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionCompletedBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionKnownCompletedBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionFlushBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const SessionGapBody& body) {
    AMQP_ServerOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExecutionSyncBody& body) {
    AMQP_ServerOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExecutionResultBody& body) {
    AMQP_ServerOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExecutionExceptionBody& body) {
    AMQP_ServerOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageAcceptBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageRejectBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageReleaseBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageAcquireBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageResumeBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageSubscribeBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageCancelBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageSetFlowModeBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageFlowBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageFlushBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const MessageStopBody& body) {
    AMQP_ServerOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const TxSelectBody& body) {
    AMQP_ServerOperations::TxHandler::Invoker invoker(*target.getTxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const TxCommitBody& body) {
    AMQP_ServerOperations::TxHandler::Invoker invoker(*target.getTxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const TxRollbackBody& body) {
    AMQP_ServerOperations::TxHandler::Invoker invoker(*target.getTxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxSelectBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxStartBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxEndBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxCommitBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxForgetBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxGetTimeoutBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxPrepareBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxRecoverBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxRollbackBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const DtxSetTimeoutBody& body) {
    AMQP_ServerOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExchangeDeclareBody& body) {
    AMQP_ServerOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExchangeDeleteBody& body) {
    AMQP_ServerOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExchangeQueryBody& body) {
    AMQP_ServerOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExchangeBindBody& body) {
    AMQP_ServerOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExchangeUnbindBody& body) {
    AMQP_ServerOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const ExchangeBoundBody& body) {
    AMQP_ServerOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const QueueDeclareBody& body) {
    AMQP_ServerOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const QueueDeleteBody& body) {
    AMQP_ServerOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const QueuePurgeBody& body) {
    AMQP_ServerOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const QueueQueryBody& body) {
    AMQP_ServerOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileQosBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileConsumeBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileCancelBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileOpenBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileOpenOkBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FilePublishBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileAckBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const FileRejectBody& body) {
    AMQP_ServerOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const StreamQosBody& body) {
    AMQP_ServerOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const StreamConsumeBody& body) {
    AMQP_ServerOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::Invoker::visit(const StreamCancelBody& body) {
    AMQP_ServerOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionStartOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionSecureOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionTuneOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionOpenBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionHeartbeatBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionCloseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ConnectionHandler::Invoker::visit(const ConnectionCloseOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionAttachBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionAttachedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionDetachBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionDetachedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionRequestTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionCommandPointBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionExpectedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionConfirmedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionCompletedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionKnownCompletedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionFlushBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::SessionHandler::Invoker::visit(const SessionGapBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExecutionHandler::Invoker::visit(const ExecutionSyncBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExecutionHandler::Invoker::visit(const ExecutionResultBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExecutionHandler::Invoker::visit(const ExecutionExceptionBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageAcceptBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageRejectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageReleaseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageAcquireBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageResumeBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageSubscribeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageCancelBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageSetFlowModeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageFlowBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageFlushBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::MessageHandler::Invoker::visit(const MessageStopBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::TxHandler::Invoker::visit(const TxSelectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::TxHandler::Invoker::visit(const TxCommitBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::TxHandler::Invoker::visit(const TxRollbackBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxSelectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxStartBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxEndBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxCommitBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxForgetBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxGetTimeoutBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxPrepareBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxRecoverBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxRollbackBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::DtxHandler::Invoker::visit(const DtxSetTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExchangeHandler::Invoker::visit(const ExchangeDeclareBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExchangeHandler::Invoker::visit(const ExchangeDeleteBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExchangeHandler::Invoker::visit(const ExchangeQueryBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::ExchangeHandler::Invoker::visit(const ExchangeBindBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExchangeHandler::Invoker::visit(const ExchangeUnbindBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::ExchangeHandler::Invoker::visit(const ExchangeBoundBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::QueueHandler::Invoker::visit(const QueueDeclareBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::QueueHandler::Invoker::visit(const QueueDeleteBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::QueueHandler::Invoker::visit(const QueuePurgeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::QueueHandler::Invoker::visit(const QueueQueryBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileQosBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileConsumeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileCancelBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileOpenBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileOpenOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FilePublishBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileAckBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::FileHandler::Invoker::visit(const FileRejectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::StreamHandler::Invoker::visit(const StreamQosBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::StreamHandler::Invoker::visit(const StreamConsumeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ServerOperations::StreamHandler::Invoker::visit(const StreamCancelBody& body) {
    body.invoke(target);
    result.handled=true;
}

}} // namespace qpid::framing

