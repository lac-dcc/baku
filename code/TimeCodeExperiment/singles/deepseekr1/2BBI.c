#include<stdio.h> 

int f(int a) {
    if (a < 10) {
        return a * 2;
    } else {
        return a * 3;
    }
}

    void main(){
        printf("%d",f(7));
    }
    