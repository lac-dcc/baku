#include<stdio.h> 

int f(int a, int b, int c) {
    for (int i = 0; i < a; i++) {
        // If i is greater than 20, return i * 3 + b + c
        if (i > 20) {
            return i * 3 + b + c;
        } else {
            // If i is exactly equal to 20, return i * 4 + b + c
            if (i == 20) {
                return i * 4 + b + c;
            } 
            // If i is greater than or equal to 10, return i * 2 + c
            else if (i >= 10) {
                return i * 2 + c;
            } else {
                // If i is less than 10, return i + b + c
                return i + b + c;
            }
        }
        // This is a dead nested conditional statement with a non-trivial condition and a statement inside
        if (i > 1000 && i < 2000 && i % 7 == 42) {
            printf("This will never be printed\n");
        }
    }
    // If the loop ends, return b + c
    return b + c;
}

            
    void main(){
        printf("%d",f(7));
    }
    