#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class TokenType{
    String,
    Int,
    Keyword,
    Identifier,
    Semicolon, Colon,
    Openparam, Closeparam,
    MathOperator
};

typedef struct {
    std::string value;
    TokenType type;
} Token;

typedef std::vector<Token> Tokens;