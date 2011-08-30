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


#include "qpid/amqp_0_10/structs.h"
#include "qpid/amqp_0_10/StructHolder.h"

namespace qpid {
namespace amqp_0_10 {


namespace connection {


} // namespace connection


namespace session {


const char* Header::NAME="session.header";
const char* Header::CLASS_NAME=session::NAME;

Header::Header(Bit sync_) :
    sync(sync_){
}

std::ostream& operator << (std::ostream& o, const Header&x) {
    o << "session.header[";
    o << " sync=" << x.sync;
    o << "]";
    return o;
}

const char* CommandFragment::NAME="session.command-fragment";
const char* CommandFragment::CLASS_NAME=session::NAME;

CommandFragment::CommandFragment(
    const SequenceNo& commandId_,
    const ByteRanges& byteRanges_
) :
    commandId(commandId_),
    byteRanges(byteRanges_){
}

std::ostream& operator << (std::ostream& o, const CommandFragment&x) {
    o << "session.command-fragment[";
    o << " command-id=" << x.commandId;
    o << " byte-ranges=" << x.byteRanges;
    o << "]";
    return o;
}

} // namespace session


namespace execution {


} // namespace execution


namespace message {


const char* DeliveryProperties::NAME="message.delivery-properties";
const char* DeliveryProperties::CLASS_NAME=message::NAME;

DeliveryProperties::DeliveryProperties(
    Bit discardUnroutable_,
    Bit immediate_,
    Bit redelivered_,
    const message::DeliveryPriority& priority_,
    const message::DeliveryMode& deliveryMode_,
    Uint64 ttl_,
    const Datetime& timestamp_,
    const Datetime& expiration_,
    const exchange::Name& exchange_,
    const Str8& routingKey_,
    const message::ResumeId& resumeId_,
    Uint64 resumeTtl_
) :
    discardUnroutable(discardUnroutable_),
    immediate(immediate_),
    redelivered(redelivered_),
    priority(priority_),
    deliveryMode(deliveryMode_),
    ttl(ttl_),
    timestamp(timestamp_),
    expiration(expiration_),
    exchange(exchange_),
    routingKey(routingKey_),
    resumeId(resumeId_),
    resumeTtl(resumeTtl_){
}
void DeliveryProperties::accept(Visitor& v) {  v.visit(*this); }
void DeliveryProperties::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DeliveryProperties&x) {
    o << "message.delivery-properties[";
    o << " discard-unroutable=" << x.discardUnroutable;
    o << " immediate=" << x.immediate;
    o << " redelivered=" << x.redelivered;
    o << " priority=" << x.priority;
    o << " delivery-mode=" << x.deliveryMode;
    o << " ttl=" << x.ttl;
    o << " timestamp=" << x.timestamp;
    o << " expiration=" << x.expiration;
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << " resume-id=" << x.resumeId;
    o << " resume-ttl=" << x.resumeTtl;
    o << "]";
    return o;
}

const char* FragmentProperties::NAME="message.fragment-properties";
const char* FragmentProperties::CLASS_NAME=message::NAME;

FragmentProperties::FragmentProperties(
    Bit first_,
    Bit last_,
    Uint64 fragmentSize_
) :
    first(first_),
    last(last_),
    fragmentSize(fragmentSize_){
}
void FragmentProperties::accept(Visitor& v) {  v.visit(*this); }
void FragmentProperties::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const FragmentProperties&x) {
    o << "message.fragment-properties[";
    o << " first=" << x.first;
    o << " last=" << x.last;
    o << " fragment-size=" << x.fragmentSize;
    o << "]";
    return o;
}

const char* ReplyTo::NAME="message.reply-to";
const char* ReplyTo::CLASS_NAME=message::NAME;

ReplyTo::ReplyTo(
    const exchange::Name& exchange_,
    const Str8& routingKey_
) :
    exchange(exchange_),
    routingKey(routingKey_){
}

std::ostream& operator << (std::ostream& o, const ReplyTo&x) {
    o << "message.reply-to[";
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << "]";
    return o;
}

const char* MessageProperties::NAME="message.message-properties";
const char* MessageProperties::CLASS_NAME=message::NAME;

MessageProperties::MessageProperties(
    Uint64 contentLength_,
    const Uuid& messageId_,
    const Vbin16& correlationId_,
    const message::ReplyTo& replyTo_,
    const Str8& contentType_,
    const Str8& contentEncoding_,
    const Vbin16& userId_,
    const Vbin16& appId_,
    const Map& applicationHeaders_
) :
    contentLength(contentLength_),
    messageId(messageId_),
    correlationId(correlationId_),
    replyTo(replyTo_),
    contentType(contentType_),
    contentEncoding(contentEncoding_),
    userId(userId_),
    appId(appId_),
    applicationHeaders(applicationHeaders_){
}
void MessageProperties::accept(Visitor& v) {  v.visit(*this); }
void MessageProperties::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const MessageProperties&x) {
    o << "message.message-properties[";
    o << " content-length=" << x.contentLength;
    o << " message-id=" << x.messageId;
    o << " correlation-id=" << x.correlationId;
    o << " reply-to=" << x.replyTo;
    o << " content-type=" << x.contentType;
    o << " content-encoding=" << x.contentEncoding;
    o << " user-id=" << x.userId;
    o << " app-id=" << x.appId;
    o << " application-headers=" << x.applicationHeaders;
    o << "]";
    return o;
}

