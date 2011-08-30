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


#include "qpid/framing/reply_exceptions.h"
#include "qpid/Msg.h"
#include <sstream>
#include <assert.h>

namespace qpid {
namespace framing {

sys::ExceptionHolder createSessionException(int code, const std::string& text) {
    sys::ExceptionHolder holder;
    switch (code) {
        case 403: holder = new UnauthorizedAccessException(text); break;
        case 404: holder = new NotFoundException(text); break;
        case 405: holder = new ResourceLockedException(text); break;
        case 406: holder = new PreconditionFailedException(text); break;
        case 408: holder = new ResourceDeletedException(text); break;
        case 409: holder = new IllegalStateException(text); break;
        case 503: holder = new CommandInvalidException(text); break;
        case 506: holder = new ResourceLimitExceededException(text); break;
        case 530: holder = new NotAllowedException(text); break;
        case 531: holder = new IllegalArgumentException(text); break;
        case 540: holder = new NotImplementedException(text); break;
        case 541: holder = new InternalErrorException(text); break;
        case 542: holder = new InvalidArgumentException(text); break;
        default: holder = new InvalidArgumentException(QPID_MSG("Bad error-code: " << code << ": " << text));
    }
    return holder;
}
sys::ExceptionHolder createConnectionException(int code, const std::string& text) {
    sys::ExceptionHolder holder;
    switch (code) {
        case 200: break;
        case 320: holder = new ConnectionForcedException(text); break;
        case 402: holder = new InvalidPathException(text); break;
        case 501: holder = new FramingErrorException(text); break;
        default: holder = new FramingErrorException(QPID_MSG("Bad close-code: " << code << ": " << text));
    }
    return holder;
}
sys::ExceptionHolder createChannelException(int code, const std::string& text) {
    sys::ExceptionHolder holder;
    switch (code) {
        case 0: break;
        case 1: holder = new SessionBusyException(text); break;
        case 2: holder = new TransportBusyException(text); break;
        case 3: holder = new NotAttachedException(text); break;
        case 4: holder = new UnknownIdsException(text); break;
        default: holder = new NotAttachedException(QPID_MSG("Bad detach-code: " << code << ": " << text));
    }
    return holder;
}

}} // namespace qpid::framing

