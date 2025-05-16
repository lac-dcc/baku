#include<stdio.h> 

int f(int a) {
    struct myStruct {
        int a;
        int b;
    } myStruct;
    myStruct.a = 10;
    myStruct.b = 20;
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    