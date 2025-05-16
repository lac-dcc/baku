#include<stdio.h> 

            int f(int a) {
                    int *p = &a;
                    int *q = &a;
                    int *r = &a;
                    int b = *q;
                    *p = 10;
                    int c = *r;
                    int d = a;
                    return b;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    