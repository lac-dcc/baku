#include<stdio.h> 

            
            int f(int a) {
                for (int i = 0; i < a; i++) {
                    if (i % 2 == 0) {
                        return i;
                    }
                    if (i > 10 && i < 20) {
                        return i * 2;
                    }
                    if (i > 20) {
                        return i * 3;
                    }
                }
                return 0;
            }
        
            
    void main(){
        printf("%d",f(7));
    }
    