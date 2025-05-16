#include<stdio.h> 

            int f(int a) {
                int i;
                for (i = 0; i < a; i++) {
                    for (int j = 0; j < i; j++) {
                        if (i % 2 == 0 && j % 3 == 0) {
                            printf("%d %d\n", i, j);
                            printf("%d\n", i * j);
                            printf("Hello World!\n");
                            printf("This is a test.\n");
                            printf("This is another test.\n");
                            printf("This is a final test.\n");
                            printf("This is a test of the final test.\n");
                            printf("This is a test of the final test 2.\n");
                            printf("This is a test of the final test 3.\n");
                            printf("This is a test of the final test 4.\n");
                            printf("This is a test of the final test 5.\n");
                        }
                    }
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    