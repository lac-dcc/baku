#include<stdio.h> 

            int f(int a) {
                if (a >= 0) {
                    if (a == 5) {
                        return 10;
                    } else if (a > 5) {
                        return a * 2;
                    } else {
                        return a + 1;
                    }
                } else {
                    return a - 1;
                }
            }

            for (int i = 0; i < 10; i++) { // Dead loop
                if (i % 2 == 0 && i > 5) { // Complex condition
                    // Statement inside the loop
                    printf("Hello World!\n");
                }
            }
            
    void main(){
        printf("%d",f(7));
    }
    