#include<stdio.h> 

             int f(int a) {
                int i, j;
                for (i = 0; i < 10; i++) {
                    for (j = 0; j < 10; j++) {
                        if (i == j) {
                            printf("i = %d, j = %d\n", i, j);
                        }
                    }
                }
                return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    