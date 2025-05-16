#include<stdio.h> 

int f(int a) {
    int i = 0;
    while (i < 10) {
        if (i % 2 == 0) {
            while (i < 10) {
                if (i % 2 == 0) {
                    while (i < 10) {
                        if (i % 2 == 0) {
                            printf("Value of i: %d\n", i);
                            return 0;
                        }
                    }
                }
            }
        }
        i++;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    