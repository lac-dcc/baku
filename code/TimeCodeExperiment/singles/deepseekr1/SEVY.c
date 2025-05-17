#include<stdio.h> 

int f(int a) {
    if (a < 5) {
        return 0;
    } else {
        return a * a;
    }
}

    void main(){
        printf("%d",f(7));
    }
    