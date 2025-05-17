#include<stdio.h> 

int f(int a) {
    if (a % 2 == 0) {
        return 0;
    } else if (a % 3 == 0) {
        return 1;
    } else if (a % 4 == 0) {
        return 2;
    } else {
        return 3;
    }
}

    void main(){
        printf("%d",f(7));
    }
    