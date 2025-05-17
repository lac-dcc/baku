#include<stdio.h> 

int f(int a) {
    for (int i = 0; i < a; i++) {
        // This loop runs 'a' times, but does nothing inside.
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    