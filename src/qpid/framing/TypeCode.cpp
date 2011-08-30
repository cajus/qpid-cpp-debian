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


#include "qpid/framing/TypeCode.h"
#include "qpid/Exception.h"
#include "qpid/Msg.h"
#include <ostream>

namespace qpid {
namespace framing {

const char* typeName(TypeCode t) {
    switch (t) {
        case TYPE_CODE_BIN8: return "bin8";
        case TYPE_CODE_INT8: return "int8";
        case TYPE_CODE_UINT8: return "uint8";
        case TYPE_CODE_CHAR: return "char";
        case TYPE_CODE_BOOLEAN: return "boolean";
        case TYPE_CODE_BIN16: return "bin16";
        case TYPE_CODE_INT16: return "int16";
        case TYPE_CODE_UINT16: return "uint16";
        case TYPE_CODE_BIN32: return "bin32";
        case TYPE_CODE_INT32: return "int32";
        case TYPE_CODE_UINT32: return "uint32";
        case TYPE_CODE_FLOAT: return "float";
        case TYPE_CODE_CHAR_UTF32: return "char-utf32";
        case TYPE_CODE_BIN64: return "bin64";
        case TYPE_CODE_INT64: return "int64";
        case TYPE_CODE_UINT64: return "uint64";
        case TYPE_CODE_DOUBLE: return "double";
        case TYPE_CODE_DATETIME: return "datetime";
        case TYPE_CODE_BIN128: return "bin128";
        case TYPE_CODE_UUID: return "uuid";
        case TYPE_CODE_BIN256: return "bin256";
        case TYPE_CODE_BIN512: return "bin512";
        case TYPE_CODE_BIN1024: return "bin1024";
        case TYPE_CODE_VBIN8: return "vbin8";
        case TYPE_CODE_STR8_LATIN: return "str8-latin";
        case TYPE_CODE_STR8: return "str8";
        case TYPE_CODE_STR8_UTF16: return "str8-utf16";
        case TYPE_CODE_VBIN16: return "vbin16";
        case TYPE_CODE_STR16_LATIN: return "str16-latin";
        case TYPE_CODE_STR16: return "str16";
        case TYPE_CODE_STR16_UTF16: return "str16-utf16";
        case TYPE_CODE_VBIN32: return "vbin32";
        case TYPE_CODE_MAP: return "map";
        case TYPE_CODE_LIST: return "list";
        case TYPE_CODE_ARRAY: return "array";
        case TYPE_CODE_STRUCT32: return "struct32";
        case TYPE_CODE_BIN40: return "bin40";
        case TYPE_CODE_DEC32: return "dec32";
        case TYPE_CODE_BIN72: return "bin72";
        case TYPE_CODE_DEC64: return "dec64";
        case TYPE_CODE_VOID: return "void";
        case TYPE_CODE_BIT: return "bit";
        default: break;
    }
    return 0;
}

bool isTypeCode(uint8_t t) { return typeName(TypeCode(t)); }

TypeCode typeCode(uint8_t t) {
    if (!isTypeCode(t)) throw Exception(QPID_MSG("Invalid TypeCode " << t));
    return TypeCode(t);
}

std::ostream& operator<<(std::ostream& o, TypeCode t) {
    if (isTypeCode(t)) return o << typeName(t);
    else return o << "Invalid TypeCode " << t;
}


}} // namespace qpid::framing

