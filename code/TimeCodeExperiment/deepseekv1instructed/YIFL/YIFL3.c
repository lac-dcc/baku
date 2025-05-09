#include<stdio.h> 

            int f(int a) {
                for(int i = 0; i < a; i++) {
                    for(int j = 0; j < a; j++) {
                        if(i == j) {
                            return 1;
                        }
                    }
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    