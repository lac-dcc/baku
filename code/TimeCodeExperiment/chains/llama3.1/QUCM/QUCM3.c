#include<stdio.h> 

int f(int a, int b) {
    if (a == 0) {
        return b;
    } else if (a == 1) {
        return 1 + b;
    } else if (a == 2) {
        return 2 + b;
    } else if (a == 3) {
        return 3 + b;
    } else if (a == 4) {
        return 4 + b;
    } else if (a == 5) {
        return 5 + b;
    } else if (a == 6) {
        return 6 + b;
    } else if (a == 7) {
        return 7 + b;
    } else if (a == 8) {
        return 8 + b;
    } else if (a == 9) {
        return 9 + b;
    } else if (a == 10) {
        return 10 + b;
    } else if (a == 11) {
        return 11 + b;
    } else {
        return 12 + b;
    }
}
            
    void main(){
        printf("%d",f(7));
    }
    