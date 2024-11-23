
#include "../include/TokenType.h"


const Token map_token_string[] = {
    {ILLEGAL, NULL},
    {_EOF, NULL},
    {FUNCTION, "fn"},
    {LET, "let"},
    {IF, "if"},
    {ELIF, "elif"},
    {ELSE, "else"},
    {FOR, "for"},
    {WHILE, "while"},
    {INTEGER, "i32"},
    {STRING, "String"},
    {DOUBLE, "f64"},
    {BOOLEAN, "bool"},
    {FALSE, "false"},
    {TRUE, "true"}, 
    {COMMA, ","},
    {SEMICOLON, ";"},
    {COLON, ":"},
    {LEFT_PARENTHESES, "("},
    {RIGHT_PARENTHESES, ")"},
    {LEFT_BRACE, "["},
    {RIGHT_BRACE, "]"},
    {ASSIGN, "<-"},
    {PLUS, "+"},
    {MINUS, "-"},
    {MULTIPLICATION, "*"},
    {DIVISION, "/"},
    {DOUBLE_QUOTES, "\""},
    {IDENTIFIER, "identifier"},
    {INTEGER_LITERAL, "integer_literal"},
    {DOUBLE_LITERAL, "double_literal"},
    {STRING_LITERAL, "string_literal"},
};


void Token_display(Token* token) {
    if ((1 < token->type) && (token->type < 28)) {
        puts(map_token_string[token->type].literal);
    } else if (token->type > 27) {
        if (token->literal == NULL) {
            fprintf(stderr, "Error while trying to display token: exprected valid tokern, got nil.\n");
            exit(EXIT_FAILURE);
        }
        printf("%s(%s)\n", map_token_string[token->type].literal, token->literal);
    }
}
