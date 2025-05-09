#include<stdio.h> 

            // Function f takes an integer a as input
            int f(int a) {
                    // If a is greater than 5, return a
                    if (a > 5) {
                    return a;
                    }
                    // If a is not greater than 5, return 0
                    return 0;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    