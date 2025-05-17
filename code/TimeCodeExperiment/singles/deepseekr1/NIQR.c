#include<stdio.h> 

struct MyStruct {
    int x;
    int y;
};

int f(int a) {
    MyStruct s = {a, 0};
    return s.x + s.y;
}

    void main(){
        printf("%d",f(7));
    }
    