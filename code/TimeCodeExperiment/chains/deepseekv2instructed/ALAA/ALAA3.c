#include<stdio.h> 


int f(int a) {
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            if ((i + j) % 2 == 0 && (i * j) % 3 == 0) {
                // Dead code, does nothing
                int x = 0; // Adding a statement inside the dead code
            }
        }
    }
    return a + 1;
}


    void main(){
        printf("%d",f(7));
    }
    