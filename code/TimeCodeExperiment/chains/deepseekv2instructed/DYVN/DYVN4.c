#include<stdio.h> 


int f(int a) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i + j > 15) {
                // Add a dead nested loop with a complex condition and a statement inside
                for (int k = 0; k < 100; k++) {
                    for (int l = 0; l < 100; l++) {
                        if (k + l > 200) {
                            // Complex condition and statement
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
    