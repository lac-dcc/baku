#include<stdio.h> 

             int f(int a) {
                    if (a > 10) {
                    return a;
                    }
                    if (a < 5) {
                    return a;
                    }
                    if (a == 5) {
                    return a;
                    }
                    if (a == 10) {
                    return a;
                    }
                    if (a == 0) {
                    return 0;
                    }
                    return a;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    