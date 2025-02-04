#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class TokenType{
    String,
    Int,
    Keyword,
    Identifier,
    Semicolon, Colon,
    Openparam, Closeparam
};

typedef struct {
    std::string value;
    TokenType type;
} Token;

typedef std::vector<Token> Tokens;