#include<stdio.h> 

int f(int a) {
    if (a < 5 && a > 5) {
        // This code won't run because the condition is impossible
        // You could add comments or other dead code here
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    