#include<stdio.h> 

int f(int a) {
    while (a < 10 && a > -10 && a != 0) {
        // Complex statement or operation
        a = a * a + 3;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    