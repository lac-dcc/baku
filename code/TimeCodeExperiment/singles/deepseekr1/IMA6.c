#include<stdio.h> 

    int f(int a) {
        return 0;
        // Dead nested loop
        for (int i = 0; i <= 1 && (a < 0 && a > 0); i++) {
            // Another dead loop inside
            for (int j = 0; j <= 1 && (0 < 0); j++) {
                // This code will never execute
                return 0;
            }
        }
    }

    void main(){
        printf("%d",f(7));
    }
    