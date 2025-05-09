#include<stdio.h> 


int f(int a) {
    if (a > 0) {
        if (a < 10) {
            return a + 1;
        }
        for (int i = 0; i < 1000000; i++) {
            for (int j = 0; j < 1000000; j++) {
                if (i + j == 1000000) {
                    return a + 2;
                }
            }
        }
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    