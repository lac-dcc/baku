#include<stdio.h> 

int f(int a) {
    int result = 0;
    if (a > 10) {
        result = a * a;
    } else {
        result = a + a;
    }
    return result;
}

    void main(){
        printf("%d",f(7));
    }
    