
        #include <stdio.h>

        int add_pointers(int *p1, int *p2) {
            return *p1 + *p2;
        }

        int main() {
            int a = 5;
            int b = 10;
            int result = add_pointers(&a, &b);
            printf("Result: %d\n", result);
            return 0;
        }
        