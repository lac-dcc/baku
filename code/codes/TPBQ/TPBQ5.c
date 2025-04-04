
            int f(int a, int b) {
                int i = 0;
                if (a == 0 || b == 0) {
                    return 0; // or any other value that makes sense for the problem
                }
                while ((i < a) && (a - i) > i) {
                    i = i + (a - i);
                    if (i % 2 == 0) {
                        printf("i is even: %d\n", i);
                    } else {
                        printf("i is odd: %d\n", i);
                    }
                }
                return i;
            }
            
            int main() {
                printf("The value of i is: %d\n", f(10, 20));
                printf("The value of i is: %d\n", f(20, 30));
                printf("The value of i is: %d\n", f(30, 40));
                printf("The value of i is: %d\n", f(40, 50));
                printf("The value of i is: %d\n", f(50, 60));
                return 0;
            }
            if (i > 100) {
                printf("i is greater than 100: %d\n", i);
            }
            