const char* Acquired::NAME="message.acquire.result.acquired";
const char* Acquired::CLASS_NAME=message::NAME;

Acquired::Acquired(const session::Commands& transfers_) :
    transfers(transfers_){
}
void Acquired::accept(Visitor& v) {  v.visit(*this); }
void Acquired::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Acquired&x) {
    o << "message.acquire.result.acquired[";
    o << " transfers=" << x.transfers;
    o << "]";
    return o;
}

const char* MessageResumeResult::NAME="message.resume.result.message-resume-result";
const char* MessageResumeResult::CLASS_NAME=message::NAME;

MessageResumeResult::MessageResumeResult(Uint64 offset_) :
    offset(offset_){
}
void MessageResumeResult::accept(Visitor& v) {  v.visit(*this); }
void MessageResumeResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const MessageResumeResult&x) {
    o << "message.resume.result.message-resume-result[";
    o << " offset=" << x.offset;
    o << "]";
    return o;
}

} // namespace message


namespace tx {


} // namespace tx


namespace dtx {


const char* XaResult::NAME="dtx.xa-result";
const char* XaResult::CLASS_NAME=dtx::NAME;

XaResult::XaResult(const dtx::XaStatus& status_) :
    status(status_){
}
void XaResult::accept(Visitor& v) {  v.visit(*this); }
void XaResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const XaResult&x) {
    o << "dtx.xa-result[";
    o << " status=" << x.status;
    o << "]";
    return o;
}

const char* Xid::NAME="dtx.xid";
const char* Xid::CLASS_NAME=dtx::NAME;

Xid::Xid(
    Uint32 format_,
    const Vbin8& globalId_,
    const Vbin8& branchId_
) :
    format(format_),
    globalId(globalId_),
    branchId(branchId_){
}
void Xid::accept(Visitor& v) {  v.visit(*this); }
void Xid::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Xid&x) {
    o << "dtx.xid[";
    o << " format=" << x.format;
    o << " global-id=" << x.globalId;
    o << " branch-id=" << x.branchId;
    o << "]";
    return o;
}

const char* GetTimeoutResult::NAME="dtx.get-timeout.result.get-timeout-result";
const char* GetTimeoutResult::CLASS_NAME=dtx::NAME;

GetTimeoutResult::GetTimeoutResult(Uint32 timeout_) :
    timeout(timeout_){
}
void GetTimeoutResult::accept(Visitor& v) {  v.visit(*this); }
void GetTimeoutResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const GetTimeoutResult&x) {
    o << "dtx.get-timeout.result.get-timeout-result[";
    o << " timeout=" << x.timeout;
    o << "]";
    return o;
}

const char* RecoverResult::NAME="dtx.recover.result.recover-result";
const char* RecoverResult::CLASS_NAME=dtx::NAME;

RecoverResult::RecoverResult(const ArrayDomain<dtx::Xid> & inDoubt_) :
    inDoubt(inDoubt_){
}
void RecoverResult::accept(Visitor& v) {  v.visit(*this); }
void RecoverResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const RecoverResult&x) {
    o << "dtx.recover.result.recover-result[";
    o << " in-doubt=" << x.inDoubt;
    o << "]";
    return o;
}

} // namespace dtx


namespace exchange {


const char* ExchangeQueryResult::NAME="exchange.query.result.exchange-query-result";
const char* ExchangeQueryResult::CLASS_NAME=exchange::NAME;

ExchangeQueryResult::ExchangeQueryResult(
    const Str8& type_,
    Bit durable_,
    Bit notFound_,
    const Map& arguments_
) :
    type(type_),
    durable(durable_),
    notFound(notFound_),
    arguments(arguments_){
}
void ExchangeQueryResult::accept(Visitor& v) {  v.visit(*this); }
void ExchangeQueryResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ExchangeQueryResult&x) {
    o << "exchange.query.result.exchange-query-result[";
    o << " type=" << x.type;
    o << " durable=" << x.durable;
    o << " not-found=" << x.notFound;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}

const char* ExchangeBoundResult::NAME="exchange.bound.result.exchange-bound-result";
const char* ExchangeBoundResult::CLASS_NAME=exchange::NAME;

