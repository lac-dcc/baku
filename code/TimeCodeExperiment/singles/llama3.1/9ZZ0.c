#include<stdio.h> 

            int f(int a) {
                int i, j;
                for (i = 0; i < a; i++) {
                    for (j = 0; j < a; j++) {
                        if (i == j || i + j == a) {
                            return i + j;
                        }
                    }
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    