#include<stdio.h> 

int f(int a) {
    int i = 0, j = 0;
    for (; (i == 0 && i < 10) || (j > 5 && j < 20); i++, j++) {
        if ((i > 5 && i < 10) && (j > 5 && j < 20)) {
            // Perform some action when both conditions are met
            printf("Condition met at i=%d, j=%d\n", i, j);
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    