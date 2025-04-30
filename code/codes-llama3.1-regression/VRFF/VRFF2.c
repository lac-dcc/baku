#include<stdio.h> 

            
int f(int a) {
    if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10) {
        if (a % 2 == 0) {
            return a * 2;
        } else {
            return a * 3;
        }
    }
    return 0;
}

            
    void main(){
        printf("%d",f(7));
    }
    