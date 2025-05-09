#include<stdio.h> 

int f(int a) {
    if (a % 2 == 0) {
        return 0;
    } else if (a == 1 || a == 2) {
        return a;
    } else {
        for (int i = 0; i < 10; i++) {
            if (i == 5) {
                return 5;
            }
        }
        return 1;
    }
}


    void main(){
        printf("%d",f(7));
    }
    