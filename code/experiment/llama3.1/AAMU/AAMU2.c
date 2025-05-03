#include<stdio.h> 

            
            int f(int a) {
                    for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 10; j++) {
                                    if (i == 5 && j == 5) {
                                            f(10);
                                            }
                                    }
                            }
                    return a + 1;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    