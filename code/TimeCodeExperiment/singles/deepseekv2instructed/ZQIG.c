#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            if (i + j == a - 1) {
                // Add a nested loop with a complex condition and a statement inside
                for (int k = 0; k < a; k++) {
                    for (int l = 0; l < a; l++) {
                        if (k + l == a - 1) {
                            // Add a nested loop with a complex condition and a statement inside
                            // This is just an example, you can add any complex logic you want
                            // For example, you can add some arithmetic operations or conditional checks
                            int sum = (i * j) + (k * l);
                            if (sum % 2 == 0) {
                                // Add a statement to be executed inside the innermost loop
                                // For example, print the values of i, j, k, l, and sum
                                printf("i: %d, j: %d, k: %d, l: %d, sum: %d\n", i, j, k, l, sum);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    