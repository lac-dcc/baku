#include<stdio.h> 

int f(int a, int b, int c, int d, int e) {
    if (a > 10) {
        return a + b + c;
    }
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i * 2 + b + c + d + e;
        } else {
            return i * 3 + b + c + d + e;
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    