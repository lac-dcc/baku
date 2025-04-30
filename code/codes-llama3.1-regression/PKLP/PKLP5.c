#include<stdio.h> 

int f(int a, int b, int c) {
    if (a > 0 && a % 2 == 0 && b > 0 && b % 2 == 0 && c > 0 && c % 2 == 0) {
        while (a > 0 && a % 2 == 0 && b > 0 && b % 2 == 0 && c > 0 && c % 2 == 0) {
            a = a / 2;
            b = b / 2;
            c = c / 2;
        }
        return a + b + c;
    }
    return 0;
}

int f(char c, char d, char e) {
    if (c >= 'A' && c <= 'Z' && d >= 'A' && d <= 'Z' && e >= 'A' && e <= 'Z') {
        return c - 'A' + d - 'A' + e - 'A' + 1;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    