
#include <stdio.h>

int f(int a, int b) {
    while (1 + a > 0 && a > 0) {
        if (a == 5) {
            printf("Value of a is 5");
        }
        printf("Hello, World!");
        if ((a * 2) % 7 == 0) { // non-trivial condition
            a = 10; // non-trivial statement
        }
        if (a >= 20) { // added condition to break the loop
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("Even number: %d\n", i);
        } else {
            printf("Odd number: %d\n", i);
        }
    }
    return b;
}

int main() {
    int a = 10;
    int b = 20;
    f(a, b);
    return 0;
}
