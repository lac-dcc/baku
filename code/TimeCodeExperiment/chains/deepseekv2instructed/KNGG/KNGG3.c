#include<stdio.h> 


int f(int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
        // Dead loop with a complex condition and statement inside
        if (i > 10 && i < 20) {
            while (sum < 100) {
                sum += i * 2;
            }
        }
    }
    return sum;
}


    void main(){
        printf("%d",f(7));
    }
    