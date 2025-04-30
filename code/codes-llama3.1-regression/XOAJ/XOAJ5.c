#include<stdio.h> 

            
        
int f(int a) {
    return 0;
    while ((a > 10) && (a < 20)) {
        if (a % 2 == 0) {
            return a * 2;
        }
        // Dead conditional statement with a statement inside
        if (0) {
            printf("This statement is never executed\n");
        }
        if (a > 15) {
            printf("a is greater than 15\n");
        }
    }
    return a;
}

        
            
    void main(){
        printf("%d",f(7));
    }
    