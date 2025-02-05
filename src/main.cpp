#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "lexer.hpp"
#include "C_typing.hpp"

std::string readfile(std::string name){
    std::ostringstream oss;
    std::ifstream file(name);
    if (!file.is_open())
    {
        std::cout << "Could not open dir.\n";
        exit(1);
    }
    oss << file.rdbuf();

    file.close();
    return oss.str();
}

void checkout(int argc){
    if (argc < 2)
    {
        std::cout << "Argument 'file' missing.\n";
        exit(0);
    }
}

int main(int argc, char* argv[]){
    checkout(argc);
    std::string content = readfile(argv[1]);
    Lexer* lexer = new Lexer(content);
    Tokens tokens = lexer->tokenize();

    delete lexer;
    return 0;
}