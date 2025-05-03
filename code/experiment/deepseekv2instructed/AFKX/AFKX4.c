#include<stdio.h> 


int f(int a) {
    if (a > 0) {
        if (a < 10) {
            return 1;
        } else {
            // Dead nested loop with a complex condition and a statement inside
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    if (i + j > 100) {
                        return 0;
                    }
                }
            }
            return 0;
        }
    } else {
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    