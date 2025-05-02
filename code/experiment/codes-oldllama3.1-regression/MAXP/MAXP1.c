#include<stdio.h> 

int f(int a) {
    if (a < 0) {
        // handle negative input
        return 0;
    }
    if (a == 0) {
        // handle edge case where a is 0
        return 0;
    }
    if (a > 1000) {
        // handle large input
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < a; i++) {
        sum += i;
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    