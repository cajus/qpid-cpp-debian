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


#include "qpid/framing/ClientInvoker.h"
#include "qpid/framing/ConnectionStartBody.h"
#include "qpid/framing/ConnectionSecureBody.h"
#include "qpid/framing/ConnectionTuneBody.h"
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
#include "qpid/framing/MessageResumeBody.h"
#include "qpid/framing/MessageSetFlowModeBody.h"
#include "qpid/framing/MessageFlowBody.h"
#include "qpid/framing/MessageStopBody.h"
#include "qpid/framing/FileQosOkBody.h"
#include "qpid/framing/FileConsumeOkBody.h"
#include "qpid/framing/FileOpenBody.h"
#include "qpid/framing/FileOpenOkBody.h"
#include "qpid/framing/FileDeliverBody.h"
#include "qpid/framing/StreamQosOkBody.h"
#include "qpid/framing/StreamConsumeOkBody.h"

namespace qpid {
namespace framing {

void AMQP_ClientOperations::Invoker::visit(const ConnectionStartBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionSecureBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionTuneBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionOpenOkBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionRedirectBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionHeartbeatBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionCloseBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ConnectionCloseOkBody& body) {
    AMQP_ClientOperations::ConnectionHandler::Invoker invoker(*target.getConnectionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionAttachBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionAttachedBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionDetachBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionDetachedBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionRequestTimeoutBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionTimeoutBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionCommandPointBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionExpectedBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionConfirmedBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionCompletedBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionKnownCompletedBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionFlushBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const SessionGapBody& body) {
    AMQP_ClientOperations::SessionHandler::Invoker invoker(*target.getSessionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ExecutionSyncBody& body) {
    AMQP_ClientOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ExecutionResultBody& body) {
    AMQP_ClientOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const ExecutionExceptionBody& body) {
    AMQP_ClientOperations::ExecutionHandler::Invoker invoker(*target.getExecutionHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageAcceptBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageRejectBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageReleaseBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageResumeBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageSetFlowModeBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageFlowBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const MessageStopBody& body) {
    AMQP_ClientOperations::MessageHandler::Invoker invoker(*target.getMessageHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const FileQosOkBody& body) {
    AMQP_ClientOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const FileConsumeOkBody& body) {
    AMQP_ClientOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const FileOpenBody& body) {
    AMQP_ClientOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const FileOpenOkBody& body) {
    AMQP_ClientOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const FileDeliverBody& body) {
    AMQP_ClientOperations::FileHandler::Invoker invoker(*target.getFileHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const StreamQosOkBody& body) {
    AMQP_ClientOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::Invoker::visit(const StreamConsumeOkBody& body) {
    AMQP_ClientOperations::StreamHandler::Invoker invoker(*target.getStreamHandler());
    body.accept(invoker);
    result=invoker.getResult();
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionStartBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionSecureBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionTuneBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionOpenOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionRedirectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionHeartbeatBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionCloseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ConnectionHandler::Invoker::visit(const ConnectionCloseOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionAttachBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionAttachedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionDetachBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionDetachedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionRequestTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionTimeoutBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionCommandPointBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionExpectedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionConfirmedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionCompletedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionKnownCompletedBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionFlushBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::SessionHandler::Invoker::visit(const SessionGapBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ExecutionHandler::Invoker::visit(const ExecutionSyncBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ExecutionHandler::Invoker::visit(const ExecutionResultBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::ExecutionHandler::Invoker::visit(const ExecutionExceptionBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageAcceptBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageRejectBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageReleaseBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageResumeBody& body) {
    this->encode(body.invoke(target), result.result);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageSetFlowModeBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageFlowBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::MessageHandler::Invoker::visit(const MessageStopBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::FileHandler::Invoker::visit(const FileQosOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::FileHandler::Invoker::visit(const FileConsumeOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::FileHandler::Invoker::visit(const FileOpenBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::FileHandler::Invoker::visit(const FileOpenOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::FileHandler::Invoker::visit(const FileDeliverBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::StreamHandler::Invoker::visit(const StreamQosOkBody& body) {
    body.invoke(target);
    result.handled=true;
}
void AMQP_ClientOperations::StreamHandler::Invoker::visit(const StreamConsumeOkBody& body) {
    body.invoke(target);
    result.handled=true;
}

}} // namespace qpid::framing

