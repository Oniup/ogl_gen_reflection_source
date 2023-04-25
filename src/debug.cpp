/****************************************************************************/
/* debug.cpp                                                                */
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

#include "debug.hpp"

#include <iostream>

bool Debug::m_enabled = false;

void Debug::enable() {
    m_enabled = true;
}

void Debug::log(const std::string& message, DebugType debug_type) {
    if (m_enabled) {
        switch (debug_type) {
        case DebugType_Message:
            std::cout << "[Message]: ";
            break;

        case DebugType_Warning:
            std::cout << "[Warning]: ";
            break;

        case DebugType_Error:
            std::cout << "[Error]: ";
            break;
        }
        std::cout << message << "\n";
    }
}
