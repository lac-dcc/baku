
            #include <stdio.h>

            int f(int x, int y, int z) {
                if (x > 5) {
                    return 10;
                } else {
                    return 0;
                }
            }

            int main() {
                int a = f(0, 0, 0);
                printf("%d\n", a);
                
                int i;
                for (i = 0; i < 5; i++) {
                    if (i == 3) {
                        break;
                    }
                    printf("%d ", i);
                }
                printf("\n");
                
                if (0) {
                    printf("This code will never be executed.\n");
                }
                
                printf("%d\n", f(10, 0, 0));
                return 0;
            }
            