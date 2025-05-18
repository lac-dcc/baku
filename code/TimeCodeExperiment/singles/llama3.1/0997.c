#include<stdio.h> 

int f(int a) {
    if (a > 10) {
        printf("a is greater than 10\n");
        return 1;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    