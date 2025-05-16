#include<stdio.h> 


    int f(int a) {
        if(a > 0) {
            if(a % 2 == 0) {
                return 2;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    }

    
    void main(){
        printf("%d",f(7));
    }
    