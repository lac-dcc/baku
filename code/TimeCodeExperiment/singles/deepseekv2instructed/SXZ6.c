#include<stdio.h> 

int f(int a) {
    while (a > 0 && a < 100) {
        if (a % 2 == 0) {
            a += 3;
        } else {
            a -= 2;
        }
        if (a > 50) {
            a *= 2;
        } else {
            a /= 2;
        }
    }
    return a;
}

    void main(){
        printf("%d",f(7));
    }
    