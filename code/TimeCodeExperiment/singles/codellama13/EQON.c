#include<stdio.h> 

             int f(int a) {
                int i;
                for (i = 0; i < a; i++) {
                    if (i % 2 == 0) {
                        printf("Even");
                    } else {
                        printf("Odd");
                    }
                }
                return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    