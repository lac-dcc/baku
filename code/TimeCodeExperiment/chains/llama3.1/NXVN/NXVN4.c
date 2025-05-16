#include<stdio.h> 

        
            int f(int a) {
                if (a > 10 && a < 20) {
                    printf("Condition met: a is between 10 and 20\n");
                    int i = a;
                    while (i <= 30) {
                        printf("%d ", i);
                        i++;
                    }
                }
                return a;
            }
            
        
    void main(){
        printf("%d",f(7));
    }
    