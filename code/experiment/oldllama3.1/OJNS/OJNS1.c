#include<stdio.h> 

int f(int a) {
    int i = 0;
    while (i < a && a < 10 && i > 0) {
        a = a + 1;
        i = i + 1;
    }
    return a;
}

    void main(){
        printf("%d",f(7));
    }
    