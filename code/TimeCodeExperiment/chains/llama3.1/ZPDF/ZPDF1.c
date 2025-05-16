#include<stdio.h> 

int f(int a) {
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i * 2;
        } else {
            return i * 3;
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    