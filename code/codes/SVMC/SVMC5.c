
            
    #include <stdio.h>

    int main() {
        int a = 5;
        int b = 10;
        printf("Value of a: %d\n", a);
        printf("Value of b: %d\n", b);
        f(a, b);
        return 0;
    }

    int f(int a, int b) {
        int i;
        for (i = 0; i < a; i++) {
            if (i % 2 == 0) {
                int j;
                for (j = 0; j < i; j++) {
                    printf("%d ", j);
                }
            } else {
                int k;
                for (k = 0; k < a - i; k++) {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
        return 0;
    }
    

            