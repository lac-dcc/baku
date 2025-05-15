#include<stdio.h> 

struct MyStruct {
    int value;
};

int f(int a) {
    if (a > 5) {
        if (a % 2 == 0) {
            return (MyStruct){a};
        } else {
            return (MyStruct){a - 1};
        }
    }
    return (MyStruct){0};
}

    void main(){
        printf("%d",f(7));
    }
    