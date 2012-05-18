#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

# This source file was created by a code generator.
# Please do not edit.




mgen_generator=$(mgen_dir)/qmf-gen \
    $(mgen_dir)/qmfgen/generate.py \
    $(mgen_dir)/qmfgen/schema.py \
    $(mgen_dir)/qmfgen/management-types.xml \
    $(top_srcdir)/../specs/management-schema.xml \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Class.h \
    $(mgen_dir)/qmfgen/templates/Class.cpp \
    $(mgen_dir)/qmfgen/templates/Args.h \
    $(mgen_dir)/qmfgen/templates/Event.h \
    $(mgen_dir)/qmfgen/templates/Event.cpp \
    $(mgen_dir)/qmfgen/templates/Package.h \
    $(mgen_dir)/qmfgen/templates/Package.cpp \
    $(mgen_dir)/qmfgen/templates/Makefile.mk

mgen_broker_cpp=qmf/org/apache/qpid/broker/System.cpp \
    qmf/org/apache/qpid/broker/Memory.cpp \
    qmf/org/apache/qpid/broker/Broker.cpp \
    qmf/org/apache/qpid/broker/Agent.cpp \
    qmf/org/apache/qpid/broker/Vhost.cpp \
    qmf/org/apache/qpid/broker/Queue.cpp \
    qmf/org/apache/qpid/broker/Exchange.cpp \
    qmf/org/apache/qpid/broker/Binding.cpp \
    qmf/org/apache/qpid/broker/Subscription.cpp \
    qmf/org/apache/qpid/broker/Connection.cpp \
    qmf/org/apache/qpid/broker/Link.cpp \
    qmf/org/apache/qpid/broker/Bridge.cpp \
    qmf/org/apache/qpid/broker/Session.cpp \
    qmf/org/apache/qpid/broker/ManagementSetupState.cpp \
    qmf/org/apache/qpid/broker/EventClientConnect.cpp \
    qmf/org/apache/qpid/broker/EventClientConnectFail.cpp \
    qmf/org/apache/qpid/broker/EventClientDisconnect.cpp \
    qmf/org/apache/qpid/broker/EventBrokerLinkUp.cpp \
    qmf/org/apache/qpid/broker/EventBrokerLinkDown.cpp \
    qmf/org/apache/qpid/broker/EventQueueDeclare.cpp \
    qmf/org/apache/qpid/broker/EventQueueDelete.cpp \
    qmf/org/apache/qpid/broker/EventExchangeDeclare.cpp \
    qmf/org/apache/qpid/broker/EventExchangeDelete.cpp \
    qmf/org/apache/qpid/broker/EventBind.cpp \
    qmf/org/apache/qpid/broker/EventUnbind.cpp \
    qmf/org/apache/qpid/broker/EventSubscribe.cpp \
    qmf/org/apache/qpid/broker/EventUnsubscribe.cpp \
    qmf/org/apache/qpid/broker/EventQueueThresholdExceeded.cpp \
    qmf/org/apache/qpid/broker/Package.cpp \
    qmf/org/apache/qpid/acl/Acl.cpp \
    qmf/org/apache/qpid/acl/EventAllow.cpp \
    qmf/org/apache/qpid/acl/EventDeny.cpp \
    qmf/org/apache/qpid/acl/EventFileLoaded.cpp \
    qmf/org/apache/qpid/acl/EventFileLoadFailed.cpp \
    qmf/org/apache/qpid/acl/Package.cpp \
    qmf/org/apache/qpid/cluster/Cluster.cpp \
    qmf/org/apache/qpid/cluster/Package.cpp \
    qmf/org/apache/qpid/ha/HaBroker.cpp \
    qmf/org/apache/qpid/ha/Package.cpp

