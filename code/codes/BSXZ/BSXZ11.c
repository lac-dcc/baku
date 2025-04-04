
            
#include <stdio.h>

// Function to calculate the sum of three numbers
int add(int num1, int num2, int num3) {
    // Return the sum of num1, num2, and num3
    return num1 + num2 + num3;
}

int main() {
    int i = 0;
    int j = 0;
    while (i < 5) {
        i++;
        while (j < 5 && i + j < 10) {
            j++;
            // Calculate the sum of i, j, and 5 using the add function
            int sum = add(i, j, 5);
            printf("%d + %d + 5 = %d\n", i, j, sum);
            if (j > 3) {
                printf("j is greater than 3\n");
            }
            // Dead nested conditional statement with a non-trivial condition and a statement inside
            if (j > 5 && i > 3) {
                printf("j is greater than 5 and i is greater than 3\n");
            }
            // Additional conditional statement
            if (sum > 10) {
                printf("The sum of %d, %d, and 5 is greater than 10\n", i, j);
            }
        }
    }
    return 0;
}

            
            