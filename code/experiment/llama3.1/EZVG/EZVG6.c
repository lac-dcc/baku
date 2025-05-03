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
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    