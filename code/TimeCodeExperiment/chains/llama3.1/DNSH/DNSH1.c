#include<stdio.h> 

 int f(int a) {
        if (a >= 0) {
            if (a == 5) {
                return 10;
            } else {
                return a + 1;
            }
        } else {
            return a - 1;
        }
    }

    void main(){
        printf("%d",f(7));
    }
    