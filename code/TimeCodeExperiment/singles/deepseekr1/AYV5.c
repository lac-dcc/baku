#include<stdio.h> 

int f(int a) {
    for ( ; false ; ) {
        // This loop never runs
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    