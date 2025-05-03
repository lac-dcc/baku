#include<stdio.h> 

            
int f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    if (a > 0) {
        if (a > 10) {
            return b + c + d + e + f + g + h + i + j + k + l;
        }
    }
    return 0;
}

            
    void main(){
        printf("%d",f(7));
    }
    