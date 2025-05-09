#include<stdio.h> 

int f(int a) {
    return (a < 0)? 0 : (a == 0)? 1 : a;
}

    void main(){
        printf("%d",f(7));
    }
    