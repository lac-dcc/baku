#include<stdio.h> 

            
            int f(int a) {
                int i;
                for (i = 0; i < 10; i++) {
                    if (i % 2 == 0) {
                        for (int j = 0; j < 5; j++) {
                            printf("Value of a is: %d\n", a);
                        }
                    } else {
                        printf("Value of a is: %d\n", a);
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
                }
                return 0;
            }
        
            
    void main(){
        printf("%d",f(7));
    }
    