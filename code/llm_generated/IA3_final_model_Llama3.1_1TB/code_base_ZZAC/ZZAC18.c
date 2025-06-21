
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define N 10000000
#define M 1000000

void matmul(int *A, int *B, int *C, int N, int M) {
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            C[i * M + j] = 0;
            for (k = 0; k < M; k++) {
                C[i * M + j] += A[i * M + k] * B[k * M + j];
            }
        }
    }
}

int main() {
    int *A, *B, *C;
    int i, j;

    A = (int *)malloc(N * M * sizeof(int));
    B = (int *)malloc(N * M * sizeof(int));
    C = (int *)malloc(N * M * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i * M + j] = rand() % 100;
            B[i * M + j] = rand() % 100;
        }
    }

    matmul(A, B, C, N, M);

    free(A);
    free(B);
    free(C);

    return 0;
}
