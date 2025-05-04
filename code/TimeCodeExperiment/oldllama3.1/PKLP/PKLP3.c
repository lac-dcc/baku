#include<stdio.h> 

int f(int a) {
    if (a > 0 && a % 2 == 0) {
        while (a > 0 && a % 2 == 0) {
            a = a / 2;
        }
        return a;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    