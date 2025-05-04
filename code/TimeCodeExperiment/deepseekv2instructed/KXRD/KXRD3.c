#include<stdio.h> 


int f(int a) {
    int i;
    for (i = 0; i < a; i++) {
        if (i % 2 == 0) {
            continue;
        }
        if (i == 7) {
            break;
        }
        printf("%d\n", i);
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    