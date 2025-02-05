#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <cstring>
#include "C_typing.hpp"

class Lexer {
    public:
    inline explicit Lexer(std::string content) : src(std::move(content)) {};
    inline Tokens tokenize() {
        Tokens tokens {};
        std::string buffer;

        while (this->peak().has_value()) {
            if (std::isalpha(this->peak().value())) {
                while (this->peak().has_value() && std::isalpha(this->peak().value())) {
                    buffer.push_back(this->consume());
                }

                if (buffer.compare("return") == 0) {
                    tokens.push_back({ "return", TokenType::Keyword });
                }
                buffer.clear();
            }
            else if (std::isdigit(this->peak().value())) {
                while (this->peak().has_value() && std::isdigit(this->peak().value())) {
                    buffer.push_back(this->consume());
                }

                tokens.push_back({ buffer, TokenType::Int });
                buffer.clear();
            }
            else if (this->peak().value() == ';') {
                tokens.push_back({ "", TokenType::Semicolon });
                this->consume();
            }
            else if (this->peak().value() == ',') {
                tokens.push_back({ "", TokenType::Colon });
                this->consume();
            }
            else if (this->peak().value() == '(') {
                tokens.push_back({ "", TokenType::Openparam });
                this->consume();
            }
            else if (this->peak().value() == ')') {
                tokens.push_back({ "", TokenType::Closeparam });
                this->consume();
            }
            else if (std::isblank(this->peak().value())) {
                this->consume();
                continue;
            }
            else {
                if (peak().value() == '+' || peak().value() == '-' || peak().value() == '*' || peak().value() == '/') {
                    buffer += this->consume();
                    tokens.push_back({ buffer, TokenType::MathOperator });
                    buffer.clear();
                } else {
                    while (this->peak().has_value() && std::isalnum(this->peak().value())) {
                        buffer.push_back(this->consume());
                    }

                    std::cout << "[ERROR] Unkown character: " << buffer << "\n";
                    buffer.clear();
                }
            }
        }

        return tokens;
    };
    private:
    std::string src;
    size_t index = 0;
    inline std::optional<char> peak(int peak_n = 1) const {
        if (this->index + peak_n <= this->src.length()) {
            return this->src.at(this->index);
        } else {
            return {};
        }
    }
    inline char consume() {
        return this->src.at(this->index++);
    }
};
