#include<stdio.h> 

            
int f() {
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
}

            
            
    void main(){
        printf("%d",f(7));
    }
    