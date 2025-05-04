#include<stdio.h> 

            
/**
 * Recursive function to calculate the sum of even numbers from 1 to 5.
 * 
 * @param a The input integer.
 * @param b The second input integer.
 * @param c The third input integer.
 * @return The sum of even numbers from 1 to 5.
 */
int f(int a, int b, int c) {
    // Base case: if a is 1, return 0
    if (a == 1) {
        return 0;
    }
    // Check if a is greater than 5
    if (a > 5) {
        return -1; // Return an error message
    }
    // Recursive case: if a is even, add it to the sum of even numbers from 1 to a-1
    if (a % 2 == 0) {
        return a + f(a-1, b, c);
    }
    // If a is odd, return the sum of even numbers from 1 to a-1
    else {
        return f(a-1, b, c);
    }
    // Dead conditional statement with a statement inside
    if (0) {
        printf("This will never be printed\n");
    }
}


            
    void main(){
        printf("%d",f(7));
    }
    