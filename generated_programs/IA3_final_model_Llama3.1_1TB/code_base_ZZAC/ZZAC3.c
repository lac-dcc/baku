
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1024*1024
#define NUM_ITERATIONS 1000

void main() {
    int *arr = (int *)malloc(SIZE);
    int i, j;

    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (int k = 0; k < SIZE; k++) {
            if (k % 2 == 0) {
                arr[k] = k * 2;
            } else {
                arr[k] = k * 3;
            }
        }
        for (int k = 0; k < SIZE; k++) {
            if (arr[k] % 2 == 0) {
                arr[k] = arr[k] * 2;
            } else {
                arr[k] = arr[k] * 3;
            }
        }
    }

    free(arr);
}

