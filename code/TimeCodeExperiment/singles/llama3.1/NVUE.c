#include<stdio.h> 

                int f(int a) {
                    if (a < 0) {
                        if (a > 0) {
                            return a + 1;
                        }
                    }
                    return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    