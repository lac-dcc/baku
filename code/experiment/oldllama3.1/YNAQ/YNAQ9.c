#include<stdio.h> 

int f(int a, int b) {
    // This function returns 1 if both a and b are greater than 0, otherwise it returns 0
    return (a > 0 && b > 0)? 1 : 0;
}

    void main(){
        printf("%d",f(7));
    }
    