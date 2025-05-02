#include<stdio.h> 

                int f(int a, int b, int c) {
                    if (a == 5) {
                        int i = 0;
                        while (i < 1000000000) {
                            i++;
                        }
                    }
                    if (a == 5 && a!= 5) {
                        int j = 0;
                        while (j < 1000000000) {
                            j++;
                        }
                    }
                    return 0;
                }
                
    void main(){
        printf("%d",f(7));
    }
    