#include<stdio.h> 

int f(int a) {
    if (a > 5 && a < 10) {
        return a * 2;
    } else {
        return 0;
    }
}

    void main(){
        printf("%d",f(7));
    }
    