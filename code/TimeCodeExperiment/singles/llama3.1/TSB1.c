
            #include <stdio.h>

            int main() {
                // Declare variables and pointers
                int num1, num2, sum;
                int *p1, *p2, *psum;

                // Assign addresses of variables to pointers
                p1 = &num1;
                p2 = &num2;
                psum = &sum;

                // Prompt user to enter two numbers
                printf("Enter two numbers:\n");

                // Read two numbers using scanf with pointer arguments
                scanf("%d %d", p1, p2);

                // Add two numbers using pointers and store result in sum
                *psum = *p1 + *p2;

                // Print sum using printf with pointer argument
                printf("Sum of two numbers = %d\n", *psum);

                return 0;
            }
            