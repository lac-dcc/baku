
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

void optimized_function(int *array) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    printf("Sum: %d\n", sum);
}

int main() {
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize array with some values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    optimized_function(array);

    free(array);
    return 0;
}
