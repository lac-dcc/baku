#include<stdio.h> 

int f(int a, int b = 5) {
    if (a > 10) {
        return a + b;
    }
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i * 2 + b;
        } else {
            return i * 3 + b;
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    