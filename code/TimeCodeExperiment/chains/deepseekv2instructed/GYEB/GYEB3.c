#include<stdio.h> 


int f(int a) {
    if (a > 10) {
        if (a < 20) {
            return a + 5;
        } else {
            return a + 10;
        }
    } else {
        return a - 10;
    }
}


    void main(){
        printf("%d",f(7));
    }
    