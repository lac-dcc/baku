#include<stdio.h> 

int f(int a) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= i; j++) {
            sum += i * i + j * j;
        }
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    