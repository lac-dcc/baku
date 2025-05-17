#include<stdio.h> 

int f(int a) {
    int sum = 0;
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        sum += a[i];
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    