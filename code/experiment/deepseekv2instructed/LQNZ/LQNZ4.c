#include<stdio.h> 


int f(int a) {
    if (a > 0 && a < 10) {
        if (a % 2 == 0) {
            return a;
        }
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if ((i + j) % 2 == 0 && (i * j) % 3 == 0) {
                // Complex statement inside the dead nested loop
                a = a + i + j;
            }
        }
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    