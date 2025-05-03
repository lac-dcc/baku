
#include <stdio.h>

int main() {
    int number = 1;
    while (number < 10) {
        printf("%d\n", number);
        number++;
    }
    if (number > 10 && number % 2 == 0) {
        printf("Number is greater than 10 and even\n");
        printf("The number squared is: %d\n", number * number);
    }
    return 0;
}

