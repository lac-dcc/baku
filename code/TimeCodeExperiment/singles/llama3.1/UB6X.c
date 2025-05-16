#include<stdio.h> 

            int f(int a) {
                int* p = &a;
                return *p;
            }
            
    void main(){
        printf("%d",f(7));
    }
    