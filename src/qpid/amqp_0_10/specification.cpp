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
#include "qpid/amqp_0_10/exceptions.h"
#include <iostream>
#include "qpid/amqp_0_10/ApplyCommand.h"
#include "qpid/amqp_0_10/ApplyControl.h"
#include "qpid/amqp_0_10/ApplyStruct.h"

namespace qpid {
namespace amqp_0_10 {


namespace connection {

const char* NAME="connection";

const char* Start::NAME="connection.start";
const char* Start::CLASS_NAME=connection::NAME;

Start::Start(
    const Map& serverProperties_,
    const Str16Array& mechanisms_,
    const Str16Array& locales_
) :
    serverProperties(serverProperties_),
    mechanisms(mechanisms_),
    locales(locales_){
}
void Start::accept(Visitor& v) {  v.visit(*this); }
void Start::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Start&x) {
    o << "connection.start[";
    o << " server-properties=" << x.serverProperties;
    o << " mechanisms=" << x.mechanisms;
    o << " locales=" << x.locales;
    o << "]";
    return o;
}
void Start::Handler::connectionStart(
    const Map& /*serverProperties_*/,
    const Str16Array& /*mechanisms_*/,
    const Str16Array& /*locales_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.start not implemented."));
}

const char* StartOk::NAME="connection.start-ok";
const char* StartOk::CLASS_NAME=connection::NAME;

StartOk::StartOk(
    const Map& clientProperties_,
    const Str8& mechanism_,
    const Vbin32& response_,
    const Str8& locale_
) :
    clientProperties(clientProperties_),
    mechanism(mechanism_),
    response(response_),
    locale(locale_){
}
void StartOk::accept(Visitor& v) {  v.visit(*this); }
void StartOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const StartOk&x) {
    o << "connection.start-ok[";
    o << " client-properties=" << x.clientProperties;
    o << " mechanism=" << x.mechanism;
    o << " response=" << x.response;
    o << " locale=" << x.locale;
    o << "]";
    return o;
}
void StartOk::Handler::connectionStartOk(
    const Map& /*clientProperties_*/,
    const Str8& /*mechanism_*/,
    const Vbin32& /*response_*/,
    const Str8& /*locale_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.start-ok not implemented."));
}

const char* Secure::NAME="connection.secure";
const char* Secure::CLASS_NAME=connection::NAME;

Secure::Secure(const Vbin32& challenge_) :
    challenge(challenge_){
}
void Secure::accept(Visitor& v) {  v.visit(*this); }
void Secure::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Secure&x) {
    o << "connection.secure[";
    o << " challenge=" << x.challenge;
    o << "]";
    return o;
}
void Secure::Handler::connectionSecure(
    const Vbin32& /*challenge_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.secure not implemented."));
}

const char* SecureOk::NAME="connection.secure-ok";
const char* SecureOk::CLASS_NAME=connection::NAME;

SecureOk::SecureOk(const Vbin32& response_) :
    response(response_){
}
void SecureOk::accept(Visitor& v) {  v.visit(*this); }
void SecureOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const SecureOk&x) {
    o << "connection.secure-ok[";
    o << " response=" << x.response;
    o << "]";
    return o;
}
void SecureOk::Handler::connectionSecureOk(
    const Vbin32& /*response_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.secure-ok not implemented."));
}

const char* Tune::NAME="connection.tune";
const char* Tune::CLASS_NAME=connection::NAME;

Tune::Tune(
    Uint16 channelMax_,
    Uint16 maxFrameSize_,
    Uint16 heartbeatMin_,
    Uint16 heartbeatMax_
) :
    channelMax(channelMax_),
    maxFrameSize(maxFrameSize_),
    heartbeatMin(heartbeatMin_),
    heartbeatMax(heartbeatMax_){
}
void Tune::accept(Visitor& v) {  v.visit(*this); }
void Tune::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Tune&x) {
    o << "connection.tune[";
    o << " channel-max=" << x.channelMax;
    o << " max-frame-size=" << x.maxFrameSize;
    o << " heartbeat-min=" << x.heartbeatMin;
    o << " heartbeat-max=" << x.heartbeatMax;
    o << "]";
    return o;
}
void Tune::Handler::connectionTune(
    Uint16 /*channelMax_*/,
    Uint16 /*maxFrameSize_*/,
    Uint16 /*heartbeatMin_*/,
    Uint16 /*heartbeatMax_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.tune not implemented."));
}

const char* TuneOk::NAME="connection.tune-ok";
const char* TuneOk::CLASS_NAME=connection::NAME;

TuneOk::TuneOk(
    Uint16 channelMax_,
    Uint16 maxFrameSize_,
    Uint16 heartbeat_
) :
    channelMax(channelMax_),
    maxFrameSize(maxFrameSize_),
    heartbeat(heartbeat_){
}
void TuneOk::accept(Visitor& v) {  v.visit(*this); }
void TuneOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TuneOk&x) {
    o << "connection.tune-ok[";
    o << " channel-max=" << x.channelMax;
    o << " max-frame-size=" << x.maxFrameSize;
    o << " heartbeat=" << x.heartbeat;
    o << "]";
    return o;
}
void TuneOk::Handler::connectionTuneOk(
    Uint16 /*channelMax_*/,
    Uint16 /*maxFrameSize_*/,
    Uint16 /*heartbeat_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.tune-ok not implemented."));
}

const char* Open::NAME="connection.open";
const char* Open::CLASS_NAME=connection::NAME;

Open::Open(
    const Str8& virtualHost_,
    const Str16Array& capabilities_,
    Bit insist_
) :
    virtualHost(virtualHost_),
    capabilities(capabilities_),
    insist(insist_){
}
void Open::accept(Visitor& v) {  v.visit(*this); }
void Open::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Open&x) {
    o << "connection.open[";
    o << " virtual-host=" << x.virtualHost;
    o << " capabilities=" << x.capabilities;
    o << " insist=" << x.insist;
    o << "]";
    return o;
}
void Open::Handler::connectionOpen(
    const Str8& /*virtualHost_*/,
    const Str16Array& /*capabilities_*/,
    Bit /*insist_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.open not implemented."));
}

const char* OpenOk::NAME="connection.open-ok";
const char* OpenOk::CLASS_NAME=connection::NAME;

OpenOk::OpenOk(const connection::AmqpHostArray& knownHosts_) :
    knownHosts(knownHosts_){
}
void OpenOk::accept(Visitor& v) {  v.visit(*this); }
void OpenOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const OpenOk&x) {
    o << "connection.open-ok[";
    o << " known-hosts=" << x.knownHosts;
    o << "]";
    return o;
}
void OpenOk::Handler::connectionOpenOk(
    const connection::AmqpHostArray& /*knownHosts_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.open-ok not implemented."));
}

const char* Redirect::NAME="connection.redirect";
const char* Redirect::CLASS_NAME=connection::NAME;

Redirect::Redirect(
    const connection::AmqpHostUrl& host_,
    const connection::AmqpHostArray& knownHosts_
) :
    host(host_),
    knownHosts(knownHosts_){
}
void Redirect::accept(Visitor& v) {  v.visit(*this); }
void Redirect::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Redirect&x) {
    o << "connection.redirect[";
    o << " host=" << x.host;
    o << " known-hosts=" << x.knownHosts;
    o << "]";
    return o;
}
void Redirect::Handler::connectionRedirect(
    const connection::AmqpHostUrl& /*host_*/,
    const connection::AmqpHostArray& /*knownHosts_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.redirect not implemented."));
}

const char* Heartbeat::NAME="connection.heartbeat";
const char* Heartbeat::CLASS_NAME=connection::NAME;

Heartbeat::Heartbeat()
{
}
void Heartbeat::accept(Visitor& v) {  v.visit(*this); }
void Heartbeat::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Heartbeat&) {
    o << "connection.heartbeat[";
    o << "]";
    return o;
}
void Heartbeat::Handler::connectionHeartbeat(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.heartbeat not implemented."));
}

const char* Close::NAME="connection.close";
const char* Close::CLASS_NAME=connection::NAME;

Close::Close(
    const connection::CloseCode& replyCode_,
    const Str8& replyText_
) :
    replyCode(replyCode_),
    replyText(replyText_){
}
void Close::accept(Visitor& v) {  v.visit(*this); }
void Close::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Close&x) {
    o << "connection.close[";
    o << " reply-code=" << x.replyCode;
    o << " reply-text=" << x.replyText;
    o << "]";
    return o;
}
void Close::Handler::connectionClose(
    const connection::CloseCode& /*replyCode_*/,
    const Str8& /*replyText_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.close not implemented."));
}

const char* CloseOk::NAME="connection.close-ok";
const char* CloseOk::CLASS_NAME=connection::NAME;

CloseOk::CloseOk()
{
}
void CloseOk::accept(Visitor& v) {  v.visit(*this); }
void CloseOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const CloseOk&) {
    o << "connection.close-ok[";
    o << "]";
    return o;
}
void CloseOk::Handler::connectionCloseOk(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("connection.close-ok not implemented."));
}

} // namespace connection


namespace session {

const char* NAME="session";

const char* Attach::NAME="session.attach";
const char* Attach::CLASS_NAME=session::NAME;

Attach::Attach(
    const session::Name& name_,
    Bit force_
) :
    name(name_),
    force(force_){
}
void Attach::accept(Visitor& v) {  v.visit(*this); }
void Attach::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Attach&x) {
    o << "session.attach[";
    o << " name=" << x.name;
    o << " force=" << x.force;
    o << "]";
    return o;
}
void Attach::Handler::sessionAttach(
    const session::Name& /*name_*/,
    Bit /*force_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.attach not implemented."));
}

const char* Attached::NAME="session.attached";
const char* Attached::CLASS_NAME=session::NAME;

Attached::Attached(const session::Name& name_) :
    name(name_){
}
void Attached::accept(Visitor& v) {  v.visit(*this); }
void Attached::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Attached&x) {
    o << "session.attached[";
    o << " name=" << x.name;
    o << "]";
    return o;
}
void Attached::Handler::sessionAttached(
    const session::Name& /*name_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.attached not implemented."));
}

const char* Detach::NAME="session.detach";
const char* Detach::CLASS_NAME=session::NAME;

Detach::Detach(const session::Name& name_) :
    name(name_){
}
void Detach::accept(Visitor& v) {  v.visit(*this); }
void Detach::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Detach&x) {
    o << "session.detach[";
    o << " name=" << x.name;
    o << "]";
    return o;
}
void Detach::Handler::sessionDetach(
    const session::Name& /*name_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.detach not implemented."));
}

const char* Detached::NAME="session.detached";
const char* Detached::CLASS_NAME=session::NAME;

Detached::Detached(
    const session::Name& name_,
    const session::DetachCode& code_
) :
    name(name_),
    code(code_){
}
void Detached::accept(Visitor& v) {  v.visit(*this); }
void Detached::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Detached&x) {
    o << "session.detached[";
    o << " name=" << x.name;
    o << " code=" << x.code;
    o << "]";
    return o;
}
void Detached::Handler::sessionDetached(
    const session::Name& /*name_*/,
    const session::DetachCode& /*code_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.detached not implemented."));
}

const char* RequestTimeout::NAME="session.request-timeout";
const char* RequestTimeout::CLASS_NAME=session::NAME;

RequestTimeout::RequestTimeout(Uint32 timeout_) :
    timeout(timeout_){
}
void RequestTimeout::accept(Visitor& v) {  v.visit(*this); }
void RequestTimeout::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const RequestTimeout&x) {
    o << "session.request-timeout[";
    o << " timeout=" << x.timeout;
    o << "]";
    return o;
}
void RequestTimeout::Handler::sessionRequestTimeout(
    Uint32 /*timeout_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.request-timeout not implemented."));
}

const char* Timeout::NAME="session.timeout";
const char* Timeout::CLASS_NAME=session::NAME;

Timeout::Timeout(Uint32 timeout_) :
    timeout(timeout_){
}
void Timeout::accept(Visitor& v) {  v.visit(*this); }
void Timeout::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Timeout&x) {
    o << "session.timeout[";
    o << " timeout=" << x.timeout;
    o << "]";
    return o;
}
void Timeout::Handler::sessionTimeout(
    Uint32 /*timeout_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.timeout not implemented."));
}

const char* CommandPoint::NAME="session.command-point";
const char* CommandPoint::CLASS_NAME=session::NAME;

CommandPoint::CommandPoint(
    const SequenceNo& commandId_,
    Uint64 commandOffset_
) :
    commandId(commandId_),
    commandOffset(commandOffset_){
}
void CommandPoint::accept(Visitor& v) {  v.visit(*this); }
void CommandPoint::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const CommandPoint&x) {
    o << "session.command-point[";
    o << " command-id=" << x.commandId;
    o << " command-offset=" << x.commandOffset;
    o << "]";
    return o;
}
void CommandPoint::Handler::sessionCommandPoint(
    const SequenceNo& /*commandId_*/,
    Uint64 /*commandOffset_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.command-point not implemented."));
}

const char* Expected::NAME="session.expected";
const char* Expected::CLASS_NAME=session::NAME;

Expected::Expected(
    const session::Commands& commands_,
    const session::CommandFragments& fragments_
) :
    commands(commands_),
    fragments(fragments_){
}
void Expected::accept(Visitor& v) {  v.visit(*this); }
void Expected::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Expected&x) {
    o << "session.expected[";
    o << " commands=" << x.commands;
    o << " fragments=" << x.fragments;
    o << "]";
    return o;
}
void Expected::Handler::sessionExpected(
    const session::Commands& /*commands_*/,
    const session::CommandFragments& /*fragments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.expected not implemented."));
}

const char* Confirmed::NAME="session.confirmed";
const char* Confirmed::CLASS_NAME=session::NAME;

Confirmed::Confirmed(
    const session::Commands& commands_,
    const session::CommandFragments& fragments_
) :
    commands(commands_),
    fragments(fragments_){
}
void Confirmed::accept(Visitor& v) {  v.visit(*this); }
void Confirmed::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Confirmed&x) {
    o << "session.confirmed[";
    o << " commands=" << x.commands;
    o << " fragments=" << x.fragments;
    o << "]";
    return o;
}
void Confirmed::Handler::sessionConfirmed(
    const session::Commands& /*commands_*/,
    const session::CommandFragments& /*fragments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.confirmed not implemented."));
}

const char* Completed::NAME="session.completed";
const char* Completed::CLASS_NAME=session::NAME;

Completed::Completed(
    const session::Commands& commands_,
    Bit timelyReply_
) :
    commands(commands_),
    timelyReply(timelyReply_){
}
void Completed::accept(Visitor& v) {  v.visit(*this); }
void Completed::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Completed&x) {
    o << "session.completed[";
    o << " commands=" << x.commands;
    o << " timely-reply=" << x.timelyReply;
    o << "]";
    return o;
}
void Completed::Handler::sessionCompleted(
    const session::Commands& /*commands_*/,
    Bit /*timelyReply_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.completed not implemented."));
}

const char* KnownCompleted::NAME="session.known-completed";
const char* KnownCompleted::CLASS_NAME=session::NAME;

KnownCompleted::KnownCompleted(const session::Commands& commands_) :
    commands(commands_){
}
void KnownCompleted::accept(Visitor& v) {  v.visit(*this); }
void KnownCompleted::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const KnownCompleted&x) {
    o << "session.known-completed[";
    o << " commands=" << x.commands;
    o << "]";
    return o;
}
void KnownCompleted::Handler::sessionKnownCompleted(
    const session::Commands& /*commands_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.known-completed not implemented."));
}

const char* Flush::NAME="session.flush";
const char* Flush::CLASS_NAME=session::NAME;

Flush::Flush(
    Bit expected_,
    Bit confirmed_,
    Bit completed_
) :
    expected(expected_),
    confirmed(confirmed_),
    completed(completed_){
}
void Flush::accept(Visitor& v) {  v.visit(*this); }
void Flush::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Flush&x) {
    o << "session.flush[";
    o << " expected=" << x.expected;
    o << " confirmed=" << x.confirmed;
    o << " completed=" << x.completed;
    o << "]";
    return o;
}
void Flush::Handler::sessionFlush(
    Bit /*expected_*/,
    Bit /*confirmed_*/,
    Bit /*completed_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.flush not implemented."));
}

const char* Gap::NAME="session.gap";
const char* Gap::CLASS_NAME=session::NAME;

Gap::Gap(const session::Commands& commands_) :
    commands(commands_){
}
void Gap::accept(Visitor& v) {  v.visit(*this); }
void Gap::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Gap&x) {
    o << "session.gap[";
    o << " commands=" << x.commands;
    o << "]";
    return o;
}
void Gap::Handler::sessionGap(
    const session::Commands& /*commands_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("session.gap not implemented."));
}

} // namespace session


namespace execution {

const char* NAME="execution";

const char* Sync::NAME="execution.sync";
const char* Sync::CLASS_NAME=execution::NAME;

Sync::Sync()
{
}
void Sync::accept(Visitor& v) {  v.visit(*this); }
void Sync::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Sync&) {
    o << "execution.sync[";
    o << "]";
    return o;
}
void Sync::Handler::executionSync(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("execution.sync not implemented."));
}

const char* Result::NAME="execution.result";
const char* Result::CLASS_NAME=execution::NAME;

Result::Result(
    const SequenceNo& commandId_,
    const Struct32& value_
) :
    commandId(commandId_),
    value(value_){
}
void Result::accept(Visitor& v) {  v.visit(*this); }
void Result::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Result&x) {
    o << "execution.result[";
    o << " command-id=" << x.commandId;
    o << " value=" << x.value;
    o << "]";
    return o;
}
void Result::Handler::executionResult(
    const SequenceNo& /*commandId_*/,
    const Struct32& /*value_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("execution.result not implemented."));
}

const char* Exception::NAME="execution.exception";
const char* Exception::CLASS_NAME=execution::NAME;

Exception::Exception(
    const execution::ErrorCode& errorCode_,
    const SequenceNo& commandId_,
    Uint8 classCode_,
    Uint8 commandCode_,
    Uint8 fieldIndex_,
    const Str16& description_,
    const Map& errorInfo_
) :
    errorCode(errorCode_),
    commandId(commandId_),
    classCode(classCode_),
    commandCode(commandCode_),
    fieldIndex(fieldIndex_),
    description(description_),
    errorInfo(errorInfo_){
}
void Exception::accept(Visitor& v) {  v.visit(*this); }
void Exception::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Exception&x) {
    o << "execution.exception[";
    o << " error-code=" << x.errorCode;
    o << " command-id=" << x.commandId;
    o << " class-code=" << x.classCode;
    o << " command-code=" << x.commandCode;
    o << " field-index=" << x.fieldIndex;
    o << " description=" << x.description;
    o << " error-info=" << x.errorInfo;
    o << "]";
    return o;
}
void Exception::Handler::executionException(
    const execution::ErrorCode& /*errorCode_*/,
    const SequenceNo& /*commandId_*/,
    Uint8 /*classCode_*/,
    Uint8 /*commandCode_*/,
    Uint8 /*fieldIndex_*/,
    const Str16& /*description_*/,
    const Map& /*errorInfo_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("execution.exception not implemented."));
}

} // namespace execution


namespace message {

const char* NAME="message";

const char* Transfer::NAME="message.transfer";
const char* Transfer::CLASS_NAME=message::NAME;

Transfer::Transfer(
    const message::Destination& destination_,
    const message::AcceptMode& acceptMode_,
    const message::AcquireMode& acquireMode_
) :
    destination(destination_),
    acceptMode(acceptMode_),
    acquireMode(acquireMode_){
}
void Transfer::accept(Visitor& v) {  v.visit(*this); }
void Transfer::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Transfer&x) {
    o << "message.transfer[";
    o << " destination=" << x.destination;
    o << " accept-mode=" << x.acceptMode;
    o << " acquire-mode=" << x.acquireMode;
    o << "]";
    return o;
}
void Transfer::Handler::messageTransfer(
    const message::Destination& /*destination_*/,
    const message::AcceptMode& /*acceptMode_*/,
    const message::AcquireMode& /*acquireMode_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.transfer not implemented."));
}

const char* Accept::NAME="message.accept";
const char* Accept::CLASS_NAME=message::NAME;

Accept::Accept(const session::Commands& transfers_) :
    transfers(transfers_){
}
void Accept::accept(Visitor& v) {  v.visit(*this); }
void Accept::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Accept&x) {
    o << "message.accept[";
    o << " transfers=" << x.transfers;
    o << "]";
    return o;
}
void Accept::Handler::messageAccept(
    const session::Commands& /*transfers_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.accept not implemented."));
}

const char* Reject::NAME="message.reject";
const char* Reject::CLASS_NAME=message::NAME;

Reject::Reject(
    const session::Commands& transfers_,
    const message::RejectCode& code_,
    const Str8& text_
) :
    transfers(transfers_),
    code(code_),
    text(text_){
}
void Reject::accept(Visitor& v) {  v.visit(*this); }
void Reject::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Reject&x) {
    o << "message.reject[";
    o << " transfers=" << x.transfers;
    o << " code=" << x.code;
    o << " text=" << x.text;
    o << "]";
    return o;
}
void Reject::Handler::messageReject(
    const session::Commands& /*transfers_*/,
    const message::RejectCode& /*code_*/,
    const Str8& /*text_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.reject not implemented."));
}

const char* Release::NAME="message.release";
const char* Release::CLASS_NAME=message::NAME;

Release::Release(
    const session::Commands& transfers_,
    Bit setRedelivered_
) :
    transfers(transfers_),
    setRedelivered(setRedelivered_){
}
void Release::accept(Visitor& v) {  v.visit(*this); }
void Release::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Release&x) {
    o << "message.release[";
    o << " transfers=" << x.transfers;
    o << " set-redelivered=" << x.setRedelivered;
    o << "]";
    return o;
}
void Release::Handler::messageRelease(
    const session::Commands& /*transfers_*/,
    Bit /*setRedelivered_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.release not implemented."));
}

const char* Acquire::NAME="message.acquire";
const char* Acquire::CLASS_NAME=message::NAME;

Acquire::Acquire(const session::Commands& transfers_) :
    transfers(transfers_){
}
void Acquire::accept(Visitor& v) {  v.visit(*this); }
void Acquire::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Acquire&x) {
    o << "message.acquire[";
    o << " transfers=" << x.transfers;
    o << "]";
    return o;
}
void Acquire::Handler::messageAcquire(
    const session::Commands& /*transfers_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.acquire not implemented."));
}

const char* Resume::NAME="message.resume";
const char* Resume::CLASS_NAME=message::NAME;

Resume::Resume(
    const message::Destination& destination_,
    const message::ResumeId& resumeId_
) :
    destination(destination_),
    resumeId(resumeId_){
}
void Resume::accept(Visitor& v) {  v.visit(*this); }
void Resume::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Resume&x) {
    o << "message.resume[";
    o << " destination=" << x.destination;
    o << " resume-id=" << x.resumeId;
    o << "]";
    return o;
}
void Resume::Handler::messageResume(
    const message::Destination& /*destination_*/,
    const message::ResumeId& /*resumeId_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.resume not implemented."));
}

const char* Subscribe::NAME="message.subscribe";
const char* Subscribe::CLASS_NAME=message::NAME;

Subscribe::Subscribe(
    const queue::Name& queue_,
    const message::Destination& destination_,
    const message::AcceptMode& acceptMode_,
    const message::AcquireMode& acquireMode_,
    Bit exclusive_,
    const message::ResumeId& resumeId_,
    Uint64 resumeTtl_,
    const Map& arguments_
) :
    queue(queue_),
    destination(destination_),
    acceptMode(acceptMode_),
    acquireMode(acquireMode_),
    exclusive(exclusive_),
    resumeId(resumeId_),
    resumeTtl(resumeTtl_),
    arguments(arguments_){
}
void Subscribe::accept(Visitor& v) {  v.visit(*this); }
void Subscribe::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Subscribe&x) {
    o << "message.subscribe[";
    o << " queue=" << x.queue;
    o << " destination=" << x.destination;
    o << " accept-mode=" << x.acceptMode;
    o << " acquire-mode=" << x.acquireMode;
    o << " exclusive=" << x.exclusive;
    o << " resume-id=" << x.resumeId;
    o << " resume-ttl=" << x.resumeTtl;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Subscribe::Handler::messageSubscribe(
    const queue::Name& /*queue_*/,
    const message::Destination& /*destination_*/,
    const message::AcceptMode& /*acceptMode_*/,
    const message::AcquireMode& /*acquireMode_*/,
    Bit /*exclusive_*/,
    const message::ResumeId& /*resumeId_*/,
    Uint64 /*resumeTtl_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.subscribe not implemented."));
}

const char* Cancel::NAME="message.cancel";
const char* Cancel::CLASS_NAME=message::NAME;

Cancel::Cancel(const message::Destination& destination_) :
    destination(destination_){
}
void Cancel::accept(Visitor& v) {  v.visit(*this); }
void Cancel::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Cancel&x) {
    o << "message.cancel[";
    o << " destination=" << x.destination;
    o << "]";
    return o;
}
void Cancel::Handler::messageCancel(
    const message::Destination& /*destination_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.cancel not implemented."));
}

const char* SetFlowMode::NAME="message.set-flow-mode";
const char* SetFlowMode::CLASS_NAME=message::NAME;

SetFlowMode::SetFlowMode(
    const message::Destination& destination_,
    const message::FlowMode& flowMode_
) :
    destination(destination_),
    flowMode(flowMode_){
}
void SetFlowMode::accept(Visitor& v) {  v.visit(*this); }
void SetFlowMode::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const SetFlowMode&x) {
    o << "message.set-flow-mode[";
    o << " destination=" << x.destination;
    o << " flow-mode=" << x.flowMode;
    o << "]";
    return o;
}
void SetFlowMode::Handler::messageSetFlowMode(
    const message::Destination& /*destination_*/,
    const message::FlowMode& /*flowMode_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.set-flow-mode not implemented."));
}

const char* Flow::NAME="message.flow";
const char* Flow::CLASS_NAME=message::NAME;

Flow::Flow(
    const message::Destination& destination_,
    const message::CreditUnit& unit_,
    Uint32 value_
) :
    destination(destination_),
    unit(unit_),
    value(value_){
}
void Flow::accept(Visitor& v) {  v.visit(*this); }
void Flow::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Flow&x) {
    o << "message.flow[";
    o << " destination=" << x.destination;
    o << " unit=" << x.unit;
    o << " value=" << x.value;
    o << "]";
    return o;
}
void Flow::Handler::messageFlow(
    const message::Destination& /*destination_*/,
    const message::CreditUnit& /*unit_*/,
    Uint32 /*value_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.flow not implemented."));
}

const char* Flush::NAME="message.flush";
const char* Flush::CLASS_NAME=message::NAME;

Flush::Flush(const message::Destination& destination_) :
    destination(destination_){
}
void Flush::accept(Visitor& v) {  v.visit(*this); }
void Flush::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Flush&x) {
    o << "message.flush[";
    o << " destination=" << x.destination;
    o << "]";
    return o;
}
void Flush::Handler::messageFlush(
    const message::Destination& /*destination_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.flush not implemented."));
}

const char* Stop::NAME="message.stop";
const char* Stop::CLASS_NAME=message::NAME;

Stop::Stop(const message::Destination& destination_) :
    destination(destination_){
}
void Stop::accept(Visitor& v) {  v.visit(*this); }
void Stop::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Stop&x) {
    o << "message.stop[";
    o << " destination=" << x.destination;
    o << "]";
    return o;
}
void Stop::Handler::messageStop(
    const message::Destination& /*destination_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("message.stop not implemented."));
}

} // namespace message


namespace tx {

const char* NAME="tx";

const char* Select::NAME="tx.select";
const char* Select::CLASS_NAME=tx::NAME;

Select::Select()
{
}
void Select::accept(Visitor& v) {  v.visit(*this); }
void Select::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Select&) {
    o << "tx.select[";
    o << "]";
    return o;
}
void Select::Handler::txSelect(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("tx.select not implemented."));
}

const char* Commit::NAME="tx.commit";
const char* Commit::CLASS_NAME=tx::NAME;

Commit::Commit()
{
}
void Commit::accept(Visitor& v) {  v.visit(*this); }
void Commit::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Commit&) {
    o << "tx.commit[";
    o << "]";
    return o;
}
void Commit::Handler::txCommit(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("tx.commit not implemented."));
}

const char* Rollback::NAME="tx.rollback";
const char* Rollback::CLASS_NAME=tx::NAME;

Rollback::Rollback()
{
}
void Rollback::accept(Visitor& v) {  v.visit(*this); }
void Rollback::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Rollback&) {
    o << "tx.rollback[";
    o << "]";
    return o;
}
void Rollback::Handler::txRollback(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("tx.rollback not implemented."));
}

} // namespace tx


namespace dtx {

const char* NAME="dtx";

const char* Select::NAME="dtx.select";
const char* Select::CLASS_NAME=dtx::NAME;

Select::Select()
{
}
void Select::accept(Visitor& v) {  v.visit(*this); }
void Select::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Select&) {
    o << "dtx.select[";
    o << "]";
    return o;
}
void Select::Handler::dtxSelect(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.select not implemented."));
}

const char* Start::NAME="dtx.start";
const char* Start::CLASS_NAME=dtx::NAME;

Start::Start(
    const dtx::Xid& xid_,
    Bit join_,
    Bit resume_
) :
    xid(xid_),
    join(join_),
    resume(resume_){
}
void Start::accept(Visitor& v) {  v.visit(*this); }
void Start::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Start&x) {
    o << "dtx.start[";
    o << " xid=" << x.xid;
    o << " join=" << x.join;
    o << " resume=" << x.resume;
    o << "]";
    return o;
}
void Start::Handler::dtxStart(
    const dtx::Xid& /*xid_*/,
    Bit /*join_*/,
    Bit /*resume_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.start not implemented."));
}

const char* End::NAME="dtx.end";
const char* End::CLASS_NAME=dtx::NAME;

End::End(
    const dtx::Xid& xid_,
    Bit fail_,
    Bit suspend_
) :
    xid(xid_),
    fail(fail_),
    suspend(suspend_){
}
void End::accept(Visitor& v) {  v.visit(*this); }
void End::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const End&x) {
    o << "dtx.end[";
    o << " xid=" << x.xid;
    o << " fail=" << x.fail;
    o << " suspend=" << x.suspend;
    o << "]";
    return o;
}
void End::Handler::dtxEnd(
    const dtx::Xid& /*xid_*/,
    Bit /*fail_*/,
    Bit /*suspend_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.end not implemented."));
}

const char* Commit::NAME="dtx.commit";
const char* Commit::CLASS_NAME=dtx::NAME;

Commit::Commit(
    const dtx::Xid& xid_,
    Bit onePhase_
) :
    xid(xid_),
    onePhase(onePhase_){
}
void Commit::accept(Visitor& v) {  v.visit(*this); }
void Commit::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Commit&x) {
    o << "dtx.commit[";
    o << " xid=" << x.xid;
    o << " one-phase=" << x.onePhase;
    o << "]";
    return o;
}
void Commit::Handler::dtxCommit(
    const dtx::Xid& /*xid_*/,
    Bit /*onePhase_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.commit not implemented."));
}

const char* Forget::NAME="dtx.forget";
const char* Forget::CLASS_NAME=dtx::NAME;

Forget::Forget(const dtx::Xid& xid_) :
    xid(xid_){
}
void Forget::accept(Visitor& v) {  v.visit(*this); }
void Forget::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Forget&x) {
    o << "dtx.forget[";
    o << " xid=" << x.xid;
    o << "]";
    return o;
}
void Forget::Handler::dtxForget(
    const dtx::Xid& /*xid_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.forget not implemented."));
}

const char* GetTimeout::NAME="dtx.get-timeout";
const char* GetTimeout::CLASS_NAME=dtx::NAME;

GetTimeout::GetTimeout(const dtx::Xid& xid_) :
    xid(xid_){
}
void GetTimeout::accept(Visitor& v) {  v.visit(*this); }
void GetTimeout::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const GetTimeout&x) {
    o << "dtx.get-timeout[";
    o << " xid=" << x.xid;
    o << "]";
    return o;
}
void GetTimeout::Handler::dtxGetTimeout(
    const dtx::Xid& /*xid_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.get-timeout not implemented."));
}

const char* Prepare::NAME="dtx.prepare";
const char* Prepare::CLASS_NAME=dtx::NAME;

Prepare::Prepare(const dtx::Xid& xid_) :
    xid(xid_){
}
void Prepare::accept(Visitor& v) {  v.visit(*this); }
void Prepare::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Prepare&x) {
    o << "dtx.prepare[";
    o << " xid=" << x.xid;
    o << "]";
    return o;
}
void Prepare::Handler::dtxPrepare(
    const dtx::Xid& /*xid_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.prepare not implemented."));
}

const char* Recover::NAME="dtx.recover";
const char* Recover::CLASS_NAME=dtx::NAME;

Recover::Recover()
{
}
void Recover::accept(Visitor& v) {  v.visit(*this); }
void Recover::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Recover&) {
    o << "dtx.recover[";
    o << "]";
    return o;
}
void Recover::Handler::dtxRecover(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.recover not implemented."));
}

const char* Rollback::NAME="dtx.rollback";
const char* Rollback::CLASS_NAME=dtx::NAME;

Rollback::Rollback(const dtx::Xid& xid_) :
    xid(xid_){
}
void Rollback::accept(Visitor& v) {  v.visit(*this); }
void Rollback::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Rollback&x) {
    o << "dtx.rollback[";
    o << " xid=" << x.xid;
    o << "]";
    return o;
}
void Rollback::Handler::dtxRollback(
    const dtx::Xid& /*xid_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.rollback not implemented."));
}

const char* SetTimeout::NAME="dtx.set-timeout";
const char* SetTimeout::CLASS_NAME=dtx::NAME;

SetTimeout::SetTimeout(
    const dtx::Xid& xid_,
    Uint32 timeout_
) :
    xid(xid_),
    timeout(timeout_){
}
void SetTimeout::accept(Visitor& v) {  v.visit(*this); }
void SetTimeout::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const SetTimeout&x) {
    o << "dtx.set-timeout[";
    o << " xid=" << x.xid;
    o << " timeout=" << x.timeout;
    o << "]";
    return o;
}
void SetTimeout::Handler::dtxSetTimeout(
    const dtx::Xid& /*xid_*/,
    Uint32 /*timeout_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("dtx.set-timeout not implemented."));
}

} // namespace dtx


namespace exchange {

const char* NAME="exchange";

const char* Declare::NAME="exchange.declare";
const char* Declare::CLASS_NAME=exchange::NAME;

Declare::Declare(
    const exchange::Name& exchange_,
    const Str8& type_,
    const exchange::Name& alternateExchange_,
    Bit passive_,
    Bit durable_,
    Bit autoDelete_,
    const Map& arguments_
) :
    exchange(exchange_),
    type(type_),
    alternateExchange(alternateExchange_),
    passive(passive_),
    durable(durable_),
    autoDelete(autoDelete_),
    arguments(arguments_){
}
void Declare::accept(Visitor& v) {  v.visit(*this); }
void Declare::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Declare&x) {
    o << "exchange.declare[";
    o << " exchange=" << x.exchange;
    o << " type=" << x.type;
    o << " alternate-exchange=" << x.alternateExchange;
    o << " passive=" << x.passive;
    o << " durable=" << x.durable;
    o << " auto-delete=" << x.autoDelete;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Declare::Handler::exchangeDeclare(
    const exchange::Name& /*exchange_*/,
    const Str8& /*type_*/,
    const exchange::Name& /*alternateExchange_*/,
    Bit /*passive_*/,
    Bit /*durable_*/,
    Bit /*autoDelete_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("exchange.declare not implemented."));
}

const char* Delete::NAME="exchange.delete";
const char* Delete::CLASS_NAME=exchange::NAME;

Delete::Delete(
    const exchange::Name& exchange_,
    Bit ifUnused_
) :
    exchange(exchange_),
    ifUnused(ifUnused_){
}
void Delete::accept(Visitor& v) {  v.visit(*this); }
void Delete::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Delete&x) {
    o << "exchange.delete[";
    o << " exchange=" << x.exchange;
    o << " if-unused=" << x.ifUnused;
    o << "]";
    return o;
}
void Delete::Handler::exchangeDelete(
    const exchange::Name& /*exchange_*/,
    Bit /*ifUnused_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("exchange.delete not implemented."));
}

const char* Query::NAME="exchange.query";
const char* Query::CLASS_NAME=exchange::NAME;

Query::Query(const Str8& name_) :
    name(name_){
}
void Query::accept(Visitor& v) {  v.visit(*this); }
void Query::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Query&x) {
    o << "exchange.query[";
    o << " name=" << x.name;
    o << "]";
    return o;
}
void Query::Handler::exchangeQuery(
    const Str8& /*name_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("exchange.query not implemented."));
}

const char* Bind::NAME="exchange.bind";
const char* Bind::CLASS_NAME=exchange::NAME;

Bind::Bind(
    const queue::Name& queue_,
    const exchange::Name& exchange_,
    const Str8& bindingKey_,
    const Map& arguments_
) :
    queue(queue_),
    exchange(exchange_),
    bindingKey(bindingKey_),
    arguments(arguments_){
}
void Bind::accept(Visitor& v) {  v.visit(*this); }
void Bind::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Bind&x) {
    o << "exchange.bind[";
    o << " queue=" << x.queue;
    o << " exchange=" << x.exchange;
    o << " binding-key=" << x.bindingKey;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Bind::Handler::exchangeBind(
    const queue::Name& /*queue_*/,
    const exchange::Name& /*exchange_*/,
    const Str8& /*bindingKey_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("exchange.bind not implemented."));
}

const char* Unbind::NAME="exchange.unbind";
const char* Unbind::CLASS_NAME=exchange::NAME;

Unbind::Unbind(
    const queue::Name& queue_,
    const exchange::Name& exchange_,
    const Str8& bindingKey_
) :
    queue(queue_),
    exchange(exchange_),
    bindingKey(bindingKey_){
}
void Unbind::accept(Visitor& v) {  v.visit(*this); }
void Unbind::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Unbind&x) {
    o << "exchange.unbind[";
    o << " queue=" << x.queue;
    o << " exchange=" << x.exchange;
    o << " binding-key=" << x.bindingKey;
    o << "]";
    return o;
}
void Unbind::Handler::exchangeUnbind(
    const queue::Name& /*queue_*/,
    const exchange::Name& /*exchange_*/,
    const Str8& /*bindingKey_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("exchange.unbind not implemented."));
}

const char* Bound::NAME="exchange.bound";
const char* Bound::CLASS_NAME=exchange::NAME;

Bound::Bound(
    const Str8& exchange_,
    const Str8& queue_,
    const Str8& bindingKey_,
    const Map& arguments_
) :
    exchange(exchange_),
    queue(queue_),
    bindingKey(bindingKey_),
    arguments(arguments_){
}
void Bound::accept(Visitor& v) {  v.visit(*this); }
void Bound::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Bound&x) {
    o << "exchange.bound[";
    o << " exchange=" << x.exchange;
    o << " queue=" << x.queue;
    o << " binding-key=" << x.bindingKey;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Bound::Handler::exchangeBound(
    const Str8& /*exchange_*/,
    const Str8& /*queue_*/,
    const Str8& /*bindingKey_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("exchange.bound not implemented."));
}

} // namespace exchange


namespace queue {

const char* NAME="queue";

const char* Declare::NAME="queue.declare";
const char* Declare::CLASS_NAME=queue::NAME;

Declare::Declare(
    const queue::Name& queue_,
    const exchange::Name& alternateExchange_,
    Bit passive_,
    Bit durable_,
    Bit exclusive_,
    Bit autoDelete_,
    const Map& arguments_
) :
    queue(queue_),
    alternateExchange(alternateExchange_),
    passive(passive_),
    durable(durable_),
    exclusive(exclusive_),
    autoDelete(autoDelete_),
    arguments(arguments_){
}
void Declare::accept(Visitor& v) {  v.visit(*this); }
void Declare::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Declare&x) {
    o << "queue.declare[";
    o << " queue=" << x.queue;
    o << " alternate-exchange=" << x.alternateExchange;
    o << " passive=" << x.passive;
    o << " durable=" << x.durable;
    o << " exclusive=" << x.exclusive;
    o << " auto-delete=" << x.autoDelete;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Declare::Handler::queueDeclare(
    const queue::Name& /*queue_*/,
    const exchange::Name& /*alternateExchange_*/,
    Bit /*passive_*/,
    Bit /*durable_*/,
    Bit /*exclusive_*/,
    Bit /*autoDelete_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("queue.declare not implemented."));
}

const char* Delete::NAME="queue.delete";
const char* Delete::CLASS_NAME=queue::NAME;

Delete::Delete(
    const queue::Name& queue_,
    Bit ifUnused_,
    Bit ifEmpty_
) :
    queue(queue_),
    ifUnused(ifUnused_),
    ifEmpty(ifEmpty_){
}
void Delete::accept(Visitor& v) {  v.visit(*this); }
void Delete::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Delete&x) {
    o << "queue.delete[";
    o << " queue=" << x.queue;
    o << " if-unused=" << x.ifUnused;
    o << " if-empty=" << x.ifEmpty;
    o << "]";
    return o;
}
void Delete::Handler::queueDelete(
    const queue::Name& /*queue_*/,
    Bit /*ifUnused_*/,
    Bit /*ifEmpty_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("queue.delete not implemented."));
}

const char* Purge::NAME="queue.purge";
const char* Purge::CLASS_NAME=queue::NAME;

Purge::Purge(const queue::Name& queue_) :
    queue(queue_){
}
void Purge::accept(Visitor& v) {  v.visit(*this); }
void Purge::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Purge&x) {
    o << "queue.purge[";
    o << " queue=" << x.queue;
    o << "]";
    return o;
}
void Purge::Handler::queuePurge(
    const queue::Name& /*queue_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("queue.purge not implemented."));
}

const char* Query::NAME="queue.query";
const char* Query::CLASS_NAME=queue::NAME;

Query::Query(const queue::Name& queue_) :
    queue(queue_){
}
void Query::accept(Visitor& v) {  v.visit(*this); }
void Query::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Query&x) {
    o << "queue.query[";
    o << " queue=" << x.queue;
    o << "]";
    return o;
}
void Query::Handler::queueQuery(
    const queue::Name& /*queue_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("queue.query not implemented."));
}

} // namespace queue


namespace file {

const char* NAME="file";

const char* Qos::NAME="file.qos";
const char* Qos::CLASS_NAME=file::NAME;

Qos::Qos(
    Uint32 prefetchSize_,
    Uint16 prefetchCount_,
    Bit global_
) :
    prefetchSize(prefetchSize_),
    prefetchCount(prefetchCount_),
    global(global_){
}
void Qos::accept(Visitor& v) {  v.visit(*this); }
void Qos::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Qos&x) {
    o << "file.qos[";
    o << " prefetch-size=" << x.prefetchSize;
    o << " prefetch-count=" << x.prefetchCount;
    o << " global=" << x.global;
    o << "]";
    return o;
}
void Qos::Handler::fileQos(
    Uint32 /*prefetchSize_*/,
    Uint16 /*prefetchCount_*/,
    Bit /*global_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.qos not implemented."));
}

const char* QosOk::NAME="file.qos-ok";
const char* QosOk::CLASS_NAME=file::NAME;

QosOk::QosOk()
{
}
void QosOk::accept(Visitor& v) {  v.visit(*this); }
void QosOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QosOk&) {
    o << "file.qos-ok[";
    o << "]";
    return o;
}
void QosOk::Handler::fileQosOk(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.qos-ok not implemented."));
}

const char* Consume::NAME="file.consume";
const char* Consume::CLASS_NAME=file::NAME;

Consume::Consume(
    const queue::Name& queue_,
    const Str8& consumerTag_,
    Bit noLocal_,
    Bit noAck_,
    Bit exclusive_,
    Bit nowait_,
    const Map& arguments_
) :
    queue(queue_),
    consumerTag(consumerTag_),
    noLocal(noLocal_),
    noAck(noAck_),
    exclusive(exclusive_),
    nowait(nowait_),
    arguments(arguments_){
}
void Consume::accept(Visitor& v) {  v.visit(*this); }
void Consume::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Consume&x) {
    o << "file.consume[";
    o << " queue=" << x.queue;
    o << " consumer-tag=" << x.consumerTag;
    o << " no-local=" << x.noLocal;
    o << " no-ack=" << x.noAck;
    o << " exclusive=" << x.exclusive;
    o << " nowait=" << x.nowait;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Consume::Handler::fileConsume(
    const queue::Name& /*queue_*/,
    const Str8& /*consumerTag_*/,
    Bit /*noLocal_*/,
    Bit /*noAck_*/,
    Bit /*exclusive_*/,
    Bit /*nowait_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.consume not implemented."));
}

const char* ConsumeOk::NAME="file.consume-ok";
const char* ConsumeOk::CLASS_NAME=file::NAME;

ConsumeOk::ConsumeOk(const Str8& consumerTag_) :
    consumerTag(consumerTag_){
}
void ConsumeOk::accept(Visitor& v) {  v.visit(*this); }
void ConsumeOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ConsumeOk&x) {
    o << "file.consume-ok[";
    o << " consumer-tag=" << x.consumerTag;
    o << "]";
    return o;
}
void ConsumeOk::Handler::fileConsumeOk(
    const Str8& /*consumerTag_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.consume-ok not implemented."));
}

const char* Cancel::NAME="file.cancel";
const char* Cancel::CLASS_NAME=file::NAME;

Cancel::Cancel(const Str8& consumerTag_) :
    consumerTag(consumerTag_){
}
void Cancel::accept(Visitor& v) {  v.visit(*this); }
void Cancel::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Cancel&x) {
    o << "file.cancel[";
    o << " consumer-tag=" << x.consumerTag;
    o << "]";
    return o;
}
void Cancel::Handler::fileCancel(
    const Str8& /*consumerTag_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.cancel not implemented."));
}

const char* Open::NAME="file.open";
const char* Open::CLASS_NAME=file::NAME;

Open::Open(
    const Str8& identifier_,
    Uint64 contentSize_
) :
    identifier(identifier_),
    contentSize(contentSize_){
}
void Open::accept(Visitor& v) {  v.visit(*this); }
void Open::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Open&x) {
    o << "file.open[";
    o << " identifier=" << x.identifier;
    o << " content-size=" << x.contentSize;
    o << "]";
    return o;
}
void Open::Handler::fileOpen(
    const Str8& /*identifier_*/,
    Uint64 /*contentSize_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.open not implemented."));
}

const char* OpenOk::NAME="file.open-ok";
const char* OpenOk::CLASS_NAME=file::NAME;

OpenOk::OpenOk(Uint64 stagedSize_) :
    stagedSize(stagedSize_){
}
void OpenOk::accept(Visitor& v) {  v.visit(*this); }
void OpenOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const OpenOk&x) {
    o << "file.open-ok[";
    o << " staged-size=" << x.stagedSize;
    o << "]";
    return o;
}
void OpenOk::Handler::fileOpenOk(
    Uint64 /*stagedSize_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.open-ok not implemented."));
}

const char* Stage::NAME="file.stage";
const char* Stage::CLASS_NAME=file::NAME;

Stage::Stage()
{
}
void Stage::accept(Visitor& v) {  v.visit(*this); }
void Stage::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Stage&) {
    o << "file.stage[";
    o << "]";
    return o;
}
void Stage::Handler::fileStage(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.stage not implemented."));
}

const char* Publish::NAME="file.publish";
const char* Publish::CLASS_NAME=file::NAME;

Publish::Publish(
    const exchange::Name& exchange_,
    const Str8& routingKey_,
    Bit mandatory_,
    Bit immediate_,
    const Str8& identifier_
) :
    exchange(exchange_),
    routingKey(routingKey_),
    mandatory(mandatory_),
    immediate(immediate_),
    identifier(identifier_){
}
void Publish::accept(Visitor& v) {  v.visit(*this); }
void Publish::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Publish&x) {
    o << "file.publish[";
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << " mandatory=" << x.mandatory;
    o << " immediate=" << x.immediate;
    o << " identifier=" << x.identifier;
    o << "]";
    return o;
}
void Publish::Handler::filePublish(
    const exchange::Name& /*exchange_*/,
    const Str8& /*routingKey_*/,
    Bit /*mandatory_*/,
    Bit /*immediate_*/,
    const Str8& /*identifier_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.publish not implemented."));
}

const char* Return::NAME="file.return";
const char* Return::CLASS_NAME=file::NAME;

Return::Return(
    const file::ReturnCode& replyCode_,
    const Str8& replyText_,
    const exchange::Name& exchange_,
    const Str8& routingKey_
) :
    replyCode(replyCode_),
    replyText(replyText_),
    exchange(exchange_),
    routingKey(routingKey_){
}
void Return::accept(Visitor& v) {  v.visit(*this); }
void Return::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Return&x) {
    o << "file.return[";
    o << " reply-code=" << x.replyCode;
    o << " reply-text=" << x.replyText;
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << "]";
    return o;
}
void Return::Handler::fileReturn(
    const file::ReturnCode& /*replyCode_*/,
    const Str8& /*replyText_*/,
    const exchange::Name& /*exchange_*/,
    const Str8& /*routingKey_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.return not implemented."));
}

const char* Deliver::NAME="file.deliver";
const char* Deliver::CLASS_NAME=file::NAME;

Deliver::Deliver(
    const Str8& consumerTag_,
    Uint64 deliveryTag_,
    Bit redelivered_,
    const exchange::Name& exchange_,
    const Str8& routingKey_,
    const Str8& identifier_
) :
    consumerTag(consumerTag_),
    deliveryTag(deliveryTag_),
    redelivered(redelivered_),
    exchange(exchange_),
    routingKey(routingKey_),
    identifier(identifier_){
}
void Deliver::accept(Visitor& v) {  v.visit(*this); }
void Deliver::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Deliver&x) {
    o << "file.deliver[";
    o << " consumer-tag=" << x.consumerTag;
    o << " delivery-tag=" << x.deliveryTag;
    o << " redelivered=" << x.redelivered;
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << " identifier=" << x.identifier;
    o << "]";
    return o;
}
void Deliver::Handler::fileDeliver(
    const Str8& /*consumerTag_*/,
    Uint64 /*deliveryTag_*/,
    Bit /*redelivered_*/,
    const exchange::Name& /*exchange_*/,
    const Str8& /*routingKey_*/,
    const Str8& /*identifier_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.deliver not implemented."));
}

const char* Ack::NAME="file.ack";
const char* Ack::CLASS_NAME=file::NAME;

Ack::Ack(
    Uint64 deliveryTag_,
    Bit multiple_
) :
    deliveryTag(deliveryTag_),
    multiple(multiple_){
}
void Ack::accept(Visitor& v) {  v.visit(*this); }
void Ack::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Ack&x) {
    o << "file.ack[";
    o << " delivery-tag=" << x.deliveryTag;
    o << " multiple=" << x.multiple;
    o << "]";
    return o;
}
void Ack::Handler::fileAck(
    Uint64 /*deliveryTag_*/,
    Bit /*multiple_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.ack not implemented."));
}

const char* Reject::NAME="file.reject";
const char* Reject::CLASS_NAME=file::NAME;

Reject::Reject(
    Uint64 deliveryTag_,
    Bit requeue_
) :
    deliveryTag(deliveryTag_),
    requeue(requeue_){
}
void Reject::accept(Visitor& v) {  v.visit(*this); }
void Reject::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Reject&x) {
    o << "file.reject[";
    o << " delivery-tag=" << x.deliveryTag;
    o << " requeue=" << x.requeue;
    o << "]";
    return o;
}
void Reject::Handler::fileReject(
    Uint64 /*deliveryTag_*/,
    Bit /*requeue_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("file.reject not implemented."));
}

} // namespace file


namespace stream {

const char* NAME="stream";

const char* Qos::NAME="stream.qos";
const char* Qos::CLASS_NAME=stream::NAME;

Qos::Qos(
    Uint32 prefetchSize_,
    Uint16 prefetchCount_,
    Uint32 consumeRate_,
    Bit global_
) :
    prefetchSize(prefetchSize_),
    prefetchCount(prefetchCount_),
    consumeRate(consumeRate_),
    global(global_){
}
void Qos::accept(Visitor& v) {  v.visit(*this); }
void Qos::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Qos&x) {
    o << "stream.qos[";
    o << " prefetch-size=" << x.prefetchSize;
    o << " prefetch-count=" << x.prefetchCount;
    o << " consume-rate=" << x.consumeRate;
    o << " global=" << x.global;
    o << "]";
    return o;
}
void Qos::Handler::streamQos(
    Uint32 /*prefetchSize_*/,
    Uint16 /*prefetchCount_*/,
    Uint32 /*consumeRate_*/,
    Bit /*global_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.qos not implemented."));
}

const char* QosOk::NAME="stream.qos-ok";
const char* QosOk::CLASS_NAME=stream::NAME;

QosOk::QosOk()
{
}
void QosOk::accept(Visitor& v) {  v.visit(*this); }
void QosOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QosOk&) {
    o << "stream.qos-ok[";
    o << "]";
    return o;
}
void QosOk::Handler::streamQosOk(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.qos-ok not implemented."));
}

const char* Consume::NAME="stream.consume";
const char* Consume::CLASS_NAME=stream::NAME;

Consume::Consume(
    const queue::Name& queue_,
    const Str8& consumerTag_,
    Bit noLocal_,
    Bit exclusive_,
    Bit nowait_,
    const Map& arguments_
) :
    queue(queue_),
    consumerTag(consumerTag_),
    noLocal(noLocal_),
    exclusive(exclusive_),
    nowait(nowait_),
    arguments(arguments_){
}
void Consume::accept(Visitor& v) {  v.visit(*this); }
void Consume::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Consume&x) {
    o << "stream.consume[";
    o << " queue=" << x.queue;
    o << " consumer-tag=" << x.consumerTag;
    o << " no-local=" << x.noLocal;
    o << " exclusive=" << x.exclusive;
    o << " nowait=" << x.nowait;
    o << " arguments=" << x.arguments;
    o << "]";
    return o;
}
void Consume::Handler::streamConsume(
    const queue::Name& /*queue_*/,
    const Str8& /*consumerTag_*/,
    Bit /*noLocal_*/,
    Bit /*exclusive_*/,
    Bit /*nowait_*/,
    const Map& /*arguments_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.consume not implemented."));
}

const char* ConsumeOk::NAME="stream.consume-ok";
const char* ConsumeOk::CLASS_NAME=stream::NAME;

ConsumeOk::ConsumeOk(const Str8& consumerTag_) :
    consumerTag(consumerTag_){
}
void ConsumeOk::accept(Visitor& v) {  v.visit(*this); }
void ConsumeOk::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ConsumeOk&x) {
    o << "stream.consume-ok[";
    o << " consumer-tag=" << x.consumerTag;
    o << "]";
    return o;
}
void ConsumeOk::Handler::streamConsumeOk(
    const Str8& /*consumerTag_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.consume-ok not implemented."));
}

const char* Cancel::NAME="stream.cancel";
const char* Cancel::CLASS_NAME=stream::NAME;

Cancel::Cancel(const Str8& consumerTag_) :
    consumerTag(consumerTag_){
}
void Cancel::accept(Visitor& v) {  v.visit(*this); }
void Cancel::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Cancel&x) {
    o << "stream.cancel[";
    o << " consumer-tag=" << x.consumerTag;
    o << "]";
    return o;
}
void Cancel::Handler::streamCancel(
    const Str8& /*consumerTag_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.cancel not implemented."));
}

const char* Publish::NAME="stream.publish";
const char* Publish::CLASS_NAME=stream::NAME;

Publish::Publish(
    const exchange::Name& exchange_,
    const Str8& routingKey_,
    Bit mandatory_,
    Bit immediate_
) :
    exchange(exchange_),
    routingKey(routingKey_),
    mandatory(mandatory_),
    immediate(immediate_){
}
void Publish::accept(Visitor& v) {  v.visit(*this); }
void Publish::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Publish&x) {
    o << "stream.publish[";
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << " mandatory=" << x.mandatory;
    o << " immediate=" << x.immediate;
    o << "]";
    return o;
}
void Publish::Handler::streamPublish(
    const exchange::Name& /*exchange_*/,
    const Str8& /*routingKey_*/,
    Bit /*mandatory_*/,
    Bit /*immediate_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.publish not implemented."));
}

const char* Return::NAME="stream.return";
const char* Return::CLASS_NAME=stream::NAME;

Return::Return(
    const stream::ReturnCode& replyCode_,
    const Str8& replyText_,
    const exchange::Name& exchange_,
    const Str8& routingKey_
) :
    replyCode(replyCode_),
    replyText(replyText_),
    exchange(exchange_),
    routingKey(routingKey_){
}
void Return::accept(Visitor& v) {  v.visit(*this); }
void Return::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Return&x) {
    o << "stream.return[";
    o << " reply-code=" << x.replyCode;
    o << " reply-text=" << x.replyText;
    o << " exchange=" << x.exchange;
    o << " routing-key=" << x.routingKey;
    o << "]";
    return o;
}
void Return::Handler::streamReturn(
    const stream::ReturnCode& /*replyCode_*/,
    const Str8& /*replyText_*/,
    const exchange::Name& /*exchange_*/,
    const Str8& /*routingKey_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.return not implemented."));
}

const char* Deliver::NAME="stream.deliver";
const char* Deliver::CLASS_NAME=stream::NAME;

Deliver::Deliver(
    const Str8& consumerTag_,
    Uint64 deliveryTag_,
    const exchange::Name& exchange_,
    const queue::Name& queue_
) :
    consumerTag(consumerTag_),
    deliveryTag(deliveryTag_),
    exchange(exchange_),
    queue(queue_){
}
void Deliver::accept(Visitor& v) {  v.visit(*this); }
void Deliver::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Deliver&x) {
    o << "stream.deliver[";
    o << " consumer-tag=" << x.consumerTag;
    o << " delivery-tag=" << x.deliveryTag;
    o << " exchange=" << x.exchange;
    o << " queue=" << x.queue;
    o << "]";
    return o;
}
void Deliver::Handler::streamDeliver(
    const Str8& /*consumerTag_*/,
    Uint64 /*deliveryTag_*/,
    const exchange::Name& /*exchange_*/,
    const queue::Name& /*queue_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("stream.deliver not implemented."));
}

} // namespace stream


namespace cluster {

const char* NAME="cluster";

const char* UpdateRequest::NAME="cluster.update-request";
const char* UpdateRequest::CLASS_NAME=cluster::NAME;

UpdateRequest::UpdateRequest(const Str16& url_) :
    url(url_){
}
void UpdateRequest::accept(Visitor& v) {  v.visit(*this); }
void UpdateRequest::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const UpdateRequest&x) {
    o << "cluster.update-request[";
    o << " url=" << x.url;
    o << "]";
    return o;
}
void UpdateRequest::Handler::clusterUpdateRequest(
    const Str16& /*url_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.update-request not implemented."));
}

const char* UpdateOffer::NAME="cluster.update-offer";
const char* UpdateOffer::CLASS_NAME=cluster::NAME;

UpdateOffer::UpdateOffer(Uint64 updatee_) :
    updatee(updatee_){
}
void UpdateOffer::accept(Visitor& v) {  v.visit(*this); }
void UpdateOffer::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const UpdateOffer&x) {
    o << "cluster.update-offer[";
    o << " updatee=" << x.updatee;
    o << "]";
    return o;
}
void UpdateOffer::Handler::clusterUpdateOffer(
    Uint64 /*updatee_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.update-offer not implemented."));
}

const char* RetractOffer::NAME="cluster.retract-offer";
const char* RetractOffer::CLASS_NAME=cluster::NAME;

RetractOffer::RetractOffer(Uint64 updatee_) :
    updatee(updatee_){
}
void RetractOffer::accept(Visitor& v) {  v.visit(*this); }
void RetractOffer::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const RetractOffer&x) {
    o << "cluster.retract-offer[";
    o << " updatee=" << x.updatee;
    o << "]";
    return o;
}
void RetractOffer::Handler::clusterRetractOffer(
    Uint64 /*updatee_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.retract-offer not implemented."));
}

const char* InitialStatus::NAME="cluster.initial-status";
const char* InitialStatus::CLASS_NAME=cluster::NAME;

InitialStatus::InitialStatus(
    Uint32 version_,
    Bit active_,
    const Uuid& clusterId_,
    const cluster::StoreState& storeState_,
    const Uuid& shutdownId_,
    const Str16& firstConfig_,
    const ArrayDomain<Str16> & urls_
) :
    version(version_),
    active(active_),
    clusterId(clusterId_),
    storeState(storeState_),
    shutdownId(shutdownId_),
    firstConfig(firstConfig_),
    urls(urls_){
}
void InitialStatus::accept(Visitor& v) {  v.visit(*this); }
void InitialStatus::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const InitialStatus&x) {
    o << "cluster.initial-status[";
    o << " version=" << x.version;
    o << " active=" << x.active;
    o << " cluster-id=" << x.clusterId;
    o << " store-state=" << x.storeState;
    o << " shutdown-id=" << x.shutdownId;
    o << " first-config=" << x.firstConfig;
    o << " urls=" << x.urls;
    o << "]";
    return o;
}
void InitialStatus::Handler::clusterInitialStatus(
    Uint32 /*version_*/,
    Bit /*active_*/,
    const Uuid& /*clusterId_*/,
    const cluster::StoreState& /*storeState_*/,
    const Uuid& /*shutdownId_*/,
    const Str16& /*firstConfig_*/,
    const ArrayDomain<Str16> & /*urls_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.initial-status not implemented."));
}

const char* Ready::NAME="cluster.ready";
const char* Ready::CLASS_NAME=cluster::NAME;

Ready::Ready(const Str16& url_) :
    url(url_){
}
void Ready::accept(Visitor& v) {  v.visit(*this); }
void Ready::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Ready&x) {
    o << "cluster.ready[";
    o << " url=" << x.url;
    o << "]";
    return o;
}
void Ready::Handler::clusterReady(
    const Str16& /*url_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.ready not implemented."));
}

const char* ConfigChange::NAME="cluster.config-change";
const char* ConfigChange::CLASS_NAME=cluster::NAME;

ConfigChange::ConfigChange(
    const Vbin16& members_,
    const Vbin16& joined_,
    const Vbin16& left_
) :
    members(members_),
    joined(joined_),
    left(left_){
}
void ConfigChange::accept(Visitor& v) {  v.visit(*this); }
void ConfigChange::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ConfigChange&x) {
    o << "cluster.config-change[";
    o << " members=" << x.members;
    o << " joined=" << x.joined;
    o << " left=" << x.left;
    o << "]";
    return o;
}
void ConfigChange::Handler::clusterConfigChange(
    const Vbin16& /*members_*/,
    const Vbin16& /*joined_*/,
    const Vbin16& /*left_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.config-change not implemented."));
}

const char* ErrorCheck::NAME="cluster.error-check";
const char* ErrorCheck::CLASS_NAME=cluster::NAME;

ErrorCheck::ErrorCheck(
    const cluster::ErrorType& type_,
    const SequenceNo& frameSeq_
) :
    type(type_),
    frameSeq(frameSeq_){
}
void ErrorCheck::accept(Visitor& v) {  v.visit(*this); }
void ErrorCheck::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ErrorCheck&x) {
    o << "cluster.error-check[";
    o << " type=" << x.type;
    o << " frame-seq=" << x.frameSeq;
    o << "]";
    return o;
}
void ErrorCheck::Handler::clusterErrorCheck(
    const cluster::ErrorType& /*type_*/,
    const SequenceNo& /*frameSeq_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.error-check not implemented."));
}

const char* TimerWakeup::NAME="cluster.timer-wakeup";
const char* TimerWakeup::CLASS_NAME=cluster::NAME;

TimerWakeup::TimerWakeup(const Str16& name_) :
    name(name_){
}
void TimerWakeup::accept(Visitor& v) {  v.visit(*this); }
void TimerWakeup::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TimerWakeup&x) {
    o << "cluster.timer-wakeup[";
    o << " name=" << x.name;
    o << "]";
    return o;
}
void TimerWakeup::Handler::clusterTimerWakeup(
    const Str16& /*name_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.timer-wakeup not implemented."));
}

const char* TimerDrop::NAME="cluster.timer-drop";
const char* TimerDrop::CLASS_NAME=cluster::NAME;

TimerDrop::TimerDrop(const Str16& name_) :
    name(name_){
}
void TimerDrop::accept(Visitor& v) {  v.visit(*this); }
void TimerDrop::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TimerDrop&x) {
    o << "cluster.timer-drop[";
    o << " name=" << x.name;
    o << "]";
    return o;
}
void TimerDrop::Handler::clusterTimerDrop(
    const Str16& /*name_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.timer-drop not implemented."));
}

const char* Shutdown::NAME="cluster.shutdown";
const char* Shutdown::CLASS_NAME=cluster::NAME;

Shutdown::Shutdown(const Uuid& shutdownId_) :
    shutdownId(shutdownId_){
}
void Shutdown::accept(Visitor& v) {  v.visit(*this); }
void Shutdown::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Shutdown&x) {
    o << "cluster.shutdown[";
    o << " shutdown-id=" << x.shutdownId;
    o << "]";
    return o;
}
void Shutdown::Handler::clusterShutdown(
    const Uuid& /*shutdownId_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.shutdown not implemented."));
}

const char* DeliverToQueue::NAME="cluster.deliver-to-queue";
const char* DeliverToQueue::CLASS_NAME=cluster::NAME;

DeliverToQueue::DeliverToQueue(
    const Str16& queue_,
    const Vbin32& message_
) :
    queue(queue_),
    message(message_){
}
void DeliverToQueue::accept(Visitor& v) {  v.visit(*this); }
void DeliverToQueue::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DeliverToQueue&x) {
    o << "cluster.deliver-to-queue[";
    o << " queue=" << x.queue;
    o << " message=" << x.message;
    o << "]";
    return o;
}
void DeliverToQueue::Handler::clusterDeliverToQueue(
    const Str16& /*queue_*/,
    const Vbin32& /*message_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.deliver-to-queue not implemented."));
}

const char* Clock::NAME="cluster.clock";
const char* Clock::CLASS_NAME=cluster::NAME;

Clock::Clock(Uint64 time_) :
    time(time_){
}
void Clock::accept(Visitor& v) {  v.visit(*this); }
void Clock::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Clock&x) {
    o << "cluster.clock[";
    o << " time=" << x.time;
    o << "]";
    return o;
}
void Clock::Handler::clusterClock(
    Uint64 /*time_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster.clock not implemented."));
}

} // namespace cluster


namespace cluster_connection {

const char* NAME="cluster-connection";

const char* Announce::NAME="cluster-connection.announce";
const char* Announce::CLASS_NAME=cluster_connection::NAME;

Announce::Announce(
    const Str16& managementId_,
    Uint32 ssf_,
    const Str16& authid_,
    Bit nodict_,
    const Str32& username_,
    const Str32& initialFrames_
) :
    managementId(managementId_),
    ssf(ssf_),
    authid(authid_),
    nodict(nodict_),
    username(username_),
    initialFrames(initialFrames_){
}
void Announce::accept(Visitor& v) {  v.visit(*this); }
void Announce::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Announce&x) {
    o << "cluster-connection.announce[";
    o << " management-id=" << x.managementId;
    o << " ssf=" << x.ssf;
    o << " authid=" << x.authid;
    o << " nodict=" << x.nodict;
    o << " username=" << x.username;
    o << " initial-frames=" << x.initialFrames;
    o << "]";
    return o;
}
void Announce::Handler::clusterConnectionAnnounce(
    const Str16& /*managementId_*/,
    Uint32 /*ssf_*/,
    const Str16& /*authid_*/,
    Bit /*nodict_*/,
    const Str32& /*username_*/,
    const Str32& /*initialFrames_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.announce not implemented."));
}

const char* DeliverClose::NAME="cluster-connection.deliver-close";
const char* DeliverClose::CLASS_NAME=cluster_connection::NAME;

DeliverClose::DeliverClose()
{
}
void DeliverClose::accept(Visitor& v) {  v.visit(*this); }
void DeliverClose::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DeliverClose&) {
    o << "cluster-connection.deliver-close[";
    o << "]";
    return o;
}
void DeliverClose::Handler::clusterConnectionDeliverClose(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.deliver-close not implemented."));
}

const char* DeliverDoOutput::NAME="cluster-connection.deliver-do-output";
const char* DeliverDoOutput::CLASS_NAME=cluster_connection::NAME;

DeliverDoOutput::DeliverDoOutput(Uint32 limit_) :
    limit(limit_){
}
void DeliverDoOutput::accept(Visitor& v) {  v.visit(*this); }
void DeliverDoOutput::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DeliverDoOutput&x) {
    o << "cluster-connection.deliver-do-output[";
    o << " limit=" << x.limit;
    o << "]";
    return o;
}
void DeliverDoOutput::Handler::clusterConnectionDeliverDoOutput(
    Uint32 /*limit_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.deliver-do-output not implemented."));
}

const char* Abort::NAME="cluster-connection.abort";
const char* Abort::CLASS_NAME=cluster_connection::NAME;

Abort::Abort()
{
}
void Abort::accept(Visitor& v) {  v.visit(*this); }
void Abort::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Abort&) {
    o << "cluster-connection.abort[";
    o << "]";
    return o;
}
void Abort::Handler::clusterConnectionAbort(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.abort not implemented."));
}

const char* ShadowSetUser::NAME="cluster-connection.shadow-set-user";
const char* ShadowSetUser::CLASS_NAME=cluster_connection::NAME;

ShadowSetUser::ShadowSetUser(const Str16& userId_) :
    userId(userId_){
}
void ShadowSetUser::accept(Visitor& v) {  v.visit(*this); }
void ShadowSetUser::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ShadowSetUser&x) {
    o << "cluster-connection.shadow-set-user[";
    o << " user-id=" << x.userId;
    o << "]";
    return o;
}
void ShadowSetUser::Handler::clusterConnectionShadowSetUser(
    const Str16& /*userId_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.shadow-set-user not implemented."));
}

const char* ShadowPrepare::NAME="cluster-connection.shadow-prepare";
const char* ShadowPrepare::CLASS_NAME=cluster_connection::NAME;

ShadowPrepare::ShadowPrepare(const Str16& managementId_) :
    managementId(managementId_){
}
void ShadowPrepare::accept(Visitor& v) {  v.visit(*this); }
void ShadowPrepare::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ShadowPrepare&x) {
    o << "cluster-connection.shadow-prepare[";
    o << " management-id=" << x.managementId;
    o << "]";
    return o;
}
void ShadowPrepare::Handler::clusterConnectionShadowPrepare(
    const Str16& /*managementId_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.shadow-prepare not implemented."));
}

const char* ConsumerState::NAME="cluster-connection.consumer-state";
const char* ConsumerState::CLASS_NAME=cluster_connection::NAME;

ConsumerState::ConsumerState(
    const Str8& name_,
    Bit blocked_,
    Bit notifyEnabled_,
    const SequenceNo& position_,
    Uint32 usedMsgCredit_,
    Uint32 usedByteCredit_,
    Uint32 deliveryCount_
) :
    name(name_),
    blocked(blocked_),
    notifyEnabled(notifyEnabled_),
    position(position_),
    usedMsgCredit(usedMsgCredit_),
    usedByteCredit(usedByteCredit_),
    deliveryCount(deliveryCount_){
}
void ConsumerState::accept(Visitor& v) {  v.visit(*this); }
void ConsumerState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ConsumerState&x) {
    o << "cluster-connection.consumer-state[";
    o << " name=" << x.name;
    o << " blocked=" << x.blocked;
    o << " notifyEnabled=" << x.notifyEnabled;
    o << " position=" << x.position;
    o << " used-msg-credit=" << x.usedMsgCredit;
    o << " used-byte-credit=" << x.usedByteCredit;
    o << " deliveryCount=" << x.deliveryCount;
    o << "]";
    return o;
}
void ConsumerState::Handler::clusterConnectionConsumerState(
    const Str8& /*name_*/,
    Bit /*blocked_*/,
    Bit /*notifyEnabled_*/,
    const SequenceNo& /*position_*/,
    Uint32 /*usedMsgCredit_*/,
    Uint32 /*usedByteCredit_*/,
    Uint32 /*deliveryCount_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.consumer-state not implemented."));
}

const char* DeliveryRecord::NAME="cluster-connection.delivery-record";
const char* DeliveryRecord::CLASS_NAME=cluster_connection::NAME;

DeliveryRecord::DeliveryRecord(
    const Str8& queue_,
    const SequenceNo& position_,
    const Str8& tag_,
    const SequenceNo& id_,
    Bit acquired_,
    Bit accepted_,
    Bit cancelled_,
    Bit completed_,
    Bit ended_,
    Bit windowing_,
    Bit enqueued_,
    Uint32 credit_
) :
    queue(queue_),
    position(position_),
    tag(tag_),
    id(id_),
    acquired(acquired_),
    accepted(accepted_),
    cancelled(cancelled_),
    completed(completed_),
    ended(ended_),
    windowing(windowing_),
    enqueued(enqueued_),
    credit(credit_){
}
void DeliveryRecord::accept(Visitor& v) {  v.visit(*this); }
void DeliveryRecord::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DeliveryRecord&x) {
    o << "cluster-connection.delivery-record[";
    o << " queue=" << x.queue;
    o << " position=" << x.position;
    o << " tag=" << x.tag;
    o << " id=" << x.id;
    o << " acquired=" << x.acquired;
    o << " accepted=" << x.accepted;
    o << " cancelled=" << x.cancelled;
    o << " completed=" << x.completed;
    o << " ended=" << x.ended;
    o << " windowing=" << x.windowing;
    o << " enqueued=" << x.enqueued;
    o << " credit=" << x.credit;
    o << "]";
    return o;
}
void DeliveryRecord::Handler::clusterConnectionDeliveryRecord(
    const Str8& /*queue_*/,
    const SequenceNo& /*position_*/,
    const Str8& /*tag_*/,
    const SequenceNo& /*id_*/,
    Bit /*acquired_*/,
    Bit /*accepted_*/,
    Bit /*cancelled_*/,
    Bit /*completed_*/,
    Bit /*ended_*/,
    Bit /*windowing_*/,
    Bit /*enqueued_*/,
    Uint32 /*credit_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.delivery-record not implemented."));
}

const char* TxStart::NAME="cluster-connection.tx-start";
const char* TxStart::CLASS_NAME=cluster_connection::NAME;

TxStart::TxStart()
{
}
void TxStart::accept(Visitor& v) {  v.visit(*this); }
void TxStart::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TxStart&) {
    o << "cluster-connection.tx-start[";
    o << "]";
    return o;
}
void TxStart::Handler::clusterConnectionTxStart(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.tx-start not implemented."));
}

const char* TxAccept::NAME="cluster-connection.tx-accept";
const char* TxAccept::CLASS_NAME=cluster_connection::NAME;

TxAccept::TxAccept(const SequenceSet& commands_) :
    commands(commands_){
}
void TxAccept::accept(Visitor& v) {  v.visit(*this); }
void TxAccept::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TxAccept&x) {
    o << "cluster-connection.tx-accept[";
    o << " commands=" << x.commands;
    o << "]";
    return o;
}
void TxAccept::Handler::clusterConnectionTxAccept(
    const SequenceSet& /*commands_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.tx-accept not implemented."));
}

const char* TxDequeue::NAME="cluster-connection.tx-dequeue";
const char* TxDequeue::CLASS_NAME=cluster_connection::NAME;

TxDequeue::TxDequeue(const Str8& queue_) :
    queue(queue_){
}
void TxDequeue::accept(Visitor& v) {  v.visit(*this); }
void TxDequeue::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TxDequeue&x) {
    o << "cluster-connection.tx-dequeue[";
    o << " queue=" << x.queue;
    o << "]";
    return o;
}
void TxDequeue::Handler::clusterConnectionTxDequeue(
    const Str8& /*queue_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.tx-dequeue not implemented."));
}

const char* TxEnqueue::NAME="cluster-connection.tx-enqueue";
const char* TxEnqueue::CLASS_NAME=cluster_connection::NAME;

TxEnqueue::TxEnqueue(const Str8& queue_) :
    queue(queue_){
}
void TxEnqueue::accept(Visitor& v) {  v.visit(*this); }
void TxEnqueue::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TxEnqueue&x) {
    o << "cluster-connection.tx-enqueue[";
    o << " queue=" << x.queue;
    o << "]";
    return o;
}
void TxEnqueue::Handler::clusterConnectionTxEnqueue(
    const Str8& /*queue_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.tx-enqueue not implemented."));
}

const char* TxPublish::NAME="cluster-connection.tx-publish";
const char* TxPublish::CLASS_NAME=cluster_connection::NAME;

TxPublish::TxPublish(
    const ArrayDomain<Str8> & queues_,
    Bit delivered_
) :
    queues(queues_),
    delivered(delivered_){
}
void TxPublish::accept(Visitor& v) {  v.visit(*this); }
void TxPublish::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TxPublish&x) {
    o << "cluster-connection.tx-publish[";
    o << " queues=" << x.queues;
    o << " delivered=" << x.delivered;
    o << "]";
    return o;
}
void TxPublish::Handler::clusterConnectionTxPublish(
    const ArrayDomain<Str8> & /*queues_*/,
    Bit /*delivered_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.tx-publish not implemented."));
}

const char* TxEnd::NAME="cluster-connection.tx-end";
const char* TxEnd::CLASS_NAME=cluster_connection::NAME;

TxEnd::TxEnd()
{
}
void TxEnd::accept(Visitor& v) {  v.visit(*this); }
void TxEnd::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const TxEnd&) {
    o << "cluster-connection.tx-end[";
    o << "]";
    return o;
}
void TxEnd::Handler::clusterConnectionTxEnd(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.tx-end not implemented."));
}

const char* AccumulatedAck::NAME="cluster-connection.accumulated-ack";
const char* AccumulatedAck::CLASS_NAME=cluster_connection::NAME;

AccumulatedAck::AccumulatedAck(const SequenceSet& commands_) :
    commands(commands_){
}
void AccumulatedAck::accept(Visitor& v) {  v.visit(*this); }
void AccumulatedAck::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const AccumulatedAck&x) {
    o << "cluster-connection.accumulated-ack[";
    o << " commands=" << x.commands;
    o << "]";
    return o;
}
void AccumulatedAck::Handler::clusterConnectionAccumulatedAck(
    const SequenceSet& /*commands_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.accumulated-ack not implemented."));
}

const char* OutputTask::NAME="cluster-connection.output-task";
const char* OutputTask::CLASS_NAME=cluster_connection::NAME;

OutputTask::OutputTask(
    Uint16 channel_,
    const Str8& name_
) :
    channel(channel_),
    name(name_){
}
void OutputTask::accept(Visitor& v) {  v.visit(*this); }
void OutputTask::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const OutputTask&x) {
    o << "cluster-connection.output-task[";
    o << " channel=" << x.channel;
    o << " name=" << x.name;
    o << "]";
    return o;
}
void OutputTask::Handler::clusterConnectionOutputTask(
    Uint16 /*channel_*/,
    const Str8& /*name_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.output-task not implemented."));
}

const char* DtxStart::NAME="cluster-connection.dtx-start";
const char* DtxStart::CLASS_NAME=cluster_connection::NAME;

DtxStart::DtxStart(
    const Str16& xid_,
    Bit ended_,
    Bit suspended_,
    Bit failed_,
    Bit expired_
) :
    xid(xid_),
    ended(ended_),
    suspended(suspended_),
    failed(failed_),
    expired(expired_){
}
void DtxStart::accept(Visitor& v) {  v.visit(*this); }
void DtxStart::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DtxStart&x) {
    o << "cluster-connection.dtx-start[";
    o << " xid=" << x.xid;
    o << " ended=" << x.ended;
    o << " suspended=" << x.suspended;
    o << " failed=" << x.failed;
    o << " expired=" << x.expired;
    o << "]";
    return o;
}
void DtxStart::Handler::clusterConnectionDtxStart(
    const Str16& /*xid_*/,
    Bit /*ended_*/,
    Bit /*suspended_*/,
    Bit /*failed_*/,
    Bit /*expired_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.dtx-start not implemented."));
}

const char* DtxEnd::NAME="cluster-connection.dtx-end";
const char* DtxEnd::CLASS_NAME=cluster_connection::NAME;

DtxEnd::DtxEnd()
{
}
void DtxEnd::accept(Visitor& v) {  v.visit(*this); }
void DtxEnd::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DtxEnd&) {
    o << "cluster-connection.dtx-end[";
    o << "]";
    return o;
}
void DtxEnd::Handler::clusterConnectionDtxEnd(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.dtx-end not implemented."));
}

const char* DtxAck::NAME="cluster-connection.dtx-ack";
const char* DtxAck::CLASS_NAME=cluster_connection::NAME;

DtxAck::DtxAck()
{
}
void DtxAck::accept(Visitor& v) {  v.visit(*this); }
void DtxAck::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DtxAck&) {
    o << "cluster-connection.dtx-ack[";
    o << "]";
    return o;
}
void DtxAck::Handler::clusterConnectionDtxAck(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.dtx-ack not implemented."));
}

const char* DtxBufferRef::NAME="cluster-connection.dtx-buffer-ref";
const char* DtxBufferRef::CLASS_NAME=cluster_connection::NAME;

DtxBufferRef::DtxBufferRef(
    const Str16& xid_,
    Uint32 index_,
    Bit suspended_
) :
    xid(xid_),
    index(index_),
    suspended(suspended_){
}
void DtxBufferRef::accept(Visitor& v) {  v.visit(*this); }
void DtxBufferRef::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DtxBufferRef&x) {
    o << "cluster-connection.dtx-buffer-ref[";
    o << " xid=" << x.xid;
    o << " index=" << x.index;
    o << " suspended=" << x.suspended;
    o << "]";
    return o;
}
void DtxBufferRef::Handler::clusterConnectionDtxBufferRef(
    const Str16& /*xid_*/,
    Uint32 /*index_*/,
    Bit /*suspended_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.dtx-buffer-ref not implemented."));
}

const char* DtxWorkRecord::NAME="cluster-connection.dtx-work-record";
const char* DtxWorkRecord::CLASS_NAME=cluster_connection::NAME;

DtxWorkRecord::DtxWorkRecord(
    const Str16& xid_,
    Bit prepared_,
    Uint32 timeout_
) :
    xid(xid_),
    prepared(prepared_),
    timeout(timeout_){
}
void DtxWorkRecord::accept(Visitor& v) {  v.visit(*this); }
void DtxWorkRecord::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const DtxWorkRecord&x) {
    o << "cluster-connection.dtx-work-record[";
    o << " xid=" << x.xid;
    o << " prepared=" << x.prepared;
    o << " timeout=" << x.timeout;
    o << "]";
    return o;
}
void DtxWorkRecord::Handler::clusterConnectionDtxWorkRecord(
    const Str16& /*xid_*/,
    Bit /*prepared_*/,
    Uint32 /*timeout_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.dtx-work-record not implemented."));
}

const char* SessionState::NAME="cluster-connection.session-state";
const char* SessionState::CLASS_NAME=cluster_connection::NAME;

SessionState::SessionState(
    const SequenceNo& replayStart_,
    const SequenceNo& commandPoint_,
    const SequenceSet& sentIncomplete_,
    const SequenceNo& expected_,
    const SequenceNo& received_,
    const SequenceSet& unknownCompleted_,
    const SequenceSet& receivedIncomplete_,
    Bit dtxSelected_
) :
    replayStart(replayStart_),
    commandPoint(commandPoint_),
    sentIncomplete(sentIncomplete_),
    expected(expected_),
    received(received_),
    unknownCompleted(unknownCompleted_),
    receivedIncomplete(receivedIncomplete_),
    dtxSelected(dtxSelected_){
}
void SessionState::accept(Visitor& v) {  v.visit(*this); }
void SessionState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const SessionState&x) {
    o << "cluster-connection.session-state[";
    o << " replay-start=" << x.replayStart;
    o << " command-point=" << x.commandPoint;
    o << " sent-incomplete=" << x.sentIncomplete;
    o << " expected=" << x.expected;
    o << " received=" << x.received;
    o << " unknown-completed=" << x.unknownCompleted;
    o << " received-incomplete=" << x.receivedIncomplete;
    o << " dtx-selected=" << x.dtxSelected;
    o << "]";
    return o;
}
void SessionState::Handler::clusterConnectionSessionState(
    const SequenceNo& /*replayStart_*/,
    const SequenceNo& /*commandPoint_*/,
    const SequenceSet& /*sentIncomplete_*/,
    const SequenceNo& /*expected_*/,
    const SequenceNo& /*received_*/,
    const SequenceSet& /*unknownCompleted_*/,
    const SequenceSet& /*receivedIncomplete_*/,
    Bit /*dtxSelected_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.session-state not implemented."));
}

const char* ShadowReady::NAME="cluster-connection.shadow-ready";
const char* ShadowReady::CLASS_NAME=cluster_connection::NAME;

ShadowReady::ShadowReady(
    Uint64 memberId_,
    Uint64 connectionId_,
    const Str16& managementId_,
    const Str8& userName_,
    const Str32& fragment_,
    Uint32 sendMax_
) :
    memberId(memberId_),
    connectionId(connectionId_),
    managementId(managementId_),
    userName(userName_),
    fragment(fragment_),
    sendMax(sendMax_){
}
void ShadowReady::accept(Visitor& v) {  v.visit(*this); }
void ShadowReady::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ShadowReady&x) {
    o << "cluster-connection.shadow-ready[";
    o << " member-id=" << x.memberId;
    o << " connection-id=" << x.connectionId;
    o << " management-id=" << x.managementId;
    o << " user-name=" << x.userName;
    o << " fragment=" << x.fragment;
    o << " send-max=" << x.sendMax;
    o << "]";
    return o;
}
void ShadowReady::Handler::clusterConnectionShadowReady(
    Uint64 /*memberId_*/,
    Uint64 /*connectionId_*/,
    const Str16& /*managementId_*/,
    const Str8& /*userName_*/,
    const Str32& /*fragment_*/,
    Uint32 /*sendMax_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.shadow-ready not implemented."));
}

const char* Membership::NAME="cluster-connection.membership";
const char* Membership::CLASS_NAME=cluster_connection::NAME;

Membership::Membership(
    const Map& joiners_,
    const Map& members_,
    const SequenceNo& frameSeq_
) :
    joiners(joiners_),
    members(members_),
    frameSeq(frameSeq_){
}
void Membership::accept(Visitor& v) {  v.visit(*this); }
void Membership::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Membership&x) {
    o << "cluster-connection.membership[";
    o << " joiners=" << x.joiners;
    o << " members=" << x.members;
    o << " frame-seq=" << x.frameSeq;
    o << "]";
    return o;
}
void Membership::Handler::clusterConnectionMembership(
    const Map& /*joiners_*/,
    const Map& /*members_*/,
    const SequenceNo& /*frameSeq_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.membership not implemented."));
}

const char* RetractOffer::NAME="cluster-connection.retract-offer";
const char* RetractOffer::CLASS_NAME=cluster_connection::NAME;

RetractOffer::RetractOffer()
{
}
void RetractOffer::accept(Visitor& v) {  v.visit(*this); }
void RetractOffer::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const RetractOffer&) {
    o << "cluster-connection.retract-offer[";
    o << "]";
    return o;
}
void RetractOffer::Handler::clusterConnectionRetractOffer(
    
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.retract-offer not implemented."));
}

const char* QueuePosition::NAME="cluster-connection.queue-position";
const char* QueuePosition::CLASS_NAME=cluster_connection::NAME;

QueuePosition::QueuePosition(
    const Str8& queue_,
    const SequenceNo& position_
) :
    queue(queue_),
    position(position_){
}
void QueuePosition::accept(Visitor& v) {  v.visit(*this); }
void QueuePosition::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QueuePosition&x) {
    o << "cluster-connection.queue-position[";
    o << " queue=" << x.queue;
    o << " position=" << x.position;
    o << "]";
    return o;
}
void QueuePosition::Handler::clusterConnectionQueuePosition(
    const Str8& /*queue_*/,
    const SequenceNo& /*position_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.queue-position not implemented."));
}

const char* Exchange::NAME="cluster-connection.exchange";
const char* Exchange::CLASS_NAME=cluster_connection::NAME;

Exchange::Exchange(const Str32& encoded_) :
    encoded(encoded_){
}
void Exchange::accept(Visitor& v) {  v.visit(*this); }
void Exchange::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Exchange&x) {
    o << "cluster-connection.exchange[";
    o << " encoded=" << x.encoded;
    o << "]";
    return o;
}
void Exchange::Handler::clusterConnectionExchange(
    const Str32& /*encoded_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.exchange not implemented."));
}

const char* AddQueueListener::NAME="cluster-connection.add-queue-listener";
const char* AddQueueListener::CLASS_NAME=cluster_connection::NAME;

AddQueueListener::AddQueueListener(
    const Str8& queue_,
    Uint32 consumer_
) :
    queue(queue_),
    consumer(consumer_){
}
void AddQueueListener::accept(Visitor& v) {  v.visit(*this); }
void AddQueueListener::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const AddQueueListener&x) {
    o << "cluster-connection.add-queue-listener[";
    o << " queue=" << x.queue;
    o << " consumer=" << x.consumer;
    o << "]";
    return o;
}
void AddQueueListener::Handler::clusterConnectionAddQueueListener(
    const Str8& /*queue_*/,
    Uint32 /*consumer_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.add-queue-listener not implemented."));
}

const char* ManagementSetupState::NAME="cluster-connection.management-setup-state";
const char* ManagementSetupState::CLASS_NAME=cluster_connection::NAME;

ManagementSetupState::ManagementSetupState(
    Uint64 objectNum_,
    Uint16 bootSequence_,
    const Uuid& brokerId_,
    const Str32& vendor_,
    const Str32& product_,
    const Str32& instance_
) :
    objectNum(objectNum_),
    bootSequence(bootSequence_),
    brokerId(brokerId_),
    vendor(vendor_),
    product(product_),
    instance(instance_){
}
void ManagementSetupState::accept(Visitor& v) {  v.visit(*this); }
void ManagementSetupState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const ManagementSetupState&x) {
    o << "cluster-connection.management-setup-state[";
    o << " objectNum=" << x.objectNum;
    o << " bootSequence=" << x.bootSequence;
    o << " broker-id=" << x.brokerId;
    o << " vendor=" << x.vendor;
    o << " product=" << x.product;
    o << " instance=" << x.instance;
    o << "]";
    return o;
}
void ManagementSetupState::Handler::clusterConnectionManagementSetupState(
    Uint64 /*objectNum_*/,
    Uint16 /*bootSequence_*/,
    const Uuid& /*brokerId_*/,
    const Str32& /*vendor_*/,
    const Str32& /*product_*/,
    const Str32& /*instance_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.management-setup-state not implemented."));
}

const char* Config::NAME="cluster-connection.config";
const char* Config::CLASS_NAME=cluster_connection::NAME;

Config::Config(const Str32& encoded_) :
    encoded(encoded_){
}
void Config::accept(Visitor& v) {  v.visit(*this); }
void Config::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Config&x) {
    o << "cluster-connection.config[";
    o << " encoded=" << x.encoded;
    o << "]";
    return o;
}
void Config::Handler::clusterConnectionConfig(
    const Str32& /*encoded_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.config not implemented."));
}

const char* QueueFairshareState::NAME="cluster-connection.queue-fairshare-state";
const char* QueueFairshareState::CLASS_NAME=cluster_connection::NAME;

QueueFairshareState::QueueFairshareState(
    const Str8& queue_,
    Uint8 position_,
    Uint8 count_
) :
    queue(queue_),
    position(position_),
    count(count_){
}
void QueueFairshareState::accept(Visitor& v) {  v.visit(*this); }
void QueueFairshareState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QueueFairshareState&x) {
    o << "cluster-connection.queue-fairshare-state[";
    o << " queue=" << x.queue;
    o << " position=" << x.position;
    o << " count=" << x.count;
    o << "]";
    return o;
}
void QueueFairshareState::Handler::clusterConnectionQueueFairshareState(
    const Str8& /*queue_*/,
    Uint8 /*position_*/,
    Uint8 /*count_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.queue-fairshare-state not implemented."));
}

const char* QueueObserverState::NAME="cluster-connection.queue-observer-state";
const char* QueueObserverState::CLASS_NAME=cluster_connection::NAME;

QueueObserverState::QueueObserverState(
    const Str8& queue_,
    const Str8& observerId_,
    const Map& state_
) :
    queue(queue_),
    observerId(observerId_),
    state(state_){
}
void QueueObserverState::accept(Visitor& v) {  v.visit(*this); }
void QueueObserverState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QueueObserverState&x) {
    o << "cluster-connection.queue-observer-state[";
    o << " queue=" << x.queue;
    o << " observer-id=" << x.observerId;
    o << " state=" << x.state;
    o << "]";
    return o;
}
void QueueObserverState::Handler::clusterConnectionQueueObserverState(
    const Str8& /*queue_*/,
    const Str8& /*observerId_*/,
    const Map& /*state_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.queue-observer-state not implemented."));
}

const char* Clock::NAME="cluster-connection.clock";
const char* Clock::CLASS_NAME=cluster_connection::NAME;

Clock::Clock(Uint64 time_) :
    time(time_){
}
void Clock::accept(Visitor& v) {  v.visit(*this); }
void Clock::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const Clock&x) {
    o << "cluster-connection.clock[";
    o << " time=" << x.time;
    o << "]";
    return o;
}
void Clock::Handler::clusterConnectionClock(
    Uint64 /*time_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.clock not implemented."));
}

const char* QueueDequeueSincePurgeState::NAME="cluster-connection.queue-dequeue-since-purge-state";
const char* QueueDequeueSincePurgeState::CLASS_NAME=cluster_connection::NAME;

QueueDequeueSincePurgeState::QueueDequeueSincePurgeState(
    const Str8& queue_,
    Uint32 dequeueSincePurge_
) :
    queue(queue_),
    dequeueSincePurge(dequeueSincePurge_){
}
void QueueDequeueSincePurgeState::accept(Visitor& v) {  v.visit(*this); }
void QueueDequeueSincePurgeState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const QueueDequeueSincePurgeState&x) {
    o << "cluster-connection.queue-dequeue-since-purge-state[";
    o << " queue=" << x.queue;
    o << " dequeueSincePurge=" << x.dequeueSincePurge;
    o << "]";
    return o;
}
void QueueDequeueSincePurgeState::Handler::clusterConnectionQueueDequeueSincePurgeState(
    const Str8& /*queue_*/,
    Uint32 /*dequeueSincePurge_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.queue-dequeue-since-purge-state not implemented."));
}

const char* InternalState::NAME="cluster-connection.internal-state";
const char* InternalState::CLASS_NAME=cluster_connection::NAME;

InternalState::InternalState(
    const Str8& type_,
    const Str8& name_,
    const Map& state_
) :
    type(type_),
    name(name_),
    state(state_){
}
void InternalState::accept(Visitor& v) {  v.visit(*this); }
void InternalState::accept(ConstVisitor& v) const { v.visit(*this); }

std::ostream& operator << (std::ostream& o, const InternalState&x) {
    o << "cluster-connection.internal-state[";
    o << " type=" << x.type;
    o << " name=" << x.name;
    o << " state=" << x.state;
    o << "]";
    return o;
}
void InternalState::Handler::clusterConnectionInternalState(
    const Str8& /*type_*/,
    const Str8& /*name_*/,
    const Map& /*state_*/
)
{
    assert(0);
    throw NotImplementedException(QPID_MSG("cluster-connection.internal-state not implemented."));
}

} // namespace cluster_connection


}} // namespace qpid::amqp_0_10

