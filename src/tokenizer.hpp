/****************************************************************************/
/* tokenizer.hpp                                                            */
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

#ifndef __TOKENIZER_HPP__
#define __TOKENIZER_HPP__

#include "input_args.hpp"

#include <string>
#include <vector>

enum TokenType {
    TokenType_Primitive
};

struct Token {
    std::string name{};
    bool is_primitive{ true };

    Token(const std::string& name, bool is_primitive = true);
};

struct TokenObject : public Token {
    std::vector<Token> members{};

    TokenObject(const std::string& name);
};

struct TokenScope {
    std::vector<Token> tokens{};
    std::vector<TokenScope> scopes{};
};

struct Tokenizer {
    std::vector<TokenScope> scopes{};
};

bool tokenize_sources(Tokenizer& tokenizer, const Input& input);

#endif // __TOKENIZER_HPP__
