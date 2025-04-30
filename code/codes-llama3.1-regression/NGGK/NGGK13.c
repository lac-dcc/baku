
#include <stdio.h>

int add(int a, int b) {
    printf("The sum of a and b is %d\n", a + b);
    return a + b;
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    if (a > b && a > c) {
        printf("a is greater than b and c\n");
    } else if (a == b && a == c) {
        printf("a is equal to b and c\n");
    } else if (a == b && a > c) {
        printf("a is equal to b and greater than c\n");
    } else if (a == b && a < c) {
        printf("a is equal to b and less than c\n");
    } else if (a > b && a < c) {
        printf("a is greater than b and less than c\n");
    } else if (a < b && a > c) {
        printf("a is less than b and greater than c\n");
    } else {
        printf("a is less than b and less than c\n");
        printf("This statement will always be executed\n");
        if ((a + b) % 3 == 0 && (a * b) > 100 && (a + c) % 2 == 0) {
            printf("The product of a and b is greater than 100, the sum of a and b is divisible by 3, and the sum of a and c is even\n");
            add(a, b);
        }
    }

    return 0;
}

