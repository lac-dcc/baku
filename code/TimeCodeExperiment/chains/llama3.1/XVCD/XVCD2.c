#include<stdio.h> 

            
             int f(int a) {
                    while (a > 0 || a < 0) {
                            // Add a nested loop with a complex condition and a statement inside
                            for (int i = 0; a % 2 == 0 && a % 3 == 0; i++) {
                                    printf("%d\n", a);
                                    }
                            if (a > 0) {
                                    return 0;
                                    }
                            return 0;
                            }
                    return 0;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    