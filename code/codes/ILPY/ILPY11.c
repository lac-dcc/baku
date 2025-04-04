#include<stdio.h> 

            int f(int a, int b, int c) {
                if (a > 10) {
                    if (a > 20) {
                        if (a > 25) {
                            return a * 3 + b + c;
                        } else {
                            return a + 5 + b + c;
                        }
                    } else {
                        return a + 10 + b + c;
                    }
                }
                bool is_true = false;
                if (is_true) {
                    switch (a % 4) {
                        case 0:
                            return 5 + b + c;
                        case 1:
                            return 10 + b + c;
                        case 2:
                            return 15 + b + c;
                        default:
                            return 20 + b + c;
                    }
                }
                for (int i = 0; i < 10; i++) {
                    if (i % 2 == 0) {
                        a += 2 + b + c;
                    } else {
                        a -= 2 + b + c;
                    }
                }
                for (int j = 0; j < 5; j++) {
                    if (j > 2 && j < 4) {
                        a += 1 + b + c;
                    }
                    if (j == 3) {
                        a -= 3 + b + c;
                    }
                    for (int k = 0; k < 3; k++) {
                        if (k % 2 == 0) {
                            a += 1 + b + c;
                        } else {
                            a -= 1 + b + c;
                        }
                    }
                }
                if (a > 5 && a < 10) {
                    return b + c;
                }
                if (a == 15) {
                    return 20 + b + c;
                }
                if (a > 20) {
                    return 30 + b + c;
                }
                return a + b + c;
            }
            // Add a dead conditional statement with a statement inside
            if (0) {
                // This statement will never be executed
                return 0;
            }
            // This statement will never be executed
            return 0;
            
    void main(){
        printf("%d",f(7));
    }
    