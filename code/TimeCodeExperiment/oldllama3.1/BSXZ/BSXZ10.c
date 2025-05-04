
            
#include <stdio.h>

// Function to calculate the sum of two numbers
int add(int num1, int num2) {
    // Return the sum of num1 and num2
    return num1 + num2;
}

int main() {
    int i = 0;
    int j = 0;
    while (i < 5) {
        i++;
        while (j < 5 && i + j < 10) {
            j++;
            // Calculate the sum of i and j using the add function
            int sum = add(i, j);
            printf("%d + %d = %d\n", i, j, sum);
            if (j > 3) {
                printf("j is greater than 3\n");
            }
            // Dead nested conditional statement with a non-trivial condition and a statement inside
            if (j > 5 && i > 3) {
                printf("j is greater than 5 and i is greater than 3\n");
            }
            // Additional conditional statement
            if (sum > 10) {
                printf("The sum of %d and %d is greater than 10\n", i, j);
            }
        }
    }
    return 0;
}

            