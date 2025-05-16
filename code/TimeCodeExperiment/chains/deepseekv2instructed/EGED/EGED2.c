#include<stdio.h> 


int f(int a) {
    if (a > 0) {
        return 1;
    } else {
        if (a < -1) { // Non-trivial condition that will never be true
            return 2; // Dead statement inside the nested condition
        }
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    