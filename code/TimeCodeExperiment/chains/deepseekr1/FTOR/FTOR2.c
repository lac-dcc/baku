#include<stdio.h> 

int f(int a) {
    while(0) {
        if(a <= 0 && a > 5) {
            return;
        }
        if(a == 3 && a > 7) {
            return;
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    