#include<stdio.h> 

int f(int a) {
    if (a > 0 && a < 0) {
        // This code will never execute
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    