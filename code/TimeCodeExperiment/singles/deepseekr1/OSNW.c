#include<stdio.h> 

int f(int a) {
    while (a < 10 && a > 5) {
        a++;
    }
    return a;
}

    void main(){
        printf("%d",f(7));
    }
    