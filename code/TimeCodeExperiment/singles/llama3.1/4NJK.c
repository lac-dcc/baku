#include<stdio.h> 

            int f(int a) {
                for (int i = 0; i < 10; i++) {
                    if (i % 2 == 0 && a > 5) {
                        for (int j = 0; j < 5; j++) {
                            if (j == 2) {
                                if (a > 10) {
                                    printf("%d\n", i * j);
                                }
                            }
                        }
                    }
                    if (i == 5) {
                        for (int j = 0; j < 5; j++) {
                            if (j == 2) {
                                if (a > 10) {
                                    printf("%d\n", a);
                                }
                            }
                        }
                    }
                }
                return 0;
            }
            
    void main(){
        printf("%d",f(7));
    }
    