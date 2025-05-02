
#include <stdio.h>

int main() {
    int number = 1;
    while (number < 10) {
        printf("%d\n", number);
        number++;
    }
    if (number > 10) {
        printf("Number is greater than 10\n");
    }
    return 0;
}
