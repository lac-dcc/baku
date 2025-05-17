#include<stdio.h> 

int f(int a) {
    int i = 1;
    while (i * i < a * a) {
        i++;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    