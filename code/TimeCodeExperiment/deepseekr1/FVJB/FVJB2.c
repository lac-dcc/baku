#include<stdio.h> 

int f(int a) {
    if (a <= 5) {
        return a * a;
    } else {
        if ((a <= 5) && (a > 5)) {
            // This condition is always false, making it a dead nested conditional statement.
        }
        return a * a * a;
    }
}

    void main(){
        printf("%d",f(7));
    }
    