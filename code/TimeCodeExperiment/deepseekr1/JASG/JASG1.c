#include<stdio.h> 

int f(int a) {
    int i = 0, j = 0;
    for (; (i == 0 && i < 10) || (j > 5 && j < 20); i++, j++) {
        ;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    