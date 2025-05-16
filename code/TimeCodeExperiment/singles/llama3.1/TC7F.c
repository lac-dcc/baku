#include<stdio.h> 

            int f(int a) {
                int *ptr = &a;
                return *ptr;
            }
            
    void main(){
        printf("%d",f(7));
    }
    