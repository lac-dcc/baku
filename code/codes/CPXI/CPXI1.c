#include<stdio.h> 

int f(int a) {
    int i = 0;
    while (i < a && a > 0) {
        printf("Looping...\n");
        i++;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    