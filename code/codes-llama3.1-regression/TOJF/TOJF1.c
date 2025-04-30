#include<stdio.h> 

int f(int a) {
    int b = 0;
    while (a > 0 && a % 2 == 0 && b < 10) {
        b++;
        a = a / 2;
    }
    return b;
}

    void main(){
        printf("%d",f(7));
    }
    