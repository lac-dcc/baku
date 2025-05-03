#include<stdio.h> 

            int f(int a) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (i > j || i == 10) { // added condition i == 10
                            return a;
                        }
                    }
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    