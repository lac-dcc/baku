#include<stdio.h> 

    int f(int a) {
        int i, j;
        for (i = 0; i < a; i++) {
            for (j = 0; j < i * i; j++) {
                // This inner loop runs for each combination of i and j
            }
        }
        return 0;
    }

    void main(){
        printf("%d",f(7));
    }
    