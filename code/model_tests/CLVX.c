
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

    // Perform addition of two arrays
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = array1[i] + array2[i];
    }

    // Print the result array
    // print_array(result, ARRAY_SIZE);

    return 0;
}
