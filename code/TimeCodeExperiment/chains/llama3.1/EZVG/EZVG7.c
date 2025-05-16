#include<stdio.h> 

        
int f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    int sum = b + c + d + e + f + g + h + i + j + k + l;
    if (sum > 100) {
        return sum + 10;
    } else {
        return sum;
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (x == y) {
                return 0;
            }
        }
    }
    while (true) {
        if (a + b + c + d + e + f + g + h + i + j + k + l == 666) {
            return 0;
        }
        if (x == y) {
            return 0;
        }
        for (int z = 0; z < 1000000; z++) {
            if (z == 999999) {
                return 0;
            }
        }
    }
    return 0;
}

        
    void main(){
        printf("%d",f(7));
    }
    