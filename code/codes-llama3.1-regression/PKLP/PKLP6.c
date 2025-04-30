#include<stdio.h> 

int f(int a, int b, int c, int d) {
    if (a > 0 && a % 2 == 0 && b > 0 && b % 2 == 0 && c > 0 && c % 2 == 0 && d > 0 && d % 2 == 0) {
        while (a > 0 && a % 2 == 0 && b > 0 && b % 2 == 0 && c > 0 && c % 2 == 0 && d > 0 && d % 2 == 0) {
            a = a / 2;
            b = b / 2;
            c = c / 2;
            d = d / 2;
        }
        return a + b + c + d;
    }
    return 0;
}

int f(char c, char d, char e, char f) {
    if (c >= 'A' && c <= 'Z' && d >= 'A' && d <= 'Z' && e >= 'A' && e <= 'Z' && f >= 'A' && f <= 'Z') {
        return c - 'A' + d - 'A' + e - 'A' + f - 'A' + 1;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    