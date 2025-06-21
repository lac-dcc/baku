
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform some operations
void some_operations() {
    int i, j;
    int arr[1000000];
    int sum = 0;

    // Fill the array with values
    for (i = 0; i < 1000000; i++) {
        arr[i] = i;
    }

    // Perform some calculations
    for (i = 0; i < 1000000; i++) {
        for (j = 0; j < 1000000; j++) {
            sum += arr[i] + arr[j];
        }
    }

    // Print the result
    printf("%d\n", sum);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Perform some operations
    some_operations();

    // Return 0 to indicate successful execution
    return 0;
}
