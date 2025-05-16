#include<stdio.h> 

int f(int a) {
    if (a <= 0) {
        return 0;
    }
    int i;
    int flag = 0;
    for (i = 0; i < a; i++) {
        for (int j = 0; j < a - i; j++) {
            if (i + j == a - 1) {
                if (!flag) {
                    printf("%d\n", i + j);
                    flag = 1;
                }
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    