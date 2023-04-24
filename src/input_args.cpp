#include "input_args.hpp"
#include "debug.hpp"

bool read_args(Input& input, int argc, char** argv) {
    input.args.resize(argc);

    for (size_t i = 0; i < input.args.size(); i++) {
        input.args[i] = argv[i];
    }

    bool result = interpret_commands(input);
    if (Debug::is_enabled()) {
        std::string message = "debug is enabled, args:\n";
        for (const std::string& arg : input.args) {
            message += "*\t" + arg + "\n";
        }

        Debug::print(message);
    }

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
                    command |= InputArgCommand_EnableDebug;
                    continue;

                case 's': command |= InputArgCommand_DefinedSources;        break;
                case 'r': command |= InputArgCommand_GenReflectionFileDest; break;
                case 'c': command |= InputArgCommand_GenCMakeFileDest;      break;
                }

                if (input.defined_commands & command) {
                    Debug::print("command defined more than once, will remove command at offset: " + std::to_string(i), DebugType_Warning);
                }
                else if (command == InputArgCommand_Invalid) {
                    Debug::print("invalid command at offset " + std::to_string(i), DebugType_Error);
                    return false;
                }
                else {
                    input.commands.push_back(CommandInput { command, i });
                }
            }
        }

        return true;
    }

    return false;
}
