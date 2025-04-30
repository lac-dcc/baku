#include<stdio.h> 

int f(int a, int b, int c) {
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            if (i > 10) {
                return i * 2 + b;
            } else {
                return i + b;
            }
        }
        if (i > 10 && i < 20) {
            return i * 2 + c;
        }
        if (i > 20) {
            return i * 3 + b + c;
        }
        if (i == 0 && i!= 0) {
            return i + b + c;
        }
        if (i % 3 == 0 && i % 3!= 0) {
            return i * 2 + b + c;
        }
        if (i > 0 && i < 0) {
            return i + b + c;
        }
        if (i == i) {
            return i + b + c;
        }
        if (i!= i) {
            return i + b + c;
        }
        if (i == 5 && i!= 5) {
            return i + b + c;
        }
    }
    return b + c;
}

    void main(){
        printf("%d",f(7));
    }
    