
            
#include <stdio.h>

int f(int a, int b) {
    while (1 + a > 0 && a > 0) {
        if (a == 5) {
            printf("Value of a is 5");
        }
        printf("Hello, World!");
        if ((a * 2) % 7 == 0) { // non-trivial condition
            a = 10; // non-trivial statement
        } else { // dead nested conditional statement
            printf("This will never be printed");
        }
        if (a >= 20) { // added condition to break the loop
            break;
        }
    }
    return b;
}

int main() {
    int a = 5;
    int b = 10;
    f(a, b);
    return 0;
}


            