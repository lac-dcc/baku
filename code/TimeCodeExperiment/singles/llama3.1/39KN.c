#include<stdio.h> 

            int f(int a) {
                if (a > 0 && a < 10) {
                    while (a > 0) {
                        printf("%d ", a);
                        a--;
                    }
                    printf("\n");
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    