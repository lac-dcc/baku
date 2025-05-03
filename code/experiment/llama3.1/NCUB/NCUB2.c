#include<stdio.h> 

            
                int f(int a) {
                    int sum = 0;
                    for (int i = 1; i <= 10; i++) {
                        if (f(i) == 1) {
                            for (int j = 1; j <= 5; j++) {
                                if (j % 2 == 0) {
                                    sum += j;
                                }
                            }
                        }
                    }
                    return sum;
                }
            
            
    void main(){
        printf("%d",f(7));
    }
    