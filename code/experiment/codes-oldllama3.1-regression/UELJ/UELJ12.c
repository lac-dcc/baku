#include<stdio.h> 

            
for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
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
    }
}

            
    void main(){
        printf("%d",f(7));
    }
    