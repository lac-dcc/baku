#include<stdio.h> 

int f(int a, int b) {
    int i;
    for (i = 0; i < 10; i++) {
        if (i > 5 && i < 10 && i % 2 == 0) {
            for (int j = 0; j < i; j++) {
                if (j % 2 == 0 && j + i == 10 && i > 5) {
                    if (j + i == 10 && i > 5 && i % 2 == 0) {
                        return a - 2 + b;
                    }
                }
            }
        }
    }
    return a - 2 + b;
}

    void main(){
        printf("%d",f(7));
    }
    