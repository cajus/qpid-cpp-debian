#ifndef QPID_HA_REPLICATIONTEST_H
#define QPID_HA_REPLICATIONTEST_H

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

#include "types.h"
#include "qpid/types/Variant.h"
#include <string>

namespace qpid {

namespace broker {
class Queue;
}

namespace framing {
class FieldTable;
}

namespace ha {
/**
 * Test whether something is replicated, taking into account the
 * default replication level.
 */
class ReplicationTest
{
  public:
    ReplicationTest(ReplicateLevel replicateDefault_) :
        replicateDefault(replicateDefault_) {}

    // Return the simple replication level, accounting for defaults.
    ReplicateLevel replicateLevel(const std::string& str);
    ReplicateLevel replicateLevel(const framing::FieldTable& f);
    ReplicateLevel replicateLevel(const types::Variant::Map& m);

    // Return true if replication for a queue is enabled at level or higher,
    // taking account of default level and queue settings.
    bool isReplicated(ReplicateLevel level,
                      const types::Variant::Map& args, bool autodelete, bool exclusive);
    bool isReplicated(ReplicateLevel level,
                      const framing::FieldTable& args, bool autodelete, bool exclusive);
    bool isReplicated(ReplicateLevel level, const broker::Queue&);
  private:
    ReplicateLevel replicateDefault;
};
}} // namespace qpid::ha

#endif  /*!QPID_HA_REPLICATIONTEST_H*/
