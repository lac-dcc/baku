#include<stdio.h> 

            int f(int a) {
                while (a > 10) {
                    return a * a;
                    a = a + 1;
                }
                while (a < 5) {
                    return a * a;
                    a = a + 1;
                }
                while (a >= 5 && a <= 10) {
                    return a * a;
                    a = a + 1;
                }
                return a;
            }
            
    void main(){
        printf("%d",f(7));
    }
    