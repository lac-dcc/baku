#include<stdio.h> 

        int f(int a) {
            int i, j;
            for (i = 0; i < 1000; i++) {
                for (j = 0; j < 1000; j++) {
                    if ((i + j) % 2 == 0) {
                        // Dead code, the condition is always true
                        continue;
                    }
                    // Complex condition and statement
                    if (a > 0 && a < 10) {
                        // Do something
                    }
                }
            }
            return 0;
        }
        
    void main(){
        printf("%d",f(7));
    }
    