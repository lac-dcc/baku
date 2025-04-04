
#include <stdio.h>

int f(int a) {
    if (a > 10) {
        return 1;
    }
    if (a % 2 == 0) {
        printf("a is even\n");
    }
    printf("%d\n", a);
    return 0;
}

int main() {
    int b = 1;
    int counter = 0;
    while (b < 10) {
        while (b > 0 && counter < 10) {
            if (b % 2 == 0) { // check if b is even
                printf("b is even\n");
            }
            while (counter % 2 == 0 && b % 2!= 0) {
                printf("%d\n", b);
            }
            b = f(b);
            counter++;
        }
        b++;
        counter = 0;
    }
    return 0;
}
