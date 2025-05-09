
            
            int f(int a) {
                if (a > 15 && a < 20 && a % 2 == 0 && a % 4 == 0) {
                    printf("Condition met: a is between 15 and 20 and is even and a multiple of 4\n");
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
                }
                return a;
            }
            
        
            
            int main() {
                f(15);
                return 0;
            }
            
        
            
            