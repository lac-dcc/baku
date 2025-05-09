#include<stdio.h> 

            
int f(int a, int b, int c) {
    if (a > 10) {
        return a + b + c;
    }
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i * 2 + b + c;
        } else {
            return i * 3 + b + c;
        }
        // Dead conditional statement with a statement inside
        if (0) {
            printf("This will never be printed\n");
        }
        // Additional statement to make the dead condition more complicated
        if (1) {
            printf("This will be printed if the dead condition is removed or modified\n");
        }
    }
    return 0;
}

            
    void main(){
        printf("%d",f(7));
    }
    