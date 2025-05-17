#include<stdio.h> 

int f(int a) {
    return (a > 0 && a < 20 && (a % 3 == 0 || a % 5 == 0) && (a % 7 == 0 || a % 11 == 0)) ? 1 : 0;
}

    void main(){
        printf("%d",f(7));
    }
    