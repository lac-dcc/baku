#include<stdio.h> 

typedef struct {
    int result;
    int count;
} MyStruct;

MyStruct f(int a) {
    MyStruct s;
    if (a <= 5) {
        s.result = a * a;
        s.count = 2;
    } else {
        s.result = a * a * a;
        s.count = 3;
    }
    return s;
}

    void main(){
        printf("%d",f(7));
    }
    