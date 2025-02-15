
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

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
    int array[SIZE];
    initialize_array(array, SIZE);

    // Unroll the loop by a factor of 4 for better cache performance
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < SIZE; i += 4) {
        sum += array[i] + array[i + 1] + array[i + 2] + array[i + 3];
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
