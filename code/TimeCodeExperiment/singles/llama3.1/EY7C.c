#include<stdio.h> 

            int f(int a) {
                if (a > 10) {
                    return 0;
                } else if (a < 5) {
                    return 1;
                } else {
                    while (a > 0) {
                        printf("%d\n", a);
                        a--;
                    }
                    return 0;
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    