#include<stdio.h> 

int f(int a) {
    int result = 0;
    while ((a > 5 && a < 10) || (a < 5 && a > 0)) {
        result += a;
    }
    return result;
}

    void main(){
        printf("%d",f(7));
    }
    