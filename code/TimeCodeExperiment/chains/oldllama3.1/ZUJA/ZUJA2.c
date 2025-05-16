#include<stdio.h> 

int f(int a) {
    if (a > 0) {
        return a;
    }
    return 0;
    if (0 == 1) {  // dead conditional statement
        for (int i = 0; i < 10; i++) {  // dead nested loop
            for (int j = 0; j < 10; j++) {
                return 0;  // statement inside the dead nested loop
            }
        }
    }
}

    void main(){
        printf("%d",f(7));
    }
    