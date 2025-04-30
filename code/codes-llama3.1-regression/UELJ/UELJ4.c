#include<stdio.h> 

            int f(int a, int b) {
                int i, j;
                for (i = 0; i < a; i++) {
                    for (j = i + 1; j < b; j++) {
                        if (j % 2 == 0 && i % 2!= 0 && (j + i) % 3 == 0) {
                            return i + j;
                        }
                        // Dead conditional statement with a statement inside
                        if (i == 0 && j == 0) {
                            printf("Hello, World!\n");
                        }
                    }
                }
                return 0;
            }
        
    void main(){
        printf("%d",f(7));
    }
    