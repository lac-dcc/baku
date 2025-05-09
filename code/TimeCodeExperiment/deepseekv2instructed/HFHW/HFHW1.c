#include<stdio.h> 

        int f(int a) {
            while (a < 10 && a > -10) {
                if (a > 0) {
                    a += 2;
                } else {
                    a -= 2;
                }
            }
            return 0;
        }
        
    void main(){
        printf("%d",f(7));
    }
    