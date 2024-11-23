#ifndef TOKEN_HEADER
#define TOKEN_HEADER


#include <stdlib.h>
#include <stdio.h>


typedef enum {
    ILLEGAL,
    _EOF,

    FUNCTION,
    LET,
    IF,
    ELIF,
    ELSE,
    FOR,
    WHILE,

    INTEGER,
    STRING,
    DOUBLE,
    BOOLEAN,

    FALSE,
    TRUE,

    COMMA,
    SEMICOLON,
    COLON,
    LEFT_PARENTHESES,
    RIGHT_PARENTHESES,
    LEFT_BRACE,
    RIGHT_BRACE,

    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLICATION,
    DIVISION,

    DOUBLE_QUOTES,

    IDENTIFIER,
    INTEGER_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
} TokenType;

typedef struct {
    TokenType type;
    char*     literal;
} Token;


extern const Token map_token_string[32];


extern void Token_display(Token* token);


#endif
