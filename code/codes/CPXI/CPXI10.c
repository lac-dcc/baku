#include<stdio.h> 

            
int f(int a, int b, int c, int d) {
    int i = 0;
    while (i <= a && i < 1000001) {
        if (a > 10) {
            printf("a is greater than 10\n");
        }
        printf("Looping...\n");
        i++;
        if (i % 2 == 0) {
            printf("This will print\n");
            int j = 0;
            while (j < 100000) { // Modified nested loop condition
                printf("Nested Looping...\n");
                j++;
            }
        }
        if (b == 5) {
            printf("b is 5\n");
        }
        if (b > 10) {
            printf("b is greater than 10\n");
        }
        if (a == 0) {
            printf("a is 0\n");
        }
    }
    return 0;
}


            
    void main(){
        printf("%d",f(7));
    }
    