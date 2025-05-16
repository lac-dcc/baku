#include<stdio.h> 

            int f(int a) {
                if (a > 10) {
                    if (a % 2 == 0) {
                        return a + 1;
                    } else {
                        return a - 1;
                    }
                } else {
                    while (a < 5) {
                        printf("Hello World!\n");
                        a++;
                    }
                    return a;
                }
            }
            
    void main(){
        printf("%d",f(7));
    }
    