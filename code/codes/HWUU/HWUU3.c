#include<stdio.h> 

            
int f(int a) {
                    while (1 + a > 0 && a > 0) {
                    if (a == 5) {
                    printf("Value of a is 5");
                    }
                    printf("Hello, World!");
                    if ((a * 2) % 7 == 0) { // non-trivial condition
                    // dead code
                    }
                    }
                    return 0;
                    }

            
            
    void main(){
        printf("%d",f(7));
    }
    