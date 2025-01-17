#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Keyword {
    char* Ret;
};
struct Keyword keyword = { "ret" };

enum TokenLT {
    TokenLT_String,
    TokenLT_Int,
    TokenLT_Keyword
};

typedef struct {
    enum TokenLT type;
    char* value;
} Token;

Token* MakeKeyword(FILE* file, char current){
    Token* token = malloc(sizeof(token));
    char* buff = malloc(sizeof(char));
    int i = 0;

    while (isalpha(current) && current != EOF){
        if (!isalpha(current)){
            break;
        }
        buff[i] = current;
        i++;
        current = fgetc(file);
    }

    token->type = TokenLT_Keyword;
    if (strcmp((const char*)buff, "ret") == 0){
        token->value = keyword.Ret;
    };

    return token;
}

Token* MakeInt(FILE* file, char current){
    char* buff = malloc(sizeof(char) * 8);
    Token* token = malloc(sizeof(Token));
    token->type = TokenLT_Int;
    int i = 0;
    
    while (isdigit(current) && current != EOF){
        if (!isdigit(current)){
            break;
        }
        buff[i] = current;
        i++;
        current = fgetc(file);
    }
    token->value = buff;

    return token;
}

void Tokenize(FILE* file){
    char current = fgetc(file);

    while (current != EOF){
        if (current == ';'){
            printf("Found(Semi): %c\n", current);
        } else if (current == '('){
            printf("Found(Open_Param): %c\n", current);
        } else if (current == ')'){
            printf("Found(Close_Param): %c\n", current);
        } else if (isdigit(current)){
            Token* token = MakeInt(file, current);
            printf("Found(Int): %s\n", token->value);
        }
        current = fgetc(file);
    }
}