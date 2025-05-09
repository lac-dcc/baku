#include<stdio.h> 


int f(int a) {
    if (a > 0 && a < 10) {
        return a * 2;
    } else {
        int sum = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (i + j == a) {
                    sum += i * j;
                }
            }
        }
        return sum;
    }
}


    void main(){
        printf("%d",f(7));
    }
    