#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../include/TokenType.h"
#include "../include/Lexer.h"


int main(int argc, char* argv[]) {
    FILE* martoon = fopen(argv[1], "r");
    if (martoon == NULL) {
        return 1;
    }

    fseek(martoon, 0, SEEK_END);
    size_t file_size = ftell(martoon);
    fseek(martoon, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(martoon);
        return 1;
    }
    fread(buffer, 1, file_size, martoon);
    buffer[file_size] = '\0';
    fclose(martoon);

    Token tokens[200] = {0};    
    size_t tokens_top = lex(buffer, file_size, tokens);

    for (size_t i = 0; i < tokens_top; ++i) {
        Token_display(&tokens[i]);
    }

    free(buffer);
    return 0;
}
