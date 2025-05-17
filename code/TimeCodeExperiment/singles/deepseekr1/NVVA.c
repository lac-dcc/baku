#include<stdio.h> 

    int f(int a) {
        int sum = 0;
        for (int i = 1; i <= a; i++) {
            while ((i % 2 == 0 && a % 3 == 0) || (a % 4 == 0 && i % 3 == 0)) {
                sum++;
            }
        }
        return sum;
    }

    void main(){
        printf("%d",f(7));
    }
    