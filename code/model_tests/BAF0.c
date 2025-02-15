
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

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
    int array[ARRAY_SIZE];
    int sum = 0;

    srand(time(NULL));
    initialize_array(array, ARRAY_SIZE);

    // Unroll the loop for better cache performance
    for (int i = 0; i < ARRAY_SIZE; i += 4) {
        sum += array[i];
        sum += array[i + 1];
        sum += array[i + 2];
        sum += array[i + 3];
    }

    printf("Sum: %d\n", sum);

    return 0;
}
