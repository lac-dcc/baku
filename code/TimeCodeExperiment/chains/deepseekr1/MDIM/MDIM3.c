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
    if (a == 1 && a == 0) {
        // This condition will never be true, so the code inside won't run.
        r.value = 3;
    }
    return r;
}

    void main(){
        printf("%d",f(7));
    }
    