#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            if ((i + j) % 2 == 0 && (i * j) % 3 == 0) {
                // Dead code, just to add complexity
                int k = 0;
                while (k < 1000000) {
                    k++;
                }
            }
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    