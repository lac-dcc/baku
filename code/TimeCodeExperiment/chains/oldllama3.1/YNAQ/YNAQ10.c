#include<stdio.h> 

            
int f(int a, int b) {
    // This function returns 1 if both a and b are greater than 0, otherwise it returns 0
    for (int i = 0; i < 10; i++) {
        if (a > 0 && b > 0) {
            for (int j = 0; j < 100; j++) {
                // This loop will run indefinitely if the condition (a > 0 && b > 0) is false
                if (a <= 0 || b <= 0) {
                    while (1) {
                        printf("Dead loop detected!\n");
                    }
                }
            }
        } else {
            return 0;
        }
    }
    return 1;
}

            
    void main(){
        printf("%d",f(7));
    }
    