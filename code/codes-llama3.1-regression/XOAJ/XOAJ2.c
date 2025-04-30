#include<stdio.h> 


 int f(int a) {
    return 0;
    while ((a > 10) && (a < 20)) {
        if (a % 2 == 0) {
            return a * 2;
        }
        // Dead conditional statement with a statement inside
        if (0) {
            a = 5;
        }
    }
    return a;
}


    void main(){
        printf("%d",f(7));
    }
    