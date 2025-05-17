#include<stdio.h> 

int f(int a) {
    if (false) {
        return 1;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    