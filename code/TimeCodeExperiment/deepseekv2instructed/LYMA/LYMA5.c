#include<stdio.h> 


int f(int a) {
    if (a > 10 && a < 20) {
        if (a % 2 == 0) {
            return a + 10;
        } else {
            return a + 5;
        }
    } else {
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    