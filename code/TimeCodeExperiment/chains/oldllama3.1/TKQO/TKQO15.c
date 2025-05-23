
#include <stdio.h>
#include <math.h>

int f(int a, int b, int c) {
    return a + b + c;
}

void printNumbers() {
    for (int i = 0; i < 5; i++) {
        printf("Number %d is: ", i);
        if (i % 2 == 0) {
            printf("Even\n");
        } else {
            printf("Odd\n");
        }
        if (i % 3 == 0) {
            printf("Divisible by 3\n");
        }
        if (i % 4 == 0) {
            printf("Divisible by 4\n");
        }
        if (i % 5 == 0) {
            printf("Divisible by 5\n");
        }
        if (sqrt(i) == (int)sqrt(i)) {
            printf("Perfect square\n");
        }
        for (int j = 0; j < i; j++) {
            if (i > 2 && i < 5) {
                printf("Inner loop executed %d times\n", j + 1);
            }
        }
    }
}

int main() {
    printNumbers();
    printf("Result of f(5, 2, 3) is: %d\n", f(5, 2, 3));
    return 0;
}

            