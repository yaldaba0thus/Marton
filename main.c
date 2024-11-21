#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    NAH = 0,
    
    LET,
    IF,
    ELSE,
    ELIF,
    FOR,
    WHILE,
    SEMICOLON,
    COLON,

    INT,
    STRING,
    DOUBLE,
    BOOLEAN,

    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLICATION,
    DIVISION,

    INT_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
    BOOLEAN_LITERAL,
} TokensType;

const char* keywords[] = {
    "let",
    "if",
    "else",
    "elif",
    "for",
    "while",
    "int",
    "string",
    "double",
    "boolean",
};

TokensType keyword_token_type[] = {
    LET,
    IF,
    ELSE,
    ELIF,
    FOR,
    WHILE,
    INT,
    STRING,
    DOUBLE,
    BOOLEAN,
};

// TODO HASH SEARCH FOR KEYWORD!!!
bool is_keyword(FILE* file, int ch, TokensType* type) {
    char word[4096];
    size_t index = 0;
    
    while (ch != ' ' && isalpha(ch) && ch != EOF) {
        word[index] = ch;
        ++index;
        ch = fgetc(file);
    }
    word[index] = '\0';
    puts(word);

    for (size_t i = 0; i < 9; ++i) {
        bool is_keyword = strcmp(word, keywords[i]);
        if (is_keyword) {
            *type = keyword_token_type[index];
            return true;
        }
    }

    return false;
}


int main(int argc, char* argv[]) {
    FILE* marton = fopen(argv[1], "r");
    if (marton == NULL) {
        return 1;
    }

    int ch;
    TokensType tokens_type[200] = {0};
    size_t tokens_type_top = 0;
    while ((ch = fgetc(marton)) != EOF) {
        switch (ch) {
            case '+':
                tokens_type[tokens_type_top] = PLUS;
                ++tokens_type_top;
                break;
            case '<':
                ch = fgetc(marton);
                if (ch == '-') {
                    tokens_type[tokens_type_top] = ASSIGN;
                } else if (ch == ' ') {

                }
                break;
            default:
                if (isalpha(ch)) {
                    TokensType type = NAH;
                    if (is_keyword(marton, ch, &type)) {
                        tokens_type[tokens_type_top] = type;
                        ++tokens_type_top;
                    }
                } else if (isdigit(ch)) {

                }
        }
    }

    for (size_t i = 0; i < tokens_type_top; ++i) {
        printf("%d\n", tokens_type[i]);
    }

    fclose(marton);
    return 0;
}
