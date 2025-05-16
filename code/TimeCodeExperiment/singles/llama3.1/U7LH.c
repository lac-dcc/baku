#include<stdio.h> 

            int f(int a) {
                if (a > 5) {
                    return a;
                }
                else {
                    return 0;
                }
            }
            
    void main(){
        printf("%d",f(7));
    }
    