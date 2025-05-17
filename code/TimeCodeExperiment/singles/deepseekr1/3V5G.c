#include<stdio.h> 

int f(int a) {
    while ( (a == 5 && a == 6) || (a < 3 && a > 7) ) {
        ;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    