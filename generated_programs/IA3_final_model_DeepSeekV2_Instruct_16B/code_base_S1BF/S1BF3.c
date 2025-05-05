
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void optimized_function() {
    int array[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = i + j;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = array[i][j] * 2;
        }
    }
}

int main() {
    optimized_function();
    return 0;
}
