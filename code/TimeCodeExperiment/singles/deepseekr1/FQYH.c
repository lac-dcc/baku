#include<stdio.h> 

int f(int a) {
    int k = 0;
    for (int i = 0; i < a && i % 2 == 0; i++) {
        for (int j = 1; j <= i; j++) {
            k++;
        }
    }
    return k;
}

    void main(){
        printf("%d",f(7));
    }
    