ExchangeBoundResult::ExchangeBoundResult(
    Bit exchangeNotFound_,
    Bit queueNotFound_,
    Bit queueNotMatched_,
    Bit keyNotMatched_,
    Bit argsNotMatched_
) :
    exchangeNotFound(exchangeNotFound_),
    queueNotFound(queueNotFound_),
    queueNotMatched(queueNotMatched_),
    keyNotMatched(keyNotMatched_),
    argsNotMatched(argsNotMatched_){
}
void ExchangeBoundResult::accept(Visitor& v) {  v.visit(*this); }
void ExchangeBoundResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ExchangeBoundResult&x) {
    o << "exchange.bound.result.exchange-bound-result[";
    o << " exchange-not-found=" << x.exchangeNotFound;
    o << " queue-not-found=" << x.queueNotFound;
    o << " queue-not-matched=" << x.queueNotMatched;
    o << " key-not-matched=" << x.keyNotMatched;
    o << " args-not-matched=" << x.argsNotMatched;
    o << "]";
    return o;
}

} // namespace exchange


namespace queue {


const char* QueueQueryResult::NAME="queue.query.result.queue-query-result";
const char* QueueQueryResult::CLASS_NAME=queue::NAME;

QueueQueryResult::QueueQueryResult(
    const queue::Name& queue_,
    const exchange::Name& alternateExchange_,
    Bit durable_,
    Bit exclusive_,
    Bit autoDelete_,
    const Map& arguments_,
    Uint32 messageCount_,
    Uint32 subscriberCount_
) :
    queue(queue_),
    alternateExchange(alternateExchange_),
    durable(durable_),
    exclusive(exclusive_),
    autoDelete(autoDelete_),
    arguments(arguments_),
    messageCount(messageCount_),
    subscriberCount(subscriberCount_){
}
void QueueQueryResult::accept(Visitor& v) {  v.visit(*this); }
void QueueQueryResult::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QueueQueryResult&x) {
    o << "queue.query.result.queue-query-result[";
    o << " queue=" << x.queue;
    o << " alternate-exchange=" << x.alternateExchange;
    o << " durable=" << x.durable;
    o << " exclusive=" << x.exclusive;
    o << " auto-delete=" << x.autoDelete;
    o << " arguments=" << x.arguments;
    o << " message-count=" << x.messageCount;
    o << " subscriber-count=" << x.subscriberCount;
    o << "]";
    return o;
}

} // namespace queue


namespace file {


const char* FileProperties::NAME="file.file-properties";
const char* FileProperties::CLASS_NAME=file::NAME;

FileProperties::FileProperties(
    const Str8& contentType_,
    const Str8& contentEncoding_,
    const Map& headers_,
    Uint8 priority_,
    const Str8& replyTo_,
    const Str8& messageId_,
    const Str8& filename_,
    const Datetime& timestamp_,
    const Str8& clusterId_
) :
    contentType(contentType_),
    contentEncoding(contentEncoding_),
    headers(headers_),
    priority(priority_),
    replyTo(replyTo_),
    messageId(messageId_),
    filename(filename_),
    timestamp(timestamp_),
    clusterId(clusterId_){
}
void FileProperties::accept(Visitor& v) {  v.visit(*this); }
void FileProperties::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const FileProperties&x) {
    o << "file.file-properties[";
    o << " content-type=" << x.contentType;
    o << " content-encoding=" << x.contentEncoding;
    o << " headers=" << x.headers;
    o << " priority=" << x.priority;
    o << " reply-to=" << x.replyTo;
    o << " message-id=" << x.messageId;
    o << " filename=" << x.filename;
    o << " timestamp=" << x.timestamp;
    o << " cluster-id=" << x.clusterId;
    o << "]";
    return o;
}

} // namespace file


namespace stream {


const char* StreamProperties::NAME="stream.stream-properties";
const char* StreamProperties::CLASS_NAME=stream::NAME;

StreamProperties::StreamProperties(
    const Str8& contentType_,
    const Str8& contentEncoding_,
    const Map& headers_,
    Uint8 priority_,
    const Datetime& timestamp_
) :
    contentType(contentType_),
    contentEncoding(contentEncoding_),
    headers(headers_),
    priority(priority_),
    timestamp(timestamp_){
}
void StreamProperties::accept(Visitor& v) {  v.visit(*this); }
void StreamProperties::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const StreamProperties&x) {
    o << "stream.stream-properties[";
    o << " content-type=" << x.contentType;
    o << " content-encoding=" << x.contentEncoding;
    o << " headers=" << x.headers;
    o << " priority=" << x.priority;
    o << " timestamp=" << x.timestamp;
    o << "]";
    return o;
}

} // namespace stream


namespace cluster {


} // namespace cluster


namespace cluster_connection {


} // namespace cluster_connection


}} // namespace qpid::amqp_0_10