# Header file install rules.
org_apache_qpid_brokerdir = $(includedir)/qmf/org/apache/qpid/broker
dist_org_apache_qpid_broker_HEADERS = qmf/org/apache/qpid/broker/System.h \
    qmf/org/apache/qpid/broker/Memory.h \
    qmf/org/apache/qpid/broker/Broker.h \
    qmf/org/apache/qpid/broker/Agent.h \
    qmf/org/apache/qpid/broker/Vhost.h \
    qmf/org/apache/qpid/broker/Queue.h \
    qmf/org/apache/qpid/broker/Exchange.h \
    qmf/org/apache/qpid/broker/Binding.h \
    qmf/org/apache/qpid/broker/Subscription.h \
    qmf/org/apache/qpid/broker/Connection.h \
    qmf/org/apache/qpid/broker/Link.h \
    qmf/org/apache/qpid/broker/Bridge.h \
    qmf/org/apache/qpid/broker/Session.h \
    qmf/org/apache/qpid/broker/ManagementSetupState.h \
    qmf/org/apache/qpid/broker/ArgsBrokerEcho.h \
    qmf/org/apache/qpid/broker/ArgsBrokerConnect.h \
    qmf/org/apache/qpid/broker/ArgsBrokerQueueMoveMessages.h \
    qmf/org/apache/qpid/broker/ArgsBrokerSetLogLevel.h \
    qmf/org/apache/qpid/broker/ArgsBrokerGetLogLevel.h \
    qmf/org/apache/qpid/broker/ArgsBrokerGetTimestampConfig.h \
    qmf/org/apache/qpid/broker/ArgsBrokerSetTimestampConfig.h \
    qmf/org/apache/qpid/broker/ArgsBrokerCreate.h \
    qmf/org/apache/qpid/broker/ArgsBrokerDelete.h \
    qmf/org/apache/qpid/broker/ArgsBrokerQuery.h \
    qmf/org/apache/qpid/broker/ArgsQueuePurge.h \
    qmf/org/apache/qpid/broker/ArgsQueueReroute.h \
    qmf/org/apache/qpid/broker/ArgsLinkBridge.h \
    qmf/org/apache/qpid/broker/EventClientConnect.h \
    qmf/org/apache/qpid/broker/EventClientConnectFail.h \
    qmf/org/apache/qpid/broker/EventClientDisconnect.h \
    qmf/org/apache/qpid/broker/EventBrokerLinkUp.h \
    qmf/org/apache/qpid/broker/EventBrokerLinkDown.h \
    qmf/org/apache/qpid/broker/EventQueueDeclare.h \
    qmf/org/apache/qpid/broker/EventQueueDelete.h \
    qmf/org/apache/qpid/broker/EventExchangeDeclare.h \
    qmf/org/apache/qpid/broker/EventExchangeDelete.h \
    qmf/org/apache/qpid/broker/EventBind.h \
    qmf/org/apache/qpid/broker/EventUnbind.h \
    qmf/org/apache/qpid/broker/EventSubscribe.h \
    qmf/org/apache/qpid/broker/EventUnsubscribe.h \
    qmf/org/apache/qpid/broker/EventQueueThresholdExceeded.h \
    qmf/org/apache/qpid/broker/Package.h

org_apache_qpid_acldir = $(includedir)/qmf/org/apache/qpid/acl
dist_org_apache_qpid_acl_HEADERS = qmf/org/apache/qpid/acl/Acl.h \
    qmf/org/apache/qpid/acl/EventAllow.h \
    qmf/org/apache/qpid/acl/EventDeny.h \
    qmf/org/apache/qpid/acl/EventFileLoaded.h \
    qmf/org/apache/qpid/acl/EventFileLoadFailed.h \
    qmf/org/apache/qpid/acl/Package.h

org_apache_qpid_clusterdir = $(includedir)/qmf/org/apache/qpid/cluster
dist_org_apache_qpid_cluster_HEADERS = qmf/org/apache/qpid/cluster/Cluster.h \
    qmf/org/apache/qpid/cluster/ArgsClusterStopClusterNode.h \
    qmf/org/apache/qpid/cluster/Package.h

org_apache_qpid_hadir = $(includedir)/qmf/org/apache/qpid/ha
dist_org_apache_qpid_ha_HEADERS = qmf/org/apache/qpid/ha/HaBroker.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerSetBrokers.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerSetPublicBrokers.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerSetExpectedBackups.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerReplicate.h \
    qmf/org/apache/qpid/ha/Package.h


if GENERATE
$(srcdir)/managementgen.mk: $(mgen_generator)
	$(mgen_cmd)

$(mgen_generator):
endif


