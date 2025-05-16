#include<stdio.h> 

             int f(int a) {
                if (a > 0) {
                    if (a % 2 == 0) {
                        return a;
                    } else {
                        return a + 1;
                    }
                } else {
                    return -a;
                }
                }
            
    void main(){
        printf("%d",f(7));
    }
    