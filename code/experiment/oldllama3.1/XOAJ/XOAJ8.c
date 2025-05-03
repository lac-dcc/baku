#include<stdio.h> 

if (a > 5) {
    if (b > 10) {
        if (c > 20) {
            printf("a > 5, b > 10, c > 20\n");
        } else {
            printf("a > 5, b > 10, c <= 20\n");
        }
    } else {
        if (c > 20) {
            printf("a > 5, b <= 10, c > 20\n");
        } else {
            printf("a > 5, b <= 10, c <= 20\n");
        }
    }
} else {
    if (b > 10) {
        if (c > 20) {
            printf("a <= 5, b > 10, c > 20\n");
        } else {
            printf("a <= 5, b > 10, c <= 20\n");
        }
    } else {
        if (c > 20) {
            printf("a <= 5, b <= 10, c > 20\n");
        } else {
            printf("a <= 5, b <= 10, c <= 20\n");
        }
    }
}

    void main(){
        printf("%d",f(7));
    }
    