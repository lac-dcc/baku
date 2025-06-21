
#include <stdio.h>

int main() {
    int i, sum = 0;
    for (i = 0; i < 100000; i++) {
        sum += i;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
