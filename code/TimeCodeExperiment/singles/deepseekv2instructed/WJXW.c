#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            if (i + j == 5) {
                // Add a nested loop with a complex condition and a statement inside
                for (int k = 0; k < 3; k++) {
                    if (k == 2) {
                        return i * j; // Return the product of i and j if k is 2
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
    