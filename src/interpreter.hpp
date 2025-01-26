#pragma once
#include <iostream>
#include <string>
#include "C_typing.hpp"

void check_type(Token token, TokenType type){
    if (token.type != type){
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
                Token msg = tokens.at(i + 1);
                check_type(msg, TokenType::Colon);

                Token msg2 = tokens.at(i + 2);
                check_type(msg2, TokenType::String);

                std::cout << msg2.value << "\n";
            } else if (token.value.compare("ret") == 0){
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