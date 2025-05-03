#include<stdio.h> 

int f(int a) {
    if (a == 0) {
        return a + 1;
    }
    if (a > 1 && a < 10) {
        return a + 10;
    }
    return 0;
}
int g(int a) {
    int i = 0;
    while (i < 5) {
        while (i < 5 && a > 1 && a < 10) {
            i++;
            a++;
        }
        i++;
    }
    return a;
}
# 
    void main(){
        printf("%d",f(7));
    }
    