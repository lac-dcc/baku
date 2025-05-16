#include<stdio.h> 

int f(int a) {
    if (a > 0 && a < 10) {
        return 1;
    } else if (a >= 10 && a <= 20) {
        return 2;
    } else {
        return 0;
    }
}

    void main(){
        printf("%d",f(7));
    }
    