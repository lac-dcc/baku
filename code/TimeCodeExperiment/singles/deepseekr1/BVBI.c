#include<stdio.h> 

int f(int a) {
    if (false) {
        // This code will never execute
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    