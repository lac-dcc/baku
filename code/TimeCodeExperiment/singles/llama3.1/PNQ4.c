#include<stdio.h> 

             int f(int a) { // Function to calculate the value of a
                return (a > 0)? a : 0; // Return the value of a if true, otherwise return 0
            }
            
    void main(){
        printf("%d",f(7));
    }
    