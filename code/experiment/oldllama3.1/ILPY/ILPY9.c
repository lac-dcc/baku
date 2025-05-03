#include<stdio.h> 

            int f(int a) {
                if (a > 10) {
                    if (a > 20) {
                        if (a > 25) {
                            return a * 3;
                        } else {
                            return a + 5;
                        }
                    } else {
                        return a + 10;
                    }
                }
                bool is_true = false;
                if (is_true) {
                    switch (a % 4) {
                        case 0:
                            return 5;
                        case 1:
                            return 10;
                        case 2:
                            return 15;
                        default:
                            return 20;
                    }
                }
                for (int i = 0; i < 10; i++) {
                    if (i % 2 == 0) {
                        a += 2;
                    } else {
                        a -= 2;
                    }
                }
                for (int j = 0; j < 5; j++) {
                    if (j > 2 && j < 4) {
                        a += 1;
                    }
                    if (j == 3) {
                        a -= 3;
                    }
                    for (int k = 0; k < 3; k++) {
                        if (k % 2 == 0) {
                            a += 1;
                        } else {
                            a -= 1;
                        }
                    }
                }
                if (a > 5 && a < 10) {
                    return 0;
                }
                if (a == 15) {
                    return 20;
                }
                if (a > 20) {
                    return 30;
                }
                return a;
            }
            
    void main(){
        printf("%d",f(7));
    }
    