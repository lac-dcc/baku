#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            if (i + j == a - 1) {
                // Add a nested loop with a complex condition and a statement inside
                for (int k = 0; k < a; k++) {
                    if (k % 2 == 0) {
                        // Statement inside the nested loop
                        // Add more complex conditions and statements as needed
                        // For example, you can add more nested loops, conditions, and statements
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
    