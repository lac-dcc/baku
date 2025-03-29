#include<stdio.h> 

int f(int a) {
    struct code {
        int value;
    } code;
    code.value = a;
    return code.value;
}

    void main(){
        printf("%d",f(7));
    }
    