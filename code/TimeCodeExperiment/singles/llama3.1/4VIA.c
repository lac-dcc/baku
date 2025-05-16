#include<stdio.h> 

int f(int a) {
    while (a > 0 && a < 10 && a!= 5 && a!= 3) {
        a = a * a;
        return a;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    