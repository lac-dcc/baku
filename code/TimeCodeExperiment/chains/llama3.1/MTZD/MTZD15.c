#include<stdio.h> 

int f(int a) {
    if (a % 2 == 0) {
        return 0;
    } else if (a == 1 || a == 2) {
        return a;
    } else {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 5 && j == 3) {
                    if (i == 7 && j == 1) {
                        return 10;
                    } else {
                        return 5;
                    }
                } else if (i == 9 && j == 4) {
                    return 20;
                }
            }
        }
        return 1;
    }
}

    void main(){
        printf("%d",f(7));
    }
    