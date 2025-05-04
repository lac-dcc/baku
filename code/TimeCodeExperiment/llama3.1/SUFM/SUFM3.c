#include<stdio.h> 

int f(int a) {
        int *p = &a;
        int *q = &a;
        int *r = &a;
        int b = *q;
        *p = 10;
        if (a == 5 && a > 0) {
                int c = *r;
                int d = a;
                for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 5; y++) {
                                if (x == 3 && y == 2) {
                                        b = a;
                                }
                        }
                }
        }
        int e = a;
        return b;
}

    void main(){
        printf("%d",f(7));
    }
    