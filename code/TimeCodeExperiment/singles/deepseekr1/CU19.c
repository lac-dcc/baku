#include<stdio.h> 

int f(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a;
        a--;
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    