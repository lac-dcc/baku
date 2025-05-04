#include<stdio.h> 

int f(int a) {
    while (a > 0 && a < 10) {
        int b = a * 2;
        if (b > 20) {
            a = a + 1;
        } else {
            a = a - 1;
        }
        if (a == 5) break; // Add this line to break the loop when a reaches 5
    }
    return a;
}

    void main(){
        printf("%d",f(7));
    }
    