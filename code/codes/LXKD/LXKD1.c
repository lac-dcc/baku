#include<stdio.h> 

int f(int a) {
    int b = a;
    if (b == b + 1) {
        b++;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    