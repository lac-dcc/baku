
            
            int f(int a) {
                int i = 0;
                if (a == 0) {
                    return 0; // or any other value that makes sense for the problem
                }
                while ((i < a) && (a - i) > i) {
                    i = i + (a - i);
                }
                return i;
            }
            
            int main() {
                printf("The value of i is: %d\n", f(10));
                printf("The value of i is: %d\n", f(20));
                printf("The value of i is: %d\n", f(30));
                printf("The value of i is: %d\n", f(40));
                printf("The value of i is: %d\n", f(50));
                return 0;
            }
            
            