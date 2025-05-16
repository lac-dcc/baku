#include<stdio.h> 

            
int f(int a, int b) {
    // Check if a is even
    if (a % 2 == 0) {
        // If a is even, return the sum of a and b
        return a + b;
    } else if (a % 2!= 0) {
        // If a is odd, return the sum of a and b
        return a + b;
    } else {
        // If a is neither even nor odd (which is not possible for integers), return 0
        return 0;
    }
}

            
    void main(){
        printf("%d",f(7));
    }
    