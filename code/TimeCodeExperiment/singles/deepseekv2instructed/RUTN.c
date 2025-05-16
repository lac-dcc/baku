#include<stdio.h> 

int f(int a) {
    if (a > 0) {
        return 1;
    } else if (a == 0) {
        return 2;
    } else {
        return 3;
    }
}

    void main(){
        printf("%d",f(7));
    }
    