#include<stdio.h> 

            
void print_hello_world(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 4 == 0 && i > j && j % 2 == 1) {
                printf("Hello, World!\n");
                static int counter = 0;
                counter++;
                printf("Hello, World! has been printed %d times.\n", counter);
                // This is a dead code, it will never be executed.
                for (int k = 0; k < 100000000; k++) {
                    int x = k * k;
                }
            }
            // Add a new loop with a complex condition
            if ((i + j) % 2 == 0 && j > i) {
                printf("i = %d, j = %d\n", i, j);
            }
        }
    }
}

            
    void main(){
        printf("%d",f(7));
    }
    