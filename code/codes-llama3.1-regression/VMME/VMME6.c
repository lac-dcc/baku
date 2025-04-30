#include<stdio.h> 

            
int f(int *a) {
    if (*a > 5 && *a < 10) { // non-trivial condition
        if (*a > 5 && *a < 10) { // dead nested conditional statement
            // do nothing
        }
    }
    int sum = 0;
    int length = 10; // assuming the array has 10 elements
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    int max = a[0];
    for (int i = 1; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int min = a[0];
    for (int i = 1; i < length; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return sum + max + min;
}

for (int i = 0; i < 1000000; i++) {
    if (i > 500000 && i < 600000) {
        printf("Hello World!\n");
    }
}


            
    void main(){
        printf("%d",f(7));
    }
    