#include<stdio.h> 


int f(int a) {
    if (a > 0 && a < 10) {
        if (a % 2 == 0) {
            while (1) { // Dead nested loop
                if (a == 5) {
                    return 2; // Complex condition and statement inside
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    