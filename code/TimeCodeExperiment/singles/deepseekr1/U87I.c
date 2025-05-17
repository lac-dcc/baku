#include<stdio.h> 

    int f(int a) {
        struct {
            int x;
            int y;
        } sum;
        sum.x = a;
        sum.y = 0;
        sum.x += sum.y;
        return sum.x;
    }

    void main(){
        printf("%d",f(7));
    }
    