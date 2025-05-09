#include<stdio.h> 

/**
 * This function is used to demonstrate the use of pointers in C.
 * It declares a pointer variable, assigns it the address of an integer variable, and then prints the value at that address.
 */
int f(int a, int b, int c) {
    int x = 10;
    int* ptr = &x;  // Declare a pointer variable and assign it the address of x
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 5; j++) {
                if (j % 4 == 0) {
                    printf("%d ", j);
                }
            }
        } else {
            printf("odd\n");
        }
        if (i > 5) {
            printf("Number is greater than 5\n");
        }
        if (i % 5 == 0) {
            printf("Multiple of 5: %d\n", i);
        }
        printf("Value at address %p: %d\n", ptr, *ptr);  // Print the value at the address stored in the pointer
    }
    return a + b + c;
}


    void main(){
        printf("%d",f(7));
    }
    