#include<stdio.h> 

int f(int a) {
    if (a <= 5) {
        if (a % 2 == 0) {
            return a;
        } else {
            return a / 2;
        }
    } else {
        return 0;
    }
}

    void main(){
        printf("%d",f(7));
    }
    