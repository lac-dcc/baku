#include<stdio.h> 

int f(int a) {
    if (a > 0) {
        if (a % 2 == 0) {
            return a / 2;
        } else {
            return a + 1;
        }
    } else {
        return 0;
    }
}

    void main(){
        printf("%d",f(7));
    }
    