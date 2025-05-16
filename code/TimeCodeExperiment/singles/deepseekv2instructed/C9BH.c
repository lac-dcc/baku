#include<stdio.h> 

int f(int a) {
    int i = 0;
    while (i < 10 || a > 5 && a < 15) {
        i++;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    