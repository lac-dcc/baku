#include<stdio.h> 

        int f(int a) {
            if (a > 10) {
                if (a < 20) {
                    return a * 2;
                } else {
                    return a / 2;
                }
            } else {
                if (a < 5) {
                    return a + 5;
                } else {
                    return a - 5;
                }
            }
        }
        
    void main(){
        printf("%d",f(7));
    }
    