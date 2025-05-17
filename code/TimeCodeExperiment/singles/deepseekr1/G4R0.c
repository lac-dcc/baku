#include<stdio.h> 

int f(int a) {
    struct SomeStruct {
        int x;
        int y;
    } myStruct;
    myStruct.x = a;
    myStruct.y = 0;
    return myStruct.x + myStruct.y;
}

    void main(){
        printf("%d",f(7));
    }
    