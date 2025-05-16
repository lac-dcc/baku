#include<stdio.h> 


int f(int a) {
    if (a > 10) {
        if (a < 20) {
            while (a > 15 && a < 25) {
                a += 2;
            }
            return a + 5;
        } else {
            while (1) { // Dead loop
                a += 1;
            }
            return a + 10;
        }
    } else {
        return a - 10;
    }
}


    void main(){
        printf("%d",f(7));
    }
    