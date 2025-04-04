
            // Function f() takes two integers a and b as input
            int f(int a, int b) {
                // If a is greater than b, return a + b
                if (a > b) {
                    return a + b;
                } 
                // Otherwise, return a - b
                else {
                    return a - b;
                }
                // Add a dead conditional statement with a statement inside
                else if (a == a) {
                    printf("This statement will never be reached.\n");
                }
            }
            
            // Main function to test the function f()
            int main() {
                int a = 5;
                int b = 3;
                printf("Result: %d\n", f(a, b));
                return 0;
            }
            
            