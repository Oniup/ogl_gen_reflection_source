/****************************************************************************/
/* debug.hpp                                                                */
/* This file is part of: ogl_gen_reflection_source                          */
/****************************************************************************/
/* Copyright 2023 Ewan Robson                                               */
/*                                                                          */
/* Licensed under the Apache License, Version 2.0 (the "License");          */
/* you may not use this file except in compliance with the License.         */
/* You may obtain a copy of the License at                                  */
/*                                                                          */
/*     http://www.apache.org/licenses/LICENSE-2.0                           */
/*                                                                          */
/* Unless required by applicable law or agreed to in writing, software      */
/* distributed under the License is distributed on an "AS IS" BASIS,        */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/* See the License for the specific language governing permissions and      */
/* limitations under the License.                                           */
/****************************************************************************/

#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__

#include <string>

enum DebugType {
    DebugType_Message,
    DebugType_Warning,
    DebugType_Error
};

struct Debug {
    static void enable();
    static inline bool is_enabled() { return m_enabled; }
    static void log(const std::string& message, DebugType debug_type = DebugType_Message);

private:
    static bool m_enabled;
};

#endif // __DEBUG_HPP__
