#include<stdio.h> 

int f(int a) {
    while (a < 10 && a > 5) {
        // Dead loop with complex condition and statement
        if (a % 2 == 0) {
            a += 2;
        } else {
            a -= 3;
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    