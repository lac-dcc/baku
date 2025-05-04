#include<stdio.h> 

int f(int a, int b) {
    if (a == 0) {
        return a + b;
    }
    if (a > 1 && a < 10) {
        return a + b + 10;
    }
    return 0;
}
int g(int a, int b) {
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
    }
    return a + b;
}
# 

    void main(){
        printf("%d",f(7));
    }
    