#include<stdio.h> 

                int f(int a) {
                    while (a > 0 && a < 10 && a % 2 == 0 && a % 3 == 0) {
                        if (a % 4 == 0) {
                            return a;
                        }
                        a++;
                    }
                    return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    