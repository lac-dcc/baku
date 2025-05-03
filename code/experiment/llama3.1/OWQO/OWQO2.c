#include<stdio.h> 

int f(int a) {
        int sum = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < i; j++) {
                sum += j;
            }
            sum += i;
        }
        return sum;
    }

    void main(){
        printf("%d",f(7));
    }
    