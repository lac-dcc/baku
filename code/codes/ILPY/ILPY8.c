#include<stdio.h> 

            
int f(int a) {
    if (a > 10) {
        if (a > 20) {
            return a * 2;
        } else {
            return a + 5;
        }
    }
    bool is_true = false;
    if (is_true) {
        if (a % 2 == 0) {
            return 5;
        } else {
            return 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            a += 2;
        } else {
            a -= 2;
        }
    }
    for (int j = 0; j < 5; j++) {
        if (j > 2 && j < 4) {
            a += 1;
        }
        if (j == 3) {
            a -= 3;
        }
    }
    if (a > 5 && a < 10) {
        return 0;
    }
    if (a == 15) {
        return 20;
    }
    return a;
}

            
    void main(){
        printf("%d",f(7));
    }
    