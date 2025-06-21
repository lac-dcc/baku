
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int main() {
    int i, j;
    int a[N], b[N];

    // Initialize arrays
    for (i = 0; i < N; i++) {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }

    // Perform operations
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i] += b[j];
        }
    }

    // Print results
    printf("Array sum: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
