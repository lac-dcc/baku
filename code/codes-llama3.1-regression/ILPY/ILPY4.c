#include<stdio.h> 

            
            int f(int a) {
                if (a > 10) {
                    return a;
                }
                bool is_true = false;
                if (is_true) {
                    return 5;
                }
                for (int i = 0; i < 10; i++) {
                    if (i % 2 == 0) {
                        a += 2;
                    } else {
                        a -= 2;
                    }
                }
                return a;
            }
            
            
    void main(){
        printf("%d",f(7));
    }
    