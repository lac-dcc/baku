#include<stdio.h> 

int f(int a) {
    int *p = &a;
    return *p + 1;
}

    void main(){
        printf("%d",f(7));
    }
    