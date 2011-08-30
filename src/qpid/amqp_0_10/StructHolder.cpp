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


#include "qpid/amqp_0_10/StructHolder.h"
#include "qpid/amqp_0_10/exceptions.h"

namespace qpid {
namespace amqp_0_10 {

using framing::in_place;

void StructHolder::set(uint8_t classCode, uint8_t code) {
    uint16_t key=(classCode<<8)+code;
    switch(key) {
        case 0x401: *this=in_place<message::DeliveryProperties>(); break;
        case 0x402: *this=in_place<message::FragmentProperties>(); break;
        case 0x403: *this=in_place<message::MessageProperties>(); break;
        case 0x404: *this=in_place<message::Acquired>(); break;
        case 0x405: *this=in_place<message::MessageResumeResult>(); break;
        case 0x601: *this=in_place<dtx::XaResult>(); break;
        case 0x604: *this=in_place<dtx::Xid>(); break;
        case 0x602: *this=in_place<dtx::GetTimeoutResult>(); break;
        case 0x603: *this=in_place<dtx::RecoverResult>(); break;
        case 0x701: *this=in_place<exchange::ExchangeQueryResult>(); break;
        case 0x702: *this=in_place<exchange::ExchangeBoundResult>(); break;
        case 0x801: *this=in_place<queue::QueueQueryResult>(); break;
        case 0x901: *this=in_place<file::FileProperties>(); break;
        case 0xa01: *this=in_place<stream::StreamProperties>(); break;
        default: 
            *this=in_place<UnknownStruct>(classCode, code);
    }
}

std::ostream& operator<<(std::ostream& o, const StructHolder& h) { return h.get() ? (o << *h.get()) : (o << "<empty StructHolder>"); }

}} // namespace qpid::amqp_0_10

