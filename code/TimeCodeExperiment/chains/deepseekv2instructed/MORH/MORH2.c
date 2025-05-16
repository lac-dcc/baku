#include<stdio.h> 


int f(int a) {
    if (a > 0) {
        while (a > 0 && a < 100) {
            a++;
            if (a == 50) {
                continue;
            }
            if (a == 60) {
                break;
            }
        }
        return 1;
    } else {
        return 0;
    }
}


    void main(){
        printf("%d",f(7));
    }
    