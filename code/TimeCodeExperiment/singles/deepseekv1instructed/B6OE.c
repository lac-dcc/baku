#include<stdio.h> 

             int f(int a) {
                int i, j;
                for(i = 0; i < a; i++) {
                    for(j = 0; j < a; j++) {
                        if(i % 2 == 0 && j % 2 == 0) {
                            return 1;
                        }
                    }
                }
                return 0;
             }
            
    void main(){
        printf("%d",f(7));
    }
    