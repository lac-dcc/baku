
            
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent the integers and their sum
typedef struct {
    int num1;
    int num2;
    int sum;
} Integer;

// Function to add two integers and store the result in the struct
void add(Integer *integer) {
    // Add the two integers and store the result in the sum field
    integer->sum = integer->num1 + integer->num2;
}

// Function to print the result
void printResult(Integer *integer) {
    // Print the two integers and their sum
    printf("The sum of %d and %d is %d\n", integer->num1, integer->num2, integer->sum);
}

int main() {
    // Declare a variable of type Integer
    Integer integer;

    // Get user input for the two integers
    printf("Enter the first integer: ");
    scanf("%d", &integer.num1);
    printf("Enter the second integer: ");
    scanf("%d", &integer.num2);

    // Call the add function to perform the addition
    add(&integer);

    // Call the printResult function to display the result
    printResult(&integer);

    // Add a dead nested loop with a complex condition and a statement inside
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i > 5 && j < 5 && i % 2 == 0) {
                printf("Hello, World!\n");
            }
        }
    }

    return 0;
}
            