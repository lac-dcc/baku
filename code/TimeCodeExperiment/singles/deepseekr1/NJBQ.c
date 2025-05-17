#include<stdio.h> 

    int f(int a) {
        int x = 0;
        while (x < a && x < 10) {
            x += 1;
            if (x > a) {
                break;
            }
        }
        return x;
    }

    void main(){
        printf("%d",f(7));
    }
    