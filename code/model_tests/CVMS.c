
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void initialize_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void sum_array(int *array, int size, int *result) {
    for (int i = 0; i < size; i++) {
        *result += array[i];
    }
}

int main() {
    int array[ARRAY_SIZE];
    int result = 0;

    srand(time(NULL));
    initialize_array(array, ARRAY_SIZE);

    // Measure the time taken by the sum_array function
    clock_t start_time = clock();
    sum_array(array, ARRAY_SIZE, &result);
    clock_t end_time = clock();

    printf("Sum: %d\n", result);
    printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}
