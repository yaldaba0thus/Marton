#include "../include/TokenType.h"
#include "../include/Lexer.h"


void get_number(char* buffer, size_t* buffer_top, Token* token) {
    static char number[4096] = {0};
    size_t      index        = 0;
    bool        is_float     = false;

    while (buffer[*buffer_top] != ' ' && (isdigit(buffer[*buffer_top]) || buffer[*buffer_top]== '.') && buffer[*buffer_top]!= '\0') {
        if (buffer[*buffer_top] == '.') {
            is_float = true;
        }
        
        number[index] = buffer[*buffer_top];
        ++index;
        ++(*buffer_top);
    }
    number[index] = '\0';

    char* literal = malloc(sizeof(char) * (index + 1));
    if (literal == NULL) {
        fprintf(stderr, "Cannot allocate memory to store number literal.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(literal, number, index + 1);
    token->literal = literal;
    token->type = is_float ? DOUBLE_LITERAL : INTEGER_LITERAL;
}

void get_identifier_or_keyword(char* buffer, size_t* buffer_top, Token* token) {
    static char word[4096] = {0};
    size_t      index      = 0;
    
    while (buffer[*buffer_top] != ' ' && (isalnum(buffer[*buffer_top]) || buffer[*buffer_top]== '_') && buffer[*buffer_top]!= '\0') {
        word[index] = buffer[*buffer_top];
        ++index;
        ++(*buffer_top);
    }
    word[index] = '\0';

    for (size_t i = 2; i < 15; ++i) {
        int is_keyword = strcmp(word, map_token_string[i].literal);
        if (is_keyword == 0) {
            *token = map_token_string[i];
            return;
        }
    }

    char* literal = malloc(sizeof(char) * (index + 1));
    if (literal == NULL) {
        fprintf(stderr, "Cannot allocate memory to store identifier.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(literal, word, index + 1);
    token->literal = literal;
    token->type = IDENTIFIER;
}

void get_string_literal(char* buffer, size_t* buffer_top, Token* token) {
    static char literal[4096] = {0};
    size_t      index         = 0;
    
    while (isprint(buffer[*buffer_top]) && buffer[*buffer_top]!= '\0' && buffer[*buffer_top] != '"') {
        literal[index] = buffer[*buffer_top];
        ++index;
        ++(*buffer_top);
    }
    literal[index] = '\0';

    char* token_literal = malloc(sizeof(char) * (index + 1));
    if (token_literal == NULL) {
        fprintf(stderr, "Cannot allocate memory to store string literal.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(token_literal, literal, index + 1);
    token->literal = token_literal;
    token->type = STRING_LITERAL;
}

size_t lex(char* buffer, size_t file_size, Token* tokens) {
    size_t buffer_top = 0;
    size_t tokens_top = 0;

    while (buffer_top < file_size) {
        switch (buffer[buffer_top]) {
            case ',':
                tokens[tokens_top] = map_token_string[COMMA];
                ++tokens_top;
                ++buffer_top;
                break;
            case ';':
                tokens[tokens_top] = map_token_string[SEMICOLON];
                ++tokens_top;
                ++buffer_top;
                break;
            case ':':
                tokens[tokens_top] = map_token_string[COLON];
                ++tokens_top;
                ++buffer_top;
                break;
            case '(':
                tokens[tokens_top] = map_token_string[LEFT_PARENTHESES];
                ++tokens_top;
                ++buffer_top;
                break;
            case ')':
                tokens[tokens_top] = map_token_string[RIGHT_PARENTHESES];
                ++tokens_top;
                ++buffer_top;
                break;
            case '[':
                tokens[tokens_top] = map_token_string[LEFT_BRACE];
                ++tokens_top;
                ++buffer_top;
                break;
            case ']':
                tokens[tokens_top] = map_token_string[RIGHT_BRACE];
                ++tokens_top;
                ++buffer_top;
                break;
            case '<':
                ++buffer_top;
                if (buffer[buffer_top] == '-') {
                    tokens[tokens_top] = map_token_string[ASSIGN];
                    ++tokens_top;
                    ++buffer_top;
                } else if (buffer[buffer_top] == ' ') {
                    
                    break;
                }
                break;
            case '+':
                tokens[tokens_top] = map_token_string[PLUS];
                ++tokens_top;
                ++buffer_top;
                break;
            case '-':
                tokens[tokens_top] = map_token_string[MINUS];
                ++tokens_top;
                ++buffer_top;
                break;
            case '*':
                tokens[tokens_top] = map_token_string[MULTIPLICATION];
                ++tokens_top;
                ++buffer_top;
                break;
            case '/':
                tokens[tokens_top] = map_token_string[DIVISION];
                ++tokens_top;
                ++buffer_top;
                break;
            case '"':
                tokens[tokens_top] = map_token_string[DOUBLE_QUOTES];
                ++tokens_top;
                ++buffer_top;
                if (isprint(buffer[buffer_top])) {
                    get_string_literal(buffer, &buffer_top, &tokens[tokens_top]);
                    ++tokens_top;
                }
                if (buffer[buffer_top] != '"') {
                    fprintf(stderr, "Expected: \"");
                    exit(EXIT_FAILURE);
                }
                tokens[tokens_top] = map_token_string[DOUBLE_QUOTES];
                ++tokens_top;
                ++buffer_top;
                break;
            case ' ': case '\n': case '\t':
                ++buffer_top;
                break;
            default:
                if (isalpha(buffer[buffer_top])) {
                    get_identifier_or_keyword(buffer, &buffer_top, &tokens[tokens_top]);
                    ++tokens_top;
                } else if (isdigit(buffer[buffer_top])) {
                    get_number(buffer, &buffer_top, &tokens[tokens_top]);
                    ++tokens_top;
                }
        }
    }

    return tokens_top;
}
