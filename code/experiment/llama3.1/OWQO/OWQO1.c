#include<stdio.h> 

int f(int a) {
        int sum = 0;
        for (int i = 0; i < a; i++) {
            sum += i;
        }
        return sum;
    }

    void main(){
        printf("%d",f(7));
    }
    