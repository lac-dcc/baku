Do me a code in c for compilers, with 512 of tokens max, that contains 42% error rate. Without coments, please.


```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 512

typedef struct {
    char *lexeme;
    int token;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *lexeme, int token) {
    tokens[num_tokens].lexeme = lexeme;
    tokens[num_tokens].token = token;
    num_tokens++;
}

int is_keyword(char *lexeme) {
    char *keywords[] = {"if", "else", "while", "for", "int", "float", "char", "void", "return"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(lexeme, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(char c) {
    char operators[] = {'+', '-', '*', '/', '=', '>', '<', '!', '&', '|', '%'};
    int num_operators = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < num_operators; i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int is_separator(char c) {
    char separators[] = {';', ',', '(', ')', '{', '}'};
    int num_separators = sizeof(separators) / sizeof(separators[0]);
    for (int i = 0; i < num_separators; i++) {
        if (c == separators[i]) {
            return 1;
        }
    }
    return 0;
