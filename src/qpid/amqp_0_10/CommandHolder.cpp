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


#include "qpid/amqp_0_10/CommandHolder.h"
#include "qpid/amqp_0_10/exceptions.h"

namespace qpid {
namespace amqp_0_10 {

using framing::in_place;

void CommandHolder::set(uint8_t classCode, uint8_t code) {
    uint16_t key=(classCode<<8)+code;
    switch(key) {
        case 0x301: *this=in_place<execution::Sync>(); break;
        case 0x302: *this=in_place<execution::Result>(); break;
        case 0x303: *this=in_place<execution::Exception>(); break;
        case 0x401: *this=in_place<message::Transfer>(); break;
        case 0x402: *this=in_place<message::Accept>(); break;
        case 0x403: *this=in_place<message::Reject>(); break;
        case 0x404: *this=in_place<message::Release>(); break;
        case 0x405: *this=in_place<message::Acquire>(); break;
        case 0x406: *this=in_place<message::Resume>(); break;
        case 0x407: *this=in_place<message::Subscribe>(); break;
        case 0x408: *this=in_place<message::Cancel>(); break;
        case 0x409: *this=in_place<message::SetFlowMode>(); break;
        case 0x40a: *this=in_place<message::Flow>(); break;
        case 0x40b: *this=in_place<message::Flush>(); break;
        case 0x40c: *this=in_place<message::Stop>(); break;
        case 0x501: *this=in_place<tx::Select>(); break;
        case 0x502: *this=in_place<tx::Commit>(); break;
        case 0x503: *this=in_place<tx::Rollback>(); break;
        case 0x601: *this=in_place<dtx::Select>(); break;
        case 0x602: *this=in_place<dtx::Start>(); break;
        case 0x603: *this=in_place<dtx::End>(); break;
        case 0x604: *this=in_place<dtx::Commit>(); break;
        case 0x605: *this=in_place<dtx::Forget>(); break;
        case 0x606: *this=in_place<dtx::GetTimeout>(); break;
        case 0x607: *this=in_place<dtx::Prepare>(); break;
        case 0x608: *this=in_place<dtx::Recover>(); break;
        case 0x609: *this=in_place<dtx::Rollback>(); break;
        case 0x60a: *this=in_place<dtx::SetTimeout>(); break;
        case 0x701: *this=in_place<exchange::Declare>(); break;
        case 0x702: *this=in_place<exchange::Delete>(); break;
        case 0x703: *this=in_place<exchange::Query>(); break;
        case 0x704: *this=in_place<exchange::Bind>(); break;
        case 0x705: *this=in_place<exchange::Unbind>(); break;
        case 0x706: *this=in_place<exchange::Bound>(); break;
        case 0x801: *this=in_place<queue::Declare>(); break;
        case 0x802: *this=in_place<queue::Delete>(); break;
        case 0x803: *this=in_place<queue::Purge>(); break;
        case 0x804: *this=in_place<queue::Query>(); break;
        case 0x901: *this=in_place<file::Qos>(); break;
        case 0x902: *this=in_place<file::QosOk>(); break;
        case 0x903: *this=in_place<file::Consume>(); break;
        case 0x904: *this=in_place<file::ConsumeOk>(); break;
        case 0x905: *this=in_place<file::Cancel>(); break;
        case 0x906: *this=in_place<file::Open>(); break;
        case 0x907: *this=in_place<file::OpenOk>(); break;
        case 0x908: *this=in_place<file::Stage>(); break;
        case 0x909: *this=in_place<file::Publish>(); break;
        case 0x90a: *this=in_place<file::Return>(); break;
        case 0x90b: *this=in_place<file::Deliver>(); break;
        case 0x90c: *this=in_place<file::Ack>(); break;
        case 0x90d: *this=in_place<file::Reject>(); break;
        case 0xa01: *this=in_place<stream::Qos>(); break;
        case 0xa02: *this=in_place<stream::QosOk>(); break;
        case 0xa03: *this=in_place<stream::Consume>(); break;
        case 0xa04: *this=in_place<stream::ConsumeOk>(); break;
        case 0xa05: *this=in_place<stream::Cancel>(); break;
        case 0xa06: *this=in_place<stream::Publish>(); break;
        case 0xa07: *this=in_place<stream::Return>(); break;
        case 0xa08: *this=in_place<stream::Deliver>(); break;
        default: 
            throw CommandInvalidException(QPID_MSG("Invalid class-command key " << std::hex << key));
    }
}

std::ostream& operator<<(std::ostream& o, const CommandHolder& h) { return h.get() ? (o << *h.get()) : (o << "<empty CommandHolder>"); }

}} // namespace qpid::amqp_0_10

