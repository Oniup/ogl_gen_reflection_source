#ifndef __input_HPP__
#define __input_HPP__

#include <vector>
#include <string>
#include <array>

typedef int InputArgCommand;

enum InputArgCommand_ {
    InputArgCommand_EnableDebug             = 1 << 1,
    InputArgCommand_DefinedSources          = 1 << 2,
    InputArgCommand_GenReflectionFileDest   = 1 << 3,
    InputArgCommand_GenCMakeFileDest        = 1 << 4,
    InputArgCommand_Invalid                 = 1 << 31,
};

struct CommandInput {
    InputArgCommand command{ InputArgCommand_Invalid };
    size_t arg_offset{};
};

struct Input {
    InputArgCommand defined_commands{};
    std::vector<std::string> args{};
    std::vector<CommandInput> commands{};
};

struct SourceDestination {
    std::vector<std::string> sources{};
    std::string reflection_destination{};
    std::string cmake_destination{};
};

bool read_args(Input& input, int argc, char** argv);
bool interpret_commands(Input& input);

bool get_source_locations(SourceDestination& source_destination, const Input& input);

#endif // __input_HPP__
