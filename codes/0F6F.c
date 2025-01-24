Do me a code in c for compilers, with 512 of tokens max, that contains 9% error rate. Without coments, please.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 512
#define MAX_TOKEN_LENGTH 256

typedef enum {
    TOKEN_ID,
    TOKEN_NUM,
    TOKEN_OP,
    TOKEN_PUNCT,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

int is_valid_identifier(char *str) {
    if (!isalpha(str[0])) {
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_valid_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_valid_operator(char *str) {
    return (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0);
}

int is_valid_punctuation(char *str) {
    return (strcmp(str, ";") == 0 || strcmp(str, "(") == 0 || strcmp(str, ")") == 0);
}

Token get_token(char *input, int *index) {
    Token token;
    token.type = TOKEN_EOF;

    while (isspace(input[*index])) {
        (*index)++;
    }

    if (input[*index] == '\0') {
        token.type =