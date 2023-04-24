#include "debug.hpp"

#include <iostream>

bool Debug::m_enabled = false;

void Debug::enable() {
    m_enabled = true;
}

void Debug::print(const std::string& message, DebugType debug_type) {
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
        std::cout << message;
    }
}
