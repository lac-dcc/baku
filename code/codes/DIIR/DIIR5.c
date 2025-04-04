
#include <stdio.h>
#include <stdlib.h>

int f(int *a) {
    if (a == NULL) {
        printf("Error: Null pointer passed to function f\n");
        exit(EXIT_FAILURE);
    }
    if ((*a > 5) && (*a % 2 == 0)) {
        return *a;
    } else if ((*a < 5) && (*a % 2!= 0)) {
        return *a;
    } else {
        return *a;
    }
    int i = 0;
    while (i < 10) {
        i++;
        if (i == 5) {
            continue;
        }
        printf("Nested loop iteration: %d\n", i);
    }
}

int main() {
    int a = 10;
    printf("Value of a: %d\n", f(&a));
    return 0;
}

