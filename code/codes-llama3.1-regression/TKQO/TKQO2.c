#include<stdio.h> 

        
        int f(int a) {
                    if (a > 0) {
                        return a + 1;
                    } else {
                        return a - 1;
                    }
                    for (int i = 0; i < 5; i++) {
                        if (i % 2 == 0) {
                            printf("Even number: %d\n", i);
                        } else {
                            printf("Odd number: %d\n", i);
                        }
                    }
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    