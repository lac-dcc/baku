
            
            #include <stdio.h>

            /**
             * Function f: returns 10 if x is greater than 5, otherwise returns 0.
             */
            int f(int x, int y, int z) {
                if (x > 5) {
                    // Return 10 if x is greater than 5
                    return 10;
                } else {
                    // Return 0 if x is not greater than 5
                    return 0;
                }
            }

            int main() {
                int a = f(0, 0, 0);
                // Call function f with x = 0 and print the result
                printf("%d\n", a);
                
                int i;
                // Loop from 0 to 4 and print each number
                for (i = 0; i < 5; i++) {
                    if (i == 3) {
                        // Break the loop when i is 3
                        break;
                    }
                    printf("%d ", i);
                }
                printf("\n");
                
                // This code will never be executed because the condition is always false
                if (0) {
                    printf("This code will never be executed.\n");
                }
                
                // Call function f with x = 10 and print the result
                printf("%d\n", f(10, 0, 0));
                return 0;
            }
            
            