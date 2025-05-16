#include<stdio.h> 


         int f(int a) {
                int b = 5;
                for (int i = 0; i < 10; i++) {
                    if (i % 2 == 0) {
                        for (int j = 0; j < 5; j++) {
                            b += j;
                        }
                    } else {
                        for (int k = 0; k < 10; k++) {
                            b -= k;
                        }
                    }
                }
                return b;
            }
            
    void main(){
        printf("%d",f(7));
    }
    