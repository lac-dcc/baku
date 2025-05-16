#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            if (i + j == a - 1) {
                // Complex statement or operation
                // Example: Print a message or perform a calculation
                // For demonstration, let's just print the sum of i and j
                int sum = i + j;
                printf("The sum of i and j is: %d\n", sum);
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    