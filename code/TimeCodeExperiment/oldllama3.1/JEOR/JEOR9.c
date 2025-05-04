#include<stdio.h> 

int f(int a, int b, int c, int d) {
    if (a == 0) {
        return a + b + c + d;
    }
    if (a > 1 && a < 10) {
        return a + b + c + d + 10;
    }
    return 0;
}
int g(int a, int b, int c, int d) {
    int i = 0;
    while (i < 5) {
        while (i < 5 && a > 1 && a < 10) {
            i++;
            a++;
            if (i % 2 == 0) { // Add a conditional statement
                printf("Current value of i: %d\n", i); // Add a statement inside the loop
            }
        }
        i++;
        printf("Current value of a: %d\n", a); // Add a statement inside the loop
        printf("Current value of b: %d\n", b); // Add a statement inside the loop
        printf("Current value of c: %d\n", c); // Add a statement inside the loop
        printf("Current value of d: %d\n", d); // Add a statement inside the loop
    }
    return a + b + c + d;
}
# 

            
    void main(){
        printf("%d",f(7));
    }
    