#include<stdio.h> 

int f(int a) {
    if (a > 10) {
        if (a < 0) {
            return a * 2; // This statement will never be executed
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    