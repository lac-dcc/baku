#include<stdio.h> 

int f(int a, int b, int c, int d) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            sum += a;
        } else {
            sum += b;
        }
    }
    for (int j = 0; j < 1000000; j++) {
        if ((j * 7) % 13 == 0 && (j * 11) % 23 == 0 && (j * 17) % 37 == 0) {
            sum += c;
        }
    }
    return sum + d;
}

    void main(){
        printf("%d",f(7));
    }
    