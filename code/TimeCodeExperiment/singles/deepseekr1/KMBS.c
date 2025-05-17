#include<stdio.h> 

int f(int a) {
    if (a > 0 && a < 0) {
        // This condition is never true
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    