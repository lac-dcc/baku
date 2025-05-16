#include<stdio.h> 

int f(int a) {
    if (a <= 5) {
        return a * a;
    } else {
        return a * a * a;
    }
}

    void main(){
        printf("%d",f(7));
    }
    