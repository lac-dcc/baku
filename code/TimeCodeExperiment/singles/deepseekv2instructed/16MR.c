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
            return sum;
        }
        
    void main(){
        printf("%d",f(7));
    }
    