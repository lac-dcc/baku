#include<stdio.h> 

int f(int a) {
    int i;
    for(i = 0; i < 10; i++) {
        for(int j = 0; j < i; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    if (j + i == 10) {
                        return a - 2 + a;
                    }
                }
            }
        }
    }
    return a - 2 + a;
}

    void main(){
        printf("%d",f(7));
    }
    