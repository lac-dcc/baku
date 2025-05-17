#include<stdio.h> 

int f(int a) {
    if (a != a) {
        return;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    