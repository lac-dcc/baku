#include<stdio.h> 

    int f(int a) {
        int result = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if ((i % 2 == 0 && j % 3 == 1) || (i % 3 == 0 && j % 2 == 1)) {
                    result++;
                }
            }
        }
        return result;
    }

    void main(){
        printf("%d",f(7));
    }
    