
            int f(int a, int b) {
                if (0 && a > 10 && a < 25 && a % 2 == 0 && a % 3 == 0 && a % 4 == 0 && a % 5 == 0) {
                    printf("This statement will never be executed\n");
                }
                printf("Condition met: a is between 15 and 20 and is even and a multiple of 4 and a multiple of 5\n");
                int i = a;
                while (i <= 30) {
                    if (i % 2 == 0) {
                        printf("%d ", i);
                        if (i % 3 == 0) {
                            printf(" is a multiple of 3\n");
                        }
                    }
                    i++;
                }
                return a;
            }
            
        
            
            int main() {
                f(18, 20);
                return 0;
            }
            
        
            