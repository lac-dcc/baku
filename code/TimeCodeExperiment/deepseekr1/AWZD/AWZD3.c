#include<stdio.h> 


int f(int a) {
    if (a < 5) {
        return a * a;
    } else if (a <= 10) {
        return a * a * a;
    } else {
        return a * 2;
    }
}


    void main(){
        printf("%d",f(7));
    }
    