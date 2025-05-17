#include<stdio.h> 

int f(int a) {
    if (0) {
        // this code never runs
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    