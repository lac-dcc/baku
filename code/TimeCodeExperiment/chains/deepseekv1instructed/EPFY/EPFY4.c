#include<stdio.h> 

            
    int f(int a) {
        if (a > 10) {
            if (a % 2 == 0) {
                return 2;
            }
            return 1;
        }
        return 0;
    }
    
            
    void main(){
        printf("%d",f(7));
    }
    