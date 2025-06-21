
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

void optimized_function(int arr[]) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
}

int main() {
    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    optimized_function(arr);
    return 0;
}
