#ifndef QPID_FRAMING_AMQP_CLIENTPROXY_H
#define QPID_FRAMING_AMQP_CLIENTPROXY_H
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


#include "qpid/framing/Proxy.h"
#include "qpid/framing/Array.h"
#include "qpid/framing/amqp_types.h"
#include "qpid/framing/amqp_structs.h"
#include "qpid/CommonImportExport.h"

namespace qpid {
namespace framing {

class QPID_COMMON_CLASS_EXTERN AMQP_ClientProxy:
    public Proxy
{
  public:
    QPID_COMMON_EXTERN AMQP_ClientProxy(FrameHandler& out);
    
    class QPID_COMMON_CLASS_EXTERN Connection:
        public Proxy
    {
        public:
        Connection(FrameHandler& f) : Proxy(f) {}
        static Connection& get(AMQP_ClientProxy& proxy) { return proxy.getConnection(); }
        QPID_COMMON_EXTERN virtual void start(const FieldTable& serverProperties,
                    const Array& mechanisms,
                    const Array& locales);
        
        QPID_COMMON_EXTERN virtual void secure(const std::string& challenge);
        
        QPID_COMMON_EXTERN virtual void tune(uint16_t channelMax,
                    uint16_t maxFrameSize,
                    uint16_t heartbeatMin,
                    uint16_t heartbeatMax);
        
        QPID_COMMON_EXTERN virtual void openOk(const Array& knownHosts);
        
        QPID_COMMON_EXTERN virtual void redirect(const std::string& host,
                    const Array& knownHosts);
        
        QPID_COMMON_EXTERN virtual void heartbeat();
        
        QPID_COMMON_EXTERN virtual void close(uint16_t replyCode,
                    const std::string& replyText);
        
        QPID_COMMON_EXTERN virtual void closeOk();
        
    };
    
    Connection& getConnection() { return connectionProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Session:
        public Proxy
    {
        public:
        Session(FrameHandler& f) : Proxy(f) {}
        static Session& get(AMQP_ClientProxy& proxy) { return proxy.getSession(); }
        QPID_COMMON_EXTERN virtual void attach(const std::string& name,
                    bool force);
        
        QPID_COMMON_EXTERN virtual void attached(const std::string& name);
        
        QPID_COMMON_EXTERN virtual void detach(const std::string& name);
        
        QPID_COMMON_EXTERN virtual void detached(const std::string& name,
                    uint8_t code);
        
        QPID_COMMON_EXTERN virtual void requestTimeout(uint32_t timeout);
        
        QPID_COMMON_EXTERN virtual void timeout(uint32_t timeout);
        
        QPID_COMMON_EXTERN virtual void commandPoint(const SequenceNumber& commandId,
                    uint64_t commandOffset);
        
        QPID_COMMON_EXTERN virtual void expected(const SequenceSet& commands,
                    const Array& fragments);
        
        QPID_COMMON_EXTERN virtual void confirmed(const SequenceSet& commands,
                    const Array& fragments);
        
        QPID_COMMON_EXTERN virtual void completed(const SequenceSet& commands,
                    bool timelyReply);
        
        QPID_COMMON_EXTERN virtual void knownCompleted(const SequenceSet& commands);
        
        QPID_COMMON_EXTERN virtual void flush(bool expected,
                    bool confirmed,
                    bool completed);
        
        QPID_COMMON_EXTERN virtual void gap(const SequenceSet& commands);
        
    };
    
    Session& getSession() { return sessionProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Execution:
        public Proxy
    {
        public:
        Execution(FrameHandler& f) : Proxy(f) {}
        static Execution& get(AMQP_ClientProxy& proxy) { return proxy.getExecution(); }
        QPID_COMMON_EXTERN virtual void sync();
        
        QPID_COMMON_EXTERN virtual void result(const SequenceNumber& commandId,
                    const std::string& value);
        
        QPID_COMMON_EXTERN virtual void exception(uint16_t errorCode,
                    const SequenceNumber& commandId,
                    uint8_t classCode,
                    uint8_t commandCode,
                    uint8_t fieldIndex,
                    const std::string& description,
                    const FieldTable& errorInfo);
        
    };
    
    Execution& getExecution() { return executionProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Message:
        public Proxy
    {
        public:
        Message(FrameHandler& f) : Proxy(f) {}
        static Message& get(AMQP_ClientProxy& proxy) { return proxy.getMessage(); }
        QPID_COMMON_EXTERN virtual void transfer(const std::string& destination,
                    uint8_t acceptMode,
                    uint8_t acquireMode);
        
        QPID_COMMON_EXTERN virtual void accept(const SequenceSet& transfers);
        
        QPID_COMMON_EXTERN virtual void reject(const SequenceSet& transfers,
                    uint16_t code,
                    const std::string& text);
        
        QPID_COMMON_EXTERN virtual void release(const SequenceSet& transfers,
                    bool setRedelivered);
        
        QPID_COMMON_EXTERN virtual void resume(const std::string& destination,
                    const std::string& resumeId);
        
        QPID_COMMON_EXTERN virtual void setFlowMode(const std::string& destination,
                    uint8_t flowMode);
        
        QPID_COMMON_EXTERN virtual void flow(const std::string& destination,
                    uint8_t unit,
                    uint32_t value);
        
        QPID_COMMON_EXTERN virtual void stop(const std::string& destination);
        
    };
    
    Message& getMessage() { return messageProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Tx:
        public Proxy
    {
        public:
        Tx(FrameHandler& f) : Proxy(f) {}
        static Tx& get(AMQP_ClientProxy& proxy) { return proxy.getTx(); }
    };
    
    Tx& getTx() { return txProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Dtx:
        public Proxy
    {
        public:
        Dtx(FrameHandler& f) : Proxy(f) {}
        static Dtx& get(AMQP_ClientProxy& proxy) { return proxy.getDtx(); }
    };
    
    Dtx& getDtx() { return dtxProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Exchange:
        public Proxy
    {
        public:
        Exchange(FrameHandler& f) : Proxy(f) {}
        static Exchange& get(AMQP_ClientProxy& proxy) { return proxy.getExchange(); }
    };
    
    Exchange& getExchange() { return exchangeProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Queue:
        public Proxy
    {
        public:
        Queue(FrameHandler& f) : Proxy(f) {}
        static Queue& get(AMQP_ClientProxy& proxy) { return proxy.getQueue(); }
    };
    
    Queue& getQueue() { return queueProxy; }
    
    class QPID_COMMON_CLASS_EXTERN File:
        public Proxy
    {
        public:
        File(FrameHandler& f) : Proxy(f) {}
        static File& get(AMQP_ClientProxy& proxy) { return proxy.getFile(); }
        QPID_COMMON_EXTERN virtual void qosOk();
        
        QPID_COMMON_EXTERN virtual void consumeOk(const std::string& consumerTag);
        
        QPID_COMMON_EXTERN virtual void open(const std::string& identifier,
                    uint64_t contentSize);
        
        QPID_COMMON_EXTERN virtual void openOk(uint64_t stagedSize);
        
        QPID_COMMON_EXTERN virtual void stage();
        
        QPID_COMMON_EXTERN virtual void return_(uint16_t replyCode,
                    const std::string& replyText,
                    const std::string& exchange,
                    const std::string& routingKey);
        
        QPID_COMMON_EXTERN virtual void deliver(const std::string& consumerTag,
                    uint64_t deliveryTag,
                    bool redelivered,
                    const std::string& exchange,
                    const std::string& routingKey,
                    const std::string& identifier);
        
    };
    
    File& getFile() { return fileProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Stream:
        public Proxy
    {
        public:
        Stream(FrameHandler& f) : Proxy(f) {}
        static Stream& get(AMQP_ClientProxy& proxy) { return proxy.getStream(); }
        QPID_COMMON_EXTERN virtual void qosOk();
        
        QPID_COMMON_EXTERN virtual void consumeOk(const std::string& consumerTag);
        
        QPID_COMMON_EXTERN virtual void return_(uint16_t replyCode,
                    const std::string& replyText,
                    const std::string& exchange,
                    const std::string& routingKey);
        
        QPID_COMMON_EXTERN virtual void deliver(const std::string& consumerTag,
                    uint64_t deliveryTag,
                    const std::string& exchange,
                    const std::string& queue);
        
    };
    
    Stream& getStream() { return streamProxy; }
    
    class QPID_COMMON_CLASS_EXTERN Cluster:
        public Proxy
    {
        public:
        Cluster(FrameHandler& f) : Proxy(f) {}
        static Cluster& get(AMQP_ClientProxy& proxy) { return proxy.getCluster(); }
    };
    
    Cluster& getCluster() { return clusterProxy; }
    
    class QPID_COMMON_CLASS_EXTERN ClusterConnection:
        public Proxy
    {
        public:
        ClusterConnection(FrameHandler& f) : Proxy(f) {}
        static ClusterConnection& get(AMQP_ClientProxy& proxy) { return proxy.getClusterConnection(); }
    };
    
    ClusterConnection& getClusterConnection() { return clusterConnectionProxy; }
    
  private:
    Connection connectionProxy;
    Session sessionProxy;
    Execution executionProxy;
    Message messageProxy;
    Tx txProxy;
    Dtx dtxProxy;
    Exchange exchangeProxy;
    Queue queueProxy;
    File fileProxy;
    Stream streamProxy;
    Cluster clusterProxy;
    ClusterConnection clusterConnectionProxy;
};

}} // namespace qpid::framing

#endif  /*!QPID_FRAMING_AMQP_CLIENTPROXY_H*/
