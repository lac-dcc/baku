#include<stdio.h> 

/**
 * This program demonstrates the use of a while loop with a complex condition and a nested if statement.
 * The function f takes three parameters: a, b, and c, where b and c are optional and default to 0.
 * The function returns the value of a after the loop has finished executing.
 */

int f(int a, int b = 0, int c = 0) {
    while (a > 0 && a < 10) { // The loop condition is a > 0 && a < 10
        int d = a * 2; // Calculate the value of d
        if (d > 20) { // If d is greater than 20
            a = a + 1; // Increment a by 1
        } else { // If d is not greater than 20
            a = a - 1; // Decrement a by 1
        }
        if (a == 5) break; // If a is equal to 5, exit the loop
        if (c > 0) { // If c is greater than 0
            a = a + c; // Increment a by c
        }
        if (c < 0) { // If c is less than 0
            a = a - c; // Decrement a by c
        }
    }
    return a; // Return the final value of a
}

    void main(){
        printf("%d",f(7));
    }
    