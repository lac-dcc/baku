
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10000000

int main() {
    int i;
    int a[MAX];
    int b[MAX];
    int c[MAX];

    // Initialize arrays
    for (i = 0; i < MAX; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
    }

    // Perform operations
    for (i = 0; i < MAX; i++) {
        // Simple arithmetic operations
        a[i] = a[i] + b[i];
        c[i] = a[i] * c[i];

        // Branching
        if (a[i] > b[i]) {
            c[i] = c[i] + 1;
        } else {
            c[i] = c[i] - 1;
        }
    }

    return 0;
}
