#include<stdio.h> 

            
int f(int *a) {
    if (*a > 5 && *a < 10) { // non-trivial condition
        // do nothing
    }
    return 0;
}

            
    void main(){
        printf("%d",f(7));
    }
    