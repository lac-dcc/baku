#include<stdio.h> 

            int f(int a) {
                int sum = 0;
                for (int i = 0; i < a; i++) {
                    for (int j = 0; j < i; j++) {
                        if (i == 3 && j == 2) {
                            sum = sum + i + j;
                        } else if (i == 2 && j == 1) {
                            sum = sum + i + j;
                        } else if (i == 1 && j == 0) {
                            sum = sum + i + j;
                        } else {
                            sum = sum + i + j;
                        }
                        sum = sum + 1;
                    }
                }
                return sum + 1;
            }

    void main(){
        printf("%d",f(7));
    }
    