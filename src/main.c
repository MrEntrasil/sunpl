#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(void){
    FILE* file;
    file = fopen("index.sn", "r");
    Tokenize(file);

    fclose(file);
    return 0;
}
