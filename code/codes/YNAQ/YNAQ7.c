#include<stdio.h> 

            
int f(int a, int b) {
    // This function returns 1 if both a and b are greater than 0, otherwise it returns 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // The conditions in this if statement are always false because 1 == 0 is false
            if (i > 5 && j < 5 && i % 2 == 0 && j % 3 == 1 && 1 == 0) {
                // This return statement will never be executed because the conditions are always false
                return (a > 0 && b > 0)? 1 : 0;
            }
        }
    }
    // This return statement will always be executed because the conditions in the if statement are always false
    return (a > 0 && b > 0)? 1 : 0;
}


            
    void main(){
        printf("%d",f(7));
    }
    