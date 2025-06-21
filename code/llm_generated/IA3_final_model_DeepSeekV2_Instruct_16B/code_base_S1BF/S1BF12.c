#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

void optimize_me(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    printf("Sum: %d\n", sum);
}

int main() {
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    optimize_me(array, ARRAY_SIZE);
    return 0;
}
