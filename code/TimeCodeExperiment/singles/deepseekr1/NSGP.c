#include<stdio.h> 

int f(int a) {
    if (a > 5 && a < 3) {
        // This conditional statement is dead because the condition is impossible to satisfy.
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    