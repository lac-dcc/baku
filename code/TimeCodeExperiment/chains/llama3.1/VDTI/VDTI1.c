#include<stdio.h> 

            #include <stdio.h>

            int f(int a) {
                    int i = 0;
                    while (i < 5) {
                        if (a > 0) {
                            printf(“%d “, a);
                            a = a – 1;
                        } else {
                            printf(“%d “, a);
                            a = a + 1;
                        }
                        i = i + 1;
                    }
                    return 0;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    