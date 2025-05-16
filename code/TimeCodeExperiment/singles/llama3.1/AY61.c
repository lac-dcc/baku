#include<stdio.h> 

            int f(int a) {
                if (a > 10 && a < 20 && a % 3 == 0 && a % 5 == 0 && a % 7 == 0) {
                    for (int i = 0; i < 10; i++) {
                        if (i == 5) {
                            break;
                        }
                    }
                }
                return 0;
            }
        
    void main(){
        printf("%d",f(7));
    }
    