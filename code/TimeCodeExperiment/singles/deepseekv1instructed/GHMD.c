#include<stdio.h> 

             int f(int a) {
                int i;
                for(i = 0; i < a; i++) {
                    if(i % 2 == 0) {
                        return 0;
                    }
                }
                return 1;
             }
            
    void main(){
        printf("%d",f(7));
    }
    