#include<stdio.h> 

struct MyStruct {
    int x;
};

struct MyStruct f(int a) {
    return {x: a};
}

    void main(){
        printf("%d",f(7));
    }
    