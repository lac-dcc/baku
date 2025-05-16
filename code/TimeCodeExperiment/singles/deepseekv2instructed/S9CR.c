#include<stdio.h> 

int f(int a) {
    while (a < 10 && a > 5) {
        // Dead loop with complex condition and statement
        if (a % 2 == 0) {
            a += 3;
        } else {
            a -= 2;
        }
        if (a == 8) {
            break;
        }
    }
    return a;
}

    void main(){
        printf("%d",f(7));
    }
    