#include<stdio.h> 

int f(int *a) {
    if (*a > 5 && *a < 10) { // non-trivial condition
        if (*a > 5 && *a < 10) { // dead nested conditional statement
            // do nothing
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    