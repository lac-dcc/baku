#include<stdio.h> 

            
            int f(int a) {
                    int x = 5;
                    while ((x > 0 && x < 10) || (x == 5 && x!= 5)) {
                            x = (x > 0)? x + 1 : x - 1;
                            x = (x > 5)? x + 1 : x - 1;
                            if (x > 10 && x < 15) {
                                    x = (x > 10)? x - 1 : x + 1;
                            }
                            /* Dead conditional statement with a statement inside */
                            if (x > 20 && x < 25) {
                                    x = 100; // This statement will never be executed
                            }
                    }
                    return 0;
            }
            
            
    void main(){
        printf("%d",f(7));
    }
    