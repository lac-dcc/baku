#include<stdio.h> 

            int f(int a) {
                int sum = 0;
                for (int i = 0; i < a; i++) {
                    for (int j = 0; j < a; j++) {
                        if (i == j) {
                            sum += i;
                        } else if (i + j == a - 1) {
                            sum += j;
                        } else {
                            sum += 0;
                        }
                        if (i == a - 1) {
                            sum += j;
                        }
                        if (j == a - 1) {
                            sum += i;
                        }
                        if (i == j && j == a - 1) {
                            sum += 1;
                        }
                        if (i == j && j == 0) {
                            sum -= 1;
                        }
                        if (j == i + 1) {
                            sum += 1;
                        }
                        if (i == j && j == 0 && i == a - 1) {
                            sum += 1;
                        }
                        if (i == 0 && j == a - 1) {
                            sum += 1;
                        }
                        if (i == a - 1 && j == 0) {
                            sum += 1;
                        }
                    }
                }
                return sum;
            }
            
    void main(){
        printf("%d",f(7));
    }
    