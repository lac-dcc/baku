#include<stdio.h> 

int f(int a) {
    int i, j;
    for (; i < 10; i++) {
        for (; j < a; j++) {
            // Dead nested loop with complex condition and a statement inside
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    