#include<stdio.h> 

            
int f(int a) {
    int i = 0; // Initialize a counter variable to 0
    do {
        if (a > 10) { // If a is greater than 10, return a immediately
            return a;
        }
        if (a < 5) { // If a is less than 5, return a immediately
            return a;
        }
        if (a == 5) { // If a is equal to 5, return a immediately
            return a;
        }
        if (a == 10) { // If a is equal to 10, return a immediately
            return a;
        }
        if (a == 0) { // If a is equal to 0, return 0 immediately
            return 0;
        }
        if (a > 7 && i % 2 == 0) { // If a is greater than 7 and i is even, multiply a by 2
            a = a * 2;
        }
        if (a < 7 && i % 2 == 1) { // If a is less than 7 and i is odd, divide a by 2
            a = a / 2;
        }
        i++; // Increment the counter variable
    } while (i < 5); // Loop until i reaches 5
    return a; // Return the final value of a
}


    void main(){
        printf("%d",f(7));
    }
    