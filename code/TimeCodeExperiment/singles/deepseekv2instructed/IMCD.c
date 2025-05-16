#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            if ((i + j) % 2 == 0 && (i * j) % 3 == 0) {
                // Dead nested loop with a complex condition and a statement inside
                int x = 0;
                for (int k = 0; k < 1000000; k++) {
                    x += k;
                }
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    