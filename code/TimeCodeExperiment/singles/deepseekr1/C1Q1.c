#include<stdio.h> 

int f(int a) {
    for (int i = 0; i < 0 && a < 5; i++) {
        // This loop will never execute because i starts at 0, making the condition false.
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    