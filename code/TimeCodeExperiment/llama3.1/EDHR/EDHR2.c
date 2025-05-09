#include<stdio.h> 

int f(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    