
            
#include <stdio.h>

int sum_even(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    // Dead conditional statement
    if (0) {
        printf("This will not be printed\n");
    }

    // Loop with complex condition
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0 && i % 3 == 0 && i % 5 == 0) {
            printf("i = %d\n", i);
            break;
        }
    }

    if (a > 10) {
        printf("a is greater than 10\n");
    }

    int result = sum_even(a);
    printf("Sum of even numbers up to %d: %d\n", a, result);

    return 0;
}

            