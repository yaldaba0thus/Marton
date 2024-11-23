#ifndef LEXER_HEADER
#define LEXER_HEADER


#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TokenType.h"


extern void   get_number(char*, size_t*, Token*);
extern void   get_identifier_or_keyword(char*, size_t*, Token*);
extern void   get_string_literal(char*, size_t*, Token*);
extern size_t lex(char*, size_t, Token*);


#endif
