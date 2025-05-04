
            
            #include <stdio.h>

            void f(int a) {
                if (a > 0 && a % 2 == 0) {
                    printf("a is even: %d\n", a);
                    return a * 2;
                }
                else if (a > 0 && a % 2!= 0) {
                    printf("a is odd: %d\n", a);
                    return a + 1;
                }
                if (a == 5 && a > 0) {
                    printf("a is 5: %d\n", a);
                    return 10;
                }
                printf("a is not valid: %d\n", a);
                return 0;
            }

            int main() {
                for (int i = 0; i < 10; i++) {
                    f(i);
                }
                return 0;
            }
            
            