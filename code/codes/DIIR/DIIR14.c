
            
        
        /* Add your code here */
        #include <stdio.h>
        #include <stdlib.h>

        int f(int *a) {
            if (a == NULL) {
                return -1;
            }
            if ((*a > 5) && (*a % 2 == 0)) {
                printf("The value %d is greater than 5 and is an even number\n", *a);
                return *a;
            } else if ((*a < 5) && (*a % 2!= 0)) {
                return *a;
            } else if (*a == 7) {
                return *a;
            } else {
                return *a;
            }
            /* Dead conditional statement */
            if (0 && (*a > 10 || *a < 0)) {
                printf("The value %d is greater than 10 or less than 0\n", *a);
            }
        }

        int main() {
            int a = 10;
            int result = f(&a);
            if (result == -1) {
                fprintf(stderr, "Error: Invalid input\n");
                return 1;
            }
            printf("Value of a: %d\n", result);
            return 0;
        }

        
            