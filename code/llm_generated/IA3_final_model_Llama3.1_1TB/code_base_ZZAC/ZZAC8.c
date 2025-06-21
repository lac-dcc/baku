
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform a simple calculation
int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int a = 10;
    int b = 20;

    // Perform the calculation 100 times
    for (int i = 0; i < 100; i++) {
        add(a, b);
    }

    printf("The final answer is %d\n", a + b);

    return 0;
}
