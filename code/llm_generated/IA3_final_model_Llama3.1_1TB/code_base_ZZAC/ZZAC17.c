

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the maximum of two numbers
int max(int a, int b) {
    return (a > b)? a : b;
}

// Function to calculate the minimum of two numbers
int min(int a, int b) {
    return (a < b)? a : b;
}

int main() {
    int a = 10000000;
    int b = 20000000;

    // Start the timer
    clock_t start_time = clock();

    // Perform the following operations:
    // 1. Loop through an array of 10000000 elements
    // 2. Use the max and min functions to find the maximum and minimum values
    // 3. Perform a branch instruction
    for (int i = 0; i < a; i++) {
        int c = max(i, b);
        int d = min(i, b);
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        } else {
            printf("Odd: %d\n", i);
        }
    }

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the execution time
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

