
            int f(int a) {
                if (a > 10 && a < 20 && a % 2 == 0) {
                    printf("Condition met: a is between 10 and 20 and is even\n");
                    int i = a;
                    while (i <= 30) {
                        if (i % 2 == 0) {
                            printf("%d ", i);
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
            
        
            