
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//

// This source file was created by a code generator.
// Please do not edit.

#include "Package.h"
#include "System.h"
#include "Memory.h"
#include "Broker.h"
#include "Agent.h"
#include "Vhost.h"
#include "Queue.h"
#include "Exchange.h"
#include "Binding.h"
#include "Subscription.h"
#include "Connection.h"
#include "Link.h"
#include "Bridge.h"
#include "Session.h"
#include "ManagementSetupState.h"
#include "EventClientConnect.h"
#include "EventClientConnectFail.h"
#include "EventClientDisconnect.h"
#include "EventBrokerLinkUp.h"
#include "EventBrokerLinkDown.h"
#include "EventQueueDeclare.h"
#include "EventQueueDelete.h"
#include "EventExchangeDeclare.h"
#include "EventExchangeDelete.h"
#include "EventBind.h"
#include "EventUnbind.h"
#include "EventSubscribe.h"
#include "EventUnsubscribe.h"
#include "EventQueueThresholdExceeded.h"


using namespace qmf::org::apache::qpid::broker;

Package::Package (::qpid::management::ManagementAgent* agent)
{
    System::registerSelf(agent);
    Memory::registerSelf(agent);
    Broker::registerSelf(agent);
    Agent::registerSelf(agent);
    Vhost::registerSelf(agent);
    Queue::registerSelf(agent);
    Exchange::registerSelf(agent);
    Binding::registerSelf(agent);
    Subscription::registerSelf(agent);
    Connection::registerSelf(agent);
    Link::registerSelf(agent);
    Bridge::registerSelf(agent);
    Session::registerSelf(agent);
    ManagementSetupState::registerSelf(agent);
    EventClientConnect::registerSelf(agent);
    EventClientConnectFail::registerSelf(agent);
    EventClientDisconnect::registerSelf(agent);
    EventBrokerLinkUp::registerSelf(agent);
    EventBrokerLinkDown::registerSelf(agent);
    EventQueueDeclare::registerSelf(agent);
    EventQueueDelete::registerSelf(agent);
    EventExchangeDeclare::registerSelf(agent);
    EventExchangeDelete::registerSelf(agent);
    EventBind::registerSelf(agent);
    EventUnbind::registerSelf(agent);
    EventSubscribe::registerSelf(agent);
    EventUnsubscribe::registerSelf(agent);
    EventQueueThresholdExceeded::registerSelf(agent);

}

