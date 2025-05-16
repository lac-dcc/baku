#include<stdio.h> 

            
            int f(int a, int b, int c, int d) {
                int i;
                for (i = 0; i < 10; i++) {
                    if (i % 2 == 0) {
                        for (int j = 0; j < 5; j++) {
                            printf("Value of a is: %d\n", a);
                            printf("Value of b is: %d\n", b);
                            printf("Value of c is: %d\n", c);
                            printf("Value of d is: %d\n", d);
                        }
                    } else {
                        printf("Value of a is: %d\n", a);
                        printf("Value of b is: %d\n", b);
                        printf("Value of c is: %d\n", c);
                        printf("Value of d is: %d\n", d);
                    }
                    printf("Iteration number: %d\n", i);
                    if (i == 5) {
                        printf("Iteration number 5 reached\n");
                    }
                    if (i == 9) {
                        printf("Last iteration reached\n");
                    }
                    if (i >= 5 && i < 8) {
                        printf("Iteration number between 5 and 8 reached\n");
                    }
                    // Dead nested loop
                    for (int k = 0; k < 100; k++) {
                        for (int l = 0; l < 100; l++) {
                            printf("Dead loop iteration: %d, %d\n", k, l);
                        }
                    }
                }
                return 0;
            }
            
            
    void main(){
        printf("%d",f(7));
    }
    