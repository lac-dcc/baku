#include<stdio.h> 

int f(int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
        for (int j = 0; j < 1000000; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                // Complex operation
            }
            // Another dead conditional statement
        }
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    