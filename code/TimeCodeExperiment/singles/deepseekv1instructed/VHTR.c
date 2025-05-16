#include<stdio.h> 

             int f(int a) {
                if(a > 0) {
                    return 1;
                } else {
                    return -1;
                }
             }
            
    void main(){
        printf("%d",f(7));
    }
    