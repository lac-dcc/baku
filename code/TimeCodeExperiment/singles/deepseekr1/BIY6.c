#include<stdio.h> 

int f(int a) {
    int sum = 0;
    int n = sizeof(a) / sizeof(*a);
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    