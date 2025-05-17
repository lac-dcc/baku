#include<stdio.h> 

int f(int a) {
    while (a == a + 1) {
        // This loop will never execute because a == a + 1 is always false
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    