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


#include "qpid/framing/AllInvoker.h"
#include "qpid/framing/ConnectionStartBody.h"
#include "qpid/framing/ConnectionStartOkBody.h"
#include "qpid/framing/ConnectionSecureBody.h"
#include "qpid/framing/ConnectionSecureOkBody.h"
#include "qpid/framing/ConnectionTuneBody.h"
#include "qpid/framing/ConnectionTuneOkBody.h"
#include "qpid/framing/ConnectionOpenBody.h"
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
#include "qpid/framing/FileQosOkBody.h"
#include "qpid/framing/FileConsumeBody.h"
#include "qpid/framing/FileConsumeOkBody.h"
#include "qpid/framing/FileCancelBody.h"
#include "qpid/framing/FileOpenBody.h"
#include "qpid/framing/FileOpenOkBody.h"
#include "qpid/framing/FilePublishBody.h"
#include "qpid/framing/FileDeliverBody.h"
#include "qpid/framing/FileAckBody.h"
#include "qpid/framing/FileRejectBody.h"
#include "qpid/framing/StreamQosBody.h"
#include "qpid/framing/StreamQosOkBody.h"
#include "qpid/framing/StreamConsumeBody.h"
#include "qpid/framing/StreamConsumeOkBody.h"
#include "qpid/framing/StreamCancelBody.h"
#include "qpid/framing/ClusterUpdateRequestBody.h"
#include "qpid/framing/ClusterUpdateOfferBody.h"
#include "qpid/framing/ClusterRetractOfferBody.h"
#include "qpid/framing/ClusterInitialStatusBody.h"
#include "qpid/framing/ClusterReadyBody.h"
#include "qpid/framing/ClusterConfigChangeBody.h"
#include "qpid/framing/ClusterErrorCheckBody.h"
#include "qpid/framing/ClusterTimerWakeupBody.h"
#include "qpid/framing/ClusterTimerDropBody.h"
#include "qpid/framing/ClusterShutdownBody.h"
#include "qpid/framing/ClusterDeliverToQueueBody.h"
#include "qpid/framing/ClusterClockBody.h"
#include "qpid/framing/ClusterConnectionAnnounceBody.h"
#include "qpid/framing/ClusterConnectionDeliverCloseBody.h"
#include "qpid/framing/ClusterConnectionDeliverDoOutputBody.h"
#include "qpid/framing/ClusterConnectionAbortBody.h"
#include "qpid/framing/ClusterConnectionShadowSetUserBody.h"
#include "qpid/framing/ClusterConnectionShadowPrepareBody.h"
#include "qpid/framing/ClusterConnectionConsumerStateBody.h"
#include "qpid/framing/ClusterConnectionDeliveryRecordBody.h"
#include "qpid/framing/ClusterConnectionTxStartBody.h"
#include "qpid/framing/ClusterConnectionTxAcceptBody.h"
#include "qpid/framing/ClusterConnectionTxDequeueBody.h"
#include "qpid/framing/ClusterConnectionTxEnqueueBody.h"
#include "qpid/framing/ClusterConnectionTxPublishBody.h"
#include "qpid/framing/ClusterConnectionTxEndBody.h"
#include "qpid/framing/ClusterConnectionAccumulatedAckBody.h"
#include "qpid/framing/ClusterConnectionOutputTaskBody.h"
#include "qpid/framing/ClusterConnectionSessionStateBody.h"
#include "qpid/framing/ClusterConnectionShadowReadyBody.h"
#include "qpid/framing/ClusterConnectionMembershipBody.h"
#include "qpid/framing/ClusterConnectionRetractOfferBody.h"
#include "qpid/framing/ClusterConnectionQueuePositionBody.h"
#include "qpid/framing/ClusterConnectionExchangeBody.h"
#include "qpid/framing/ClusterConnectionAddQueueListenerBody.h"
#include "qpid/framing/ClusterConnectionManagementSetupStateBody.h"
#include "qpid/framing/ClusterConnectionConfigBody.h"
#include "qpid/framing/ClusterConnectionQueueFairshareStateBody.h"
#include "qpid/framing/ClusterConnectionQueueObserverStateBody.h"
#include "qpid/framing/ClusterConnectionClockBody.h"
#include "qpid/framing/ClusterConnectionQueueDequeueSincePurgeStateBody.h"

