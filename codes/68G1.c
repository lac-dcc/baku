Do me a code in c for compilers, with 512 of tokens max, that contains 57% bandwidth utilization. Without coments, please.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 512
#define MAX_TOKEN_LENGTH 256

typedef enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_LITERAL,
    TOKEN_TYPE_SEPARATOR,
    TOKEN_TYPE_COMMENT
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

int is_keyword(char *token) {
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(char *token) {
    char *operators[] = {
        "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=",
        "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=",
        "/=", "%=", "&=", "|=", "^=", "<<=", ">>="
    };
    int num