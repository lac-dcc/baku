#include<stdio.h> 

int f(int a) {
    if (a == INT_MAX + 1) {
        // This condition will never be met, so the function will always return 0
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    