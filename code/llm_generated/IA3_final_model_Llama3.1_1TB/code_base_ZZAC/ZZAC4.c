#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 10000000

int main() {
    int i, j, k, a[N], b[N], c[N];
    struct timeval start, end;

    // Initialize arrays
    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
    }

    // Start timer
    gettimeofday(&start, NULL);

    // Perform computation
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                a[i] = a[i] + b[j] + c[k];
            }
        }
    }

    // Stop timer
    gettimeofday(&end, NULL);

    // Print time taken
    printf("Time taken: %.6f seconds\n", (end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000);

    return 0;
}

