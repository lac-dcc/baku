#include<stdio.h> 

int f(int a, int b, int c, int d) {
    int i;
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0 && i > 5) {
            return a - 2 + b + c - d;
        }
    }
    return a - 2 + b + c - d;
}

    void main(){
        printf("%d",f(7));
    }
    