#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = i + 1; j < a; j++) {
            if (j % 2 == 0 && i % 2!= 0 && (j + i) % 3 == 0) {
                return i + j;
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    