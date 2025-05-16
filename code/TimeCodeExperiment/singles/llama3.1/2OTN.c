#include<stdio.h> 

int f(int a) {
    // Outer loop iterates from 0 to 3
    for (int i = 0; i <= 3; i++) {
        // Declare and initialize variable j to 0
        int j = 0;
        // Inner loop checks complex condition and executes statement
        while (j < a && j > 0) {
            // Simple assignment operation: increment j by 1
            j = j + 1;
            // Comment: The condition j < a && j > 0 is always false for any positive value of a
            // because j will be 0 and will not be greater than 0. This loop will not execute
            // for any positive value of a.
        }
    }
    // Return 0 at the end
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    