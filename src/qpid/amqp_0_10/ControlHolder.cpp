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


#include "qpid/amqp_0_10/ControlHolder.h"
#include "qpid/amqp_0_10/exceptions.h"

namespace qpid {
namespace amqp_0_10 {

using framing::in_place;

void ControlHolder::set(uint8_t classCode, uint8_t code) {
    uint16_t key=(classCode<<8)+code;
    switch(key) {
        case 0x101: *this=in_place<connection::Start>(); break;
        case 0x102: *this=in_place<connection::StartOk>(); break;
        case 0x103: *this=in_place<connection::Secure>(); break;
        case 0x104: *this=in_place<connection::SecureOk>(); break;
        case 0x105: *this=in_place<connection::Tune>(); break;
        case 0x106: *this=in_place<connection::TuneOk>(); break;
        case 0x107: *this=in_place<connection::Open>(); break;
        case 0x108: *this=in_place<connection::OpenOk>(); break;
        case 0x109: *this=in_place<connection::Redirect>(); break;
        case 0x10a: *this=in_place<connection::Heartbeat>(); break;
        case 0x10b: *this=in_place<connection::Close>(); break;
        case 0x10c: *this=in_place<connection::CloseOk>(); break;
        case 0x201: *this=in_place<session::Attach>(); break;
        case 0x202: *this=in_place<session::Attached>(); break;
        case 0x203: *this=in_place<session::Detach>(); break;
        case 0x204: *this=in_place<session::Detached>(); break;
        case 0x205: *this=in_place<session::RequestTimeout>(); break;
        case 0x206: *this=in_place<session::Timeout>(); break;
        case 0x207: *this=in_place<session::CommandPoint>(); break;
        case 0x208: *this=in_place<session::Expected>(); break;
        case 0x209: *this=in_place<session::Confirmed>(); break;
        case 0x20a: *this=in_place<session::Completed>(); break;
        case 0x20b: *this=in_place<session::KnownCompleted>(); break;
        case 0x20c: *this=in_place<session::Flush>(); break;
        case 0x20d: *this=in_place<session::Gap>(); break;
        case 0x8001: *this=in_place<cluster::UpdateRequest>(); break;
        case 0x8002: *this=in_place<cluster::UpdateOffer>(); break;
        case 0x8003: *this=in_place<cluster::RetractOffer>(); break;
        case 0x8005: *this=in_place<cluster::InitialStatus>(); break;
        case 0x8010: *this=in_place<cluster::Ready>(); break;
        case 0x8011: *this=in_place<cluster::ConfigChange>(); break;
        case 0x8014: *this=in_place<cluster::ErrorCheck>(); break;
        case 0x8015: *this=in_place<cluster::TimerWakeup>(); break;
        case 0x8016: *this=in_place<cluster::TimerDrop>(); break;
        case 0x8020: *this=in_place<cluster::Shutdown>(); break;
        case 0x8021: *this=in_place<cluster::DeliverToQueue>(); break;
        case 0x8022: *this=in_place<cluster::Clock>(); break;
        case 0x8101: *this=in_place<cluster-connection::Announce>(); break;
        case 0x8102: *this=in_place<cluster-connection::DeliverClose>(); break;
        case 0x8103: *this=in_place<cluster-connection::DeliverDoOutput>(); break;
        case 0x8104: *this=in_place<cluster-connection::Abort>(); break;
        case 0x810e: *this=in_place<cluster-connection::ShadowSetUser>(); break;
        case 0x810f: *this=in_place<cluster-connection::ShadowPrepare>(); break;
        case 0x8110: *this=in_place<cluster-connection::ConsumerState>(); break;
        case 0x8111: *this=in_place<cluster-connection::DeliveryRecord>(); break;
        case 0x8112: *this=in_place<cluster-connection::TxStart>(); break;
        case 0x8113: *this=in_place<cluster-connection::TxAccept>(); break;
        case 0x8114: *this=in_place<cluster-connection::TxDequeue>(); break;
        case 0x8115: *this=in_place<cluster-connection::TxEnqueue>(); break;
        case 0x8116: *this=in_place<cluster-connection::TxPublish>(); break;
        case 0x8117: *this=in_place<cluster-connection::TxEnd>(); break;
        case 0x8118: *this=in_place<cluster-connection::AccumulatedAck>(); break;
        case 0x8119: *this=in_place<cluster-connection::OutputTask>(); break;
        case 0x811a: *this=in_place<cluster-connection::DtxStart>(); break;
        case 0x811b: *this=in_place<cluster-connection::DtxEnd>(); break;
        case 0x811c: *this=in_place<cluster-connection::DtxAck>(); break;
        case 0x811d: *this=in_place<cluster-connection::DtxBufferRef>(); break;
        case 0x811e: *this=in_place<cluster-connection::DtxWorkRecord>(); break;
        case 0x811f: *this=in_place<cluster-connection::SessionState>(); break;
        case 0x8120: *this=in_place<cluster-connection::ShadowReady>(); break;
        case 0x8121: *this=in_place<cluster-connection::Membership>(); break;
        case 0x8122: *this=in_place<cluster-connection::RetractOffer>(); break;
        case 0x8130: *this=in_place<cluster-connection::QueuePosition>(); break;
        case 0x8131: *this=in_place<cluster-connection::Exchange>(); break;
        case 0x8134: *this=in_place<cluster-connection::AddQueueListener>(); break;
        case 0x8136: *this=in_place<cluster-connection::ManagementSetupState>(); break;
        case 0x8137: *this=in_place<cluster-connection::Config>(); break;
        case 0x8138: *this=in_place<cluster-connection::QueueFairshareState>(); break;
        case 0x8139: *this=in_place<cluster-connection::QueueObserverState>(); break;
        case 0x8140: *this=in_place<cluster-connection::Clock>(); break;
        case 0x8141: *this=in_place<cluster-connection::QueueDequeueSincePurgeState>(); break;
        case 0x8142: *this=in_place<cluster-connection::InternalState>(); break;
        default: 
            throw CommandInvalidException(QPID_MSG("Invalid class-control key " << std::hex << key));
    }
}

std::ostream& operator<<(std::ostream& o, const ControlHolder& h) { return h.get() ? (o << *h.get()) : (o << "<empty ControlHolder>"); }

}} // namespace qpid::amqp_0_10

