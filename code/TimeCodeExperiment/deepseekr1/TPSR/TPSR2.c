#include<stdio.h> 

    int f(int a) {
        int sum = 0;
        int prime_count = 0;
        int current_number = 2;
        for (int i = 1; i <= a; i++) {
            // Check if current_number is prime
            bool is_prime = true;
            for (int j = 2; j <= sqrt(current_number); j++) {
                if (current_number % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                sum += current_number * current_number;
                prime_count++;
                current_number++;
            } else {
                current_number++;
            }
        }
        return sum;
    }

    void main(){
        printf("%d",f(7));
    }
    