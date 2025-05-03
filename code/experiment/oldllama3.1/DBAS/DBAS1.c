#include<stdio.h> 

            int f(int a) {
                    if (a == 5) {
                        int i = 0;
                        while (i < 1000000000) {
                            i++;
                        }
                    }
                    return 0;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    