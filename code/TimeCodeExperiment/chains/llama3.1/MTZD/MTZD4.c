#include<stdio.h> 

int f(int a) {
    while (1) {
        if ((a < 0 && a!= -1) || (a == 0 && a!= 1)) {
            return 0;
        } else if (a > 0 && a!= 2) {
            return 1;
        } else if (a == 1 || a == 2) {
            return a;
        } else {
            return 0;
        }
        if ((a == 3 && a == 4)) {
            return 0;
        }
    }
}

    void main(){
        printf("%d",f(7));
    }
    