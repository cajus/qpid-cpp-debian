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


#include "qpid/framing/MethodBodyDefaultVisitor.h"
#include "qpid/framing/all_method_bodies.h"

namespace qpid {
namespace framing {

void MethodBodyDefaultVisitor::visit(const ConnectionStartBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionStartOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionSecureBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionSecureOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionTuneBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionTuneOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionOpenBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionOpenOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionRedirectBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionHeartbeatBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionCloseBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ConnectionCloseOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionAttachBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionAttachedBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionDetachBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionDetachedBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionRequestTimeoutBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionTimeoutBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionCommandPointBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionExpectedBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionConfirmedBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionCompletedBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionKnownCompletedBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionFlushBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const SessionGapBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExecutionSyncBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExecutionResultBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExecutionExceptionBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageTransferBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageAcceptBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageRejectBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageReleaseBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageAcquireBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageResumeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageSubscribeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageCancelBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageSetFlowModeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageFlowBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageFlushBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const MessageStopBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const TxSelectBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const TxCommitBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const TxRollbackBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxSelectBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxStartBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxEndBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxCommitBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxForgetBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxGetTimeoutBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxPrepareBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxRecoverBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxRollbackBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const DtxSetTimeoutBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExchangeDeclareBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExchangeDeleteBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExchangeQueryBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExchangeBindBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExchangeUnbindBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ExchangeBoundBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const QueueDeclareBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const QueueDeleteBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const QueuePurgeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const QueueQueryBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileQosBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileQosOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileConsumeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileConsumeOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileCancelBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileOpenBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileOpenOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileStageBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FilePublishBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileReturnBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileDeliverBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileAckBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const FileRejectBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamQosBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamQosOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamConsumeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamConsumeOkBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamCancelBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamPublishBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamReturnBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const StreamDeliverBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterUpdateRequestBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterUpdateOfferBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterRetractOfferBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterInitialStatusBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterReadyBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConfigChangeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterErrorCheckBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterTimerWakeupBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterTimerDropBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterShutdownBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterDeliverToQueueBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterClockBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionAnnounceBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDeliverCloseBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDeliverDoOutputBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionAbortBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionShadowSetUserBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionShadowPrepareBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionConsumerStateBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDeliveryRecordBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionTxStartBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionTxAcceptBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionTxDequeueBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionTxEnqueueBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionTxPublishBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionTxEndBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionAccumulatedAckBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionOutputTaskBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDtxStartBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDtxEndBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDtxAckBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDtxBufferRefBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionDtxWorkRecordBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionSessionStateBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionShadowReadyBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionMembershipBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionRetractOfferBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionQueuePositionBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionExchangeBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionAddQueueListenerBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionManagementSetupStateBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionConfigBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionQueueFairshareStateBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionQueueObserverStateBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionClockBody& b) { defaultVisit(b); }
void MethodBodyDefaultVisitor::visit(const ClusterConnectionQueueDequeueSincePurgeStateBody& b) { defaultVisit(b); }

}} // namespace qpid::framing

