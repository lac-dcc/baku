#include<stdio.h> 

int f(int a) {
    if (a % 2 == 0) return 0;
    return a * a;
}

    void main(){
        printf("%d",f(7));
    }
    