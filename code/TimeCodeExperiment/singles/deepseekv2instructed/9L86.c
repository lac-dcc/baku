#include<stdio.h> 

int f(int a) {
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    return sum;
}

    void main(){
        printf("%d",f(7));
    }
    