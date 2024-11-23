#include <assert.h>

#include "../include/TokenType.h"
#include "../include/Lexer.h"


const char* mock_martoon_tokens = \
    "fn\n"
    "let\n"
    "if\n"
    "else\n"
    "elif\n"
    "for\n"
    "while\n"
    "i32\n"
    "String\n"
    "f64\n"
    "bool\n"
    "false\n"
    "true\n"
    ",\n"
    ";\n"
    ":\n"
    "(\n"
    ")\n"
    "[\n"
    "]\n"
    "<-\n"
    "+\n"
    "-\n"
    "*\n"
    "/\n"
    "string_type\n"
    "4\n"
    "20.5\n"
    "\"Hello, World!\"\n";


int main(void) {
    size_t martoon_tokens_size = strlen(mock_martoon_tokens);
    Token  tokens[31] = {0};
    size_t token_amount = lex((char*) mock_martoon_tokens, martoon_tokens_size, tokens);

    TokenType types[] = {
        FUNCTION,
        LET,
        IF,
        ELSE,
        ELIF,
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

        IDENTIFIER,
        INTEGER_LITERAL,
        DOUBLE_LITERAL,
        DOUBLE_QUOTES,
        STRING_LITERAL,
        DOUBLE_QUOTES,
    };
    assert(token_amount == 31);
    for (size_t i = 0; i < token_amount; ++i) {
        assert(tokens[i].type == types[i]);
    }
    return 0;
}
