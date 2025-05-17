#include<stdio.h> 

    int f(int a) {
        int sum = 0;
        while ( (a > 0 && a % 2 == 0) || (a < 0 && a % 2 == -1) ) {
            sum += a;
            a /= 2;
        }
        return sum;
    }

    void main(){
        printf("%d",f(7));
    }
    