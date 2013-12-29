#ifndef LEXER_H
#define LEXER_H

#include "error.h"
#include "source.h"
#include <stddef.h>

typedef struct lexer_t lexer_t;

typedef enum
{
  TK_NONE,

  // primitives
  TK_STRING,
  TK_INT,
  TK_FLOAT,
  TK_ID,

  // symbols
  TK_LBRACE,
  TK_RBRACE,
  TK_LPAREN,
  TK_RPAREN,
  TK_LBRACKET,
  TK_RBRACKET,
  TK_COMMA,
  TK_ARROW,
  TK_DBLARROW,

  TK_DOT,
  TK_COLON,
  TK_SEMI,
  TK_EQUALS,

  TK_PLUS,
  TK_MINUS,
  TK_MULTIPLY,
  TK_DIVIDE,
  TK_MOD,

  TK_LSHIFT,
  TK_RSHIFT,

  TK_LT,
  TK_LE,
  TK_GE,
  TK_GT,

  TK_EQ,
  TK_NEQ,

  TK_PIPE,
  TK_QUESTION,

  // keywords
  TK_USE,
  TK_AS,
  TK_ALIAS,
  TK_TRAIT,
  TK_CLASS,
  TK_ACTOR,
  TK_IS,
  TK_ISO,
  TK_TRN,
  TK_VAR,
  TK_VAL,
  TK_BOX,
  TK_TAG,
  TK_FUN,
  TK_BE,
  TK_NEW,
  TK_RETURN,
  TK_BREAK,
  TK_CONTINUE,
  TK_IF,
  TK_THEN,
  TK_ELSE,
  TK_END,
  TK_FOR,
  TK_IN,
  TK_WHILE,
  TK_DO,
  TK_MATCH,
  TK_TRY,
  TK_UNDEF,
  TK_THIS,
  TK_NOT,
  TK_AND,
  TK_OR,
  TK_XOR,
  TK_INFER,

  // abstract
  TK_PROGRAM,
  TK_PACKAGE,
  TK_MODULE,
  TK_FIELD,
  TK_LOCAL,
  TK_LIST,
  TK_ADT,
  TK_OBJTYPE,
  TK_FUNTYPE,
  TK_MODE,
  TK_EPHEMERAL,
  TK_TYPEPARAM,
  TK_PARAM,
  TK_TYPEARGS,
  TK_CALL,
  TK_SEQ,
  TK_CASE,
  TK_LAMBDA,
  TK_CANTHROW,
  TK_REF,

  TK_EOF
} token_id;

typedef struct token_t
{
  token_id id;
  size_t line;
  size_t pos;

  union
  {
    const char* string;
    double real;
    __uint128_t integer;
  };
} token_t;

lexer_t* lexer_open( source_t* source );
void lexer_close( lexer_t* lexer );
token_t* lexer_next( lexer_t* lexer );

token_t* token_new( token_id id, size_t line, size_t pos );
const char* token_string( token_t* token );
void token_setstring( token_t* token, const char* s );
void token_free( token_t* token );

#endif
