#include<stdio.h> 


int f(int a, int b) {
    if (a > 0 && a < 10) {
        return a * 2 + b;
    } else {
        int sum = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (i + j == a) {
                    sum += i * j;
                }
                // Dead loop to make the code complex
                while (i + j < a * 2) {
                    int k = 0;
                    while (k < 1000000) {
                        k++;
                    }
                }
            }
        }
        return sum + b;
    }
}


    void main(){
        printf("%d",f(7));
    }
    