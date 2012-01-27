#ifndef TESTS_ALLSEGMENTTYPES_H
#define TESTS_ALLSEGMENTTYPES_H
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


#include "qpid/amqp_0_10/specification.h"
#include "qpid/amqp_0_10/Header.h"
#include "qpid/amqp_0_10/Body.h"

using namespace qpid::amqp_0_10;

template <class Op> size_t allSegmentTypes(Op& op) {
    op(Header());
    op(Body());
    op(ControlHolder(connection::Start()));
    op(ControlHolder(connection::StartOk()));
    op(ControlHolder(connection::Secure()));
    op(ControlHolder(connection::SecureOk()));
    op(ControlHolder(connection::Tune()));
    op(ControlHolder(connection::TuneOk()));
    op(ControlHolder(connection::Open()));
    op(ControlHolder(connection::OpenOk()));
    op(ControlHolder(connection::Redirect()));
    op(ControlHolder(connection::Heartbeat()));
    op(ControlHolder(connection::Close()));
    op(ControlHolder(connection::CloseOk()));
    op(ControlHolder(session::Attach()));
    op(ControlHolder(session::Attached()));
    op(ControlHolder(session::Detach()));
    op(ControlHolder(session::Detached()));
    op(ControlHolder(session::RequestTimeout()));
    op(ControlHolder(session::Timeout()));
    op(ControlHolder(session::CommandPoint()));
    op(ControlHolder(session::Expected()));
    op(ControlHolder(session::Confirmed()));
    op(ControlHolder(session::Completed()));
    op(ControlHolder(session::KnownCompleted()));
    op(ControlHolder(session::Flush()));
    op(ControlHolder(session::Gap()));
    op(CommandHolder(execution::Sync()));
    op(CommandHolder(execution::Result()));
    op(CommandHolder(execution::Exception()));
    op(CommandHolder(message::Transfer()));
    op(CommandHolder(message::Accept()));
    op(CommandHolder(message::Reject()));
    op(CommandHolder(message::Release()));
    op(CommandHolder(message::Acquire()));
    op(CommandHolder(message::Resume()));
    op(CommandHolder(message::Subscribe()));
    op(CommandHolder(message::Cancel()));
    op(CommandHolder(message::SetFlowMode()));
    op(CommandHolder(message::Flow()));
    op(CommandHolder(message::Flush()));
    op(CommandHolder(message::Stop()));
    op(CommandHolder(tx::Select()));
    op(CommandHolder(tx::Commit()));
    op(CommandHolder(tx::Rollback()));
    op(CommandHolder(dtx::Select()));
    op(CommandHolder(dtx::Start()));
    op(CommandHolder(dtx::End()));
    op(CommandHolder(dtx::Commit()));
    op(CommandHolder(dtx::Forget()));
    op(CommandHolder(dtx::GetTimeout()));
    op(CommandHolder(dtx::Prepare()));
    op(CommandHolder(dtx::Recover()));
    op(CommandHolder(dtx::Rollback()));
    op(CommandHolder(dtx::SetTimeout()));
    op(CommandHolder(exchange::Declare()));
    op(CommandHolder(exchange::Delete()));
    op(CommandHolder(exchange::Query()));
    op(CommandHolder(exchange::Bind()));
    op(CommandHolder(exchange::Unbind()));
    op(CommandHolder(exchange::Bound()));
    op(CommandHolder(queue::Declare()));
    op(CommandHolder(queue::Delete()));
    op(CommandHolder(queue::Purge()));
    op(CommandHolder(queue::Query()));
    op(CommandHolder(file::Qos()));
    op(CommandHolder(file::QosOk()));
    op(CommandHolder(file::Consume()));
    op(CommandHolder(file::ConsumeOk()));
    op(CommandHolder(file::Cancel()));
    op(CommandHolder(file::Open()));
    op(CommandHolder(file::OpenOk()));
    op(CommandHolder(file::Stage()));
    op(CommandHolder(file::Publish()));
    op(CommandHolder(file::Return()));
    op(CommandHolder(file::Deliver()));
    op(CommandHolder(file::Ack()));
    op(CommandHolder(file::Reject()));
    op(CommandHolder(stream::Qos()));
    op(CommandHolder(stream::QosOk()));
    op(CommandHolder(stream::Consume()));
    op(CommandHolder(stream::ConsumeOk()));
    op(CommandHolder(stream::Cancel()));
    op(CommandHolder(stream::Publish()));
    op(CommandHolder(stream::Return()));
    op(CommandHolder(stream::Deliver()));
    op(ControlHolder(cluster::UpdateRequest()));
    op(ControlHolder(cluster::UpdateOffer()));
    op(ControlHolder(cluster::RetractOffer()));
    op(ControlHolder(cluster::InitialStatus()));
    op(ControlHolder(cluster::Ready()));
    op(ControlHolder(cluster::ConfigChange()));
    op(ControlHolder(cluster::ErrorCheck()));
    op(ControlHolder(cluster::TimerWakeup()));
    op(ControlHolder(cluster::TimerDrop()));
    op(ControlHolder(cluster::Shutdown()));
    op(ControlHolder(cluster::DeliverToQueue()));
    op(ControlHolder(cluster::Clock()));
    op(ControlHolder(cluster_connection::Announce()));
    op(ControlHolder(cluster_connection::DeliverClose()));
    op(ControlHolder(cluster_connection::DeliverDoOutput()));
    op(ControlHolder(cluster_connection::Abort()));
    op(ControlHolder(cluster_connection::ShadowSetUser()));
    op(ControlHolder(cluster_connection::ShadowPrepare()));
    op(ControlHolder(cluster_connection::ConsumerState()));
    op(ControlHolder(cluster_connection::DeliveryRecord()));
    op(ControlHolder(cluster_connection::TxStart()));
    op(ControlHolder(cluster_connection::TxAccept()));
    op(ControlHolder(cluster_connection::TxDequeue()));
    op(ControlHolder(cluster_connection::TxEnqueue()));
    op(ControlHolder(cluster_connection::TxPublish()));
    op(ControlHolder(cluster_connection::TxEnd()));
    op(ControlHolder(cluster_connection::AccumulatedAck()));
    op(ControlHolder(cluster_connection::OutputTask()));
    op(ControlHolder(cluster_connection::DtxStart()));
    op(ControlHolder(cluster_connection::DtxEnd()));
    op(ControlHolder(cluster_connection::DtxAck()));
    op(ControlHolder(cluster_connection::DtxBufferRef()));
    op(ControlHolder(cluster_connection::DtxWorkRecord()));
    op(ControlHolder(cluster_connection::SessionState()));
    op(ControlHolder(cluster_connection::ShadowReady()));
    op(ControlHolder(cluster_connection::Membership()));
    op(ControlHolder(cluster_connection::RetractOffer()));
    op(ControlHolder(cluster_connection::QueuePosition()));
    op(ControlHolder(cluster_connection::Exchange()));
    op(ControlHolder(cluster_connection::AddQueueListener()));
    op(ControlHolder(cluster_connection::ManagementSetupState()));
    op(ControlHolder(cluster_connection::Config()));
    op(ControlHolder(cluster_connection::QueueFairshareState()));
    op(ControlHolder(cluster_connection::QueueObserverState()));
    op(ControlHolder(cluster_connection::Clock()));
    op(ControlHolder(cluster_connection::QueueDequeueSincePurgeState()));
    return 26;
}
#endif  /*!TESTS_ALLSEGMENTTYPES_H*/
