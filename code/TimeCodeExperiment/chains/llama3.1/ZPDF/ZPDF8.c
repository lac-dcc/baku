#include<stdio.h> 

int f(int a, int b, int c) {
    if (a > 10) {
        return a + b + c;
    }
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i * 2 + b + c;
        } else {
            return i * 3 + b + c;
        }
        // Dead conditional statement with a statement inside
        if (0) {
            printf("This will never be printed\n");
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    