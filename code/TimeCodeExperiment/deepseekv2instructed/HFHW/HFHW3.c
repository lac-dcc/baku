#include<stdio.h> 


int f(int a) {
    while (a < 10 && a > -10) {
        if (a > 0) {
            a += 2;
        } else {
            a -= 2;
        }
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                if (i == j) {
                    continue;
                }
            }
        }
        // Dead loop with a complex condition and statement inside
        if (a % 2 == 0) {
            int x = 0;
            while (x < 1000000) {
                x++;
                if (a > 0 && a < 5) {
                    a += 3;
                } else if (a >= 5 && a < 8) {
                    a -= 3;
                } else {
                    a += 1;
                }
            }
        } else {
            int y = 0;
            while (y < 1000000) {
                y++;
                if (a > 0 && a < 5) {
                    a += 3;
                } else if (a >= 5 && a < 8) {
                    a -= 3;
                } else {
                    a += 1;
                }
            }
        }
    }
    return 0;
}


    void main(){
        printf("%d",f(7));
    }
    