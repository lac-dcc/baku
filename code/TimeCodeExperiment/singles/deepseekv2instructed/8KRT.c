#include<stdio.h> 

int f(int a) {
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            if ((i + j) % 2 == 0) {
                // Dead code, just to add complexity
                if (i * j > 1000000) {
                    // Another dead code, just to add more complexity
                    if (a % 2 == 0) {
                        return a + 1;
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
    