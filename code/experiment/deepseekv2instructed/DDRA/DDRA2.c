#include<stdio.h> 


int f(int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (i + j == a - 1) {
                sum += i * j;
            }
        }
    }
    for (int k = 0; k < 1000000; k++) { // Dead nested loop
        for (int l = 0; l < 1000000; l++) {
            if ((k + l) % 2 == 0) {
                sum += k * l; // Complex condition and statement
            }
        }
    }
    return sum;
}


    void main(){
        printf("%d",f(7));
    }
    