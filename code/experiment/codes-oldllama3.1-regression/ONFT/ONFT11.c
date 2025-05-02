#include<stdio.h> 

            
int f(int a, int b = 5, int c = 10) {
        // Dead nested conditional statement
        if (a == 10 && b == 5 && c == 10) {
                // This condition will never be true
                printf("This will never be printed\n");
        }
        if (a > 10) {
                return 0;
        }
        else {
                return 0;
        }
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        if (i > 5 && j < 5) {
                                printf("Hello World\n");
                        }
                        else {
                                for (int k = 0; k < 10; k++) {
                                        for (int l = 0; l < 10; l++) {
                                                if (k > 5 && l < 5) {
                                                        printf("Hello World\n");
                                                }
                                                else if (k < 3 && l > 7) {
                                                        printf("Hello Universe\n");
                                                }
                                        }
                                }
                        }
                }
        }
}

            
    void main(){
        printf("%d",f(7));
    }
    