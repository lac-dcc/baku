
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1024
#define M 1024

int main() {
    uint32_t a[N][M];
    uint32_t b[N][M];
    uint32_t c[N][M];
    uint32_t d[N][M];

    // Initialize arrays
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = i * j;
            b[i][j] = i * j;
            c[i][j] = 0;
            d[i][j] = 0;
        }
    }

    // Perform operations
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            c[i][j] = a[i][j] + b[i][j];
            d[i][j] = a[i][j] * b[i][j];
        }
    }

    // Print result
    printf("Result:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%u ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
