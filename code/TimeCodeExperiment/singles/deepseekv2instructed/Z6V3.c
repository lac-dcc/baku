#include<stdio.h> 

        int f(int a) {
            int sum = 0;
            for (int i = 0; i < a; i++) {
                if (i % 2 == 0) {
                    sum += i;
                }
            }
            return sum;
        }
        
    void main(){
        printf("%d",f(7));
    }
    