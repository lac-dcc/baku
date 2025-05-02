#include<stdio.h> 

            
int sum_even_integers(int a, int b, int c, int d, int e) {
    // Check if all input integers are greater than 0 and even
    if (a > 0 && a % 2 == 0 && b > 0 && b % 2 == 0 && c > 0 && c % 2 == 0 && d > 0 && d % 2 == 0 && e > 0 && e % 2 == 0) {
        // Initialize sum to 0
        int sum = 0;
        // Loop until all integers are no longer even
        for (int i = a; i > 0 && i % 2 == 0; i /= 2) {
            sum += i;
        }
        for (int i = b; i > 0 && i % 2 == 0; i /= 2) {
            sum += i;
        }
        for (int i = c; i > 0 && i % 2 == 0; i /= 2) {
            sum += i;
        }
        for (int i = d; i > 0 && i % 2 == 0; i /= 2) {
            sum += i;
        }
        for (int i = e; i > 0 && i % 2 == 0; i /= 2) {
            sum += i;
        }
        return sum;
    }
    return 0;
}

int sum_uppercase_chars(char c, char d, char e, char f, char g) {
    // Check if all input characters are uppercase letters
    if (c >= 'A' && c <= 'Z' && d >= 'A' && d <= 'Z' && e >= 'A' && e <= 'Z' && f >= 'A' && f <= 'Z' && g >= 'A' && g <= 'Z') {
        // Return the sum of the ASCII values of the characters minus the ASCII value of 'A' plus 1
        return (c - 'A' + 1) + (d - 'A' + 1) + (e - 'A' + 1) + (f - 'A' + 1) + (g - 'A' + 1);
    }
    return 0;
}

            
            
    void main(){
        printf("%d",f(7));
    }
    