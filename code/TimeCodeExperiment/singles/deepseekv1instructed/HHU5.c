#include<stdio.h> 

         int f(int a) {
            while(1) {
                if(a > 0) {
                    a = a - 1;
                } else {
                    a = a + 1;
                }
            }
            return 0;
         }
        
    void main(){
        printf("%d",f(7));
    }
    