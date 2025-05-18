#include<stdio.h> 

        int f(int a) {
            if (a > 0) {
                return 0;
            }
            else {
                return a;
            }
        }
        
    void main(){
        printf("%d",f(7));
    }
    