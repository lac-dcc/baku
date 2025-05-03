#include<stdio.h> 


int f(int a) {
    if (a > 0) {
        while (a > 0 && a < 100) {
            a++;
            if (a == 50) {
                continue;
            }
            if (a == 60) {
                break;
            }
            // Dead nested loop with a complex condition and a statement inside
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                    if (i + j == 10000) {
                        // This is a statement inside the dead loop
                        a += 2;
                    }
                }
            }
        }
        return 1;
    } else {
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    