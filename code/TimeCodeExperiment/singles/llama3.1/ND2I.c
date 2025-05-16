#include<stdio.h> 

int f(int a) {
    if (a > 0 && a < 10) {
        return a * a;
    } else if (a == 10) {
        return a * 10;
    } else {
        return a;
    }
}

    void main(){
        printf("%d",f(7));
    }
    