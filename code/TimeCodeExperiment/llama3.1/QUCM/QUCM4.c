#include<stdio.h> 

int f(int a, int b) {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 5; j++) {
                if (j % 2 == 0) {
                    return i + j + b;
                }
            }
        } else {
            for (int j = 0; j < 5; j++) {
                if (j % 2 == 0) {
                    return i + j + b;
                }
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    