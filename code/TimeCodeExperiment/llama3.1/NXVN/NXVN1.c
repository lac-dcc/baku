#include<stdio.h> 

            int f(int a) {
                if (a > 10 && a < 20) {
                    while (1) {
                        printf("%d ", a);
                        a++;
                        if (a > 30) {
                            a = a;
                        }
                    }
                }
                return a;
            }
            
    void main(){
        printf("%d",f(7));
    }
    