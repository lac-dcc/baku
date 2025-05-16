#include<stdio.h> 

int f(int a) {
    int x = 5;
    while (x > 0 && x < 10) {
        x++;
        if (x == 8) {
            continue;
        }
        if (x == 12) {
            break;
        }
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    