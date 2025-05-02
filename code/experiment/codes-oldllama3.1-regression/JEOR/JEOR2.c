#include<stdio.h> 

            
             int f(int a) {
                    if (a == 0) {
                        return a + 1;
                    }
                    if (a > 1 && a < 10) {
                        return a + 10;
                    }
                    return 0;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    