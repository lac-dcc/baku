#include<stdio.h> 


int f(int a) {
    while (a < 10 && a > -10) {
        if (a > 0) {
            a += 2;
        } else {
            a -= 2;
        }
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                if (i == j) {
                    continue;
                }
            }
        }
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    