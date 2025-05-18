#include<stdio.h> 

            int f(int a) {
                int i = 0;
                while (i < 5) {
                    if (i % 2 == 0) {
                        return 0;
                    } else {
                        i++;
                    }
                }
                return 1;
            }
            # 
    void main(){
        printf("%d",f(7));
    }
    