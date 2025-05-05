
#include <stdio.h>

int main() {
    int i;
    long long sum = 0;

    for (i = 0; i < 1000000; i++) {
        sum += i;
    }

    printf("Sum: %lld\n", sum);
    return 0;
}
