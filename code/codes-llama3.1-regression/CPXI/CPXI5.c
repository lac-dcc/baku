#include<stdio.h> 

int f(int a) {
    int i = 0;
    while (i <= a && a > 0) {
        if (a > 10) {
            printf("a is greater than 10\n");
        }
        printf("Looping...\n");
        i++;
        if (i % 2 == 0 && i > 1000000) { // Dead condition, i will never be greater than 1000000 in this loop
            printf("This will never print\n");
            int j = 0;
            while (j < 1000000000) { // Dead nested loop
                printf("Nested Looping...\n");
                j++;
            }
        }
    }
    return 0;
}

            
    void main(){
        printf("%d",f(7));
    }
    