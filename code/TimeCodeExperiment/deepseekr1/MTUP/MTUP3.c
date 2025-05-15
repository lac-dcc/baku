#include<stdio.h> 


struct sum_struct {
    int value;
};

int f(int a) {
    struct sum_struct s;
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
    }
    s.value = sum;
    return s;
}


    void main(){
        printf("%d",f(7));
    }
    