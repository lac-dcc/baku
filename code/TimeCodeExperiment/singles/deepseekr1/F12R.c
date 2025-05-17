#include<stdio.h> 

int f(int a, int b = 0) {
    return a + b;
}

    void main(){
        printf("%d",f(7));
    }
    