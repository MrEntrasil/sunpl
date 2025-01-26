#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "C_typing.hpp"

Tokens Tokenize(std::string content){
    Tokens tokens {};

    for (int i = 0;i < content.length();i++)
    {
        char c = content.at(i);

        if (std::isdigit(c))
        {
            std::string v;
            v.push_back(c);

            i++;
            while (std::isdigit(content.at(i)))
            {
                v.push_back(content.at(i));
                i++;
            }
            i--;

            tokens.push_back({ .value = v, .type = TokenType::Int });
            v.clear();
        }
        else if (std::isalpha(c))
        {
            std::string v;
            v.push_back(c);

            i++;
            while (std::isalpha(content.at(i)))
            {
                v.push_back(content.at(i));
                i++;
            }
            i--;

            if (v.compare("ret") == 0)
            {
                tokens.push_back({ .value = "ret", .type = TokenType::Keyword });
            }
            else if (v.compare("show") == 0) {
                tokens.push_back({ .value = "show", .type = TokenType::Keyword });
            }
            else if (v.compare("slknumcompensa") == 0) {
                tokens.push_back({ .value = "slknumcompensa", .type = TokenType::Keyword });
            }
            v.clear();
            continue;
        }
        else if (c == ';')
        {
            tokens.push_back({ .value = "", .type = TokenType::Semicolon });
            continue;
        }
        else if (c == '[')
        {
            std::string v;
            i++;

            while (true){
                if (content.at(i) == ']')
                {
                    break;
                }
                else
                {
                    v.push_back(content.at(i));
                    i++;
                }
            }

            tokens.push_back({ .value = v, .type = TokenType::String });
            v.clear();
            continue;
        }
        else if (c == ',')
        {
            tokens.push_back({ .value = "", .type = TokenType::Colon });
        }
        else if (c == '#')
        {
            while (true){
                if (content.at(i) == '\n')
                {
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
    }

    return tokens;
}