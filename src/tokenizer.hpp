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
