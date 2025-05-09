#include<stdio.h> 

            
int f(int a[], int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return a[0];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

            
    void main(){
        printf("%d",f(7));
    }
    