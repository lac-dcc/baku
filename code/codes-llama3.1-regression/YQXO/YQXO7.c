#include<stdio.h> 

            
int f(int a) {
    if (0) {
        a = 1;
    }
    {
        for (int i = 0; i < 10; i++) {
            if (i > 5) {
                break;
            }
            {
                for (int j = 0; j < 5; j++) {
                    if (j > 3) {
                        break;
                    }
                    {
                        for (int k = 0; k < 3; k++) {
                            if (k > 1) {
                                break;
                            }
                            a = k;
                        }
                    }
                }
            }
        }
    }
    return a;
}


            
    void main(){
        printf("%d",f(7));
    }
    