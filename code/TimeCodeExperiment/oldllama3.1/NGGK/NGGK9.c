
            
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    if (a > b) {
        printf("a is greater than b\n");
    } else if (a == b) {
        printf("a is equal to b\n");
    } else {
        printf("a is less than b\n");
        if ((a + b) % 3 == 0 && (a * b) > 100) {
            printf("The product of a and b is greater than 100 and the sum of a and b is divisible by 3\n");
        }
    }

    return 0;
}

            