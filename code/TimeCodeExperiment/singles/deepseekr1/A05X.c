#include<stdio.h> 

int f(int a) {
    while (a && !a) {
        // Do nothing
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    