qmfgen_sources=qmf/org/apache/qpid/broker/System.h \
    qmf/org/apache/qpid/broker/Memory.h \
    qmf/org/apache/qpid/broker/Broker.h \
    qmf/org/apache/qpid/broker/Agent.h \
    qmf/org/apache/qpid/broker/Vhost.h \
    qmf/org/apache/qpid/broker/Queue.h \
    qmf/org/apache/qpid/broker/Exchange.h \
    qmf/org/apache/qpid/broker/Binding.h \
    qmf/org/apache/qpid/broker/Subscription.h \
    qmf/org/apache/qpid/broker/Connection.h \
    qmf/org/apache/qpid/broker/Link.h \
    qmf/org/apache/qpid/broker/Bridge.h \
    qmf/org/apache/qpid/broker/Session.h \
    qmf/org/apache/qpid/broker/ManagementSetupState.h \
    qmf/org/apache/qpid/broker/ArgsBrokerEcho.h \
    qmf/org/apache/qpid/broker/ArgsBrokerConnect.h \
    qmf/org/apache/qpid/broker/ArgsBrokerQueueMoveMessages.h \
    qmf/org/apache/qpid/broker/ArgsBrokerSetLogLevel.h \
    qmf/org/apache/qpid/broker/ArgsBrokerGetLogLevel.h \
    qmf/org/apache/qpid/broker/ArgsBrokerGetTimestampConfig.h \
    qmf/org/apache/qpid/broker/ArgsBrokerSetTimestampConfig.h \
    qmf/org/apache/qpid/broker/ArgsBrokerCreate.h \
    qmf/org/apache/qpid/broker/ArgsBrokerDelete.h \
    qmf/org/apache/qpid/broker/ArgsBrokerQuery.h \
    qmf/org/apache/qpid/broker/ArgsQueuePurge.h \
    qmf/org/apache/qpid/broker/ArgsQueueReroute.h \
    qmf/org/apache/qpid/broker/ArgsLinkBridge.h \
    qmf/org/apache/qpid/broker/EventClientConnect.h \
    qmf/org/apache/qpid/broker/EventClientConnectFail.h \
    qmf/org/apache/qpid/broker/EventClientDisconnect.h \
    qmf/org/apache/qpid/broker/EventBrokerLinkUp.h \
    qmf/org/apache/qpid/broker/EventBrokerLinkDown.h \
    qmf/org/apache/qpid/broker/EventQueueDeclare.h \
    qmf/org/apache/qpid/broker/EventQueueDelete.h \
    qmf/org/apache/qpid/broker/EventExchangeDeclare.h \
    qmf/org/apache/qpid/broker/EventExchangeDelete.h \
    qmf/org/apache/qpid/broker/EventBind.h \
    qmf/org/apache/qpid/broker/EventUnbind.h \
    qmf/org/apache/qpid/broker/EventSubscribe.h \
    qmf/org/apache/qpid/broker/EventUnsubscribe.h \
    qmf/org/apache/qpid/broker/EventQueueThresholdExceeded.h \
    qmf/org/apache/qpid/broker/Package.h \
    qmf/org/apache/qpid/acl/Acl.h \
    qmf/org/apache/qpid/acl/EventAllow.h \
    qmf/org/apache/qpid/acl/EventDeny.h \
    qmf/org/apache/qpid/acl/EventFileLoaded.h \
    qmf/org/apache/qpid/acl/EventFileLoadFailed.h \
    qmf/org/apache/qpid/acl/Package.h \
    qmf/org/apache/qpid/cluster/Cluster.h \
    qmf/org/apache/qpid/cluster/ArgsClusterStopClusterNode.h \
    qmf/org/apache/qpid/cluster/Package.h \
    qmf/org/apache/qpid/ha/HaBroker.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerSetBrokers.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerSetPublicBrokers.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerSetExpectedBackups.h \
    qmf/org/apache/qpid/ha/ArgsHaBrokerReplicate.h \
    qmf/org/apache/qpid/ha/Package.h \
    qmf/org/apache/qpid/broker/System.cpp \
    qmf/org/apache/qpid/broker/Memory.cpp \
    qmf/org/apache/qpid/broker/Broker.cpp \
    qmf/org/apache/qpid/broker/Agent.cpp \
    qmf/org/apache/qpid/broker/Vhost.cpp \
    qmf/org/apache/qpid/broker/Queue.cpp \
    qmf/org/apache/qpid/broker/Exchange.cpp \
    qmf/org/apache/qpid/broker/Binding.cpp \
    qmf/org/apache/qpid/broker/Subscription.cpp \
    qmf/org/apache/qpid/broker/Connection.cpp \
    qmf/org/apache/qpid/broker/Link.cpp \
    qmf/org/apache/qpid/broker/Bridge.cpp \
    qmf/org/apache/qpid/broker/Session.cpp \
    qmf/org/apache/qpid/broker/ManagementSetupState.cpp \
    qmf/org/apache/qpid/broker/EventClientConnect.cpp \
    qmf/org/apache/qpid/broker/EventClientConnectFail.cpp \
    qmf/org/apache/qpid/broker/EventClientDisconnect.cpp \
    qmf/org/apache/qpid/broker/EventBrokerLinkUp.cpp \
    qmf/org/apache/qpid/broker/EventBrokerLinkDown.cpp \
    qmf/org/apache/qpid/broker/EventQueueDeclare.cpp \
    qmf/org/apache/qpid/broker/EventQueueDelete.cpp \
    qmf/org/apache/qpid/broker/EventExchangeDeclare.cpp \
    qmf/org/apache/qpid/broker/EventExchangeDelete.cpp \
    qmf/org/apache/qpid/broker/EventBind.cpp \
    qmf/org/apache/qpid/broker/EventUnbind.cpp \
    qmf/org/apache/qpid/broker/EventSubscribe.cpp \
    qmf/org/apache/qpid/broker/EventUnsubscribe.cpp \
    qmf/org/apache/qpid/broker/EventQueueThresholdExceeded.cpp \
    qmf/org/apache/qpid/broker/Package.cpp \
    qmf/org/apache/qpid/acl/Acl.cpp \
    qmf/org/apache/qpid/acl/EventAllow.cpp \
    qmf/org/apache/qpid/acl/EventDeny.cpp \
    qmf/org/apache/qpid/acl/EventFileLoaded.cpp \
    qmf/org/apache/qpid/acl/EventFileLoadFailed.cpp \
    qmf/org/apache/qpid/acl/Package.cpp \
    qmf/org/apache/qpid/cluster/Cluster.cpp \
    qmf/org/apache/qpid/cluster/Package.cpp \
    qmf/org/apache/qpid/ha/HaBroker.cpp \
    qmf/org/apache/qpid/ha/Package.cpp

