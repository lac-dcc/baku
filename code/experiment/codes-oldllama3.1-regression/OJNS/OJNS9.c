
/**
 * @file    main.c
 * @brief   A simple program that demonstrates a loop with a complex condition and statement inside.
 * @author  [Your Name]
 * @date    [Today's Date]
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief   Prints a message to the console with a given value.
 * @param   value The value to be printed.
 */
void print_value(int value) {
    printf("Value: %d\n", value);
}

int main() {
    int i = 0; // Initialize the loop counter to 0
    while (i < 10 && i > 0) { // Outer loop runs from 0 to 9
        printf("%d ", i); // Print the current value of i
        i++; // Increment the loop counter
        while (i > 10 || i < 5) { // Inner loop runs from 5 to 10 or from 11 to 0
            printf("Dead loop is running: %d\n", i); // Print a message indicating that the inner loop is running
            if (i % 2 == 0) { // Check if the value of i is even
                printf("Even value: %d\n", i); // Print a message if the value of i is even
            }
            i = 10; // This line will cause the inner loop to exit immediately
        }
    }
    printf("\n"); // Print a newline character
    return 0; // Return 0 to indicate successful execution
}

