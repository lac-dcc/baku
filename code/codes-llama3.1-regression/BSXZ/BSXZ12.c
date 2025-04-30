
#include <stdio.h>

// Function to calculate the sum of four numbers
int add(int num1, int num2, int num3, int num4) {
    // Return the sum of num1, num2, num3, and num4
    return num1 + num2 + num3 + num4;
}

int main() {
    int i = 0;
    int j = 0;
    while (i < 5) {
        i++;
        while (j < 5 && i + j < 10) {
            j++;
            // Calculate the sum of i, j, 5, and 2 using the add function
            int sum = add(i, j, 5, 2);
            printf("%d + %d + 5 + 2 = %d\n", i, j, sum);
            if (j > 3) {
                printf("j is greater than 3\n");
            }
            // Dead nested conditional statement with a non-trivial condition and a statement inside
            if (j > 5 && i > 3) {
                printf("j is greater than 5 and i is greater than 3\n");
            }
            // Additional conditional statement
            if (sum > 10) {
                printf("The sum of %d, %d, 5, and 2 is greater than 10\n", i, j);
            }
        }
    }
    return 0;
}

