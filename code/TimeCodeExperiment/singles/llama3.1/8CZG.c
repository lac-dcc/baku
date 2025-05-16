#include<stdio.h> 

            int f(int a) {
                int *p = &a;
                int *q = &a;
                if (p!= q) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            
    void main(){
        printf("%d",f(7));
    }
    