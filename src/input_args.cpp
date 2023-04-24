#include "input_args.hpp"
#include "debug.hpp"

#include <iostream>
#include <pthread.h>

bool read_args(Input& input, int argc, char** argv) {
    input.args.resize(argc);

    for (size_t i = 0; i < input.args.size(); i++) {
        input.args[i] = argv[i];
    }

    bool result = interpret_commands(input);
    Debug::log("Debug Logs is enabled");

    return result;
}

bool interpret_commands(Input& input) {
    if (input.args.size() > 1) {
        for (size_t i = 0; i < input.args.size(); i++) {
            const std::string& arg = input.args[i];
            InputArgCommand command = InputArgCommand_Invalid;

            if (arg[0] == '-') {
                switch (arg[1]) {
                case 'd':
                    Debug::enable();
                    input.defined_commands |= InputArgCommand_EnableDebug;
                    continue;

                case 's': command = InputArgCommand_DefinedSources;        break;
                case 'r': command = InputArgCommand_GenReflectionFileDest; break;
                case 'c': command = InputArgCommand_GenCMakeFileDest;      break;
                }

                if (input.defined_commands & command) {
                    Debug::log("Command defined more than once, will remove command at offset: " + std::to_string(i), DebugType_Warning);
                }
                else if (command == InputArgCommand_Invalid) {
                    Debug::log("Invalid command at offset " + std::to_string(i), DebugType_Error);
                    return false;
                }
                else {
                    input.defined_commands |= command;
                    input.commands.push_back(CommandInput { command, i });
                }
            }
        }

        return true;
    }

    return false;
}

bool get_source_locations(SourceDestination& source_destination, const Input& input) {
    for (const CommandInput& command : input.commands) {
        std::vector<std::string> sources{};

        for (size_t i = command.arg_offset + 1; i < input.args.size(); i++) {
            if (input.args[i][0] == '-') {
                break;
            }

            sources.push_back(input.args[i]);
        }

        if (sources.size() == 0) {
            Debug::log("Command doesn't have any input at command with offset: " + std::to_string(command.arg_offset), DebugType_Error);
            return false;
        }

        switch (command.command) {
        case InputArgCommand_Invalid:
            Debug::log("Invalid command, however this should never be called here", DebugType_Error);
            return false;

        case InputArgCommand_EnableDebug:
            Debug::log("For some reason there is another enable debug. This should never be called", DebugType_Error);
            return false;

        case InputArgCommand_DefinedSources:
            for (const std::string& path : sources) {
                FILE* file = fopen(path.c_str(), "r");
                if (file != nullptr) {
                    fclose(file);
                }
                else {
                    Debug::log("Source file doesn't exist: " + path, DebugType_Error);
                    return false;
                }
            }

            if (Debug::is_enabled()) {
                std::string message = "Sources:";
                for (const std::string& path : sources) {
                    message += "\n\t* " + path;
                }
                Debug::log(message);
            }

            source_destination.sources = sources;
            break;

        case InputArgCommand_GenReflectionFileDest:
            if (sources.size() > 1) {
                Debug::log("More than 1 reflection file paths were given. Note that will only be using the first one given", DebugType_Warning);
            }
            source_destination.reflection_destination = sources.front();
            Debug::log("Reflection gen path:\n\t* " + source_destination.reflection_destination);
            break;

        case InputArgCommand_GenCMakeFileDest:
            if (sources.size() > 1) {
                Debug::log("More than 1 cmake file paths were given. Note that will only be using the first one given", DebugType_Warning);
            }
            source_destination.cmake_destination = sources.front();
            Debug::log("CMake gen path:\n\t* " + source_destination.cmake_destination);
            break;
        }
    }

    return true;
}
