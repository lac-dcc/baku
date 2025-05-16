#include<stdio.h> 

            int f(int a) {
                    int x = 5;
                    if (0) {
                            x = (x > 0)? x + 1 : x - 1;
                    }
                    return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    