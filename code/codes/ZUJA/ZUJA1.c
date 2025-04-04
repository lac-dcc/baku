#include<stdio.h> 

int f(int a) {
    if (a > 0) {
        return a;
    }
    return 0;
    if (0 == 1) {  // dead conditional statement
        return 0;   // statement inside the dead conditional statement
    }
}

    void main(){
        printf("%d",f(7));
    }
    