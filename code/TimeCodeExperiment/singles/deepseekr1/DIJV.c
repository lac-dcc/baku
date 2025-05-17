#include<stdio.h> 

int f(int a) {
    if (a < 5 && a > 5) {
        // This conditional will never be true, making it dead code.
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    