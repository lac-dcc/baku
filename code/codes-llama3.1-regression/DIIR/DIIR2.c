
#include <stdio.h>
#include <stdlib.h>

int f(int *a) {
    if (a == NULL) {
        printf("Error: Null pointer passed to function f\n");
        exit(EXIT_FAILURE);
    }
    if (*a > 5) {
        return *a;
    } else {
        return *a;
    }
}

int main() {
    int a = 10;
    printf("Value of a: %d\n", f(&a));
    return 0;
}
