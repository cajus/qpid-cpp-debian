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


#include <string>
#include <sstream>

namespace qpid {
namespace amqp_0_10 {


namespace {

struct Names
{
    Names() {
        for (int i =0; i < 256; ++i) {
            std::ostringstream os;
            os << "UnknownType<" << i << ">";
            names[i] = os.str();
        }
        names[0x00] = "bin8";
        names[0x01] = "int8";
        names[0x02] = "uint8";
        names[0x04] = "char";
        names[0x08] = "boolean";
        names[0x10] = "bin16";
        names[0x11] = "int16";
        names[0x12] = "uint16";
        names[0x20] = "bin32";
        names[0x21] = "int32";
        names[0x22] = "uint32";
        names[0x23] = "float";
        names[0x27] = "char-utf32";
        names[0x30] = "bin64";
        names[0x31] = "int64";
        names[0x32] = "uint64";
        names[0x33] = "double";
        names[0x38] = "datetime";
        names[0x40] = "bin128";
        names[0x48] = "uuid";
        names[0x50] = "bin256";
        names[0x60] = "bin512";
        names[0x70] = "bin1024";
        names[0x80] = "vbin8";
        names[0x84] = "str8-latin";
        names[0x85] = "str8";
        names[0x86] = "str8-utf16";
        names[0x90] = "vbin16";
        names[0x94] = "str16-latin";
        names[0x95] = "str16";
        names[0x96] = "str16-utf16";
        names[0xa0] = "vbin32";
        names[0xa8] = "map";
        names[0xa9] = "list";
        names[0xaa] = "array";
        names[0xab] = "struct32";
        names[0xc0] = "bin40";
        names[0xc8] = "dec32";
        names[0xd0] = "bin72";
        names[0xd8] = "dec64";
        names[0xf0] = "void";
        names[0xf1] = "bit";
    }
    std::string names[256];
};
Names names;

} // namespace 

std::string typeName(uint8_t code) { return names.names[code]; }

}} // namespace qpid::amqp_0_10

