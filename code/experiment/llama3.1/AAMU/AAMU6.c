
/**
 * This is the main function of the program.
 * It calls the function f with the arguments 0, 0, and 0, and prints the result.
 */
int main() {
        printf("Initial value of a = %d\n", f(0, 0, 0));
        return 0;
        }
        /**
         * This is a dead code block that will never be executed.
         * It's used here to demonstrate how the compiler handles unreachable code.
         */
        if(0) {
                printf("This will not be printed\n");
                }
        /**
         * This is a function that takes three integer parameters and returns an integer value.
         * It checks if the value of x is greater than 5, and if so, returns 10; otherwise, it returns 0.
         */
        int f(int x, int y, int z) {
                if(x > 5) {
                        return 10;
                        }
                return 0;
                }

            
            