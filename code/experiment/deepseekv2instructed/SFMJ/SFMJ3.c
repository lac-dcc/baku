#include<stdio.h> 


int f(int a, int b) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            if (i + j == 5) {
                // Complex statement or operation
                // Example: Print a message or perform a calculation
                printf("The sum of %d and %d is 5\n", i, j);
            }
            // Dead conditional statement
            if (i == 0 && j == 0) {
                // Dead code
                printf("This will never be printed\n");
            }
        }
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    