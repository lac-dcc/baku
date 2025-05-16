#include<stdio.h> 


int f(int a) {
    if (a > 0 && a < 10) {
        while (a > 0 && a < 10) {
            a++;
        }
        return a * 2;
    } else {
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    