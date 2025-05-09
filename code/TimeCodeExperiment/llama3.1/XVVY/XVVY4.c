#include<stdio.h> 

            
int f(int a) {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 5; j++) {
                if (j % 3 == 0 && j % 4 == 0) {
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
    }
}

            
    void main(){
        printf("%d",f(7));
    }
    