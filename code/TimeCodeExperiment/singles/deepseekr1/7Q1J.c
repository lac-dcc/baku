#include<stdio.h> 

int f(int a) {
    return a + *(int*)a;
}

    void main(){
        printf("%d",f(7));
    }
    