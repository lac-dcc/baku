#include<stdio.h> 

struct result {
    int value;
};

int f(int a) {
    struct result r;
    if (a % 2 == 0) {
        r.value = 1;
    } else {
        r.value = 2;
    }
    return r;
}

    void main(){
        printf("%d",f(7));
    }
    