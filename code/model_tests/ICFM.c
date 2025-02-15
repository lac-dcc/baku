
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
    int sum = 0;

    srand(time(NULL));
    initialize_array(array, SIZE);

    // Unroll the loop for better cache performance
    for (int i = 0; i < SIZE; i += 4) {
        sum += array[i];
        sum += array[i + 1];
        sum += array[i + 2];
        sum += array[i + 3];
    }

    printf("Sum: %d\n", sum);

    return 0;
}
