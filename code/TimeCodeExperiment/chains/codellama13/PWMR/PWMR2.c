#include<stdio.h> 

            
             int f(int a, int b) {
                    if (a > 0) {
                            if (b > 0) {
                                    return a + b;
                            }
                    }
                    return 0;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    