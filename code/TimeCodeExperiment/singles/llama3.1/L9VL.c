
             int f(int a) {
                // Use a switch statement to check the input value a
                switch (a) {
                    case 5:
                        // If a is 5, return the value of a incremented by 1
                        return a + 1;
                    case 10:
                        // If a is 10, return the value of a multiplied by 2
                        return a * 2;
                    default:
                        // If a is neither 5 nor 10, return the value of a incremented by 1
                        return a + 1;
                }
                }

            int g(int a) {
                // Use a conditional statement to check if the input value a is greater than 5
                if (a > 5) {
                    // If it is, return the value of a multiplied by 2
                    return a * 2;
                } else {
                    // If it is not, return the value of a incremented by 1
                    return a + 1;
                }
                }

            int h(int a) {
                // Use a recursive function to call itself with a smaller input value
                if (a > 1) {
                    // If a is greater than 1, return the value of a incremented by the result of h(a-1)
                    return a + h(a-1);
                } else {
                    // If a is not greater than 1, return 1
                    return 1;
                }
                }

            int main() {
                // Test the function f with different input values
                printf("f(5) = %d\n", f(5));
                printf("f(10) = %d\n", f(10));
                // Use a loop to test the function f with different input values
                for (int i = 1; i <= 10; i++) {
                    printf("f(%d) = %d\n", i, f(i));
                    // Use a conditional statement to check if the result is greater than 5
                    if (f(i) > 5) {
                        printf("Result is greater than 5\n");
                    } else {
                        printf("Result is not greater than 5\n");
                    }
                    // Call the function g with the input value i
                    printf("g(%d) = %d\n", i, g(i));
                    // Call the function h with the input value i
                    printf("h(%d) = %d\n", i, h(i));
                    // Create a pointer to the function f
                    int (*fp)(int) = f;
                    // Call the function f through the pointer fp
                    printf("fp(%d) = %d\n", i, fp(i));
                }
                return 0;
                }
            