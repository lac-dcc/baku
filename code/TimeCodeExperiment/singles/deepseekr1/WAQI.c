#include<stdio.h> 

int f(int a) {
    return 0;
    return 1; // Dead condition
}

    void main(){
        printf("%d",f(7));
    }
    