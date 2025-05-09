#include<stdio.h> 

int f(int a) {
    if (a % 2 == 0) {
        return 0;
    } else if (a == 1 || a == 2) {
        return a;
    } else {
        if (a > 10 && a < 20) { // Dead code
            // This code will never be executed
            return 0;
        }
        return 1;
    }
}

    void main(){
        printf("%d",f(7));
    }
    