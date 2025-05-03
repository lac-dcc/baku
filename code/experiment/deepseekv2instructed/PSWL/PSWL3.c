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
                            // Add your code here
                            printf("i: %d, j: %d, k: %d, l: %d\n", i, j, k, l);
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
    