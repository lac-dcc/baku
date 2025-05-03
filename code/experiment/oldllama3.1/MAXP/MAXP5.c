#include<stdio.h> 

            
int f(int a) {
    if (a < 0) {
        // handle negative input
        return 0;
    }
    if (a == 0) {
        // handle edge case where a is 0
        return 0;
    }
    if (a > 1000) {
        // handle large input
        return 0;
    }
    if ((a > 0) && (a < 1000)) {
        // handle normal input
        int sum = 0;
        for (int i = 0; i < a; i++) {
            sum += i;
        }
        if (a % 2 == 0) {
            // handle even number
            return sum + 1;
        } else {
            // handle odd number
            return sum - 1;
        }
    }
    // add new condition to check if a is a prime number
    if (is_prime(a)) {
        // handle prime number
        return sum + 2;
    }
    return 0;
}

// helper function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

            
    void main(){
        printf("%d",f(7));
    }
    