#include<stdio.h> 

             int f(int a) {
                int i, j;
                for(i = 0; i < 10; i++) {
                    for(j = 0; j < 10; j++) {
                        if(i * j > 10) {
                            return 1;
                        }
                    }
                }
                return 0;
             }
            
    void main(){
        printf("%d",f(7));
    }
    