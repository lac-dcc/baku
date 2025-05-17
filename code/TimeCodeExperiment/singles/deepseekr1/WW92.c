#include<stdio.h> 

int f(int a) {
    if (a != a) {
        // This condition is always false, making it a dead conditional
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    