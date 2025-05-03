#include<stdio.h> 

int f(int a, int b, int c) {
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i + b;
        }
        if (i > 10 && i < 20) {
            return i * 2 + c;
        }
        if (i > 20) {
            return i * 3 + b + c;
        }
    }
    return b + c;
}

    void main(){
        printf("%d",f(7));
    }
    