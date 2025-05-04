#include<stdio.h> 

            
            int f(int a) {
                    int x = 5;
                    while ((x > 0 && x < 10) || (x == 5 && x!= 5)) {
                            x = (x > 0)? x + 1 : x - 1;
                            x = (x > 5)? x + 1 : x - 1;
                    }
                    return 0;
            }
            
            
    void main(){
        printf("%d",f(7));
    }
    