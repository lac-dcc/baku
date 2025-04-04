#include<stdio.h> 

            
             int f(int a) {
                    int i = 0;
                    do {
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
                    i++;
                    } while (i < 5);
                    return a;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    