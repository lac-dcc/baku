#include<stdio.h> 

int f(int a) {
    int b = a;
    for (int i = 0; i < 10; i++) {
        if (b == b + 1) {
            b++;
        }
        else {
            b = b * 2;
        }
    }
    return b;
}


    void main(){
        printf("%d",f(7));
    }
    