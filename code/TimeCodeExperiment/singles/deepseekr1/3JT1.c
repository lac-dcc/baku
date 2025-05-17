#include<stdio.h> 

int f(int a) {
    return 0;
    while (a > 0 && a < 0) {
        // This loop will never execute because a cannot be both greater than 0 and less than 0 at the same time.
    }
}

    void main(){
        printf("%d",f(7));
    }
    