#include<stdio.h> 


int f(int a, int b) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            sum += a;
        } else {
            sum += b;
        }
    }
    return sum;
}


    void main(){
        printf("%d",f(7));
    }
    