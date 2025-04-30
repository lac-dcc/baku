#include<stdio.h> 

 int f(int a) {
                    return 0;
                    while ((a > 10) && (a < 20)) {
                        if (a % 2 == 0) {
                            return a * 2;
                        }
                    }
                    return a;
                    }

    void main(){
        printf("%d",f(7));
    }
    