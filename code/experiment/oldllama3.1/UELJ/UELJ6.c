#include<stdio.h> 

            
            int f(int a, int b) {
                int i, j;
                for (i = 0; i < a; i++) {
                    for (j = i + 1; j < b; j++) {
                        if (j % 2 == 0 && i % 2!= 0 && (j + i) % 3 == 0) {
                            return i + j;
                        }
                        // Dead conditional statement with a statement inside. This condition is never true.
                        if ((i + j) % 4 == 0 && i > j && j % 2 == 1) {
                            printf("Hello, World!\n");
                        }
                    }
                }
                return 0;
            }
        
            
            
    void main(){
        printf("%d",f(7));
    }
    