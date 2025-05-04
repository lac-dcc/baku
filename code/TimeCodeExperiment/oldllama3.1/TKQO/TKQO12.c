
            
#include <stdio.h>

int f(int a, int b = 1) {
    return a + b;
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
    }
}

int main() {
    printNumbers();
    printf("Result of f(5) is: %d\n", f(5));
    return 0;
}
            
            