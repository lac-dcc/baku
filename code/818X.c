
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1024

void initialize_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array1[ARRAY_SIZE];
    int array2[ARRAY_SIZE];
    int result[ARRAY_SIZE];

    srand(time(NULL));
    initialize_array(array1, ARRAY_SIZE);
    initialize_array(array2, ARRAY_SIZE);

    // Unroll the loop for better cache utilization
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i += 8) {
        result[i] = array1[i] + array2[i];
        result[i + 1] = array1[i + 1] + array2[i + 1];
        result[i + 2] = array1[i + 2] + array2[i + 2];
        result[i + 3] = array1[i + 3] + array2[i + 3];
        result[i + 4] = array1[i + 4] + array2[i + 4];
        result[i + 5] = array1[i + 5] + array2[i + 5];
        result[i + 6] = array1[i + 6] + array2[i + 6];
        result[i + 7] = array1[i + 7] + array2[i + 7];
    }

    // Align arrays for better memory access patterns
    alignas(32) int aligned_array1[ARRAY_SIZE];
    alignas(32) int aligned_array2[ARRAY_SIZE];
    alignas(32) int aligned_result[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        aligned_array1[i] = array1[i];
        aligned_array2[i] = array2[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i += 8) {
        aligned_result[i] = aligned_array1[i] + aligned_array2[i];
        aligned_result[i + 1] = aligned_array1[i + 1] + aligned_array2[i + 1];
        aligned_result[i + 2] = aligned_array1[i + 2] + aligned_array2[i + 2];
        aligned_result[i + 3] = aligned_array1[i + 3] + aligned_array2[i + 3];
        aligned_result[i + 4] = aligned_array1[i + 4] + aligned_array2[i + 4];
        aligned_result[i + 5] = aligned_array1[i + 5] + aligned_array2[i + 5];
        aligned_result[i + 6] = aligned_array1[i + 6] + aligned_array2[i + 6];
        aligned_result[i + 7] = aligned_array1[i + 7] + aligned_array2[i + 7];
    }

    return 0;
}
