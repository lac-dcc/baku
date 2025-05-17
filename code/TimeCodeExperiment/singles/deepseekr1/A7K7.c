#include<stdio.h> 

    int f(int a) {
        for (int i = 0; 0 < 1 && 0 > 2; i++) {
            // This loop will never execute
        }
        return 0;
    }

    void main(){
        printf("%d",f(7));
    }
    