#pragma once
#include <iostream>
#include <string>
#include "C_typing.hpp"

void assert_type(Tokens tokens, int n, TokenType type){
    if (tokens.size() < n || tokens.at(n).type != type){
        std::cout << "Syntax error: type checking failed.\n";
        exit(1);
    }
}

void Run(Tokens tokens){
    bool exited = false;
    for (int i = 0;i < tokens.size();i++){
        const Token token = tokens.at(i);

        if (token.type == TokenType::Keyword){
            if (token.value.compare("show") == 0){
                assert_type(tokens, i + 1, TokenType::String);
                assert_type(tokens, i + 2, TokenType::Semicolon);

                std::cout << tokens.at(i + 1).value << "\n";
            } else if (token.value.compare("ret") == 0){
                assert_type(tokens, i + 1, TokenType::Int);
                std::string exitCode = tokens.at(i + 1).value;
                if (exitCode.compare("0") == 0)
                    std::cout << "Program exited with code: 0\n";
                else if (exitCode.compare("1") == 0)
                    std::cout << "Program failed with code: 1\n";
                else
                    std::cout << "Program exited with an unkown code\n";
                exited = true;
            } else if (token.value.compare("slknumcompensa") == 0){
                std::cout << "Slk, num compensa\n";
            }
        }
    }

    if (!exited)
        std::cout << "Program exited with code: !true\n";
        exit(1);
}