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
    static void print(const std::string& message, DebugType debug_type = DebugType_Message);

private:
    static bool m_enabled;
};

#endif // __DEBUG_HPP__
