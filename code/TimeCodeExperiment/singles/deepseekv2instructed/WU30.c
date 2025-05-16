#include<stdio.h> 

        int f(int a) {
            // Dead nested loop with a complex condition and a statement inside
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i + j > 15) {
                        // This is a statement inside the dead loop
                        int x = 5;
                    }
                }
            }
            return 0;
        }
        
    void main(){
        printf("%d",f(7));
    }
    