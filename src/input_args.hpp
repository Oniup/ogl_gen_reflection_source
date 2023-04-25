/****************************************************************************/
/* input_args.hpp                                                           */
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
