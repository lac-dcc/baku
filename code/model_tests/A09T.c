
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
    int array[ARRAY_SIZE];
    int sum = 0;

    initialize_array(array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}
