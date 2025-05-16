#include<stdio.h> 


int f(int a, int b) {
    if (a > 10) {
        if (a < 20) {
            return a + b;
        } else {
            int i;
            for (i = 0; i < 1000000; i++) {
                if (a % 2 == 0) {
                    continue;
                }
                if (a > 15) {
                    return a - b;
                }
            }
            return a - b;
        }
    } else {
        if (a > 5) {
            return a + b;
        } else {
            int j;
            for (j = 0; j < 1000000; j++) {
                if (a % 3 == 0) {
                    break;
                }
                if (a < 3) {
                    return a - b;
                }
            }
            return a - b;
        }
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    