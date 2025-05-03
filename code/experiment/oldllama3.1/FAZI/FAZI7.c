#include<stdio.h> 

int f(int a) {
        int x = 5;
        while ((x > 0 && x < 10) || (x == 5 && x!= 5)) {
                x = (x > 0)? x + 1 : x - 1;
                x = (x > 5)? x + 1 : x - 1;
                if (x > 10 && x < 15) {
                        x = (x > 10)? x - 1 : x + 1;
                }
                /* Dead nested loop with a complex condition and a statement inside */
                if (x > 20 && x < 25 && a > 0) {
                        for (int i = 0; i < 5; i++) {
                                if (i == 3) {
                                        x = 100; // This statement will be executed when i is equal to 3
                                }
                        }
                }
        }
        return 0;
}

    void main(){
        printf("%d",f(7));
    }
    