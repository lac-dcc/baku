#include<stdio.h> 


int f(int a) {
    if (a > 10) {
        if (a < 20) {
            for (int i = 0; i < 5; i++) {
                if (a % 2 == 0) {
                    return a + 10;
                } else {
                    return a - 5;
                }
            }
        } else {
            return a - 5;
        }
    } else {
        return a + 5;
    }
}


    void main(){
        printf("%d",f(7));
    }
    