namespace qpid {
namespace framing {

void AMQP_AllOperations::Invoker::visit(const ConnectionStartBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionStartOkBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionSecureBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionSecureOkBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionTuneBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionTuneOkBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionOpenBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionOpenOkBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionRedirectBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionHeartbeatBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionCloseBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ConnectionCloseOkBody& body) {
    AMQP_AllOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionAttachBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionAttachedBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionDetachBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionDetachedBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionRequestTimeoutBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionTimeoutBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionCommandPointBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionExpectedBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionConfirmedBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionCompletedBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionKnownCompletedBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionFlushBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const SessionGapBody& body) {
    AMQP_AllOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExecutionSyncBody& body) {
    AMQP_AllOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExecutionResultBody& body) {
    AMQP_AllOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExecutionExceptionBody& body) {
    AMQP_AllOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageAcceptBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageRejectBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageReleaseBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageAcquireBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageResumeBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageSubscribeBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageCancelBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageSetFlowModeBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageFlowBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageFlushBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const MessageStopBody& body) {
    AMQP_AllOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const TxSelectBody& body) {
    AMQP_AllOperations::TxHandler::Invoker invoker(*target.getTxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const TxCommitBody& body) {
    AMQP_AllOperations::TxHandler::Invoker invoker(*target.getTxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const TxRollbackBody& body) {
    AMQP_AllOperations::TxHandler::Invoker invoker(*target.getTxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxSelectBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxStartBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxEndBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxCommitBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxForgetBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxGetTimeoutBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxPrepareBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxRecoverBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxRollbackBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const DtxSetTimeoutBody& body) {
    AMQP_AllOperations::DtxHandler::Invoker invoker(*target.getDtxHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExchangeDeclareBody& body) {
    AMQP_AllOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExchangeDeleteBody& body) {
    AMQP_AllOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExchangeQueryBody& body) {
    AMQP_AllOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExchangeBindBody& body) {
    AMQP_AllOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExchangeUnbindBody& body) {
    AMQP_AllOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ExchangeBoundBody& body) {
    AMQP_AllOperations::ExchangeHandler::Invoker invoker(*target.getExchangeHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const QueueDeclareBody& body) {
    AMQP_AllOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const QueueDeleteBody& body) {
    AMQP_AllOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const QueuePurgeBody& body) {
    AMQP_AllOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const QueueQueryBody& body) {
    AMQP_AllOperations::QueueHandler::Invoker invoker(*target.getQueueHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileQosBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileQosOkBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileConsumeBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileConsumeOkBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileCancelBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileOpenBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileOpenOkBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FilePublishBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileDeliverBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileAckBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const FileRejectBody& body) {
    AMQP_AllOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const StreamQosBody& body) {
    AMQP_AllOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const StreamQosOkBody& body) {
    AMQP_AllOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const StreamConsumeBody& body) {
    AMQP_AllOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const StreamConsumeOkBody& body) {
    AMQP_AllOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const StreamCancelBody& body) {
    AMQP_AllOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterUpdateRequestBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterUpdateOfferBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterRetractOfferBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterInitialStatusBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterReadyBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConfigChangeBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterErrorCheckBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterTimerWakeupBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterTimerDropBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterShutdownBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterDeliverToQueueBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterClockBody& body) {
    AMQP_AllOperations::ClusterHandler::Invoker invoker(*target.getClusterHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionAnnounceBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionDeliverCloseBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionDeliverDoOutputBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionAbortBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionShadowSetUserBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionShadowPrepareBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionConsumerStateBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionDeliveryRecordBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionTxStartBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionTxAcceptBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionTxDequeueBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionTxEnqueueBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionTxPublishBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionTxEndBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionAccumulatedAckBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionOutputTaskBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionSessionStateBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionShadowReadyBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionMembershipBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionRetractOfferBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionQueuePositionBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionExchangeBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionAddQueueListenerBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionManagementSetupStateBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionConfigBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionQueueFairshareStateBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionQueueObserverStateBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionClockBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::Invoker::visit(const ClusterConnectionQueueDequeueSincePurgeStateBody& body) {
    AMQP_AllOperations::ClusterConnectionHandler::Invoker invoker(*target.getClusterConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionStartBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionStartOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionSecureBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionSecureOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionTuneBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionTuneOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionOpenBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionOpenOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionRedirectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionHeartbeatBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionCloseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ConnectionHandler::Invoker::visit(const ConnectionCloseOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionAttachBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionAttachedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionDetachBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionDetachedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionRequestTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionCommandPointBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionExpectedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionConfirmedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionCompletedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionKnownCompletedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionFlushBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::SessionHandler::Invoker::visit(const SessionGapBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExecutionHandler::Invoker::visit(const ExecutionSyncBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExecutionHandler::Invoker::visit(const ExecutionResultBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExecutionHandler::Invoker::visit(const ExecutionExceptionBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageAcceptBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageRejectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageReleaseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageAcquireBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageResumeBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageSubscribeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageCancelBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageSetFlowModeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageFlowBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageFlushBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::MessageHandler::Invoker::visit(const MessageStopBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::TxHandler::Invoker::visit(const TxSelectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::TxHandler::Invoker::visit(const TxCommitBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::TxHandler::Invoker::visit(const TxRollbackBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxSelectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxStartBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxEndBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxCommitBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxForgetBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxGetTimeoutBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxPrepareBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxRecoverBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxRollbackBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::DtxHandler::Invoker::visit(const DtxSetTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExchangeHandler::Invoker::visit(const ExchangeDeclareBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExchangeHandler::Invoker::visit(const ExchangeDeleteBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExchangeHandler::Invoker::visit(const ExchangeQueryBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::ExchangeHandler::Invoker::visit(const ExchangeBindBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExchangeHandler::Invoker::visit(const ExchangeUnbindBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ExchangeHandler::Invoker::visit(const ExchangeBoundBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::QueueHandler::Invoker::visit(const QueueDeclareBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::QueueHandler::Invoker::visit(const QueueDeleteBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::QueueHandler::Invoker::visit(const QueuePurgeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::QueueHandler::Invoker::visit(const QueueQueryBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileQosBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileQosOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileConsumeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileConsumeOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileCancelBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileOpenBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileOpenOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FilePublishBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileDeliverBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileAckBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::FileHandler::Invoker::visit(const FileRejectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::StreamHandler::Invoker::visit(const StreamQosBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::StreamHandler::Invoker::visit(const StreamQosOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::StreamHandler::Invoker::visit(const StreamConsumeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::StreamHandler::Invoker::visit(const StreamConsumeOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::StreamHandler::Invoker::visit(const StreamCancelBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterUpdateRequestBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterUpdateOfferBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterRetractOfferBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterInitialStatusBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterReadyBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterConfigChangeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterErrorCheckBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterTimerWakeupBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterTimerDropBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterShutdownBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterDeliverToQueueBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterHandler::Invoker::visit(const ClusterClockBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionAnnounceBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionDeliverCloseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionDeliverDoOutputBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionAbortBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionShadowSetUserBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionShadowPrepareBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionConsumerStateBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionDeliveryRecordBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionTxStartBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionTxAcceptBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionTxDequeueBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionTxEnqueueBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionTxPublishBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionTxEndBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionAccumulatedAckBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionOutputTaskBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionSessionStateBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionShadowReadyBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionMembershipBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionRetractOfferBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionQueuePositionBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionExchangeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionAddQueueListenerBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionManagementSetupStateBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionConfigBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionQueueFairshareStateBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionQueueObserverStateBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionClockBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_AllOperations::ClusterConnectionHandler::Invoker::visit(const ClusterConnectionQueueDequeueSincePurgeStateBody& body) {
    body.invoke(target);
    result.handled=true;
}

}} // namespace qpid::framing

