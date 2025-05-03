#include<stdio.h> 

                int f(int a) {
                    if (a > 10 && a < 20) {
                        return 1;
                    }
                    return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    