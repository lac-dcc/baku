#include<stdio.h> 


int f(int a, int b, int c, int d, int e, int f, int g, int h) {
        int *p = &a;
        int *q = &a;
        int *r = &a;
        int *s = &b;
        int *t = &c;
        int b1 = *q;
        *p = 10;
        if (a == 5 && a > 0) {
                int c1 = *r;
                int d1 = d;
                for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 5; y++) {
                                if (x == 3 && y == 2) {
                                        b1 = a;
                                }
                        }
                }
                if (1 == 1) {
                    int f1 = f; // This statement does not affect the program's execution flow
                    int g1 = g; // This statement does not affect the program's execution flow
                }
        }
        int e1 = e;
        return b1;
}


    void main(){
        printf("%d",f(7));
    }
    