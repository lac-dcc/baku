Do me a code in c for compilers, with 1024 of tokens max, that contains 75% latency. Without coments, please.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TOKENS 1024
#define MAX_LATENCY 75

typedef struct {
    char *name;
    int latency;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, int latency) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: maximum number of tokens reached\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].latency = latency;
    num_tokens++;
}

void generate_code() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < num_tokens; i++) {
        for (j = 0; j < tokens[i].latency; j++) {
            printf("%s", tokens[i].name);
        }
    }
}

int main() {
    add_token("a", 1);
    add_token("b", 2);
    add_token("c", 3);
    generate_code();
    return 0;
}
```