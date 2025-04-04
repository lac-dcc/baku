
            
    #include <stdio.h>

    void f(int a, int b) {
        int i;
        for (i = 0; i < a; i++) {
            if (i % 2 == 0) {
                int j;
                for (j = 0; j < i; j++) {
                    printf("%d ", j);
                }
                int count = 0;
                for (j = 0; j < i; j++) {
                    if (j % 3 == 0) {
                        count++;
                    }
                }
                if (count > 2) {
                    int k;
                    for (k = 0; k < i; k++) {
                        printf("%d ", k);
                    }
                }
            } else {
                int k;
                for (k = 0; k < a - i; k++) {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
    }

    int main() {
        int a = 5;
        int b = 10;
        printf("Value of a: %d\n", a);
        printf("Value of b: %d\n", b);
        f(a, b);
        return 0;
    }
    

            
            