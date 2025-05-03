#include<stdio.h> 

            
            int f(int a) {
                    if (a > 5) {
                        if (a % 2 == 0) {
                            return a;
                        }
                        if (a > 10) {
                            return a * 2;
                        }
                    }
                    return 0;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    