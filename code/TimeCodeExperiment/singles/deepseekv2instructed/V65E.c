#include<stdio.h> 

int f(int a) {
    // Add a dead nested loop with a complex condition and a statement inside
    while (a < 10) {
        if (a > 10) {
            // This is a dead code path
            for (;;) {
                // Infinite loop
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    