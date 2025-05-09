#include<stdio.h> 

        
        int f(int a, int b) {
            if (a > 0) {
                if (a < 10) {
                    return a + b;
                } else {
                    for (int i = 0; i < 1000000; i++) {
                        for (int j = 0; j < 1000000; j++) {
                            if (i + j == 1000000) {
                                while (1) { // Dead loop
                                    // Complex statement inside
                                    int x = a * b;
                                    if (x > 100) {
                                        return x;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return 0;
        }


            
    void main(){
        printf("%d",f(7));
    }
    