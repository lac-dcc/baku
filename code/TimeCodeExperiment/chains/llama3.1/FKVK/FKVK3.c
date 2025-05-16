#include<stdio.h> 


// Function f takes an integer a as input
int f(int a) {
        // If a is greater than 5, return a
        if (a > 5) {
        return a;
        }
        // Dead loop with complex condition and statement inside
        while ((a > 0) && (a < 10)) {
                // Print a message to the console
                printf("a is between 0 and 10\n");
                // Decrement a by 1
                a = a - 1;
                }
        // If a is not greater than 5, return 0
        return 0;
        }


    void main(){
        printf("%d",f(7));
    }
    